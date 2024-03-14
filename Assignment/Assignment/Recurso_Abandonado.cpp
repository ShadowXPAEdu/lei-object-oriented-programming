#include "Recurso_Abandonado.h"
#include "Imperio_Jogador.h"

Recurso_Abandonado::Recurso_Abandonado() : Evento("RecursoAbandonado", "Um recurso abandonado foi encontrado e fornece recursos ao imperio.") {}

Recurso_Abandonado::Recurso_Abandonado(Recurso_Abandonado &ev) : Evento(ev) {}

Recurso_Abandonado::~Recurso_Abandonado() {}

void Recurso_Abandonado::efeito(Imperio_Jogador *const imp, const float ano) {
	Evento::efeito(imp, ano);
	if (ano < 2.0f) {
		imp->incrementa_armazem();
	} else {
		imp->incrementa_cofre();
	}
}

Evento *Recurso_Abandonado::novo() {
	return new Recurso_Abandonado(*this);
}
