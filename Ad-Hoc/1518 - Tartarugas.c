#include <stdio.h>
#include <stdlib.h>

#define INF 1000000000

int minimo(int a, int b) {
    return a < b ? a : b;
}

int absoluto(int valor) {
    return valor < 0 ? -valor : valor;
}

int distancia(int xdestino, int ydestino, int x, int y) {
    int a = absoluto(xdestino - x);
    int b = absoluto(ydestino - y);
    if (a > b) {
        int aux = a;
        a = b;
        b = aux;
    }
    return a + (b - a + 1) / 2;
}

int consegue(int xdestino, int ydestino, int x1, int y1, int x2, int y2) {
    return absoluto(x1 - xdestino) + absoluto(y1 - ydestino) >= distancia(xdestino, ydestino, x2, y2);
}

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int proxima_permutacao(int *vetor, int tamanho) {
    int i = tamanho - 2;
    while (i >= 0 && vetor[i] >= vetor[i + 1]) i--;
    if (i < 0) return 0;
    int j = tamanho - 1;
    while (vetor[j] <= vetor[i]) j--;
    trocar(&vetor[i], &vetor[j]);
    for (int a = i + 1, b = tamanho - 1; a < b; a++, b--) {
        trocar(&vetor[a], &vetor[b]);
    }
    return 1;
}

void resolver() {
    int x, y, posicoes[3][2];
    char direcoes[3];

    if (scanf("%d %d", &x, &y) != 2 || (x == 0 && y == 0)) exit(0);

    for (int i = 0; i < 3; i++) {
        scanf("%d %d %c", &posicoes[i][0], &posicoes[i][1], &direcoes[i]);
    }

    int ordem[3] = {0, 1, 2};
    int tempo_minimo = INF;

    do {
        int tempo_total = 0, atual_x = x, atual_y = y;
        for (int i = 0; i < 3; i++) {
            int indice = ordem[i];
            int alvo_x = posicoes[indice][0];
            int alvo_y = posicoes[indice][1];

            if (direcoes[indice] == 'C') {
                alvo_y += tempo_total;
                int inicio = alvo_y, fim = INF;
                while (inicio < fim) {
                    int meio = (inicio + fim) / 2;
                    if (consegue(alvo_x, meio, alvo_x, alvo_y, atual_x, atual_y)) fim = meio;
                    else inicio = meio + 1;
                }
                tempo_total += fim - alvo_y;
                atual_x = alvo_x;
                atual_y = fim;
            } else {
                alvo_x += tempo_total;
                int inicio = alvo_x, fim = INF;
                while (inicio < fim) {
                    int meio = (inicio + fim) / 2;
                    if (consegue(meio, alvo_y, alvo_x, alvo_y, atual_x, atual_y)) fim = meio;
                    else inicio = meio + 1;
                }
                tempo_total += fim - alvo_x;
                atual_x = fim;
                atual_y = alvo_y;
            }
        }

        tempo_minimo = minimo(tempo_minimo, tempo_total);

    } while (proxima_permutacao(ordem, 3));

    printf("%d\n", tempo_minimo);
}

int main() {
    for (;;) resolver();
    return 0;
}
