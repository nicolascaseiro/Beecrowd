#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n > 0) {
        int seculo = (n + 99) / 100;
        printf("%d\n", seculo);
    }
    return 0;
}
