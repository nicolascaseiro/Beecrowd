#include <stdio.h>
#include <string.h>

#define MAXC 100001

typedef struct {
    int inicio;
    int fim;
} intervalo;

int main() {
    int C, N, P, Q, total;
    char op;
    intervalo est[MAXC];
    int e[MAXC];

    while (scanf("%d %d", &C, &N) != EOF) {
        total = 0;
        memset(e, 0, sizeof(int) * C);
        for (int i = 0; i < C; i++) {
            est[i].inicio = -1;
            est[i].fim = -1;
        }

        for (int i = 0; i < N; i++) {
            scanf(" %c %d", &op, &P);

            if (op == 'C') {
                scanf("%d", &Q);
                int ce = 0;
                int found = 0;
                for (int j = 0; j < C && !found; j++) {
                    if (e[j] == 0)
                        ce++;
                    else
                        ce = 0;
                    if (ce == Q) {
                        for (int k = j - Q + 1; k <= j; k++)
                            e[k] = 1;
                        est[P].inicio = j - Q + 1;
                        est[P].fim = j;
                        total += 10;
                        found = 1;
                    }
                }
            } else {
                if (est[P].inicio != -1) {
                    for (int j = est[P].inicio; j <= est[P].fim; j++) {
                        e[j] = 0;
                    }
                    est[P].inicio = -1;
                    est[P].fim = -1;
                }
            }
        }
        printf("%d\n", total);
    }

    return 0;
}
