#include <stdio.h>

int main() {

    int quantidade, distancia, paginas;
    while (1) {
        scanf("%d", &quantidade);
        if (quantidade == 0) break;
        scanf("%d %d", &distancia, &paginas);
        int resultado = (distancia * paginas * quantidade) / (paginas - quantidade);
        if (resultado == 1) printf("%d pagina\n", resultado);
        else printf("%d paginas\n", resultado);
    }
    return 0;
}
