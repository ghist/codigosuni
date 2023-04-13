#include<stdio.h>

int main(){
	int n1, n2;
	int resto;
	
	scanf("%d%d", &n1,&n2);
	
	while(n2 != 0){
		resto = n1 % n2;
		n1 = n2;
		n2 = resto;
		printf("%d\n", resto);
	}
	printf("mdc = %d", n1);
	return 0;
}
