#include <stdio.h>

int inverter(int num){
	int aux = 0;
	
	while(num > 0){
		aux = aux*10 + num%10;
		num /= 10;
	}
	
	return aux;
}

int main(){
	int nume;
	
	do{
	scanf("%d", &nume);
	}while(nume < 1000 || nume > 9999);
	
	printf("%d", inverter(nume));
	
	return 0;
}
