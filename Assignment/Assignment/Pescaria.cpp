#include "Pescaria.h"

Pescaria::Pescaria() : Ilha("Pescaria", 9, 2, 0) {}

Pescaria::Pescaria(Pescaria &ter) : Ilha(ter) {}

Pescaria::~Pescaria() {}

void Pescaria::set_criacao_produtos(int turno) {
    if (turno <= 5) {
        this->criacao_produtos = 2;
    } else {
        this->criacao_produtos = 4;
    }
}

void Pescaria::set_criacao_ouro(int) {}

Territorio *Pescaria::novo() {
    return new Pescaria(*this);
}
