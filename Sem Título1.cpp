#include <stdio.h>

void preencheFibVetor( long long fibVetor[], int tamanho){
	int i, n;
	fibVetor [0] = 0;
	fibVetor [1] = 1;
	for(i = 2; i <= 60; i++){
		fibVetor[i] = fibVetor[i-1] + fibVetor[i-2];
	}
	
	for(i = 0; i < tamanho; i++){
		scanf("%d", &n);
		printf("Fib(%d) = %lli\n", n, fibVetor[n]);
	}
	
}

int main(){
	int tam;
	long long vet[61];
	
	scanf("%d", &tam);
	preencheFibVetor(vet, tam);
	
	
	return 0;
}
