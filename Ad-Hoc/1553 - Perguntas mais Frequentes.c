#include <stdio.h>

int main() {

    int quantidade_numeros, frequencia_minima;
    while (1) {
        scanf("%d %d", &quantidade_numeros, &frequencia_minima);
        if (quantidade_numeros == 0 && frequencia_minima == 0) break;
        int frequencias[1001] = {0};
        for (int i = 0; i < quantidade_numeros; i++) {
            int numero;
            scanf("%d", &numero);
            frequencias[numero - 1]++;
        }
        int contador = 0;
        for (int i = 0; i < 1001; i++) {
            if (frequencias[i] >= frequencia_minima) contador++;
        }
        printf("%d\n", contador);
    }
    return 0;
}
