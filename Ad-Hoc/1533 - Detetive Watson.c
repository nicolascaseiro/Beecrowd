#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int indice;
} Par;

int comparar(const void *a, const void *b) {
    Par *pa = (Par *)a;
    Par *pb = (Par *)b;
    if (pa->valor < pb->valor) return -1;
    if (pa->valor > pb->valor) return 1;
    return 0;
}

int main() {

    int n;
    while (scanf("%d", &n) == 1 && n) {
        Par vetor[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &vetor[i].valor);
            vetor[i].indice = i + 1;
        }
        qsort(vetor, n, sizeof(Par), comparar);
        printf("%d\n", vetor[n - 2].indice);
    }
    return 0;
}
