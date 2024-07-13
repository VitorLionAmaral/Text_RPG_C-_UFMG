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
    this->defendeuF = 0;  
    this->defendeuM = 0;
}

void Personagem::addItems(item it){
    this->trabalho.Set_VIDA(this->trabalho.Get_VIDA() + it.vida_bonus);
    this->trabalho.Set_ataque_FIS(this->trabalho.Get_ataque_FIS() + it.ataque_FIS_bonus);
    this->trabalho.Set_ataque_MAG(this->trabalho.Get_ataque_MAG() + it.ataque_MAG_bonus);
    this->trabalho.Set_res_FIS(this->trabalho.Get_res_FIS() + it.res_FIS_bonus);
    this->trabalho.Set_res_Mag(this->trabalho.Get_res_Mag() + it.res_Mag_bonus);
}

void Personagem::removerItem(item it) {
    this->trabalho.Set_VIDA(this->trabalho.Get_VIDA() - it.vida_bonus);
    this->trabalho.Set_ataque_FIS(this->trabalho.Get_ataque_FIS() - it.ataque_FIS_bonus);
    this->trabalho.Set_ataque_MAG(this->trabalho.Get_ataque_MAG() - it.ataque_MAG_bonus);
    this->trabalho.Set_res_FIS(this->trabalho.Get_res_FIS() - it.res_FIS_bonus);
    this->trabalho.Set_res_Mag(this->trabalho.Get_res_Mag() - it.res_Mag_bonus);
}

void Personagem::AtacarFisico(Personagem *monstro) {
    if (this->defendeuF == 1) {
        defendeuF = 0;
        this->trabalho.Set_res_FIS(this->trabalho.Get_res_FIS() - 10);
    }
    if (this->defendeuM == 1) {
        defendeuM = 0;
        this->trabalho.Set_res_Mag(this->trabalho.Get_res_Mag() - 10);
    }

    int num = rand() % 100;
    int chance_de_ataque = this->trabalho.Get_ataque_FIS() - monstro->trabalho.Get_res_FIS();

    if (num < chance_de_ataque) {
        monstro->trabalho.Set_VIDA(monstro->trabalho.Get_VIDA() - this->trabalho.Get_ataque_FIS());
        cout << "\n" + monstro->nome + " sofreu um ataque físico!\n";
    } else {
        cout << "\n" + monstro->nome + " Defendeu o ataque físico!\n";
    }
}

void Personagem::AtacarMagico(Personagem *monstro) {
    if (this->defendeuF == 1) {
        defendeuF = 0;
        this->trabalho.Set_res_FIS(this->trabalho.Get_res_FIS() - 10);
    }
    if (this->defendeuM == 1) {
        defendeuM = 0;
        this->trabalho.Set_res_Mag(this->trabalho.Get_res_Mag() - 10);
    }

    int num = rand() % 100;
    int chance_de_ataque = this->trabalho.Get_ataque_MAG() - monstro->trabalho.Get_res_Mag();

    if (num < chance_de_ataque) {
        monstro->trabalho.Set_VIDA(monstro->trabalho.Get_VIDA() - this->trabalho.Get_ataque_MAG());
        cout << "\n" + monstro->nome + " sofreu um ataque mágico!\n";
    } else {
        cout << monstro->nome + " Defendeu o ataque mágico!\n";
    }
}

void Personagem::DefenderFisico() {
    if (this->defendeuF == 0) {
        this->defendeuF = 1;
        this->trabalho.Set_res_FIS(this->trabalho.Get_res_FIS() + 10);
        cout << "Você está se defendendo fisicamente!\n";
    } else {
        cout << "Você já está se defendendo fisicamente!\n";
    }
}

void Personagem::DefenderMagico() {
    if (this->defendeuM == 0) {
        this->defendeuM = 1;
        this->trabalho.Set_res_Mag(this->trabalho.Get_res_Mag() + 10);
        cout << "Você está se defendendo magicamente!\n";
    } else {
        cout << "Você já está se defendendo magicamente!\n";
    }
}

void Personagem::imprimirAtributos() {
    cout << this->nome << std::endl;
    cout << "Vida: " << trabalho.Get_VIDA() << std::endl;
    cout << "Ataque Físico: " << trabalho.Get_ataque_FIS() << std::endl;
    cout << "Ataque Mágico: " << trabalho.Get_ataque_MAG() << std::endl;
    cout << "Resistência Física: " << trabalho.Get_res_FIS() << std::endl;
    cout << "Resistência Mágica: " << trabalho.Get_res_Mag() << std::endl;
}

