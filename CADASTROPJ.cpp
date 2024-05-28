
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastro1() {
    char cnpj[15];
    char nomeempresa[19];
    char nomepropietario[35];
    float idadeempresa;
    float idadepropietario;
    char senha[20];
    char CPF[12];  
    char telefone[10]; 

    printf("Por favor, digite seu nome (proprietario): ");
    scanf("%s", nomepropietario);

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

    printf("\nPor favor, digite a idade do proprietário: ");
    scanf("%f", &idadepropietario);

    
    do {
        printf("\nPor favor, digite o CPF (11 dígitos): ");
        scanf("%s", CPF);

        if (strlen(CPF) == 11) {
            printf("CPF válido.\n");
            break;
        } else {
            printf("CPF inválido. Por favor, digite novamente.\n");
        }
    } while (1);

    
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
}

int main() {
    cadastro1();
    return 0;
}