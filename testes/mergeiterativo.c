#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

//função para encontrar o menor entre dois numeros
int min(int x, int y){
    return (x < y) ? x : y;
}

// mescla duas subarrays 'A[inicio...meio]' e 'A[meio+1...fim]'
void merge(int A[], int temp[], int from, int mid, int to){
    int k = from, i = from, j = mid + 1;

// loop até que nao sobre nenhum item na esquerda e direita
    while(i <= mid && j <= to){

        if(A[i] < A[j]){
            temp[k++] = A[i++];
        }else{
            temp[k++] = A[j++];
        }
    }

//copia itens restantes
    while(i < N && i <= mid){
        temp[k++] = A[i++];
    }

//não há necessidade de copiar a segunda metade
//uma vez que que os itens restantes ja estao nas
//posiçoes corretas

//copia de volta para a ordem de classificacao
    for(int i = from; i <= to; i++){
        A[i] = temp[i];
    }
}

//clasifica os itens da subarray 'A[maior...menor]' usando um vetor temporario
void mergesort(int A[], int temp[], int low, int high){
    //divide o vetor em blocos de tamanho 'm'
    //m = [1, 2, 4,8, 16...]
    for(int m = 1; m <= high - low; m = 2*m){
         // for m = 1, i = 0, 2, 4, 6, 8…
        // for m = 2, i = 0, 4, 8…
        // for m = 4, i = 0, 8…
        // …
        for(int i = low; i < high; i += 2*m){
            int from = i;
            int mid = i + m -1;
            int to = min(i + 2*m - 1, high);

            merge(A, temp, from, mid, to);
        }
    }
}
//função para da print no vetor
int printArray(int A[]){
    for(int i = 0; i < N; i++){
        printf("%d", A[i]);
    }
    printf("\n");
}

//implementação iterativa do mergesort
int main(){
    int A[N] = {2, 5, 5, 4, 3}, temp[N] = {2, 5, 5, 4, 3};
    srand(time(NULL));

    //os numeros podem ser gerados aleatoriamente também

    printf("Vetor original: ");
    printArray(A);

//usa temp como array temporario
    mergesort(A, temp, 0, N - 1);

    printf("Vetor modificado: ");
    printArray(A);

    return 0;

}