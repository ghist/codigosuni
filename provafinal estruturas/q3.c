#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 10

/*Cada time possui os campos: nome, 
treinador, vitórias, empates, derrotas, jogadores (um vetor de jogadores). 
Implemente as operações*/
struct time{
	char nome[30];
	char treinador[30];
	int vitorias;
	int empates;
	int derrotas;
	
};
typedef struct time ti;


void atribui(int t, ti **tim){
	
	printf("atribui \n");
	fflush(stdin);
	if(t < max){

		tim[t]= (ti*) malloc(sizeof(ti));
		
		printf("Time dados! \n");
		printf("Nome do time: ");
		gets(tim[t]->nome);
		printf("Treinador: ");
		gets(tim[t]->treinador);
		printf("Vitorias: ");
		scanf("%d", &tim[t]->vitorias);
		printf("Empates: ");
		scanf("%d", &tim[t]->empates);
		printf("Derrotas: ");
		scanf("%d", &tim[t]->derrotas);
		
		printf("\n");
		
		printf("time: %s \n", tim[t]->nome);
	}
	printf("\n");
}

void imprime(int t, ti **tim){
	int c;
	printf("imprime \n");
	printf("time a ser buscado: ");
	scanf("%d", &c);
	int aux = 0;
	
	if(c > 0 || c < t){
		for(int i = 0; i < t; i++){
			if(c == i){
				printf("Nome do time: %s\n Treinador: %s\n Vitorias: %i\n Empates: %i\n Derrotas: %i\n", tim[i]->nome, tim[i]->treinador, tim[i]->vitorias, tim[i]->empates, tim[i]->derrotas);
				aux = 1;
			}
		}
	}
	if(aux == 0){
		printf("Time nao encontrado! ");
	}
	
}

void imprime_todos(int t, ti **tim){
	printf("Todos os times! \n");
	for(int i = 0; i < t; i++){
		printf("Nome do time: %s\n Treinador: %s\n Vitorias: %i\n Empates: %i\n Derrotas: %i\n", tim[i]->nome, tim[i]->treinador, tim[i]->vitorias, tim[i]->empates, tim[i]->derrotas);
		printf("\n");
	}
}

void soma(int t, ti **tim){
	int c;
	int soma1, soma2, total;
	printf("Soma dos pontos! ");
	printf("Insira codigo do time: ");
	scanf("%i", &c);
	
	if(c > 0 || c < t){
		for(int i = 0; i < t; i++){
			if(c == i){
				soma1 = tim[i]->vitorias * 3;
				soma2 = tim[i]->empates * 1;
				total = soma1 + soma2;
				printf("Time: %s ", tim[i]->nome);
				printf("total de pontos: %i pontos\n", total);
			}
		}
	}
	
}

void libera(int t, ti **tim){
	int c;
	printf("Libera\n");
	printf("Liberar time: ");
	scanf("%d", &c);
	
	if(c > 0 || c < t){
		free(tim[c]);
		tim[c] = NULL;
	}
}

int main(){
	int op;
	int t = 0;
	ti *tim[max];
	
	
	do{
		printf("1 - atribui \n");
		printf("2 - impreme \n");
		printf("3 - impreme todos \n");
		printf("4 - pontuacao\n");
		printf("5 - libera\n");
		scanf("%i", &op);
		if(op == 1){
			atribui(t, tim);
			t++;
		}else if(op == 2){
			imprime(t, tim);
		}else if(op == 3){
			imprime_todos(t, tim);			
		}else if(op == 4){
			soma(t, tim);
		}else if(op == 5){
			libera(t, tim);
		}else{
			printf("Operacao invalida, tente novamente! \n");
		}
		
	}while(op != 0);
}
