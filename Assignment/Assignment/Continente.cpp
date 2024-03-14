#include "Continente.h"
#include "Imperio_Jogador.h"

using namespace std;

Continente::Continente(string nome, int resistencia, int criacao_produtos, int criacao_ouro) : Territorio(nome, 1, resistencia, criacao_produtos, criacao_ouro) {
	unsigned int static s_count = 0;
	s_count++;
	this->nome += to_string(s_count);
}

Continente::Continente(Continente &ter) : Territorio(ter) {}

Continente::~Continente() {}

bool Continente::ser_conquistado(Imperio_Jogador &imp, int) {
	return imp.adicionar_territorio_conquistado(this);
}
