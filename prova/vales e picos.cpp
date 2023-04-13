#include <stdio.h>

int main()
{
    int n, i, bsf = 1;
    scanf("%d", &n);
    int aux[n];
    for(i=0; i<n; i++)
        scanf("%d", &aux[i]);
    if(n==2 && aux[0]==aux[1]) bsf = 0;
    else
    {
        for(i=2; i<n; i++)
        {
            if(aux[i] >= aux[i-1] && aux[i-1] >= aux[i-2])
            {
                bsf = 0;
                break;
            }
            else if(aux[i] <= aux[i-1] && aux[i-1] <= aux[i-2])
            {
                bsf = 0;
                break;
            }
        }
    }
    
    printf((bsf==1)?"1\n":"0\n");
    return 0;
}
