#include <stdio.h>

int main(){
	int num, soma = 0;
	
	scanf("%d", &num);
	
	do{
		
		soma = num + soma;
		scanf("%d", &num);
		
	}while(num > 0);
	
	printf("%d", soma);
	
	return 0;
	
}
