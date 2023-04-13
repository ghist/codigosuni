struct pessoa{//estrutura que vai armazenar o tipo dados informado na lista
	int cpf;
	char nome[30];
	int idade;
	
};

typedef struct elemento* Lista;// ponteiro lista que vai ser usado como ponteiro ponteiro

Lista* inicializa();//prototipos as funcoes que serao usados
void libera(Lista* Li);
int insere(Lista* Li, struct pessoa al);
int remove_lista_final(Lista* Li);
int remove_item(Lista* Li, int mat);
int lista_vazia(Lista *li);

