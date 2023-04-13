#include <stdio.h>
#include <stdlib.h>
//define o tamanho MAX, usado para limite de jogadores cadastrados
#define MAX 2

//Estrutura de dados dos jogadores
struct jogador_de_futebol{
	char nome[20];
	int jogos;
	int gols;
	int assistencias;
};

//Aqui defino Jogador tipo
typedef struct jogador_de_futebol Jogador;
//a funcao atribui de forma dinamica os dados dos jogadores, e recebe como parametro o total de jogadores e um ponteiro para ponteiro
void Atribui(int t, Jogador **jog){
	int i;
	printf("Atribui \n");
	//For responsavel por atribuir os dados dos jogadores até o limite 
	for(i=0; i<t; i++){	
		//aloca a memoria para cada jogador jog[i], e logo apos vou armazenando os dados
		jog[i] = (Jogador*) malloc(sizeof(Jogador));
		//onde é feito o salvvamento dos dados inseridos pelo usuario sobre os jogadores
		printf("Jogador Camisa [%d] \n", i);
		printf("Nome: ");
		scanf("%s", &jog[i]->nome);
		printf("Jogos: ");
		scanf("%d", &jog[i]->jogos);
		printf("Gols: ");
		scanf("%d", &jog[i]->gols);
		printf("Assistencias: ");
		scanf("%d", &jog[i]->assistencias);
		//dou um \n para saltar uma linha
		printf("\n");
	}
	
}

//minha função chamada imprime recebe o total de jogadores e recebe um ponteiro para ponteiro **jog, onde a variavel c armazena a posicao do jogador de 0 ate max
//e depois pede o numero da camisa do jogador para ser buscado
void Imprime(int t, Jogador **jog){

	int c;
	printf("Imprime \n");
	printf("Buscar Jogador Camisa: ");
	scanf("%d", &c);
	
	//se o numero digitado pelo usuario for maior que 0 e menor que t. entra no if e é feita a busca, caso nao atenda a condicao, entra no else
	if(c > 0 || c < t){
		//for busca a posição do jogador
		for(int i=0; i<t; i++){
			//caso c seja igual a alguma posição do meu vetor de jogadores o printf abaixo sera mostrado
			if(c == i){
				printf("Jogador Camisa [%d] \n", c);
				printf("Nome: %s\n Jogos: %d\n Gols: %d\n Assistencias: %d\n", jog[i]->nome, jog[i]->jogos, jog[i]->gols, jog[i]->assistencias);	
			}
		}	
	}else{
		printf("Jogador não Existe, so existem %d jogadores", MAX);
	}
}

//função soma que recebe o tamanho MAX(t=MAX) e um ponteiro para ponteiro **jog, e que tem duas variaveis para armazenar a posicao dos dois jogadores que vai ser feita a soma dos atributos
void soma(int t, Jogador **jog){
	
	int a, b, soma = 0;
	printf("Soma \n");
	printf("Jogador A: ");
	scanf("%d", &a);
	printf("Jogador B: ");
	scanf("%d", &b);
	//confirmo que a e b são maiores que 0 e menores que MAX
	if(a > 0 || a < t || b > 0 || b < t){
		soma = jog[a]->assistencias + jog[b]->assistencias;
		
		printf("A soma dos jogadores e: %d", soma);	
	}else{//caso nao sejam, exibe msg de erro
		printf("Jogador não Existe, so existem %d jogadores", MAX);
	}
	
}

//Função Ehbom que recebe o t = MAX e um ponteiro para ponteiro, a funcao define se é bom caso o numero de gols seja maior que os de jogos
void Ehbom(int t, Jogador **jog){
	//variavel que ira armazenar a posição do jogador
	int c;
	printf("EhBom \n");
	//Peço a pisção do jogador para o usuario e salvo na variavel &c
	printf("Buscar Jogador Camisa: ");
	scanf("%d", &c);
	//Confirmo se c e maior que 0 e menor que MAX
	if(c > 0 || c < t){
		
		if(jog[c]->gols > jog[c]->jogos){//caso os gols sejam maior que os jogos, entra no if, se nao, entra no else, caso o jogador nao exista, aparece msg de erro
		
			printf("O jogador %d que se chama %s, Eh bom", c, jog[c]->nome);
		}else{
			printf("O jogador %d que se chama %s, Nao e muito bom", c, jog[c]->nome);
		}
	}else{
		printf("Jogador não Existe, so existem %d jogadores", MAX);
	}
	
}

//Função sera responsavel por liberar uma posição de jogadores, ela recebe t e um ponteiro para ponteiro
void Libera(int t, Jogador **jog){
	int c;
	printf("Libera \n");
	//pergunto ao usuario qual indice ele vai querer liberar
	printf("Liberar qual jogador: ");
	scanf("%d", &c);
	//se for maior que 0 e menor que max entra no if
	if(c > 0 || c < t){
		free(jog[c]);
		jog[c] = NULL;
	}
}



int main(){//a funcao main sera responsavel pelas declaracoes de variaveis e chamadda das funcoes atraves de switchcase, se digitado 6, sai do prog
	int i = 1, op, t = MAX;
	//Aqui declaro um ponteiro para vetor com tamanho MAX
	Jogador *jog[MAX];
	
	
	printf("1- Atribui \n");
	printf("2- Imprime \n");
	printf("3- Soma \n");
	printf("4- EhBom \n");
	printf("5- Libera \n");
	printf("6- Sair \n");
	
	while(i != 0){
		printf("\n");
		printf("Opcao: ");
		scanf("%d", &op);
		switch(op){
			
			case 1:
				Atribui(t, jog);
				break;
			
			case 2:
				Imprime(t, jog);
				break;
			
			case 3:
				soma(t, jog);
				break;
			
			case 4:
				Ehbom(t, jog);
				break;
			
			case 5:
				Libera(t, jog);
				break;
			
			case 6:
				i = 0;
				break;
			//caso não seja nenhuma das opções de 1 a 6 entra no meu default
			default:
				printf("Valor invalido \n");
		}
	}
	return 0;
}

