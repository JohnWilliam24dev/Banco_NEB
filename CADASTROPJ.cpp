#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include "crud.c"

void cadastro1() {
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

int main() {
    cadastro1();
    return 0;
}