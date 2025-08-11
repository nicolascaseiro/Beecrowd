#include <stdio.h>
#include <stdlib.h>

int main() {
  
    long int quantidade_casos;
    scanf("%ld", &quantidade_casos);
    while (quantidade_casos--) {
        int quantidade_alunos, nota_referencia;
        scanf("%d %d", &quantidade_alunos, &nota_referencia);
        int menor_diferenca = 1000, posicao_menor = 1000;
        for (int i = 0; i < quantidade_alunos; i++) {
            int nota;
            scanf("%d", &nota);
            int diferenca = abs(nota_referencia - nota);
            if (diferenca < menor_diferenca) {
                menor_diferenca = diferenca;
                posicao_menor = i;
            }
        }
        printf("%d\n", posicao_menor + 1);
    }
    return 0;
}
