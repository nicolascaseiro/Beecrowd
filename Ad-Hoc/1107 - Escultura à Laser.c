#include <stdio.h>

int main() {
    
    int A, C, anterior, atual, resp;

    while (scanf("%d %d", &A, &C))
    {
        if (!A && !C)
            break;

        resp = 0;
        scanf("%d", &anterior);
        for (int i = 1; i < C; ++i)
        {
            scanf("%d", &atual);

            if (atual > anterior)
            {
                resp += atual - anterior;
            }
            anterior = atual;
        }
        resp += A - anterior;

        printf("%d\n", resp);
    }

    return 0;
}
