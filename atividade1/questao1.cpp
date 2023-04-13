#include <stdio.h>



int main(){
	
	float valor, venda;
	
	printf("");
	scanf("%f", &valor);
	
	if(valor > 20){
		venda = valor * 1.3;
	} else {
		venda = valor * 1.45;
	}
	
	printf("%0.2f", venda);
	
	return 0;
}


