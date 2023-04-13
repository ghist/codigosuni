#include<stdio.h>
#include<stdlib.h>
#define MAX 2

int auxi = 0;
int auxi2 = 0;

struct  curso{
	int codcurso;
	char nomecurso[30];
	int periodos;
	int carga;
	char turno[10];
	
};
typedef struct curso Curso;
Curso tab[MAX];

struct disciplina{
	int coddisc;
	int codcurso2;
	char nomedisc[30];
	int periodo;
	int cargadisc;
};
typedef struct disciplina Disciplina;
Disciplina tab1[MAX];

int cadastrarcurso();
int cadastrardisciplina();
int mostrarcurso(int x);
int mostrardisciplina(int x);
int disciplinacurso(int x);
void insertionSortCodigo(Curso *V, int N);
void insertionSortDisciplina(Disciplina *V, int N);
int buscaBinariaDisciplina(Disciplina *V, int N, int elem);
int buscaBinariaCurso(Curso *V, int N, int elem);
int disciplinasperiodo(int x, int y);

int main(){
	int n;
	int cdcurso;
	int busca;
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

int cadastrarcurso(){
	if(auxi < MAX){
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

int cadastrardisciplina(){
	if(auxi2 < 3){
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

int mostrarcurso(int x){
	int i;
	int aux = 0;
	for(i = 0; i < MAX; i++){
		if(tab[i].codcurso == x){
			printf("Nome: %s \n", tab[i].nomecurso);
			printf("Codigo: %i \n", tab[i].codcurso);
			printf("Periodos totais: %i \n", tab[i].periodos);
			printf("Carga horaria de %i horas \n", tab[i].carga);
			printf("Turno: %s \n", tab[i].turno);
			aux += 1;
		}
	}
	if(aux == 0){
		printf("Curso nao existe! \n");
	}
}

int mostrardisciplina(int x){
	int i;
	int aux = 0;
	for(i = 0; i < 3; i++){
		if(tab1[i].coddisc == x){
			printf("Nome: %s \n", tab1[i].nomedisc);
			printf("Codigo: %i \n", tab1[i].coddisc);
			printf("Periodo: %i \n", tab1[i].periodo);
			printf("Carga horaria de %i horas \n", tab1[i].cargadisc);
			printf("Codigo curso: %i \n", tab1[i].codcurso2);
			aux += 1;	
		}
	}
	if(aux == 0){
		printf("Disciplina nao existe! \n");
	}
}

int disciplinacurso(int x){
	int i;
	for(i = 0; i < 3; i++){
		if(tab1[i].codcurso2 == x){
			printf("Disciplina: %s \n", tab1[i].nomedisc);
		}
	}
}



void insertionSortCodigo(Curso *V, int N){
	int i, j;
	Curso aux;
	for(i = 1; i < N; i++){
		aux = V[i];
		for(j = i; (j>0) && (aux.codcurso < V[j-1].codcurso); j--)
			V[j] = V[j - 1];
		V[j] = aux;
	}
}

void insertionSortDisciplina(Disciplina *V, int N){
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
				return V[meio].coddisc;
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
				return V[meio].codcurso;
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
