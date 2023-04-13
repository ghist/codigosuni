#include <stdio.h>
 
int main() {
 	int N, M;
    do{
    scanf("%d%d", &N,&M);
	}while(N && M > 40);
	M=N-M;
    printf("%d", M);
	return 0;
}
