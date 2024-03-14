#pragma once

#include "Evento.h"

class Alianca_Diplomatica : public Evento {
private:
public:
	Alianca_Diplomatica();
	Alianca_Diplomatica(Alianca_Diplomatica &);
	~Alianca_Diplomatica();
	void efeito(Imperio_Jogador *const, const float) override;
	Evento *novo() override;
};
