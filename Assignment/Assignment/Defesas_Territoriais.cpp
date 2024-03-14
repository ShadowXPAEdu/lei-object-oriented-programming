#include "Defesas_Territoriais.h"

Defesas_Territoriais::Defesas_Territoriais() : Tecnologia("DefesasTerritoriais", "E um equipamento especial de defesa que acrescenta uma unidade a resistencia do territorio invadido durante um evento de invasao.", 4) {}

Defesas_Territoriais::Defesas_Territoriais(Defesas_Territoriais &tec) : Tecnologia(tec) {}

Defesas_Territoriais::~Defesas_Territoriais() {}

bool Defesas_Territoriais::comprar(Imperio_Jogador &imp) {
    return Tecnologia::comprar(imp);
}

Tecnologia *Defesas_Territoriais::novo() {
    return new Defesas_Territoriais(*this);
}
