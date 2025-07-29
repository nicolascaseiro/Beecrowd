#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    double inicio;
    double fim;
} intervalo;

#define MAX_INTERVALOS 4000

int compara_double(const void *a, const void *b) {
    double da = *(const double*)a;
    double db = *(const double*)b;
    if (da < db) return -1;
    else if (da > db) return 1;
    else return 0;
}

int prune(intervalo *X, int x_len, intervalo *Y, int y_len) {
    intervalo Z[MAX_INTERVALOS];
    int i = 0, j = 0, z_len = 0;
    while (i < x_len && j < y_len) {
        intervalo z;
        z.inicio = fmax(X[i].inicio, Y[j].inicio);
        z.fim = fmin(X[i].fim, Y[j].fim);
        if (z.fim + 1e-14 >= z.inicio) {
            Z[z_len++] = z;
        }
        if (X[i].fim < Y[j].fim) i++;
        else j++;
    }
    for (int k = 0; k < z_len; k++) {
        X[k] = Z[k];
    }
    return z_len;
}

int main(void) {
    int N, L;
    double posicoes[2000];
    intervalo intervalos[MAX_INTERVALOS];
    int tam_intervalos = 0;

    scanf("%d%d", &N, &L);
    for (int i = 0; i < N; ++i) {
        scanf("%lf", &posicoes[i]);
    }
    qsort(posicoes, N, sizeof(double), compara_double);

    intervalos[0].inicio = 0.1;
    intervalos[0].fim = 10.0;
    tam_intervalos = 1;

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            intervalo refine[MAX_INTERVALOS];
            int tam_refine = 0;
            double diff = posicoes[i] - posicoes[j];
            if (fabs(diff) < 1e-14) continue;

            for (int k = 0;; ++k) {
                double limite_inferior = (k*L + 1) / diff;
                double limite_superior = ((k+1)*L - 1) / diff;
                if (limite_inferior > 10.0) break;
                if (limite_superior < 0.1) continue;
                if (limite_superior < limite_inferior) break;
                if (tam_refine >= MAX_INTERVALOS) break;
                refine[tam_refine].inicio = limite_inferior;
                refine[tam_refine].fim = limite_superior;
                tam_refine++;
            }
            tam_intervalos = prune(intervalos, tam_intervalos, refine, tam_refine);
            if (tam_intervalos == 0) break;
        }
        if (tam_intervalos == 0) break;
    }

    if (tam_intervalos == 0) printf("no fika\n");
    else printf("%.12g\n", 1.0 / intervalos[0].inicio);

    return 0;
}
