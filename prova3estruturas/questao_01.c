//declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#define MAX 10


//declaração de struct, aqui a placa ja é declarada como um vetor, sei que tá errado mas é o que conseguimos fazer
typedef struct fila{
	int placa[MAX];
	int fim;
}Fila;

//inicializo a fila, funcao para inicializar
int inicializa(Fila *f){
	f->fim = -1;
	return 1;
}

//função que serve para mostrar se a fila esta cheia, caso esteja cheia nao é adicionado mais carros
int fila_cheia(Fila *f){
	if(f->fim >= MAX-1){
		printf("Fila cheia \n");
		return 1;
	}
	return 0;
}

//função que verifica se a lista esta vazia, importante para saber se existe carros ou nao no estacionamento
int fila_vazia(Fila *f){
	if(f->fim == -1){
		printf("Fila Vazia\n");
		return 1;
	}
	return 0;
}

//função que vai inserindo valores a minha lista f->placa de tamanho MAX(definido como 10)
//aqui recebo um valor para colocar na minha placa
int fila_insere(Fila *f, int valor){
	//verificaçao da fila, como citei la em cima, se tiver cheia nao adiciona, caso nao adiciona
	if(!fila_cheia(f)){
		f->fim++;
		f->placa[f->fim] = valor;
		return 1;	
	}

	return 0;
}

//aqui eu so consigo remover o ultimo
void fila_remove(Fila *f, int placa){
	int i = 0;
	for(i=0; i <= f->fim; i++){
		if(placa == f->placa[i]){
			printf("\nManobrado %dx \n", i);
		}
	}
	
}
//remover recebe fila *f, FUNCAO ESTÁ ERRADA, MAS FOI COMO CONSEGUIMOS
void remover(Fila *f){
	int i;
	
	for(i=0; i<f->fim; i++){
		f->placa[i] = f->placa[+i];
	}
	f->fim--;
}

//função  para imprimir
void imprimir(Fila *f){
	printf("\n");
    for(int i=0; i<=f->fim; i++){
        printf("%d  ", f->placa[i]);
    }
}

int main(){
	Fila *f;
	//declaro *f acima e as variaveis abaixo
	int placa, i = 1, op;
	//inicializo
	inicializa(&f);
	
	while(i != 0){
		//menuzinho
		printf("\n1-Insere\n2-Remove\n3-Imprime\n0-Sair\n");
		printf("Opcao: ");
		scanf("%d", &op);
		//switch case para perguntar qual opção o usuario deseja
		switch(op){
			case 1:
				printf("Inserir Placa: ");
				scanf("%d", &placa);
				fila_insere(&f, placa);
				break;
			case 2:
				printf("Inserir Placa: ");
				scanf("%d", &placa);
				fila_remove(&f, placa);
				remover(&f);
				break;
			case 3:
				imprimir(&f);
				break;
			case 0:
				return 1;
				break;
			default:
				printf("Opcao errada \n");
				break;
		}	
	}

	
	return 1;
}







