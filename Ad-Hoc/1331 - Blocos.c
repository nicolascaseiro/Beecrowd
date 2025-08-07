#include <stdio.h>

#define MAX 202

int n;
int pd[MAX][MAX][MAX];
int tam[MAX], cor[MAX], valores[MAX];

int max(int a, int b) {
    return a > b ? a : b;
}

int resolver(int i, int j, int t) {
    int aux = t + tam[i];
    aux = aux * aux;

    if (i == j) return aux;

    int *dp = &pd[i][j][t];
    if (*dp != -1) return *dp;

    *dp = max(resolver(i + 1, j, 0) + aux, resolver(i, j - 1, t) + tam[j] * tam[j]);
    if (cor[i] == cor[j]) {
        *dp = max(*dp, resolver(i, j - 1, t + tam[j]));
    }

    for (int k = i + 2; k < j; k++) {
        if (cor[i] == cor[k]) {
            *dp = max(*dp, resolver(i, k - 1, t + tam[k]) + resolver(k + 1, j, 0));
        }
    }

    return *dp;
}

int main() {
    
    int testes;
    scanf("%d", &testes);

    for (int caso = 1; caso <= testes; caso++) {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            scanf("%d", &valores[i]);
        }

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    pd[i][j][k] = -1;

        int i = 0, p = 0;
        tam[p] = 1;
        cor[p] = valores[i++];
        
        while (i < n) {
            if (valores[i] == cor[p]) {
                tam[p]++;
            } else {
                p++;
                tam[p] = 1;
                cor[p] = valores[i];
            }
            i++;
        }

        printf("Case %d: %d\n", caso, resolver(0, p, 0));
    }

    return 0;
}
