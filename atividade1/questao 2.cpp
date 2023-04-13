#include <stdio.h>



int main(){
	
	float bruto, desconto, receber;
	
	scanf("%f", &bruto);
	
	if(bruto <= 600){
		receber = bruto;
		printf("%0.2f", receber);
	}
	
	if((bruto > 600) && (bruto <= 1200)){
		desconto = bruto * 0.20;
		receber = bruto - desconto;
		printf("%0.2f", desconto);
		printf("\n%0.2f", receber);
	
	}
	
	if((bruto > 1200) && (bruto <= 2000)){
		desconto = bruto * 0.25;
		receber = bruto - desconto;
		printf("%0.2f", desconto);
		printf("\n%0.2f", receber);
	
	}
	
	if(bruto > 2000){
		desconto = bruto * 0.30;
		receber = bruto - desconto;
		printf("%0.2f", desconto);
		printf("\n%0.2f", receber);
	}
	
	return 0;
	
}
