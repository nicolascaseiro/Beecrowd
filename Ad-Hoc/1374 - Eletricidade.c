#include <stdio.h>

typedef struct {
    int d, m, y, c;
} Medicao;

int bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

int dias_no_mes(int mes, int ano) {
    int dias_mes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (mes == 2 && bissexto(ano)) return 29;
    return dias_mes[mes - 1];
}

int datas_consecutivas(Medicao a, Medicao b) {
    a.d++;
    if (a.d > dias_no_mes(a.m, a.y)) {
        a.d = 1;
        a.m++;
        if (a.m > 12) {
            a.m = 1;
            a.y++;
        }
    }
    return a.d == b.d && a.m == b.m && a.y == b.y;
}

int main() {
    
    int n;
    while (scanf("%d", &n) && n != 0) {
        Medicao m[1005];
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &m[i].d, &m[i].m, &m[i].y, &m[i].c);
        }

        int dias = 0, consumo = 0;
        for (int i = 1; i < n; i++) {
            if (datas_consecutivas(m[i - 1], m[i])) {
                dias++;
                consumo += m[i].c - m[i - 1].c;
            }
        }

        printf("%d %d\n", dias, consumo);
    }
    return 0;
}
