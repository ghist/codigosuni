#include<stdio.h>

int elemento[10]{0,1,2,3,4,5,6,7,8,9};
int i;
	
int main(){
	
	
	printf("elemento    valor\n");
	
	for(i = 0; i < 10; i++){
		printf("%d            %d\n", elemento[i], (elemento[i]+1)*2);

		
		
	}
}
