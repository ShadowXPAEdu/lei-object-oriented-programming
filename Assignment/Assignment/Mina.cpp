#include "Mina.h"

Mina::Mina() : Continente("Mina", 5, 0, 0) {}

Mina::Mina(Mina &ter) : Continente(ter) {}

Mina::~Mina() {}

void Mina::set_criacao_produtos(int) {}

void Mina::set_criacao_ouro(int turno) {
    if (turno <= 2 || (turno >= 6 && turno <= 8)) {
        this->criacao_ouro = 1;
    } else {
        this->criacao_ouro = 2;
    }
}

Territorio *Mina::novo() {
    return new Mina(*this);
}
