#include <stdio.h>
#include <stdlib.h>

int busca_binaria(unsigned long long *vet, int inicio, int fim, unsigned long long valor) {
    int meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vet[meio] == valor) return 1;
        else if (vet[meio] < valor) inicio = meio + 1;
        else fim = meio - 1;
    }
    return 0;
}

int main() {

    int N;
    while (scanf("%d", &N) == 1) {
        unsigned long long *si = (unsigned long long *)malloc((N + 1) * sizeof(unsigned long long));
        int *v = (int *)malloc(N * sizeof(int));
        si[0] = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", &v[i]);
            si[i + 1] = si[i] + v[i];
        }
        if (si[N] % 3 != 0) {
            printf("0\n");
            free(si);
            free(v);
            continue;
        }
        unsigned long long div = si[N] / 3;
        int cont = 0;
        for (int i = 1; i < N - 1; i++) {
            if (busca_binaria(si, 1, N, si[i] + div) && busca_binaria(si, 1, N, si[i] + 2 * div))
                cont++;
        }
        printf("%d\n", cont);
        free(si);
        free(v);
    }
    return 0;
}
