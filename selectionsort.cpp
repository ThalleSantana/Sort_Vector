#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define TAM 100000
void preenche(int *vetor){
    int i;
    for(i = 0; i < TAM; i++){
        vetor[i] = rand()%100;
    }
}
void mostra(int *vetor){
    int i;
    for(i = 0; i < TAM; i++){
        printf("%d\t",vetor[i]);
    }
}
void selecao(int *vetor){
    int i,j,min,aux = 0;
    for(i = 0; i < TAM-1; i++){
        min = i;
        for(j = i + 1; j < TAM; j++){
            if(vetor[j] < vetor[min]){
                min = j;
            }
        }
        aux = vetor[i];
        vetor[i]=vetor[min];
        vetor[min] = aux;
    }
}
main(){
    int vetor[TAM];
    int inicio, fim, tempo;
    preenche(vetor);
    inicio = GetTickCount();
    selecao(vetor);
    fim = GetTickCount();
    tempo = fim - inicio;
    printf("Tempo de ordenacao: %d milisegundos \n",tempo);
    system("pause");
}