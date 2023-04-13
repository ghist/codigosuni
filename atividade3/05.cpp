#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void jogo(){
	int tent, aux, i = 0;
	srand(time(NULL));
	
	aux = rand() % 1000+1;
	
	printf("%d", aux);
	
	do{
		scanf("%d", &tent);
		if(tent >= 1 && tent <= 1000){
	 		if(tent < aux){
	 			printf("Muito baixo. Tente novamente. \n");
	 			i++;
			} 
	 		if(tent > aux){
				printf("Muito alto. Tente novamente.\n");
				i++;
			}
			if(tent == aux){
				i++;
				printf("Excelente! Voce adivinhou o numero!\n");
				printf("foram necessarias %d tentativas.", i);
			} 
		}
	}while(tent != aux);
}

int main(){
	
	printf("Eu tenho um numero entre 1 e 1000.\n");
	printf("Voce pode adivinhar meu numero?\n");
	printf("Digite seu primeiro palpite:");
	
	
	jogo();
	
	return 0;
}
