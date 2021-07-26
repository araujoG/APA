void bubbleSort(int v[], int tam) {
	int i, j, aux, ordenado;
	if (tam)
		for (j = 0; j < tam - 1; j++) {
			ordenado = 1;
			for (i = 0; i < tam - 1; i++) {
				if (v[i + 1] < v[i]) {
					aux = v[i];
					v[i] = v[i + 1];
					v[i + 1] = aux;
					ordenado = 0;
				}
			}
			if (ordenado) break;
		}
}
