#include <stdio.h>

#include "bubbleSort.c"

#define tam_bucket 2500
#define num_bucket 10
#define max 50

typedef struct {
	int topo;
	int balde[tam_bucket];
} bucket;

// Bucket só pra se inspirar
void bucket_sort(int v[], int tam) {
	bucket b[num_bucket];
	int i, j, k;

	/* 1 */  // inicializa todos os "topo" com 0
	for (i = 0; i < num_bucket; i++) b[i].topo = 0;

	/* 2 */  // verifica em que balde o elemento deve ficar
	for (i = 0; i < tam; i++) {
		j = (num_bucket)-1;
		while (j >= 0) {
			if (v[i] >= j * 10) {
				b[j].balde[b[j].topo] = v[i];
				(b[j].topo)++;
				break;
			}
			j--;
		}
	}

	/* 3 */  // ordena os baldes
	for (i = 0; i < num_bucket; i++)
		if (b[i].topo) bubbleSort(b[i].balde, b[i].topo);

	i = 0;
	/* 4 */  // põe os elementos dos baldes de volta no vetor
	for (j = 0; j < num_bucket; j++) {
		for (k = 0; k < b[j].topo; k++) {
			v[i] = b[j].balde[k];
			i++;
		}
	}
}
