#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <sys/stat.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "transferenciaBancaria.cpp"
#include "FAQ.c"

// DefiniÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â§ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â£o da estrutura Cliente
typedef struct {
	
    char nome[50];
    char senha[9];
    char pin [5];
    char cpf[13];
    float credito;
    char telefone[14];
    char endereco[50];
    float saldo;
    char data_de_nascimento[11];
    char profissao[50];
} Cliente;



int verificaCPF(char * CPF) {
	char cpfBuscado[13];
	char *ptr = CPF;
	int i = 0;
	while(*ptr !='\0')
	{
		cpfBuscado[i] = *ptr;
		ptr++;
		i++;
	}
	
	char path[100] = "./PF/userPF";
	strcat(path, cpfBuscado);
	char ext[15] = {".txt"};
	strcat(path, ext);
	FILE *arquivo;
	arquivo = fopen(path, "r");
	if(arquivo == NULL)
	{
		return 0;
	}
	fclose(arquivo);

	return 1; // SE (verificaCPF) = 1, entÃƒÂ£o o arquivo PATH "CPF" existe no banco de dados.
}

void vericSaldo(const char *usuarioCpf){
	float saldoAtual;
	
	system("cls");
	
	saldoAtual=atoi(request_PF(usuarioCpf,7));
	
	wprintf(L"O seu saldo atual e de %.2f R$", saldoAtual);
	getchar();
	
}

void deposito(const char *usuarioCpf){
	float adicionarSaldo;
	double atualSaldo_double;
	float atualSaldo;
	char atualSaldo_string[20];
	char valor_movimentado[20];
	
	system("cls");
	
	wprintf(L"Quanto voce deseja adicionar? \n");
	scanf("%f", &adicionarSaldo);
	getchar();
	
	atualSaldo_double = atof(request_PF(usuarioCpf,7));
	atualSaldo = (float) atualSaldo_double;
	
	atualSaldo += adicionarSaldo;
	
	sprintf(atualSaldo_string, "%.2f", atualSaldo);
	sprintf(valor_movimentado, "%.2f", adicionarSaldo);
	
	edit_PF(&usuarioCpf[0], 7, &atualSaldo_string[0]);
	insert_extract_PF(&usuarioCpf[0], &usuarioCpf[0], &valor_movimentado[0], &atualSaldo_string[0]);
	
	wprintf("Seu saldo atual e de %f R$", atualSaldo);
	pausarExecucao();
	
}

void entradaCliente() {
    char usuarioCpf[12];
    char usuarioSenha[20];
    int opcaoCliente;

    printf("Por favor insira seu CPF: \n");
    scanf("%12s",usuarioCpf);
    fflush(stdin);

    if(verificaCPF(&usuarioCpf[0]))
    {
    
	do{
    	printf("Senha: \n");
    	scanf("%20s", usuarioSenha);
    	fflush(stdin);
    	
		system("cls");
    
    	if (strcmp(request_PF(usuarioCpf,1),usuarioSenha) != 0) {
                printf("Senha incorreta! Por favor tente novamente.\n\n");
                return 0;
            }
    } while (strcmp(request_PF(usuarioCpf, 1),usuarioSenha) != 0);
    	
	fflush(stdin);

    system("cls");
    // Procurar no banco de dados se a senha ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â© compatÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â­vel com o CPF, caso erre 3 vezes a conta ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â© bloqueada

    // Caso o CPF e a senha estejam corretos, mostrar o menu do cliente
    //fazer um DO WHILE para volta para o menu de conta
	}
	else 
	{
		printf("CPF NÃƒÆ’O CONSTA COMO USUARIO!\n");
		pausarExecucao();
		return 0; //encerra execuÃƒÂ§ÃƒÂ£o voltando pro menu inicial;
	}
	DASHBOARD:
		
	do{
	
    	wprintf(L"Bem-vindo(a)! Como podemos ajudar-lo?\n");
    	wprintf(L"1. Verificar saldo\n");
    	wprintf(L"2. Transferencia\n");
    	wprintf(L"3. Verificar extrato\n");
    	wprintf(L"4. Fazer um deposito\n");
    	wprintf(L"5. Alterar informacoes pessoais\n");
    	wprintf(L"6. Finalizar sessao\n");
    	scanf("%d", &opcaoCliente);
    	fflush(stdin);
    
    	switch (opcaoCliente) {
        	case 1:
            	vericSaldo(usuarioCpf); 
            	system("cls");
            	goto DASHBOARD;
            	break;
        	case 2:
        		system("cls");
            	transferencia(&usuarioCpf[0]);
            	system("cls");
            	goto DASHBOARD;
            	break;
       	 	case 3:
            	system("cls");
            	printExtrato_PF(&usuarioCpf[0]);
            	system("cls");
            	goto DASHBOARD;
            	break;
        	case 4:
            	deposito(usuarioCpf);
            	system("cls");
            	goto DASHBOARD;
            	break;
        	case 5:
            	editinfo_clientPF(usuarioCpf);
            	system("cls");
            	goto DASHBOARD;
            	break;
        	case 6:
            	wprintf(L"Obrigado por usar os servicos do Banco NEB!\n");
            	exit(0);
            	break;
        	default:
            	wprintf(L"Opcao incorreta, por favor tente novamente!\n");
            	system("pause");
            	system("cls");
            	break;

        }
    }while(opcaoCliente!=6);
}



bool vericPin(const char *pin) {
    if (strlen(pin) != 4) {
        printf("O PIN deve ter 4 dígitos. Por favor, tente novamente.\n");
        return false;
    }
    for (int i = 0; i < 4; i++) {
        if (!isdigit(pin[i])) {
            printf("PIN inválido, deve conter apenas dígitos\n");
            return false;
        }
    }
    return true;
}

bool verificarSenha(const char *senha) {
    bool temMinuscula = false, temMaiuscula = false, temNumero = false;

    if (strlen(senha) < 8) {
        printf("A senha deve ter pelo menos 8 caracteres. Por favor, tente novamente.\n");
        return false;
    }

    for (int cont = 0; cont < strlen(senha); cont++) {
        if (islower(senha[cont])) temMinuscula = true;
        if (isupper(senha[cont])) temMaiuscula = true;
        if (isdigit(senha[cont])) temNumero = true;
    }

    if (temMinuscula && temMaiuscula && temNumero) {
        return true;
    } else {
        printf("A senha deve conter pelo menos uma letra minúscula, uma letra maiúscula e um número.\n");
        getchar();
        return false;
    }
}

bool verifNumeroTelefone(const char *telefone) {
    if (strlen(telefone) != 13) {
        printf("Numero incorreto, lembre-se que o numero 9 foi adicionado na frente dos numeros depois do DDD\n");
        fflush(stdin);
        getchar();
        system("cls");
        return false;
    }

    for (int i = 0; i < 13; i++) {
        if (!isdigit(telefone[i])) {
            printf("Numero de telefone invalido, deve conter apenas digitos\n");
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
        printf("Lembre-se de adicionar o 9 antes do seu numero, por favor tente novamente\n");
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
        wprintf(L"Vamos comecar com seu CPF.\n");
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

    wprintf(L"Nos fale um pouco sobre voce!\n\n");

    wprintf(L"Qual o seu nome?\n");
    fgets(cliente.nome, sizeof(cliente.nome), stdin);
    fflush(stdin);

    do {
        wprintf(L"Qual a sua data de nascimento?\n");
        scanf("%10s", cliente.data_de_nascimento);
        fflush(stdin);
        system("cls");

        if (!verifData(cliente.data_de_nascimento)) {
            printf("Formato de data errado, por favor coloque uma data valida seguindo esse modelo 01/12/2024\n");
            getchar();
        }
    } while (!verifData(cliente.data_de_nascimento));

    wprintf(L"Qual a sua profissao?\n");
    scanf("%49s", cliente.profissao);
    fflush(stdin);

    system("cls");

    do {
        wprintf(L"Qual e seu telefone?\n");
        scanf("%13s", cliente.telefone);
        fflush(stdin);
        system("cls");
    } while (!verifNumeroTelefone(cliente.telefone));

    wprintf(L"Qual e o seu endereco?\n");
    scanf("%49s", cliente.endereco);
    fflush(stdin);

    system("cls");

    do {
        wprintf(L"Agora vamos criar a sua senha!\n");
        wprintf(L"Por favor, crie uma senha com no minimo 8 caracteres que contenham numeros, letras e caracteres.\n");
        scanf("%20s", cliente.senha);
        fflush(stdin);
        system("cls");
    } while (!verificarSenha(cliente.senha));

    system("cls");
    
    do{
    wprintf(L"Estamos quase acabando! Por favor crie o seu PIN.\n O seu PIN é utilizado para acessar algumas funções de sua conta.");
    wprintf(L"O seu PIN é utilizado para acessar algumas funções de sua conta\n");
    wprintf(L"O seu PIN deve conter 4 digitos\n");

    scanf("%4s", cliente.pin);
    fflush(stdin);
    system("cls");
	}while(!vericPin(cliente.pin));
    
    

    wprintf(L"Conta criada com sucesso! Bem-vindo a familia NEB!\n");
    wprintf(L"Agora voce ja pode acessar a sua conta atraves do login!\n");
    getchar();
    system("cls");

    cliente.saldo=0;
    cliente.credito=0;

    insert_client_legal_entire(cliente.nome,cliente.senha,cliente.pin,cliente.data_de_nascimento,cliente.cpf,cliente.telefone,cliente.endereco,cliente.saldo,cliente.credito);
}

void recupSenha() {
    char usuarioCpf[12];
    char vericPin[5];
    char vericData[11];
    char novaSenha[21], vericNovaSenha[21];

    printf("Por favor, informe seu CPF: ");
    scanf("%12s", usuarioCpf);
    fflush(stdin);
    
    system("cls");

    if (verificaCPF(&usuarioCpf[0])) {
        do {
            printf("Agora vamos fazer algumas perguntas de segurança:\n");
            printf("Qual a sua data de nascimento? (Use o seguinte formato: 01/12/2001): ");
            scanf("%10s", vericData);
            fflush(stdin);
            system("cls");

            if (strcmp(request_PF(usuarioCpf,3),vericData) != 0) {
                printf("Data de nascimento incorreta! Por favor tente novamente.\n\n");
            }
        } while (strcmp(request_PF(usuarioCpf, 3),vericData) != 0);

        do {
            printf("Agora nos informe o seu atual PIN: ");
            scanf("%4s", vericPin);
            fflush(stdin);
            system("cls");

            if (strcmp(request_PF(usuarioCpf, 2), vericPin) != 0) {
                printf("PIN incorreto! Por favor tente novamente.\n");
            }
        } while (strcmp(request_PF(usuarioCpf, 2), vericPin) != 0);

        do {
            do {
            	
            	system("cls");
            	
                printf("As informacaes solicitadas estao todas corretas, agora por favor digite a sua nova senha:\n");
                printf("Lembre-se que a senha deve conter no minimo 8 digitos e deve possuir pelo menos uma letra minuscula, uma letra maiuscula e um numero: ");
                scanf("%20s", novaSenha);
                fflush(stdin);
                
                system("cls");
                
                if (!verificarSenha(novaSenha)){
                printf("Senha incorreta! Por favor tente novamente.\n");
            	}
                
            } while (!verificarSenha(novaSenha));
            
            system("cls");

            printf("Agora digite a sua nova senha novamente: ");
            scanf("%20s", vericNovaSenha);
            fflush(stdin);
				
            if (strcmp(novaSenha, vericNovaSenha) != 0) {
            	
				system("cls");
            	
                printf("As senhas não coincidem. Por favor tente novamente.\n\n");
            }
        } while (strcmp(novaSenha, vericNovaSenha) != 0);

        edit_PF(usuarioCpf, 1, novaSenha);
		
		system("cls");
		  
        printf("Senha alterada com sucesso!\n");
        getchar();
    } else {
        printf("CPF nao consta como usuário!\n");
    }
}

int menu() {
    int opcaoInicial;

    setlocale(LC_ALL, "Portuguese");
    wprintf(L"Bem-vindo ao Banco NEB!\n");
    wprintf(L"1. Acessar sua conta\n");
    wprintf(L"2. Quero ser cliente\n");
    wprintf(L"3. Suporte Banco NEB\n");
    wprintf(L"4. Recuperar a senha\n");
    wprintf(L"5. Sair do aplicativo\n");

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
			FAQPF();    
            break;
        case 4:
        	recupSenha();
        	break;
        case 5:
            wprintf(L"Obrigado por usar os servicos do Banco NEB!\n");
            exit(0);
            break;
        default:
        	
            wprintf(L"Opcao incorreta, por favor tente novamente!\n");
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
