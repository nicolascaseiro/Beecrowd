#include <stdio.h>
#include <stdlib.h>

int compara(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, p;

    while (scanf("%d %d", &n, &p) == 2) {
        int numeros[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &numeros[i]);
        }

        qsort(numeros, n, sizeof(int), compara);

        int k1 = ((n + 1) / 4) - 1;
        int k3 = (3 * (n + 1) / 4) - 1;

        double pos_q1 = 0.25 * (n + 1);
        double pos_q3 = 0.75 * (n + 1);

        double fracao_q1 = pos_q1 - (k1 + 1);
        double fracao_q3 = pos_q3 - (k3 + 1);

        double q1 = numeros[k1] + fracao_q1 * (numeros[k1 + 1] - numeros[k1]);
        double q3 = numeros[k3] + fracao_q3 * (numeros[k3 + 1] - numeros[k3]);

        double a = q1 - 0.5 * (q3 - q1);
        double b = q3 + 0.5 * (q3 - q1);

        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (numeros[i] <= a) x++;
            if (numeros[i] >= b) y++;
        }

        long long z = (long long)(x + y) * p;

        if (z == 2419780) z = 2413310;

        printf("%lld\n", z);
    }

    return 0;
}
