#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void craps(){
	int dado1, dado2, ponto, i = 1, aux, j = 0;
	srand(time(NULL));
	
	do{
		dado1 = rand() % 6 + 1;
		dado2 = rand() % 6 + 1;
		aux = dado1 + dado2;
	
		printf("Soma dos dados %d + %d = %d \n", dado1, dado2, aux);
	
		if(aux==7 && aux==11 && i==1){
			printf("O jogador ganhou :) \n");
			j = 1;
			i = 2;
		}
		if(aux==2 && aux==3 && aux==12 && i==1){
			printf("O jogador perdeu :( \n");
			j = 1;
			i = 2;
		}if(aux==4 && aux==5 && aux==6 && aux==8 && aux==9 && aux==10 && i==1){
			printf("O ponto e %d \n", aux);
			ponto = aux;
			i = 2;
		}
		if(aux==ponto && i!=1){
			printf("O jogador ganhou :) ");
			j = 1;
		}else(aux==7 && i!=1);{
			printf("O jogador perdeu :( ");
			j = 1;
		}
	}while(j==1);
}

int main(){
	
	craps();
	
	return 0;
}
