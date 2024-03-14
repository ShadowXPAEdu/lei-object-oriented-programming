#pragma once

#include "Tecnologia.h"

class Defesas_Territoriais : public Tecnologia {
private:
public:
	Defesas_Territoriais();
	Defesas_Territoriais(Defesas_Territoriais &);
	~Defesas_Territoriais();
	bool comprar(Imperio_Jogador &) override;
	Tecnologia *novo() override;
};
