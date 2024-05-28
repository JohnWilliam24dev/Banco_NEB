#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

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

bool verificarSenha(char *senha) {
    int cont = 0;
    int temMinuscula = 0, temMaiuscula = 0, temNumero = 0;
    // Verifica se a senha possui pelo menos 8 caracteres
    if (strlen(senha) < 8 || strlen(senha) > 8){
        printf("Formato incorreto! Por favor, tente novamente.\n");
        getchar();
        system("cls");
        return 0;
    }

    for(cont=0;cont<9;cont++){
        if (islower(senha[cont])){
            temMinuscula = 1;
        }else if (isupper(senha[cont])){
            temMaiuscula = 1;
        }else if (isdigit(senha[cont])){
            temNumero = 1;
            return 1;
        }
    }
    return 0;
}

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

    system("cls");

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
    fflush(stdin);

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
            wprintf(L"Obrigado por usar os serviços do Banco NEB!\n");
            exit(0);
            break;
        default:
            wprintf(L"Opção incorreta, por favor tente novamente!\n");
            break;
    }
}

//Adicionar um verificador de telefone, só levantando em conta o numero internacional o 55, o ddd tem muito, eu acho que não precisa
/*bool vericNumeroTelefone(const char *telefone){
    if(strlen(telefone)!=13){
            printf("Numero incorreto, lembre-se que o numero 9 foi adicionado na frente dos numeros depois do DDD");
            fflush(stdin);
            getchar();
            system("cls");
         }else{
             if (isdigit(telefone[0]) && 
                isdigit(telefone[1]) && 
                isdigit(telefone[3]) && 
                isdigit(telefone[4]) &&
                isdigit(telefone[6]) && 
                isdigit(telefone[7]) &&
                isdigit(telefone[8]) && 
                isdigit(telefone[9]) && 
                isdigit(telefone[10]) && 
                isdigit(telefone[11]) && 
                isdigit(telefone[12]) && 
                isdigit(telefone[13])) {          
         }
}*/

bool vericData(const char *data) {
    
    if (isdigit(data[0]) && 
        isdigit(data[1]) && 
        data[2] == '/'   && 
        isdigit(data[3]) && 
        isdigit(data[4]) &&
        data[5] == '/'   && 
        isdigit(data[6]) && 
        isdigit(data[7]) &&
        isdigit(data[8]) && 
        isdigit(data[9])) {
            
        int ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + (data[9] - '0');
        int mes = (data[3] - '0') * 10 + (data[4] - '0');
        int dia = (data[0] - '0') * 10 + (data[1] - '0');

        if (ano >= 1920 && ano <= 2008) {
            if (mes >= 1 && mes <= 12) {
                if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia >= 1 && dia <= 30) {
                    getchar();
                    return true;
                } else if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia >= 1 && dia <= 31) {
                    getchar();
                    return true;
                } else if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) && dia >= 1 && dia <= 29) {
                    getchar();
                    return true;
                } else if (mes == 2 && dia >= 1 && dia <= 28) {
                    getchar();
                    return true;
                }
            }
        }
    }
    return false;
}
// Função para cadastrar cliente
void cadastraCliente() {
    Cliente cliente;
    
    setlocale(LC_ALL, "Portuguese");
    
    do{
    wprintf(L"Vamos começar com seu CPF.\n");
    scanf("%s", cliente.cpf);
    fflush(stdin);
    system("cls");
    
        if(strlen(cliente.cpf)!=12){
            printf("CPF incorreto, por favor digite novamente!");
            fflush(stdin);
            getchar();
            system("cls");
      
         }

        system("cls");

    }while(strlen(cliente.cpf)!=12);
 
    system("cls");
    
    wprintf(L"Nos fale um pouco sobre você!\n\n");
    
    wprintf(L"Qual o seu nome?\n");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    fflush(stdin);
    

    do{
        wprintf(L"Qual é a sua data de nascimento?\n");// Fazer uma verificação para a data
        scanf("%10s", cliente.data_de_nascimento);
        fflush(stdin);
        system("cls");

            if(!vericData(cliente.data_de_nascimento)){
                printf("Formato de data errado, por favor coloque uma data valida seguindo esse modelo 01/12/2024");
                getchar();
            }
    }while(!vericData(cliente.data_de_nascimento));
    
    wprintf(L"Qual é a sua profissão?\n");
    scanf("%49s", cliente.profissao);
    fflush(stdin);
    
    system("cls");
    
    wprintf(L"Qual é seu telefone?\n");//Fazer uma verificação para o telefone
    scanf("%12s", cliente.telefone);
    fflush(stdin);

    //vericNumeroTelefone(cliente.telefone); Função para verificar se o telefone é valido
    
    wprintf(L"Qual é o seu endereço?\n");
    scanf("%49s", cliente.endereco);
    fflush(stdin);
    
    system("cls");
    

    do{
    wprintf(L"Agora vamos criar a sua senha!\n");
    wprintf(L"Por favor, crie uma senha com 8 caracteres que contenham números, letras e caracteres.\n");
    scanf("%8s", cliente.senha);
    fflush(stdin);

    }while(!verificarSenha(cliente.senha));


    
    system("cls");

    wprintf(L"Conta criada com sucesso! Bem vindo a familia NEB!");
    wprintf(L"Agora você já pode acessar a sua conta através do login!");
    getchar();

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
            wprintf(L"Obrigado por usar os serviços do Banco NEB!\n");
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
