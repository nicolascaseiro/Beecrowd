#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_C 1002
#define MAX_N 10010

int contador[MAX_C], soma[MAX_N][MAX_C], tamanho[MAX_N], n;

int minimo(int a, int b) {
    return a < b ? a : b;
}

int valor_absoluto(int x) {
    return x < 0 ? -x : x;
}

int main() {
    
    while (1) {
        if (scanf("%d", &n) != 1) break;
        if (n == 0) break;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &tamanho[i]);
            memset(contador, 0, sizeof(contador));
            for (int j = 1; j <= tamanho[i]; j++) {
                int atual;
                scanf("%d", &atual);
                contador[atual + 1]++;
            }
            for (int j = 1; j < MAX_C; j++) {
                soma[i][j] = contador[j] + soma[i][j - 1];
            }
        }

        int resposta = 1000000000;
        for (int j = 1; j < MAX_C; j++) {
            int temp = 0;
            for (int i = 1; i <= n; i++) {
                int antes = soma[i][j - 1];
                int depois = tamanho[i] - antes;
                temp += valor_absoluto(antes - depois);
            }
            resposta = minimo(resposta, temp);
        }
        printf("%d\n", resposta);
    }
    return 0;
}
