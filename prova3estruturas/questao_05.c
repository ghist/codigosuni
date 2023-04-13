
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 20

//struct no com as variaveis para guardar os valores digitados e os no prox e no ant para fazer o referenciamento
typedef struct no{
	int cpf;
	char nome[MAX];
	int idade;
	struct no *proximo;
	struct no *anterior;	
}No;


int tamanho = 0;

// aqui é onde ocorre o inserir que ja vai ordernando por cpf, logo apos ser chamada é criado o alocamento para a nova pessoa inserida
void ordenar(No **lista, int num, char nome[], int idade){
	
	No *aux, *novo = malloc(sizeof(No));
	
	
	if(novo){
	
		novo->cpf = num;//novo->cpf recebe o cpf que foi passado assim como novo->()recebe as outras variaveis, depois é feita a ordenacao
		//é percorrida a lista para fazer a ordenacao
		strcpy(novo->nome, nome);
	
		novo->idade = idade;
		
	
		if(*lista == NULL){
			
			novo->proximo = NULL;
			novo->anterior = NULL;
			
			*lista = novo;
		
		}
		
		else if(novo->cpf < (*lista)->cpf){
			novo->proximo = *lista;
			
			(*lista)->anterior = novo;
			
			*lista = novo;
		
		}
		
		else{
			
			aux = *lista;
			
			while(aux->proximo && novo->cpf > aux->proximo->cpf){
			
				aux = aux->proximo;
			}
		
			novo->proximo = aux->proximo;
			
			if(aux->proximo){
			
				aux->proximo->anterior = novo;
			}
		
			novo->anterior = aux;
			
			aux->proximo = novo;	
		}
	
		tamanho++;//serve para percorrer a lista, ja que é um ponteiro a deslocacao é feita assim
	}
	
	else{
		printf("Erro ao alocar memoria \n");
	}
}
//funcao basica q é feita a impresao das variaveis, enquanto no nao for null é percorrida e imprime os valores naquela posicao da lista
void imprimir(No *no){
	int i = 0;
	printf("\nLista: ");
	while(no != NULL){
	
		printf("Pessoa [%d] \n", i);
		printf("Cpf: %d, ", no->cpf);
		printf("Nome: %s, ", no->nome);
		printf("Idade: %d \n", no->idade);

		no = no->proximo;
		i++;
		printf("\n");
	}
	printf("\n\n");
}

//aqui é a funcao onde mostra as pessoas desejadas ate tal idade
void mostrar(No *no){
	
	int i=0, idade;
	
	printf("Mostrar pessoas ate certa idade \n");
	
	printf("Idade: ");
	
	scanf("%d", &idade);
	
	printf("Lista de pessoas ate %d anos \n", idade);
	while(no){
	
		if(no->idade < idade){
			printf("Pessoa [%d] \n", i);
			printf("Cpf: %d, ", no->cpf);
			printf("Nome: %s, ", no->nome);
			printf("Idade: %d \n", no->idade);
		}
	
		no = no->proximo;
		i++;
	}
	
	printf("\n\n");
}

//funcao que busca um cpf especifico, caso encontrado é feito o retorno do no onde se encontra, passado por parametro um ponteiro para ponteiro
No *busca(No **lista, int cpf){//e o cpf desejado

	No *auxiliar, *no = NULL;

	auxiliar = *lista;

	while(auxiliar && auxiliar->cpf != cpf)

		auxiliar = auxiliar->proximo;

	if(auxiliar)

		no = auxiliar;
	return no;
}

//funcao que procura a pessoa maior pelo cpf que vem depois que passa pela funcao buscar, entao é feito as condicoes e entra em cada se for o caso
int maior(No *achou){
	

	if(achou->proximo == NULL && achou->anterior == NULL){//se for null em ambos, entao volta que nao tem vizinho
		printf("Pessoa nao possui vizinhos \n");
	}

	else if(achou->proximo == NULL){//se apenas o proximo for null diz que nao tem um vizinho proximo
		printf("Não existe um vizinho proximo \n");
		if(achou->anterior->idade > achou->idade){//e aqui segue a logica
			printf("Pessoa informada e mais nova que vizinho anterior \n");
		}else{
			printf("Pessoa informada e mais velha que vizinho anterior \n");
		}
		
	}
	
	else if(achou->anterior == NULL){// se o anterior for null retorna que nao tem vizinho antes
		printf("Anterior vizinho e igual a NULL \n");
		if(achou->proximo->idade > achou->idade){//aqui segue a logica para todo o resto dessa funcao achou
			printf("Pessoa informada e mais nova que vizinho proximo\n");
		}else{
			printf("Pessoa informada e mais velha que este proximo \n");
		}
	}
	
	
	else if(achou->proximo->idade > achou->anterior->idade){
	
		printf("O seu vizio [%s]  e mais velho [%d] \n", achou->proximo->nome ,achou->proximo->idade);
		
	
		if(achou->proximo->idade > achou->idade){
			printf("Pessoa informada e mais nova que este vizinho \n");
		}else{
			printf("Pessoa informada e mais velha que este vizinho \n");
		}
	
		}else{
			printf("O seu vizio [%s]  e mais velho [%d] \n", achou->anterior->nome ,achou->anterior->idade);
		
			if(achou->anterior->idade > achou->idade){
				printf("Pessoa informada e mais nova que este vizinho \n");
			}else{
				printf("Pessoa informada e mais velha que este vizinho \n");
			}
		}	
		
	return 1;
}

//funcao main que serve apenas para interagir
int main() {

	int op, cpf, idade;

	char nome[MAX];

	No *lista = NULL;

	No *achou;
	

	printf("1- Inserir\n2-Imprimir\n3-Mostrar pessoas ate uma idade\n4-Buscar pelo cpf\n5-Digite um numero negativo para sair\n");

	do{

		printf("Opcao: ");
		scanf("%d", &op);

		switch(op){

			case 1:

				printf("Cpf: ");
				scanf("%d", &cpf);
				printf("Nome: ");
				scanf("%s", &nome);
				printf("idade: ");
				scanf("%d", &idade);
			
				ordenar(&lista, cpf, nome, idade);
				break;
			case 2:
			
				printf("Existem [%d] Pessoas na lista\n", tamanho);
			
				imprimir(lista);
				break;
			case 3:
			
				mostrar(lista);
				break;
			case 4:
				
				printf("Cpf a ser buscado: ");
				scanf("%d", &cpf);
				
				achou = busca(&lista, cpf);
				
				if(achou){
					printf("Encontrado: cpf: [%d], nome: [%s], idade: [%d]\n", achou->cpf, achou->nome, achou->idade);
					maior(achou);
				}
				
				else
					printf("Nao encontrado \n");
				break;
			
			default:
				printf("Opcao errada \n");
				break;
		}
	
	}while(op > 0);
	
	
	return 0;
}
