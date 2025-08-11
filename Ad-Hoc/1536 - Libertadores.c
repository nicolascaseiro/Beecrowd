#include <stdio.h>
#include <string.h>

int main() {
    int casos_de_teste;
    scanf("%d\n", &casos_de_teste);

    for (int i = 0; i < casos_de_teste; i++) {
        char ida[20], volta[20];
        fgets(ida, sizeof(ida), stdin);
        fgets(volta, sizeof(volta), stdin);

        int t1_mandante, t2_visitante;
        int t2_mandante, t1_visitante;

        // Parse ida "X x Y"
        sscanf(ida, "%d x %d", &t1_mandante, &t2_visitante);
        sscanf(volta, "%d x %d", &t2_mandante, &t1_visitante);

        int saldo_gols_t1 = (t1_mandante + t1_visitante) - (t2_mandante + t2_visitante);
        int saldo_gols_t2 = -saldo_gols_t1;

        int gols_casa_t1 = t1_visitante;
        int gols_casa_t2 = t2_visitante;

        if (saldo_gols_t1 > saldo_gols_t2) {
            printf("Time 1\n");
        } else if (saldo_gols_t2 > saldo_gols_t1) {
            printf("Time 2\n");
        } else if (gols_casa_t1 > gols_casa_t2) {
            printf("Time 1\n");
        } else if (gols_casa_t2 > gols_casa_t1) {
            printf("Time 2\n");
        } else {
            printf("Penaltis\n");
        }
    }
    return 0;
}
