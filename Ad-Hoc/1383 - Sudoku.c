#include <stdio.h>
#include <string.h>

int s[9][9];

int linha(int x) {
    int n[10] = {0};
    for (int i = 0; i < 9; i++) {
        int val = s[x][i];
        if (val < 1 || val > 9 || n[val]) return 0;
        n[val] = 1;
    }
    return 1;
}

int coluna(int y) {
    int n[10] = {0};
    for (int i = 0; i < 9; i++) {
        int val = s[i][y];
        if (val < 1 || val > 9 || n[val]) return 0;
        n[val] = 1;
    }
    return 1;
}

int quadrante(int x) {
    int n[10] = {0};
    int l = 3 * (x / 3), c = 3 * (x % 3);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int val = s[l + i][c + j];
            if (val < 1 || val > 9 || n[val]) return 0;
            n[val] = 1;
        }
    }
    return 1;
}

int main() {
    
    int n;
    scanf("%d", &n);
    for (int k = 1; k <= n; k++) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &s[i][j]);
            }
        }

        printf("Instancia %d\n", k);
        int valido = 1;

        for (int i = 0; i < 9; i++) {
            if (!linha(i) || !coluna(i) || !quadrante(i)) {
                valido = 0;
                break;
            }
        }

        if (valido) {
            printf("SIM\n\n");
        } else {
            printf("NAO\n\n");
        }
    }

    return 0;
}
