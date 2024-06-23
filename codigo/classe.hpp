#ifndef classe_H 
#define classe_H

#include <string>

class classe{
   
public:
    classe(std::string nome ,int vida,int ataque_FIS,int ataque_MAG, int res_FIS, int res_MAG);
    std::string nome;
    void Set_VIDA(int vida);
    void Set_ataque_FIS(int ataque_FIS);
    void Set_ataque_MAG(int ataque_MAG);
    void Set_res_FIS(int res_FIS);
    void Set_res_Mag(int res_MAG);
    void imprimirAtributos();
    
    int Get_VIDA();
    int Get_ataque_FIS();
    int Get_ataque_MAG();
    int Get_res_FIS();
    int Get_res_Mag();
    
private:
    int vida;
    int ataque_FIS;
    int ataque_MAG;
    int res_FIS;
    int res_MAG;
};

#endif
