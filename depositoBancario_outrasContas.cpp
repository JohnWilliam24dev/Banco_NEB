#include <stdio.h>
# include "bancoDeDados.c" //Nome fictício do banco de dados Desenvolvido por João
#include "verificaPIN.c"
#include "dadosContaBeneficiaria"
int depositoBancario() { // a função retorna 1 se o depósito for realizado;
	int numero_conta_beneficiaria;
	int contaExiste = 0;
	
	printf("NUMERO DA CONTA BENEFICIARIA: ");
	scanf("%d", &numero_conta_beneficiaria);
	for(i = 0; i < LIMITE; i++) // LIMITE é uma constante definida em bancoDeDados.c, que define o número máximo de conta
	{
		if(numero_conta_beneficiaria == pessoaFisica[i].numeroConta)
		{
			contaExiste = 1;
			int posicao_vetorial_conta = i; //Posição da conta beneficiária no vetor Banco de Dados;	
			break;
		}
	}
	
	if(contaExiste = 0)
		return 0;
		
	else	
	{
		int escolha;
		int PIN_digitado;
		double valorDeposito;
			
		printf("VALOR DEPOSITADO: R$ ");
		scanf("%d", &valorDeposito);
		dadosContaBeficiaria(posicao_vetorial_conta);
		printf("\n\nCONFIRMAR DEPOSITO? (1 SIM | 0 NAO)	");
		scanf("%d", &escolha);
			
		if(escolha == 0)
			return 0;
			
		else
		{
			printf("PIN DA CONTA: ");
			scanf("%d", &PIN_digitado);
			verificaPIN(PIN_digitado);
				
			if(verificaPIN) 
			{
				pessoaFisica[contaUsuario].saldo -= valorDeposito; //contaUsuario será a posição no B.D armazenada quando a função login PF for executada;
				printf("DEPOSITO BANCARIO REALIZADO COM SUCESSO!\n");
				printf("PRESSIONE <ENTER> PARA CONTINUAR");
				getchar();
				return 1;
			}
			else
			{
				printf("PIN INCORRETO!\nOPERACAO CANCELADA\n");
				printf("PRESSIONE <ENTER> PARA CONTINUAR ");
				getchar();
				return 0;
			}
		}	
	}	
}

/*
Estrutura de Dados para Referência:
typedef struct {
	int numeroConta;
	char nome[100];
	char cpf[12];
	char endereco[200];
	char telefone[15];
	double saldo;
}PessoaFisica;
*/
