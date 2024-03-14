#include "Tecnologia.h"
#include "Imperio_Jogador.h"

using namespace std;

Tecnologia::Tecnologia(string nome, string objetivo, int custo) {
	this->nome = nome;
	this->objetivo = objetivo;
	this->custo = custo;
	this->adquirido = false;
}

Tecnologia::Tecnologia(Tecnologia &tec) {
	this->nome = tec.nome;
	this->objetivo = tec.objetivo;
	this->custo = tec.custo;
	this->adquirido = tec.adquirido;
}

Tecnologia::~Tecnologia() {}

string Tecnologia::get_nome() {
	return string(this->nome);
}

int Tecnologia::get_custo() {
	return this->custo;
}

string Tecnologia::get_objetivo() {
	return string(this->objetivo);
}

bool Tecnologia::ja_adquirido() {
	return this->adquirido;
}

bool Tecnologia::tomar() {
	if (!this->adquirido) {
		this->adquirido = true;
		return true;
	}
	return false;
}

bool Tecnologia::comprar(Imperio_Jogador &imp) {
	if (imp.get_cofre() >= this->custo) {
		imp.decrementar_cofre(this->custo);
		this->tomar();
		return true;
	}
	return false;
}
