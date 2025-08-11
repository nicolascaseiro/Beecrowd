#include <stdio.h>

#define MAX_COLUNAS 110

int problemas_resolvidos[MAX_COLUNAS];

int main() {
    int linhas, colunas;

    while (scanf("%d %d", &linhas, &colunas) && (linhas || colunas)) {
        for (int i = 0; i < colunas; i++) problemas_resolvidos[i] = 0;

        int condicao1 = 1, condicao2 = 1, condicao3 = 1, condicao4 = 1;

        for (int i = 0; i < linhas; i++) {
            int resolvidos_por_participante = 0;
            for (int j = 0; j < colunas; j++) {
                int entrada;
                scanf("%d", &entrada);
                if (entrada) {
                    resolvidos_por_participante++;
                    problemas_resolvidos[j]++;
                }
            }
            if (resolvidos_por_participante == 0) condicao4 = 0;
            if (resolvidos_por_participante == colunas) condicao1 = 0;
        }

        for (int i = 0; i < colunas; i++) {
            if (problemas_resolvidos[i] == linhas) condicao3 = 0;
            if (problemas_resolvidos[i] == 0) condicao2 = 0;
        }

        printf("%d\n", condicao1 + condicao2 + condicao3 + condicao4);
    }

    return 0;
}
