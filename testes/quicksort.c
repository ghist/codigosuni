#include <stdio.h>
#include <string.h>

#define swap( _a, _b ) do{ int _tmp = _a; _a = _b; _b = _tmp; } while(0)

void quicksort( int array[], int start, int end )
{
    if( start < end )
    {
        int l = start + 1;
        int r = end;
        int p = array[start];

        while( l < r )
        {
            if( array[l] <= p )
            {
                l++;
            }
            else if( array[r] >= p )
            {
                r--;
            }
            else
            {
                swap( array[l], array[r] );
            }
        }

        if( array[l] < p )
        {
            swap( array[l], array[start] );
            l--;
        }
        else
        {
            l--;
            swap( array[l], array[start] );
        }

        quicksort( array, start, l );
        quicksort( array, r, end );
    }
}

void exibir( int array[], int tam )
{
    int i = 0;

    for( i = 0; i < tam; i++ )
        printf( "%s%d", (i>0)?", ":"", array[i] );

    printf("\n");
}


int main( int argc, char * argv[] )
{
    int numeros[16] = { 6, -9, 7, 5, 3, -1, 8, -6, 4, 2, 1, -3, -5, 9, -8, 0 };
    int numeros2 [16] = { 6, -9, 7, 5, 3, -1, 8, -6, 4, 2, 1, -3, -5, 9, 2, 55 };

    printf("Array Original: ");
    exibir( numeros, 16 );

    quicksort( numeros, 0, 16 );

    printf("Array Ordenada: ");
    exibir( numeros, 16 );
    
    printf("Array Original: ");
    exibir( numeros2, 16 );

    quicksort( numeros2, 0, 16 );

    printf("Array Ordenada: ");
    exibir( numeros2, 16 );
    
    
    

    return 0;
}
