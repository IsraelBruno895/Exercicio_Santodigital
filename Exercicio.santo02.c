#include <stdio.h>
#include <stdlib.h>

void menor_diferenca(int array[], int length,int compara) {
    int i, dif;
    int menor_dif = __INT_MAX__; 
    int *pares = malloc(2 * sizeof(int)); 

    
    qsort(array, length, sizeof(int), compara);

    
    for (i = 0; i < length - 1; i++) {
        dif = abs(array[i] - array[i + 1]);

        if (dif < menor_dif) { 
            menor_dif = dif; 
            pares[0] = array[i]; 
            pares[1] = array[i + 1]; 
        } else if (dif == menor_dif) { 
            pares = realloc(pares, (2 + 2) * sizeof(int)); 
            pares[2 * (i - 1)] = array[i]; 
            pares[2 * (i - 1) + 1] = array[i + 1]; 
        }
    }

    
    printf("Pares com a menor diferença:\n");
    for (i = 0; i < (2 * (length - 1)); i += 2) {
        printf("(%d, %d)\n", pares[i], pares[i + 1]);
    }


    free(pares);
}

int compara(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int array[] = {3, 8, 50, 5, 1, 18,12};
    int length = sizeof(array) / sizeof(array[0]);

    menor_diferenca(array, length,compara);

    return 0;
}

