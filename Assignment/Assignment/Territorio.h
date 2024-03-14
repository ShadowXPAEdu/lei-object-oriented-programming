#pragma once

class Imperio_Jogador;
#include <string>
#include <iostream>

class Territorio {
protected:
	std::string nome;
	int pontos_vitoria;
	int resistencia;
	int criacao_produtos;
	int criacao_ouro;
public:
	Territorio(std::string, int, int, int, int);
	~Territorio();
	std::string get_nome();
	int get_pontos_vitoria();
	int get_resistencia();
	int get_criacao_produtos();
	int get_criacao_ouro();
	virtual void set_criacao_produtos(int) = 0;
	virtual void set_criacao_ouro(int) = 0;
	virtual bool ser_conquistado(Imperio_Jogador &, int = 0) = 0;
	bool tomar_posse(Imperio_Jogador &);
	virtual Territorio *novo() = 0;
};
