#include <stdio.h>
#include <stdlib.h>


void FAQ() {
    int choice;
    do {
        printf("\nBem vindo a central de ajuda!!\n");
        printf("Escolha uma das opcoes abaixo:\n");
        printf("1 - Problemas com cadastro\n");
        printf("2 - Problemas com login\n");
        printf("3 - Problemas com transaçoes\n");
        printf("4 - Outras duvidas\n");
        printf("0 - Sair\n");
        printf("Digite sua escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nPara problemas com cadastro, por favor, verifique se todos os campos obrigatórios estao preenchidos corretamente.\n");
                break;
            case 2:
                printf("\nPara problemas com login, verifique se você está digitando seu usuário e senha corretamente. Caso tenha esquecido sua senha, fale com suporte .\n");
                break;
            case 3:
                printf("\nPara problemas com transaçoes, certifique-se de que possui saldo suficiente e que está utilizando os dados corretos do destinatario.\n");
                break;
            case 4:
                printf("\nPara outras duvidas, entre em contato com nosso suporte através do email suporte@banconeb.com ou pelo telefone 0800-123-456.\n");
                break;
            case 0:
                printf("\nObrigado por utilizar a central de ajuda! Ate logo!\n");
                break;
            default:
                printf("\nOpçao invalida! Por favor, tente novamente.\n");
        }
    } while (choice != 0);
}

int main() {
    system("cls");  
    FAQ();         
    return 0;
}
