#include <stdio.h>

int main() {

    double a, b, flutuacao;
    scanf("%lf %lf", &a, &b);
    flutuacao = ((1.0 + a / 100.0) * (1.0 + b / 100.0) - 1.0) * 100.0;
    printf("%.6f\n", flutuacao);

    return 0;
}
