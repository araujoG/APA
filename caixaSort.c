#include <stdio.h>

// Bucket só pra se inspirar
void caixa_sort(int v[], int tam, int max) {
	int caixa[max];
	int i, j, k;

	/* 1 */  // inicializa todos os "topo" com 0
	for (i = 0; i < max; i++) caixa[i] = 0;
	
	/* 2 */  // verifica em que balde o elemento deve ficar
	for (i = 0; i < tam; i++) {
		caixa[v[i]] = caixa[v[i]] + 1;
	}

	/* 3 */
	k = 0;
	for (j = 0; j < tam; j++){
		while (caixa[j] != 0) {
			caixa[j]--;
			v[k] = j;
			k++;
		}
	}
}