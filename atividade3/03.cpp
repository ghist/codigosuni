#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void moeda(){
	int cara, coroa;
	int i, j = 0;
	int aux;
	srand(time(NULL));
	
	for(i = 0; i < 100; i++){
		aux = rand() % 2;
		if(aux == 0) printf("coroa \n");
		if(aux == 1){
			printf("cara \n");
			j++;
		}
	}
	
	printf("%d", j);
	
}

int main(){
	
	moeda();
	
	return 0;
}
