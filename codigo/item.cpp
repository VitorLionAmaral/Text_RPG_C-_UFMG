#include <iostream>
#include <string> 
#include "item.hpp"
using namespace std;



item::item(std::string nome, 
 int vida_bonus,
 int ataque_FIS_bonus,
 int ataque_MAG_bonus,
 int res_FIS_bonus,
 int res_Mag_bonus){

 this->nome = nome ; 
 this->vida_bonus = vida_bonus ;
 this->ataque_FIS_bonus = ataque_FIS_bonus;
 this->ataque_MAG_bonus = ataque_MAG_bonus;
 this->res_FIS_bonus = res_FIS_bonus;
 this->res_Mag_bonus = res_Mag_bonus;
 }
void item::imprimirBonus(){
    cout << this->nome << std::endl;
    cout << "Vida: " << vida_bonus << std::endl;
    cout << "Ataque Físico: " << ataque_FIS_bonus << std::endl;
    cout << "Ataque Mágico: " << ataque_MAG_bonus << std::endl;
    cout << "Resistência Física: " << res_FIS_bonus << std::endl;
    cout << "Resistência Mágica: " << res_Mag_bonus << std::endl;
}

