#include <stdio.h>//declaracao das bibliotecas
#include <stdlib.h>
#include "ListaDuplaEncadeada.h"


struct elemento{//os tipos de dados da lista
	struct elemento *ant;
	struct pessoa dados;
	struct elemento *prox;
};
typedef struct elemento Elem;

Lista* inicializa(){//retorna uma lista, é alocado espaço na memoria para Li
	Lista* Li = (Lista*) malloc(sizeof(Lista));//se for != null, significa que deu certo
	if(Li != NULL)//entao *Li vai apontar para Null, depois retorno Li
		*Li = NULL;
	return Li;
}

void libera(Lista* Li){//passo a lista como parametro
	if(Li != NULL){//se nao for nula, crio uma struct no auxiliar
		Elem* no;//entao desde que a lista tenha conteudo, sera executado e no recebe o conteudo de lista, até o ultimo elemento
		while((*Li) != NULL){//depois de todo o conteudo ser liberado, libero a lista também, ou como //, pode ser liberado so o Li e o no nao
			no = *Li;
			*Li = (*Li) -> prox;
			free(no);
			//free(Li);
		}
		free(Li);
	}
}

int lista_vazia(Lista *li){
	if ((*li) == NULL) {
		return 1;
	}
	return (*li == NULL);
}

int insere(Lista *li, struct pessoa al){
	if (li == NULL) {
		return 0;
	}
	Elem *no = (Elem *) malloc (sizeof(Elem));

	if (no == NULL) {
		return 0;
	}
	no->dados = al;
	if (lista_vazia(li)) {//insere no inicio
		no->ant = NULL; ////////////////////
		(*li)->ant = no; ///////////////////
		no->prox = (*li); //////////////////
		*li = no;
		return 1;
	} else {
		Elem *ant, *atual = *li;

		while (atual != NULL
			&& atual->dados.cpf < al.cpf) {
			ant = atual;
			atual = atual->prox;
		}
		if (atual == *li) { //insere no inicio
			(*li)->ant = no; //////////////
			no->prox = (*li);
			*li = no;
		} else { //insere depois de 
			no->prox=ant->prox; /////////
			no->ant = ant; ////////////
			ant->prox = no;
		}
	}
	return 1;
}
/* passo a lista como parametro, caso a lista nao existe ou esteja vazia, retorno 0, crio um no auxiliar que recebe o primeiro item a lista
,enquanto o o proximo item da lista nao for null, eu percorro toda a lista, apos andar e chegar no ultimo, verifico se o anterior é null
se for, significa que so tem um elemento, e a lista fica vazia, caso nao seja o caso também, aponta para o no anterior, que a ponta para o proximo e entao é feita a remocao*/
int remove_lista_final(Lista* Li){
	if(Li == NULL) return 0;
	Elem *no = *Li;
	while(no->prox != NULL){
		no = no->prox;
	}
	if(no->ant == NULL){
		*Li = no->prox;
	}else{
		no->ant->prox = NULL;
	}
	free(no);
	return 1;
}
/* diferente do outro metodo, aqui removo um numero especifico, é passado a lista e o numero como parametro, entao percorro a lista, se encontrado, é feita a remoção
entao o no criado que recebe o primeiro elemento for diferente de null e o numero for diferente, eu ando na lista, se no == null, entao cheguei ao fim da lista
e nao encontrei o elemento, se no->ant for == a null, to removendo o primeiro elemento, entao *li aponta para o proximo elemento
caso nao seja igual a null, significa que to removento no meio, entao *li aponta para o ant que aponta para o proximo recebe o proximo no
caso nao seja o ultimo aponto para o anterior e entao libero*/
int remove_item(Lista* Li, int mat){
	if(Li == NULL) return 0;
	Elem *no = *Li;
	while(no != NULL && no->dados.cpf != mat){
		no = no->prox;
	}
	if(no == NULL) return 0;
	if(no->ant == NULL){
		*Li = no->prox;
	}else{
		no->ant->prox = no->prox;
	}
	
	if(no->prox != NULL){
		no->prox->ant = no->ant;
	}
	free(no);
	return 1;
}
/*passo a lista como parametro, verifico se é null, caso nao seja, crio um no auxiliar que recebe o primeiro elemento, entao
dese que no seja diferente de null, no recebe o proximo elemento e printa*/
void mostra_lista(Lista *Li) {
	if (Li == NULL) {
		printf("\nLista = ");
	} else {
		printf("\nLista = ");
		Elem *no = *Li;
		
		while (no != NULL) {
			printf("%d ", no->dados.cpf);
			no = no->prox;
		}
		printf(" ");
	}
}




int main(){//o main serve apenas para ter interacao e chamada de funcoes
	Lista *Li;
	struct pessoa Num;
	
	int x;
	int n = 0;
	while (n != 7){
		printf("1 - inicializa\n");
		printf("2 - insere\n");
		printf("3 - imprime\n");
		printf("4 - remove ultimo item\n");
		printf("5 - remove item especifico\n");
		printf("6 - libera\n");
		printf("7 - encerrar\n");
		scanf("%i", &n);
		if(n == 1){
			Li = inicializa();
		}
		if(n == 2){
			Num.cpf = 044;
			Num.nome = "marcos";
			Num.idade = 22;
			insere(Li, Num);
			Num.cpf = 072;
			Num.nome = "beatriz";
			Num.idade = 20;
			insere(Li, Num);
			Num.cpf = 070;
			Num.nome = "lena";
			Num.idade = 20;
			insere(Li, Num);	
		}
		if(n == 3){
			mostra_lista(Li);			
		}
		if(n == 4){
			remove_lista_final(Li);
		}
		if(n == 5){
			printf("Informe um numero: ");
			scanf("%i", &n);
			remove_item(Li, n);
		}
		if(n == 6){
			libera(Li);
		}
		if(n == 7){
			break;
		}
	}	
	return 0;
}

