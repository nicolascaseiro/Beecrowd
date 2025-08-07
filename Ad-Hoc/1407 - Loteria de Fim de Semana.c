#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    
    int N, C, K;

    while (1) {
        if (scanf("%d %d %d", &N, &C, &K) != 3) break;
        if (N == 0) break;

        int *X = (int *) malloc(C * sizeof(int));
        int *A = (int *) calloc(K + 1, sizeof(int));
        int *RESP = (int *) malloc((K + 1) * sizeof(int));
        int resp_size = 0;
        int menor = INT_MAX;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < C; j++) {
                scanf("%d", &X[j]);
                A[X[j]]++;
            }
        }

        for (int j = 1; j <= K; j++) {
            if (A[j] < menor) {
                menor = A[j];
                resp_size = 0;
                RESP[resp_size++] = j;
            } else if (A[j] == menor) {
                RESP[resp_size++] = j;
            }
        }

        for (int j = 0; j < resp_size; j++) {
            printf("%d", RESP[j]);
            if (j != resp_size -1) printf(" ");
        }
        printf("\n");

        free(X);
        free(A);
        free(RESP);
    }

    return 0;
}
