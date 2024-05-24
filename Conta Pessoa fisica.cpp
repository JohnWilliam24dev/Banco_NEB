#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <sys/stat.h>
#include <string.h>

typedef struct {
    char nome[50];
    char senha[8];
    int pin=0;
    char cpf[13];
    float credito=0;
    char telefone[13];
    char endereco[50];
    float saldo=0;
    char data_de_nascimento[10];
    char profissao[50];
} Cliente;



void cadastraCliente(){
    Cliente cliente;
    
    setlocale(LC_ALL, "Portuguese");
    
    wprintf(L"Vamos começar com seu CPF.\n");
    scanf("%s", cliente.cpf);
    
    //Fazer uma forma de contar a quantidade de caracteres do cpf
    
    system("cls");
    
    
    wprintf(L"Nós fale um pouco sobre você!\n\n");
    
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
    wprintf(L"Por favor, crie uma senha com 8 caracteres que contenham numeros, letras e caracteres.\n");
    scanf("%s", cliente.senha);
    
    
    system("cls");
    // criar uma verificação para descobri se a senha tem caracteres, numeros e caracteres especias.
    //insert_client_natural_person();
    
}

int menu(){
    int opcaoInicial;

    setlocale(LC_ALL, "Portuguese");
    wprintf(L"Bem vindo ao Banco Neb!\n");
    wprintf(L"1. Acessar sua conta\n");
    wprintf(L"2. Quero ser cliente\n");
    wprintf(L"3. Sair do aplicativo\n");
    
    scanf("%d", &opcaoInicial);
    fflush(stdin);
    
    system("cls");
    
    switch(opcaoInicial){
        case 1:
            //entradaCliente        
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

int main(){
    int continuar;
    
    do{
        continuar=menu();
    }while(continuar!=0);
    
    return 0;
}
