#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define MAX_FAQ_ENTRADA 100
#define MAX_PERGUNTA_TAM 100
#define MAX_RESPOSTA_TAM 500

typedef struct {
    char pergunta[MAX_PERGUNTA_TAM];
    char resposta[MAX_RESPOSTA_TAM];
} FAQEntrada;

FAQEntrada faq[MAX_FAQ_ENTRADA];
int faqContador = 0;

void adcFAQ(char *pergunta, char *resposta) { //Função para adicionar faqs
    if (faqContador < MAX_FAQ_ENTRADA) {
        strncpy(faq[faqContador].pergunta, pergunta, MAX_PERGUNTA_TAM - 1);
        faq[faqContador].pergunta[MAX_PERGUNTA_TAM - 1] = '\0';
        strncpy(faq[faqContador].resposta, resposta, MAX_RESPOSTA_TAM - 1);
        faq[faqContador].resposta[MAX_RESPOSTA_TAM - 1] = '\0';
        faqContador++;
    } else {
        printf("Armazenamento FAQ está cheio!\n");
    }
}

void listFAQ() { //função para listar faqs 
    for (int i = 0; i < faqContador; i++) {
        printf("FAQ #%d\n", i + 1);
        printf("Pergunta: %s\n", faq[i].pergunta);
        printf("Resposta: %s\n\n", faq[i].resposta);
    }
}

void procuraFAQ(char *palavraChave) {
    int achado = 0;
    for (int i = 0; i < faqContador; i++) {
        if (strstr(faq[i].pergunta, palavraChave) || strstr(faq[i].resposta, palavraChave)) {
            printf("FAQ #%d\n", i + 1);
            printf("Question: %s\n", faq[i].pergunta);
            printf("Answer: %s\n\n", faq[i].resposta);
            achado = 1;
        }
    }
    if (!achado) {
        printf("Nenhuma FAQ encontrada contendo a palavra-chave! '%s'.\n", palavraChave);
    }
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    adcFAQ("Não consigo criar a conta. E agora?", "Confira se a sua senha está dentro dos padrões exigidos.");
    adcFAQ("Não consigo transferir. E agora? ", "Confira se o seu CPF e senha estão corretos. ");
    adcFAQ("Qual o passo a passo da transferência? ", "Na ordem: CPF, PIN, Quantia a ser transferida, CPF do destinatário.");

    printf("Listando todas as FAQs:\n");
    listFAQ();

    printf("Procurando por 'transferir':\n");
    procuraFAQ("cadastro");

    return 0;
}

