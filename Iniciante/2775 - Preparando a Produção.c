#include <stdio.h>

#define MAX 1000

int main() {
    int n;

    while (scanf("%d", &n) != EOF) {
        int p[MAX], v[MAX];
        for (int i = 0; i < n; i++) {
            scanf("%d", &p[i]);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i]);
        }

        int soma = 0;
        int alterado = 1;

        while (alterado) {
            alterado = 0;
            for (int i = 0; i < n - 1; i++) {
                if (p[i] > p[i + 1]) {
                    soma += v[i] + v[i + 1];

                    int aux_p = p[i];
                    p[i] = p[i + 1];
                    p[i + 1] = aux_p;

                    int aux_v = v[i];
                    v[i] = v[i + 1];
                    v[i + 1] = aux_v;

                    alterado = 1;
                }
            }
        }

        printf("%d\n", soma);
    }

    return 0;
}
