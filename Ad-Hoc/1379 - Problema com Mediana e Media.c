#include <stdio.h>

int main() {
    
    int A, B, C;
    while (scanf("%d %d", &A, &B) == 2 && (A + B)) {
        C = 2 * A - B;
        printf("%d\n", C);
    }
    return 0;
}
