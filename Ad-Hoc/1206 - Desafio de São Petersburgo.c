#include <stdio.h>
#include <string.h>

#define TAM_TABULEIRO 8
#define LIVRE 0
#define PECA 1
#define ATACADA 2
#define SUPORTE 3

int dx[9] = {0, 1, -1, 0, 0, 1, 1, -1, -1};
int dy[9] = {0, 0, 0, 1, -1, 1, -1, 1, -1};

char entrada[20][6];
int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

int posicao_valida(int x, int y) {
    return x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO &&
           (tabuleiro[x][y] == LIVRE || tabuleiro[x][y] == PECA);
}

void adicionar_peao(int x, int y) {
    int nx1 = x - 1, ny1 = y - 1;
    int nx2 = x + 1, ny2 = y - 1;

    if (nx1 >= 0 && nx1 < TAM_TABULEIRO && ny1 >= 0 && ny1 < TAM_TABULEIRO) {
        if (tabuleiro[nx1][ny1] == LIVRE)
            tabuleiro[nx1][ny1] = ATACADA;
        else if (tabuleiro[nx1][ny1] == PECA)
            tabuleiro[nx1][ny1] = SUPORTE;
    }
    if (nx2 >= 0 && nx2 < TAM_TABULEIRO && ny2 >= 0 && ny2 < TAM_TABULEIRO) {
        if (tabuleiro[nx2][ny2] == LIVRE)
            tabuleiro[nx2][ny2] = ATACADA;
        else if (tabuleiro[nx2][ny2] == PECA)
            tabuleiro[nx2][ny2] = SUPORTE;
    }
}

void adicionar_bispo(int x, int y) {
    int i, j;

    for (i = x - 1, j = y - 1; i >= 0 && j >= 0; i--, j--) {
        if (tabuleiro[i][j] == LIVRE)
            tabuleiro[i][j] = ATACADA;
        else if (tabuleiro[i][j] == PECA) {
            tabuleiro[i][j] = SUPORTE;
            break;
        }
    }
    for (i = x + 1, j = y + 1; i < TAM_TABULEIRO && j < TAM_TABULEIRO; i++, j++) {
        if (tabuleiro[i][j] == LIVRE)
            tabuleiro[i][j] = ATACADA;
        else if (tabuleiro[i][j] == PECA) {
            tabuleiro[i][j] = SUPORTE;
            break;
        }
    }
    for (i = x - 1, j = y + 1; i >= 0 && j < TAM_TABULEIRO; i--, j++) {
        if (tabuleiro[i][j] == LIVRE)
            tabuleiro[i][j] = ATACADA;
        else if (tabuleiro[i][j] == PECA) {
            tabuleiro[i][j] = SUPORTE;
            break;
        }
    }
    for (i = x + 1, j = y - 1; i < TAM_TABULEIRO && j >= 0; i++, j--) {
        if (tabuleiro[i][j] == LIVRE)
            tabuleiro[i][j] = ATACADA;
        else if (tabuleiro[i][j] == PECA) {
            tabuleiro[i][j] = SUPORTE;
            break;
        }
    }
}

void adicionar_torre(int x, int y) {
    int i;

    for (i = x - 1; i >= 0; i--) {
        if (tabuleiro[i][y] == LIVRE)
            tabuleiro[i][y] = ATACADA;
        else if (tabuleiro[i][y] == PECA) {
            tabuleiro[i][y] = SUPORTE;
            break;
        }
    }
    for (i = x + 1; i < TAM_TABULEIRO; i++) {
        if (tabuleiro[i][y] == LIVRE)
            tabuleiro[i][y] = ATACADA;
        else if (tabuleiro[i][y] == PECA) {
            tabuleiro[i][y] = SUPORTE;
            break;
        }
    }
    for (i = y - 1; i >= 0; i--) {
        if (tabuleiro[x][i] == LIVRE)
            tabuleiro[x][i] = ATACADA;
        else if (tabuleiro[x][i] == PECA) {
            tabuleiro[x][i] = SUPORTE;
            break;
        }
    }
    for (i = y + 1; i < TAM_TABULEIRO; i++) {
        if (tabuleiro[x][i] == LIVRE)
            tabuleiro[x][i] = ATACADA;
        else if (tabuleiro[x][i] == PECA) {
            tabuleiro[x][i] = SUPORTE;
            break;
        }
    }
}

void adicionar_rei(int x, int y) {
    int i;
    for (i = 1; i < 9; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= TAM_TABULEIRO || ny >= TAM_TABULEIRO) continue;

        if (tabuleiro[nx][ny] == LIVRE)
            tabuleiro[nx][ny] = ATACADA;
        else if (tabuleiro[nx][ny] == PECA)
            tabuleiro[nx][ny] = SUPORTE;
    }
}

int main(void) {
    int num_pecas;

    while (scanf("%d", &num_pecas) != EOF) {
        int i;

        memset(tabuleiro, 0, sizeof(tabuleiro));

        for (i = 0; i < num_pecas; i++) {
            scanf("%s", entrada[i]);
            int x = entrada[i][1] - 'a';
            int y = entrada[i][2] - '1';
            tabuleiro[x][y] = PECA;
        }

        for (i = 0; i < num_pecas; i++) {
            int x = entrada[i][1] - 'a';
            int y = entrada[i][2] - '1';

            if (entrada[i][0] == 'P')
                adicionar_peao(x, y);
            if (entrada[i][0] == 'T' || entrada[i][0] == 'R')
                adicionar_torre(x, y);
            if (entrada[i][0] == 'B' || entrada[i][0] == 'R')
                adicionar_bispo(x, y);
            if (entrada[i][0] == 'W')
                adicionar_rei(x, y);
        }

        scanf("%s", entrada[num_pecas]);
        int x_rei = entrada[num_pecas][1] - 'a';
        int y_rei = entrada[num_pecas][2] - '1';

        int tem_escapatoria = 0;
        for (i = 0; i < 9; i++) {
            int nx = x_rei + dx[i];
            int ny = y_rei + dy[i];
            if (posicao_valida(nx, ny)) {
                tem_escapatoria = 1;
                break;
            }
        }

        if (tem_escapatoria)
            printf("NAO\n");
        else
            printf("SIM\n");
    }

    return 0;
}
