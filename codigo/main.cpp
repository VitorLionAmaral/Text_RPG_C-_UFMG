
#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include "GeradorDeEntidades.hpp"
#include "Personagem.hpp"
#include "classe.hpp"
#include "item.hpp"
#include "inventario.hpp"
#include <cstdlib>


using namespace std;

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printComDelay(const string& texto, int atraso_ms) {
    for (char c : texto) {
        cout << c << flush;
        
        this_thread::sleep_for(chrono::milliseconds(atraso_ms));
    }
    cout << endl;
}

 
void subirNivel(Personagem& personagem) {
   int vidaAtual = personagem.trabalho.Get_VIDA();
    personagem.trabalho.Set_VIDA(vidaAtual + 2);

    int ataqueFisicoAtual = personagem.trabalho.Get_ataque_FIS();
    personagem.trabalho.Set_ataque_FIS(ataqueFisicoAtual + 2);

    int ataqueMagicoAtual = personagem.trabalho.Get_ataque_MAG();
    personagem.trabalho.Set_ataque_MAG(ataqueMagicoAtual + 2);

    int resistenciaFisicaAtual = personagem.trabalho.Get_res_FIS();
    personagem.trabalho.Set_res_FIS(resistenciaFisicaAtual + 2);

    int resistenciaMagicaAtual = personagem.trabalho.Get_res_Mag();
    personagem.trabalho.Set_res_Mag(resistenciaMagicaAtual + 2);
    
    printComDelay("Você subiu de nível! Seus atributos aumentaram.", 40); 
}

classe mago = classe("Mago",60,30,150,10,20);
classe guereiro = classe("guereiro",150,60,20,20,10);
classe ladino = classe("ladino",80,150,20,10,10);
classe tanker = classe("tanker",200,30,30,15,15);


void escolherAcao(int n, Personagem * monstro,Personagem *jogador){
    if(n==1){ jogador->AtacarFisico(monstro);}
    if(n==2){ jogador->AtacarMagico(monstro);}
    if(n==3){ jogador->DefenderFisico();}
    if(n==4){jogador->DefenderMagico();}
    
    
}
void turnoDoMostro(Personagem * monstro,Personagem *jogador){
    int n = rand()%2;
       int vidaAtual = jogador->trabalho.Get_VIDA();
    if(n==1){
        monstro->AtacarFisico(jogador);
        cout << "\nVoce tomou um ataque Fisico e agora \n |voce tem " <<  jogador->trabalho.Get_VIDA()  <<" De vida|\n";
        jogador->imprimirAtributos();
     return;   
    }
        monstro->AtacarMagico(jogador);
        cout << "\nVoce tomou um ataque Magico e agora \n |voce tem "  << jogador->trabalho.Get_VIDA()  << " De vida|\n";
        jogador->imprimirAtributos();
    return;
    
}
classe escolherClasse(int n){
    if(n == 1){
        return mago;
    }
    if(n==2){
        return guereiro;
    }
    if(n==4){
        return tanker;
    }
    return ladino;
}

int main() {
      srand(12312341);
    string nomePersonagem = "------";
    int idade  = 28;
    string sexo = "M";
    string raca = "elfo";
    int vida, ataqueFIS, ataqueMAG, resFIS, resMAG;
    string resposta;
   
   limparTela(); 
    printComDelay("Bem Vindo ao RNG RPG onde a sorte tem que estar ao seu lado!", 40);
    printComDelay("Para comecar, primeiro digite o nome do seu personagem: ", 50);
    getline(cin, nomePersonagem);
    printComDelay("Digite a idade do personagem: ", 40);
    cin >> idade;
    cin.ignore();
    printComDelay("Digite o sexo do personagem: ", 40);
    getline(cin, sexo);
    printComDelay("Digite a raça do personagem: ", 40);
    getline(cin, raca);
    printComDelay("Escolha sua classe", 40);
    cout << "[1]---------------------------\n";
    mago.imprimirAtributos();
    cout << "[2]---------------------------\n";
    guereiro.imprimirAtributos();
    cout << "[3]---------------------------\n";
    ladino.imprimirAtributos();
    cout << "[4] --------------------------\n";
    tanker.imprimirAtributos();
    int escolha;
    cin >> escolha;
    classe classejogador  =   escolherClasse(escolha);
    
    Personagem* jogador = new Personagem(nomePersonagem,idade,sexo,raca,classejogador);


limparTela();

  
    Personagem* monstro;
    item* equipamento;
    GeradorDeEntidades* gerador = new GeradorDeEntidades();
    
    vector<item*> itensGerados;
    for (int i = 0; i < 10; i++) {
        item* equipamento = gerador->gerarItem();
        itensGerados.push_back(equipamento);

        cout << "Item " << i + 1 << ":\n";
        equipamento->imprimirBonus();
        cout << "---------------------------\n";
    }
    

    cout << "Escolha um item para ficar (1 a 10): ";
    cin >> escolha;
    limparTela();

    if (escolha >= 1 && escolha <= 10) {
        item* itemEscolhido = itensGerados[escolha - 1];
        cout << "Item escolhido:\n";
        jogador->addItems(*itemEscolhido);
        itemEscolhido->imprimirBonus();
        gerador->inventario.adicionarItem(*itemEscolhido);
        cout << "Item adicionado ao inventário.\n";
        for (size_t i = 0; i < itensGerados.size(); ++i) {
            if (i != escolha - 1) {
                delete itensGerados[i];
            }
        }
        itensGerados.clear();

    } else {
        cout << "Escolha inválida.\n";
    }
    
    
    this_thread::sleep_for(chrono::milliseconds(2000));
    limparTela();
    
  
    gerador-> nivelDeDificuldade = 0 ;

while(1){
    monstro = gerador->gerarMonstro();
    gerador-> nivelDeDificuldade +=5;
    printComDelay("Voce encontrou um monstro!!:", 30);
    printComDelay("Seus atributos atuais:\n------------------------", 30);
    jogador->imprimirAtributos();
    cout << "----------------------------------\n";
    monstro->imprimirAtributos();
   do{
       cout << "--------------------------------\n";
       printComDelay("O que voce Faz?\n [1] Atacar fiscamente, \n [2] Atacar Magicamente \n [3] Defender Fisico \n [4] Defender Magicamente", 30);
       cin >> escolha;
       limparTela();
       cout << "-------------------------------------------------\n";
       escolherAcao(escolha,monstro,jogador);
       monstro->imprimirAtributos();
       turnoDoMostro(monstro,jogador);
       if(jogador->trabalho.Get_VIDA() == 0){
           printComDelay("Fim de jogo", 30);
         return 0;
       }

   }while(monstro->trabalho.Get_VIDA()>0); {
       limparTela();
       printComDelay("Parabéns, voce derrotou o monstro", 30);
       subirNivel(*jogador);
       jogador->trabalho.Set_VIDA(jogador->trabalho.Get_VIDA() + 10);
       jogador->imprimirAtributos();
       item* itemGerado = gerador->gerarItem();
       this_thread::sleep_for(chrono::milliseconds(2000));
       gerador->inventario.exibirInventario();
       limparTela();
       printComDelay("Você achou a " + itemGerado->nome + "deseja equipar?: \n [1] Sim \n [2] Não", 30);
       itemGerado->imprimirBonus();
        cin>> escolha;
        if(escolha ==1){
            jogador->addItems(*itemGerado);
        }
        this_thread::sleep_for(chrono::milliseconds(2000));
        limparTela();
   }}
   
  /* int indice;
    cout << "Quer remover algum item do inventário? (sim ou não): ";
    cin >> resposta;
    if (resposta == "sim") {
        cout << "Digite o número do item que deseja remover: ";
        cin >> indice;
        gerador->inventario.removerItem(indice - 1);
    } else if (resposta == "não") {
        cout << "Nenhum item removido." << endl;
    } else {
        cout << "Resposta inválida. Nenhum item removido." << endl;
    }
      */
    delete gerador; 
    return 0;
}
