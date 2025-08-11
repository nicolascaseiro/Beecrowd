#include <stdio.h>
#include <stdbool.h>

int n, v;

bool verifica(int valor) {
    int contador = valor, posicao = 0;
    while (posicao <= n && valor > 0) {
        posicao += valor;
        if (posicao == n) return true;
        contador--;
        if (contador == 0) {
            valor--;
            contador = valor;
        }
    }
    return false;
}

int main() {
  
    while (scanf("%d %d", &n, &v) == 2 && n) {
        bool possivel = false;
        for (int i = 1; i <= v; i++) {
            if (verifica(i)) {
                possivel = true;
                break;
            }
        }
        if (possivel) printf("possivel\n");
        else printf("impossivel\n");
    }
    return 0;
}
