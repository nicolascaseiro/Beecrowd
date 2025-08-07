#include <stdio.h>

#define INF 1e13

int N, M, n[101];
double pd[101][100001];
struct {
    int first;
    double second;
} m[100001];

double min(double a, double b) {
    return a < b ? a : b;
}

double solve(int i, int j) {
    if (i == N) return 0.0;
    if (j == M) return INF;
    if (pd[i][j] > -1.0) return pd[i][j];
    double ret = solve(i, j + 1);
    if (m[j].first == n[i]) {
        double val = solve(i + 1, j + 1) + m[j].second;
        ret = min(ret, val);
    }
    return pd[i][j] = ret;
}

int main() {
    
    while (scanf("%d %d", &N, &M) == 2 && N + M) {
        for (int i = 0; i < N; i++) {
            scanf("%d", &n[i]);
            for (int j = 0; j <= M; j++) {
                pd[i][j] = -1.0;
            }
        }
        for (int i = 0; i < M; i++) {
            scanf("%d %lf", &m[i].first, &m[i].second);
        }
        double out = solve(0, 0);
        if (out >= INF) printf("Impossible\n");
        else printf("%.2lf\n", out);
    }
    return 0;
}
