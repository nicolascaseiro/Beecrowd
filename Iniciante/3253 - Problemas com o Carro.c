#include <stdio.h>

#define MAX 1000

int nro_ruas;
int ruas_adjacentes[MAX][MAX];
int tamanho_ruas_adjacentes[MAX];
int chegam[MAX][MAX];
int tamanho_chegam[MAX];
int ordem_entrada[MAX];
int visitado[MAX];
int visitado2[MAX];

void dfs(int vetor[][MAX], int tamanho[], int inicio, int visitados[]) {
    int pilha[MAX], topo = 0;
    pilha[topo++] = inicio;
    for (int i = 0; i < MAX; i++)
        visitados[i] = 0;
    while (topo > 0) {
        int atual = pilha[--topo];
        if (!visitados[atual]) {
            visitados[atual] = 1;
            for (int i = 0; i < tamanho[atual]; i++) {
                int rua = vetor[atual][i];
                if (!visitados[rua]) {
                    pilha[topo++] = rua;
                }
            }
        }
    }
}

int main() {
    scanf("%d", &nro_ruas);
    for (int i = 0; i < MAX; i++) {
        tamanho_ruas_adjacentes[i] = 0;
        tamanho_chegam[i] = 0;
    }
    for (int i = 0; i < nro_ruas; i++) {
        int id, nro_alcancaveis;
        scanf("%d %d", &id, &nro_alcancaveis);
        ordem_entrada[i] = id;
        for (int j = 0; j < nro_alcancaveis; j++) {
            int alc;
            scanf("%d", &alc);
            ruas_adjacentes[id][tamanho_ruas_adjacentes[id]++] = alc;
            chegam[alc][tamanho_chegam[alc]++] = id;
        }
    }
    dfs(ruas_adjacentes, tamanho_ruas_adjacentes, 0, visitado);
    dfs(chegam, tamanho_chegam, 0, visitado2);
    int sem_problema = 1;
    for (int i = 0; i < nro_ruas; i++) {
        int id = ordem_entrada[i];
        if (!visitado2[id]) {
            printf("TRAPPED %d\n", id);
            sem_problema = 0;
        }
    }
    for (int i = 0; i < nro_ruas; i++) {
        int id = ordem_entrada[i];
        if (!visitado[id]) {
            printf("UNREACHABLE %d\n", id);
            sem_problema = 0;
        }
    }
    if (sem_problema) {
        printf("NO PROBLEMS\n");
    }
    return 0;
}
