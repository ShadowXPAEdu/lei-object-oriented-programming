#pragma once

#include "Territorio.h"

class Ilha : public Territorio {
public:
	Ilha(std::string, int, int, int);
	Ilha(Ilha &);
	~Ilha();
	bool ser_conquistado(Imperio_Jogador &, int = 0) override;
	Territorio *novo() = 0;
};
