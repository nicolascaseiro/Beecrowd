#include <stdio.h>
#include <stdlib.h>

int abs_diff(int a, int b) {
    int diff = a - b;
    return diff < 0 ? -diff : diff;
}

int main() {
    
    int L;
    while (scanf("%d", &L) == 1 && L) {
        int **mat = malloc(L * sizeof(int *));
        int **pat = malloc(L * sizeof(int *));
        int **tam = malloc(L * sizeof(int *));
        for (int i = 0; i < L; i++) {
            mat[i] = malloc(L * sizeof(int));
            pat[i] = malloc(L * sizeof(int));
            tam[i] = malloc(L * sizeof(int));
        }
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                scanf("%d", &mat[i][j]);
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                scanf("%d", &pat[i][j]);
        double ans = 0.0, qt;
        qt = 0.0;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                if (abs_diff(mat[i][j], pat[i][j]) <= 100) qt++;
        if (qt/(L*L) > ans) ans = qt/(L*L);
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                tam[i][L - j - 1] = mat[i][j];
        qt = 0.0;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                if (abs_diff(tam[i][j], pat[i][j]) <= 100) qt++;
        if (qt/(L*L) > ans) ans = qt/(L*L);
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                tam[i][L - j - 1] = mat[j][i];
        qt = 0.0;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                if (abs_diff(tam[i][j], pat[i][j]) <= 100) qt++;
        if (qt/(L*L) > ans) ans = qt/(L*L);
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                mat[i][L - j - 1] = tam[i][j];
        qt = 0.0;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                if (abs_diff(mat[i][j], pat[i][j]) <= 100) qt++;
        if (qt/(L*L) > ans) ans = qt/(L*L);
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                mat[i][L - j - 1] = tam[j][i];
        qt = 0.0;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                if (abs_diff(mat[i][j], pat[i][j]) <= 100) qt++;
        if (qt/(L*L) > ans) ans = qt/(L*L);
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                tam[i][L - j - 1] = mat[i][j];
        qt = 0.0;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                if (abs_diff(tam[i][j], pat[i][j]) <= 100) qt++;
        if (qt/(L*L) > ans) ans = qt/(L*L);
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                tam[i][L - j - 1] = mat[j][i];
        qt = 0.0;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                if (abs_diff(tam[i][j], pat[i][j]) <= 100) qt++;
        if (qt/(L*L) > ans) ans = qt/(L*L);
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                mat[i][L - j - 1] = tam[i][j];
        qt = 0.0;
        for (int i = 0; i < L; i++)
            for (int j = 0; j < L; j++)
                if (abs_diff(mat[i][j], pat[i][j]) <= 100) qt++;
        if (qt/(L*L) > ans) ans = qt/(L*L);
        printf("%.2lf\n", ans * 100.0);
        for (int i = 0; i < L; i++) {
            free(mat[i]);
            free(pat[i]);
            free(tam[i]);
        }
        free(mat);
        free(pat);
        free(tam);
    }
    return 0;
}
