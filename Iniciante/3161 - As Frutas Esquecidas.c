#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void strminusculo(char *s) {
    for (int i = 0; s[i]; i++) {
        s[i] = tolower((unsigned char)s[i]);
    }
}

void strinverte(char *s, char *out) {
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        out[i] = s[len - 1 - i];
    }
    out[len] = '\0';
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    getchar();

    char frutas[n][51];
    for (int i = 0; i < n; i++) {
        fgets(frutas[i], 51, stdin);
        frutas[i][strcspn(frutas[i], "\n")] = '\0';
        strminusculo(frutas[i]);
    }

    char buffer[10000] = "";
    char linha[201];
    for (int i = 0; i < m; i++) {
        fgets(linha, 201, stdin);
        linha[strcspn(linha, "\n")] = '\0';
        strminusculo(linha);
        strcat(buffer, linha);
        strcat(buffer, " ");
    }

    for (int i = 0; i < n; i++) {
        char fruta_inv[51];
        strinverte(frutas[i], fruta_inv);

        if (strstr(buffer, frutas[i]) != NULL || strstr(buffer, fruta_inv) != NULL) {
            printf("Sheldon come a fruta %s\n", frutas[i]);
        } else {
            printf("Sheldon detesta a fruta %s\n", frutas[i]);
        }
    }

    return 0;
}
