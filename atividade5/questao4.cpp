#include <stdio.h>

void somaComplexo( float rz1, float iz1, float rz2, float iz2, float *rz3, float *iz3){
	*rz3 = rz1 + rz2;
	*iz3 = iz1 + iz2;
	
	if(*iz3 < 0) printf("%.1f %.1f", *rz3, *iz3);
	if(*rz3 && *iz3 > 0){
		printf("%.1f + %.1fi", *rz3, *iz3);
	}
}

int main(){
	float nr1, ni1, nr2, ni2, nr3 = 0, ni3 = 0;
	
	scanf("%f %f %f %f",&nr1, &ni1, &nr2, &ni2);
	somaComplexo(nr1, ni1, nr2, ni2, &nr3, &ni3);
	
}
