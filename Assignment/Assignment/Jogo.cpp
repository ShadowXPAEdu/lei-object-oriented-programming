#include "Jogo.h"

using namespace std;

Jogo::Jogo() {
	srand((unsigned int) time(nullptr));
	this->turno = 0;
	this->pontuacao = 0;
	this->fase = -1;
	this->jogo_a_correr = true;
	this->mundo = new Mundo();
	this->mundo->adicionar_territorio_inicial(new Territorio_Inicial());
	this->evento = nullptr;
	this->set_proximo_evento(this->mundo->get_imperio()->gerar_fator_sorte(0, 3));
}

Jogo::Jogo(Jogo &jogo) {
	this->turno = jogo.turno;
	this->pontuacao = jogo.pontuacao;
	this->jogo_a_correr = jogo.jogo_a_correr;
	this->fase = jogo.fase;
	this->mundo = new Mundo(*jogo.mundo);
	this->evento = jogo.evento->novo();
}

Jogo::~Jogo() {
	delete this->mundo;
	delete this->evento;
}

Mundo *const Jogo::get_mundo() {
	return this->mundo;
}

Evento *const Jogo::get_evento() {
	return this->evento;
}

void Jogo::adicionar_territorio(Territorio *ter) {
	this->mundo->adicionar_territorio(ter);
}

bool Jogo::conquistar_territorio(string territorio) {
	return this->mundo->conquistar_territorio(territorio, this->turno);
}

void Jogo::mostra_territorio(string territorio) {
	this->mundo->mostra_territorio(territorio);
}

void Jogo::mostra_territorios_imperio() {
	this->mundo->mostra_territorios_imperio();
}

void Jogo::mostra_territorios_nao_conquistados() {
	this->mundo->mostra_territorios_nao_conquistados();
}

float Jogo::get_ano() {
	return (turno / 6.0f) + 1;
}

int Jogo::get_turno() {
	return this->turno;
}

int Jogo::get_fator_sorte() {
	return this->mundo->get_fator_sorte();
}

int Jogo::get_fase() {
	return this->fase;
}

bool &Jogo::get_jogo_a_correr() {
	return this->jogo_a_correr;
}

void Jogo::incrementa_fase() {
	this->fase = ++this->fase % 4;
}

void Jogo::recolha_produtos_ouro() {
	this->mundo->get_imperio()->verifica_turno(this->turno);
	this->mundo->get_imperio()->adquire_prod_ouro();
}

void Jogo::occorencia_evento() {
	this->evento->efeito(this->get_mundo()->get_imperio(), this->get_ano());
	this->set_proximo_evento(this->mundo->get_imperio()->gerar_fator_sorte(0, 3));
	if (this->mundo->get_imperio()->tamanho_territorios_conquistados() == 0) {
		this->jogo_a_correr = false;
	}
}

void Jogo::termina_turno() {
	this->turno++;
	this->pontuacao = this->mundo->get_imperio()->obter_pontos(this->mundo->get_num_territorios());
	if (this->get_ano() >= 3.0f) {
		this->jogo_a_correr = false;
	}
}

void Jogo::get_evento_string() {
	cout << endl;
	cout << this->evento->get_nome() << ": " << this->evento->get_descricao();
	cout << endl;
}

void Jogo::set_proximo_evento(int i) {
	delete this->evento;
	switch (i) {
		case 1:
		{
			this->evento = new Alianca_Diplomatica();
			break;
		}
		case 2:
		{
			this->evento = new Invasao();
			break;
		}
		case 3:
		{
			this->evento = new Recurso_Abandonado();
			break;
		}
		case 0:
		default:
			this->evento = new Evento();
			break;
	}
}

int Jogo::get_pontuacao() {
	return this->pontuacao;
}
