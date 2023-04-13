#include <stdio.h>

int main(){
	int a, b, c, d;
	int total, totali;
	
	scanf("%d%d%d%d", &a, &b, &c, &d);
	
	if((a > b) && (c > d)){
		total = a + d;
		totali = b * c;
	}if((a > b) && (d > c)){
		total = a + c;
		totali = b * d;
	}if((b > a) && (c > d)){
		total = b + d;
		totali = a * c;
	}if((b > a) && (d > c)){
		total = b + c;
		totali = a * d;
	}
	printf("%d %d", total, totali);
	
	return 0;
}
