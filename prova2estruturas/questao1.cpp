#include<stdio.h>
#include<stdlib.h>
#define MAX 2 //esse define foi usado para facilitar a quantidade de disciplinas e cursos armazenados

int auxi = 0;//variaveis globais, sao importantes pois assumem o papel de um contador
int auxi2 = 0;//e para nao serem resetadas sempre, coloquei para inicializarem com 0

struct  curso{//struct do curso com as variaveis
	int codcurso;
	char nomecurso[30];
	int periodos;
	int carga;
	char turno[10];
	
};
typedef struct curso Curso;//typedef e a criacao do vetor de struct curso
Curso tab[MAX];

struct disciplina{//mesma coisa da declaracao de curso, so que com os dados da disciplina
	int coddisc;
	int codcurso2;
	char nomedisc[30];
	int periodo;
	int cargadisc;
};
typedef struct disciplina Disciplina;
Disciplina tab1[MAX];

int cadastrarcurso();//todas as declaracoes das funcoes, sao muitas
int cadastrardisciplina();
int mostrarcurso(int x);
int mostrardisciplina(int x);
int disciplinacurso(int x);
void insertionSortCodigo(Curso *V, int N);
void insertionSortDisciplina(Disciplina *V, int N);
int buscaBinariaDisciplina(Disciplina *V, int N, int elem);
int buscaBinariaCurso(Curso *V, int N, int elem);
int disciplinasperiodo(int x, int y);

int main(){//na funcao main contem a declaracao de variaveis e o menu interativo
	int n;//que é a base de um while, que usa como parametro ser diferente de 0, saco queira sair do menu
	int cdcurso;//só digitar 0, é usado ifs, para fazer a leitura da variavem n que é o parametro dos if
	int busca;//e entao entra em cada condicao assim chamando as funcoes de cada opcao
	int pe;
	
	do{	
		printf("MENU \n");
		printf("1 - Cadastrar curso! \n");
		printf("2 - Cadastrar disciplina! \n");
		printf("3 - Mostrar curso! \n");
		printf("4 - Mostrar disciplina! \n");
		printf("5 - Listar curso por turno! \n");
		printf("6 - Disciplinas de um curso! \n");
		printf("7 - Disciplinas de um periodo! \n");
		scanf("%d", &n);
		if(n == 1){
			cadastrarcurso();
		}
		if(n == 2){
			cadastrardisciplina();
		}
		if(n == 3){
			printf("Codigo do curso: ");
			scanf("%i", &cdcurso);
			busca = buscaBinariaCurso(tab, MAX, cdcurso);
			mostrarcurso(busca);
		}
		if(n == 4){
			printf("Codigo da disciplina: ");
			scanf("%i", &cdcurso);
			busca = buscaBinariaDisciplina(tab1, 3, cdcurso);
			mostrardisciplina(busca);
		}
		if(n == 6){
			printf("Informe o codigo do curso: ");
			scanf("%i", &cdcurso);
			disciplinacurso(cdcurso);			
		}
		if(n == 7){
			printf("Informe o codigo do curso e o periodo: ");
			scanf("%i%i", &cdcurso, &pe);
			disciplinasperiodo(cdcurso, pe);
			
			
		}
		
	}while(n != 0);
	
	return 0;
}

int cadastrarcurso(){//a funcao cadastrar usa um if, enquanto o vetor estiver vazio, é possivel fazer o cadastro, caso nao, exibe uma mensagem
	if(auxi < MAX){//o auxi como citei antes, serve como um contador para armazenamento e tambem para parametro da ordenacaao que é chamada depois de inserir os dados
		printf("Curso dados: \n");
		printf("Codigo:");
		scanf("%i", &tab[auxi].codcurso);
		printf("Nome: ");
		scanf("%s", &tab[auxi].nomecurso);
		printf("Quantidade Periodos:");
		scanf("%i", &tab[auxi].periodos);
		printf("Carga horaria total:");
		scanf("%i", &tab[auxi].carga);
		printf("Turno:");
		scanf("%s", &tab[auxi].turno);
		auxi += 1;
		insertionSortCodigo(tab, auxi);
	}else{
		printf("Não é mais possivel cadastrar!");
	}
}

int cadastrardisciplina(){//cadastrar disciplina funciona do mesmo jeito que curso, com o mesmo if e tambem a ordenacao apos o cadastro, assim sempre que for cadastrado
	if(auxi2 < 3){//é feito a ordenacao
		printf("Discpila dados: \n");
		printf("Codigo:");
		scanf("%i", &tab1[auxi2].coddisc);
		printf("Codigo do curso:");
		scanf("%i", &tab1[auxi2].codcurso2);
		printf("Nome:");
		scanf("%s", &tab1[auxi2].nomedisc);
		printf("Periodo:");
		scanf("%i", &tab1[auxi2].periodo);
		printf("Carga horaria:");
		scanf("%i", &tab1[auxi2].cargadisc);
		auxi2 += 1;
		insertionSortDisciplina(tab1, auxi2);
	}else{
		printf("Não é mais possivel cadastrar!");
	}
}

int mostrarcurso(int x){//mostrar curso e mostrar disciplina funcionam da mesma maneira, é dado o codigo do curso, entao entra na funcao da busca binaria
	if(x == -1){//apos feita a busca, se for encontrado, retorna o indice da posicao e entra na funcao que exibe os dados daquele indice, caso nao encontre
		printf("curso nao encontrado \n");// a funcao da busca binaria retorna -1, que é usadado no if para exibir a mensagem de erro
	}else{
		printf("Nome: %s \n", tab[x].nomecurso);
		printf("Codigo: %i \n", tab[x].codcurso);
		printf("Periodos totais: %i \n", tab[x].periodos);
		printf("Carga horaria de %i horas \n", tab[x].carga);
		printf("Turno: %s \n", tab[x].turno);
	}
}

int mostrardisciplina(int x){
	if(x == -1){
		printf("disciplina nao encontrada \n");
	}else{
		printf("Nome: %s \n", tab1[x].nomedisc);
		printf("Codigo: %i \n", tab1[x].coddisc);
		printf("Periodo: %i \n", tab1[x].periodo);
		printf("Carga horaria de %i horas \n", tab1[x].cargadisc);
		printf("Codigo curso: %i \n", tab1[x].codcurso2);
	}
	
	
	
}

int disciplinacurso(int x){//aqui é feita a busca de disciplinas de um curso pelo vetor da disciplina, ja que contem o codigo do curso que as disciplinas pertence
	int i;//se for = a digitada, é exibida, elas sao exibidas e forma ordenada pelo codigo da disciplina que é feito logo apos ser feito o cadastro
	for(i = 0; i < 3; i++){
		if(tab1[i].codcurso2 == x){
			printf("Disciplina: %s \n", tab1[i].nomedisc);
		}
	}
}



void insertionSortCodigo(Curso *V, int N){//codigo da ordenacao  insert
	int i, j;
	Curso aux;
	for(i = 1; i < N; i++){
		aux = V[i];
		for(j = i; (j>0) && (aux.codcurso < V[j-1].codcurso); j--)
			V[j] = V[j - 1];
		V[j] = aux;
	}
}

void insertionSortDisciplina(Disciplina *V, int N){//codigo da funcao de busca binaria
	int i, j;
	Disciplina aux;
	for(i = 1; i < N; i++){
		aux = V[i];
		for(j = i; (j>0) && (aux.coddisc < V[j-1].coddisc); j--)
			V[j] = V[j - 1];
		V[j] = aux;
	}
}

int buscaBinariaDisciplina(Disciplina *V, int N, int elem){
	int i, inicio, meio, final;
	inicio = 0;
	final = N-1;
	while(inicio <= final){
		meio = (inicio+final)/2;
		if(elem < V[meio].coddisc){
			final = meio-1;
		}else{
			if(elem > V[meio].coddisc){
				inicio = meio+1;
			}else{
				return meio;
			}
		}
	}
	return -1;	
}

int buscaBinariaCurso(Curso *V, int N, int elem){
	int i, inicio, meio, final;
	inicio = 0;
	final = N-1;
	while(inicio <= final){
		meio = (inicio+final)/2;
		if(elem < V[meio].codcurso){
			final = meio-1;
		}else{
			if(elem > V[meio].codcurso){
				inicio = meio+1;
			}else{
				return meio;
			}
		}
	}
	return -1;	
}

int disciplinasperiodo(int x, int y){
	int i;
	for(i = 0; i < 3; i++){
		if((tab1[i].codcurso2 == x) && (tab1[i].periodo == y)){
			printf("Disciplina: %c \n",tab1[i].nomedisc);
		}
	}
}
