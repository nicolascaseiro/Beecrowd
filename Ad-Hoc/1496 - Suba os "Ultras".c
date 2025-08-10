#include <stdio.h>
#include <stdlib.h>

#define MAX 100010
#define INF 0x3f3f3f3f

int n, alturas[MAX];
int arvoreMax[4*MAX], arvoreMin[4*MAX];

void construir(int no, int i, int j) {
    if(i == j) {
        arvoreMax[no] = alturas[i];
        arvoreMin[no] = alturas[i];
        return;
    }
    int esq = no * 2, dir = esq + 1, meio = (i + j) / 2;
    construir(esq, i, meio);
    construir(dir, meio + 1, j);
    arvoreMax[no] = (arvoreMax[esq] > arvoreMax[dir]) ? arvoreMax[esq] : arvoreMax[dir];
    arvoreMin[no] = (arvoreMin[esq] < arvoreMin[dir]) ? arvoreMin[esq] : arvoreMin[dir];
}

int consultaDireita(int no, int i, int j, int a, int b, int k) {
    if(i > j || i > b || j < a || arvoreMax[no] <= k) return -1;
    if(i == j) return i;
    int esq = no * 2, dir = esq + 1, meio = (i + j) / 2;
    int res = consultaDireita(dir, meio + 1, j, a, b, k);
    if(res != -1) return res;
    return consultaDireita(esq, i, meio, a, b, k);
}

int consultaEsquerda(int no, int i, int j, int a, int b, int k) {
    if(i > j || i > b || j < a || arvoreMax[no] <= k) return -1;
    if(i == j) return i;
    int esq = no * 2, dir = esq + 1, meio = (i + j) / 2;
    int res = consultaEsquerda(esq, i, meio, a, b, k);
    if(res != -1) return res;
    return consultaEsquerda(dir, meio + 1, j, a, b, k);
}

int consultaMin(int no, int i, int j, int a, int b) {
    if(i > j || i > b || j < a) return INF;
    if(i >= a && j <= b) return arvoreMin[no];
    int esq = no * 2, dir = esq + 1, meio = (i + j) / 2;
    int minEsq = consultaMin(esq, i, meio, a, b);
    int minDir = consultaMin(dir, meio + 1, j, a, b);
    return (minEsq < minDir) ? minEsq : minDir;
}

int main() {
    
    while(scanf("%d", &n) == 1) {
        for(int i = 0; i < n; i++) {
            scanf("%d", &alturas[i]);
        }
        construir(1, 0, n - 1);
        int primeiro = 1;
        for(int i = 1; i < n - 1; i++) {
            int esq = consultaDireita(1, 0, n - 1, 0, i - 1, alturas[i]);
            int dir = consultaEsquerda(1, 0, n - 1, i + 1, n - 1, alturas[i]);
            int minEsq = 0, minDir = 0;
            if(esq != -1 && esq + 1 <= i) minEsq = consultaMin(1, 0, n - 1, esq + 1, i);
            if(dir != -1 && i <= dir - 1) minDir = consultaMin(1, 0, n - 1, i, dir - 1);
            int p = alturas[i] - (minEsq > minDir ? minEsq : minDir);
            if(p >= 150000) {
                if(!primeiro) printf(" ");
                printf("%d", i + 1);
                primeiro = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
