#include "Misseis_Teleguiados.h"

Misseis_Teleguiados::Misseis_Teleguiados() : Tecnologia("MisseisTeleguiados", "Esta tecnologia e necessaria para conquistar ilhas.", 4) {}

Misseis_Teleguiados::Misseis_Teleguiados(Misseis_Teleguiados &tec) : Tecnologia(tec) {}

Misseis_Teleguiados::~Misseis_Teleguiados() {}

bool Misseis_Teleguiados::comprar(Imperio_Jogador &imp) {
	return Tecnologia::comprar(imp);
}

Tecnologia *Misseis_Teleguiados::novo() {
	return new Misseis_Teleguiados(*this);
}
