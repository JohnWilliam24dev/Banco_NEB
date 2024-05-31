#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crud.c"

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

void cadastro() {
    char cnpj[15];
    char nomeempresa[19];
    float idadeempresa;
    char senha[20]; 
    char pin[5];
    char telefone[10]; 
    char cep[9];
    float saldo = 0;
    float credito = 0;
 
    printf("\nPor favor, digite o nome da empresa: ");
    scanf("%s", nomeempresa);

    
    do {
        printf("\nPor favor, digite o CNPJ (14 dígitos): ");
        scanf("%s", cnpj);

        if (strlen(cnpj) == 14) {
            printf("CNPJ válido.\n");
            break;
        } else {
            printf("CNPJ inválido. Por favor, digite novamente.\n");
        }
    } while (1);

    printf("\nPor favor, digite a idade da empresa: ");
    scanf("%f", &idadeempresa);


    do {
        printf("\nPor favor, digite o telefone (8 dígitos): ");
        scanf("%s", telefone);

        if (strlen(telefone) == 8) {
            printf("Telefone válido.\n");
            break;
        } else {
            printf("Telefone inválido. Por favor, digite novamente.\n");
        }
    } while (1);

    
    do {
        printf("\nPor favor, crie uma senha (mínimo 8 caracteres): ");
        scanf("%s", senha);
        if (strlen(senha) >= 8) {  
            printf("Senha validada!!\n");
            break;
        } else {
            printf("Senha inválida. Digite novamente.\n");
        }
    } while (1);
    do {
        printf("\nPor favor, coloquei o pin : ");
        scanf("%s", pin );
        if (strlen(pin) == 4) {  
            printf("pin validado!!\n");
            break;
        } else {
            printf("Pin inválido. Digite novamente.\n");
        }
    } while (1);
    do {
        printf("\nPor favor, coloque o cep: ");
        scanf("%s", cep);
        if (strlen(cep) == 8) {  
            printf("Cep validada!!\n");
            break;
        } else {
            printf("Cep inválida. Digite novamente.\n");
        }
    } while (1);

    system("cls");
	
	printf("Cadastro finalizado");
	
	   
    system("cls");
    printf("\nO seu saldo é: %.2f\n", saldo);
    printf("O seu crédito é: %.2f\n", credito);  
	
	insert_client_legal_entire(nomeempresa, senha, pin, idadeempresa, cnpj, telefone, cep, saldo, credito); 
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
			cadastro();
			break;
		case 2:
			entrar();
			break;
		case 3:
			printf("saindo");
			abort();
		default:
			printf("Opção invalida");
			break;
	}
}





int main (){
	inicio();
}
