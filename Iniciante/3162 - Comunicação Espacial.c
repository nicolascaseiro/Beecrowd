#include <stdio.h>
#include <math.h>

int main() {
    int n;
    scanf("%d", &n);

    int ss[n][3];
    for (int i = 0; i < n; i++) {
        scanf("%d %d %d", &ss[i][0], &ss[i][1], &ss[i][2]);
    }

    for (int i = 0; i < n; i++) {
        double distancia = 500.0;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int a = ss[i][0] - ss[j][0];
                int b = ss[i][1] - ss[j][1];
                int c = ss[i][2] - ss[j][2];
                double dif = sqrt(a * a + b * b + c * c);
                if (dif < distancia) {
                    distancia = dif;
                }
            }
        }
        if (distancia <= 20) {
            printf("A\n");
        } else if (distancia <= 50) {
            printf("M\n");
        } else {
            printf("B\n");
        }
    }

    return 0;
}
