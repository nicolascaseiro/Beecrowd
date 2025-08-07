#include <stdio.h>

#define MAX 100001

int soldados[MAX][2];

#define anterior(i) soldados[i][0]
#define proximo(i) soldados[i][1]

int main() {
    int num_soldados, num_batalhas;

    while (scanf("%d %d", &num_soldados, &num_batalhas), num_soldados || num_batalhas) {
        for (int i = 1; i <= num_soldados; ++i) {
            anterior(i) = i - 1;
            proximo(i) = i + 1;
        }

        proximo(num_soldados) = 0;

        for (int i = 0; i < num_batalhas; ++i) {
            int esquerda, direita;
            scanf("%d %d", &esquerda, &direita);

            proximo(anterior(esquerda)) = proximo(direita);
            anterior(proximo(direita)) = anterior(esquerda);

            int soldado_esquerda = anterior(esquerda);
            int soldado_direita = proximo(direita);

            if (soldado_esquerda && soldado_direita)
                printf("%d %d\n", soldado_esquerda, soldado_direita);
            else if (!soldado_esquerda && soldado_direita)
                printf("* %d\n", soldado_direita);
            else if (soldado_esquerda && !soldado_direita)
                printf("%d *\n", soldado_esquerda);
            else
                printf("* *\n");
        }

        printf("-\n");
    }

    return 0;
}
