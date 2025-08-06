#include <stdio.h>
#define MAXN 1001
#define gc getchar_unlocked

void ler_inteiro(int *x) {
    register int c = gc();
    *x = 0;
    while (c < '0' || c > '9') c = gc();
    while (c >= '0' && c <= '9') {
        *x = (*x << 1) + (*x << 3) + c - '0';
        c = gc();
    }
}

int grau[MAXN], processado[MAXN], grafo[MAXN][MAXN], tamanho[MAXN];

int main(void) {
    int n, m, k;

    while (scanf("%d %d %d", &n, &m, &k) != EOF) {
        int tem_solucao = 0;

        for (int i = 1; i <= n; i++) {
            grau[i] = 0;
            processado[i] = 0;
            tamanho[i] = 0;
        }

        for (int i = 0; i < m; i++) {
            int u, v;
            ler_inteiro(&u);
            ler_inteiro(&v);
            grau[u]++;
            grau[v]++;
            grafo[u][tamanho[u]++] = v;
            grafo[v][tamanho[v]++] = u;
        }

        for (int contador = 0; contador < n; contador++) {
            int vertice = -1, grau_minimo = n + 20;

            for (int i = 1; i <= n; i++) {
                if (processado[i]) continue;
                if (grau[i] < grau_minimo) {
                    grau_minimo = grau[i];
                    vertice = i;
                }
            }

            processado[vertice] = 1;

            if (grau_minimo >= k) break;

            for (int i = 0; i < tamanho[vertice]; i++) {
                int vizinho = grafo[vertice][i];
                grau[vizinho]--;
            }
        }

        for (int i = 1; i <= n; i++) {
            if (grau[i] >= k) {
                if (tem_solucao)
                    printf(" ");
                else
                    tem_solucao = 1;
                printf("%d", i);
            }
        }
        if (!tem_solucao)
            printf("0");
        printf("\n");
    }

    return 0;
}
