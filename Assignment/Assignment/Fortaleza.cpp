#include "Fortaleza.h"

Fortaleza::Fortaleza() : Continente("Fortaleza", 8, 0, 0) {}

Fortaleza::Fortaleza(Fortaleza &ter) : Continente(ter) {}

Fortaleza::~Fortaleza() {}

void Fortaleza::set_criacao_produtos(int) {}

void Fortaleza::set_criacao_ouro(int) {}

Territorio *Fortaleza::novo() {
    return new Fortaleza(*this);
}
