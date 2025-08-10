#include <stdio.h>
#include <string.h>

int dp[100000];
int n;

int maximo(int a, int b) {
    return (a > b) ? a : b;
}

int resolver(int k) {
    if (dp[k] != -1) return dp[k];
    if (k == 1) return dp[k] = 1;
    if (k % 2 == 0) {
        dp[k] = maximo(k, resolver(k / 2));
    } else {
        dp[k] = maximo(k, resolver(3 * k + 1));
    }
    return dp[k];
}

int main() {
    
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    while (scanf("%d", &n) == 1 && n != 0) {
        printf("%d\n", resolver(n));
    }
    return 0;
}
