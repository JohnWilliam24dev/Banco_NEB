#include <stdio.h>
#include <stdlib.h>


void clearScreen() {
    printf("\nPressione Enter para continuar...");
    system("pause"); // Pausa o programa e aguarda o usuário pressionar Enter
    system("cls "); // Limpa a tela (compatível com Windows e Linux)
}

void FAQPF() {
    int choice;
    do {
        printf("\nCentral de Ajuda - Pessoa Fisica\n");
        printf("Escolha uma das opcoes abaixo:\n");
        printf("1 - Problemas com cadastro\n");
        printf("2 - Problemas com login\n");
        printf("3 - Problemas com transacoes\n");
        printf("4 - Atualizar informacoes pessoais\n");
        printf("5 - Recuperar senha\n");
        printf("6 - Contatar suporte\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Digite sua escolha: ");
        scanf("%d", &choice);

        getchar(); // Captura o caractere de nova linha deixado no buffer pelo scanf

        switch (choice) {
            case 1:
                printf("\nPara problemas com cadastro, verifique se todos os campos obrigatorios estao preenchidos corretamente.\n");
                clearScreen();
                break;
            case 2:
                printf("\nPara problemas com login, verifique se voce esta digitando seu usuario e senha corretamente. Caso tenha esquecido sua senha, utilize a opcao de recuperar senha.\n");
                clearScreen();
                break;
            case 3:
                printf("\nPara problemas com transacoes, certifique-se de que possui saldo suficiente e que esta utilizando os dados corretos do destinatario.\n");
                clearScreen();
                break;
            case 4:
                printf("\nPara atualizar suas informacoes pessoais, acesse sua conta e va para a secao 'Perfil' para fazer as alteracoes necessarias.\n");
                clearScreen();
                break;
            case 5:
                printf("\n Para recuperar a senha acesse a opçao Esqueci a senha, No menu de entrada.\n");
                clearScreen();
                break;
            case 6:
                printf("\nPara contatar o suporte, envie um email para suporte@banco.com ou ligue para 0800-123-456.\n");
                clearScreen();
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                clearScreen();
                break;
            default:
                printf("\nOpcao invalida! Por favor, tente novamente.\n");
                clearScreen();
        }
    } while (choice != 0);
}


