#include "Banco_Central.h"
#include "Imperio_Jogador.h"

Banco_Central::Banco_Central() : Tecnologia("BancoCentral", "Esta tecnologia permite aumentar em duas unidades a capacidade de armazenamento do armazem e do cofre do imperio.", 3) {}

Banco_Central::Banco_Central(Banco_Central &tec) : Tecnologia(tec) {}

Banco_Central::~Banco_Central() {}

bool Banco_Central::comprar(Imperio_Jogador &imp) {
	if (Tecnologia::comprar(imp)) {
		imp.set_armazem_cofre();
		return true;
	}
	return false;
}

Tecnologia *Banco_Central::novo() {
	return new Banco_Central(*this);
}
