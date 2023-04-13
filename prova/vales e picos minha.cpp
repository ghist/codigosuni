#include <stdio.h>

int tipoPaisagem( int padrao[], int tamanho ){
	int i;
	int bsf = 1;
	for(i=0; i<tamanho; i++)
        scanf("%d", &padrao[i]);
    if(tamanho==2 && padrao[0]==padrao[1]) bsf = 0;
    else
    {
        for(i=2; i<tamanho; i++)
        {
            if(padrao[i] >= padrao[i-1] && padrao[i-1] >= padrao[i-2])
            {
                bsf = 0;
                break;
            }
            else if(padrao[i] <= padrao[i-1] && padrao[i-1] <= padrao[i-2])
            {
                bsf = 0;
                break;
            }
        }
    }
    
    printf((bsf==1)?"1\n":"0\n");
	
}

int main(){
	int N;
	scanf("%d", &N);
	int aux[N];
	
	tipoPaisagem(aux, N);
	
	
	
}
