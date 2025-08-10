#include <stdio.h>
#include <math.h>

int main() {
    
    int T;
    scanf("%d", &T);
    while (T--) {
        double n, m;
        scanf("%lf %lf", &n, &m);
        int resultado = (int)round((n - 1) / 3.0) * (int)round((m - 1) / 3.0);
        printf("%d\n", resultado);
    }
    return 0;
}
