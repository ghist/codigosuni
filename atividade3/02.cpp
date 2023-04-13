#include <stdio.h>.
#include<math.h>

float pontos(float x1, float y1, float x2, float y2){
	return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main(){
	float x1, y1, x2, y2;
	
	scanf("%f %f", &x1, &y1);
	scanf("%f %f", &x2, &y2);
	
	printf("%f", pontos(x1,y1,x2,y2));
	
	return 0;
}
