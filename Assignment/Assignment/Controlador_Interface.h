#pragma once

#include "Gravacao.h"

class Controlador_Interface {
private:
	Jogo *jogo;
	std::vector<Gravacao *> gravacoes;
	bool s_f2_prod_ouro;
	bool s_f3_mil_tec;
public:
	Controlador_Interface();
	~Controlador_Interface();
	void cmd_cria(const std::string, const int);
	void cmd_conquista(const std::string);
	void cmd_carrega(const std::string);
	void cmd_lista(const std::string);
	void cmd_passa();
	void cmd_maisouro();
	void cmd_maisprod();
	void cmd_maismilitar();
	void cmd_adquire(const std::string);
	void cmd_avanca();
	void cmd_grava(const std::string);
	void cmd_ativa(const std::string);
	void cmd_apaga(const std::string);
	void cmd_toma(const std::string, const std::string);
	void cmd_modifica(const std::string, const int);
	void cmd_fevento(const std::string);
	void ler_cmd(std::string);
	void mostra_lista_peq();
	void inicia();
	std::vector<std::string> stringSplit(const std::string str_to_split, const std::string delimiter);
};
