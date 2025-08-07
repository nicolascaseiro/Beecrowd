#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int first;
    int second;
} pair;

void func(pair *pawns, int p_size, int pos, int *minimum, int cont, int turn) {
    if (pos < 1 || pos > 64) return;
    int isthere = 0;
    int aux = -1;
    if (*minimum != 0 && turn > *minimum) return;
    if (turn > -1) {
        for (int i = 0; i < p_size; i++) {
            if (pawns[i].second == 0) {
                if (pawns[i].first + turn * 8 > 64) {
                    if (aux != -1) pawns[aux].second = 0;
                    return;
                }
                if (pawns[i].first + turn * 8 == pos - 8) {
                    if (aux != -1) pawns[aux].second = 0;
                    return;
                }
                if (pawns[i].first + turn * 8 == pos) {
                    pawns[i].second = 1;
                    aux = i;
                } else
                    isthere = 1;
            }
        }
    }
    if (!isthere && turn > -1) {
        if (*minimum == 0)
            *minimum = cont;
        else if (cont < *minimum)
            *minimum = cont;
        if (aux != -1)
            pawns[aux].second = 0;
        return;
    }
    if (pos > 16 && pos % 8 != 1)
        func(pawns, p_size, pos - 17, minimum, cont + 1, turn + 1);
    if (pos > 16 && pos % 8 != 0)
        func(pawns, p_size, pos - 15, minimum, cont + 1, turn + 1);
    if (pos > 8 && pos % 8 != 1 && pos % 8 != 2)
        func(pawns, p_size, pos - 10, minimum, cont + 1, turn + 1);
    if (pos > 8 && pos % 8 != 0 && pos % 8 != 7)
        func(pawns, p_size, pos - 6, minimum, cont + 1, turn + 1);
    if (pos < 57 && pos % 8 != 1 && pos % 8 != 2)
        func(pawns, p_size, pos + 6, minimum, cont + 1, turn + 1);
    if (pos < 57 && pos % 8 != 0 && pos % 8 != 7)
        func(pawns, p_size, pos + 10, minimum, cont + 1, turn + 1);
    if (pos < 49 && pos % 8 != 1)
        func(pawns, p_size, pos + 15, minimum, cont + 1, turn + 1);
    if (pos < 49 && pos % 8 != 0)
        func(pawns, p_size, pos + 17, minimum, cont + 1, turn + 1);
    if (aux != -1)
        pawns[aux].second = 0;
}

int main() {
    
    int p, h;
    while (1) {
        if (scanf("%d", &p) != 1 || p == 0) break;
        pair *pawns = (pair *)malloc(p * sizeof(pair));
        for (int i = 0; i < p; i++) {
            scanf("%d", &pawns[i].first);
            pawns[i].second = 0;
        }
        scanf("%d", &h);
        int minimum = 0;
        func(pawns, p, h, &minimum, 0, -1);
        if (minimum == 0)
            printf("impossible\n");
        else
            printf("%d\n", minimum);
        free(pawns);
    }
    return 0;
}
