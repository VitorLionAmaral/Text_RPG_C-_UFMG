#include "inventario.hpp"
#include <iostream>

void Inventario::adicionarItem(const item& novoItem) {
    itens.push_back(novoItem);
}

void Inventario::removerItem(int indice) {
    if (indice >= 1 && indice <= static_cast<int>(itens.size())) {
        itens.erase(itens.begin() + indice - 1);
    }
}

void Inventario::exibirInventario() {
    if (itens.empty()) {
        std::cout << "Inventário vazio\n";
    } else {
        std::cout << "Inventário:\n";
        for (size_t i = 0; i < itens.size(); ++i) {
            std::cout << "[" << i + 1 << "] "; 
            itens[i].imprimirBonus(); 
            std::cout << "---------------------------\n";
        }
    }
}

item Inventario::getItem(int index) const {
    if (index >= 0 && index < itens.size()) {
        return itens[index];
    } else {
        throw std::out_of_range("Índice fora do intervalo");
    }
}
void Inventario::limparInventario() {
    itens.clear();
}

int Inventario::getTotalItens() const {
    return itens.size(); 
}
