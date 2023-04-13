#include <stdio.h>
 
int main() {
    int n1,n2,n3,n4,n5,t;
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    scanf("%d",&n4);
    scanf("%d",&n5);
    n1 = n1*300;
    n2 = n2*1500;
    n3 = n3*600;
    n4 = n4*1000;
    n5 = n5*150;
    t = n1+n2+n3+n4+n5+225;
    printf("%d", t);
    
 
    return 0;
}
