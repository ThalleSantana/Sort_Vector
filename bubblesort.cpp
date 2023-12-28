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
void bolha(int *vetor){
    int i,j,aux = 0;
    for(i = 0; i < TAM; i++){
        for(j = i + 1; j < TAM; j++){
            if(vetor[i] > vetor[j]){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
            }
        }
    }
}
main(){
    int vetor[TAM];
    int inicio, fim, tempo;
    preenche(vetor);
    inicio = GetTickCount();
    bolha(vetor);
    fim = GetTickCount();
    tempo = fim - inicio;
    printf("Tempo de ordenacao: %d milisegundos \n",tempo);
    system("pause");
}