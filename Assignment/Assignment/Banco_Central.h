#pragma once

#include "Tecnologia.h"

class Banco_Central : public Tecnologia {
private:
public:
	Banco_Central();
	Banco_Central(Banco_Central &);
	~Banco_Central();
	bool comprar(Imperio_Jogador &) override;
	Tecnologia *novo() override;
};
