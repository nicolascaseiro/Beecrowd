#include <stdio.h>
#include <math.h>

typedef struct {
    double primeiro;
    double segundo;
} Par;

double solucao(double a, double b, double c) {
    return (b + sqrt(b * b - 4 * a * c)) / (2 * a);
}

int main() {
    double a[5];
    scanf("%lf %lf %lf %lf %lf", &a[0], &a[1], &a[2], &a[3], &a[4]);

    double l = a[0], k = a[1], t1 = a[2], t2 = a[3], h = a[4];

    Par min_max;

    if (l > h) {
        min_max.primeiro = h;
        min_max.segundo = h;
    } else {
        // k * l * t1 + f^2 == f * (h + k * (t1 + t2))
        // f é raiz da equação quadrática: f^2 - f*(h + k*(t1 + t2)) + k*l*t1 = 0
        double b = h + k * (t1 + t2);
        double c = k * l * t1;
        double f = solucao(1.0, b, c);

        if (l < h) {
            min_max.primeiro = f;
            min_max.segundo = f;
        } else {
            min_max.primeiro = h;
            min_max.segundo = f;
        }
    }

    printf("%.9f %.9f\n", min_max.primeiro, min_max.segundo);

    return 0;
}
