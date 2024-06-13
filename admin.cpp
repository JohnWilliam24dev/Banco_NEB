#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "Database.h"

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
	    scanf("%i",option);
	    fflush(stdin);
	    listclientPF();
    
    


}