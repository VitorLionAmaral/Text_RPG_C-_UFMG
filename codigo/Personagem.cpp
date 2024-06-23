#include "Personagem.hpp"
#include <iostream>
#include <cmath> 
#include "item.hpp"
#include "Personagem.hpp"
#include "classe.hpp"
using namespace std;

Personagem::Personagem(std::string nome,int idade,std::string sexo,std::string raca,classe trabalho){
    this->nome = nome;
    this->idade = idade;
    this->sexo = sexo;
    this->raca = raca;
    this->trabalho  = trabalho;
}


void Personagem::addItems(item it){
    this->trabalho.Set_VIDA(this->trabalho.Get_VIDA() + it.vida_bonus);
    this->trabalho.Set_ataque_FIS(this->trabalho.Get_ataque_FIS() + it.ataque_FIS_bonus);
    this->trabalho.Set_ataque_MAG(this->trabalho.Get_ataque_MAG() + it.ataque_MAG_bonus);
    this->trabalho.Set_res_FIS(this->trabalho.Get_res_FIS() + it.res_FIS_bonus);
    this->trabalho.Set_res_Mag(this->trabalho.Get_res_Mag() + it.res_Mag_bonus);
}

void Personagem::AtacarFisico(Personagem *monstro){
    if(this-> defendeuF ==1) {
        defendeuF = 0 ;
        this->trabalho.Set_res_FIS(this->trabalho.Get_res_FIS() - 10);
    }
    if(this->defendeuM==1){
        defendeuM = 0;
        this->trabalho.Set_res_Mag(this->trabalho.Get_res_Mag() - 10);
    }
    
    int num = rand()%100;
    
    if(monstro->trabalho.Get_res_FIS() < num){
        monstro->trabalho.Set_VIDA(monstro->trabalho.Get_VIDA() - this->trabalho.Get_ataque_FIS());
        return;
    }
    cout << "\n" + monstro->nome + "  Defendeu!\n";
}
void Personagem::AtacarMagico(Personagem *monstro){
     if(this-> defendeuF ==1) {
        defendeuF = 0 ;
        this->trabalho.Set_res_FIS(this->trabalho.Get_res_FIS() - 10);
    }
    if(this->defendeuM==1){
        defendeuM = 0;
        this->trabalho.Set_res_Mag(this->trabalho.Get_res_Mag() - 10);
    }
     int num = rand()%100;
     if(monstro->trabalho.Get_res_Mag() < num){
        monstro->trabalho.Set_VIDA(monstro->trabalho.Get_VIDA() - this->trabalho.Get_ataque_MAG());
    
         return;
     } cout << monstro->nome + " \nDefendeu!\n";
    
}

void Personagem::DefenderFisico(){
    if(this->defendeuF==0){
        this->defendeuF=1;
        this->trabalho.Set_res_FIS(this->trabalho.Get_res_FIS() + 10);
        return;
    }
    
    cout << "Você já esta se defendendo!\n";
    return;
    
}


void Personagem::DefenderMagico(){
     if(this->defendeuM==0){
         this->defendeuM=1;
        this->trabalho.Set_res_Mag(this->trabalho.Get_res_Mag() + 10);
        return;
    }
        cout << "Você já esta se defendendo!\n";
        return;
}

void Personagem::imprimirAtributos() {
    cout << this->nome << std::endl;
    cout << "Vida: " << trabalho.Get_VIDA() << std::endl;
    cout << "Ataque Físico: " << trabalho.Get_ataque_FIS() << std::endl;
    cout << "Ataque Mágico: " << trabalho.Get_ataque_MAG() << std::endl;
    cout << "Resistência Física: " << trabalho.Get_res_FIS() << std::endl;
    cout << "Resistência Mágica: " << trabalho.Get_res_Mag() << std::endl;
}
