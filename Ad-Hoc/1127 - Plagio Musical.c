#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 100000
#define MAXM 10000

char mus[MAXN][4], t[MAXM][4];
int a[MAXN + MAXM], p[MAXN + MAXM];
int n, m;

int notas(char *s) {
    if (strcmp(s, "A") == 0) return 1;
    if (strcmp(s, "A#") == 0) return 2;
    if (strcmp(s, "Ab") == 0) return 12;
    if (strcmp(s, "B") == 0) return 3;
    if (strcmp(s, "B#") == 0) return 4;
    if (strcmp(s, "Bb") == 0) return 2;
    if (strcmp(s, "C") == 0) return 4;
    if (strcmp(s, "C#") == 0) return 5;
    if (strcmp(s, "Cb") == 0) return 3;
    if (strcmp(s, "D") == 0) return 6;
    if (strcmp(s, "D#") == 0) return 7;
    if (strcmp(s, "Db") == 0) return 5;
    if (strcmp(s, "E") == 0) return 8;
    if (strcmp(s, "E#") == 0) return 9;
    if (strcmp(s, "Eb") == 0) return 7;
    if (strcmp(s, "F") == 0) return 9;
    if (strcmp(s, "F#") == 0) return 10;
    if (strcmp(s, "Fb") == 0) return 8;
    if (strcmp(s, "G") == 0) return 11;
    if (strcmp(s, "G#") == 0) return 12;
    if (strcmp(s, "Gb") == 0) return 10;
    return 0;
}

void kmp_prefix(int *arr, int len) {
    int i, j;
    p[0] = 0;
    for (i = 1; i < len; i++) {
        j = p[i - 1];
        while (j > 0 && arr[i] != arr[j]) {
            j = p[j - 1];
        }
        if (arr[i] == arr[j]) {
            j++;
        }
        p[i] = j;
    }
}

int main() {
    while (1) {
        scanf("%d %d", &n, &m);
        if (n == 0 && m == 0) break;

        int i, j;
        for (i = 0; i < n; i++) scanf("%s", mus[i]);
        for (i = 0; i < m; i++) scanf("%s", t[i]);

        int plagio = 0;

        if (m == 1) {
            for (i = 0; i < n; i++) {
                if (strcmp(mus[i], t[0]) == 0) {
                    plagio = 1;
                    break;
                }
            }
        } else {
            int len = 0;
            for (i = 0; i < m - 1; i++) {
                int x = notas(t[i + 1]) - notas(t[i]);
                if (x < 0) x += 12;
                a[len++] = x;
            }
            a[len++] = INT_MAX;
            for (i = 0; i < n - 1; i++) {
                int x = notas(mus[i + 1]) - notas(mus[i]);
                if (x < 0) x += 12;
                a[len++] = x;
            }

            kmp_prefix(a, len);
            for (i = m; i < len; i++) {
                if (p[i] == m - 1) {
                    plagio = 1;
                    break;
                }
            }
        }

        if (plagio) printf("S\n");
        else printf("N\n");
    }

    return 0;
}
