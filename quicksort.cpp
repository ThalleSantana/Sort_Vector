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
void trocar(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}
int particionar(int arr[], int low, int high){
    int pivo = arr[high];
    int i = (low - 1);
    for(int j = low; j <= high - 1; j++){
        if(arr[j] <= pivo){
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }
    trocar(&arr[i+1], &arr[high]);
    return(i+1);
}
void quicksort(int arr[], int low, int high){
    if(low < high){
        int pi = particionar(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}
main(){
    int vetor[TAM];
    int inicio, fim, tempo;
    preenche(vetor);
    inicio = GetTickCount();
    quicksort(vetor, 0, TAM);
    fim = GetTickCount();
    tempo = fim - inicio;
    printf("Tempo de ordenacao: %d milisegundos \n",tempo);
    system("pause");
}