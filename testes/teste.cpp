#include <stdio.h>
#include <stdlib.h>

int main(){
	int *p;
	int a;
	
	p = (int *)malloc(sizeof(int));
	
	if(p==NULL){
		printf("**Erro: Memoria Insuficiente**");
		exit(1);
	}else{
		printf("**Memoria alocada com sucesso**");
	}
	return 0;
}
