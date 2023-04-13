#include<stdio.h>

int elemento[10]{0,1,2,3,4,5,6,7,8,9};
int i;

void Ast (int n){
    for(int i = 0; i < n; i++){
    printf("*");
    }
    printf("\n");
}
	
int main(){
	
	
	printf("elemento    valor    histograma\n");
	
	for(i = 0; i < 10; i++){
		printf("%d            %d           ", elemento[i], (elemento[i]+1)*2);
		Ast((elemento[i]+1)*2);

		
		
	}
}
