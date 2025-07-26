#include <stdio.h>

int main() {
    
    int entrada[3];
    scanf("%d %d %d", &entrada[0], &entrada[1], &entrada[2]);

    int g = entrada[0] + entrada[1];
    int c = entrada[2];
    int resp = 0;

    while (g >= c) {
        resp += g / c;
        g = (g / c) + (g % c);
    }

    printf("%d\n", resp);

    return 0;
}
