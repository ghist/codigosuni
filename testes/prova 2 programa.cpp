#include <stdio.h>
#include <stdlib.h>

int main(){
	int n, cont = 0, aux, codigo2, i=0;
	int codigo[1000];
	float preco[1000];
	char descricao[1000][30];
	int gatilho=0, auxi = 0;
	
	printf("1-cadastrar\n2-visualizar\n3-visualizar um registro\n4-ordenar por preco\n5-finalizar\ninforme o modulo desejado: ");
	
	for(i = 0; i < 1000 ; i++){
		codigo[i]=0;
	}
	
	
	
	do{
		scanf("%d", &n);
		switch(n){
		case 1:
		printf("codigo: ");
		scanf("%d", &codigo2);
		for(aux = 0; aux < 1000; aux++){
			if (codigo[aux] == codigo2){
				gatilho=1;
				break;
			 }if (codigo[aux] == 0){
			 	auxi = aux;
			 	break;
			 }
		}
		if(gatilho == 0){
			codigo[auxi] = codigo2;
                printf("descricao: ");
                scanf("%s", &descricao[i]);
                i++;
                printf("preco: ");
                scanf("%f", &preco);
                printf("\ninforme o modulo desejado: ");
                auxi=0;
				gatilho=0;
                break;
		}else{
			printf("ja cadastrado");
			printf("\ninforme o modulo desejado: ");
			auxi=0;
			gatilho=0;
			break;
		} 
		
		auxi=0;
		gatilho=0;
		
		case 2:
			for(i = 0; i < 1000; i++){
				printf("%d,%s,%0.2f\n", codigo[i], descricao[i], preco[i]);
			}
			break;
			
		case 5:
		break;
		}
		
	}while(n!=5);
	
	
	
	return 0;			
	
}
