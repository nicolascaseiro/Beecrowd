#include <stdio.h>

int main() {
    int andares, comeco, fim, cima, baixo;
    scanf("%d %d %d %d %d", &andares, &comeco, &fim, &cima, &baixo);

    if (fim < comeco) {
        int temp = cima;
        cima = baixo;
        baixo = temp;
        comeco = andares - comeco;
        fim = andares - fim;
    }

    if (cima == 0) {
        printf("use the stairs\n");
        return 0;
    }

    int diferenca = fim - comeco;

    if (diferenca == 0) {
        printf("0\n");
        return 0;
    }

    int u = 0, d = 0;

    u += diferenca / cima;
    diferenca %= cima;

    if (diferenca == 0) {
        printf("%d\n", u);
        return 0;
    }

    u++;
    diferenca -= cima;
    diferenca = -diferenca;

    if (baixo == 0) {
        printf("use the stairs\n");
        return 0;
    }

    d += diferenca / baixo;
    diferenca %= baixo;

    if (diferenca == 0)
        printf("%d\n", u + d);
    else
        printf("use the stairs\n");

    return 0;
}
