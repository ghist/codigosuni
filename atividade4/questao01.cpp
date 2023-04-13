#include <stdio.h>
#include <string.h>

struct estudantes{
	char nome [20];
	float peso, altura, ira;
};

int main(){
	float mediap, mediai, mediaa;
	float maiorp = 0, maiori = 0, maiora = 0;
	char nomea[20], nomep[20], nomei[20];
	int i;
	struct estudantes e1[5];
	
	for(i = 0; i < 5; i++){
		scanf("%s", &e1[i].nome);
		scanf("%f", &e1[i].altura);
		scanf("%f", &e1[i].peso);
		scanf("%f", &e1[i].ira);
		
		mediaa = mediaa + e1[i].altura;
		mediap = mediap + e1[i].peso;
		mediai = mediai + e1[i].ira;
		
		if(e1[i].altura > maiora){
			maiora = e1[i].altura;
			strcpy (nomea, e1[i].nome);
		}
		if(e1[i].peso > maiorp){
			maiorp = e1[i].peso;
			strcpy (nomep, e1[i].nome);
		}
		if(e1[i].ira > maiori){
			maiori = e1[i].ira;
			strcpy (nomei, e1[i].nome);
		}
		
	}
	
	mediaa = mediaa/5;
	mediap = mediap/5;
	mediai = mediai/5; 
	
	printf("Media de peso: %0.3f \n", mediap);
	printf("Media de altura: %0.3f \n", mediaa);
	printf("Media de IRA: %0.3f \n", mediai);
	printf("\n");
	printf("Maior peso: %s (%0.3f) \n", nomep, maiorp);
	printf("Maior altura: %s (%0.3f) \n", nomea, maiora);
	printf("Maior CRA: %s (%0.3f) \n", nomei, maiori);
	printf("\n");
	
	return 0;
}

