#include <stdio.h>
#include <string.h>

int casos(int n){
	for(int i=n; i>0;i--)
    {
    	int aux = 0;
        char vetor [10];
		scanf ("%s", vetor);

        if ( strlen (vetor) == 5 ) printf ("3\n");
        else
        {
            if ( vetor [0] == 'o' ) aux++;
            if ( vetor [1] == 'n' ) aux++;
            if ( vetor [2] == 'e' ) aux++;
			if ( aux >= 2 ) printf ("1 \n");
            else printf ("2 \n");
        }
    }
	
}

int main ()
{
    int caso; 
	scanf ("%d", &caso);
	casos(caso);
	return 0;
}
