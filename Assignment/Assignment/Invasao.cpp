#include "Invasao.h"
#include "Imperio_Jogador.h"

using namespace std;

Invasao::Invasao() : Evento("Invasao", "Um outro imperio concorrente esta a tentar conquistar um dos territorios do jogador.") {}

Invasao::Invasao(Invasao &ev) : Evento(ev) {}

Invasao::~Invasao() {}

void Invasao::efeito(Imperio_Jogador *const imp, const float ano) {
	Evento::efeito(imp, ano);
	int fator_sorte = imp->gerar_fator_sorte();
	fator_sorte += ano < 2.0f ? 2 : 3;
	bool invadido = imp->territorio_invadido(fator_sorte);
	cout << (invadido ? "Territorio invadido" : "Territorio nao invadido") << endl;
}

Evento *Invasao::novo() {
	return new Invasao(*this);
}
