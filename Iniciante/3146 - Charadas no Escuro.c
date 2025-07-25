#include <stdio.h>

int main() {
    double r, pi = 3.14, circunferencia;
    scanf("%lf", &r);
    circunferencia = 2 * pi * r;
    printf("%.2f\n", circunferencia);
    return 0;
}
