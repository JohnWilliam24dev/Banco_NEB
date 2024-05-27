#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <sys/stat.h>
#include <string.h>

// Definição da estrutura Cliente
typedef struct {
    char nome[50];
    char senha[9];
    int pin;
    char cpf[13];
    float credito;
    char telefone[13];
    char endereco[50];
    float saldo;
    char data_de_nascimento[10];
    char profissao[50];
} Cliente;

// Função para entrada de cliente
void entradaCliente() {
    char verifCpf[13];
    char verifSenha[9];
    int opcaoCliente;

    printf("Por favor insira seu CPF: \n");
    scanf("%s", verifCpf);
    fflush(stdin);

    // Procurar no banco de dados se há um CPF compatível, caso não exista, mostrar uma mensagem e retornar

    printf("Senha: \n");
    scanf("%s", verifSenha);
    fflush(stdin);

    // Procurar no banco de dados se a senha é compatível com o CPF, caso erre 3 vezes a conta é bloqueada

    // Caso o CPF e a senha estejam corretos, mostrar o menu do cliente
    wprintf(L"Bem vindo(a)! Como podemos ajudar-lo?\n");
    wprintf(L"1. Verificar saldo\n");
    wprintf(L"2. Transferência\n");
    wprintf(L"3. Verificar extrato\n");
    wprintf(L"4. Solicitar empréstimo\n");
    wprintf(L"5. Fazer um depósito\n");
    wprintf(L"6. Alterar informações pessoais\n");
    wprintf(L"7. Finalizar sessão\n");
    scanf("%d", &opcaoCliente);

    switch(opcaoCliente) {
        case 1:
            // Verificar saldo
            break;
        case 2:
            // Transferência
            break;
        case 3:
            // Verificar extrato
            break;
        case 4:
            // Solicitar empréstimo
            break;
        case 5:
            // Fazer um depósito
            break;
        case 6:
            // Alterar informações pessoais
            break;
        case 7:
            wprintf(L"Você escolheu sair do aplicativo.\n");
            exit(0);
            break;
        default:
            wprintf(L"Opção incorreta, por favor tente novamente!\n");
            break;
    }
}

// Função para cadastrar cliente
void cadastraCliente() {
    Cliente cliente;
    
    setlocale(LC_ALL, "Portuguese");
    
    wprintf(L"Vamos começar com seu CPF.\n");
    scanf("%s", cliente.cpf);
    
    // Fazer uma forma de contar a quantidade de caracteres do CPF
    
    system("cls");
    
    wprintf(L"Nos fale um pouco sobre você!\n\n");
    
    wprintf(L"Qual o seu nome?\n");
    scanf("%s", cliente.nome);
    
    wprintf(L"Qual é a sua data de nascimento?\n");
    scanf("%s", cliente.data_de_nascimento);
    
    wprintf(L"Qual é a sua profissão?\n");
    scanf("%s", cliente.profissao);
    
    system("cls");
    
    wprintf(L"Qual é seu telefone?\n");
    scanf("%s", cliente.telefone);
    
    wprintf(L"Qual é o seu endereço?\n");
    scanf("%s", cliente.endereco);
    
    system("cls");
    
    wprintf(L"Agora vamos criar a sua senha!\n");
    wprintf(L"Por favor, crie uma senha com 8 caracteres que contenham números, letras e caracteres.\n");
    scanf("%s", cliente.senha);
    
    system("cls");
    // Criar uma verificação para descobrir se a senha tem caracteres, números e caracteres especiais.
    // insert_client_natural_person();
}

// Função para exibir o menu principal
int menu() {
    int opcaoInicial;

    setlocale(LC_ALL, "Portuguese");
    wprintf(L"Bem vindo ao Banco Neb!\n");
    wprintf(L"1. Acessar sua conta\n");
    wprintf(L"2. Quero ser cliente\n");
    wprintf(L"3. Sair do aplicativo\n");
    
    scanf("%d", &opcaoInicial);
    fflush(stdin);
    
    system("cls");
    
    switch(opcaoInicial) {
        case 1:
            entradaCliente();
            break;
        case 2:
            cadastraCliente();
            break;
        case 3:
            wprintf(L"Você escolheu sair do aplicativo.\n");
            exit(0);
            break;
        default:
            wprintf(L"Opção incorreta, por favor tente novamente!\n");
            break;
    }
    return 1;    
}

// Função principal
int main() {
    int continuar;
    
    do {
        continuar = menu();
    } while(continuar != 0);
    
    return 0;
}
