#include <stdio.h>
#include <string.h>

#define MAXN 404

int N, mark[MAXN][MAXN], v[MAXN], sum[MAXN];
double F, pd[MAXN][MAXN];

double min(double a, double b) {
    return (a < b) ? a : b;
}

double solve(int i, int j) {
    if(i == j) return 0.0;
    if(mark[i][j]) return pd[i][j];
    mark[i][j] = 1;
    double ret = 1e18;
    int k;
    for(k = i; k < j; k++) {
        double left = solve(i, k);
        double right = solve(k + 1, j);
        double cost = max(sum[k] - sum[i-1], sum[j] - sum[k]) * F;
        if(left + right + cost < ret) ret = left + right + cost;
    }
    pd[i][j] = ret;
    return ret;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    
    while(scanf("%d %lf", &N, &F) == 2 && N) {
        N++;
        int i, j;
        memset(mark, 0, sizeof(mark));
        for(i = 1; i < N; i++) {
            scanf("%d", &v[i]);
            v[i + N - 1] = v[i];
        }
        sum[0] = 0;
        for(i = 1; i < 2 * N; i++) {
            sum[i] = sum[i-1] + v[i];
        }

        double ans = 1e18;
        for(i = 1; i < N; i++) {
            double val = solve(i, i + N - 2);
            if(val < ans) ans = val;
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}
