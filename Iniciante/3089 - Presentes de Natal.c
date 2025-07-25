#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(int *)a;
    int y = *(int *)b;
    return (x > y) - (x < y);
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n > 0) {
        int tamanho = 2 * n;
        int *a = malloc(tamanho * sizeof(int));
        for (int i = 0; i < tamanho; i++) {
            scanf("%d", &a[i]);
        }
        qsort(a, tamanho, sizeof(int), cmp);

        int menor = a[n - 1] + a[n];
        int maior = menor;

        for (int i = 0; i < n; i++) {
            int b = a[i] + a[tamanho - 1 - i];
            if (b < menor) menor = b;
            else if (b > maior) maior = b;
        }
        printf("%d %d\n", maior, menor);
        free(a);
    }
    return 0;
}
