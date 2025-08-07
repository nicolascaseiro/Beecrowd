#include <stdio.h>

#define MAX 10001

int main() {
    
    int total_cartoes, total_pessoas;

    scanf("%d %d", &total_cartoes, &total_pessoas);

    while (total_cartoes > 0 && total_pessoas > 0) {
        int tickets[MAX] = {0};
        int pessoas[MAX];

        for (int i = 0; i < total_pessoas; i++) {
            scanf("%d", &pessoas[i]);
        }

        for (int i = 0; i < total_pessoas; i++) {
            int ticket_entregue = pessoas[i];
            tickets[ticket_entregue]++;
        }

        int contador = 0;
        for (int i = 1; i <= total_cartoes; i++) {
            if (tickets[i] > 1) {
                contador++;
            }
        }

        printf("%d\n", contador);

        scanf("%d %d", &total_cartoes, &total_pessoas);
    }

    return 0;
}
