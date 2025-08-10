#include <stdio.h>

char entrada[1001];

int main() {
    
    int n;
    while (scanf("%d", &n) && n) {
        scanf("%s", entrada);
        char direcao = 'N';
        for (int i = 0; i < n; i++) {
            if (direcao == 'N') {
                if (entrada[i] == 'D') direcao = 'L';
                else if (entrada[i] == 'E') direcao = 'O';
            } else if (direcao == 'S') {
                if (entrada[i] == 'D') direcao = 'O';
                else if (entrada[i] == 'E') direcao = 'L';
            } else if (direcao == 'L') {
                if (entrada[i] == 'D') direcao = 'S';
                else if (entrada[i] == 'E') direcao = 'N';
            } else if (direcao == 'O') {
                if (entrada[i] == 'D') direcao = 'N';
                else if (entrada[i] == 'E') direcao = 'S';
            }
        }
        printf("%c\n", direcao);
    }
    return 0;
}
