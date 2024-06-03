#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>

void insert_client_legal_entire(char nome[],char senha[],int pin,char data_de_nascimento[],char CNPJ[],char telefone[],char endereco[],float saldo,float credito){


    
    
    int f=mkdir("./PJ",S_IRWXU);
    if (f==0){
        system("mkdir PJ");
        system("clear");
    }
    char path[100]="./PJ/userPJ";
    strcat(path,CNPJ);
    char ext[15]={".txt"};
    strcat(path,ext);
    FILE *file;
    file=fopen(path,"w");
    
    fprintf(file,"%s\n",nome);
    fprintf(file,"%s\n",senha);
    fprintf(file,"%d\n",pin);
    fprintf(file,"%s\n",data_de_nascimento);
    fprintf(file,"%s\n",CNPJ);
    fprintf(file,"%s\n",telefone);
    fprintf(file,"%s\n",endereco);
    fprintf(file,"%2.f\n",saldo);
    fprintf(file,"%2.f\n",credito);
    

}

void insert_client_natural_person(char nome[],char senha[],int pin,char data_de_nascimento[],char CPF[],char telefone[],char endereco[],float saldo,float credito){

int f=mkdir("./PF",S_IRWXU);
    if (f==0){
        system("mkdir PF");
        system("clear");
    }
    char path[100]="./PF/userPF";
    strcat(path,CPF);
    char ext[15]={".txt"};
    strcat(path,ext);
    FILE *file;
    file=fopen(path,"w");
    
    fprintf(file,"%s\n",nome);
    fprintf(file,"%s\n",senha);
    fprintf(file,"%d\n",pin);
    fprintf(file,"%s\n",data_de_nascimento);
    fprintf(file,"%s\n",CPF);
    fprintf(file,"%s\n",telefone);
    fprintf(file,"%s\n",endereco);
    fprintf(file,"%2.f\n",saldo);
    fprintf(file,"%2.f\n",credito);
    
}

char* request_PF(char CPF[],int option){
  
    char path[100]="./PF/userPF";
    strcat(path,CPF);
    char ext[15]={".txt"};
    strcat(path,ext);
    
    char *chPF = (char *) malloc(sizeof(char)*30);


    FILE *filePF;
    filePF =fopen(path,"r");
    int i=0;
    while (fgets(chPF,40,filePF)!=NULL)
    {
    	if(i == option) break;
        i++;
    }

    fclose(filePF);
    return chPF;
}

char* request_PJ(char CNPJ[],int option){
  
    char path[100]="./PJ/userPJ";
    strcat(path,CNPJ);
    char ext[15]={".txt"};
    strcat(path,ext);

    char *chPJ = (char *) malloc(sizeof(char)*30);


    FILE *filePJ;
    filePJ =fopen(path,"r");
    int i=0;
    while (fgets(chPJ,40,filePJ)!=NULL)
    {
    	if(i == option) break;
        i++;
    }
    
    fclose(filePJ);
    return chPJ;

}


int main(){
    insert_client_legal_entire("Felipe","annythn123",4567,"24/03/2005","8765431232321","73998824924","rua Baker numero 3",0,0);

    char *teste=request_PJ("8765431232321",0);
    printf("debug %s",*teste);
}
