#pragma once

class Imperio_Jogador;
#include <string>
#include <iostream>

class Evento {
protected:
	std::string nome;
	std::string descricao;
public:
	Evento();
	Evento(Evento &);
	Evento(std::string, std::string);
	~Evento();
	std::string get_nome();
	std::string get_descricao();
	virtual void efeito(Imperio_Jogador *const, const float);
	virtual Evento *novo();
};
