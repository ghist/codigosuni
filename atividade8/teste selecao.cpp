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

void selecao(int *v, int n){
	int i,j, min;
	for(i = 0; i < n-1; i++){
		min = i;
		for(j = i + 1; j <n; j++){
			if(v[j] < v[min])
				min = j;
				NUM_COMP++;
		}
		
		troca(&v[i], &v[min]);			
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
	
	selecao(vetor, n);
	printf("comparacoes: %d\nmovimentacoes: %d", NUM_COMP, NUM_MOV);
	
	return 0;
	
	
}
