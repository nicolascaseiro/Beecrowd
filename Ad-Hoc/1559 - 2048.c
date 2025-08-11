#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int matriz[4][4];
        int terminou = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                scanf("%d", &matriz[i][j]);
                if (matriz[i][j] == 2048) terminou = 1;
            }
        }
        if (terminou) {
            printf("NONE\n");
            continue;
        }

        int pode_baixo = 0;
        for (int i = 0; i < 3 && !pode_baixo; i++) {
            for (int j = 0; j < 4; j++) {
                if (matriz[i][j] != 0 && (matriz[i + 1][j] == 0 || matriz[i + 1][j] == matriz[i][j])) {
                    pode_baixo = 1;
                    break;
                }
            }
        }

        int pode_esquerda = 0;
        for (int i = 0; i < 4 && !pode_esquerda; i++) {
            for (int j = 1; j < 4; j++) {
                if (matriz[i][j] != 0 && (matriz[i][j - 1] == 0 || matriz[i][j - 1] == matriz[i][j])) {
                    pode_esquerda = 1;
                    break;
                }
            }
        }

        int pode_direita = 0;
        for (int i = 0; i < 4 && !pode_direita; i++) {
            for (int j = 0; j < 3; j++) {
                if (matriz[i][j] != 0 && (matriz[i][j + 1] == 0 || matriz[i][j + 1] == matriz[i][j])) {
                    pode_direita = 1;
                    break;
                }
            }
        }

        int pode_cima = 0;
        for (int i = 1; i < 4 && !pode_cima; i++) {
            for (int j = 0; j < 4; j++) {
                if (matriz[i][j] != 0 && (matriz[i - 1][j] == 0 || matriz[i - 1][j] == matriz[i][j])) {
                    pode_cima = 1;
                    break;
                }
            }
        }

        int primeiro = 1;
        if (!pode_baixo && !pode_esquerda && !pode_direita && !pode_cima) {
            printf("NONE\n");
        } else {
            if (pode_baixo) {
                printf("DOWN");
                primeiro = 0;
            }
            if (pode_esquerda) {
                if (!primeiro) printf(" ");
                printf("LEFT");
                primeiro = 0;
            }
            if (pode_direita) {
                if (!primeiro) printf(" ");
                printf("RIGHT");
                primeiro = 0;
            }
            if (pode_cima) {
                if (!primeiro) printf(" ");
                printf("UP");
            }
            printf("\n");
        }
    }
    return 0;
}
