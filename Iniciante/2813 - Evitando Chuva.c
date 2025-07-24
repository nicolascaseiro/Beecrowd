#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    int casaComprado = 0, trabComprado = 0;
    int casaSobrando = 0, trabSobrando = 0;
    char irProTrabalho[10], irPraCasa[10];

    for (int i = 0; i < N; i++) {
        scanf("%s %s", irProTrabalho, irPraCasa);

        // Ida para o trabalho
        if (strcmp(irProTrabalho, "chuva") == 0) {
            if (casaSobrando == 0) {
                casaComprado++;
                trabSobrando++;
            } else {
                casaSobrando--;
                trabSobrando++;
            }
        }

        // Volta pra casa
        if (strcmp(irPraCasa, "chuva") == 0) {
            if (trabSobrando == 0) {
                trabComprado++;
                casaSobrando++;
            } else {
                trabSobrando--;
                casaSobrando++;
            }
        }
    }

    printf("%d %d\n", casaComprado, trabComprado);
    return 0;
}
