#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void cadastro1() {
    char cnpj[15];
    char nomeempresa[19];
    char nomepropietario[35];
    float idadeempresa;
    float idadepropietario;

    printf("Por favor, digite seu nome(propietario): ");
    scanf("%s", nomepropietario);
    
    printf("\nPor favor, digite o nome da empresa: ");
    scanf("%s", nomeempresa);
    
    printf("\nPor favor, digite o cnpj: ");
    scanf("%s", cnpj);
    
 do {
        printf("\nPor favor, digite o CNPJ: ");
        scanf("%s", cnpj);

        if(strlen(cnpj) == 14) {
            printf("CNPJ válido.\n");
            break;
        } else {
            printf("CNPJ inválido. Por favor digite novamente.\n");
        }
    } while (1);
    
    printf("\nPor favor, digite a idade da empresa: ");
    scanf("%f", &idadeempresa);
    
    printf("\nPor favor, digite a idade do propietrio: ");
    scanf("%f", &idadepropietario);
}

int main() {
    cadastro1();
    return 0;
}
