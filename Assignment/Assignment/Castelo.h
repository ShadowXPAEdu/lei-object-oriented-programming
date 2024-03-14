#pragma once

#include "Continente.h"

class Castelo : public Continente {
public:
	Castelo();
	Castelo(Castelo &);
	~Castelo();
	void set_criacao_produtos(int) override;
	void set_criacao_ouro(int) override;
	Territorio *novo() override;
};
