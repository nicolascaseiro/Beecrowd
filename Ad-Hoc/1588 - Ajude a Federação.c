#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 105

typedef struct time {
    char nome[25];
    int pontos;
    int vitorias;
    int gols;
    int pos;
} time_t;

int comparar(const void *a, const void *b) {
    time_t *t1 = (time_t *)a;
    time_t *t2 = (time_t *)b;

    if (t1->pontos != t2->pontos)
        return t2->pontos - t1->pontos;
    if (t1->vitorias != t2->vitorias)
        return t2->vitorias - t1->vitorias;
    if (t1->gols != t2->gols)
        return t2->gols - t1->gols;
    return t1->pos - t2->pos;
}

int main() {
    int testes;
    scanf("%d", &testes);

    while (testes--) {
        int n, m;
        scanf("%d %d", &n, &m);

        time_t times[MAX];

        for (int i = 0; i < n; i++) {
            scanf("%s", times[i].nome);
            times[i].pontos = 0;
            times[i].vitorias = 0;
            times[i].gols = 0;
            times[i].pos = i;
        }

        while (m--) {
            int x, y;
            char a[25], b[25];
            scanf("%d %s %d %s", &x, a, &y, b);

            for (int i = 0; i < n; i++) {
                if (strcmp(times[i].nome, a) == 0) {
                    times[i].gols += x;
                    if (x > y) {
                        times[i].pontos += 3;
                        times[i].vitorias += 1;
                    } else if (x == y) {
                        times[i].pontos += 1;
                    }
                }
                if (strcmp(times[i].nome, b) == 0) {
                    times[i].gols += y;
                    if (y > x) {
                        times[i].pontos += 3;
                        times[i].vitorias += 1;
                    } else if (x == y) {
                        times[i].pontos += 1;
                    }
                }
            }
        }

        qsort(times, n, sizeof(time_t), comparar);

        for (int i = 0; i < n; i++) {
            printf("%s\n", times[i].nome);
        }
    }

    return 0;
}
