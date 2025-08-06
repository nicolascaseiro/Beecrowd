#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int valor;
    int pos;
} Par;

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        Par* v = (Par*) malloc(n * sizeof(Par));
        bool* vis = (bool*) calloc(n, sizeof(bool));

        for (int i = 0; i < n; i++) {
            scanf("%d", &v[i].valor);
            v[i].valor--;
            v[v[i].valor].pos = i;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            x--;
            vis[x] = true;
            for (int j = 0; j < v[x].pos; j++) {
                if (!vis[v[j].valor]) ans++;
            }
        }

        printf("%d\n", ans);

        free(v);
        free(vis);
    }
    return 0;
}
