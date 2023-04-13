#include <stdio.h>.
#include<math.h>

struct distancia{
	float x, y;
};

float pontos(float x1, float y1, float x2, float y2){
	return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int main(){
	
	struct distancia p[2];
	
	scanf("%f%f", &p[0].x, &p[0].y);
	scanf("%f%f", &p[1].x, &p[1].y);
	
	printf("Distancia: %0.4f", pontos(p[0].x, p[0].y, p[1].x, p[1].y));
	
	return 0;
}
