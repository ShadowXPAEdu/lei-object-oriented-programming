#pragma once

#include "Mundo.h"
#include "Castelo.h"
#include "Duna.h"
#include "Fortaleza.h"
#include "Mina.h"
#include "Montanha.h"
#include "Planicie.h"
#include "Ilha.h"
#include "Pescaria.h"
#include "Refugio_Piratas.h"
#include <algorithm>
#include <random>
#include <time.h>
#include <fstream>

class Jogo {
private:
	Mundo *mundo;
	Evento *evento;
	int turno;
	int pontuacao;
	bool jogo_a_correr;
	int fase;
	/*void cmd_cria(const string, const int);
	void cmd_conquista(const string);
	void cmd_carrega(const string);
	void cmd_lista(const string);*/
public:
	Jogo();
	Jogo(Jogo &);
	~Jogo();
	Mundo *const get_mundo();
	Evento *const get_evento();
	void adicionar_territorio(Territorio *);
	bool conquistar_territorio(std::string);
	void mostra_territorio(std::string);
	void mostra_territorios_imperio();
	void mostra_territorios_nao_conquistados();
	float get_ano();
	int get_turno();
	int get_fase();
	int get_fator_sorte();
	bool &get_jogo_a_correr();
	void incrementa_fase();
	//void conquistar_passar();
	void recolha_produtos_ouro();
	//void compra_unidades();
	void occorencia_evento();
	void termina_turno();
	void get_evento_string();
	void set_proximo_evento(int);
	int get_pontuacao();
};
