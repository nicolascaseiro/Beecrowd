#include <stdio.h>

int main() {
    
    int ordem;

    while (1) {
        scanf("%d", &ordem);
        if (ordem == 0) {
            break;
        }

        int valor, vitorias_mary = 0, vitorias_john = 0;

        for (int i = 0; i < ordem; i++) {
            scanf("%d", &valor);
            if (valor == 0) {
                vitorias_mary++;
            } else if (valor == 1) {
                vitorias_john++;
            }
        }

        printf("Mary won %d times and John won %d times\n", vitorias_mary, vitorias_john);
    }

    return 0;
}
