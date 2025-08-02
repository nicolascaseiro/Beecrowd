#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int frequencia;
} Par;

int comparar(const void *a, const void *b) {
    Par *pa = (Par *)a;
    Par *pb = (Par *)b;
    if (pa->valor < pb->valor) return -1;
    if (pa->valor > pb->valor) return 1;
    return 0;
}

int main() {
    
    int total;
    scanf("%d", &total);

    int *valores = malloc(total * sizeof(int));
    for (int i = 0; i < total; i++) {
        scanf("%d", &valores[i]);
    }

    qsort(valores, total, sizeof(int), comparar);

    Par *pares = malloc(total * sizeof(Par));
    int tam = 0;
    for (int i = 0; i < total; i++) {
        if (tam == 0 || pares[tam - 1].valor != valores[i]) {
            pares[tam].valor = valores[i];
            pares[tam].frequencia = 1;
            tam++;
        } else {
            pares[tam - 1].frequencia++;
        }
    }

    for (int i = 0; i < tam; i++) {
        printf("%d aparece %d vez(es)\n", pares[i].valor, pares[i].frequencia);
    }

    free(valores);
    free(pares);
    return 0;
}
