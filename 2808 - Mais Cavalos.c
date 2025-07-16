#include <stdio.h>
#include <stdlib.h>

int main() {
    char i[3], d[3];
    scanf("%s %s", i, d);

    int col = abs(i[0] - d[0]);
    int lin = abs((i[1]-'0') - (d[1]-'0'));

    if ((col == 1 && lin == 2) || (col == 2 && lin == 1)) {
        printf("VALIDO\n");
    } else {
        printf("INVALIDO\n");
    }

    return 0;
}
