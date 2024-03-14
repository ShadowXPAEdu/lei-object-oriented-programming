#include "Gravacao.h"

Gravacao::Gravacao(std::string nome, Jogo &jogo) {
	this->nome = nome;
	this->jogo = new Jogo(jogo);
}

Gravacao::~Gravacao() {
	delete this->jogo;
}

std::string Gravacao::get_nome() {
	return this->nome;
}

Jogo *Gravacao::get_jogo() {
	return this->jogo;
}
