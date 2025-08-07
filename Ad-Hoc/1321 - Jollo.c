#include <stdio.h>

void ordenar_cartas_princesa(int cartas_princesa[]) {
    for (int i = 1; i < 3; i++) {
        int j = i;
        while (j > 0 && cartas_princesa[j] < cartas_princesa[j - 1]) {
            int temp = cartas_princesa[j - 1];
            cartas_princesa[j - 1] = cartas_princesa[j];
            cartas_princesa[j] = temp;
            j--;
        }
    }
}

int contar_vitorias_princesa(int cartas_princesa[], int cartas_principe[]) {
    int vitorias = 0;
    for (int i = 1; i >= 0; i--) {
        int j;
        for (j = 0; j < 3; j++) {
            if (cartas_princesa[j] > cartas_principe[i]) {
                cartas_princesa[j] = 0;
                vitorias++;
                break;
            }
        }
        if (j == 3) {
            for (int k = 0; k < 3; k++) {
                if (cartas_princesa[k] != 0) {
                    cartas_princesa[k] = 0;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < 3; i++) {
        if (cartas_princesa[i] != 0) {
            cartas_princesa[0] = cartas_princesa[i];
        }
    }
    return vitorias;
}

int menor_carta_possivel(int vitorias, int cartas_usadas[], int menor_carta_princesa) {
    switch (vitorias) {
        case 0: {
            int i = 0;
            int proxima_carta = 1;
            while (i < 5) {
                if (proxima_carta == cartas_usadas[i]) {
                    proxima_carta++;
                    i = -1;
                }
                i++;
            }
            return proxima_carta;
        }
        case 1: {
            int i = 0;
            int proxima_carta = menor_carta_princesa + 1;
            while (i < 5) {
                if (proxima_carta == 53) {
                    return -1;
                }
                if (proxima_carta == cartas_usadas[i]) {
                    proxima_carta++;
                    i = -1;
                }
                i++;
            }
            return proxima_carta;
        }
        case 2: {
            return -1;
        }
    }
    return 0;
}

int main() {
    
    int cartas_princesa[3];
    int cartas_principe[2];

    while (1) {
        for (int i = 0; i < 3; i++) {
            scanf("%d", &cartas_princesa[i]);
        }
        for (int i = 0; i < 2; i++) {
            scanf("%d", &cartas_principe[i]);
        }
        if (cartas_princesa[0] == 0) {
            return 0;
        }

        int cartas_usadas[5] = {
            cartas_princesa[0],
            cartas_princesa[1],
            cartas_princesa[2],
            cartas_principe[0],
            cartas_principe[1]
        };

        if (cartas_principe[0] > cartas_principe[1]) {
            int temp = cartas_principe[1];
            cartas_principe[1] = cartas_principe[0];
            cartas_principe[0] = temp;
        }

        ordenar_cartas_princesa(cartas_princesa);
        int vitorias = contar_vitorias_princesa(cartas_princesa, cartas_principe);
        printf("%d\n", menor_carta_possivel(vitorias, cartas_usadas, cartas_princesa[0]));
    }

    return 0;
}
