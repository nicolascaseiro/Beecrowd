#include <stdio.h>
#include <stdlib.h>

#define MAX 10005

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    
    int a, d;
    int atk[MAX], dfs[MAX];

    while (1) {
        if (scanf("%d %d", &a, &d) != 2)
            break;

        if (a + d == 0)
            break;

        for (int i = 0; i < a; i++)
            scanf("%d", &atk[i]);

        for (int i = 0; i < d; i++)
            scanf("%d", &dfs[i]);

        qsort(dfs, d, sizeof(int), compare);

        int min_atk = atk[0];
        for (int i = 1; i < a; i++) {
            if (atk[i] < min_atk)
                min_atk = atk[i];
        }

        if (min_atk < dfs[1])
            printf("Y\n");
        else
            printf("N\n");
    }

    return 0;
}
