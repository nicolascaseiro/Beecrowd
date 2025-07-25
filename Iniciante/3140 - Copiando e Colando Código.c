#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char linha[1001];
    while (1) {
        if (fgets(linha, sizeof(linha), stdin) == NULL) break;
        int i = 0;
        while (linha[i] == ' ') i++;
        if (strncmp(linha + i, "<body>", 6) == 0) break;
    }
    while (1) {
        if (fgets(linha, sizeof(linha), stdin) == NULL) break;
        int i = 0;
        while (linha[i] == ' ') i++;
        if (strncmp(linha + i, "</body>", 7) == 0) break;
        printf("%s", linha);
    }
    return 0;
}
