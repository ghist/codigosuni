#include<stdio.h>
#include<stdlib.h>

int soma(int num, int somab){
	if(num<1){
		return somab;
	}
	somab+=(num%10);
	return soma(num/10, somab);
}

int main(){
	int num;
	int somaa;
	printf("Digite um numero: ");
	scanf("%i", &num);
	somaa = soma(num, 0);
	
	printf("%i", somaa);
	
	return 0;
}
