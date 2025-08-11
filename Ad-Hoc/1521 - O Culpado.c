#include <stdio.h>

#define MAX 55

int adjacencia[MAX][1];

void DFS(int atual) {
    if (adjacencia[atual][0] == atual) {
        printf("%d\n", atual);
        return;
    }
    DFS(adjacencia[atual][0]);
}

int main() {
    int quantidade;

    while (scanf("%d", &quantidade) == 1 && quantidade) {
        for (int i = 1; i <= quantidade; i++) {
            int destino;
            scanf("%d", &destino);
            adjacencia[i][0] = destino;
        }

        int inicio;
        scanf("%d", &inicio);
        DFS(inicio);
    }

    return 0;
}
