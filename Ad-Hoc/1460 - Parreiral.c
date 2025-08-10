#include <stdio.h>
#include <stdlib.h>

#define MAXN 500

int matriz[MAXN][MAXN];
int maior[MAXN], menor[MAXN];
int linhas, colunas;

typedef struct {
    int val[MAXN];
    int idx[MAXN];
    int inicio, fim;
} deque_t;

void inicializa_deque(deque_t *d) {
    d->inicio = 0;
    d->fim = -1;
}

void adiciona_max(deque_t *d, int i, int v) {
    while (d->fim >= d->inicio && d->val[d->fim] <= v) d->fim--;
    d->fim++;
    d->idx[d->fim] = i;
    d->val[d->fim] = v;
}

void adiciona_min(deque_t *d, int i, int v) {
    while (d->fim >= d->inicio && d->val[d->fim] >= v) d->fim--;
    d->fim++;
    d->idx[d->fim] = i;
    d->val[d->fim] = v;
}

void remove_inicio(deque_t *d) {
    d->inicio++;
}

int indice_inicio(deque_t *d) {
    return d->idx[d->inicio];
}

int verifica(int k) {
    deque_t janela_maior, janela_menor;
    inicializa_deque(&janela_maior);
    inicializa_deque(&janela_menor);

    for (int i = 0; i < k; i++) {
        adiciona_max(&janela_maior, i, maior[i]);
        adiciona_min(&janela_menor, i, menor[i]);
    }

    int delta = janela_menor.val[janela_menor.inicio] - janela_maior.val[janela_maior.inicio] + 1;
    if (delta >= k) return 1;

    for (int i = k; i < linhas; i++) {
        adiciona_max(&janela_maior, i, maior[i]);
        if (indice_inicio(&janela_maior) <= i - k) remove_inicio(&janela_maior);

        adiciona_min(&janela_menor, i, menor[i]);
        if (indice_inicio(&janela_menor) <= i - k) remove_inicio(&janela_menor);

        delta = janela_menor.val[janela_menor.inicio] - janela_maior.val[janela_maior.inicio] + 1;
        if (delta >= k) return 1;
    }
    return 0;
}

int busca_inferior(int *arr, int tamanho, int x) {
    int baixo = 0, alto = tamanho;
    while (baixo < alto) {
        int meio = (baixo + alto) / 2;
        if (arr[meio] < x) baixo = meio + 1;
        else alto = meio;
    }
    return baixo;
}

int busca_superior(int *arr, int tamanho, int x) {
    int baixo = 0, alto = tamanho;
    while (baixo < alto) {
        int meio = (baixo + alto) / 2;
        if (arr[meio] <= x) baixo = meio + 1;
        else alto = meio;
    }
    return baixo;
}

int main() {
    while (scanf("%d %d", &linhas, &colunas) == 2 && (linhas || colunas)) {
        for (int i = 0; i < linhas; i++) {
            for (int j = 0; j < colunas; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        int consultas;
        scanf("%d", &consultas);
        while (consultas--) {
            int a, b;
            scanf("%d %d", &a, &b);
            for (int i = 0; i < linhas; i++) {
                if (matriz[i][colunas - 1] < a) {
                    maior[i] = colunas + 2;
                } else {
                    int pos = busca_inferior(matriz[i], colunas, a);
                    maior[i] = pos + 1;
                }
                if (matriz[i][0] > b) {
                    menor[i] = -1;
                } else {
                    int pos = busca_superior(matriz[i], colunas, b) - 1;
                    menor[i] = pos + 1;
                }
            }
            int inicio = 1, fim = (linhas < colunas) ? linhas : colunas, resposta = 0;
            while (inicio <= fim) {
                int meio = (inicio + fim) / 2;
                if (verifica(meio)) {
                    resposta = meio;
                    inicio = meio + 1;
                } else {
                    fim = meio - 1;
                }
            }
            printf("%d\n", resposta);
        }
        printf("-\n");
    }
    return 0;
}
