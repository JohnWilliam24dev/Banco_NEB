#include <stdio.h>
#include <stdlib.h>
void FAQPF() {
      int choice;
    do {
        printf("\nCentral de Ajuda - Pessoa Fisica\n");
        printf("Escolha uma das opcoes abaixo:\n");
        printf("1 - Problemas com cadastro\n");
        printf("2 - Problemas com login\n");
        printf("3 - Problemas com transacoes\n");
        printf("4 - Atualizar informações pessoais\n");
        printf("5 - Recuperar senha\n");
        printf("6 - Contatar suporte\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Digite sua escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nPara problemas com cadastro, verifique se todos os campos obrigatorios estao preenchidos corretamente.\n");
                getchar();
                system("cls");
                break;
            case 2:
                printf("\nPara problemas com login, verifique se você esta digitando seu usuario e senha corretamente. Caso tenha esquecido sua senha, utilize a opcao de recuperar senha.\n");
                getchar();
                system("cls");
                break;
            case 3:
                printf("\nPara problemas com transações, certifique-se de que possui saldo suficiente e que está utilizando os dados corretos do destinatário.\n");
                getchar();
                system("cls");
                break;
            case 4:
                printf("\nPara atualizar suas informcoes pessoais, acesse sua conta e vá para a secao 'Perfil' para fazer as alteracoes necessarias.\n");
                getchar();
                system("cls");
                break;
            case 5:
                printf("\nPara recuperar sua senha, clique na opção 'Esqueci minha senha' na página de login e siga as instrucoes enviadas para o seu email.\n");
                getchar();
                system("cls");
                break;
            case 6:
                printf("\nPara contatar o suporte, envie um email para suporte@banco.com ou ligue para 0800-123-456.\n");
                getchar();
                system("cls");
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpcao invalida! Por favor, tente novamente.\n");
        }
    } while (choice != 0);
}

