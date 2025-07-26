#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    int valor;
    int indice;
} Par;

int n;

Par buscar(Par *arvore) {
    if (arvore[1].valor != -1) {
        return arvore[1];
    } else {
        Par aux = {-1, -1};
        return aux;
    }
}

void atualizar(int k, int x, Par *arvore, int tamanho) {
    int original = k;
    k += n;
    arvore[k].valor = x;
    arvore[k].indice = original;

    for (k /= 2; k >= 1; k /= 2) {
        if (arvore[2 * k].valor >= tamanho && arvore[2 * k + 1].valor >= tamanho) {
            if (arvore[2 * k].indice < arvore[2 * k + 1].indice) {
                arvore[k] = arvore[2 * k];
            } else {
                arvore[k] = arvore[2 * k + 1];
            }
        } else if (arvore[2 * k].valor < tamanho && arvore[2 * k + 1].valor < tamanho) {
            arvore[k].valor = -1;
            arvore[k].indice = -1;
        } else if (arvore[2 * k].valor >= tamanho) {
            arvore[k] = arvore[2 * k];
        } else {
            arvore[k] = arvore[2 * k + 1];
        }
    }
}

int main() {
    int alcance;
    scanf("%d %d", &n, &alcance);

    char titans[n + 1];
    scanf("%s", titans);

    int pequeno, medio, grande;
    scanf("%d %d %d", &pequeno, &medio, &grande);

    Par *arvorePequenos = malloc(sizeof(Par) * (2 * n + 2));
    Par *arvoreMedios = malloc(sizeof(Par) * (2 * n + 2));
    Par *arvoreGrandes = malloc(sizeof(Par) * (2 * n + 2));

    for (int i = 0; i < 2 * n + 2; i++) {
        arvorePequenos[i].valor = -1; arvorePequenos[i].indice = -1;
        arvoreMedios[i].valor = -1; arvoreMedios[i].indice = -1;
        arvoreGrandes[i].valor = -1; arvoreGrandes[i].indice = -1;
    }

    Par aux = {-1, -1};
    int muros = 0;

    for (int i = 0; i < n; i++) {
        int tamanho = 0;
        bool inserir = false;
        Par resultado;

        if (titans[i] == 'P') {
            tamanho = pequeno;
            resultado = buscar(arvorePequenos);
            if (resultado.valor == -1 && resultado.indice == -1) inserir = true;
        } else if (titans[i] == 'M') {
            tamanho = medio;
            resultado = buscar(arvoreMedios);
            if (resultado.valor == -1 && resultado.indice == -1) inserir = true;
        } else if (titans[i] == 'G') {
            tamanho = grande;
            resultado = buscar(arvoreGrandes);
            if (resultado.valor == -1 && resultado.indice == -1) inserir = true;
        }

        if (inserir) {
            muros++;
            atualizar(muros, alcance - tamanho, arvorePequenos, pequeno);
            atualizar(muros, alcance - tamanho, arvoreMedios, medio);
            atualizar(muros, alcance - tamanho, arvoreGrandes, grande);
        } else {
            atualizar(resultado.indice, resultado.valor - tamanho, arvorePequenos, pequeno);
            atualizar(resultado.indice, resultado.valor - tamanho, arvoreMedios, medio);
            atualizar(resultado.indice, resultado.valor - tamanho, arvoreGrandes, grande);
        }
    }

    printf("%d\n", muros);

    free(arvorePequenos);
    free(arvoreMedios);
    free(arvoreGrandes);

    return 0;
}
