#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int testes;
    scanf("%d", &testes);
    getchar();

    for (int i = 0; i < testes; i++) {
        char operacao[100];
        fgets(operacao, sizeof(operacao), stdin);

        int tamanho = strlen(operacao);
        if (tamanho > 0 && operacao[tamanho - 1] == '\n') {
            operacao[tamanho - 1] = '\0';
        }

        if (strcmp(operacao, "P=NP") == 0) {
            printf("skipped\n");
        } else {
            char *sinal = strchr(operacao, '+');
            if (sinal) {
                *sinal = '\0';
                int a = atoi(operacao);
                int b = atoi(sinal + 1);
                printf("%d\n", a + b);
            }
        }
    }

    return 0;
}
