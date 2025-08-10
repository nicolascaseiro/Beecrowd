#include <stdio.h>
#include <string.h>

#define TAM 105

int main() {
    
    int times, jogos;

    while (1) {
        if (scanf("%d %d", &times, &jogos) != 2)
            break;

        if (times == 0 && jogos == 0)
            break;

        int pontos_total = 0;
        char nome[TAM];

        for (int i = 0; i < times; i++) {
            scanf("%s", nome);
            int pontos;
            scanf("%d", &pontos);
            pontos_total += pontos;
        }

        printf("%d\n", 3 * jogos - pontos_total);
    }

    return 0;
}
