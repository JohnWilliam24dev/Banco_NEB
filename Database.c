#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/stat.h>
void insert_client_legal_entire(char nome[],char senha[],int pin,char data_de_nascimento[],char CNPJ[],char telefone[],char endereco[],float saldo,float credito){


    
    
    int f=mkdir("./PJ");
    if (f==0){
        system("mkdir PJ");
        system("cls");
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

int f=mkdir("./PF");
    if (f==0){
        system("mkdir PF");
        system("cls");
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
void edit_PF(char CPF[],int option,char mod[]){
  
    char path[100]="./PF/userPF";
    strcat(path,CPF);
    char ext[15]={".txt"};
    strcat(path,ext);
    char chPF[100][50];


    FILE *filePF;
    filePF =fopen(path,"r");
    int tamanho=0;
    int i=0;
    while (fgets(chPF[i],40,filePF)!=NULL)
    {
    	
    
        i++;
    }
    tamanho=i-1;
    fclose(filePF);
    i=0;
    filePF =fopen(path,"w+");
    fprintf(filePF," ");
    
    fclose(filePF);
    
    
    strcpy(chPF[option],mod);
    
    
    filePF =fopen(path,"w+");
     while (i<=tamanho){
    	
    	
    	if(strcmp(chPF[i],chPF[option])==0){
    		fprintf(filePF,"%s\n",chPF[i]);
		}else{
			fprintf(filePF,chPF[i]);
		}
    
	
		
        i++;
        
    }

    fclose(filePF);
    
}

void edit_PJ(char CNPJ[],int option,char mod[]){
  
    char path[100]="./PJ/userPJ";
    strcat(path,CNPJ);
    char ext[15]={".txt"};
    strcat(path,ext);
    char chPJ[100][51];


    FILE *filePJ;
    filePJ =fopen(path,"r");
    int tamanho=0;
    int i=0;
    while (fgets(chPJ[i],40,filePJ)!=NULL)
    {
    	
    
        i++;
    }
    tamanho=i-1;
    fclose(filePJ);
    i=0;
    filePJ =fopen(path,"w+");
    fprintf(filePJ," ");
    
    fclose(filePJ);
    
    
    strcpy(chPJ[option],mod);
    
    
    filePJ =fopen(path,"w+");
     while (i<=tamanho){
    	
    	
    	if(strcmp(chPJ[i],chPJ[option])==0){
    		fprintf(filePJ,"%s\n",chPJ[i]);
		}else{
			fprintf(filePJ,chPJ[i]);
		}
    
	
		
        i++;
        
    }

    fclose(filePJ);
    
}