#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "crud.c"
void pausarExecucao() {
	printf("pressione <ENTER> para continuar");
	getchar();
	fflush(stdin);
	system("cls");
}
void cadastro1() {
    char CNPJ[15];
    char nomeEmpresa[19];
    char idadeEmpresa[5];
    char senha[20]; 
    char pin[5];
    char telefone[10]; 
    char CEP[9];
    float saldo = 0;
    float credito = 0;
 
    printf("\nPor favor, digite o nome da empresa: ");
    gets(nomeEmpresa);

    
    do {
        printf("\nPor favor, digite o CNPJ (14 dÃ­gitos): ");
        scanf("%s", CNPJ);
        gets(CNPJ);

        if (strlen(CNPJ) == 14) {
            printf("CNPJ vÃ¡lido.\n");
            pausarExecucao()
            break;
        } else {
            printf("CNPJ invÃ¡lido. Por favor, digite novamente.\n");
            pausarExecucao()
        }
    } while (1);

    printf("\nPor favor, digite a idade da empresa: ");
    gets(idadeEmpresa);


    do {
        printf("\nPor favor, digite o telefone (8 dÃ­gitos): ");
        gets(telefone);

        if (strlen(telefone) == 8) {
            printf("Telefone vÃ¡lido.\n");
            pausarExecucao()
            break;
        } else {
            printf("Telefone invÃ¡lido. Por favor, digite novamente.\n");
            pausarExecucao()
        }
    } while (1);

    
    do {
        printf("\nPor favor, crie uma senha (mÃ­nimo 8 caracteres): ");
        gets(senha);
        if (strlen(senha) >= 8) {  
            printf("Senha validada!!\n");
            pausarExecucao()
            break;
        } else {
            printf("Senha invÃ¡lida. Digite novamente.\n");
            pausarExecucao()
        }
    } while (1);
    do {
        printf("\nPor favor, coloquei o pin : ");
        gets(pin);
        if (strlen(pin) == 4) {  
            printf("pin validado!!\n");
            pausarExecucao()
            break;
        } else {
            printf("Pin invÃ¡lido. Digite novamente.\n");
            pausarExecucao()
        }
    } while (1);
    do {
        printf("\nPor favor, coloque o cep: ");
        gets(CEP);
        if (strlen(CEP) == 8) {  
            printf("Cep validada!!\n");
            pausarExecucao()
            break;
        } else {
            printf("Cep invÃ¡lida. Digite novamente.\n");
            pausarExecucao()
        }
    } while (1);

    system("cls");
	
	printf("Cadastro finalizado");
	pausarExecucao()
	
	   
    system("cls");
    printf("\nO seu saldo Ã©: %.2f\n", saldo);
    printf("O seu crÃ©dito Ã©: %.2f\n", credito);  
    pausarExecucao()
	
	insert_client_legal_entire(nomeEmpresa, senha, pin, idadeEmpresa, CNPJ, telefone, CEP, saldo, credito); 
}

int main() {
    cadastro1();
    return 0;
}
