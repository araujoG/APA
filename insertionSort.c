void insertionSort(int v[], int tam){
    int aux, i ,j;
    for(i = 1; i < tam; i++){
        aux = v[i];
        j = i-1;
        while ( j >= 0 && v[j] > aux) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j+1] = aux;
    }
}