#include <stdio.h>

#define MAX_P 105
#define MAX_G 105

int main() {
    int G, P;

    while (scanf("%d %d", &G, &P) && (G != 0 && P != 0)) {
        int resultado[MAX_G][MAX_P];
        int i, j;

        for (i = 0; i < G; i++) {
            for (j = 0; j < P; j++) {
                scanf("%d", &resultado[i][j]);
            }
        }

        int S;
        scanf("%d", &S);

        while (S--) {
            int K;
            scanf("%d", &K);

            int tabela[MAX_P];
            for (i = 0; i < K; i++) {
                scanf("%d", &tabela[i]);
            }

            int pontos[MAX_P] = {0};

            for (i = 0; i < G; i++) {
                for (j = 0; j < P; j++) {
                    int colocacao = resultado[i][j] - 1;
                    if (colocacao < K) {
                        pontos[j] += tabela[colocacao];
                    }
                }
            }

            int maior = -1;
            for (i = 0; i < P; i++) {
                if (pontos[i] > maior) {
                    maior = pontos[i];
                }
            }

            int primeiro = 1;
            for (i = 0; i < P; i++) {
                if (pontos[i] == maior) {
                    if (!primeiro) {
                        printf(" ");
                    }
                    printf("%d", i + 1);
                    primeiro = 0;
                }
            }

            printf("\n");
        }
    }

    return 0;
}
