#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_client_legal_entire(char nome[],char data_de_nascimento[],char CNPJ[],float saldo,float credito){


    
    
    
    char path[100]="./PJ/userPJ";
    strcat(path,CNPJ);
    char ext[15]={".txt"};
    strcat(path,ext);
    FILE *file;
    file=fopen(path,"a");
    
    fprintf(file,"nome=%s\n",nome);
    fprintf(file,"CNPJ=%s\n",CNPJ);
    fprintf(file,"credito=%f\n",credito);
    fprintf(file,"saldo=%f\n",saldo);
    fprintf(file,"data=%s\n",data_de_nascimento);

}

int main(){
    insert_client_legal_entire("João","01/02/1990","39278382000155",11234,30000);
    insert_client_legal_entire("Pedro","30/03/2004","46792439000103",11234,30000);
    insert_client_legal_entire("Daniel","11/11/2001","38646218000190",11234,30000);
    insert_client_legal_entire("Sayd","01/02/1990","20373525000180",11234,30000);
    insert_client_legal_entire("Matheus","01/02/1990","63167366000170",11234,30000);
    insert_client_legal_entire("Matheus","01/02/1990","23186418000130",11234,30000);
}