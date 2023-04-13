#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int codigo;
	char descricao[30];
	float preco;
}produto;

produto item[1000];

FILE *fptr;

int main(){
	
	int op;
	int cont = 0;
	
	printf(" 1-cadastro\n 2-visualizar\n 3-visualizar um registro\n 4-ordenar por preco\n 5-finalizar\n informe o modulo desejado: ");
	
	while(true){
		scanf("%d", &op);
		if(op == 1){
			fptr = fopen("cadastro.txt", "w");
			bool achou = false;			
			for(int i=0; i<1000;i++){
				printf("Codigo, descricao, preco: ");
				scanf("%d %s %f", &item[cont].codigo, &item[cont].descricao, &item[cont].preco);
				cont++;				
				if(item[i].codigo==item[cont].codigo){
					achou=true;
					printf("Codigo ja cadastrado. \n");
					break;
				}
				fprintf(fptr, "%d %s %f \n", item[cont].codigo, item[cont].descricao, item[cont].preco);
				
			}
			fclose(fptr);
			printf("informe o modulo desejado: ");
		}
		
		if(op == 2){
			for(int i = 0; i < cont; i++){
				printf("codigo: %d", item[i].codigo);
				printf(" descricao: %s", item[i].descricao);
				printf(" preco: %.2f\n", item[i].preco);
				
			}
			printf("informe o modulo desejado: ");
		}
		
		if(op == 3){
			int x;
			bool achou1 = false;
			printf("digite o arquivo a ser buscado: ");
			scanf("%d", &x);
			for(int i = 0; i < 1000; i++){
				if(item[i].codigo == x){
					printf("codigo: %d", item[i].codigo);
					printf(" descricao: %s", item[i].descricao);
					printf(" preco: %.2f\n", item[i].preco);
					achou1 = true;
					break;
				}
			}
			if(achou1 == false){
				printf("codigo nao encontrado. \n");
			}
			printf("informe o modulo desejado: ");
		}
		
		if(op == 5){
			break;
		}
	}
	
	
	return 0;
}
