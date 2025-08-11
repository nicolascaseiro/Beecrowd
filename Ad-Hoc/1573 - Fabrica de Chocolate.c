#include <stdio.h>
#include <math.h>

int main() {

    int A, B, C;

    while (1) {
        scanf("%d %d %d", &A, &B, &C);
        if (A == 0 && B == 0 && C == 0) break;

        int volume = A * B * C;
        int raiz_cubica = (int)floor(pow(volume, 1.0/3.0));

        printf("%d\n", raiz_cubica);
    }

    return 0;
}
