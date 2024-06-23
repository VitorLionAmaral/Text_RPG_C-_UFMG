#include "classe.hpp"
#include <iostream>
#include <string>
using namespace std;





classe::classe(std::string nome, int vida,int ataque_FIS,int ataque_MAG, int res_FIS, int res_MAG){
    this->nome = nome;
    Set_VIDA(vida);
    Set_ataque_FIS(ataque_FIS);
    Set_ataque_MAG(ataque_MAG);
    Set_res_FIS(res_FIS);
    Set_res_Mag(res_MAG);
}

void classe::imprimirAtributos(){
    cout << this->nome << std::endl;
    cout << "Vida: " << this->Get_VIDA() << std::endl;
    cout << "Ataque Físico: " << this->Get_ataque_FIS() << std::endl;
    cout << "Ataque Mágico: " << this->Get_ataque_MAG() << std::endl;
    cout << "Resistência Física: " << this->Get_res_FIS() << std::endl;
    cout << "Resistência Mágica: " << this->Get_res_Mag() << std::endl;
    
    
}


void classe::Set_VIDA(int vida){
    if(vida >= 0 ){
    this->vida = vida;
    }else{
        this->vida = 0;
    }
}
void classe::Set_ataque_FIS(int ataque_FIS){
    if(ataque_FIS >=0){
    this->ataque_FIS = ataque_FIS;}
    else{
        this->ataque_FIS =0;
    }
}
void classe::Set_ataque_MAG(int ataque_MAG){
    if(ataque_MAG >=0){
    this->ataque_MAG = ataque_MAG;}else{
        this->ataque_MAG =0;
    }
}
void classe::Set_res_FIS(int res_FIS){
    if(res_FIS>=0){
    this->res_FIS = res_FIS;}
    else{
        this->res_FIS =0;
    }
}
void classe::Set_res_Mag(int res_MAG){
    if(res_MAG >=0){
    this->res_MAG = res_MAG;}
    else{
        this->res_MAG = 0;
    }
}
    
    
int classe::Get_VIDA(){
    return this->vida;
}
int classe::Get_ataque_FIS(){
    return this->ataque_FIS;
}
int classe::Get_ataque_MAG(){
    return this->ataque_MAG;
}
int classe::Get_res_FIS(){
    return this->res_FIS;
}
int classe::Get_res_Mag(){
    return this->res_MAG;
}






