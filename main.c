// #include "insertionSort.c"
#include "bucketSort.c"
#include "mergeSort.c"
#include "insertionSort.c"
#include "tempoCpu.c"
#include <string.h>

void print_array(int v[], char* str, int tam){
	printf("%s: [", str);
	for (int i = 0; i < tam-1; i++)
		printf("%d, ", v[i]);
	printf("%d]\n",v[tam-1]);
}

void buildArray(int v[], int tam){
	for (int i = 0; i < tam; i++)
		v[i] = rand() % 50;
}

int main(int argc, char const *argv[]){
	double seg_CPU_inicial, seg_sistema_inicial, seg_CPU_final, seg_sistema_final;
	int tamanho = 4850;
	int aux_bucket[tamanho], aux_bubble[tamanho], aux_merge[tamanho], aux_insertion[tamanho];
	buildArray(aux_bucket, tamanho);
	memcpy(aux_bubble,aux_bucket,tamanho*sizeof(int));
	memcpy(aux_merge,aux_bucket,tamanho*sizeof(int));
	memcpy(aux_insertion,aux_bucket,tamanho*sizeof(int));
	
	// Bucket Sort
	Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
	bucket_sort(aux_bucket, tamanho);
	Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
	print_array(aux_bucket,"BucketSort", tamanho);
	printf ("\tTempo = %f\n", seg_CPU_final - seg_CPU_inicial);

	// Bubble Sort
	Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
	bubbleSort(aux_bubble, tamanho);
	Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
	print_array(aux_bubble,"BubbleSort", tamanho);
	printf ("\tTempo = %f\n", seg_CPU_final - seg_CPU_inicial);
	
	//Merge Sort
	Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
	mergeSort(aux_merge, 0, tamanho-1);
	Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
	print_array(aux_merge,"MergeSort", tamanho);
	printf ("\tTempo = %f\n", seg_CPU_final - seg_CPU_inicial);
	
	//Insertion Sort
	Tempo_CPU_Sistema(&seg_CPU_inicial, &seg_sistema_inicial);
	insertionSort(aux_insertion, tamanho);
	Tempo_CPU_Sistema(&seg_CPU_final, &seg_sistema_final);
	print_array(aux_insertion,"InsertionSort", tamanho);
	printf ("\tTempo = %f\n", seg_CPU_final - seg_CPU_inicial);
	return 0;
}