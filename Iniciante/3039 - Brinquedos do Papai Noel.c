#include <stdio.h>

int main() {
    int n, m = 0, f = 0;
    scanf("%d", &n);
    char nome[101], tipo;

    for (int i = 0; i < n; i++) {
        scanf("%s %c", nome, &tipo);
        if (tipo == 'M') {
            m++;
        } else {
            f++;
        }
    }

    printf("%d carrinhos\n", m);
    printf("%d bonecas\n", f);
    return 0;
}
