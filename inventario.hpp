#ifndef INVENTARIO_HPP
#define INVENTARIO_HPP

#include <vector>
#include "item.hpp"

class Inventario {
private:
    std::vector<item> itens;

public:
    void adicionarItem(const item& novoItem);
    void removerItem(int index);
    void exibirInventario();
    void limparInventario();
};

#endif
