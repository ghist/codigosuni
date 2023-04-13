#include<stdio.h>
#include<string.h>

char engracada(const char * const risada){
	
	char y[50];
	int i, j=0, lnth;
	for(i=0; risada[i]; i++)
    {
        if(risada[i]=='a' || risada[i]=='e' || risada[i]=='i' || risada[i]=='o' || risada[i]=='u')
        {
            y[j] = risada[i];
            j++;
        }
    }
    y[j] = '\0';
    lnth = strlen(y);
    for(i=0, j=lnth-1; i < lnth; i++, j--)
    {
        if(y[i] != y[j])
        {
            printf("N\n");
            return 0;
        }
    }
    printf("S\n");
}

int main()
{
    char x[50];
    scanf("%s", x);
    engracada(x);
    return 0;
}
