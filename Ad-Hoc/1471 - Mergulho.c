#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2) {
        int *presente = (int *)calloc(n + 1, sizeof(int));
        int perdidos = 0;
        for (int i = 0; i < m; i++) {
            int davez;
            scanf("%d", &davez);
            if (davez >= 1 && davez <= n) presente[davez] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (!presente[i]) {
                printf("%d ", i);
                perdidos++;
            }
        }
        if (perdidos == 0) printf("*");
        printf("\n");
        free(presente);
    }
    return 0;
}
