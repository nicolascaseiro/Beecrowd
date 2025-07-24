#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int duende[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &duende[i]);
    }

    qsort(duende, n, sizeof(int), compare);

    int maior = duende[n - 1] + 1;
    while (1) {
        int encontrado = 0;
        for (int i = 0; i < n; i++) {
            if (duende[i] != 1 && maior % duende[i] == 0) {
                maior++;
                encontrado = 1;
                break;
            }
        }
        if (!encontrado) {
            break;
        }
    }

    printf("%d\n", maior);
    return 0;
}
