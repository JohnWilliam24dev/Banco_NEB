#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void conta(int da){
	int saldo;
	
	fflush(stdin);
	scanf("%d", &saldo);
	system("cls");
	
	printf("\t\t\tBancoNeb\n");
	printf("\t{Bem vindo %d }\n\n" ,da);
	printf("\t\t\t\SALDO : %d\n\n", saldo);
	printf("--|PIX|------|TRANSFERENCIAS|-----|EXTRATO|------|INVESTIMENTOS|-\n");
	printf("  | 1 |______|      2       |_____|   3   |______|     4       |\n");
}

void entrar(){
   char cnpj[15], senha[15];
   int da = 1;
	do{
		printf("Coloque seu CNPJ abaixo !\n");
		scanf("%s", cnpj);
		fflush(stdin);
		printf("\nDigite a senha !\n");
		scanf("%s", senha);
	}while(strlen(cnpj) >14 && strlen(senha) > 8);
	
	conta(da);
}

void inicio(){
	int opt;
	
	printf("\t\t\t MMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("\t\t\t{  Bem vindo ao BancoNeb }\n");
	printf("\t\t\t WWWWWWWWWWWWWWWWWWWWWWWW\n\n");
	
	printf("\t\t\t\t  Deseja! \n\n\t\t\t\tCriar Conta 1 \n\t\t\tEntrar em conta existente 2\n");
	scanf("%d", &opt);
	
	switch (opt){
		case 1:
			printf("\\chamar funcao criar conta");
			break;
		case 2:
			entrar();
			break;
		case 3:
			printf("\\sair");
			break;
		default:
			printf("Opção invalida");
			break;
	}
}





int main (){
	inicio();
}
