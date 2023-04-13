#include <stdio.h>

void cubo(int *nPtr){
	*nPtr=(*nPtr)*(*nPtr)*(*nPtr);
}

int main(){
	int n;
	printf("Entrada:         Saida: \n");
	do{
		scanf("%d",&n);
		if(n > 0){
		cubo(&n);
		printf("                 %i \n", n);
		}
		
	}while(n > 0);
}
