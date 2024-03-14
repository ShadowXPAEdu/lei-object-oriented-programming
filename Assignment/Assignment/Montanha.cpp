#include "Montanha.h"

Montanha::Montanha() : Continente("Montanha", 6, 0, 0) {
    this->turno_conquistado = 0;
}

Montanha::Montanha(Montanha &ter) : Continente(ter) {
    this->turno_conquistado = ter.turno_conquistado;
}

Montanha::~Montanha() {}

void Montanha::set_criacao_produtos(int turno) {
    if ((turno - this->turno_conquistado) >= 2) {
        this->criacao_produtos = 1;
    }
}

void Montanha::set_criacao_ouro(int) {}

bool Montanha::ser_conquistado(Imperio_Jogador &imp, int turno) {
    bool temp = Continente::ser_conquistado(imp);
    if (temp) {
        this->turno_conquistado = turno;
    }
    return temp;
}

Territorio *Montanha::novo() {
    return new Montanha(*this);
}
