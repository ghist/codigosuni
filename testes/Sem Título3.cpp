#include<stdio.h>
#include<stdlib.h>

int main(void){
	FILE *file;
	file = fopen("numeros.txt", "r");
	
	if(file == NULL){
		printf("O arquivo nao pode ser aberto. ");
		return 0;
	}
	
	int x, y, z;
	fscanf(file, "%i %i %i", &x, &y, &z);
	printf("%i %i %i", x, y, z);
	fclose(file);
	return 0;
}
