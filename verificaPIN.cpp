#include <stdio.h>
#include "bancoDeDados.c"
int verificaPIN(int PIN) {
	if(PIN == pessoaFisica[contaUsuario].pin)
		return 1;
	else
		return 0;	
}
