#include "Bolsa_Valores.h"

Bolsa_Valores::Bolsa_Valores() : Tecnologia("BolsaValores", "Sistema comercial que torna possivel as trocas entre produtos e ouro.", 2) {}

Bolsa_Valores::Bolsa_Valores(Bolsa_Valores &tec) : Tecnologia(tec) {}

Bolsa_Valores::~Bolsa_Valores() {}

bool Bolsa_Valores::comprar(Imperio_Jogador &imp) {
    return Tecnologia::comprar(imp);
}

Tecnologia *Bolsa_Valores::novo() {
    return new Bolsa_Valores(*this);
}
