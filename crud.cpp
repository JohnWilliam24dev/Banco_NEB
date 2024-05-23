#include <stdio.h>
#include <stdlib.h>
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
    
    fprintf(file,"nome=%s\n",nome);
    fprintf(file,"senha=%s\n",senha);
    fprintf(file,"pin=%d\n",pin);
    fprintf(file,"CNPJ=%s\n",CNPJ);
    fprintf(file,"credito=%2.f\n",credito);
    fprintf(file,"Telefone=%s\n",telefone);
    fprintf(file,"endereco=%s\n",endereco);
    fprintf(file,"saldo=%2.f\n",saldo);
    fprintf(file,"data=%s\n",data_de_nascimento);

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
    
    fprintf(file,"nome=%s\n",nome);
    fprintf(file,"senha=%s\n",senha);
    fprintf(file,"pin=%d\n",pin);
    fprintf(file,"CNPJ=%s\n",CPF);
    fprintf(file,"credito=%2.f\n",credito);
    fprintf(file,"Telefone=%s\n",telefone);
    fprintf(file,"endereco=%s\n",endereco);
    fprintf(file,"saldo=%2.f\n",saldo);
    fprintf(file,"data=%s\n",data_de_nascimento);
}

void request_salePF(char CPF[]){
    char path[100]="./PF/userPF";
    strcat(path,CPF);
    char ext[15]={".txt"};
    strcat(path,ext);

    char ch[30][30];

    FILE *file;
    file =fopen(path,"r");
    int i=0;
    while (fgets(ch[i],40,file))
    {
        i++;
    }
    
    printf("%s",ch[7]);

}

int main(){
  request_salePF("38646218000190");
}