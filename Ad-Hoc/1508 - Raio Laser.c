#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 100005

typedef struct {
    int x, y;
} Ponto;

int comparar_x(const void *a, const void *b) {
    Ponto *pa = (Ponto *)a;
    Ponto *pb = (Ponto *)b;
    return pa->x - pb->x;
}

int comparar_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int limite_inferior(int *vetor, int tamanho, int valor) {
    int esquerda = 0, direita = tamanho;
    while (esquerda < direita) {
        int meio = (esquerda + direita) / 2;
        if (vetor[meio] < valor) esquerda = meio + 1;
        else direita = meio;
    }
    return esquerda;
}

int limite_superior(int *vetor, int tamanho, int valor) {
    int esquerda = 0, direita = tamanho;
    while (esquerda < direita) {
        int meio = (esquerda + direita) / 2;
        if (vetor[meio] <= valor) esquerda = meio + 1;
        else direita = meio;
    }
    return esquerda;
}

void resolver() {
    int n, largura;
    if (scanf("%d %d", &n, &largura) != 2 || (n == 0 && largura == 0)) {
        exit(0);
    }

    Ponto pontos[MAXN];
    int coordenadas_y[MAXN];

    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &pontos[i].x, &pontos[i].y);
        coordenadas_y[i] = pontos[i].y;
    }

    pontos[n].x = INT_MAX;
    pontos[n].y = 0;

    qsort(pontos, n + 1, sizeof(Ponto), comparar_x);
    qsort(coordenadas_y, n, sizeof(int), comparar_int);

    int contador = 0, ultimo_x = -INT_MAX;

    for (int i = 0; i < n; ++i) {
        int menor_y = INT_MAX, maior_y = -INT_MAX;

        if (ultimo_x == pontos[i].x) continue;
        ultimo_x = pontos[i].x;

        for (int j = i; j < n; ++j) {
            if (pontos[j].x - pontos[i].x > largura) break;

            if (pontos[j].y < menor_y) menor_y = pontos[j].y;
            if (pontos[j].y > maior_y) maior_y = pontos[j].y;

            if (pontos[j].x == pontos[j + 1].x) continue;

            contador++;

            if (maior_y - menor_y <= largura) {
                int esquerda = limite_inferior(coordenadas_y, n, menor_y);
                int direita = limite_superior(coordenadas_y, n, maior_y);
                if (direita - esquerda == j - i + 1) {
                    contador--;
                }
            }
        }
    }

    int unicos_y[MAXN], total_unicos = 0;
    unicos_y[total_unicos++] = coordenadas_y[0];
    for (int i = 1; i < n; ++i) {
        if (coordenadas_y[i] != coordenadas_y[i - 1]) {
            unicos_y[total_unicos++] = coordenadas_y[i];
        }
    }

    int k = 0;
    for (int i = 0; i < total_unicos; ++i) {
        while (k < total_unicos && unicos_y[k] - unicos_y[i] <= largura) {
            ++k;
        }
        contador += k - i;
    }

    printf("%d\n", contador);
}

int main() {
    
    for (;;) {
        resolver();
    }
    return 0;
}
