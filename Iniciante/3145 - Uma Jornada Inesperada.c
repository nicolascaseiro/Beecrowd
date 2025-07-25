#include <stdio.h>

int main() {
    int n, x;
    scanf("%d %d", &n, &x);
    double dias = (double)x / (n + 2);
    printf("%.2f\n", dias);
    return 0;
}
