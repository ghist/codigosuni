#include <stdio.h>

int main(){
	int num, num2;
	int h, i;
	
	scanf("%d%d", &num, &num2);
	
	for(h = 0; h < num; h++){
		printf("\n");
		printf("*");
		for(i = 1; i < num2; i++){
			printf("*");
		}
	}
	
	return 0;
}
