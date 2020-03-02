#include <string.h>
#include <string>
#include <iostream>
#include <sstream>
#include <math.h>
using namespace std;
class Tabela
{
private:
	string entrada;
public:
	Tabela() { entrada = "0"; }
	void setEntrada(string entrada1) { entrada = entrada1; }
	string getEntrada() { return entrada; }
	string classe(string entrada1, int opcao);
	string mascara(string entrada1, int opcao, int barraMascara1);
	int barraMascara(string entrada1, int opcao);
	int numeroHosts(string entrada1,int barraMascara1);
	string rede(string entrada1, int barraMascara1);
	string broadcast(string entrada1, int barraMascara1);
	string ipInicial(string entrada1, int barraMascara1);
	string ipFinal(string entrada1, int barraMascara1);
	int decimalParaCidr(string notacaoDecimal);
	bool verificaIP(string entrada1);

};