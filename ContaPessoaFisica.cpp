#include <stdio.h>
#include <stdlib.h>

void escolhaInicial(int *opcaoInicial){
	
	switch(*opcaoInicial){
		case 1:
			//entradaCliente
			printf("Você escolheu acessar sua conta.\n");
			break;
			
		case 2:
			//cadastraCliente
			printf("Você escolheu ser cliente.\n");
			break;
			
		case 3:
			printf("Você escolheu sair do aplicativo.\n");
			break;
			
		default:
			printf("Opção incorreta, por favor tente novamente!\n");
	}
	
}

void menu(){
	
	int opcaoInicial;

	printf("Bem vindo ao Banco Neb!\n");
	printf("1. Acessar sua conta\n");
	printf("2. Quero ser cliente\n");
	printf("3. Sair do aplicativo\n");
	
	scanf("%d", &opcaoInicial);
	fflush(stdin);
	
	system("cls");
	
	escolhaInicial(&opcaoInicial);
	
}
	

int main(){
	
	int continuar;
	
	do{
	menu();
	continuar==escolhaInicial(&opcaoInicial);
	}while(continuar!=0);
	
}