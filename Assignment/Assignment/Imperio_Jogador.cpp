#include "Imperio_Jogador.h"

using namespace std;

Imperio_Jogador::Imperio_Jogador() {
	this->armazem = 0;
	this->max_armazem = 3;
	this->cofre = 0;
	this->max_cofre = 3;
	this->forca_militar = 0;
	this->max_forca_militar = 3;
	this->fator_sorte = 0;
	this->tecnologias.push_back(new Banco_Central());
	this->tecnologias.push_back(new Bolsa_Valores());
	this->tecnologias.push_back(new Defesas_Territoriais());
	this->tecnologias.push_back(new Drones_Militares());
	this->tecnologias.push_back(new Misseis_Teleguiados());
}

Imperio_Jogador::Imperio_Jogador(Imperio_Jogador &imp) {
	this->armazem = imp.armazem;
	this->max_armazem = imp.max_armazem;
	this->cofre = imp.cofre;
	this->max_cofre = imp.max_cofre;
	this->forca_militar = imp.forca_militar;
	this->max_forca_militar = imp.max_forca_militar;
	this->fator_sorte = imp.fator_sorte;
	for (int i = 0; i < imp.tecnologias.size(); i++) {
		this->tecnologias.push_back(imp.tecnologias[i]->novo());
	}
}

Imperio_Jogador::~Imperio_Jogador() {
	for (int i = 0; i < this->tecnologias.size(); i++) {
		delete this->tecnologias[i];
	}
}

void Imperio_Jogador::set_armazem_cofre() {
	this->set_armazem();
	this->set_cofre();
}

int Imperio_Jogador::get_armazem() {
	return this->armazem;
}

int Imperio_Jogador::get_max_armazem() {
	return this->max_armazem;
}

void Imperio_Jogador::set_armazem(int n) {
	this->armazem = n;
}

void Imperio_Jogador::set_armazem() {
	if (this->adquiriu_tecnologia("bancocentral"))
		this->max_armazem = 5;
}

bool Imperio_Jogador::maisprod() {
	if (this->adquiriu_tecnologia("bolsavalores") && this->cofre >= 2 && this->incrementa_armazem()) {
		this->cofre -= 2;
		return true;
	}
	return false;
}

bool Imperio_Jogador::incrementa_armazem(int i) {
	for (int j = 0; j < i; j++) {
		if (this->armazem + 1 > this->max_armazem) {
			return false;
		}
		this->armazem++;
	}
	return true;
}

int Imperio_Jogador::get_cofre() {
	return this->cofre;
}

int Imperio_Jogador::get_max_cofre() {
	return this->max_cofre;
}

void Imperio_Jogador::set_cofre(int n) {
	this->cofre = n;
}

void Imperio_Jogador::set_cofre() {
	if (this->adquiriu_tecnologia("bancocentral"))
		this->max_cofre = 5;
}

bool Imperio_Jogador::maisouro() {
	if (this->adquiriu_tecnologia("bolsavalores") && this->armazem >= 2 && this->incrementa_cofre()) {
		this->armazem -= 2;
		return true;
	}
	return false;
}

bool Imperio_Jogador::incrementa_cofre(int i) {
	for (int j = 0; j < i; j++) {
		if (this->cofre + 1 > this->max_cofre) {
			return false;
		}
		this->cofre++;
	}
	return true;
}

void Imperio_Jogador::decrementar_cofre(int i) {
	this->cofre -= i;
	if (this->cofre < 0)
		this->cofre = 0;
}

int Imperio_Jogador::get_forca_militar() {
	return this->forca_militar;
}

int Imperio_Jogador::get_max_forca_militar() {
	return this->max_forca_militar;
}

void Imperio_Jogador::set_forca_militar() {
	if (this->adquiriu_tecnologia("dronesmilitares"))
		this->max_forca_militar = 5;
}

bool Imperio_Jogador::maismilitar() {
	if (this->armazem >= 1 && this->cofre >= 1 && this->incrementa_militar()) {
		this->armazem--;
		this->cofre--;
		return true;
	}
	return false;
}

bool Imperio_Jogador::incrementa_militar(int i) {
	if (this->forca_militar + i <= this->max_forca_militar) {
		this->forca_militar += i;
		return true;
	}
	return false;
}

int Imperio_Jogador::get_fator_sorte() {
	return this->fator_sorte;
}

int Imperio_Jogador::gerar_fator_sorte(int min, int max) {
	return min + rand() % (max - min + 1);
}

size_t Imperio_Jogador::tamanho_territorios_conquistados() {
	return this->territorios_conquistados.size();
}

std::string Imperio_Jogador::get_nome_territorio_conquistado(size_t i) {
	return this->territorios_conquistados[i]->get_nome();
}

bool Imperio_Jogador::pode_adquirir(std::string tipo) {
	string aux;
	for (int i = 0; i < this->tecnologias.size(); i++) {
		aux = this->tecnologias[i]->get_nome();
		transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		if (aux.compare(tipo) == 0) {
			return this->tecnologias[i]->comprar(*this);
		}
	}
	return false;
}

bool Imperio_Jogador::adquiriu_tecnologia(std::string tecnologia) {
	string aux;
	for (int i = 0; i < this->tecnologias.size(); i++) {
		aux = this->tecnologias[i]->get_nome();
		transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		if (aux.compare(tecnologia) == 0) {
			return this->tecnologias[i]->ja_adquirido();
		}
	}
	return false;
}

bool Imperio_Jogador::tomar_tecnologia(std::string tecnologia) {
	string aux;
	for (int i = 0; i < this->tecnologias.size(); i++) {
		aux = this->tecnologias[i]->get_nome();
		transform(aux.begin(), aux.end(), aux.begin(), ::tolower);
		if (aux.compare(tecnologia) == 0) {
			return this->tecnologias[i]->tomar();
		}
	}
	return false;
}

void Imperio_Jogador::mostrar_tecnologias() {
	for (int i = 0; i < this->tecnologias.size(); i++) {
		cout << "\nNome: " << this->tecnologias[i]->get_nome();
		cout << "\nCusto: " << this->tecnologias[i]->get_custo();
		cout << "\nObjetivo: " << this->tecnologias[i]->get_objetivo();
		cout << "\nAdquirido: " << (this->tecnologias[i]->ja_adquirido() ? "sim" : "nao");
		cout << "\n------------------";
	}
}

bool Imperio_Jogador::adicionar_territorio_conquistado(Territorio *ter) {
	this->fator_sorte = this->gerar_fator_sorte();
	this->fator_sorte += this->forca_militar;

	if (this->fator_sorte >= ter->get_resistencia()) {
		return this->tomar_territorio(ter);
	} else {
		this->forca_militar -= (this->forca_militar <= 0) ? 0 : 1;
	}
	return false;
}

bool Imperio_Jogador::territorio_invadido(const int fator_sorte) {
	size_t offset = this->territorios_conquistados.size() - 1;
	Territorio *ter = this->territorios_conquistados[offset];
	int res = ter->get_resistencia();
	res += this->adquiriu_tecnologia("defesasterritoriais") ? 1 : 0;
	if (fator_sorte < res)
		return false;
	this->territorios_conquistados.erase(this->territorios_conquistados.begin() + offset);
	return true;
}

void Imperio_Jogador::adicionar_territorio_inicial(Territorio_Inicial *ter) {
	this->territorios_conquistados.push_back(ter);
}

void Imperio_Jogador::mostra_territorios_conquistados() {
	for (int i = 0; i < this->territorios_conquistados.size(); i++) {
		cout << "\nNome: " << this->territorios_conquistados[i]->get_nome();
		cout << "\nResistencia: " << this->territorios_conquistados[i]->get_resistencia();
		cout << "\nProducao de produtos: " << this->territorios_conquistados[i]->get_criacao_produtos();
		cout << "\nProducao de ouro: " << this->territorios_conquistados[i]->get_criacao_ouro();
		cout << "\n------------------";
	}
}

bool Imperio_Jogador::encontra_territorio(Territorio *ter) {
	for (int i = 0; i < this->territorios_conquistados.size(); i++) {
		if (ter == this->territorios_conquistados[i]) {
			return true;
		}
	}
	return false;
}

void Imperio_Jogador::adquire_prod_ouro() {
	for (int i = 0, j = 0; i < this->territorios_conquistados.size() && j != 2; i++, j = 0) {
		auto ter = this->territorios_conquistados[i];
		j += incrementa_armazem(ter->get_criacao_produtos()) ? 0 : 1;
		j += incrementa_cofre(ter->get_criacao_ouro()) ? 0 : 1;
	}
}

int *Imperio_Jogador::possibilidade_adquirir_prod_ouro() {
	int *temp = new int[2];
	*(temp + 0) = 0;
	*(temp + 1) = 0;
	for (int i = 0; i < this->territorios_conquistados.size(); i++) {
		auto ter = this->territorios_conquistados[i];
		*(temp + 0) += ter->get_criacao_produtos();
		*(temp + 1) += ter->get_criacao_ouro();
	}
	return temp;
}

int Imperio_Jogador::obter_pontos(size_t num_ter) {
	int tmp = 0, ter = 0, tec = 0;
	size_t num_ter_conq = this->territorios_conquistados.size();
	for (int i = 0; i < num_ter_conq; i++) {
		ter += this->territorios_conquistados[i]->get_pontos_vitoria();
	}
	tmp += num_ter == num_ter_conq ? ter + 3 : ter;
	for (int i = 0; i < this->tecnologias.size(); i++) {
		tec += this->tecnologias[i]->ja_adquirido() ? 1 : 0;
	}
	tmp += tec >= 5 ? tec + 1 : tec;
	return tmp;
}

bool Imperio_Jogador::tomar_territorio(Territorio *ter) {
	if (!this->encontra_territorio(ter)) {
		this->territorios_conquistados.push_back(ter);
		return true;
	}
	return false;
}

void Imperio_Jogador::verifica_turno(int turno) {
	for (int i = 0; i < this->territorios_conquistados.size(); i++) {
		auto ter = this->territorios_conquistados[i];
		ter->set_criacao_ouro(turno);
		ter->set_criacao_produtos(turno);
	}
}
