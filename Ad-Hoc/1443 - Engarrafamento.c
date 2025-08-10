#include <stdio.h>

int main() {
    
    int N;

    while (1) {
        scanf("%d", &N);
        if (N == 0) break;

        double distancia = 0.0, tempo, velocidade = 0.0;
        int inicio, fim, anterior = 0;

        while (N--) {
            scanf("%d %d", &inicio, &fim);
            tempo = inicio - anterior;

            if (velocidade - 2 * tempo < 0.0) {
                tempo = velocidade / 2.0;
                distancia += (velocidade * tempo) / 2.0;
                velocidade = 0.0;
            } else {
                distancia += (velocidade + velocidade - 2 * tempo) * tempo / 2.0;
                velocidade = velocidade - 2 * tempo;
            }

            tempo = fim - inicio;

            if (velocidade + tempo > 10) {
                distancia += (10 + velocidade) * (10 - velocidade) / 2.0;
                tempo = tempo - (10 - velocidade);
                velocidade = 10;
                distancia += tempo * 10;
            } else {
                distancia += (velocidade + velocidade + tempo) * tempo / 2.0;
                velocidade = velocidade + tempo;
            }

            anterior = fim;
        }

        printf("%.2lf\n", distancia);
    }

    return 0;
}
