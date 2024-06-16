#include <stdio.h>
#include <stdlib.h>
#include "Database.h"
#include <windows.h>
#include <string.h>
void pausarExecucao();
int tipoTransferencia();
void processarTransferencia(int tipo);
void transferencia(char *CPF_usuarioPF);
int buscarCPF(char * CPF, float saldoBeneficiario);
int verificaPIN(char *PIN_fornecido, char *CPF_user);
int verificaSaldo(char *CPF_user, float valorTransferido);
int transferenciaPF();
int buscarCNPJ(char *CNPJ, float saldoBeneficiario);
int transferenciaPJ();
int printExtrato_PF(char *CPF_user);
int printExtrato_PJ(char *CNPJ_user);
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes
char CPF_usuario[13]; //STRING global;


void pausarExecucao(){
	printf("PRESSIONE <ENTER> PARA CONTINUAR");
	getchar();
	fflush(stdin);
	system("cls");
}
/* AS FUNÃƒâ€¡Ãƒâ€¢ES COMENTADAS ABAIXO POSSIVELMENTE SERÃƒÆ’O APAGADAS;

int menuTransferencia() {
	char digitoOperacao;
	printf("\tMENU DE TRANSFERENCIAS\n\n");
	printf("1. REALIZAR NOVA TRANSFERENCIA\n");
	printf("2. VERIFICAR EXTRATO DE TRANSFERENCIAS\n");
	printf("0. RETORNAR PARA O MENU INICIAL\n");
	scanf("%d", &digitoOperacao);
	return digitoOperacao;
}

void processarOperacao(int digito) { //"digito" ÃƒÆ’Ã‚Â© uma variÃƒÆ’Ã‚Â¡vel retorno obtida por menuTransferencia;
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
*/

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
			transferenciaPF();
			break;
		case 2:
			transferenciaPJ();
			break;
		default:
			printf("DIGITO INVALIDO!\n");
			pausarExecucao();		
	}
}

void transferencia(char *CPF_usuarioPF) {
	int i = 0;
	char *ptr = CPF_usuarioPF;
	
	while(*ptr != '\0')
	{
		CPF_usuario[i] = *ptr; //CPF_usuario STRING global;
		ptr++;
		i++;
	}
	
	int tipoConta = tipoTransferencia();
	fflush(stdin);
	system("cls");
	processarTransferencia(tipoConta);
}


/*OBS 1: A funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o buscarCPF retorna 1 se o CPF existir;
retorna 0 se o CPF ÃƒÆ’Ã‚Â© inexistente;
OBS 2: A funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Â£o "retorna" como parÃƒÆ’Ã‚Â¢metro o saldo
da Conta BeneficiÃƒÆ’Ã‚Â¡ria;*/

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
	saldo = atof(request_PF(&cpfBuscado[0], 7));
	
	saldoBeneficiario = (float) saldo;
	
	return 1;
}

int verificaPIN(char *PIN_fornecido, char *CPF_user) {
	char pin_user[5];
	strcpy(pin_user, request_PF(&CPF_usuario[0], 2));
	if(strcmp(pin_user, PIN_fornecido)==0)
	{
		return 1;
	}
	return 0;
}

int verificaSaldo(char *CPF_user, float valorTransferido) {
	float saldo;
	double saldo_double;
	saldo_double = atof(request_PF(&CPF_usuario[0], 7));
	saldo = (float) saldo_double;
	
	if(valorTransferido > 0 && valorTransferido <= saldo)
	{
		return 1;
	}
	return 0;
}

int transferenciaPF() {
	char cpf[13];
	float saldoBeneficiario;
	float valor;
	char PIN_usuario[5];
	
	printf("CPF CONTA BENEFICIARIA: ");
	gets(cpf);
	fflush(stdin);
	int contaExiste = buscarCPF(&cpf[0], saldoBeneficiario);
	
	if(contaExiste)
	{
		printf("VALOR A SER TRANSFERIDO: R$ ");
		scanf("%f", &valor);
		fflush(stdin);
		printf("PIN DA CONTA: ");
		gets(PIN_usuario);
		fflush(stdin);
		int pinCorreto = verificaPIN(&PIN_usuario[0], &CPF_usuario[0]); //CPF_usuario provÃƒÆ’Ã‚Â©m de funÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Âµes anteriores;
		
		if(pinCorreto) 
		{
			int saldoValido = verificaSaldo(&CPF_usuario[0], valor);
			if(saldoValido)
			{
				//ModificaÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Âµes no saldo do USUÃƒÆ’Ã‚ÂRIO;
				double saldo_usuario_double;
				float saldo_usuario;
				
				saldo_usuario_double = atof(request_PF(&CPF_usuario[0], 7));
				saldo_usuario = (float) saldo_usuario_double;
				saldo_usuario -= valor;
				
				char novo_saldo_usuario[20];
				sprintf(novo_saldo_usuario, "%.2f", saldo_usuario); //converter float saldo_usuario para string;
				
				edit_PF(&CPF_usuario[0], 7, &novo_saldo_usuario[0]);
				
				
				//ModificaÃƒÆ’Ã‚Â§ÃƒÆ’Ã‚Âµes no saldo do BENEFICIÃƒÆ’Ã‚ÂRIO;
				double saldo_beneficiario_double;
				float saldo_beneficiario;
				
				saldo_beneficiario_double = atof(request_PF(&cpf[0], 7));
				saldo_beneficiario = (float) saldo_beneficiario_double;
				saldo_beneficiario += valor;
				
				char novo_saldo_beneficiario[20];
				sprintf(novo_saldo_beneficiario, "%.2f", saldo_beneficiario); //converter float saldo_beneficiario para string;
				
				edit_PF(&cpf[0], 7, &novo_saldo_beneficiario[0]);
				
				printf("TRANSFERENCIA REALIZADA COM SUCESSO!\n");
				pausarExecucao();
				fflush(stdin);
				system("cls");
				
				return 1;
			}
			
			else
			{
				printf("ERRO OU SALDO INSUFICIENTE!\n");
				pausarExecucao();
				return 0;
			}
		}
		
		else
		{
			printf("PIN INCORRETO!\n");
			pausarExecucao();
			return 0;
		}
	}
	
	else
	{
		printf("CONTA INEXISTENTE!\n");
		pausarExecucao();
		return 0;
	}
}


int buscarCNPJ(char * CNPJ, float saldoBeneficiario) {
	char cnpjBuscado[15];
	char *ptr = CNPJ;
	int i = 0;
	while(*ptr !='\0')
	{
		cnpjBuscado[i] = *ptr;
		ptr++;
		i++;
	}
	
	char path[100] = "./PJ/userPJ";
	strcat(path, cnpjBuscado);
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
	saldo = atof(request_PJ(&cnpjBuscado[0], 7));
	
	saldoBeneficiario = (float) saldo;
	
	return 1;
}

int transferenciaPJ() {
	char cnpj[15];
	float saldoBeneficiario;
	float valor;
	char PIN_usuario[5];
	
	printf("CNPJ CONTA BENEFICIARIA: ");
	gets(cnpj);
	fflush(stdin);
	int contaExiste = buscarCNPJ(&cnpj[0], saldoBeneficiario);
	
	if(contaExiste)
	{
		printf("VALOR A SER TRANSFERIDO: R$ ");
		scanf("%f", &valor);
		fflush(stdin);
		printf("PIN DA CONTA: ");
		gets(PIN_usuario);
		fflush(stdin);
		int pinCorreto = verificaPIN(&PIN_usuario[0], &CPF_usuario[0]); //CPF_usuario provÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â©m de funÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Âµes anteriores;
		
		if(pinCorreto) 
		{
			int saldoValido = verificaSaldo(&CPF_usuario[0], valor);
			if(saldoValido)
			{
				//ModificaÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Âµes no saldo do USUÃƒÆ’Ã†â€™Ãƒâ€šÃ‚ÂRIO;
				double saldo_usuario_double;
				float saldo_usuario;
				
				saldo_usuario_double = atof(request_PF(&CPF_usuario[0], 7));
				saldo_usuario = (float) saldo_usuario_double;
				saldo_usuario -= valor;
				
				char novo_saldo_usuario[20];
				sprintf(novo_saldo_usuario, "%.2f", saldo_usuario); //converter float saldo_usuario para string;
				
				edit_PF(&CPF_usuario[0], 7, &novo_saldo_usuario[0]);
				
				
				//ModificaÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Âµes no saldo do BENEFICIÃƒÆ’Ã†â€™Ãƒâ€šÃ‚ÂRIO;
				double saldo_beneficiario_double;
				float saldo_beneficiario;
				
				saldo_beneficiario_double = atof(request_PJ(&cnpj[0], 7));
				saldo_beneficiario = (float) saldo_beneficiario_double;
				saldo_beneficiario += valor;
				
				char novo_saldo_beneficiario[20];
				sprintf(novo_saldo_beneficiario, "%.2f", saldo_beneficiario); //converter float saldo_beneficiario para string;
				
				edit_PJ(&cnpj[0], 7, &novo_saldo_beneficiario[0]);
				
				printf("TRANSFERENCIA REALIZADA COM SUCESSO!\n");
				pausarExecucao();
				fflush(stdin);
				system("cls");
				
				return 1;
			}
			
			else
			{
				printf("ERRO OU SALDO INSUFICIENTE!\n");
				pausarExecucao();
				fflush(stdin);
				return 0;
			}
		}
		
		else
		{
			printf("PIN INCORRETO!\n");
			pausarExecucao();
			fflush(stdin);
			return 0;
		}
	}
	
	else
	{
		printf("CONTA INEXISTENTE!\n");
		pausarExecucao();
		fflush(stdin);
		return 0;
	}
}

int printExtrato_PF(char *CPF_user) {
	char path[100] = "./PF/extratos";
	strcat(path, CPF_user);
	char ext[15] = ".txt";
	strcat(path, ext);
	
	FILE *arquivo;
	arquivo = fopen(path, "r");
	
	if(arquivo == NULL)
	{
		printf("EXTRATO VAZIO!\n");
		pausarExecucao();
		return 0;
	}	
	
	char CPF_CNPJ_destino[15];
	char nome_conta_destino[100];
	char saldo_atual[50];
	char valor_movimentado[50];
	int count; //variÃ¡vel utilizada para saber se o DESTINO da trasnferÃªncia/depÃ³sito Ã© um CPF ou CNPJ;
	
	printf("\tEXTRATO DE TRANSFERENCIAS E DEPOSITOS\n\n");
	while(fscanf(arquivo, "%s %s %s", CPF_CNPJ_destino, valor_movimentado, saldo_atual)==3)
	{
		count = strlen(CPF_CNPJ_destino);
		
		if(count == 12)
		{
			strcpy(nome_conta_destino, request_PF(CPF_CNPJ_destino, 0));
		}
		else
		{
			strcpy(nome_conta_destino, request_PJ(CPF_CNPJ_destino, 0));
		}
		
		printf("NOME CONTA DESTINO: %s\n", nome_conta_destino);
		printf("VALOR MOVIMENTADO: R$ %s\n", valor_movimentado);
		printf("SALDO ATUAL: R$ %s\n\n", saldo_atual);
	}
	
	fclose(arquivo);
	printf("PRESSIONE QUALQUER TECLA PARA SAIR DO EXTRATO");
	getchar();
	fflush(stdin);
	system("cls");
	return 1;
}

int printExtrato_PJ(char *CNPJ_user) {
	char path[100] = "./PJ/extratos";
	strcat(path, CNPJ_user);
	char ext[15] = ".txt";
	strcat(path, ext);
	
	FILE *arquivo;
	arquivo = fopen(path, "r");
	
	if(arquivo == NULL)
	{
		printf("EXTRATO VAZIO!\n");
		pausarExecucao();
		return 0;
	}
		
		char CPF_CNPJ_destino[15];
		char nome_conta_destino[100];
		char saldo_atual[50];
		char valor_movimentado[50];
		int count; //variÃ¡vel utilizada para saber se o DESTINO da trasnferÃªncia/depÃ³sito Ã© um CPF ou CNPJ;
			
	printf("\tEXTRATO DE TRANSFERENCIAS E DEPOSITOS\n\n");
	while(fscanf(arquivo, "%s %s %s", CPF_CNPJ_destino, valor_movimentado, saldo_atual)==3)
	{
		count = strlen(CPF_CNPJ_destino);
		
		if(count == 12)
		{
			strcpy(nome_conta_destino, request_PF(CPF_CNPJ_destino, 0));
		}
		else
		{
			strcpy(nome_conta_destino, request_PJ(CPF_CNPJ_destino, 0));
		}
		
		printf("NOME CONTA DESTINO: %s\n", nome_conta_destino);
		printf("VALOR MOVIMENTADO: R$ %s\n", valor_movimentado);
		printf("SALDO ATUAL: R$ %s\n\n", saldo_atual);
	}
	
	fclose(arquivo);
	printf("PRESSIONE QUALQUER TECLA PARA SAIR DO EXTRATO");
	getchar();
	fflush(stdin);
	system("cls");
	return 1;
}
