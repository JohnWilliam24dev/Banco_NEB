#include "Database.h"
#include <string.h>
#include <locale.h>

void conta(char cnpj[16]), menu();

void transferir_pf(char cnpj[16]){
	char tipo[4], cpf_destino[16],destino_saldo_c[20], *p_destino_saldo_c, opt, *verifica_cpf, *p_saldo_c = request_PJ(cnpj, 7), saldo_c[20], senha[20], *senha_c;
	float quantia, saldo, destino_saldo;
	
	saldo = atof(p_saldo_c);
	
	do{	 
	system("cls");
		printf("\t\t\tBancoNeb\n");
		printf("\t{Bem vindo à area de tranferencias }\n\n" );
		printf("\t\t\tV Dados do destinatario V\n\n");
		

		
		fflush(stdin);
		printf("CPF da conta : ");
		scanf("%s", cpf_destino);
		
		verifica_cpf = request_PF(cpf_destino, 4);
		
		fflush(stdin);
		printf("Quantia a ser enviada: ");
		scanf("%f", &quantia);
		
		fflush(stdin);
		printf("Digite sua senha: ");
		scanf("%s", senha);
		
		senha_c = request_PJ(cnpj, 1);
		
		if(strcmp(senha,senha_c) != 0) {
			printf("senha incorreta !\n\n");
		}
		
		if(saldo < quantia){
			printf("Valor invalido\nTente Novamente\n");
		}
		if(strcmp(cpf_destino,verifica_cpf ) !=0){
			printf("CPF do destinatário inválido\n\n");
		}
		
	fflush(stdin);
	printf("Deseja continuar ? S/N\n ");
	scanf("%c", &opt);
	
	if(opt=='N' or opt == 'n'){
			conta(cnpj);
			fflush(stdin);
	}
		
	fflush(stdin);
	} while(saldo < quantia and strcmp(cpf_destino,verifica_cpf ) !=0 and strcmp(senha,senha_c) != 0);
	
	if(opt=='s' or opt == 'S'){
	
		fflush(stdin);
	
		saldo = saldo - quantia;
		sprintf(saldo_c,"%.2f",saldo);
		edit_PJ(cnpj,7 ,saldo_c);
	
	
		p_destino_saldo_c = request_PJ(cpf_destino, 7);
		destino_saldo = atof(p_destino_saldo_c);
		destino_saldo = destino_saldo + quantia;
	
		sprintf(destino_saldo_c, "%.2f", destino_saldo);
		edit_PJ(cpf_destino,7 ,destino_saldo_c );
	
		printf("Transferencia concluida\n");
		system("pause");
		conta(cnpj);
	}
}


void transferir_pj(char cnpj[16]){
	char tipo[4], cnpj_destino[16],destino_saldo_c[20], *p_destino_saldo_c, opt, *verifica_cnpj, *p_saldo_c = request_PJ(cnpj, 7), saldo_c[20], senha[20], *senha_c;
	float quantia, saldo, destino_saldo;
	
	saldo = atof(p_saldo_c);
	
	do{	 
	system("cls");
		printf("\t\t\tBancoNeb\n");
		printf("\t{Bem vindo à area de tranferencias }\n\n" );
		printf("\t\t\tV Dados do destinatario V\n\n");
		

		
		fflush(stdin);
		printf("Cnpj da conta : ");
		scanf("%s", cnpj_destino);
		
		verifica_cnpj = request_PJ(cnpj_destino, 4);
		
		fflush(stdin);
		printf("Quantia a ser enviada: ");
		scanf("%f", &quantia);

		fflush(stdin);
		printf("Digite sua senha: ");
		scanf("%s", senha);
		
		senha_c = request_PJ(cnpj, 1);
		
		if(strcmp(senha,senha_c) !=0) {
			printf("senha incorreta !\n\n");
		}
		
		if(saldo < quantia){
			printf("Valor invalido\nTente Novamente\n");
		}
		if(strcmp(cnpj_destino,verifica_cnpj ) !=0){
			printf("CNPJ do destinatário inválido\n\n");
		}
		
		fflush(stdin);
		printf("Deseja continuar ? S/N\n ");
		scanf("%c", &opt);
		
		if(opt=='N' or opt == 'n'){
			conta(cnpj);
			fflush(stdin);
	}
	} while(saldo < quantia and strcmp(cnpj_destino,verifica_cnpj ) !=0 and strcmp(senha,senha_c) != 0);
	
	if(opt=='s' or opt == 'S'){
	fflush(stdin);
	
	saldo = saldo - quantia;
	sprintf(saldo_c,"%.2f",saldo);
	edit_PJ(cnpj,7 ,saldo_c);
	
	
	p_destino_saldo_c = request_PJ(cnpj_destino, 7);
	destino_saldo = atof(p_destino_saldo_c);
	destino_saldo = destino_saldo + quantia;
	
	sprintf(destino_saldo_c, "%.2f", destino_saldo);
	edit_PJ(cnpj_destino,7 ,destino_saldo_c );
	
	printf("Transferencia concluida\n");
	system("pause");
	conta(cnpj);
	}
}

           
void conta(char cnpj[16]){
	char *saldo_c = request_PJ(cnpj,7);
	char *nome = request_PJ(cnpj,0);
	int opt;
	float saldo;
	saldo = atof(saldo_c);
	printf("debug %f ",saldo);
	system("cls");
	do{
	
		printf("\t\t\tBancoNeb\n");
		printf("\t{Bem vindo %s }\n\n" ,nome);
		printf("\t\tSALDO : %.2f \n\n", saldo);
		printf("--||TRANSFERENCIA PF|------|TRANSFERENCIA PJ|-----|EXTRATO|-----|SAIR|\n");
		printf("  |        1        |______|       2        |_____|   3   |_____| 4  |\n");
	
		scanf("%d", &opt);
		switch(opt){
			case 1:
				transferir_pf(cnpj);
				system("cls");
				break;
			case 2:
				transferir_pj(cnpj);
				system("cls");
				break;
			case 3:
				//funçao extrato
				system("cls");
				break;
			case 4:
				printf("Saindo...");
				system("pause");
				system("cls");
				break;
			default:
				printf("Opção invalida\n");
				system("pause");
				system("cls");
				break;
		}
	}while(opt > 4);
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
 	fflush(stdin);
    printf("\nPor favor, digite o nome da empresa: ");
    gets(nomeEmpresa);

    
    do {
        printf("\nPor favor, digite o CNPJ (14 digitos): ");
        scanf("%s", CNPJ);

        if (strlen(CNPJ) == 14) {
            printf("CNPJ valido.\n");
            pausarExecucao();
            break;
        } else {
            printf("CNPJ invalido. Por favor, digite novamente.\n");
            pausarExecucao();
        }
    } while (1);

    printf("\nPor favor, digite a idade da empresa: ");
    gets(idadeEmpresa);


    do {
        printf("\nPor favor, digite o telefone (8 digitos): ");
        gets(telefone);

        if (strlen(telefone) == 8) {
            printf("Telefone valido.\n");
            pausarExecucao();
            break;
        } else {
            printf("Telefone invalido. Por favor, digite novamente.\n");
            pausarExecucao();
        }
    } while (1);

    
    do {
        printf("\nPor favor, crie uma senha (minimo 8 caracteres): ");
        gets(senha);
        if (strlen(senha) >= 8) {  
            printf("Senha validada!!\n");
            pausarExecucao();
            break;
        } else {
            printf("Senha invalida. Digite novamente.\n");
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
            printf("Pin invalido. Digite novamente.\n");
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
            printf("Cep invalida. Digite novamente.\n");
            pausarExecucao();
        }
    } while (1);

    system("cls");
	
	printf("Cadastro finalizado");
	pausarExecucao();
	
	   
    system("cls");
    printf("\nO seu saldo e: %.2f\n", saldo);  
    pausarExecucao();
	
	insert_client_legal_entire(nomeEmpresa, senha, pin, idadeEmpresa, CNPJ, telefone, CEP, saldo, credito); 
}

void entrar(){
   char cnpj[15], senha[20],*senha_c, senha_tt, opt = 'n';

   
   
	do{
		system("cls");
		printf("\t\t\t MMMMMMMMMMMMMMMMMMMMMMMM\n");
		printf("\t\t\t{  Bem vindo ao BancoNeb }\n");
		printf("\t\t\t WWWWWWWWWWWWWWWWWWWWWWWW\n\n");
	
		printf("Coloque seu CNPJ abaixo !\n");
		scanf("%s", cnpj);
		
		senha_c = request_PJ(cnpj, 1);
		
		fflush(stdin);
		printf("\nDigite a senha !\n");
		scanf("%s", senha);
		fflush(stdin);
		
		
		
		if(strcmp(senha,senha_c) != 0) {
			printf("senha incorreta !\n\n");
		}
		
		printf("Deseja sair ? S/N \n");
		scanf("%c", &opt);
		
		if(opt == 'S' or opt == 's'){
			system("pause");
			system("cls");
			menu();
		}
		
 }while(strcmp(senha,senha_c) != 0);
	
	conta(cnpj);	
}

void menu(){
	int opt;
	
	do{
	
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
				printf("Opção invalida\n\n");
				system("pause");
				system("cls");
				break;
		}
	}while(opt!=1 or opt!=2 or opt!=3);
}

int main (){
	int opt;
	setlocale(LC_ALL, "Portuguese");
	menu();

}
