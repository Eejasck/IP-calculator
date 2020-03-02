#include "Tabela.h"

bool Tabela::verificaIP(string entrada1)//se retornar true o ip é invalido porque tem algum caracter errado.
{
    for(int i = 0; i < sizeof(entrada1); i++)
    {
        if(entrada1[i]!='0'&&entrada1[i]!='1'&&entrada1[i]!='2'&&entrada1[i]!='3'&&entrada1[i]!='4'&&entrada1[i]!='5'&&entrada1[i]!='6'&&entrada1[i]!='7'&&entrada1[i]!='8'&&entrada1[i]!='9'&&entrada1[i]!='.')
        {
            return true;
        }
    }
    return false;
}

string Tabela::classe(string entrada1, int opcao)
{
	string classeFinal="";

    if (opcao == 1) 
    {
	char primeiroConjunto[3];
	for (int i = 0; i < 3; i++)
	{
		if (entrada1[i] != '.')
		{
			primeiroConjunto[i] = entrada1[i];
		}
		else
		{
			i = 3;
		}
	}

	int classeTeste = atoi(primeiroConjunto);
	if (classeTeste < 0 || classeTeste>255)
	{
		classeFinal = "F";
		return classeFinal;
	}

		if (classeTeste <= 127)
		{
			classeFinal = "A";
		}
		else if (classeTeste <= 191)
		{
			classeFinal = "B";
		}
		else if (classeTeste <= 223)
		{
			classeFinal = "C";
		}
		else if(classeTeste <= 239)
		{
			classeFinal = "D";
		}
		else
		{
			classeFinal = "E";
		}		
	}

	if (opcao == 2) 
	{
		classeFinal = "Decimal";
	}

	if(opcao == 3)
	{
		classeFinal = "CIDR";
	}
	
	return classeFinal;
}

string Tabela::mascara(string entrada1, int opcao, int barraMascara1)
{

	string mascaraFinal="";
	
	if (opcao == 1) 
	{
	char primeiroConjunto[3];
	for (int i = 0; i < 3; i++)
	{
		if (entrada1[i] != '.')
		{
			primeiroConjunto[i] = entrada1[i];
		}
		else
		{
			i = 3;
		}
	}

	int classeTeste = atoi(primeiroConjunto);

		if (classeTeste <= 127)
		{
			mascaraFinal = "255.0.0.0";
		}
		else if (classeTeste <= 191)
		{
			mascaraFinal = "255.255.0.0";
		}
		else
		{
			mascaraFinal = "255.255.255.0";
		}
	}

	if (opcao == 2|| opcao == 3)
	{
		int valoresConvercao[8];
		valoresConvercao[1] = 128;
		valoresConvercao[2] = 64;
		valoresConvercao[3] = 32;
		valoresConvercao[4] = 16;
		valoresConvercao[5] = 8;
		valoresConvercao[6] = 4;
		valoresConvercao[7] = 2;
		valoresConvercao[0] = 1;
		int barraMascaraBinario[32];
		
		for(int i=0; i<32; i++)
		{
			barraMascaraBinario[i] = 0;
		}
		for (int i = 0; i < barraMascara1; i++)
		{
			barraMascaraBinario[i] = 1;
		}

		int binarioParaDecimal = 0;

		for(int i=0; i<32;i++)
		{
			if(barraMascaraBinario[i]==1)
			{
				binarioParaDecimal = binarioParaDecimal + valoresConvercao[(i+1)%8];
			}
			if(i==7)
			{
				stringstream intParaString;
				string aux = "";
				intParaString << binarioParaDecimal;
				intParaString >> aux;
				mascaraFinal = mascaraFinal + aux + ".";
				binarioParaDecimal = 0;
			}
			if(i==15)
			{
				stringstream intParaString;
				string aux = "";
				intParaString << binarioParaDecimal;
				intParaString >> aux;
				mascaraFinal = mascaraFinal + aux + ".";
				binarioParaDecimal = 0;
			}
			if (i == 23)
			{
				stringstream intParaString;
				string aux = "";
				intParaString << binarioParaDecimal;
				intParaString >> aux;
				mascaraFinal = mascaraFinal + aux + ".";
				binarioParaDecimal = 0;
			}
			if (i == 31)
			{
				stringstream intParaString;
				string aux = "";
				intParaString << binarioParaDecimal;
				intParaString >> aux;
				mascaraFinal = mascaraFinal + aux;
				binarioParaDecimal = 0;
			}
		}
	}

	return mascaraFinal;
}

int Tabela::barraMascara(string entrada1, int opcao)
{
	if (opcao == 1)
	{
		char primeiroConjunto[3];
		primeiroConjunto[0] = ' ';
		primeiroConjunto[1] = ' ';
		primeiroConjunto[2] = ' ';
		for (int i = 0; i < 3; i++)
		{
			if (entrada1[i] != '.')
			{
				primeiroConjunto[i] = entrada1[i];
			}
			else
			{
				if (i == 1) {
					primeiroConjunto[0] = '0';
					primeiroConjunto[1] = '0';
					primeiroConjunto[2] = entrada1[0];
				}
				if (i == 2) {
					primeiroConjunto[0] = '0';
					primeiroConjunto[1] = entrada1[1];
					primeiroConjunto[2] = entrada1[0];
				}
				i = 3;
			}
		}

		int classeTeste = atoi(primeiroConjunto);

		int barraMascaraFinal = 0;

		if (classeTeste <= 127)
		{
			barraMascaraFinal = 8;
		}
		else if (classeTeste <= 191)
		{
			barraMascaraFinal = 16;
		}
		else
		{
			barraMascaraFinal = 24;
		}
		return barraMascaraFinal;
	}
	if(opcao==3)
	{
		string parteDaMascara[4];
		int contarPontos = 0;
		
		char partesDoIP[3];
        int partesdoIPInt[4];
        int contador=0;
        int contadorB=0;
    
        for(int i = 0; i < 15; i++)
        {
            if(entrada1[i]!= '.')
            {
                partesDoIP[contador]=entrada1[i];
                contador++;
            }
            else
            {
                contador=0;
                partesdoIPInt[contadorB]=atoi(partesDoIP);
                partesDoIP[0]=' ';
                partesDoIP[1]=' ';
                partesDoIP[2]=' ';
                contadorB++;
            }
            if(i==14)
            {
                partesdoIPInt[contadorB]=atoi(partesDoIP);
            }
        }
    
    		
		
		int barraMascaraAux = 0;
		for (int i = 0; i < 4; i++) 
		{
			if(partesdoIPInt[i] == 255)
			{
				barraMascaraAux = barraMascaraAux + 8;
			}
			else if (partesdoIPInt[i] == 254)
			{
				barraMascaraAux = barraMascaraAux + 7;
			}
			else if (partesdoIPInt[i] == 252)
			{
				barraMascaraAux = barraMascaraAux + 6;
			}
			else if (partesdoIPInt[i] == 248)
			{
				barraMascaraAux = barraMascaraAux + 5;
			}
			else if (partesdoIPInt[i] == 240)
			{
				barraMascaraAux = barraMascaraAux + 4;
			}
			else if (partesdoIPInt[i] == 224)
			{
				barraMascaraAux = barraMascaraAux + 3;
			}
			else if (partesdoIPInt[i] == 192)
			{
				barraMascaraAux = barraMascaraAux + 2;
			}
			else if (partesdoIPInt[i] == 128)
			{
				barraMascaraAux = barraMascaraAux + 1;
			}
		}
		return barraMascaraAux;
	}
}

int Tabela::numeroHosts(string entrada1, int barraMascara1)
{
	char barraMascaraBinario[32];
	for (int i = 0; i < 32; i++)
	{
		barraMascaraBinario[i] = '0';
	}
	for (int i = 0; i < barraMascara1; i++)
	{
		barraMascaraBinario[i] = '1';
	}

	int contadorDeZeros=0;
	for (int i = 0; i < 32; i++) 
	{
		if (barraMascaraBinario[i] == '0')
		{
			contadorDeZeros++;
		}
	}

	int numeroHostsFinal=0;
	numeroHostsFinal = pow(2, contadorDeZeros);
	numeroHostsFinal=numeroHostsFinal-2;
	return numeroHostsFinal;
}

string Tabela::rede(string entrada1, int barraMascara1)
{
    char octetoBinario[32];
    char partesDoIP[3];
    int partesdoIPInt[4];
    int contador=0;
    int contadorB=0;

    for(int i = 0; i < 32; i++)
    {
        octetoBinario[i]='0';
    }


    for(int i = 0; i < 15; i++)
    {
        if(entrada1[i]!= '.')
        {
            partesDoIP[contador]=entrada1[i];
            contador++;
        }
        else
        {
            contador=0;
            partesdoIPInt[contadorB]=atoi(partesDoIP);
            partesDoIP[0]=' ';
            partesDoIP[1]=' ';
            partesDoIP[2]=' ';
            contadorB++;
        }
        if(i==14)
        {
            partesdoIPInt[contadorB]=atoi(partesDoIP);
        }
    }

    int bin[8];
    int aux;

    for(int i = 3; i >= 0; i--)
    {
        for (aux = 7; aux >= 0; aux--) 
        {
            if (partesdoIPInt[i] % 2 == 0) {
                bin[aux] = 0;
                partesdoIPInt[i] = partesdoIPInt[i] / 2;
            }
            else {
                bin[aux] = 1;
                partesdoIPInt[i] = partesdoIPInt[i] / 2;
            }
        }
        
        for (aux = 0; aux < 8; aux++)
        {
            if(bin[aux]==1)
            {
                octetoBinario[aux+(8*i)]='1';
            }
            else
            {
                octetoBinario[aux+(8*i)]='0';
            }
        }
        
    }

    for(int i = 0; i < 32; i++)
    {
        if(barraMascara1<i)
        {
            octetoBinario[i]='0';
        }
    }
    
    int valoresConvercao[8];
	valoresConvercao[0] = 128;
	valoresConvercao[1] = 64;
	valoresConvercao[2] = 32;
	valoresConvercao[3] = 16;
	valoresConvercao[4] = 8;
	valoresConvercao[5] = 4;
	valoresConvercao[6] = 2;
	valoresConvercao[7] = 1;
	
	int partesdoIPInt1=0;
	int partesdoIPInt2=0;
	int partesdoIPInt3=0;
	int partesdoIPInt4=0;
	
	contador = 0;
	contadorB = 0;
	for(int i = 0; i < 32; i++)
	{
	    if(octetoBinario[i]=='1')
	    {
	        if(i<8){
	            partesdoIPInt1=partesdoIPInt1+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        else if(i<16){
	            partesdoIPInt2=partesdoIPInt2+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        else if(i<24){
	            partesdoIPInt3=partesdoIPInt3+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        else if(i<32){
	            partesdoIPInt4=partesdoIPInt4+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        
	    }
	    else
	    {
	        contadorB++;
	    }
	    
	    if(contadorB==8)
	    {
	        contadorB=0;
	        contador++;
	    }
	}
	
	string resultado;
	stringstream converteAux[4];
	
	converteAux[0]<<partesdoIPInt1;
	resultado = resultado + converteAux[0].str()+".";
	converteAux[1]<<partesdoIPInt2;
	resultado = resultado+converteAux[1].str()+".";
	converteAux[2]<<partesdoIPInt3;
	resultado = resultado+converteAux[2].str()+".";
	converteAux[3]<<partesdoIPInt4;
	resultado = resultado+converteAux[3].str();
	
    return resultado;
}

string Tabela::broadcast(string entrada1, int barraMascara1)
{
	char octetoBinario[32];
    char partesDoIP[3];
    int partesdoIPInt[4];
    int contador=0;
    int contadorB=0;

    for(int i = 0; i < 32; i++)
    {
        octetoBinario[i]='0';
    }


    for(int i = 0; i < 15; i++)
    {
        if(entrada1[i]!= '.')
        {
            partesDoIP[contador]=entrada1[i];
            contador++;
        }
        else
        {
            contador=0;
            partesdoIPInt[contadorB]=atoi(partesDoIP);
            partesDoIP[0]=' ';
            partesDoIP[1]=' ';
            partesDoIP[2]=' ';
            contadorB++;
        }
        if(i==14)
        {
            partesdoIPInt[contadorB]=atoi(partesDoIP);
        }
    }

    int bin[8];
    int aux;

    for(int i = 3; i >= 0; i--)
    {
        for (aux = 7; aux >= 0; aux--) 
        {
            if (partesdoIPInt[i] % 2 == 0) {
                bin[aux] = 0;
                partesdoIPInt[i] = partesdoIPInt[i] / 2;
            }
            else {
                bin[aux] = 1;
                partesdoIPInt[i] = partesdoIPInt[i] / 2;
            }
        }
        
        for (aux = 0; aux < 8; aux++)
        {
            if(bin[aux]==1)
            {
                octetoBinario[aux+(8*i)]='1';
            }
            else
            {
                octetoBinario[aux+(8*i)]='0';
            }
        }
        
    }

    for (int i = 0; i < 32; i++)
	{
		if (i >= barraMascara1)
		{
			octetoBinario[i] = '1';
		}
	}
    
    int valoresConvercao[8];
	valoresConvercao[0] = 128;
	valoresConvercao[1] = 64;
	valoresConvercao[2] = 32;
	valoresConvercao[3] = 16;
	valoresConvercao[4] = 8;
	valoresConvercao[5] = 4;
	valoresConvercao[6] = 2;
	valoresConvercao[7] = 1;
	
	int partesdoIPInt1=0;
	int partesdoIPInt2=0;
	int partesdoIPInt3=0;
	int partesdoIPInt4=0;
	
	contador = 0;
	contadorB = 0;
	for(int i = 0; i < 32; i++)
	{
	    if(octetoBinario[i]=='1')
	    {
	        if(i<8){
	            partesdoIPInt1=partesdoIPInt1+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        else if(i<16){
	            partesdoIPInt2=partesdoIPInt2+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        else if(i<24){
	            partesdoIPInt3=partesdoIPInt3+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        else if(i<32){
	            partesdoIPInt4=partesdoIPInt4+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        
	    }
	    else
	    {
	        contadorB++;
	    }
	    
	    if(contadorB==8)
	    {
	        contadorB=0;
	        contador++;
	    }
	}
	
	string resultado;
	stringstream converteAux[4];
	
	converteAux[0]<<partesdoIPInt1;
	resultado = resultado + converteAux[0].str()+".";
	converteAux[1]<<partesdoIPInt2;
	resultado = resultado+converteAux[1].str()+".";
	converteAux[2]<<partesdoIPInt3;
	resultado = resultado+converteAux[2].str()+".";
	converteAux[3]<<partesdoIPInt4;
	resultado = resultado+converteAux[3].str();
	
    return resultado;
}

string Tabela::ipInicial(string entrada1, int barraMascara1)
{
    char octetoBinario[32];
    char partesDoIP[3];
    int partesdoIPInt[4];
    int contador=0;
    int contadorB=0;

    for(int i = 0; i < 32; i++)
    {
        octetoBinario[i]='0';
    }


    for(int i = 0; i < 15; i++)
    {
        if(entrada1[i]!= '.')
        {
            partesDoIP[contador]=entrada1[i];
            contador++;
        }
        else
        {
            contador=0;
            partesdoIPInt[contadorB]=atoi(partesDoIP);
            partesDoIP[0]=' ';
            partesDoIP[1]=' ';
            partesDoIP[2]=' ';
            contadorB++;
        }
        if(i==14)
        {
            partesdoIPInt[contadorB]=atoi(partesDoIP);
        }
    }

    int bin[8];
    int aux;

    for(int i = 3; i >= 0; i--)
    {
        for (aux = 7; aux >= 0; aux--) 
        {
            if (partesdoIPInt[i] % 2 == 0) {
                bin[aux] = 0;
                partesdoIPInt[i] = partesdoIPInt[i] / 2;
            }
            else {
                bin[aux] = 1;
                partesdoIPInt[i] = partesdoIPInt[i] / 2;
            }
        }
        
        for (aux = 0; aux < 8; aux++)
        {
            if(bin[aux]==1)
            {
                octetoBinario[aux+(8*i)]='1';
            }
            else
            {
                octetoBinario[aux+(8*i)]='0';
            }
        }
        
    }

    for(int i = 0; i < 32; i++)
    {
        if(barraMascara1<=i)
        {
            octetoBinario[i]='0';
        }
    }
    
    int valoresConvercao[8];
	valoresConvercao[0] = 128;
	valoresConvercao[1] = 64;
	valoresConvercao[2] = 32;
	valoresConvercao[3] = 16;
	valoresConvercao[4] = 8;
	valoresConvercao[5] = 4;
	valoresConvercao[6] = 2;
	valoresConvercao[7] = 1;
	
	int partesdoIPInt1=0;
	int partesdoIPInt2=0;
	int partesdoIPInt3=0;
	int partesdoIPInt4=0;
	
	contador = 0;
	contadorB = 0;
	for(int i = 0; i < 32; i++)
	{
	    if(octetoBinario[i]=='1')
	    {
	        if(i<8){
	            partesdoIPInt1=partesdoIPInt1+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        else if(i<16){
	            partesdoIPInt2=partesdoIPInt2+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        else if(i<24){
	            partesdoIPInt3=partesdoIPInt3+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        else if(i<32){
	            partesdoIPInt4=partesdoIPInt4+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        
	    }
	    else
	    {
	        contadorB++;
	    }
	    
	    if(contadorB==8)
	    {
	        contadorB=0;
	        contador++;
	    }
	}
	
	string resultado;
	stringstream converteAux[4];
	
	if((partesdoIPInt4 + 1)<255)
	{
	    partesdoIPInt4=partesdoIPInt4+1;
	}
	else if((partesdoIPInt3+1)<255)
	{
	    partesdoIPInt3=partesdoIPInt3+1;
	    partesdoIPInt4=0;
	}
	else if((partesdoIPInt2+1)<255)
	{
	    partesdoIPInt2=partesdoIPInt2+1;
	    partesdoIPInt3=0;
	    partesdoIPInt4=0;
	}
	else if((partesdoIPInt1+1)<255)
	{
	    partesdoIPInt1=partesdoIPInt1+1;
	    partesdoIPInt2=0;
	    partesdoIPInt3=0;
	    partesdoIPInt4=0;
	}else
	{
	    return "Nao existe um ip disponivel para ipInicial.";
	}
	
	converteAux[0]<<partesdoIPInt1;
	resultado = resultado + converteAux[0].str()+".";
	converteAux[1]<<partesdoIPInt2;
	resultado = resultado+converteAux[1].str()+".";
	converteAux[2]<<partesdoIPInt3;
	resultado = resultado+converteAux[2].str()+".";
	converteAux[3]<<partesdoIPInt4;
	resultado = resultado+converteAux[3].str();
	
	
    return resultado;
}


string Tabela::ipFinal(string entrada1, int barraMascara1)
{
	char octetoBinario[32];
    char partesDoIP[3];
    int partesdoIPInt[4];
    int contador=0;
    int contadorB=0;

    for(int i = 0; i < 32; i++)
    {
        octetoBinario[i]='0';
    }


    for(int i = 0; i < 15; i++)
    {
        if(entrada1[i]!= '.')
        {
            partesDoIP[contador]=entrada1[i];
            contador++;
        }
        else
        {
            contador=0;
            partesdoIPInt[contadorB]=atoi(partesDoIP);
            partesDoIP[0]=' ';
            partesDoIP[1]=' ';
            partesDoIP[2]=' ';
            contadorB++;
        }
        if(i==14)
        {
            partesdoIPInt[contadorB]=atoi(partesDoIP);
        }
    }

    int bin[8];
    int aux;

    for(int i = 3; i >= 0; i--)
    {
        for (aux = 7; aux >= 0; aux--) 
        {
            if (partesdoIPInt[i] % 2 == 0) {
                bin[aux] = 0;
                partesdoIPInt[i] = partesdoIPInt[i] / 2;
            }
            else {
                bin[aux] = 1;
                partesdoIPInt[i] = partesdoIPInt[i] / 2;
            }
        }
        
        for (aux = 0; aux < 8; aux++)
        {
            if(bin[aux]==1)
            {
                octetoBinario[aux+(8*i)]='1';
            }
            else
            {
                octetoBinario[aux+(8*i)]='0';
            }
        }
        
    }

    for (int i = 0; i < 32; i++)
	{
		if (i >= barraMascara1)
		{
			octetoBinario[i] = '1';
		}
	}
    
    int valoresConvercao[8];
	valoresConvercao[0] = 128;
	valoresConvercao[1] = 64;
	valoresConvercao[2] = 32;
	valoresConvercao[3] = 16;
	valoresConvercao[4] = 8;
	valoresConvercao[5] = 4;
	valoresConvercao[6] = 2;
	valoresConvercao[7] = 1;
	
	int partesdoIPInt1=0;
	int partesdoIPInt2=0;
	int partesdoIPInt3=0;
	int partesdoIPInt4=0;
	
	contador = 0;
	contadorB = 0;
	for(int i = 0; i < 32; i++)
	{
	    if(octetoBinario[i]=='1')
	    {
	        if(i<8){
	            partesdoIPInt1=partesdoIPInt1+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        else if(i<16){
	            partesdoIPInt2=partesdoIPInt2+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        else if(i<24){
	            partesdoIPInt3=partesdoIPInt3+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        else if(i<32){
	            partesdoIPInt4=partesdoIPInt4+valoresConvercao[contadorB];
	            contadorB++;
	        }
	        
	    }
	    else
	    {
	        contadorB++;
	    }
	    
	    if(contadorB==8)
	    {
	        contadorB=0;
	        contador++;
	    }
	}
	
	string resultado;
	stringstream converteAux[4];
	
	if(partesdoIPInt4>0)
	{
	    partesdoIPInt4=partesdoIPInt4 - 1;
	}
	else if(partesdoIPInt3>0)
	{
	    partesdoIPInt3=partesdoIPInt3 - 1;
	    partesdoIPInt4=255;
	}
	else if(partesdoIPInt2>0)
	{
	    partesdoIPInt2=partesdoIPInt2 - 1;
	    partesdoIPInt3=255;
	    partesdoIPInt4=255;
	}
	else if(partesdoIPInt1>0)
	{
	    partesdoIPInt1=partesdoIPInt1 - 1;
	    partesdoIPInt2=255;
	    partesdoIPInt3=255;
	    partesdoIPInt4=255;
	}
	else
	{
	    return "Nao existe ip disponivel para ip final.";
	}
	
	
	converteAux[0]<<partesdoIPInt1;
	resultado = resultado + converteAux[0].str()+".";
	converteAux[1]<<partesdoIPInt2;
	resultado = resultado+converteAux[1].str()+".";
	converteAux[2]<<partesdoIPInt3;
	resultado = resultado+converteAux[2].str()+".";
	converteAux[3]<<partesdoIPInt4;
	resultado = resultado+converteAux[3].str();
	
    return resultado;
}

int Tabela::decimalParaCidr(string notacaoDecimal) 
{
	int mascaraEmBinario[32];
	for(int i = 0; i < 32 ; i++)
	{
		mascaraEmBinario[i] = 0;
	}

	char primeiroConjunto[12];
	
	for (int i = 0; i < 12; i++)
	{
		if (notacaoDecimal[i] != '.')
		{
			primeiroConjunto[i] = notacaoDecimal[i];
		}
		
	}
	int parteDoIpEmInt[4];
	int mascaraCIDR=0;
	char parte1[3];
	char parte2[3];
	char parte3[3];
	char parte4[3];
	parteDoIpEmInt[0] = atoi(parte1);
	parteDoIpEmInt[1] = atoi(parte2);
	parteDoIpEmInt[2] = atoi(parte3);
	parteDoIpEmInt[3] = atoi(parte4);
	for (int i = 0; i < 4; i++)
	{
		if (parteDoIpEmInt[i] == 128)
		{
			mascaraCIDR += 1;
		}
		if (parteDoIpEmInt[i] == 192)
		{
			mascaraCIDR += 2;
		}
		if (parteDoIpEmInt[i] == 224)
		{
			mascaraCIDR += 3;
		}
		if (parteDoIpEmInt[i] == 240)
		{
			mascaraCIDR += 4;
		}
		if (parteDoIpEmInt[i] == 248)
		{
			mascaraCIDR += 5;
		}
		if (parteDoIpEmInt[i] == 252)
		{
			mascaraCIDR += 6;
		}
		if (parteDoIpEmInt[i] == 254)
		{
			mascaraCIDR += 7;
		}
		if (parteDoIpEmInt[i] == 255)
		{
			mascaraCIDR += 8;
		}
	}
	return mascaraCIDR;
}
