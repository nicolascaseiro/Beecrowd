#include <stdio.h>
#include <stdlib.h>

typedef long double ld;

typedef struct {
    ld valor;
    int indice;
} Par;

int n;
ld T;
Par heap[100000];
int tamanho = 0;

int cortes[100000];
ld vegetais[100000];
ld menor = 1e18;

void troca(int i, int j) {
    Par temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}

void inserir_heap(Par x) {
    int i = tamanho++;
    heap[i] = x;
    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].valor >= heap[i].valor) break;
        troca(p, i);
        i = p;
    }
}

void ajustar_heap(int i) {
    int maior = i;
    int esq = 2*i + 1;
    int dir = 2*i + 2;
    if (esq < tamanho && heap[esq].valor > heap[maior].valor)
        maior = esq;
    if (dir < tamanho && heap[dir].valor > heap[maior].valor)
        maior = dir;
    if (maior != i) {
        troca(i, maior);
        ajustar_heap(maior);
    }
}

Par remover_topo() {
    Par ret = heap[0];
    heap[0] = heap[--tamanho];
    ajustar_heap(0);
    return ret;
}

Par topo() {
    return heap[0];
}

int main() {
    scanf("%Lf %d", &T, &n);

    for (int i = 0; i < n; i++) {
        scanf("%Lf", &vegetais[i]);
        cortes[i] = 1;
        if (vegetais[i] < menor) menor = vegetais[i];
        inserir_heap((Par){vegetais[i], i});
    }

    int resposta = 0;
    while (menor / topo().valor < T) {
        Par atual = remover_topo();
        resposta++;
        cortes[atual.indice]++;
        ld novo = vegetais[atual.indice] / cortes[atual.indice];
        if (novo < menor) menor = novo;
        inserir_heap((Par){novo, atual.indice});
    }

    printf("%d\n", resposta);

    return 0;
}
