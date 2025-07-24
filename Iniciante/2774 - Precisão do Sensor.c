#include <stdio.h>
#include <math.h>

int main() {
    int h, m;
    while (scanf("%d %d", &h, &m) == 2) {
        double valores[105000];
        int total = 0;
        double x, soma = 0.0;
        while (scanf("%lf", &x) == 1) {
            valores[total++] = x;
            soma += x;
            if (getchar() == '\n') break;
        }
        double media = soma / total;
        double somaQuadrados = 0.0;
        for (int i = 0; i < total; i++) {
            double diff = valores[i] - media;
            somaQuadrados += diff * diff;
        }
        double precisao = sqrt(somaQuadrados / (total - 1));
        printf("%.5lf\n", precisao);
    }
    return 0;
}
