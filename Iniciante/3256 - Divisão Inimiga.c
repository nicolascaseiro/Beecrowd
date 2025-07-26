#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *g_size = calloc(n, sizeof(int));
    int *g_cap = malloc(n * sizeof(int));
    int **g = malloc(n * sizeof(int*));

    for (int i = 0; i < n; i++) {
        g_cap[i] = 4;
        g[i] = malloc(g_cap[i] * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        if (g_size[a] == g_cap[a]) {
            g_cap[a] *= 2;
            g[a] = realloc(g[a], g_cap[a] * sizeof(int));
        }
        if (g_size[b] == g_cap[b]) {
            g_cap[b] *= 2;
            g[b] = realloc(g[b], g_cap[b] * sizeof(int));
        }
        g[a][g_size[a]++] = b;
        g[b][g_size[b]++] = a;
    }

    int *col = malloc(n * sizeof(int));
    int *enem = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) col[i] = 2;

    for (int i = 0; i < n; i++) {
        int cnt[3] = {0, 0, 0};
        for (int j = 0; j < g_size[i]; j++) {
            int idx = col[g[i][j]];
            cnt[idx]++;
        }
        int color = (cnt[0] > 1) ? 1 : 0;

        int cur = i;
        while (1) {
            col[cur] = color;
            int ncur = -1;

            for (int j = 0; j < g_size[cur]; j++) {
                int inim = g[cur][j];
                if (col[inim] == color) {
                    enem[cur]++;
                    enem[inim]++;
                    if (enem[inim] == 2) {
                        ncur = inim;
                        for (int l = 0; l < g_size[ncur]; l++) {
                            int inim2 = g[ncur][l];
                            if (col[inim2] == color) {
                                enem[inim2]--;
                                enem[ncur]--;
                            }
                        }
                    }
                }
            }
            if (ncur == -1) break;

            cur = ncur;
            color = (color == 1) ? 0 : 1;
        }
    }

    int **res = malloc(2 * sizeof(int*));
    int res_count[2] = {0, 0};
    for (int i = 0; i < 2; i++) {
        res[i] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        res[col[i]][res_count[col[i]]++] = i;
    }

    printf("%d\n", (res_count[1] > 0) ? 2 : 1);

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < res_count[i]; j++) {
            printf("%d", res[i][j] + 1);
            if (j + 1 < res_count[i]) printf(" ");
            else printf("\n");
        }
    }

    for (int i = 0; i < n; i++) free(g[i]);
    free(g);
    free(g_size);
    free(g_cap);
    free(col);
    free(enem);
    for (int i = 0; i < 2; i++) free(res[i]);
    free(res);

    return 0;
}
