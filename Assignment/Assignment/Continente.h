#pragma once

#include "Territorio.h"

class Continente : public Territorio {
public:
	Continente(std::string, int, int, int);
	Continente(Continente &);
	~Continente();
	bool ser_conquistado(Imperio_Jogador &, int = 0) override;
	Territorio *novo() = 0;
};
