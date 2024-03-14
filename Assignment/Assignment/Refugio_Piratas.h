#pragma once

#include "Ilha.h"

class Refugio_Piratas : public Ilha {
public:
	Refugio_Piratas();
	Refugio_Piratas(Refugio_Piratas &);
	~Refugio_Piratas();
	void set_criacao_produtos(int) override;
	void set_criacao_ouro(int) override;
	Territorio *novo() override;
};
