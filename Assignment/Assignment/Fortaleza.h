#pragma once

#include "Continente.h"

class Fortaleza : public Continente {
public:
	Fortaleza();
	Fortaleza(Fortaleza &);
	~Fortaleza();
	void set_criacao_produtos(int) override;
	void set_criacao_ouro(int) override;
	Territorio *novo() override;
};
