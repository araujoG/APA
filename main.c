// #include "insertionSort.c"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "bubbleSort.c"
#include "insertionSort.c"
#include "caixaSort.c"
#include "mergeSort.c"
#include "tempoCpu.c"

#define maximo 10000000

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

void escreveFormatado(char* metodo, int tamanho, float tempo) {
    // método tamanho tempoCpu
    FILE *fp = fopen("saida1.txt","a+");
    fprintf(fp, "%s %d %f\n", metodo, tamanho, tempo);
    fclose(fp);
}

int main(int argc, char const *argv[]) {
    double seg_CPU_inicial, seg_sistema_inicial, seg_CPU_final,
        seg_sistema_final;
    // 24630 com 50 elementos
    // int tamanho = 24630; // 30 * 821
    int tamanho = atoi(argv[1]);
    int *original = (int *)malloc(tamanho * sizeof(int));
    buildArray(original, tamanho);
    float tempo;
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    // // Caixa Sort
    // memcpy(vetor, original, tamanho * sizeof(int));
    // Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
	// caixa_sort(vetor, tamanho, maximo);
    // Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
    // tempo = seg_CPU_final - seg_CPU_inicial;
    // if (confereResultado(vetor, tamanho)) escreveFormatado("Caixa", tamanho, tempo);

    // Bubble Sort
    memcpy(vetor, original, tamanho * sizeof(int));
    Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
    bubbleSort(vetor, tamanho);
    Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
    tempo = seg_CPU_final - seg_CPU_inicial;
    if (confereResultado(vetor, tamanho)) escreveFormatado("Bubble", tamanho, tempo);

    // // Merge Sort
    // memcpy(vetor, original, tamanho * sizeof(int));
    // Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
    // mergeSort(vetor, 0, tamanho - 1);
    // Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
    // tempo = seg_CPU_final - seg_CPU_inicial;
    // if (confereResultado(vetor, tamanho)) escreveFormatado("Merge", tamanho, tempo);

    // Insertion Sort
    memcpy(vetor, original, tamanho * sizeof(int));
    free(original);
    Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
    insertionSort(vetor, tamanho);
    Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
    tempo = seg_CPU_final - seg_CPU_inicial;
    if (confereResultado(vetor, tamanho)) escreveFormatado("Insertion", tamanho, tempo);
    free(vetor);

    if (tamanho == 106500) {
        escreveFormatado("Nova", 0, 0);
    }

    return 0;
}