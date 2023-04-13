#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
void main()
{
    int i, TamStr;
    char Str[30];
    scanf("%s", Str);
    TamStr = strlen(Str);
    for(i=0; i<TamStr; i++)
    {                            // Converte cada caracter de Str
     Str[i] = toupper (Str[i]);  // para maiusculas
    }
    for(i = 0; i<TamStr; i++){
        printf("%c ",Str[i]);
    }
    getch();
}
