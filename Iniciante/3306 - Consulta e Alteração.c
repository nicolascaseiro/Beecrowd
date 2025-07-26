#include <stdio.h>
#include <stdlib.h>

void atualizar_vetor(int* vetor, int A, int B, int V) {
    for (int i = A - 1; i < B; i++) {
        vetor[i] += V;
    }
}

int mdc(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int* vetor = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &vetor[i]);
    }

    for (int c = 0; c < Q; c++) {
        int tipo_consulta;
        scanf("%d", &tipo_consulta);

        if (tipo_consulta == 1) {
            int A, B, V;
            scanf("%d %d %d", &A, &B, &V);
            atualizar_vetor(vetor, A, B, V);
        } else if (tipo_consulta == 2) {
            int A, B;
            scanf("%d %d", &A, &B);
            int resultado_mdc = vetor[A - 1];
            for (int i = A; i < B; i++) {
                resultado_mdc = mdc(resultado_mdc, vetor[i]);
            }
            printf("%d\n", resultado_mdc);
        }
    }

    free(vetor);
    return 0;
}
