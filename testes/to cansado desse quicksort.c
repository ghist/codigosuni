#include <stdio.h>
#include <stdlib.h>
#define n 11

void quickSort(int *V, int inicio, int fim) {
	int pivo;
	if(fim > inicio){
		pivo = particiona(V, inicio, fim);
		quickSort(V, inicio, pivo-1);
		quickSort(V, pivo+1, fim);
	}
}

int particiona(int *V, int inicio, int final) {
	int esq, dir, pivo, aux;
	esq = inicio;
	dir = final;
	pivo = V[inicio];
	while(esq < dir){
		while(V[esq] <= pivo)
			esq++;
		while(V[dir] > pivo)
			dir--;
		if(esq < dir){
			aux = V[esq];
			V[esq] = V[dir];
			V[dir] = aux;
		}
	}
	V[inicio] = V[dir];
	V[dir] = pivo;
	return dir;
}

int inserir(int *vetor3[], int *vetor4[], int *vetor5[]){
	int i;
	if(i < n){
		vetor5[i*2] = vetor3[i];
		vetor5[i*2+1] = vetor4[i];
		i+=1;
		inserir(vetor3, vetor4, vetor5);
	}
}

int main(){
	int vetor[n] = {50,4,3,5,7,9,8,10,6,2,11};
	int vetor2[n] = {51,4,3,5,7,9,8,10,6,13,12};
	int vetor6[n*2];
	
	quickSort(vetor, 0, n-1);
	quickSort(vetor2, 0, n-1);
	
	for(int i = 0; i < n; i++){
		printf("%d ",vetor[i]);
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ",vetor2[i]);
	}
	printf("\n");
	
	inserir(vetor, vetor2, vetor6);
	
	
	for(int i = 0; i < n*2; i++){
		printf("%d ",vetor6[i]);
	}	
	return 0;
}
