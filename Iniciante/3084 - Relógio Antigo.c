#include <stdio.h>

int main() {
    int a[2];
    while (scanf("%d %d", &a[0], &a[1]) == 2) {
        int hora = a[0] / 30;
        int minuto = a[1] / 6;
        printf("%02d:%02d\n", hora, minuto);
    }
    return 0;
}
