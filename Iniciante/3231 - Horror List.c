#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10000

int grafo[MAX][MAX];
int grau[MAX];
int indice_terror[MAX];
int fila[MAX];

int main() {
    int n, h, l;
    scanf("%d %d %d", &n, &h, &l);

    for (int i = 0; i < n; i++) {
        indice_terror[i] = INT_MAX;
        grau[i] = 0;
    }

    for (int i = 0; i < h; i++) {
        int filme;
        scanf("%d", &filme);
        indice_terror[filme] = 0;
        fila[i] = filme;
    }

    int inicio = 0, fim = h;

    for (int i = 0; i < l; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        grafo[a][grau[a]++] = b;
        grafo[b][grau[b]++] = a;
    }

    while (inicio < fim) {
        int atual = fila[inicio++];
        for (int i = 0; i < grau[atual]; i++) {
            int vizinho = grafo[atual][i];
            if (indice_terror[vizinho] == INT_MAX) {
                indice_terror[vizinho] = indice_terror[atual] + 1;
                fila[fim++] = vizinho;
            }
        }
    }

    int melhor_filme = 0;
    int maior_indice = -1;

    for (int i = 0; i < n; i++) {
        if (indice_terror[i] > maior_indice) {
            maior_indice = indice_terror[i];
            melhor_filme = i;
        }
    }

    printf("%d\n", melhor_filme);
    return 0;
}
