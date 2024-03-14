#pragma once

#include "Tecnologia.h"

class Bolsa_Valores : public Tecnologia {
private:
public:
	Bolsa_Valores();
	Bolsa_Valores(Bolsa_Valores &);
	~Bolsa_Valores();
	bool comprar(Imperio_Jogador &) override;
	Tecnologia *novo() override;
};
