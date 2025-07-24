#include <stdio.h>
#include <stdlib.h>

unsigned escadinha(int *, unsigned short);

int main()
{
    unsigned short i;
    unsigned short tamSequencia;

    scanf("%hu", &tamSequencia);

    int *sequencia = (int *)malloc(tamSequencia * sizeof(int));
    if (sequencia == NULL) {
        fprintf(stderr, "Erro de alocação de memória.\n");
        return 1;
    }

    for (i = 0; i < tamSequencia; ++i)
        scanf("%d", &sequencia[i]);

    printf("%u\n", escadinha(sequencia, tamSequencia));

    free(sequencia);
    return 0;
}

unsigned escadinha(int *sequencia, unsigned short tam)
{
    unsigned short i;
    int anterior, atual, qtsEscadinhas;

    if (tam == 1 || tam == 2)
        return 1;

    qtsEscadinhas = 1;
    anterior = sequencia[1] - sequencia[0];

    for (i = 2; i < tam; ++i)
    {
        atual = sequencia[i] - sequencia[i - 1];
        if (atual != anterior) {
            anterior = atual;
            qtsEscadinhas++;
        }
    }

    return qtsEscadinhas;
}
