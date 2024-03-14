#pragma once

#include "Evento.h"

class Invasao : public Evento {
private:
public:
	Invasao();
	Invasao(Invasao &);
	~Invasao();
	void efeito(Imperio_Jogador *const, const float) override;
	Evento *novo() override;
};
