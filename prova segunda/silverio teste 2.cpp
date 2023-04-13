#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 6500


typedef struct{
	int codigo;
	char descricao[30];
	float preco;
}Tabela;

void cadastrar(Tabela t[], const int tamanho);
void visualizar(Tabela t[], const int tamanho);
void visualizaregistro(Tabela t[], const int tamanho);

FILE *fptr;
int op, cont=0;
Tabela v[MAX+1];

int main(void) 
{
	Tabela t[MAX+1];
	int i; 
	const int tamanho = 1000;
	printf(" 1-cadastrar \n 2-visualizar \n 3-visualizar registro \n 5-Finalizar\n ");		
	printf("Informe o módulo desejado: ");
	scanf("%d", &op);
	for(i=0;i<=tamanho;i++){
		t[i].codigo = 0;
	}
	
	while(op != 5){
		switch(op)
		{
			case 1:
				cadastrar(t, tamanho);
				break;
			case 2:
				visualizar(t, tamanho);
				break;
			case 3:
				visualizaregistro(t, tamanho);
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Opcao Invalida \n");
		}
		printf("Informe o módulo desejado: ");
		scanf("%d", &op);
	};
	
}

void cadastrar(Tabela t[], const int tamanho){
	int i;
	fptr = fopen("dados.txt", "w");
	t[0].codigo = 0;
	cont +=1;
	for(i=0; i<= tamanho;i++)
	{
		printf("Codigo, descricao, preco: ");
		scanf("%d %s %f", &t[i].codigo, t[i].descricao, &t[i].preco);
		if(t[i].codigo == t[i-1].codigo){
			printf("Cadastro ja existente!! \n");
			break;
		}
		fprintf(fptr, "%d %s %f \n", t[i].codigo, t[i].descricao, t[i].preco);	
	}	
	fclose(fptr);
	printf("%d \n", cont);
	
}

void visualizar(Tabela t[], const int tamanho){
	int i, codigo;
	char descricao[30];
	float preco;
	fptr = fopen("dados.txt", "r");
	printf("Dados armazenado no Arquivo: \n");
	while(!feof(fptr)){
	 	   printf( "codigo: %d, descricao, %s, preco: %f\n", codigo, descricao, preco );
           fscanf( fptr, "%d%s%f", &codigo, descricao, &preco );
	}
    fclose( fptr );
}


void visualizaregistro(Tabela t[], const int tamanho){
	int x;
	bool achou1 = false;
	printf("digite o arquivo a ser buscado: ");
	scanf("%d", &x);
	for(int i = 0; i < tamanho; i++){
		if(t[i].codigo == x){
			printf("codigo: %d", t[i].codigo);
			printf(" descricao: %s", t[i].descricao);
			printf(" preco: %.2f\n", t[i].preco);
			achou1 = true;
			break;
		}
	}
			if(achou1 == false){
				printf("codigo nao encontrado. \n");
			}
}
