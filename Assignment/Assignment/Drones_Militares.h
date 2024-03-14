#pragma once

#include "Tecnologia.h"

class Drones_Militares : public Tecnologia {
private:
public:
	Drones_Militares();
	Drones_Militares(Drones_Militares &);
	~Drones_Militares();
	bool comprar(Imperio_Jogador &) override;
	Tecnologia *novo() override;
};
