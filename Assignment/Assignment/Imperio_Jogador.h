#pragma once

#include "Territorio.h"
#include "Territorio_Inicial.h"
#include "Tecnologia.h"
#include "Banco_Central.h"
#include "Bolsa_Valores.h"
#include "Defesas_Territoriais.h"
#include "Drones_Militares.h"
#include "Misseis_Teleguiados.h"
#include "Ilha.h"
#include "Alianca_Diplomatica.h"
#include "Invasao.h"
#include "Recurso_Abandonado.h"
#include <vector>
#include <typeinfo>
#include <random>
#include <iostream>

class Imperio_Jogador {
private:
	std::vector<Territorio *> territorios_conquistados;
	std::vector<Tecnologia *> tecnologias;
	int armazem;
	int max_armazem;
	int cofre;
	int max_cofre;
	int forca_militar;
	int max_forca_militar;
	int fator_sorte;
public:
	Imperio_Jogador();
	Imperio_Jogador(Imperio_Jogador &);
	~Imperio_Jogador();
	void set_armazem_cofre();
	int get_armazem();
	int get_max_armazem();
	void set_armazem(int);
	void set_armazem();
	bool maisprod();
	bool incrementa_armazem(int = 1);
	int get_cofre();
	int get_max_cofre();
	void set_cofre(int);
	void set_cofre();
	bool maisouro();
	bool incrementa_cofre(int = 1);
	void decrementar_cofre(int);
	int get_forca_militar();
	int get_max_forca_militar();
	void set_forca_militar();
	bool maismilitar();
	bool incrementa_militar(int = 1);
	int get_fator_sorte();
	int gerar_fator_sorte(int = 1, int = 6);
	size_t tamanho_territorios_conquistados();
	std::string get_nome_territorio_conquistado(size_t);
	bool pode_adquirir(std::string);
	bool adquiriu_tecnologia(std::string);
	bool tomar_tecnologia(std::string);
	void mostrar_tecnologias();
	bool adicionar_territorio_conquistado(Territorio *);
	bool territorio_invadido(const int);
	void adicionar_territorio_inicial(Territorio_Inicial *);
	void mostra_territorios_conquistados();
	bool encontra_territorio(Territorio *);
	void adquire_prod_ouro();
	int* possibilidade_adquirir_prod_ouro();
	int obter_pontos(size_t);
	bool tomar_territorio(Territorio *);
	void verifica_turno(int);
};
