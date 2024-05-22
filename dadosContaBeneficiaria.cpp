#include <stdio.h>
#include "bancoDeDados.c"
void dadosContaBeficiaria(int numeroVetorial) {
	printf("NOME: %s\n", pessoaFisica[numeroVetorial].nome);
	printf("TELEFONE: %s\n", pessoaFisica[numeroVetorial].telefone);
}
