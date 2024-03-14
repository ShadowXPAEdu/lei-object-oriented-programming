#pragma once

#include "Continente.h"

class Montanha : public Continente {
private:
	int turno_conquistado;
public:
	Montanha();
	Montanha(Montanha &);
	~Montanha();
	void set_criacao_produtos(int) override;
	void set_criacao_ouro(int) override;
	bool ser_conquistado(Imperio_Jogador &, int = 0) override;
	Territorio *novo() override;
};
