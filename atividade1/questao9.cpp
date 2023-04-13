#include <stdio.h>

int main(){
	int num, num2;
	int j, i;
	
	scanf("%d%d", &num, &num2);
	
	for(i = 0; i < num; i++){
		printf("\n");
		for(j = 0; j < num2; j++){
		    if(i == 0 || j == 0 || i == num - 1 || j == num2 - 1){
			    printf("*");
		    }else{
		        printf(" ");
		    }
		}
	}
	
	return 0;
}
