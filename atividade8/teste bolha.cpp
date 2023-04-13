#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int NUM_COMP = 0, NUM_MOV = 0;

void troca(int *a, int *b){ 
    int aux = *a; 
    *a = *b; 
    *b = aux; 
    NUM_MOV++;  
} 

void bolha(int *v, int n){
	int i,j;
	for(i = 0; i < n-1; i++){
		for(j = 1; j <n-i; j++){
			if(v[j] < v[j-1])
				troca(&v[j-1], &v[j]);
				NUM_COMP++;
		}
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
	
	bolha(vetor, n);
	printf("comparacoes: %d\nmovimentacoes: %d", NUM_COMP, NUM_MOV);
	
	return 0;
	
	
}
