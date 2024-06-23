#include "inventario.hpp"
#include <iostream>

void Inventario::adicionarItem(const item& novoItem) {
    itens.push_back(novoItem);
}

void Inventario::removerItem(int indice) {
    if (indice >= 1 && indice <= static_cast<int>(itens.size())) {
        itens.erase(itens.begin() + indice - 1);
        std::cout << "Item removido com sucesso.\n";
    } else {
        std::cout << "Índice inválido. Nenhum item removido.\n";
    }
}

void Inventario::exibirInventario() {
    if (itens.empty()) {
        std::cout << "Inventário vazio\n";
    } else {
        std::cout << "Inventário:\n";
        for (size_t i = 0; i < itens.size(); ++i) {
            itens[i].imprimirBonus(); 
            std::cout << "---------------------------\n";
        }
    }
}

void Inventario::limparInventario() {
    itens.clear();
}