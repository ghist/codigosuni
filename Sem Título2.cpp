#include <stdio.h>
#include <math.h>


float r;
typedef struct{
	float x1;
	float x2;
	float y1;
	float y2;	
}Ponto;

float Pontodistancia(Ponto p1, Ponto p2){
 float a, b, c, r;
 a = p1.x1 - p2.x2; 
 b = p1.y1 - p2.y2; 
 c = a * a + b * b; 
 r = sqrt(c); 
 printf("Distancia: %2.4f \n", r);
}

int main(){
 	Ponto p1;
 	Ponto p2;
	scanf("%f %f", &p1.x1, &p1.y1);
	scanf("%f %f", &p2.x2, &p2.y2);
 	Pontodistancia(p1, p2);
 	
 	return 0;
}


