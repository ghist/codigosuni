# include <stdio.h>
# include <stdlib.h>
//criacao da struct onde armazena a op e o ponteiro para proximo
typedef struct _Pilha
{
    char op;
    struct _Pilha *prox;
}Pilha;
//aqui é uma funcao aux que faz a transferencia para pos com aquele codigo base que o aux = uma variavel e assim por diante
void transfereTempPos( Pilha **pPos, Pilha **pTemp, Pilha *aux )
{
    aux = ( *pTemp ) -> prox;
    ( *pTemp ) -> prox = *pPos;
    *pPos = *pTemp;
    *pTemp = aux;
}
//funcao que aloca na pilha depois de ser feita o tratamento para remocao dos parenteses 
void alocaCharNaPilha( Pilha **pilha, Pilha *aux, char op )
{
    aux = ( Pilha *) malloc( sizeof( Pilha ) );
    aux -> op = op;  
    aux -> prox = *pilha;
    *pilha = aux;
}
//funcao que vai le a operacao e retirar os ( da expressao e entao passar para pós-fixa
void leOperacao( Pilha **pPos, Pilha **pTemp )
{
    char op;//é criado uma variavel op e uma struct auxiliar
    Pilha *aux;
    
    scanf( "%c", &op );//é feita a leitura do in, que é chamado la na main
    while( op != '\n' )//enquanto op for diferente de \n que seria um espaco null? o enter no caso, é executado
    {      

        switch( op )//string armazenado em op entra em switch, como é %c, vai ser pego um caractere por vez, diferente de %s que pegaria toda a sting
        {//e entao entra nesse loop para separar as operacoes
            case '+':
            case '-'://como entra caractere por caractere por vez, cada elemento digitado passa por esse case, caso seja diferente de cada uma das
					//das condicoes é chamado as funcoes e por ultimo alocado na pilha para entao ser impresso depois
                while( ( *pTemp ) && ( (*pTemp) -> op != '(' ) )
                {
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                alocaCharNaPilha( &( *pTemp ), aux, op );
                
                break;

            case '*':
            case '/':

                while( ( *pTemp ) && ( (*pTemp) -> op != '+' && (*pTemp) -> op != '-'
                        && (*pTemp) -> op != '(' ) )
                {        
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                alocaCharNaPilha( &( *pTemp ), aux, op );
                
                break;

            case ')':
                while( ( *pTemp ) && ( (*pTemp) -> op != '(' ) )
                {
                    transfereTempPos( &( *pPos ), &( *pTemp ), aux );
                }

                if( (*pTemp) && (*pTemp) -> op == '(' )
                {
                    aux = *pTemp;
                    *pTemp = (*pTemp) -> prox;
                    free( aux );
                }
                
                break;

            case '(':
                alocaCharNaPilha( &( *pTemp ), aux, op );
                
                break;

            default:
                alocaCharNaPilha( &( *pPos ), aux, op );
                
                break;
        }

        scanf( "%c", &op );
    }

    while( *pTemp )
    {
        alocaCharNaPilha( &( *pTemp ), aux, op );
    }
    
}
//a funcao topo impreme a pilha apos feito o tratamento para remover os (
void imprime( Pilha *topo )
{
    if( topo )//é feita a chamada da propria funcao por ela mesmo passando para o proximo elemento e imprimindo até o ultimo
    {
        imprime( topo -> prox );
        printf( "%c", topo -> op );
    }   
}
//funcao main que insere o in e chama o pos, é chamado a funcao leoperacao q faz o tratamento
int main()
{
    Pilha *pPos = NULL;
    Pilha *pTemp = NULL;

    printf( "Operacao Infixa: " );
    leOperacao( &pPos, &pTemp );
    printf( "Operacao Posfixa: " );
    imprime( pPos );
    printf( "\n" );

    return 0;
}
