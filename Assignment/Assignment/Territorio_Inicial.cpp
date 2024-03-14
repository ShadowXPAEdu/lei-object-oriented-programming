#include "Territorio_Inicial.h"

Territorio_Inicial::Territorio_Inicial() : Territorio("TerritorioInicial", 0, 9, 1, 1) {}

Territorio_Inicial::Territorio_Inicial(Territorio_Inicial &ter) : Territorio(ter) {}

Territorio_Inicial::~Territorio_Inicial() {}

void Territorio_Inicial::set_criacao_produtos(int) {}

void Territorio_Inicial::set_criacao_ouro(int) {}

bool Territorio_Inicial::ser_conquistado(Imperio_Jogador &imp, int) {
    return false;
}

Territorio *Territorio_Inicial::novo() {
    return new Territorio_Inicial(*this);
}
