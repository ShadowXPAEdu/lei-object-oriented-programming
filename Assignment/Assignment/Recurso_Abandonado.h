#pragma once

#include "Evento.h"

class Recurso_Abandonado : public Evento {
private:
public:
	Recurso_Abandonado();
	Recurso_Abandonado(Recurso_Abandonado &);
	~Recurso_Abandonado();
	void efeito(Imperio_Jogador *const, const float) override;
	Evento *novo() override;
};
