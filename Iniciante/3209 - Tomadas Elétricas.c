#include <stdio.h>

int main() {

    int aparelhos_conectados;
    
    int N, K;
    
    scanf("%d", &N);

    for (int i = 0; i < N; i++){

        scanf("%d", &K);

        int tomadas, total_tomadas = 0;

        for (int j = 0; j < K; j++){

            scanf("%d", &tomadas);
            total_tomadas += tomadas;
        }

        aparelhos_conectados = total_tomadas - K + 1;

        printf("%d\n", aparelhos_conectados);

    }

    return 0;
}
