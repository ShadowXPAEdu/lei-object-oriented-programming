#pragma once

#include "Continente.h"

class Duna : public Continente {
public:
	Duna();
	Duna(Duna &);
	~Duna();
	void set_criacao_produtos(int) override;
	void set_criacao_ouro(int) override;
	Territorio *novo() override;
};
