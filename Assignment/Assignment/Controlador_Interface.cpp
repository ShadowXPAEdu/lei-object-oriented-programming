#include "Controlador_Interface.h"

using namespace std;

Controlador_Interface::Controlador_Interface() {
	this->s_f2_prod_ouro = false;
	this->s_f3_mil_tec = false;
	this->jogo = new Jogo();
}

Controlador_Interface::~Controlador_Interface() {
	delete this->jogo;
	for (int i = 0; i < this->gravacoes.size(); i++) {
		delete this->gravacoes[i];
	}
}

void Controlador_Interface::cmd_cria(string tipo, const int n) {
	int i = 0;
	transform(tipo.begin(), tipo.end(), tipo.begin(), ::tolower);
	for (; i < n; i++) {
		if (tipo.compare("castelo") == 0) {
			this->jogo->adicionar_territorio(new Castelo());
		} else if (tipo.compare("duna") == 0) {
			this->jogo->adicionar_territorio(new Duna());
		} else if (tipo.compare("forteleza") == 0) {
			this->jogo->adicionar_territorio(new Fortaleza());
		} else if (tipo.compare("mina") == 0) {
			this->jogo->adicionar_territorio(new Mina());
		} else if (tipo.compare("montanha") == 0) {
			this->jogo->adicionar_territorio(new Montanha());
		} else if (tipo.compare("planicie") == 0) {
			this->jogo->adicionar_territorio(new Planicie());
		} else if (tipo.compare("pescaria") == 0) {
			this->jogo->adicionar_territorio(new Pescaria());
		} else if (tipo.compare("refugiopiratas") == 0) {
			this->jogo->adicionar_territorio(new Refugio_Piratas());
		} else {
			break;
		}
	}
	if (i != 0) {
		cout << "\nCriado " << n << " territorios do tipo: " << tipo << endl;
	}
}

void Controlador_Interface::cmd_conquista(const string nome) {
	if (this->jogo->conquistar_territorio(nome)) {
		cout << "\nComando conquista efetuado com sucesso!\n";
	} else {
		cout << "\nImpossivel aquirir o territorio que desejava!\n";
	}
}

void Controlador_Interface::cmd_carrega(const string nome_fich) {
	ifstream File(nome_fich);
	string Line;
	if (File.is_open()) {
		while (getline(File, Line)) {
			this->ler_cmd(Line);
			cout << Line << endl;
		}
		File.close();
	} else
		cout << "Erro ao carregar o ficheiro!\n";
}

void Controlador_Interface::cmd_lista(const string nome) {
	if (nome.compare("") == 0) {
		this->mostra_lista_peq();
		cout << "\nTerritorios conquistados:";
		this->jogo->mostra_territorios_imperio();
		cout << "\nTerritorios nao conquistados:";
		this->jogo->mostra_territorios_nao_conquistados();
		cout << "\n------------------";
		this->jogo->get_mundo()->get_imperio()->mostrar_tecnologias();
		cout << "\nProximo evento: ";
		this->jogo->get_evento_string();
	} else {
		this->jogo->mostra_territorio(nome);
	}
}

void Controlador_Interface::cmd_passa() {
	this->ler_cmd("avanca");
}

void Controlador_Interface::cmd_maisouro() {
	if (this->jogo->get_mundo()->get_imperio()->maisouro()) {
		cout << "\nComando maisouro efetuado com sucesso!\n";
	} else {
		cout << "\nImpossivel obter mais ouro pois nao tem pelo menos 2 produtos!\n";
	}
}

void Controlador_Interface::cmd_maisprod() {
	if (this->jogo->get_mundo()->get_imperio()->maisprod()) {
		cout << "\nComando maisprod efetuado com sucesso!\n";
	} else {
		cout << "\nImpossivel obter mais produtos pois nao tem pelo menos 2 ouro!\n";
	}
}

void Controlador_Interface::cmd_maismilitar() {
	if (this->jogo->get_mundo()->get_imperio()->maismilitar()) {
		cout << "\nComando maismilitar efetuado com sucesso!\n";
	} else {
		cout << "\nImpossivel obter mais militar pois nao tem pelo menos 1 ouro e 1 produto!\n";
	}
}

void Controlador_Interface::cmd_adquire(const string tipo) {
	if (this->jogo->get_mundo()->get_imperio()->pode_adquirir(tipo)) {
		cout << "\nComando aquire efetuado com sucesso!\n";
	} else {
		cout << "\nImpossivel aquirir a tecnologia que desejava!\n";
	}
}

void Controlador_Interface::cmd_avanca() {
	this->jogo->incrementa_fase();
	switch (this->jogo->get_fase()) {
		case 0:
		{
			cout << endl << "Fase: Conquistar/Passar" << endl;
			// Conquistar / Passar
			break;
		}
		case 1:
		{
			cout << endl << "Fase: Recolha de produtos e ouro" << endl;
			// Recolha de produtos e ouro
			// Adquirir produtos e ouro de cada território
			this->jogo->recolha_produtos_ouro();
			// Permitir a leitura de mais comandos se o império tiver a tecnologia "Bolsa de Valores"
			if (!this->jogo->get_mundo()->get_imperio()->adquiriu_tecnologia("bolsavalores")) {
				this->ler_cmd("avanca");
			}
			// Uma vez por turno
			s_f2_prod_ouro = false;
			break;
		}
		case 2:
		{
			cout << endl << "Fase: Compra de unidades militares e tecnologia" << endl;
			// Compra de unidades militares e tecnologia
			// Uma vez por turno
			s_f3_mil_tec = false;
			break;
		}
		case 3:
		{
			cout << endl << "Fase: Eventos" << endl;
			// Fase de Eventos
			// Ativar o Evento e escolher o próximo evento
			this->jogo->occorencia_evento();
			// Somar todos os pontos adquiridos neste turno
			// e Verificar se chegou o fim do jogo!
			this->jogo->termina_turno();
			// Passar para a próxima fase
			this->ler_cmd("avanca");
			break;
		}
		default:
			break;
	}
}

void Controlador_Interface::cmd_grava(const std::string nome) {
	for (int i = 0; i < this->gravacoes.size(); i++) {
		if (nome.compare(this->gravacoes[i]->get_nome()) == 0) {
			cout << "Nome da gravacao ja existe!" << endl;
			return;
		}
	}
	this->gravacoes.push_back(new Gravacao(nome, *this->jogo));
	cout << "Jogo gravado com sucesso!" << endl;
}

void Controlador_Interface::cmd_ativa(const std::string nome) {
	for (int i = 0; i < this->gravacoes.size(); i++) {
		if (nome.compare(this->gravacoes[i]->get_nome()) == 0) {
			delete this->jogo;
			this->jogo = new Jogo(*this->gravacoes[i]->get_jogo());
			cout << "Jogo ativado com sucesso!" << endl;
			return;
		}
	}
	cout << "Nao foi encontrado nenhuma gravacao com esse nome!" << endl;
}

void Controlador_Interface::cmd_apaga(const std::string nome) {
	for (int i = 0; i < this->gravacoes.size(); i++) {
		if (nome.compare(this->gravacoes[i]->get_nome()) == 0) {
			delete this->gravacoes[i]->get_jogo();
			this->gravacoes.erase(this->gravacoes.begin() + i);
			cout << "Jogo apagado!" << endl;
			return;
		}
	}
	cout << "Jogo nao encontrado!" << endl;
}

void Controlador_Interface::cmd_toma(const std::string qual, const std::string nome) {
	if (qual.compare("terr") == 0) {
		if (this->jogo->get_mundo()->tomar_territorio(nome)) {
			cout << "Tomada a posse do territorio" << endl;
		} else {
			cout << "Nao foi possivel tomar posse do territorio" << endl;
		}
	} else if (qual.compare("tec") == 0) {
		if (this->jogo->get_mundo()->tomar_tecnologia(nome)) {
			cout << "Tomada a posse da tecnologia" << endl;
		} else {
			cout << "Nao foi possivel tomar posse da tecnologia" << endl;
		}
	}
}

void Controlador_Interface::cmd_modifica(const std::string recurso, const int n) {
	if (recurso.compare("ouro") == 0) {
		this->jogo->get_mundo()->get_imperio()->set_cofre(n);
		cout << "Modificado a quantidade de ouro" << endl;
	} else if (recurso.compare("prod") == 0) {
		this->jogo->get_mundo()->get_imperio()->set_armazem(n);
		cout << "Modificado a quantidade de produtos" << endl;
	}
}

void Controlador_Interface::cmd_fevento(const std::string evento) {
	if (evento.compare("sem") == 0) {
		this->jogo->set_proximo_evento(0);
	} else if (evento.compare("alianca") == 0) {
		this->jogo->set_proximo_evento(1);
	} else if (evento.compare("invasao") == 0) {
		this->jogo->set_proximo_evento(2);
	} else if (evento.compare("recurso") == 0) {
		this->jogo->set_proximo_evento(3);
	}
}

void Controlador_Interface::ler_cmd(string comando) {
	transform(comando.begin(), comando.end(), comando.begin(), ::tolower);
	auto str = stringSplit(comando, " ");
	int fase = this->jogo->get_fase();
	if (str[0].compare("sair") == 0) {
		this->jogo->get_jogo_a_correr() = false;
	} else if (str[0].compare("cria") == 0) {
		if (fase == -1) {
			if (str.size() < 3)
				return;
			cmd_cria(str[1], stoi(str[2]));
		} else {
			cout << "\nA fase de inicializacao ja terminou!\n";
		}
	} else if (str[0].compare("conquista") == 0) {
		if (fase == 0) {
			if (str.size() < 2)
				return;
			cmd_conquista(str[1]);
		} else {
			cout << "\nA primeira fase ja terminou!\n";
		}
	} else if (str[0].compare("carrega") == 0) {
		if (fase == -1) {
			if (str.size() < 2)
				return;
			cmd_carrega(str[1]);
		} else {
			cout << "\nA fase de inicializacao ja terminou!\n";
		}
	} else if (str[0].compare("lista") == 0) {
		if (str.size() < 2)
			cmd_lista("");
		else
			cmd_lista(str[1]);
	} else if (str[0].compare("passa") == 0) {
		if (fase == 0) {
			cmd_passa();
		} else {
			cout << "\nA primeira fase ja terminou!\n";
		}
	} else if (str[0].compare("maisouro") == 0) {
		if (fase == 1) {
			if (!s_f2_prod_ouro) {
				s_f2_prod_ouro = true;
				cmd_maisouro();
			} else {
				cout << "\nJa adquiriu ouro ou produtos neste turno!\n";
			}
		} else {
			cout << "\nA segunda fase ja terminou!\n";
		}
	} else if (str[0].compare("maisprod") == 0) {
		if (fase == 1) {
			if (!s_f2_prod_ouro) {
				s_f2_prod_ouro = true;
				cmd_maisprod();
			} else {
				cout << "\nJa adquiriu produtos ou ouro neste turno!\n";
			}
		} else {
			cout << "\nA segunda fase ja terminou!\n";
		}
	} else if (str[0].compare("maismilitar") == 0) {
		if (fase == 2) {

			if (!s_f3_mil_tec) {
				s_f3_mil_tec = true;
				cmd_maismilitar();
			} else {
				cout << "\nJa adquiriu militares neste turno!\n";
			}
		} else {
			cout << "\nA terceira fase ja terminou!\n";
		}
	} else if (str[0].compare("adquire") == 0) {
		if (fase == 2) {
			if (str.size() < 2)
				return;
			if (!s_f3_mil_tec) {
				s_f3_mil_tec = true;
				cmd_adquire(str[1]);
			} else {
				cout << "\nJa adquiriu tecnologias neste turno!\n";
			}
		} else {
			cout << "\nA terceira fase ja terminou!\n";
		}
	} else if (str[0].compare("avanca") == 0) {
		cmd_avanca();
	} else if (str[0].compare("grava") == 0) {
		if (str.size() < 2)
			return;
		cmd_grava(str[1]);
	} else if (str[0].compare("ativa") == 0) {
		if (str.size() < 2) {
			for (int i = 0; i < this->gravacoes.size(); i++) {
				cout << endl << this->gravacoes[i]->get_nome();
			}
			return;
		}
		cmd_ativa(str[1]);
	} else if (str[0].compare("apaga") == 0) {
		if (str.size() < 2)
			return;
		cmd_apaga(str[1]);
	} else if (str[0].compare("toma") == 0) {
		if (str.size() < 3)
			return;
		cmd_toma(str[1], str[2]);
	} else if (str[0].compare("modifica") == 0) {
		if (str.size() < 3)
			return;
		cmd_modifica(str[1], stoi(str[2]));
	} else if (str[0].compare("fevento") == 0) {
		if (str.size() < 2)
			return;
		cmd_fevento(str[1]);
	}
}

void Controlador_Interface::mostra_lista_peq() {
	cout << "\nAno: " << this->jogo->get_ano();
	cout << "\nTurno: " << this->jogo->get_turno();
	cout << "\nFase: " << this->jogo->get_fase() + 1;
	cout << "\nUltimo fator sorte gerado: " << this->jogo->get_fator_sorte();
	cout << "\nPontuacao: " << this->jogo->get_pontuacao();
	cout << endl << "Produtos: " << this->jogo->get_mundo()->get_imperio()->get_armazem();
	cout << endl << "Maximo produtos: " << this->jogo->get_mundo()->get_imperio()->get_max_armazem();
	int* prod_ouro = this->jogo->get_mundo()->get_imperio()->possibilidade_adquirir_prod_ouro();
	cout << endl << "Producao de produtos: " << prod_ouro[0];
	cout << endl << "Ouro: " << this->jogo->get_mundo()->get_imperio()->get_cofre();
	cout << endl << "Maximo ouro: " << this->jogo->get_mundo()->get_imperio()->get_max_cofre();
	cout << endl << "Producao de ouro: " << prod_ouro[1];
	delete prod_ouro;
	cout << endl << "Forca militar: " << this->jogo->get_mundo()->get_imperio()->get_forca_militar();
	cout << endl << "Maximo forca militar: " << this->jogo->get_mundo()->get_imperio()->get_max_forca_militar();
	cout << "\n------------------";
}

void Controlador_Interface::inicia() {
	this->ler_cmd("carrega Territorios.txt");
	while (this->jogo->get_jogo_a_correr()) {
		this->mostra_lista_peq();
		string str = "";
		cout << "\nIntroduza o comando que deseja: ";
		getline(cin, str);
		this->ler_cmd(str);
	}
	cout << endl << "FIM DO JOGO!!!" << endl;
	this->mostra_lista_peq();
}

vector<string> Controlador_Interface::stringSplit(const string str_to_split, const string delimiter) {
	vector<string> list;
	string str(str_to_split);
	size_t position = 0;
	string token;
	while ((position = str.find(delimiter)) != string::npos) {
		token = str.substr(0, position);
		list.push_back(token);
		str.erase(0, position + delimiter.length());
	}
	list.push_back(str);
	return list;
}
