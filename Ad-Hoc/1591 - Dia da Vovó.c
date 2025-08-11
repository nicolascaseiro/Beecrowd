#include <stdio.h>
#include <string.h>

char matriz[55][55];
int altura, largura;

int buscar_direita(char *palavra, int linha, int coluna) {
    int tamanho = strlen(palavra);
    for (int i = 0; i < tamanho; i++) {
        if (matriz[linha][coluna + i] != palavra[i]) {
            return 0;
        }
    }
    return 1;
}

int buscar_baixo(char *palavra, int linha, int coluna) {
    int tamanho = strlen(palavra);
    for (int i = 0; i < tamanho; i++) {
        if (matriz[linha + i][coluna] != palavra[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int testes;
    scanf("%d", &testes);

    while (testes--) {
        scanf("%d %d", &altura, &largura);
        for (int i = 0; i < altura; i++) {
            scanf("%s", matriz[i]);
        }

        int consultas;
        scanf("%d", &consultas);

        while (consultas--) {
            char palavra[55];
            scanf("%s", palavra);
            int tamanho = strlen(palavra);
            int total = 0;

            if (tamanho == 1) {
                for (int i = 0; i < altura; i++) {
                    for (int j = 0; j < largura; j++) {
                        if (matriz[i][j] == palavra[0]) {
                            total++;
                        }
                    }
                }
            } else {
                for (int i = 0; i < altura; i++) {
                    for (int j = 0; j < largura; j++) {
                        if (matriz[i][j] == palavra[0]) {
                            if (j <= largura - tamanho) {
                                total += buscar_direita(palavra, i, j);
                            }
                            if (i <= altura - tamanho) {
                                total += buscar_baixo(palavra, i, j);
                            }
                        }
                    }
                }
            }

            printf("%d\n", total);
        }
    }

    return 0;
}
