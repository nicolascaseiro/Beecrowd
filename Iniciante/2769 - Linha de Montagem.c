#include <stdio.h>
#include <string.h>

#define MAX 1123

int N;
int a[2][MAX], t[2][MAX], e[2], x[2];
int pd[2][MAX];

int min(int a, int b) {
    return a < b ? a : b;
}

int solve(int i, int j) {
    if (pd[i][j] != -1)
        return pd[i][j];

    if (j == N)
        return pd[i][j] = a[i][j] + x[i];

    if (j == 0)
        return pd[i][j] = e[i] + solve(i, j + 1);

    return pd[i][j] = a[i][j] + min(solve(i, j + 1), t[i][j] + solve(!i, j + 1));
}

int main(void) {
    while (scanf("%d", &N) != EOF) {
        if (N <= 0 || N >= MAX) continue; // segurança extra

        scanf("%d %d", &e[0], &e[1]);

        for (int i = 0; i < 2; i++)
            for (int j = 1; j <= N; j++)
                scanf("%d", &a[i][j]);

        for (int i = 0; i < 2; i++)
            for (int j = 1; j < N; j++)
                scanf("%d", &t[i][j]);

        scanf("%d %d", &x[0], &x[1]);

        memset(pd, -1, sizeof(pd));

        int resultado = min(solve(0, 0), solve(1, 0));
        printf("%d\n", resultado);
    }

    return 0;
}
