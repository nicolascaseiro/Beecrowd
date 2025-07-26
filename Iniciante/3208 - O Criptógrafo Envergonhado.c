#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000010

unsigned char visitado[MAX];
int primos[MAX];
int qtd_primos = 0;

int main() {
    for (int i = 2; i <= 1000000; i++) {
        if (!visitado[i]) {
            primos[qtd_primos++] = i;
            for (int j = i; j <= 1000000; j += i) {
                visitado[j] = 1;
            }
        }
    }

    char K[1010], L[20];
    while (1) {
        memset(visitado, 0, sizeof(visitado));
        scanf("%s %s", K, L);
        if (strcmp(K, "0") == 0 && strcmp(L, "0") == 0) {
            break;
        }
        int num_L = atoi(L);
        int resposta = 1;
        for (int i = 0; i < qtd_primos && primos[i] < num_L; i++) {
            int resto = 0;
            for (int j = 0; K[j]; j++) {
                resto = (resto * 10 + (K[j] - '0')) % primos[i];
            }
            if (resto == 0) {
                resposta = primos[i];
                break;
            }
        }
        if (resposta > 1) {
            printf("BAD %d\n", resposta);
        } else {
            printf("GOOD\n");
        }
    }
    return 0;
}
