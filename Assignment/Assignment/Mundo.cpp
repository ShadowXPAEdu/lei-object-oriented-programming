#include "Mundo.h"

using namespace std;

Mundo::Mundo() {
	this->imperio = new Imperio_Jogador();
}

Mundo::Mundo(Mundo &mundo) {
	for (int i = 0; i < mundo.territorios.size(); i++) {
		this->territorios.push_back(mundo.territorios[i]->novo());
	}
	this->imperio = new Imperio_Jogador(*mundo.imperio);
	for (int i = 0; i < mundo.get_imperio()->tamanho_territorios_conquistados(); i++) {
		this->tomar_territorio(mundo.get_imperio()->get_nome_territorio_conquistado(i));
	}
}

Mundo::~Mundo() {
	delete this->imperio;
	for (int i = 0; i < this->territorios.size(); i++) {
		delete this->territorios[i];
	}
}

Imperio_Jogador *const Mundo::get_imperio() {
	return this->imperio;
}

int Mundo::get_fator_sorte() {
	return this->imperio->get_fator_sorte();
}

size_t Mundo::get_num_territorios() {
	return this->territorios.size();
}

void Mundo::adicionar_territorio_inicial(Territorio_Inicial *ter) {
	this->imperio->adicionar_territorio_inicial(ter);
	this->adicionar_territorio(ter);
}

void Mundo::adicionar_territorio(Territorio *ter) {
	this->territorios.push_back(ter);
}

bool Mundo::conquistar_territorio(string nome, int turno) {
	string aux;
	for (int i = 0; i < this->territorios.size(); i++) {
		aux = this->territorios[i]->get_nome();
		transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		if (aux.compare(nome) == 0) {
			return this->territorios[i]->ser_conquistado(*this->get_imperio(), turno);
		}
	}
	return false;
}

bool Mundo::tomar_territorio(std::string nome) {
	string aux;
	for (int i = 0; i < this->territorios.size(); i++) {
		aux = this->territorios[i]->get_nome();
		transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		if (aux.compare(nome) == 0) {
			return this->territorios[i]->tomar_posse(*this->get_imperio());
		}
	}
	return false;
}

bool Mundo::tomar_tecnologia(std::string tecnologia) {
	return this->imperio->tomar_tecnologia(tecnologia);
}

void Mundo::mostra_territorios_imperio() {
	this->imperio->mostra_territorios_conquistados();
}

void Mundo::mostra_territorios_nao_conquistados() {
	for (int i = 0; i < this->territorios.size(); i++) {
		auto it = this->imperio->encontra_territorio(this->territorios[i]);
		if (!it) {
			cout << "\nNome: " << this->territorios[i]->get_nome();
			cout << "\nResistencia: " << this->territorios[i]->get_resistencia();
			cout << "\nProducao de produtos: " << this->territorios[i]->get_criacao_produtos();
			cout << "\nProducao de ouro: " << this->territorios[i]->get_criacao_ouro();
			cout << "\n------------------";
		}
	}
}

void Mundo::mostra_territorio(string nome_territorio) {
	string aux;
	for (int i = 0; i < this->territorios.size(); i++) {
		aux = this->territorios[i]->get_nome();
		transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		if (nome_territorio.compare(aux) == 0) {
			cout << "\nNome: " << this->territorios[i]->get_nome();
			cout << "\nPontos de Vitoria: " << this->territorios[i]->get_pontos_vitoria();
			cout << "\nResistencia: " << this->territorios[i]->get_resistencia();
			cout << "\nCriacao de Produtos: " << this->territorios[i]->get_criacao_produtos();
			cout << "\nCriacao de Ouro: " << this->territorios[i]->get_criacao_ouro();
			break;
		}
	}
}
