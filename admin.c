#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

    system("clear");
    printf("\tDashboard:\n");
    printf("\t(1)Listar clientes PF\n");
    printf("\t(2)Listar clientes PJ\n");
    printf("\t(3)Modificar informações de cliente\n");
    printf("\t(4)Negociações de alto valor\n");
    printf("\t(5)Mudança de regras de negocio\n");
    


}