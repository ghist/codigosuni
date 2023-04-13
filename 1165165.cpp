#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char engracada(const char * const risada){
    int gatilho = 1;
    int i = 0;
    for(i = 0; i < strlen(risada); i++){

        if(strcmp(&risada[i],"a") || strcmp(&risada[i],"e") || strcmp(&risada[i],"i") || strcmp(&risada[i],"o") || strcmp(&risada[i],"u")){
            if(strcmp(&risada[i+1],"a") || strcmp(&risada[i+1],"e") || strcmp(&risada[i+1],"i") || strcmp(&risada[i+1],"o") || strcmp(&risada[i+1],"u")){
                gatilho = 0;
                break;
            }
        }
    }
    if(gatilho == 0)
        printf("N");
    else
        printf("S");

}
int main()
{
    char risada[50];
    scanf("%s", risada);
    engracada(risada);
    
    return 0;
}

