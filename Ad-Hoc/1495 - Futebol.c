#include <stdio.h>
#include <stdlib.h>

int compara_ints(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
}

int main() {
    int partidas, gols_disponiveis;
    while (scanf("%d %d", &partidas, &gols_disponiveis) == 2) {
        int *dif_gols = (int *)malloc(partidas * sizeof(int));
        int cont_dif_gols = 0;
        int empates = 0, vitorias = 0;

        for (int i = 0; i < partidas; i++) {
            int gols_time_a, gols_time_b;
            scanf("%d %d", &gols_time_a, &gols_time_b);
            if (gols_time_a == gols_time_b) {
                empates++;
            } else if (gols_time_a > gols_time_b) {
                vitorias++;
            } else {
                dif_gols[cont_dif_gols++] = gols_time_b - gols_time_a;
            }
        }

        qsort(dif_gols, cont_dif_gols, sizeof(int), compara_ints);

        int compra_empates = (empates < gols_disponiveis) ? empates : gols_disponiveis;
        empates -= compra_empates;
        vitorias += compra_empates;
        gols_disponiveis -= compra_empates;

        for (int i = 0; i < cont_dif_gols && gols_disponiveis > 0; i++) {
            int diferenca = dif_gols[i];
            if (gols_disponiveis >= diferenca + 1) {
                gols_disponiveis -= diferenca + 1;
                vitorias++;
            } else if (gols_disponiveis == diferenca) {
                empates++;
                gols_disponiveis -= diferenca;
            }
        }

        printf("%d\n", empates + 3 * vitorias);
        free(dif_gols);
    }
    return 0;
}
