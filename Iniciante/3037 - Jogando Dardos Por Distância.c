#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int joao = 0, maria = 0;
        for (int j = 0; j < 3; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            joao += x * y;
        }
        for (int j = 0; j < 3; j++) {
            int x, y;
            scanf("%d %d", &x, &y);
            maria += x * y;
        }

        if (joao > maria) {
            printf("JOAO\n");
        } else {
            printf("MARIA\n");
        }
    }

    return 0;
}
