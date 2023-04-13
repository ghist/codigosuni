#include <stdio.h>

int main() {
 
    int X, aux, i;
 
    scanf("%d", &X);
    
    for(i=X; i<X+12; i++){
        aux = i;
        if(aux%2==1) printf("%d\n", aux);
    }
	
	return 0;
}
