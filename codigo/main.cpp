
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
#include <vector>

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
    personagem.trabalho.Set_VIDA(vidaAtual + 20);

    int ataqueFisicoAtual = personagem.trabalho.Get_ataque_FIS();
    personagem.trabalho.Set_ataque_FIS(ataqueFisicoAtual + 20);

    int ataqueMagicoAtual = personagem.trabalho.Get_ataque_MAG();
    personagem.trabalho.Set_ataque_MAG(ataqueMagicoAtual + 20);

    int resistenciaFisicaAtual = personagem.trabalho.Get_res_FIS();
    personagem.trabalho.Set_res_FIS(resistenciaFisicaAtual + 20);

    int resistenciaMagicaAtual = personagem.trabalho.Get_res_Mag();
    personagem.trabalho.Set_res_Mag(resistenciaMagicaAtual + 20);
    
    printComDelay("Você subiu de nível! Seus atributos aumentaram.", 40); 
}

classe mago = classe("Mago",60,30,150,10,20);
classe guereiro = classe("guereiro",150,60,20,20,10);
classe ladino = classe("ladino",80,150,20,10,10);
classe tanker = classe("tanker",200,30,30,15,15);

void escolherAcao(int n, Personagem * monstro, Personagem *jogador) {
    if(n == 1) jogador->AtacarFisico(monstro);
    if(n == 2) jogador->AtacarMagico(monstro);
    if(n == 3) jogador->DefenderFisico();
    if(n == 4) jogador->DefenderMagico();
}

void turnoDoMostro(Personagem *monstro, Personagem *jogador) {
    int vidaInicial = jogador->trabalho.Get_VIDA();
    int dano;

    int n = rand() % 2;
    if (n == 1) {
        monstro->AtacarFisico(jogador);
        dano = vidaInicial - jogador->trabalho.Get_VIDA();
        cout << "\nVocê tomou um ataque Físico de " << dano << " de dano.\n";
    } else {
        monstro->AtacarMagico(jogador);
        dano = vidaInicial - jogador->trabalho.Get_VIDA();
        cout << "\nVocê tomou um ataque Mágico de " << dano << " de dano.\n";
    }

    jogador->imprimirAtributos();
}

classe escolherClasse(int n) {
    if(n == 1) return mago;
    if(n == 2) return guereiro;
    if(n == 4) return tanker;
    return ladino;
}

void removerItemDoInventario(GeradorDeEntidades* gerador, Personagem* jogador) {
    gerador->inventario.exibirInventario();
    
    int indice;
    cout << "Digite o número do item que deseja remover (1 a " << gerador->inventario.getTotalItens() << "): ";
    cin >> indice;
    
    if (cin.fail()) {
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Nenhum item removido.\n";
        return;
    }
    
    if (indice >= 1 && indice <= gerador->inventario.getTotalItens()) {
        item it = gerador->inventario.getItem(indice - 1);
        jogador->removerItem(it);  // Atualizar atributos do personagem
        gerador->inventario.removerItem(indice - 1); 
        cout << "Item removido do inventário.\n";
    } else {
        cout << "Índice inválido. Nenhum item removido.\n";
    }
}


int main() {
    
    limparTela(); 
    int semente;

    string nomePersonagem;
    int idade;
    string sexo;
    string raca;
    string resposta;
   
    limparTela(); 
    printComDelay("Bem Vindo ao RNG RPG onde a sorte tem que estar ao seu lado!", 40);
    cout << "Dessa forma entre com um numero, será seu numero da sorte, nao se engane esse numero ira ditar o seu percurso" << endl;
    cin >> semente;
    
    if (std::cin.fail()) {
            std::cin.clear(); // Limpa o erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora a entrad)
            semente = 123112341;
    }
 
     string confirmacaoPerfil;   
    do {
        printComDelay("Para começar, primeiro digite o nome do seu personagem: ", 50);
        std::getline(std::cin, nomePersonagem);

        printComDelay("Digite a idade do personagem: ", 40);
        while (!(std::cin >> idade)) {
            std::cin.clear(); // Limpa o estado de erro de cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora a entrada inválida
            printComDelay("Por favor, digite um número para a idade do personagem: ", 40);
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Limpa o buffer de entrada

        printComDelay("Digite o sexo do personagem: ", 40);
        std::getline(std::cin, sexo);

        printComDelay("Digite a raça do personagem: ", 40);
        std::getline(std::cin, raca);
        Recomecar:
        std::cout << std::endl;
        printComDelay("Confirme seu personagem, não poderá alterar seus dados posteriormente:", 40);
        std::cout << "Nome: " << nomePersonagem << std::endl; 
        std::cout << "Idade: " << idade << std::endl;
        std::cout << "Sexo: " << sexo << std::endl;
        std::cout << "Raça: " << raca << std::endl;

        std::cout << "Caso queira redefinir, escreva 'Redefinir': ";
        std::getline(std::cin, confirmacaoPerfil);

    } while (confirmacaoPerfil == "Redefinir");
    limparTela();
    printComDelay("Escolha sua classe", 40);
    cout << "[1]---------------------------\n";
    mago.imprimirAtributos();
    cout << "[2]---------------------------\n";
    guereiro.imprimirAtributos();
    cout << "[3]---------------------------\n";
    ladino.imprimirAtributos();
    cout << "[4]---------------------------\n";
    tanker.imprimirAtributos();
    int escolha = 5;
    do{
        cin >> escolha;
        if (std::cin.fail()) {
            std::cin.clear(); // Limpa o erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora a entrada inválida
            printComDelay("Para sobreviver no labirinto você precisa escolher uma classe", 40); 
            }else if(escolha < 1 || escolha > 4){
                printComDelay("Para sobreviver no labirinto voce precisa escolher uma classe", 40);
                printComDelay("Escolha uma classe (1-4): ", 20);
                std::cout << "1 = Mago" << endl;
                std::cout << "2 = Guerreiro" << endl;
                std::cout << "3 = Ladino" << endl;
                std::cout << "4 = Tanker" << endl;
        }
    }while( escolha  < 1 || escolha > 4 );
 
    classe classejogador = escolherClasse(escolha);
    
    Personagem* jogador = new Personagem(nomePersonagem, idade, sexo, raca, classejogador);

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

    escolha =0;
    do{
        cin >> escolha;
        if (std::cin.fail()) {
            std::cin.clear(); // Limpa o erro
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora a entrada inválida
            printComDelay("Para sobreviver no labirinto você precisara de um equipamento", 40); 
            }else if(escolha < 1 || escolha >10 ){
                printComDelay("Para sobreviver no labirinto voce precisara de um equipamento", 40);

        }
    }while( escolha  < 1 || escolha > 10 );
    
    this_thread::sleep_for(chrono::milliseconds(2000));
    limparTela();
    
    gerador->nivelDeDificuldade = 10;


    string recomecarJogo;
    int andar = 0;
    while (1) {
        monstro = gerador->gerarMonstro();
        gerador->nivelDeDificuldade += 10;
        printComDelay("Você encontrou um monstro!!", 30);
        printComDelay("Seus atributos atuais:\n------------------------", 30);
        jogador->imprimirAtributos();
        cout << "----------------------------------\n";
        monstro->imprimirAtributos();
        
        do {
            cout << "--------------------------------\n";
            printComDelay("O que você faz?\n[1] Atacar fisicamente\n[2] Atacar magicamente\n[3] Defender físico\n[4] Defender mágico", 30);
            cin >> escolha;
            limparTela();
            cout << "-------------------------------------------------\n";
            escolherAcao(escolha, monstro, jogador);
            monstro->imprimirAtributos();
            turnoDoMostro(monstro, jogador);
            if (jogador->trabalho.Get_VIDA() == 0) {
                printComDelay("Fim de jogo", 30);
                return 0;
            }
            
        } while (monstro->trabalho.Get_VIDA() > 0);
        
        limparTela();
        andar += 1;
        if( andar == 10){
            printComDelay("Voce conquistou a Masmorra !!!", 60);
            cout << nomePersonagem << ",gostaria de jogar novamente ?" << endl;
            cin >> recomecarJogo;
            if(recomecarJogo !="Sim"){
                return 0;
            }else{
                goto Recomecar;
            }
        }
            
            
        printComDelay("Parabéns, você derrotou o monstro", 30);
        subirNivel(*jogador);
        jogador->trabalho.Set_VIDA(jogador->trabalho.Get_VIDA() + 30);
        jogador->imprimirAtributos();
        item* itemGerado = gerador->gerarItem();
        this_thread::sleep_for(chrono::milliseconds(2000));
        limparTela();
        printComDelay("Você achou a " + itemGerado->nome + ". Deseja equipar?\n[1] Sim\n[2] Não", 30);
        itemGerado->imprimirBonus();
        
       int indice_repeticao = 0;
       escolha = 0;
       do{
            cin >> escolha;
            if (std::cin.fail()) {
                std::cin.clear(); // Limpa o erro
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora a entrada inválida
                printComDelay("Escolha entre: \n [1] Pegar o item \n [2]Abandonar o item" , 40);
            }else{
                indice_repeticao +=1;
                cout << "Pense bem caso nao escolha, " << itemGerado->nome << " será descartado" << endl;
                escolha = 2;
            }   
        }while(escolha  < 1 || escolha > 2);
        

        if (escolha == 1) {
            if (gerador->inventario.getTotalItens() >= 10) {
                cout << "Seu inventário está cheio. Você deve remover um item antes de adicionar um novo.\n";
                removerItemDoInventario(gerador, jogador);
                cout << "Deseja tentar adicionar o novo item novamente?\n[1] Sim\n[2] Não\n";
                cin >> escolha;
                if (escolha == 1) {
                    jogador->addItems(*itemGerado);
                    gerador->inventario.adicionarItem(*itemGerado);
                    cout << "Novo item adicionado ao inventário.\n";
                } else {
                    cout << "Você optou por não adicionar o novo item.\n";
                }
            } else {
                jogador->addItems(*itemGerado);  
                gerador->inventario.adicionarItem(*itemGerado);
                cout << "Novo item adicionado ao inventário.\n";
            }
        }

        this_thread::sleep_for(chrono::milliseconds(2000));
        limparTela();
    }
    
    delete gerador; 
    return 0;
}

