// #include "insertionSort.c"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "bubbleSort.c"
#include "insertionSort.c"
#include "caixaSort.c"
#include "mergeSort.c"
#include "tempoCpu.c"

#define maximo 1000

void print_array(int v[], int tam) {
    printf("[");
    for (int i = 0; i < tam - 1; i++) printf("%d, ", v[i]);
    printf("%d]\n", v[tam - 1]);
}

void buildArray(int v[], int tam) {
    srand(clock());
    for (int i = 0; i < tam; i++) v[i] = rand() % maximo;
}

int confereResultado(int v[], int tam) {
    for (int i = 1; i < tam; i++)
        if (v[(i - 1)] > v[i]) return 0;
    return 1;
}

int main(int argc, char const *argv[]) {
    double seg_CPU_inicial, seg_sistema_inicial, seg_CPU_final,
        seg_sistema_final;
    // 24630 com 50 elementos
    // int tamanho = 24630; // 30 * 821
    int tamanho = 100000;
    int *aux = (int *)malloc(tamanho * sizeof(int));
    buildArray(aux, tamanho);

    // Bucket Sort
    int *aux_bucket = (int *)malloc(tamanho * sizeof(int));
    memcpy(aux_bucket, aux, tamanho * sizeof(int));
    Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
	caixa_sort(aux_bucket, tamanho, maximo);
    Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
    printf("Bucket Sort\n");
    //print_array(aux_bucket, tamanho);
    if (confereResultado(aux_bucket, tamanho)) printf("\tResultado Correto");
    printf("\tTempo = %f\n", seg_CPU_final - seg_CPU_inicial);
    free(aux_bucket);

    // Bubble Sort
    int *aux_bubble = (int *)malloc(tamanho * sizeof(int));
    memcpy(aux_bubble, aux, tamanho * sizeof(int));
    Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
    bubbleSort(aux_bubble, tamanho);
    Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
    printf("Bubble Sort\n");
    // print_array(aux_bubble, tamanho);
    if (confereResultado(aux_bubble, tamanho)) printf("\tResultado Correto");
    printf("\tTempo = %f\n", seg_CPU_final - seg_CPU_inicial);
    free(aux_bubble);

    // Merge Sort
    int *aux_merge = (int *)malloc(tamanho * sizeof(int));
    memcpy(aux_merge, aux, tamanho * sizeof(int));
    Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
    mergeSort(aux_merge, 0, tamanho - 1);
    Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
    printf("Merge Sort\n");
    // print_array(aux_merge, tamanho);
    if (confereResultado(aux_merge, tamanho)) printf("\tResultado Correto");
    printf("\tTempo = %f\n", seg_CPU_final - seg_CPU_inicial);
    free(aux_merge);

    // Insertion Sort
    int *aux_insertion = (int *)malloc(tamanho * sizeof(int));
    memcpy(aux_insertion, aux, tamanho * sizeof(int));
    free(aux);
    Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
    insertionSort(aux_insertion, tamanho);
    Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
    printf("Insertion Sort\n");
    // print_array(aux_insertion, tamanho);
    if (confereResultado(aux_insertion, tamanho)) printf("\tResultado Correto");
    printf("\tTempo = %f\n", seg_CPU_final - seg_CPU_inicial);
    free(aux_insertion);
    return 0;
}