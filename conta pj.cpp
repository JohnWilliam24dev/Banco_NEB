#include "Database.c"
#include <string.h>

void conta(char cnpj[16]);

void transferir(char cnpj[16]){
	char tipo[4], cnpj_destino[16];
	float quantia;
	char *saldo_c = request_PJ(cnpj, 7);
	int opt;
	float saldo;
	saldo = atof(saldo_c);
	
	do{	 
	system("cls");
		printf("\t\t\tBancoNeb\n");
		printf("\t{Bem vindo à area de tranferencias }\n\n" );
		printf("\t\t\tV Dados do destinatario V\n\n");
		printf("Cnpj da conta : ");
		scanf("%s", cnpj_destino);
		printf("Quantia a ser enviada");
		scanf("%f", &quantia);
		printf("Tipo da conta PJ/PF");
		scanf("%s", tipo);
		
		if(saldo < quantia){
			printf("Valor invalido\nTente Novamente\n");
		}
		printf("Deseja Sair 1\n Tentar Novamente outro");
		scanf("%d", &opt);
		if(opt==1){
		
			conta(cnpj);
	}
	} while(saldo < quantia);
	
	printf("Transferencia concluida\n");
	conta(cnpj);
}
           
void conta(char cnpj[16]){
	char *saldo_c = request_PJ(cnpj,7);
	char *nome = request_PJ(cnpj,0);
	int opt;
	float saldo;
	saldo = atof(saldo_c);
	printf("debug %f ",saldo);
	system("cls");
	
	printf("\t\t\tBancoNeb\n");
	printf("\t{Bem vindo %s }\n\n" ,nome);
	printf("\t\t\t\SALDO : %f \n\n", saldo);
	printf("--|PIX|------|TRANSFERENCIAS|-----|EXTRATO|\n");
	printf("  | 1 |______|      2       |_____|   3   |\n");
	
	scanf("%d", &opt);
	switch(opt){
		case 1:
			transferir(cnpj);
			break;
		case 2:
			transferir(cnpj);
			break;
		case 3:
			//fun�ao extrato
			break;
		default:
			printf("Opção invalida");
			break;
	}
}

void pausarExecucao() {
	printf("pressione <ENTER> para continuar");
	getchar();
	fflush(stdin);
	system("cls");
}

void cadastro1() {
    char CNPJ[15];
    char nomeEmpresa[19];
    char idadeEmpresa[5];
    char senha[20]; 
    char pin[5];
    char telefone[10]; 
    char CEP[9];
    float saldo = 0;
    float credito = 0;
 
    printf("\nPor favor, digite o nome da empresa: ");
    gets(nomeEmpresa);

    
    do {
        printf("\nPor favor, digite o CNPJ (14 dÃ­gitos): ");
        scanf("%s", CNPJ);
        gets(CNPJ);

        if (strlen(CNPJ) == 14) {
            printf("CNPJ vÃ¡lido.\n");
            pausarExecucao();
            break;
        } else {
            printf("CNPJ invÃ¡lido. Por favor, digite novamente.\n");
            pausarExecucao();
        }
    } while (1);

    printf("\nPor favor, digite a idade da empresa: ");
    gets(idadeEmpresa);


    do {
        printf("\nPor favor, digite o telefone (8 dÃ­gitos): ");
        gets(telefone);

        if (strlen(telefone) == 8) {
            printf("Telefone vÃ¡lido.\n");
            pausarExecucao();
            break;
        } else {
            printf("Telefone invÃ¡lido. Por favor, digite novamente.\n");
            pausarExecucao();
        }
    } while (1);

    
    do {
        printf("\nPor favor, crie uma senha (mÃ­nimo 8 caracteres): ");
        gets(senha);
        if (strlen(senha) >= 8) {  
            printf("Senha validada!!\n");
            pausarExecucao();
            break;
        } else {
            printf("Senha invÃ¡lida. Digite novamente.\n");
            pausarExecucao();
        }
    } while (1);
    do {
        printf("\nPor favor, coloquei o pin : ");
        gets(pin);
        if (strlen(pin) == 4) {  
            printf("pin validado!!\n");
            pausarExecucao();
            break;
        } else {
            printf("Pin invÃ¡lido. Digite novamente.\n");
            pausarExecucao();
        }
    } while (1);
    do {
        printf("\nPor favor, coloque o cep: ");
        gets(CEP);
        if (strlen(CEP) == 8) {  
            printf("Cep validada!!\n");
            pausarExecucao();
            break;
        } else {
            printf("Cep invÃ¡lida. Digite novamente.\n");
            pausarExecucao();
        }
    } while (1);

    system("cls");
	
	printf("Cadastro finalizado");
	pausarExecucao();
	
	   
    system("cls");
    printf("\nO seu saldo Ã©: %.2f\n", saldo);
    printf("O seu crÃ©dito Ã©: %.2f\n", credito);  
    pausarExecucao();
	
	insert_client_legal_entire(nomeEmpresa, senha, pin, idadeEmpresa, CNPJ, telefone, CEP, saldo, credito); 
}

void entrar(){
   char cnpj[15], senha[20],*senha_c, senha_tt, aa[20];

   
   
	do{
		printf("Coloque seu CNPJ abaixo !\n");
		scanf("%s", cnpj);
		
		senha_c = request_PJ(cnpj, 1);
		printf("  %s",senha_c);
		
		fflush(stdin);
		printf("\nDigite a senha !\n");
		scanf("%s", senha);
		fflush(stdin);
		aa= strcmp(senha,senha_c);
		printf("%s",aa);
		
		if(strcmp(senha,senha_c) != 0) {
			printf("senha incorreta !\n\n");
		}
 }while(strcmp(senha,senha_c) != 0);
	
	conta(cnpj);
	
	
	
	
	
	
	
	
	
}

/*strlen(cnpj) !=14 and

void inicio(){
	int opt;
	
	printf("\t\t\t MMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("\t\t\t{  Bem vindo ao BancoNeb }\n");
	printf("\t\t\t WWWWWWWWWWWWWWWWWWWWWWWW\n\n");
	
	printf("\t\t\t\t  Deseja! \n\n\t\t\t\tCriar Conta 1 \n\t\t\tEntrar em conta existente 2\n");
	scanf("%d", &opt);
	
	switch (opt){
		case 1:
			cadastro1();
			break;
		case 2:
			entrar();
			break;
		case 3:
			printf("saindo");
			abort();
		default:
			printf("Opção invalida");
			break;
	}
}*/





int main (){
	int opt;
	
	printf("\t\t\t MMMMMMMMMMMMMMMMMMMMMMMM\n");
	printf("\t\t\t{  Bem vindo ao BancoNeb }\n");
	printf("\t\t\t WWWWWWWWWWWWWWWWWWWWWWWW\n\n");
	
	printf("\t\t\t\t  Deseja! \n\n\t\t\t\tCriar Conta 1 \n\t\t\tEntrar em conta existente 2\n");
	scanf("%d", &opt);
	
	switch (opt){
		case 1:
			cadastro1();
			break;
		case 2:
			entrar();
			break;
		case 3:
			printf("saindo");
			abort();
		default:
			printf("Opção invalida");
			break;
	}

}
