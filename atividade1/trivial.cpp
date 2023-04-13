#include <stdio.h>

int main(){
	int n1, n2;
	int resto, aux;
	
	scanf("%d%d", &n1, &n2);
	
	while(n1 != n2){
		if(n1 > n2){
			resto = n1 - n2;
			n1 = resto;
			printf("%d\n", resto);
		}else if(n2 > n1){
			aux = n1;
			n1 = n2;
			n2 = aux;
			
		}
		
		
	}
	
	return 0;
}
