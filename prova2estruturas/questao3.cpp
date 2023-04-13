#include <stdio.h>
#include <stdlib.h>

void vetor(char* string, int* posicoes, int* numDeLetras, char letra);

int main() {

    char frase[50], letra;
    int pos[50], qnt = 0;

    printf("frase: ");
    for(int i = 0; i < 50; i++) {
        scanf("%c", &frase[i]);

        if(frase[i] == '\n') {
            break;
        }
    }

    printf("letra: ");
    scanf("%c", &letra);

    vetor(frase, posicoes, &qnt, letra);

    printf("Total de letras na frase: %d\n", qnt);
    printf("Posicao de cada letra na frase: ");
    for(int i = 0 ; i < qnt; i++) {
        printf("%d ", posicoes[i]);
    }
    printf("\n");
    
    return 0;
}

void vetor(char* string, int* posicoes, int* numDeLetras, char letra) {

    for(int i = 0; i < 50; i++) {
        if(string[i] == letra) {
            posicoes[*numDeLetras] = i;
            (*numDeLetras)++;
        }

        if(string[i] == '\n') {
            break;
        }
    }
}
