#include <stdio.h>
#include <string.h>

int main() {
    char s[101];
    while (scanf("%s", s) != EOF) {
        int len = strlen(s);
        if (len > 3) {
            printf("Essa coluna nao existe Tobias!\n");
            continue;
        }
        char x[105] = "@@";
        strcat(x, s);
        int xlen = strlen(x);

        char sub[4];
        strncpy(sub, x + xlen - 3, 3);
        sub[3] = '\0';

        if (strcmp(sub, "XFD") <= 0) {
            int a[3];
            for (int i = 0; i < 3; i++) {
                a[i] = sub[i] - '@';
            }
            int n = a[0] * 676 + a[1] * 26 + a[2];
            printf("%d\n", n);
        } else {
            printf("Essa coluna nao existe Tobias!\n");
        }
    }
    return 0;
}
