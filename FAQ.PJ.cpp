#include <stdio.h>
#include <stdlib.h>
void FAQPJ() {
    int choice;
    do {
        printf("\nCentral de Ajuda - Pessoa Juridica\n");
        printf("Escolha uma das opcoes abaixo:\n");
        printf("1 - Problemas com cadastro\n");
        printf("2 - Problemas com login\n");
        printf("3 - Problemas com transacoes\n");
        printf("4 - Atualizar informacoes da empresa\n");
        printf("5 - Recuperar senha\n");
        printf("6 - Contatar suporte\n");
        printf("0 - Voltar ao menu principal\n");
        printf("Digite sua escolha: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nPara problemas com cadastro, verifique se todos os campos obrigatorios estao preenchidos corretamente, incluindo o CNPJ.\n");
                break;
            case 2:
                printf("\nPara problemas com login, verifique se você está digitando seu usuário e senha corretamente. Caso tenha esquecido sua senha, utilize a opçao de recuperar senha.\n");
                break;
            case 3:
                printf("\nPara problemas com transaçoes, certifique-se de que possui saldo suficiente e que está utilizando os dados corretos do destinatario.\n");
                break;
            case 4:
                printf("\nPara atualizar as informaçoes da sua empresa, acesse sua conta e va para a seçao 'Perfil da Empresa' para fazer as alteraçoes necessarias.\n");
                break;
            case 5:
                printf("\nPara recuperar sua senha, clique na opçao 'Esqueci minha senha' na pagina de login e siga as instruções enviadas para o email cadastrado.\n");
                break;
            case 6:
                printf("\nPara contatar o suporte, envie um email para suporte@banco.com ou ligue para 0800-123-456.\n");
                break;
            case 0:
                printf("\nVoltando ao menu principal...\n");
                break;
            default:
                printf("\nOpção inválida! Por favor, tente novamente.\n");
        }
    } while (choice != 0);
}
int main(){
	FAQPJ();
	
	return 0;
}