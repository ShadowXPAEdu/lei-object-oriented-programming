#include "Drones_Militares.h"
#include "Imperio_Jogador.h"

Drones_Militares::Drones_Militares() : Tecnologia("DronesMilitares", "Esta tecnologia faz passar o limite maximo da forca militar para cinco.", 3) {}

Drones_Militares::Drones_Militares(Drones_Militares &tec) : Tecnologia(tec) {}

Drones_Militares::~Drones_Militares() {}

bool Drones_Militares::comprar(Imperio_Jogador &imp) {
	if (Tecnologia::comprar(imp)) {
		imp.set_forca_militar();
		return true;
	}
	return false;
}

Tecnologia *Drones_Militares::novo() {
	return new Drones_Militares(*this);
}
