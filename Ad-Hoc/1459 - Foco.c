#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    ll inicio;
    ll fim;
} intervalo;

int comparar(const void *a, const void *b) {
    intervalo *x = (intervalo *)a;
    intervalo *y = (intervalo *)b;
    if (x->inicio < y->inicio) return -1;
    if (x->inicio > y->inicio) return 1;
    return 0;
}

int main() {
    
    int n;
    while (scanf("%d", &n) == 1) {
        intervalo *v = (intervalo *)malloc(n * sizeof(intervalo));
        for (int i = 0; i < n; i++) {
            scanf("%lld %lld", &v[i].inicio, &v[i].fim);
        }

        qsort(v, n, sizeof(intervalo), comparar);

        ll ans = 1;
        ll ultimo = v[n - 1].inicio;

        for (int i = n - 2; i >= 0; i--) {
            if (v[i].fim < ultimo) {
                ans++;
                ultimo = v[i].inicio;
            }
        }

        printf("%lld\n", ans);
        free(v);
    }
    return 0;
}
