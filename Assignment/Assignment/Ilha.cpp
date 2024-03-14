#include "Ilha.h"
#include "Imperio_Jogador.h"

using namespace std;

Ilha::Ilha(string nome, int resistencia, int criacao_produtos, int criacao_ouro) : Territorio(nome, 2, resistencia, criacao_produtos, criacao_ouro) {
	unsigned int static s_count = 0;
	s_count++;
	this->nome += to_string(s_count);
}

Ilha::Ilha(Ilha &ter) : Territorio(ter) {}

Ilha::~Ilha() {}

bool Ilha::ser_conquistado(Imperio_Jogador &imp, int) {
	// Verificar se tem as tecnologias necessárias
	bool adquiriu_tec = imp.adquiriu_tecnologia("misseisteleguiados");
	size_t numero_terr_conquistados = imp.tamanho_territorios_conquistados();
	// Proceder à conquista caso seja possível conquistar
	if (adquiriu_tec && numero_terr_conquistados >= 5) {
		return imp.adicionar_territorio_conquistado(this);
	}
	return false;
}
