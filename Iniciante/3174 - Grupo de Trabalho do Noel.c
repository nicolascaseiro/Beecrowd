#include <stdio.h>
#include <string.h>

int main() {
    int bonecos = 0, arquitetos = 0, musicos = 0, desenhistas = 0;
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char nome[100], grupo[20];
        int horas;
        scanf("%s %s %d", nome, grupo, &horas);

        if (strcmp(grupo, "bonecos") == 0) bonecos += horas;
        else if (strcmp(grupo, "arquitetos") == 0) arquitetos += horas;
        else if (strcmp(grupo, "musicos") == 0) musicos += horas;
        else if (strcmp(grupo, "desenhistas") == 0) desenhistas += horas;
    }

    printf("%d\n", bonecos / 8 + arquitetos / 4 + musicos / 6 + desenhistas / 12);

    return 0;
}
