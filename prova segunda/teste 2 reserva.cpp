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
			fptr = fopen("cadastro.txt", "a");
			bool achou = false;
			printf("codigo, descricao e preco: ");
			scanf("%d", &item[cont].codigo);
			for(int i=0; i<1000;i++){
				if(item[i].codigo==item[cont].codigo && i != cont){
					achou=true;
					printf("Codigo ja cadastrado. \n");
					break;
				}
				
			}
			if(achou==false){
				scanf("%s", &item[cont].descricao);
				scanf("%f", &item[cont].preco);
				fprintf(fptr, "%d %s %f \n", item[cont].codigo, item[cont].descricao, item[cont].preco);
				cont++;
				
			}
			fclose(fptr);
			printf("informe o modulo desejado: ");
		}
		
		if(op == 2){
            int i, codigo;
            char descricao[30];
            float preco;
            int codaux = 849494;
            fptr = fopen("cadastro.txt", "r");
            if(fptr == NULL){
             	printf("Erro na abertura do arquivo! \n");
			}else{
			printf("Arquivo aberto com sucesso!! \n");
            printf("Dados armazenado no Arquivo: \n");
            while(!feof(fptr)){
                fscanf( fptr, "%d%s%f", &codigo, descricao, &preco );
                if(codaux == codigo){
                    ;
                }else{
                    printf( "codigo: %d, descricao, %s, preco: %f\n", codigo, descricao, preco );
                    codaux = codigo;
                }
			}
			}
            fclose(fptr);
            printf("informe o modulo desejado: ");
        }
		
		if(op == 3){
			int i, codigo;
            char descricao[30];
            int cod, gatilho ;
            float preco;
            fptr = fopen("cadastro.txt", "r");
            printf("Digite o codigo do registro: \n");
            scanf("%d", &cod);
            while(!feof(fptr)){
                fscanf( fptr, "%d%s%f", &codigo, descricao, &preco );
                if(cod == codigo){
                    printf( "codigo: %d, descricao, %s, preco: %f\n", codigo, descricao, preco );
                    gatilho = 1;
                    break;
                }
            }
            if(gatilho == 0){
                printf("codigo nao existente!\n");
            }
            fclose(fptr);
            printf("informe o modulo desejado: ");
		}
		
		
		if(op == 5){
			break;
		}
	}
	
	
	return 0;
}
