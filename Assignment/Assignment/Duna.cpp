#include "Duna.h"

Duna::Duna() : Continente("Duna", 4, 1, 0) {}

Duna::Duna(Duna &ter) : Continente(ter) {}

Duna::~Duna() {}

void Duna::set_criacao_produtos(int) {}

void Duna::set_criacao_ouro(int) {}

Territorio *Duna::novo() {
    return new Duna(*this);
}
