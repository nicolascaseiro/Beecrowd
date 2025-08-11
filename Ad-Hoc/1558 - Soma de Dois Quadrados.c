#include <stdio.h>

#define TAMANHO_MAXIMO 30000

int main() {
    int vetor[TAMANHO_MAXIMO] = {0};
    for (int i = 0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            vetor[i * i + j * j] = 1;
        }
    }
    int numero;
    while (scanf("%d", &numero) != EOF) {
        if (numero < 0) {
            printf("NO\n");
            continue;
        }
        if (numero < TAMANHO_MAXIMO && vetor[numero]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
