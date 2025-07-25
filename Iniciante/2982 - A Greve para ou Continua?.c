#include <stdio.h>
#include <string.h>

int main() {
    int n, v = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        char tipo[2];
        int valor;
        scanf("%s %d", tipo, &valor);
        if (strcmp(tipo, "G") == 0) {
            v += valor;
        } else {
            v -= valor;
        }
    }
    if (v > 0) {
        printf("NAO VAI TER CORTE, VAI TER LUTA!\n");
    } else {
        printf("A greve vai parar.\n");
    }
    return 0;
}
