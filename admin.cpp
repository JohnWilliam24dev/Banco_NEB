#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Database.h"
void editinfo(){
	system("cls");
	char cpf[15];
	char mod[200];
	int index;
	printf("Digite o CPF do cliente titular: ");
	scanf("%s",cpf);
		printf("0 %s\n",request_PF(cpf,0));
		printf("1 %s\n",request_PF(cpf,1));
		printf("2 %s\n",request_PF(cpf,2));
		printf("3 %s\n",request_PF(cpf,3));
		printf("4 %s\n",request_PF(cpf,4));
		printf("5 %s\n",request_PF(cpf,5));
		printf("6 %s\n",request_PF(cpf,6));
		printf("7 %s\n",request_PF(cpf,7));
		printf("8 %s\n\n",request_PF(cpf,8));
	printf("Digite o indice que deseja modificar: ");
	scanf("%i",&index);
	fflush(stdin);
	printf("Digite a modificação que deseja fazer: ");
	scanf("%s",mod);
	edit_PF(cpf,index,mod);
	printf("A alteração foi feita com sucesso!");
	system("pause");
	
}
int main(){
    char access_name[10];
    int tentativa=0;
    bool authenticator=false;
    printf("Bem vindo ao ADMIN interface:\n");
    INIT:printf("Digite seu codigo de acesso: ");
    scanf("%s",access_name);
    if(strcmp(access_name,"456890")==0){
        printf("Preparando dashboard...\n");
        authenticator=true;
    }
    else{
        tentativa++;
        authenticator=false;
        printf("Usuario não identificado> tente novamente\n");
        printf("%i",tentativa);
        if(tentativa==3){
            printf("Por motivos de seguranca o acesso sera bloqueado");
            exit(0);
        }else{
            goto INIT;
        }
        
    }
	MENU:
		int option=0;
	    system("cls");
	    printf("\tDashboard:\n");
	    printf("\t(1)Listar clientes PF\n");
	    printf("\t(2)Listar clientes PJ\n");
	    printf("\t(3)Modificar informações sensiveis de clientes\n");
	    printf("\t(4)Sair\n");
	    scanf("%i",&option);
	    //fflush(stdin);
	    switch (option){
	    	case 1:
	    		listclientPF();
	    		system("pause");
	    		system("cls");
	    		goto MENU;
	    		break;
	    	case 2:
	    		listclientPJ();
	    		system("pause");
	    		system("cls");
	    		goto MENU;
	    		break;
	    	case 3:
	    		editinfo();
	    		goto MENU;
	    		break;
	    	case 4:
	    	
	    	break;
	    	default:
	    		system("cls");
	    		printf("opcao invalida tente novamente");
	    		goto MENU;
	    		break;
	    	
		} 


}