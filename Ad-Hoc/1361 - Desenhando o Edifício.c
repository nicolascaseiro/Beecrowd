#include <stdio.h>
#include <stdlib.h>

typedef long long int ll;

ll lerInteiro();

int max(int a, int b) {
    return (a > b) ? a : b;
}

int *azul = NULL, *verm = NULL;
int tamAzul = 0, tamVerm = 0;

int compararDesc(const void *a, const void *b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return (ib - ia);
}

int resolver(int i, int j, int l) {
    int ret = 0;
    if(l == 0) {
        if(tamVerm == 0) return 0;
        while(j < tamVerm && verm[j] >= azul[i]) {
            j++;
            if(j == tamVerm) return 0;
        }
        ret += resolver(i, j, 1) + 1;
    } else {
        if(tamAzul == 0) return 0;
        while(i < tamAzul && azul[i] >= verm[j]) {
            i++;
            if(i == tamAzul) return 0;
        }
        ret += resolver(i, j, 0) + 1;
    }
    return ret;
}

int main() {
    
    int P = (int)lerInteiro();
    while(P--) {
        free(azul);
        free(verm);
        tamAzul = 0;
        tamVerm = 0;

        int Q = (int)lerInteiro();

        int *tempAzul = malloc(Q * sizeof(int));
        int *tempVerm = malloc(Q * sizeof(int));
        int contAzul = 0, contVerm = 0;

        for(int k = 0; k < Q; k++) {
            int aux = (int)lerInteiro();
            if(aux < 0) tempVerm[contVerm++] = abs(aux);
            else tempAzul[contAzul++] = aux;
        }

        azul = malloc(contAzul * sizeof(int));
        verm = malloc(contVerm * sizeof(int));
        tamAzul = contAzul;
        tamVerm = contVerm;

        for(int k = 0; k < contAzul; k++) azul[k] = tempAzul[k];
        for(int k = 0; k < contVerm; k++) verm[k] = tempVerm[k];

        free(tempAzul);
        free(tempVerm);

        qsort(azul, tamAzul, sizeof(int), compararDesc);
        qsort(verm, tamVerm, sizeof(int), compararDesc);

        int saida = 0;
        if(tamAzul != 0) saida = max(saida, resolver(0, 0, 0) + 1);
        if(tamVerm != 0) saida = max(saida, resolver(0, 0, 1) + 1);

        printf("%d\n", saida);

        free(azul);
        free(verm);
        azul = NULL;
        verm = NULL;
    }
    return 0;
}

ll lerInteiro() {
    int negativo = 0;
    ll resultado = 0;
    int c = getchar();
    while(c != '-' && (c < '0' || c > '9')) c = getchar();
    if(c == '-') {
        negativo = 1;
        c = getchar();
    }
    while(c >= '0' && c <= '9') {
        resultado = resultado * 10 + (c - '0');
        c = getchar();
    }
    return negativo ? -resultado : resultado;
}
