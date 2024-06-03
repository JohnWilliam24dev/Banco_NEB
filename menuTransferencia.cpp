#include <stdio.h>
#include <stdlib.h>
int menuTransferencia() {
	char digitoOperacao;
	printf("\tMENU DE TRANSFERENCIAS\n\n");
	printf("1. REALIZAR NOVA TRANSFERENCIA\n");
	printf("2. VERIFICAR EXTRATO DE TRANSFERENCIAS\n");
	printf("0. RETORNAR PARA O MENU INICIAL\n");
	scanf("%d", &digitoOperacao);
	return digitoOperacao;
}

void pausarExecucao() {
	printf("PRESSIONE <ENTER> PARA CONTINUAR");
	getchar();
	fflush(stdin);
	system("cls");
}
