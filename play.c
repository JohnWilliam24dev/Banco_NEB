#include <stdio.h>
#include <stdlib.h>
#include "Database.h"
int main(){
	char info[20];
	char* pin;
	printf("digite uma info: ");
	scanf("%s",info);
	pin=request_PF("12345678011",2);
	printf("%i",strcmp(info,pin));
	
	return 0;
	}