#include <stdio.h>

int main(){
	int X, Y;
	int i, soma = 0, somaa = 1;
	
	do{
		
		scanf("%d%d", &X, &Y);
		
	}while(X > Y-2);
	
	
	for(i = X; i <= Y; i++){
		if(i % 2 == 0){
			soma = i + soma;
		}else{
			somaa = i * somaa;
		}
		
	}
	
	printf("%d \n%d", soma, somaa);
	
	return 0;
	
	
	
}
