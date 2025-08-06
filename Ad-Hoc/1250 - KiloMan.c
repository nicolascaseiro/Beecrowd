#include <stdio.h>
#include <stdlib.h>

int main() {
    
    int x;
    scanf("%d", &x);

    for (int h = 0; h < x; h++) {
        int qt;
        scanf("%d", &qt);

        int *alturas = (int*) malloc(qt * sizeof(int));
        char *pulos = (char*) malloc(qt * sizeof(char));

        for (int i = 0; i < qt; i++) {
            scanf("%d", &alturas[i]);
        }

        for (int i = 0; i < qt; i++) {
            scanf(" %c", &pulos[i]);
        }

        int counter = 0;
        for (int i = 0; i < qt; i++) {
            if ((alturas[i] == 1 || alturas[i] == 2) && pulos[i] == 'S')
                counter++;
            if (alturas[i] > 2 && pulos[i] == 'J')
                counter++;
        }

        printf("%d\n", counter);

        free(alturas);
        free(pulos);
    }

    return 0;
}
