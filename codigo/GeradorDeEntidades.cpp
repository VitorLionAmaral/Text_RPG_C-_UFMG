#include "GeradorDeEntidades.hpp"
#include <string>
#include <cstdlib>
#include "item.hpp"
#include "Personagem.hpp"
#include "classe.hpp"
#include "inventario.hpp"

std::string GeradorDeEntidades::gerarNomeItem() {
    int indexSubitens = rand() % 95;
    int indexAdjItens = rand() % 102;
    return Subitens[indexSubitens] + " " + AdjItens[indexAdjItens];
}

item* GeradorDeEntidades::gerarItem() {
    
    int ContVatagem=0;
    int Vantagem[5];
    for(int i=0;i<5;i++){
        if(rand()%2 == 1){
            Vantagem[i] = -1;
            ContVatagem++;
        }else{
            Vantagem[i] =  1; 
            
        }
    }
    for(int i=0;i<5;i++){
       if(Vantagem[i]==1){
          Vantagem[i] = (ContVatagem*0.3) + (1+0.1*nivelDeDificuldade) + 1;
       }else{
           Vantagem[i] =  -(1+0.1*nivelDeDificuldade) - 1;
       }
    }
    
    
    
    std::string nome = gerarNomeItem();
    int vida_bonus = (rand() % 20) * Vantagem[0];
    int ataque_FIS_bonus = (rand() % 15) * Vantagem[1];
    int ataque_MAG_bonus = (rand() % 15) * Vantagem[2];
    int res_FIS_bonus = (rand() % 10) * Vantagem[3];
    int res_MAG_bonus = (rand() % 10) * Vantagem[4];

item* novoItem = new item(nome, vida_bonus, ataque_FIS_bonus, ataque_MAG_bonus, res_FIS_bonus, res_MAG_bonus);


    return novoItem;
}
std::string GeradorDeEntidades::gerarNomeMonstro() {
    int indexSubMonstros = rand() % 87;
    int indexAdjMonstros = rand() % 100;
    return SubMonstros[indexSubMonstros] + " " + AdjMonstros[indexAdjMonstros];
}

Personagem* GeradorDeEntidades::gerarMonstro() {
    std::string nome = gerarNomeMonstro();
    int idade = rand() % 100 + 1;
    std::string sexo = "Indefinido";
    std::string raca = "Monstro";

    int vida = (rand() % 90 + 10) * (1+0.1*this->nivelDeDificuldade);
    int ataque_FIS = (rand() % 40) * (1+0.1*this->nivelDeDificuldade);
    int ataque_MAG = (rand() % 40) * (1+0.1*this->nivelDeDificuldade);
    int res_FIS = (rand() % 30) * (1+0.1*this->nivelDeDificuldade);
    int res_MAG = (rand() % 30) * (1+0.1*this->nivelDeDificuldade);

    
    return new Personagem(nome,idade,sexo,raca, classe("monstro",vida,ataque_FIS,ataque_MAG,res_FIS,res_MAG));
    
}









