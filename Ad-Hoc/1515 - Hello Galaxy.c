#include <stdio.h>
#include <string.h>
#include <limits.h>

#define MAX_NOME 110

int main() {
    int quantidade;

    while (scanf("%d", &quantidade) && quantidade != 0) {
        int minimo = INT_MAX;
        char nome_atual[MAX_NOME];
        char nome_resposta[MAX_NOME];

        for (int i = 0; i < quantidade; i++) {
            int ano, tempo;
            scanf("%s %d %d", nome_atual, &ano, &tempo);
            int inicio = ano - tempo;

            if (inicio < minimo) {
                minimo = inicio;
                strcpy(nome_resposta, nome_atual);
            }
        }

        printf("%s\n", nome_resposta);
    }

    return 0;
}
