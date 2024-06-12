#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "transferenciaBancaria_PF.cpp"

// DefiniÃ§Ã£o da estrutura Cliente
typedef struct {
    char nome[50];
    char senha[9];
    int pin;
    char cpf[13];
    float credito;
    char telefone[14];
    char endereco[50];
    float saldo;
    char data_de_nascimento[11];
    char profissao[50];
} Cliente;

bool vericSenha(const char *usuarioSenha, const char *usuarioCpf){
	if(request_PF(usuarioCpf,1)==usuarioSenha){
		return 1;
	}else{
	 return 0;
	}
}

/*void vericSaldo(const char *usuarioCpf){
	float saldoAtual;
	
	system("cls");
	
	saldoAtual=atoi(request_PF(usuarioCpf,7));
	
	wprintf(L"O seu saldo atual Ã© de %f R$", (usuarioCpf,7));
	wprintf(L"O seu saldo atual Ã© de %f R$", saldoAtual);
	getchar();
	
}*/

/*void deposito(const char *usuarioCpf){
	float adicionarSaldo,atualSaldo;
	
	system("cls");
	
	wprintf(L"Quanto vocÃª deseja adicionar? \n");
	scanf("%f", &adicionarSaldo);
	getchar();
	
	atualSaldo=atoi(request_PF(usuarioCpf,7));
	
	atualSaldo+=adicionarSaldo;
	
	wprintf("Seu saldo atual Ã© de %f R$", atualSaldo);
	
}*/

void entradaCliente() {
    char usuarioCpf[12];
    char usuarioSenha[9];
    int opcaoCliente;

    printf("Por favor insira seu CPF: \n");
    scanf("%12s",usuarioCpf);
    fflush(stdin);

    // Procurar no banco de dados se hÃ¡ um CPF compatÃ­vel, caso nÃ£o exista, mostrar uma mensagem e retornar
	
	do{
    printf("Senha: \n");
    scanf("%8s", usuarioSenha);
    vericSenha(usuarioSenha,usuarioCpf);
    fflush(stdin);

    system("cls");
    }while(!vericSenha);
    // Procurar no banco de dados se a senha Ã© compatÃ­vel com o CPF, caso erre 3 vezes a conta Ã© bloqueada

    // Caso o CPF e a senha estejam corretos, mostrar o menu do cliente
    //fazer um DO WHILE para volta para o menu de conta
    wprintf(L"Bem-vindo(a)! Como podemos ajudar-lo?\n");
    wprintf(L"1. Verificar saldo\n");
    wprintf(L"2. TransferÃªncia\n");
    wprintf(L"3. Verificar extrato\n");
    wprintf(L"4. Solicitar emprÃ©stimo\n");
    wprintf(L"5. Fazer um depÃ³sito\n");
    wprintf(L"6. Alterar informaÃ§Ãµes pessoais\n");
    wprintf(L"7. Finalizar sessÃ£o\n");
    scanf("%d", &opcaoCliente);
    fflush(stdin);

    switch (opcaoCliente) {
        case 1:
            //vericSaldo(usuarioCpf); NÃ£o estÃ¡ atualizando o saldo
            break;
        case 2:
            transferencia(&usuarioCpf[0]);
            break;
        case 3:
            // Verificar extrato
            break;
        case 4:
            // Solicitar emprÃ©stimo
            break;
        case 5:
            //deposito(usuarioCpf);NÃ£o estÃ¡ atualizando o saldo
            break;
        case 6:
            // Alterar informaÃ§Ãµes pessoais
            break;
        case 7:
            wprintf(L"Obrigado por usar os serviÃ§os do Banco NEB!\n");
            exit(0);
            break;
        default:
            wprintf(L"OpÃ§Ã£o incorreta, por favor tente novamente!\n");
            break;
    }
}


bool verificarSenha(const char *senha) {
    bool temMinuscula = false, temMaiuscula = false, temNumero = false;

    // Verifica se a senha possui pelo menos 8 caracteres
    if (strlen(senha) < 8) {
        printf("Formato incorreto! A senha deve ter pelo menos 8 caracteres. Por favor, tente novamente.\n");
        return false;
    }

    // Percorre os caracteres da senha
    for (int cont = 0; cont < strlen(senha); cont++) {
        if (islower(senha[cont])) temMinuscula = true;
        if (isupper(senha[cont])) temMaiuscula = true;
        if (isdigit(senha[cont])) temNumero = true;
    }

    // Verifica se possui pelo menos um de cada tipo de caractere
    if (temMinuscula && temMaiuscula && temNumero) {
        return true;
    } else {
        printf("A senha deve conter pelo menos uma letra minÃºscula, uma letra maiÃºscula e um nÃºmero.\n");
        getchar();
        system("cls");
        return false;
    }
}

bool verifNumeroTelefone(const char *telefone) {
    if (strlen(telefone) != 13) {
        printf("NÃºmero incorreto, lembre-se que o nÃºmero 9 foi adicionado na frente dos nÃºmeros depois do DDD\n");
        fflush(stdin);
        getchar();
        system("cls");
        return false;
    }

    for (int i = 0; i < 13; i++) {
        if (!isdigit(telefone[i])) {
            printf("NÃºmero de telefone invÃ¡lido, deve conter apenas dÃ­gitos\n");
            fflush(stdin);
            getchar();
            system("cls");
            return false;
        }
    }

    int ddd = (telefone[0] - '0') * 10 + (telefone[1] - '0');
    if (ddd != 55) {
        printf("DDD incorreto, por favor tente novamente.\n");
        getchar();
        system("cls");
        return false;
    }

    int nonoDigitoTelefone = telefone[4] - '0';
    if (nonoDigitoTelefone != 9) {
        printf("Lembre-se de adicionar o 9 antes do seu nÃºmero, por favor tente novamente\n");
        getchar();
        system("cls");
        return false;
    }

    return true;
}

bool verifData(const char *data) {
    if (strlen(data) != 10) return false;

    if (isdigit(data[0]) && isdigit(data[1]) && data[2] == '/' && 
        isdigit(data[3]) && isdigit(data[4]) && data[5] == '/' && 
        isdigit(data[6]) && isdigit(data[7]) && isdigit(data[8]) && isdigit(data[9])) {
        
        int dia = (data[0] - '0') * 10 + (data[1] - '0');
        int mes = (data[3] - '0') * 10 + (data[4] - '0');
        int ano = (data[6] - '0') * 1000 + (data[7] - '0') * 100 + (data[8] - '0') * 10 + (data[9] - '0');

        if (ano >= 1920 && ano <= 2008) {
            if (mes >= 1 && mes <= 12) {
                if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia >= 1 && dia <= 30) {
                    return true;
                } else if ((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) && dia >= 1 && dia <= 31) {
                    return true;
                } else if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || ano % 400 == 0) && dia >= 1 && dia <= 29) {
                    return true;
                } else if (mes == 2 && dia >= 1 && dia <= 28) {
                    return true;
                }
            }
        }
    }
    return false;
}

void cadastraCliente() {
    Cliente cliente;

    setlocale(LC_ALL, "Portuguese");

    do {
        wprintf(L"Vamos comeÃ§ar com seu CPF.\n");
        scanf("%12s", cliente.cpf);
        fflush(stdin);
        system("cls");

        if (strlen(cliente.cpf) != 11) {
            printf("CPF incorreto, por favor digite novamente!\n");
            fflush(stdin);
            getchar();
            system("cls");
        }

        system("cls");
    } while (strlen(cliente.cpf) != 11);

    system("cls");

    wprintf(L"Nos fale um pouco sobre vocÃª!\n\n");

    wprintf(L"Qual o seu nome?\n");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    fflush(stdin);

    do {
        wprintf(L"Qual Ã© a sua data de nascimento?\n");
        scanf("%10s", cliente.data_de_nascimento);
        fflush(stdin);
        system("cls");

        if (!verifData(cliente.data_de_nascimento)) {
            printf("Formato de data errado, por favor coloque uma data vÃ¡lida seguindo esse modelo 01/12/2024\n");
            getchar();
        }
    } while (!verifData(cliente.data_de_nascimento));

    wprintf(L"Qual Ã© a sua profissÃ£o?\n");
    scanf("%49s", cliente.profissao);
    fflush(stdin);

    system("cls");

    do {
        wprintf(L"Qual Ã© seu telefone?\n");
        scanf("%13s", cliente.telefone);
        fflush(stdin);
        system("cls");
    } while (!verifNumeroTelefone(cliente.telefone));

    wprintf(L"Qual Ã© o seu endereÃ§o?\n");
    scanf("%49s", cliente.endereco);
    fflush(stdin);

    system("cls");

    do {
        wprintf(L"Agora vamos criar a sua senha!\n");
        wprintf(L"Por favor, crie uma senha com 8 caracteres que contenham nÃºmeros, letras e caracteres.\n");
        scanf("%8s", cliente.senha);
        fflush(stdin);
        system("cls");
    } while (!verificarSenha(cliente.senha));

    system("cls");

    wprintf(L"Conta criada com sucesso! Bem-vindo Ã  famÃ­lia NEB!\n");
    wprintf(L"Agora vocÃª jÃ¡ pode acessar a sua conta atravÃ©s do login!\n");
    getchar();
    system("cls");

    cliente.pin=0; 
    cliente.saldo=0;
    cliente.credito=0;

    insert_client_legal_entire(cliente.nome,cliente.senha,cliente.pin,cliente.data_de_nascimento,cliente.cpf,cliente.telefone,cliente.endereco,cliente.saldo,cliente.credito);
}

int menu() {
    int opcaoInicial;

    setlocale(LC_ALL, "Portuguese");
    wprintf(L"Bem-vindo ao Banco NEB!\n");
    wprintf(L"1. Acessar sua conta\n");
    wprintf(L"2. Quero ser cliente\n");
    wprintf(L"3. Sair do aplicativo\n");

    scanf("%d", &opcaoInicial);
    fflush(stdin);

    system("cls");

    switch (opcaoInicial) {
        case 1:
            entradaCliente();
            break;
        case 2:
            cadastraCliente();
            break;
        case 3:
            wprintf(L"Obrigado por usar os serviÃ§os do Banco NEB!\n");
            exit(0);
            break;
        default:
            wprintf(L"OpÃ§Ã£o incorreta, por favor tente novamente!\n");
            break;
    }
    return 1;
}

int main() {
    int continuar;

    do {
        continuar = menu();
    } while (continuar != 0);

    return 0;
}
