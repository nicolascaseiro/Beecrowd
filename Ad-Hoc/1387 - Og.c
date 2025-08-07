#include <stdio.h>

int main() {
    
    int A, B;

    while (1) {
        if (scanf("%d %d", &A, &B) != 2) break;
        if (A == 0 && B == 0) break;

        printf("%d\n", A + B);
    }

    return 0;
}
