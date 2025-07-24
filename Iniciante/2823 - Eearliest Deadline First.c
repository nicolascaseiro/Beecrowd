#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    double total_utilizacao = 0.0;
    for (int i = 0; i < n; i++) {
        int c, p;
        scanf("%d %d", &c, &p);
        total_utilizacao += (double)c / p;
    }

    if (total_utilizacao <= 1.0) {
        printf("OK\n");
    } else {
        printf("FAIL\n");
    }

    return 0;
}
