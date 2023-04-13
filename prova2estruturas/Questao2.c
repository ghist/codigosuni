//Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
//É Ultilizada a função strcmp da string.h
#include <string.h>
//define é usado para definir o tamanho do conjunto
#define CONJUNTO 3

//declaracao da struct livros com as variaveis para os dados;
typedef struct livros{
	int codigo;
	char titulo[20];
	char autor[20];
	char editora[20];
	int ano;
	int num_exemplar;
}Livros;

//Função inicializar, que inicia com NULL em todas as posições do vetor
void inicializar(int t, Livros **livro){
	int i=0;
	
	for(i=0; i<t; i++){
		livro[i] = NULL;
	}
}

//Função usada para cadastro dos livros
void cadastrar(int t, Livros **livro, int i){
	
	//if de condicao para verificar se o conjunto ja está no limite, seja o caso, aparece essa mensagem
	if(i >= t){
		printf("Limite do conjunto atingido");
	}
	
	//caso o valor de livro[i] == NULL, é alocado memoria livro[i] e feito o cadastro do livro
	if(livro[i]==NULL){
		livro[i] = (Livros*)malloc(sizeof(Livros));
		printf("Informe o codigo: ");
		scanf("%d", &livro[i]->codigo);
		printf("Informe o titulo: ");
		scanf("%s", &livro[i]->titulo);
		printf("Informe o autor: ");
		scanf("%s", &livro[i]->autor);
		printf("Informe a editora: ");
		scanf("%s", &livro[i]->editora);
		printf("Informe o ano: ");
		scanf("%d", &livro[i]->ano);
		printf("Informe o numero de exemplares: ");
		scanf("%d", &livro[i]->num_exemplar);
		printf("\n");
	}	
}


//função para buscar a editora
void editora(int t, Livros **livro){//é feita a entrada de dados da editora desejada, entao o for percorre todos os valores do vetor livro[i].editora
	int i, verifica;//é usada a funcao strcmp da string para verificar se a editora inserida ''e igual a alguma, se for retorna 0
	char n[20];
	printf("Informe a editora: ");
	scanf("%s", &n);
	

	for(i=0; i<t; i++){

		verifica = strcmp(n,livro[i]->editora);
		//caso verifica for igual a 0 ela mostra apenas os livros que tem a mesma editora
		if(verifica == 0){
			printf("\n");
			printf("Codigo: %d \n", livro[i]->codigo);
			printf("Titulo: %s \n", livro[i]->titulo);
			printf("Autor: %s \n", livro[i]->autor);
			printf("Editora: %s \n", livro[i]->editora);
			printf("Ano: %d \n", livro[i]->ano);
			printf("Numero de exemplares: %d \n", livro[i]->num_exemplar);
			break;		
		}
		
	}
	
}

//função autor responsavel por mostrar apenas os livros com os mesmos autores
void autor(int t, Livros **livro){//funciona da mesma maneira da funcao que busca editora, é inserido o autor, e um for que percorre todo o vetor
	//verifica recebe o retorno 0, caso o dado inserido tenha no vetor livro.autor, e entao entra no if e impreme os dados, ate percorrer todo o vetor
	int i, verifica;
	char n[20];
	
	printf("Informe a editora: ");
	scanf("%s", &n);
	
	for(i=0; i<t; i++){
		
		verifica = strcmp(n,livro[i]->autor);
		if(verifica == 0){
			printf("\n");
			printf("Codigo: %d \n", livro[i]->codigo);
			printf("Titulo: %s \n", livro[i]->titulo);
			printf("Autor: %s \n", livro[i]->autor);
			printf("Editora: %s \n", livro[i]->editora);
			printf("Ano: %d \n", livro[i]->ano);
			printf("Numero de exemplares: %d \n", livro[i]->num_exemplar);		
		}
	}
}

//função libera
void remover(int t, Livros **livro){
	
	int r;
	//aqui pede o codigo do livro para ser removido
	printf("Codigo para remover o livro: ");
	scanf("%d", r);
	//uso o free para liberar a memoria.
	free(livro[r]);
	livro[r] = NULL;
}
 
//meu main
int main(){//na main, tem decalaracao das variaveis e o menu interativo, while com a condicao de ser executado enquanto i for diferente de 0
	int i=1, t = CONJUNTO, op, limite=0;
	//declaração do ponteiro vetor 
	Livros *livro[CONJUNTO];
	//chamada da função inicializar que recebe t=CONJUNTO e meu ponteiro vetor livro
	inicializar(t, livro);
	//pequeno menuzinho mostrando oque o programa faz
	printf("1- Cadastrar Livro \n");
	printf("2- Mostrar Editora \n");
	printf("3- Mostrar Autor \n");
	printf("4- Remover Livro \n");
	printf("5- Sair \n");
	
	while(i != 0){
		printf("\n");
		printf("Opcao: ");
		scanf("%d", &op);
		switch(op){
			case 1:
				cadastrar(t, livro, limite);
				limite += 1;
				break;
			case 2:
				editora(t, livro);
				break;
			case 3:
				autor(t, livro);
				break;
			case 4:
				remover(t, livro);
				break;
			case 5:
				printf("Programa Encerrado.....");
				i = 0;
				break;
			default:
				printf("Opcao invalida, tente novamente");
				break;
		}
	}
	return 0;
}
