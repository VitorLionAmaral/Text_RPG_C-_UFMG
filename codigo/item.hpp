#ifndef item_H
#define item_H
#include <string>
class item{
public:
 std::string nome; 
 int vida_bonus;
 int ataque_FIS_bonus;
 int ataque_MAG_bonus;
 int res_FIS_bonus;
 int res_Mag_bonus;
 
 item(std::string nome, 
 int vida_bonus,
 int ataque_FIS_bonus,
 int ataque_MAG_bonus,
 int res_FIS_bonus,
 int res_Mag_bonus);
 void imprimirBonus();
};

#endif
