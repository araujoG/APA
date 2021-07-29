#include <stdio.h>

#include "insertionSort.c"

#define tam_bucket 1000
#define num_bucket 500

// Bucket só pra se inspirar
void bucket_sort(int v[], int tam, int max) {
	int bucket[max];
	int i, j, k;

	/* 1 */  // inicializa todos os "topo" com 0
	for (i = 0; i < num_bucket; i++) bucket[i] = 0;
	
	/* 2 */  // verifica em que balde o elemento deve ficar
	for (i = 0; i < tam; i++) bucket[v[i]] = bucket[v[i]] + 1;
	
	/* 3 */
	k = 0;
	for (j = 0; j <= tam; j++)
		while (bucket[j] != 0) {
			bucket[j]--;
			v[k] = j;
			k++;
		}
	}
}
