#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char cart[52][30];

const struct{
	char valor[13][10];
	char naipe[4][10];
}cartas ={{"As", "Dois", "Tres", "Quatro", "Cinco", "Seis", 
"Sete", "Oito", "Nove", "Dez", "Valete", "Dama", "Rei"},{"Paus", "Ouros", "Copas", "Espadas"}};

void impr();
void aleat();

int main(){
	int n;
	scanf("%d", &n);
	if(n==1){
		impr();
	}else if(n==0){
		aleat();
	}
	return 0;
}

void impr(){
	int k, l, cont=0;
	for(k=0; k<4; k++){
		for(l=0; l<=12; l++){
			strcpy(cart[cont], cartas.valor[l]);
			strcat(cart[cont], cartas.naipe[k]);
			printf("%s de %s \n", cartas.valor[l], cartas.naipe[k]);
		}
	}
	printf("\n");
}

void aleat(){
	int x, y, m;
	srand (time(NULL));
	for(m=0; m<52; m++){
		x=rand()%13;
		y=rand()%4;
		if(cartas.valor[x]!=cartas.valor[x-1])
		printf("%s de %s \n", cartas.valor[x], cartas.naipe[y]);
	}
	printf("\n");
}

