#pragma once

#include "Ilha.h"

class Pescaria : public Ilha {
public:
	Pescaria();
	Pescaria(Pescaria &);
	~Pescaria();
	void set_criacao_produtos(int) override;
	void set_criacao_ouro(int) override;
	Territorio *novo() override;
};
