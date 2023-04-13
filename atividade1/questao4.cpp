#include <stdio.h>

int main(){
	int quant;
	float valor;
	
	scanf("%d", &quant);
	
	if((quant < 12) && (quant > 0)){
		valor = quant * 1.30;
	}if(quant >= 12){
		valor = quant *1;
	}
	
	printf("R$ %0.2f", valor);
	
	return 0;
}
