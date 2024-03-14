#pragma once

#include "Territorio.h"

class Territorio_Inicial : public Territorio {
public:
	Territorio_Inicial();
	Territorio_Inicial(Territorio_Inicial &);
	~Territorio_Inicial();
	void set_criacao_produtos(int) override;
	void set_criacao_ouro(int) override;
	bool ser_conquistado(Imperio_Jogador &, int = 0) override;
	Territorio *novo() override;
};
