#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>//necessário p/ função time()

void ler_aposta(int *aposta, int n){//funcao ler aposta vai passar como parametro o vetor aposta e a quantidade de numeros apostados
	int i, num;
	printf("Ler Aposta \n");
	for(i=0; i<n; i++){//enquanto i for menor que n, o for sera executado e será lido o numero digitado que o usuario apostar
		printf("Digite os numeros: ");//caso seja fora do intervalo 0 e 100, aparecerá uma mensagem de erro
		scanf("%d", &num);
		if(num > 0 && num < 100){
			*(aposta+i) = num;
		}else{
			printf("Valor errado \n");
		}
	}
}

void sorteia_valores(int *sorteio, int n){//funcao que sorteia os numeros de 0 a 100 usando o rand, e passando como parametro o vetor sorteio e a
	int i;//quantidade de numeros sorteados, e armazenando os numeros sorteados no vetor
	
	for(i=0; i < n; i++){
		*(sorteio+i) = rand()%100;
	}
	
//	for(i=0; i < n; i++){
//		printf("%d \n", *(sorteio+i));
//	}
}


int* compara_aposta(int *aposta, int *sorteio, int *qtdcertos, int na, int ns){//a funcao recebe os vetores aposta, sorte, e retorna qtdcertos, e recebe na e ns
	//é feito dois for, de i ate na e o outro de j ate ns, caso os numeros apostados sejam iguais aos sorteados, qtdcertos recebe + 1

	
	for(int i=0; i<na; i++){
		for(int j=0; j<ns; j++){
			if(*(aposta+i) == *(sorteio+j)){
				*qtdcertos += 1;
			}
		}
	}
	
	return *qtdcertos;
}

int main(){//na main é feita a declaracao de variaveis, *vetores com null e a alocacao com malloc e calloc
	//feito o pedido da quantidade de numeros que serao apostados, e entao é chamado as funcoes e depois impreme os acertos
	int n, na, ns, s = 20;
	int *aposta = NULL;
	int *sorteio = NULL;
	int *qtdcertos;
	int *vetordeacertos;
	printf("Bingo de ED I \n");
	printf("Quantidade de numeros que deseja apostar entre 1 e 20: ");
	scanf("%d", &n);
	
	aposta = (int*) malloc(n*sizeof(int));
	sorteio = (int*) malloc(s*sizeof(int));
	qtdcertos = (int*) calloc(n, sizeof(int));
	*qtdcertos = 0;	
	vetordeacertos = (int*) calloc(n, sizeof(int));
	
	
	ler_aposta(aposta, n);
	na = n;
	//srand(time(NULL));
	sorteia_valores(sorteio, s);
	ns = 20;
	
	for(int i=0; i<na; i++){
		for(int j=0; j<ns; j++){
			if(*(aposta+i) == *(sorteio+j)){
				*(vetordeacertos+i) = *(aposta+i);
			}
		}
	}
	
	*(vetordeacertos+n) = compara_aposta(aposta, sorteio, qtdcertos, na, ns);
	
	for(int i=0; i<na; i++){
		printf("%d ", *(vetordeacertos+i));
	}
	printf("\n");
	printf("Total de acertos: %d", *(vetordeacertos+n));
	return 0;
}


