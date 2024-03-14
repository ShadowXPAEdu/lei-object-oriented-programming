#include "Refugio_Piratas.h"

Refugio_Piratas::Refugio_Piratas() : Ilha("RefugioPiratas", 9, 0, 1) {}

Refugio_Piratas::Refugio_Piratas(Refugio_Piratas &ter) : Ilha(ter) {}

Refugio_Piratas::~Refugio_Piratas() {}

void Refugio_Piratas::set_criacao_produtos(int) {}

void Refugio_Piratas::set_criacao_ouro(int) {}

Territorio *Refugio_Piratas::novo() {
    return new Refugio_Piratas(*this);
}
