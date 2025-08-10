#include <stdio.h>

int main() {
    
    int R;

    while (scanf("%d", &R) == 1 && R) {
        int M[R], L[R];
        int soma_M = 0, soma_L = 0;

        for (int i = 0; i < R; i++) {
            scanf("%d", &M[i]);
            soma_M += M[i];
        }

        for (int i = 0; i < R; i++) {
            scanf("%d", &L[i]);
            soma_L += L[i];
        }

        int tem_trio_M = 0, tem_trio_L = 0;

        for (int i = 1; i < R - 1; i++) {
            if (M[i] == M[i - 1] && M[i] == M[i + 1]) {
                tem_trio_M = 1;
            }
            if (L[i] == L[i - 1] && L[i] == L[i + 1]) {
                tem_trio_L = 1;
            }

            if (tem_trio_M && !tem_trio_L) {
                soma_M += 30;
                break;
            }
            if (tem_trio_L && !tem_trio_M) {
                soma_L += 30;
                break;
            }
        }

        if (soma_M > soma_L)
            printf("M\n");
        else if (soma_L > soma_M)
            printf("L\n");
        else
            printf("T\n");
    }

    return 0;
}
