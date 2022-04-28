#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void codificar(char *nome_vetor, char *nome_vetor2, int tamanho_vetor);
void decodificar(char *nome_vetor3, char *nome_vetor4, int tamanho_vetor2);

int main()
{
	char nome_vetor[50];
	char nome_vetor2[50];
	char nome_vetor3[50];
	char nome_vetor4[50];
	int tamanho_vetor;
	int tamanho_vetor2;
	char *imprimir_nome;
	
	printf("Frase codificar: ");
	gets(nome_vetor);
	tamanho_vetor = strlen(nome_vetor);
	
	codificar(nome_vetor, nome_vetor2, tamanho_vetor);
	
	imprimir_nome = nome_vetor2;
	
	for(int i = 0; i < tamanho_vetor; i++){
		printf("%c", *imprimir_nome);
		imprimir_nome++;
	}
	
	printf("\n");
	
	printf("Frase decodificar: ");
	gets(nome_vetor3);
	tamanho_vetor2 = strlen(nome_vetor3);
	
	decodificar(nome_vetor3, nome_vetor4, tamanho_vetor2);
	
	imprimir_nome = nome_vetor4;
	
	for(int i = 0; i < tamanho_vetor2; i++){
		printf("%c", *imprimir_nome);
		imprimir_nome++;
	}
}

void codificar(char *nome_vetor,char *nome_vetor2, int tamanho_vetor){
	
	
	
	for(int i = 0; i < tamanho_vetor; i++){
		
		if(*nome_vetor == 'a'){
			*nome_vetor2 = 'z';
		}else if(*nome_vetor == 'b'){
			*nome_vetor2 = 'a';
		}else if(*nome_vetor == 'c'){
			*nome_vetor2 = 'b';
		}else if(*nome_vetor == 'd'){
			*nome_vetor2 = 'c';
		}else if(*nome_vetor == 'e'){
			*nome_vetor2 = 'd';
		}else if(*nome_vetor == 'f'){
			*nome_vetor2 = 'e';
		}else if(*nome_vetor == 'g'){
			*nome_vetor2 = 'f';
		}else if(*nome_vetor == 'h'){
			*nome_vetor2 = 'g';
		}else if(*nome_vetor == 'i'){
			*nome_vetor2 = 'h';
		}else if(*nome_vetor == 'j'){
			*nome_vetor2 = 'i';
		}else if(*nome_vetor == 'k'){
			*nome_vetor2 = 'j';
		}else if(*nome_vetor == 'l'){
			*nome_vetor2 = 'k';
		}else if(*nome_vetor == 'm'){
			*nome_vetor2 = 'l';
		}else if(*nome_vetor == 'n'){
			*nome_vetor2 = 'm';
		}else if(*nome_vetor == 'o'){
			*nome_vetor2 = 'n';
		}else if(*nome_vetor == 'p'){
			*nome_vetor2 = 'o';
		}else if(*nome_vetor == 'q'){
			*nome_vetor2 = 'p';
		}else if(*nome_vetor == 'r'){
			*nome_vetor2 = 'q';
		}else if(*nome_vetor == 's'){
			*nome_vetor2 = 'r';
		}else if(*nome_vetor == 't'){
			*nome_vetor2 = 's';
		}else if(*nome_vetor == 'u'){
			*nome_vetor2 = 't';
		}else if(*nome_vetor == 'v'){
			*nome_vetor2 = 'u';
		}else if(*nome_vetor == 'x'){
			*nome_vetor2 = 'v';
		}else if(*nome_vetor == 'w'){
			*nome_vetor2 = 'x';
		}else if(*nome_vetor == 'y'){
			*nome_vetor2 = 'w';
		}else if(*nome_vetor == 'z'){
			*nome_vetor2 = 'y';
		}else if(*nome_vetor == '\0'){
	 		*nome_vetor2 = ' ';
	 	}
		nome_vetor++;
		nome_vetor2++;
	}
}

void decodificar(char *nome_vetor3,char *nome_vetor4, int tamanho_vetor2){
	
	
	
	for(int i = 0; i < tamanho_vetor2; i++){
		
		if(*nome_vetor3 == 'z'){
			*nome_vetor4 = 'a';
		}else if(*nome_vetor3 == 'a'){
			*nome_vetor4 = 'b';
		}else if(*nome_vetor3 == 'b'){
			*nome_vetor4 = 'c';
		}else if(*nome_vetor3 == 'c'){
			*nome_vetor4 = 'd';
		}else if(*nome_vetor3 == 'd'){
			*nome_vetor4 = 'e';
		}else if(*nome_vetor3 == 'e'){
			*nome_vetor4 = 'f';
		}else if(*nome_vetor3 == 'f'){
			*nome_vetor4 = 'g';
		}else if(*nome_vetor3 == 'g'){
			*nome_vetor4 = 'h';
		}else if(*nome_vetor3 == 'h'){
			*nome_vetor4 = 'i';
		}else if(*nome_vetor3 == 'i'){
			*nome_vetor4 = 'j';
		}else if(*nome_vetor3 == 'j'){
			*nome_vetor4 = 'k';
		}else if(*nome_vetor3 == 'k'){
			*nome_vetor4 = 'l';
		}else if(*nome_vetor3 == 'l'){
			*nome_vetor4 = 'm';
		}else if(*nome_vetor3 == 'm'){
			*nome_vetor4 = 'n';
		}else if(*nome_vetor3 == 'n'){
			*nome_vetor4 = 'o';
		}else if(*nome_vetor3 == 'o'){
			*nome_vetor4 = 'p';
		}else if(*nome_vetor3 == 'p'){
			*nome_vetor4 = 'q';
		}else if(*nome_vetor3 == 'q'){
			*nome_vetor4 = 'r';
		}else if(*nome_vetor3 == 'r'){
			*nome_vetor4 = 's';
		}else if(*nome_vetor3 == 's'){
			*nome_vetor4 = 't';
		}else if(*nome_vetor3 == 't'){
			*nome_vetor4 = 'u';
		}else if(*nome_vetor3 == 'u'){
			*nome_vetor4 = 'v';
		}else if(*nome_vetor3 == 'v'){
			*nome_vetor4 = 'x';
		}else if(*nome_vetor3 == 'x'){
			*nome_vetor4 = 'w';
		}else if(*nome_vetor3 == 'w'){
			*nome_vetor4 = 'y';
		}else if(*nome_vetor3 == 'y'){
			*nome_vetor4 = 'z';
		}else if(*nome_vetor3 == '\0'){
	 		*nome_vetor4 = ' ';
	 	}
		nome_vetor3++;
		nome_vetor4++;
	}
}

