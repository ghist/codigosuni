#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int NUM_COMP = 0, NUM_MOV = 0;

void insercao(int *v, int n){
	int i,j;
	int aux;
	for(i = 1; i < n; i++){
		aux = v[i];
		j = i -1;
		while((j >= 0) && (aux < v[j])){
			v[j + 1] = v[j];
			j--;
			NUM_MOV++;
		}
		v[j + 1] = aux;
		NUM_COMP++;
	}
	
	for(i = 0; i < n; i++){
		printf("%d \n", v[i]);
	}
}


int main(){
	srand(time(NULL));
	int n = 1000;
	int vetor[n];
	
	for(int i = 0; i < n; i++){
		vetor[i] = rand() % n;
	}
	
	insercao(vetor, n);
	printf("comparacoes: %d\nmovimentacoes: %d", NUM_COMP, NUM_MOV);
	
	return 0;
	
	
}
