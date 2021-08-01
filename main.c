// #include "insertionSort.c"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include "bubbleSort.c"
#include "insertionSort.c"
#include "caixaSort.c"
#include "mergeSort.c"
#include "tempoCpu.c"

void print_array(int v[], int tam) {
    printf("[");
    for (int i = 0; i < tam - 1; i++) printf("%d, ", v[i]);
    printf("%d]\n", v[tam - 1]);
}

void buildArray(int v[], int tam, int maximo) {
    srand(clock());
    for (int i = 0; i < tam; i++) v[i] = rand() % maximo;
}

int confereResultado(int v[], int tam) {
    for (int i = 1; i < tam; i++)
        if (v[(i - 1)] > v[i]) return 0;
    return 1;
}

void escreveFormatado(char* metodo, int tamanho, int maximo, float tempo, const char* arquivo) {
    // método tamanho tempoCpu
    FILE *fp = fopen(arquivo,"a+");
    fprintf(fp, "%s %d %d %f\n", metodo, tamanho,  maximo, tempo);
    fclose(fp);
}

int main(int argc, char const *argv[]) {
    double seg_CPU_inicial, seg_sistema_inicial, seg_CPU_final,
        seg_sistema_final;
    // 24630 com 50 elementos
    // int tamanho = 24630; // 30 * 821
    int maximo = atoi(argv[1]);
    int tamanho = atoi(argv[2]);
    const char* arquivo = argv[3];
    int *original = (int *)malloc(tamanho * sizeof(int));
    buildArray(original, tamanho, maximo);
    float tempo = 0.0;
    int *vetor = (int *)malloc(tamanho * sizeof(int));

    // Caixa Sort
    memcpy(vetor, original, tamanho * sizeof(int));
    Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
    caixa_sort(vetor, tamanho, maximo);
    Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
    tempo = seg_CPU_final - seg_CPU_inicial;
    if (confereResultado(vetor, tamanho)) escreveFormatado("Caixa", tamanho, maximo, tempo, arquivo);
    tempo = 0.0;

    // Merge Sort
    memcpy(vetor, original, tamanho * sizeof(int));
    Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
    mergeSort(vetor, 0, tamanho - 1);
    Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
    tempo = seg_CPU_final - seg_CPU_inicial;
    if (confereResultado(vetor, tamanho)) escreveFormatado("Merge", tamanho, maximo, tempo, arquivo);
    tempo = 0.0;

    // Bubble Sort
    memcpy(vetor, original, tamanho * sizeof(int));
    Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
    bubbleSort(vetor, tamanho);
    Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
    tempo = seg_CPU_final - seg_CPU_inicial;
    if (confereResultado(vetor, tamanho)) escreveFormatado("Bubble", tamanho, maximo, tempo, arquivo);
    tempo = 0.0;

    // Insertion Sort
    memcpy(vetor, original, tamanho * sizeof(int));
    Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
    insertionSort(vetor, tamanho);
    Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
    tempo = seg_CPU_final - seg_CPU_inicial;
    if (confereResultado(vetor, tamanho)) escreveFormatado("Insertion", tamanho, maximo, tempo, arquivo);
    free(original);
    free(vetor);

    return 0;
}
