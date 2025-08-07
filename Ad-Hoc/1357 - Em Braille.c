#include <stdio.h>
#include <string.h>

char str_braile[900];

char braile[10][7] = {
    ".***..",
    "*.....",
    "*.*...",
    "**....",
    "**.*..",
    "*..*..",
    "***...",
    "****..",
    "*.**..",
    ".**..."
};

void to_braile(const char *str) {
    int n = (int)strlen(str) * 3;
    int i, k, j;

    for (i = 0; str[i] != '\0'; i++) {
        j = str[i] - '0';

        k = 3 * i;
        str_braile[k] = braile[j][0];
        str_braile[k + 1] = braile[j][1];
        str_braile[k + 2] = ' ';

        k += n;
        str_braile[k] = braile[j][2];
        str_braile[k + 1] = braile[j][3];
        str_braile[k + 2] = ' ';

        k += n;
        str_braile[k] = braile[j][4];
        str_braile[k + 1] = braile[j][5];
        str_braile[k + 2] = ' ';
    }

    str_braile[n - 1] = '\n';
    str_braile[2 * n - 1] = '\n';
    str_braile[3 * n - 1] = '\0';

    printf("%s\n", str_braile);
}

int find(const char *str) {
    int i;
    for (i = 0; i < 10; i++) {
        if (strncmp(str, braile[i], 6) == 0) return i;
    }
    return -1;
}

void to_num(char *str, int s) {
    int k, n = s * 3;
    char num[7];
    int i;
    str[0] = '\0';

    for (i = 0; i < s; i++) {
        k = 3 * i;
        num[0] = str_braile[k];
        num[1] = str_braile[k + 1];

        k += n;
        num[2] = str_braile[k];
        num[3] = str_braile[k + 1];

        k += n;
        num[4] = str_braile[k];
        num[5] = str_braile[k + 1];
        num[6] = '\0';

        int val = find(num);
        if (val == -1) val = 0;

        int len = (int)strlen(str);
        str[len] = val + '0';
        str[len + 1] = '\0';
    }

    printf("%s\n", str);
}

int main() {
    
    int d;
    char c;
    char str[301];

    while (scanf("%d", &d) == 1 && d != 0) {
        getchar();
        c = getchar();

        if (c == 'S') {
            scanf("%s", str);
            to_braile(str);
        } else {
            getchar();
            fgets(str_braile, 900, stdin);
            fgets(str_braile + d * 3, 900, stdin);
            fgets(str_braile + 2 * d * 3, 900, stdin);
            to_num(str, d);
        }
    }

    return 0;
}
