#include <stdio.h>
#include <stdlib.h>
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
	int tipoConta = tipoTransferencia;
	system("cls");
	processarTransferencia(tipoConta);
}

