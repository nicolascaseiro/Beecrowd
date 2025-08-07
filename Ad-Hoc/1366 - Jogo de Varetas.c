#include <stdio.h>

int main() {
    
    int n;
    while (scanf("%d", &n) == 1 && n != 0) {
        int resposta = 0;
        while (n--) {
            int x, y;
            scanf("%d %d", &y, &x);
            resposta += x / 2;
        }
        printf("%d\n", resposta / 2);
    }
    return 0;
}
