#include <stdio.h>
#include <string.h>
#include <banco_de_dados_boleto.cpp>
int buscar_codigoBoleto_BD(char *codigo) {
	char *ptr = codigo;
	char codigo_recebido[MAX_SIZE];
	//1. Cria uma cópia da string do Código Boleto, para ser comparada com os códigos pertencentes ao boleto;
	for(int i = 0; i < MAX_SIZE; i++)
	{
		codigo_recebido[i] = *ptr;
		ptr++;
	}
	//2. Retorna 1 se o código recebido existir no Banco de Dados;
	for(int i = 0; i < QTD; i++)
	{
		if(strcmp(codigo_recebido, codigos[i].codigo_boleto)==0)
		{
			return 1;
		}
		return 0;
	}
}
