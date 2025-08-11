#include <stdio.h>
#include <stdlib.h>

#define MAX 5000

typedef struct {
    int x, altura, fim;
} Evento;

Evento eventos[MAX * 2];
int total_eventos = 0;

int comparar(const void *a, const void *b) {
    Evento *e1 = (Evento *)a;
    Evento *e2 = (Evento *)b;
    if (e1->x != e2->x) return e1->x - e2->x;
    if (e1->fim != e2->fim) return e1->fim - e2->fim;
    return e2->altura - e1->altura;
}

int alturas[MAX], tamanho_alturas = 0;

void inserir_altura(int h) {
    alturas[tamanho_alturas++] = h;
}

void remover_altura(int h) {
    for (int i = 0; i < tamanho_alturas; i++) {
        if (alturas[i] == h) {
            for (int j = i; j < tamanho_alturas - 1; j++) {
                alturas[j] = alturas[j + 1];
            }
            tamanho_alturas--;
            break;
        }
    }
}

int maior_altura() {
    int maior = 0;
    for (int i = 0; i < tamanho_alturas; i++) {
        if (alturas[i] > maior) {
            maior = alturas[i];
        }
    }
    return maior;
}

int main() {
    int l, h, r;
    while (scanf("%d %d %d", &l, &h, &r) != EOF) {
        eventos[total_eventos].x = l;
        eventos[total_eventos].altura = h;
        eventos[total_eventos].fim = 0;
        total_eventos++;

        eventos[total_eventos].x = r;
        eventos[total_eventos].altura = h;
        eventos[total_eventos].fim = 1;
        total_eventos++;
    }

    qsort(eventos, total_eventos, sizeof(Evento), comparar);

    int resposta_x[MAX * 2], resposta_h[MAX * 2];
    int total_resposta = 0;

    for (int i = 0; i < total_eventos; ) {
        int j = i;
        if (eventos[i].fim == 0) {
            if (tamanho_alturas == 0 || maior_altura() < eventos[i].altura) {
                resposta_x[total_resposta] = eventos[i].x;
                resposta_h[total_resposta] = eventos[i].altura;
                total_resposta++;
            }
            while (j < total_eventos && eventos[j].x == eventos[i].x && eventos[j].fim == 0) {
                inserir_altura(eventos[j].altura);
                j++;
            }
        } else {
            while (j < total_eventos && eventos[j].x == eventos[i].x && eventos[j].fim == 1) {
                remover_altura(eventos[j].altura);
                j++;
            }
            if (tamanho_alturas == 0) {
                resposta_x[total_resposta] = eventos[i].x;
                resposta_h[total_resposta] = 0;
                total_resposta++;
            } else if (maior_altura() < eventos[i].altura) {
                resposta_x[total_resposta] = eventos[i].x;
                resposta_h[total_resposta] = maior_altura();
                total_resposta++;
            }
        }
        i = j;
    }

    for (int i = 0; i < total_resposta; i++) {
        printf("%d %d", resposta_x[i], resposta_h[i]);
        if (i != total_resposta - 1) printf(" ");
    }
    printf("\n");

    return 0;
}
