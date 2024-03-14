#pragma once

#include "Tecnologia.h"

class Misseis_Teleguiados : public Tecnologia {
private:
public:
	Misseis_Teleguiados();
	Misseis_Teleguiados(Misseis_Teleguiados &);
	~Misseis_Teleguiados();
	bool comprar(Imperio_Jogador &) override;
	Tecnologia *novo() override;
};
