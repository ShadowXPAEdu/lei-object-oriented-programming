#include "Castelo.h"

Castelo::Castelo() : Continente("Castelo", 7, 0, 1) {}

Castelo::Castelo(Castelo &ter) : Continente(ter) {}

Castelo::~Castelo() {}

void Castelo::set_criacao_produtos(int turno) {
    if (turno <= 1 || (turno >= 6 && turno <= 7)) {
        this->criacao_produtos = 3;
    } else {
        this->criacao_produtos = 0;
    }
}

void Castelo::set_criacao_ouro(int) {}

Territorio *Castelo::novo() {
    return new Castelo(*this);
}
