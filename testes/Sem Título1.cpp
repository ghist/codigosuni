#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int buscabi(int tama, int* v, int n){
	int ini=0;
	int fim = tama-1;
	int meio;
	int vet[tama];
	
	while(ini <= fim)
	{
		meio = (ini +fim)/2;
		if(n < v[meio]){
			fim = meio-1;
		}else if(n > v[meio]){
			ini = meio+1;
		}else return meio;
	} return -1;
}

int main()
{
	int vet[]={1,2,3,4,5,6,9,10,23,43,99};
	int tama = sizeof (vet)/sizeof(int);
	
	printf("%d \n", buscabi(tama, vet, 99));
	return 0;	
}


