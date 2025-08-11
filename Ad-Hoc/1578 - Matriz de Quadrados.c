#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 25

int main() {
    int casos;
    scanf("%d", &casos);

    for (int caso = 4; caso < casos + 4; caso++) {
        if (caso != 4) printf("\n");

        int ordem;
        scanf("%d", &ordem);

        printf("Quadrado da matriz #%d:\n", caso);

        unsigned long long matriz[MAX][MAX];
        int digitos[MAX];

        for (int i = 0; i < ordem; i++) digitos[i] = 1;

        for (int i = 0; i < ordem; i++) {
            for (int j = 0; j < ordem; j++) {
                scanf("%llu", &matriz[i][j]);
                matriz[i][j] *= matriz[i][j];
                if (matriz[i][j] > 0) {
                    int d = (int)log10((double)matriz[i][j]) + 1;
                    if (d > digitos[j]) digitos[j] = d;
                }
            }
        }

        for (int i = 0; i < ordem; i++) {
            for (int j = 0; j < ordem; j++) {
                if (j > 0) printf(" ");
                printf("%*llu", digitos[j], matriz[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
