#include "Evento.h"

using namespace std;

Evento::Evento() : Evento("SemEvento", "Nada ocorre e todos podem dormir descansados.") {}

Evento::Evento(Evento &evento) {
	this->nome = evento.nome;
	this->descricao = evento.descricao;
}

Evento::Evento(string nome, string descricao) {
	unsigned int static s_count = 0;
	s_count++;
	this->nome = nome;
	this->descricao = descricao;
	this->nome += to_string(s_count);
}

Evento::~Evento() {}

std::string Evento::get_nome() {
	return this->nome;
}

std::string Evento::get_descricao() {
	return this->descricao;
}

void Evento::efeito(Imperio_Jogador *const imp, const float ano) {
	cout << this->descricao << endl;
}

Evento *Evento::novo() {
	return new Evento(*this);
}
