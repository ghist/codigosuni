#include <stdio.h>

int main(){
	
	int 
	frequencia[10];
	int i = 0, voto;
	
	while(i < 10){
		
		frequencia[i] = 0;
		i++;
	}
	
	for(i = 0; i < 40; i++){
		scanf("%d", &voto);
		if(voto == -1) break;
		
		frequencia[voto-1] = 1+frequencia[voto -1];
	}
	
	for(i = 0; i < 10; i++){
        printf("%d ", i+1);
        printf("%d \n", frequencia[i]);
    }
    
	
	return 0;
	
}
