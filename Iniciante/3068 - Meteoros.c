#include <stdio.h>

int main() {
    int x1, y1, x2, y2, n, t = 0;
    while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) == 4) {
        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0)
            break;
        t++;
        scanf("%d", &n);
        int cont = 0;
        for (int i = 0; i < n; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            if (x >= x1 && x <= x2 && y <= y1 && y >= y2) {
                cont++;
            }
        }
        printf("Teste %d\n%d\n", t, cont);
    }
    return 0;
}
