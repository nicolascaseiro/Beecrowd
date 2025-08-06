#include <stdio.h>
#include <stdlib.h>

#define MAXN 100001

int main() {
    
    int N, R, Q, z = 1;
    while (scanf("%d", &N) == 1 && N) {
        printf("Genome %d\n", z++);
        int *n = (int *)malloc((N + 1) * sizeof(int));
        for (int i = 1; i <= N; i++) n[i] = i;
        scanf("%d", &R);
        int *a = (int *)malloc(R * sizeof(int));
        int *b = (int *)malloc(R * sizeof(int));
        for (int i = 0; i < R; i++) {
            scanf("%d %d", &a[i], &b[i]);
        }
        for (int i = R - 1; i >= 0; i--) {
            int start = a[i];
            int end = b[i];
            while (start < end) {
                int temp = n[start];
                n[start] = n[end];
                n[end] = temp;
                start++;
                end--;
            }
        }
        free(a);
        free(b);
        scanf("%d", &Q);
        for (int i = 0; i < Q; i++) {
            int pos;
            scanf("%d", &pos);
            printf("%d\n", n[pos]);
        }
        free(n);
    }
    return 0;
}
