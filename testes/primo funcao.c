#include<stdio.h>
#include<stdlib.h>

int primo(int m, int* maior, int* menor);

int main(){
	int m;
	int *p1;
	int *p2;
	
	p1 = (int *) malloc(sizeof(int));
	p2 = (int *) malloc(sizeof(int));
	
	p1 = 0;
	p2 = 0;
	
	scanf("%d", &m);
	
	primo(m, &p1, &p2);
	
	printf("%d \n", p1);
	printf("%d \n", p2);
	
}

int primo(int m, int *maior, int *menor){
	int count = 0;
	int count2 = 0;
	
	for(int i = 1; i < m; i++){
		for(int j = 1; j <= i; j++ ){
			if(i%j == 0){
				count++;
			}
			
		}
		
		if((*maior <= m) && (count == 2)){
				*maior = i;
			}
		
		count = 0;
	}	
	
	for(int i = m; i < m + (m/2); i++){
		for(int j = 1; j <= i; j++ ){
			if(i%j == 0){
				count2++;
			}
			
		}
		
		if((*menor <= m) && (count2 == 2)){
				*menor = i;
			}
		
		count2 = 0;
	}
	
}
