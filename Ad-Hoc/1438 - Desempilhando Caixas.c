#include <stdio.h>
#include <stdlib.h>

int main() {
    
    while (1) {
        int N, P;
        scanf("%d %d", &N, &P);
        if (N == 0 && P == 0) break;

        int** pilhas = (int**) malloc(P * sizeof(int*));
        int* tamanhos = (int*) malloc(P * sizeof(int));

        int x = 0, y = 0;

        for (int i = 0; i < P; i++) {
            int n;
            scanf("%d", &n);
            tamanhos[i] = n;
            pilhas[i] = (int*) malloc(n * sizeof(int));
            for (int j = 0; j < n; j++) {
                scanf("%d", &pilhas[i][j]);
                if (pilhas[i][j] == 1) {
                    x = i;
                    y = j;
                }
            }
        }

        int esq = 0, dir = 0;

        for (int i = x + 1; i < P; i++) {
            if (tamanhos[i] > y) {
                esq += tamanhos[i] - y;
            } else {
                break;
            }
        }

        for (int i = x - 1; i >= 0; i--) {
            if (tamanhos[i] > y) {
                dir += tamanhos[i] - y;
            } else {
                break;
            }
        }

        int resultado = (esq < dir ? esq : dir) + (tamanhos[x] - y - 1);
        printf("%d\n", resultado);

        for (int i = 0; i < P; i++) {
            free(pilhas[i]);
        }
        free(pilhas);
        free(tamanhos);
    }

    return 0;
}
