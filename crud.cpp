#include <stdio.h>
#include <stdlib.h>

int main(){
    struct userPJ
    {
        char nome;
        char data_de_nascimento;
        char CNPJ;
        float saldo;
        float credito;
    };
    system("mkdir PF");
    FILE *file;
    file=fopen(("./PF/userPF.txt"),"a");
    fprintf(file,"nome=%s","João");

}