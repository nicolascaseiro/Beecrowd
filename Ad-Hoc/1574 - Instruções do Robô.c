#include <stdio.h>
#include <string.h>

int main() {
    int testes;
    scanf("%d", &testes);

    while (testes--) {
        int posicao = 0, instrucoes;
        scanf("%d", &instrucoes);

        char historico[instrucoes][10];

        for (int i = 0; i < instrucoes; i++) {
            char linha[20];
            scanf(" %[^\n]", linha);

            if (strcmp(linha, "LEFT") == 0) {
                posicao--;
                strcpy(historico[i], "LEFT");
            } else if (strcmp(linha, "RIGHT") == 0) {
                posicao++;
                strcpy(historico[i], "RIGHT");
            } else {
                int indice;
                sscanf(linha, "SAME AS %d", &indice);
                if (strcmp(historico[indice - 1], "RIGHT") == 0) {
                    posicao++;
                    strcpy(historico[i], "RIGHT");
                } else {
                    posicao--;
                    strcpy(historico[i], "LEFT");
                }
            }
        }

        printf("%d\n", posicao);
    }

    return 0;
}
