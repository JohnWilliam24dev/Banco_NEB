#include <stdio.h>
#include <stdlib.h>
#include <database.c>
#include <windows.h>
void pausarExecucao() {
	printf("PRESSIONE <ENTER> PARA CONTINUAR");
	getchar();
	fflush(stdin);
	system("cls");
}

int menuTransferencia() {
	char digitoOperacao;
	printf("\tMENU DE TRANSFERENCIAS\n\n");
	printf("1. REALIZAR NOVA TRANSFERENCIA\n");
	printf("2. VERIFICAR EXTRATO DE TRANSFERENCIAS\n");
	printf("0. RETORNAR PARA O MENU INICIAL\n");
	scanf("%d", &digitoOperacao);
	return digitoOperacao;
}

void processarOperacao(int digito) { //"digito" é uma variável retorno obtida por menuTransferencia;
	switch(digito)
	{
		case 0:
			//pausarExecucao();
			break;
		case 1:
			//transferencia();
			break;
		case 2:
			//extratoTrasnferencia();
			break;
		default:
			//printf("OPCAO INVALIDA!\n");
			//pausarExecucao();
	}
}

int tipoTransferencia() {
	int digitoTransf;
	printf("\tTRANSFERENCIA BANCARIA\n\n");
	printf("SELECIONE TIPO DE CONTA BENEFICIARIA:\n");
	printf("1. PESSOA FISICA\n");
	printf("2. PESSOA JURIDICA\n");
	printf("INSERIR DIGITO --> ");
	scanf("%d", &digitoTransf);
	return digitoTransf;
}

void processarTransferencia(int tipo) { //tipo == 'PF' ou 'PJ'
	switch(tipo)
	{
		case 1:
			//transferenciaPF();
		case 2:
			//transferenciaPJ();
		default:
			//printf("DIGITO INVALIDO!\n");
			//pausarExecucao();		
	}
}

void transferencia() {
	int tipoConta = tipoTransferencia();
	system("cls");
	processarTransferencia(tipoConta);
}


/*OBS 1: A função buscarCPF retorna 1 se o CPF existir;
retorna 0 se o CPF é inexistente;
OBS 2: A função "retorna" como parâmetro o saldo
da Conta Beneficiária;*/

int buscarCPF(char * CPF, float saldoBeneficiario) {
	char cpfBuscado[13];
	char *ptr = CPF;
	int i = 0;
	while(*ptr !='\0')
	{
		cpfBuscado[i] = *ptr;
		ptr++;
		i++;
	}
	
	char path[100] = "./PF/userPF";
	strcat(path, cpfBuscado);
	char ext[15] = {".txt"};
	strcat(path, ext);
	FILE *arquivo;
	arquivo = fopen(path, "r");
	if(arquivo == NULL)
	{
		return 0;
	}
	fclose(arquivo);
	
	double saldo; 
	saldo = atof(request_PF(cpfBuscado, 7));
	
	saldoBeneficiario = (float) saldo;
	
	return 1;
}

void transferenciaPF() {
	char cpf[13];
	float saldoBeneficiario;
	printf("CPF CONTA BENEFICIARIA: ");
	gets(cpf);
	int contaExiste = buscarCPF(cpf, saldoBeneficiario);
	
	if(contaExiste)
	{
		//valor a ser transferido e demais procedimentos;
	}
	else
	{
		//printf("CONTA INEXISTENTE!\n");
		//pausarExecucao();
	}
}
