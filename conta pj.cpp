#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void transferir(){
	char tipo[4], cnpj[16];
	float quantia;
	float *qtd_conta = request(cnpj, 7);
	int opt;
	
	do{	 
	system("cls");
		printf("\t\t\tBancoNeb\n");
		printf("\t{Bem vindo à area de tranferencias }\n\n" ,);
		printf("\t\t\tV Dados do destinatario V\n\n");
		printf("Cnpj da conta : ");
		scanf("%s", cnpj);
		printf("Quantia a ser enviada");
		scanf("%f", &quantia);
		printf("Tipo da conta PJ/PF");
		scanf("%s", tipo);
		
		if(qtd_conta < quantia){
			printf("Valor invalido\nTente Novamente\n");
		}
		printf("Deseja Sair 1\n Tentar Novamente outro");
		scanf("%d", &opt);
		if(opt==1)
			conta();
			
	} while(qtd_conta < quantia)
	
	printf("Transferencia concluida\n");
	conta();
}
           
void conta(char *cnpj){
	float *saldo = request(*cnpj,7);
	char *nome = request(*cnpj,0);
	int opt;

	system("cls");
	
	printf("\t\t\tBancoNeb\n");
	printf("\t{Bem vindo %d }\n\n" ,da);
	printf("\t\t\t\SALDO : %d\n\n", saldo);
	printf("--|PIX|------|TRANSFERENCIAS|-----|EXTRATO|\n");
	printf("  | 1 |______|      2       |_____|   3   |\n");
	
	scanf("%d", &opt);
	switch(opt){
		case 1:
			transferir();
			break:
		case 2:
			tranferir();
			break;
		case 3:
			extrato();
			break;
		default
			printf("Opção invalida");
			break;
	}
}

void entrar(){
   char cnpj[15], senha[15], *CNPJ;
   int da = 1;
   *CNPJ = &cnpj
	do{
		printf("Coloque seu CNPJ abaixo !\n");
		scanf("%s", cnpj);
		fflush(stdin);
		printf("\nDigite a senha !\n");
		scanf("%s", senha);
	}while(strlen(cnpj) !=14 && strlen(senha) < 8);
	
	conta(CNPJ);
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
