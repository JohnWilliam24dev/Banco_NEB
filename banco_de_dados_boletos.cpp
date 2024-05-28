#include <stdio.h>
typedef struct {
	char codigo_boleto[9];
	float valor_boleto;
}Codigos;
Codigos codigos[9];

int main() {
	codigos[0].codigo_boleto = "26562951";
	codigos[0].valor_boleto = 140;
	
	codigos[1].codigo_boleto = "67991257";
	codigos[1].valor_boleto = 141;
	
	codigos[2].codigo_boleto = "88574391";
	codigos[2].valor_boleto = 142;
	
	codigos[3].codigo_boleto = "47649058";
	codigos[3].valor_boleto = 143;
	
	codigos[4].codigo_boleto = "37317496";
	codigos[4].valor_boleto = 144;	
	
	codigos[5].codigo_boleto = "26472900";
	codigos[5].valor_boleto = 145;
	
	codigos[6].codigo_boleto = "68547301";
	codigos[6].valor_boleto = 146;
	
	codigos[7].codigo_boleto = "97719282";
	codigos[7].valor_boleto = 147;
	
	codigos[8].codigo_boleto = "07024520";
	codigos[8].valor_boleto = 148;
}
