#include <stdio.h>
#include <string.h>

int main() {
    int n, x;
    char z[2];
    scanf("%d %1s", &n, z);

    int a = (z[0] == 'A');
    int b = (z[0] == 'B');
    int c = (z[0] == 'C');

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        if (x == 1) {
            int temp = a;
            a = b;
            b = temp;
        } else if (x == 2) {
            int temp = b;
            b = c;
            c = temp;
        } else {
            int temp = a;
            a = c;
            c = temp;
        }
    }

    if (a) printf("A\n");
    else if (b) printf("B\n");
    else printf("C\n");

    return 0;
}
