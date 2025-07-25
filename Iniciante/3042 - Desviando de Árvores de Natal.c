#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int m;
    scanf("%d", &m);

    while (m > 0) {
        int p = 2;
        int cont = 0;
        char linha[10];

        for (int i = 0; i < m; i++) {
            scanf(" %[^\n]", linha);

            if (strcmp(linha, "0 1 1") == 0 && p != 1) {
                cont += abs(p - 1);
                p = 1;
            } else if (strcmp(linha, "1 0 1") == 0 && p != 2) {
                cont += abs(p - 2);
                p = 2;
            } else if (strcmp(linha, "1 1 0") == 0 && p != 3) {
                cont += abs(p - 3);
                p = 3;
            }
        }

        printf("%d\n", cont);
        scanf("%d", &m);
    }

    return 0;
}
