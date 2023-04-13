#include <stdio.h>
#include <math.h>

void raizes(float a, float b, float c, float *x1, float *x2){
	float d;
	if(a != 0){
		d = b*b - 4*a*c;
		if(d == 0){
			*x1 = (-b + sqrt(d))/(2*a);
			printf("%.1f %.1f\n", *x1, *x1);
		}else{
			if(d > 0){
				*x1 = (-b + sqrt(d))/(2*a);
    			*x2 = (-b - sqrt(d))/(2*a);
    			printf("%.1f %.1f\n", *x1, *x2);
			}else{
				printf("complexo");
			}
		}
	}
    
}

int main(){
	float n1, n2, n3, r1 = 0, r2 = 0, di;
	
	do{
		scanf("%f %f %f", &n1, &n2, &n3 );
		raizes(n1, n2, n3, &r1, &r2);
		di = n1;
	}while(di != 0);
	
	return 0;
}
