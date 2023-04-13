#include<stdio.h>

int main(void){
	FILE *file;
	file = fopen("numeros.txt", "w");
	fprintf(file,"10 20 30");
	fclose(file);
	
	return 0;
}
