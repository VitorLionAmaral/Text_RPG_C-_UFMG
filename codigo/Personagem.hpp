#ifndef Personagem_H 
#define Personagem_H
#include <vector>
#include "classe.hpp"
#include "item.hpp"
#include "inventario.hpp"
#include <string>
class Personagem{

public:
    std::string nome;
    int idade;
    std::string sexo;
    std::string raca;
    classe trabalho = classe("vagabundo",100,30,30,30,30);
    Inventario intens; 
    int defendeuM=0;
    int defendeuF=0;
 
    
    Personagem(std::string nome,int idade,std::string sexo,std::string raca,classe trabalho);
    void addItems(item it);
    void AtacarFisico(Personagem *monstro);
    void AtacarMagico(Personagem *monstro);
    void DefenderFisico();
    void DefenderMagico();
    void printItems();
    void imprimirAtributos();
};

#endif
