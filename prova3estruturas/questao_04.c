#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//struct com o valor e no para proximo elemento
typedef struct{
	float valor;
	struct no *proximo;	
}No;

//funcao empilhar no que serve para empilhar os caracteres depois de passar pelo tratamento la na funcao 
No *empilhar(No *pilha, float num){

	No *novo = malloc(sizeof(No));
	
	
	if(novo){
		novo->valor = num;
		novo->proximo = pilha;
	
		return novo;	
	}
	
	else{
		printf("Não foi possivel alocar memoria!\n");
	}
	
	return NULL;
}

//funcao que ocorre o desempilhamento, os no proximo vao recebendo valor null, e entao retorna o no auxiliar remove
No *desempilhar(No **pilha){

	No *remove;
	
	remove = NULL;
	
	if(*pilha){
	
		remove = *pilha;
	
		*pilha = remove->proximo;
	}
	else

		printf("Pilha Vazia");

	return remove;
}
//funcao que serve para resolver as operacoes, e passado 3 parametros, onde dois servem para a soma das operacoes e o x como a operacao
float operacao(float a, float b, char x){//é feito a operacao e depois retornada o valor
	

	switch(x){
		
		case '+':
			return a + b;
			break;
		
	
		case '-':
			return a-b;
			break;
		
		case '/':
			return a / b;
			break;
		
		case '*':
			return a * b;
			break;
	
		default:
			return 0.0;
	}
}
//é passado por parametro o vetor de caracteres, sao declarados um ponteiro c do tipo char, um float num e 3 structs do tipo no, sendo pilha null
float resolver_expressao(char x[]){

	char *c;

	float num;

	No *numero_1, *numero_2, *pilha = NULL;
	
	c = strtok(x, " ");//a funcao strtok retorna um ponteiro para a proxima palavra string, que serve para saber os simbolos de operacao

	while(c){//enquanto c tiver é feito o loop
	
		if(c[0] == '+' || c[0] == '-' || c[0] == '/' || c[0] == '*'){//caso seja um dessas operacoes entra no if
			
			numero_1 = desempilhar(&pilha);
			numero_2 = desempilhar(&pilha);
			
			num = operacao(numero_2->valor, numero_1->valor, c[0]);
			pilha = empilhar(pilha, num);
			
			free(numero_1);
			free(numero_2);
		}
	
		else{
		
			num = strtol(c, NULL, 10);//serve para transformar uma string em int
		
			pilha = empilhar(pilha, num);
		}
	
		c = strtok(NULL, " ");
	}

	numero_1 = desempilhar(&pilha);

	num = numero_1->valor;

	free(numero_1);

	return num;	//apos ser feita as chamadas de empilha, desempilha e soma das operacoes, retorna num que é o valor ja exibido em print
}


//funcao main que le a expressao e chama a funcao resolver ja dentro de um print que é impresso o valor de num
int main(){
	
	char exp[50];

	printf("Expressao: ");
	
	gets(exp);

	printf("%2.f\n", resolver_expressao(exp));
	return 0;
}
