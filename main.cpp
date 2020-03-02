#include <iostream>
#include "Tabela.h"

int main()
{
    string imprimirTexto;
    char barraMascaraChar[1];
    int barraMascaraInt;
    Tabela numeroDoIp;
    int opcao;
    string ipAux="";
    string barraMascara="";
    bool escolha = true;
    cout << "Calculadora IPV4\n";
    cout << "Redes de Computadores II\n";
    cout << "Aluno: Elismar Eldor Jascovski\n\n";
    while (escolha)
    {
        cout << "\n\nOpcoes:\n";
        cout << "1 - Calcular IP com classe\n2 - Calcular IP sem classe e notacao CIDR\n3 - Calcular IP sem classe e notacao decimal\n4 - Sair\n\n";
        cout << "Digite o numero da opcao desejada: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "\n\nDigite um IP valido(padrao: n.n.n.n): ";
            cin >> ipAux;
            numeroDoIp.setEntrada(ipAux);
            
            if(numeroDoIp.verificaIP(numeroDoIp.getEntrada()))
            {
                cout<<"\n\n----Numero do IP fornecido tem algum caracter invalido.----\n";
                break;
            }
            
            if(numeroDoIp.classe(numeroDoIp.getEntrada(),opcao)=="A"||numeroDoIp.classe(numeroDoIp.getEntrada(),opcao)=="B"||numeroDoIp.classe(numeroDoIp.getEntrada(),opcao)=="C")
            {
                cout<<"\n-----------------------------------------------------------";
                cout<<"\nClasse: ";
                cout<<numeroDoIp.classe(numeroDoIp.getEntrada(),opcao);
            }else if(numeroDoIp.classe(numeroDoIp.getEntrada(),opcao)=="D")
            {
                cout<<"\n-----------------------------------------------------------";
                cout<<"\nClasse: ";
                cout<<numeroDoIp.classe(numeroDoIp.getEntrada(),opcao);
                cout<<"\n\nEndereco reservado para multicast.";
                break;
            }else if(numeroDoIp.classe(numeroDoIp.getEntrada(),opcao)=="E")
            {
                cout<<"\n-----------------------------------------------------------";
                cout<<"\nClasse: ";
                cout<<numeroDoIp.classe(numeroDoIp.getEntrada(),opcao);
                cout<<"\n\nEndereco reservado para uso futuro.";
                break;
            }else
            {
                cout<<"\n\n-----Numero de IP fornecido invalido-----\n";
                break;
            }
            
            cout << "\nEntrada: ";
            cout << numeroDoIp.getEntrada();
            cout << "\nMascara(/): /";
            cout << numeroDoIp.barraMascara(numeroDoIp.getEntrada(),1);
            cout << "\nMascara: ";
            cout << numeroDoIp.mascara(numeroDoIp.getEntrada(),1,(numeroDoIp.barraMascara(numeroDoIp.getEntrada(),1)));
            cout << "\nNumero de Hosts: ";
            cout << numeroDoIp.numeroHosts(numeroDoIp.getEntrada(), (numeroDoIp.barraMascara(numeroDoIp.getEntrada(),1)));
            cout << "\nRede: ";
            cout << numeroDoIp.rede(numeroDoIp.getEntrada(),(numeroDoIp.barraMascara(numeroDoIp.getEntrada(),1)));
            cout << "\nBroadcast: ";
            cout << numeroDoIp.broadcast(numeroDoIp.getEntrada(),(numeroDoIp.barraMascara(numeroDoIp.getEntrada(),1)));
            cout << "\nIP Inicial: ";
            cout << numeroDoIp.ipInicial(numeroDoIp.getEntrada(),(numeroDoIp.barraMascara(numeroDoIp.getEntrada(),1)));
            cout << "\nIP Final: ";
            cout << numeroDoIp.ipFinal(numeroDoIp.getEntrada(),(numeroDoIp.barraMascara(numeroDoIp.getEntrada(),1)));
            cout<<"\n-----------------------------------------------------------";
            break;

        case 2:
            cout << "\n\nDigite um IP valido(padrao: n.n.n.n): ";
            cin >> ipAux;
            numeroDoIp.setEntrada(ipAux);
            
            if(numeroDoIp.verificaIP(numeroDoIp.getEntrada()))
            {
                cout<<"\n\n----Numero do IP fornecido tem algum caracter invalido.----\n";
                break;
            }
            
            cout << "\n\nDigite a mascara de notacao CIDR(padrao n): ";
            cin >> barraMascaraChar;
            barraMascaraInt = atoi(barraMascaraChar);
            
            if(barraMascaraInt<0||barraMascaraInt>28)
            {
                cout<<"\n\n----Notacao CIDR fornecida e invalida.----\n";
                break;
            }
            cout<<"\n-----------------------------------------------------------";
            cout << "\nClasse: ";
            cout << numeroDoIp.classe(numeroDoIp.getEntrada(), 2);
            cout << "\nEntrada: ";
            cout << numeroDoIp.getEntrada();
            cout << "\nMascara(/): ";
            cout <<"/"<< barraMascaraChar;
            cout << "\nMascara: ";
            cout << numeroDoIp.mascara(numeroDoIp.getEntrada(),2,barraMascaraInt);
            cout << "\nNumero de Hosts: ";
            cout << numeroDoIp.numeroHosts(numeroDoIp.getEntrada(), barraMascaraInt);
            cout << "\nRede: ";
            cout << numeroDoIp.rede(numeroDoIp.getEntrada(),barraMascaraInt);
            cout << "\nBroadcast: ";
            cout << numeroDoIp.broadcast(numeroDoIp.getEntrada(),barraMascaraInt);
            cout << "\nIP Inicial: ";
            cout << numeroDoIp.ipInicial(numeroDoIp.getEntrada(),barraMascaraInt);
            cout << "\nIP Final: ";
            cout << numeroDoIp.ipFinal(numeroDoIp.getEntrada(),barraMascaraInt);
            cout<<"\n-----------------------------------------------------------";
            break;

        case 3:
            cout << "\n\nDigite um IP valido(padrao: n.n.n.n): ";
            cin >> ipAux;
            numeroDoIp.setEntrada(ipAux);
            
            if(numeroDoIp.verificaIP(numeroDoIp.getEntrada()))
            {
                cout<<"\n\n----Numero do IP fornecido tem algum caracter invalido.----\n";
                break;
            }
            
            cout << "\n\nDigite a mascara de notacao decimal(padrao n.n.n.n): ";
            cin >> barraMascara;
            cout<<"\n-----------------------------------------------------------";
            cout << "\nClasse: ";
            cout << numeroDoIp.classe(numeroDoIp.getEntrada(), 3);
            cout << "\nEntrada: ";
            cout << numeroDoIp.getEntrada();
            cout << "\nMascara(/): /";
            cout << numeroDoIp.barraMascara(barraMascara,3);
            cout << "\nMascara: ";
            cout << barraMascara;
            cout << "\nNumero de Hosts: ";
            cout << numeroDoIp.numeroHosts(numeroDoIp.getEntrada(), (numeroDoIp.barraMascara(barraMascara,3)));
            cout << "\nRede: ";
            cout << numeroDoIp.rede(numeroDoIp.getEntrada(),(numeroDoIp.barraMascara(barraMascara,3)));
            cout << "\nBroadcast: ";
            cout << numeroDoIp.broadcast(numeroDoIp.getEntrada(),(numeroDoIp.barraMascara(barraMascara,3)));
            cout << "\nIP Inicial: ";
            cout << numeroDoIp.ipInicial(numeroDoIp.getEntrada(),(numeroDoIp.barraMascara(barraMascara,3)));
            cout << "\nIP Final: ";
            cout << numeroDoIp.ipFinal(numeroDoIp.getEntrada(),(numeroDoIp.barraMascara(barraMascara,3)));
            cout<<"\n-----------------------------------------------------------";
            break;
            
            break;

        case 4:
            cout << "\n\n----------Caldulador de IP encerrando com sucesso-------------\n\n";
            return 0;
            break;
        default:
            cout << "\n\n------------Opcao invalida, selecione uma opcao valida-------------\n\n";
            break;
        }
    }
}
