#pragma once

#include <string>
#include "Jogo.h"

class Gravacao {
private:
	std::string nome;
	Jogo *jogo;
public:
	Gravacao(std::string, Jogo &);
	~Gravacao();
	std::string get_nome();
	Jogo *get_jogo();
};
