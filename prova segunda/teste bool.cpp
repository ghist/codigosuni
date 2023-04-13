#include <stdio.h>
#include <stdlib.h>

typedef struct produto{
	int codigo;
	char descricao[30];
	float preco;
}produto;

produto item[1000];

int main(){
	bool a = true;
	if(a == false){
		printf("3");
	}
	
	return 0;
}
