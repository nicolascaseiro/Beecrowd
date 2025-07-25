#include <stdio.h>

int main() {
    int b, g;
    scanf("%d %d", &b, &g);

    int faltam = g / 2 - b;

    if (faltam > 0) {
        printf("Faltam %d bolinha(s)\n", faltam);
    } else {
        printf("Amelia tem todas bolinhas!\n");
    }

    return 0;
}
