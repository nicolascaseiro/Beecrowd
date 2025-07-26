#include <stdio.h>
#include <stdbool.h>

#define N 10008

int main() {
    bool p[N];
    for(int i = 0; i < N; i++) p[i] = true;
    p[0] = false; p[1] = false;
    for(int n = 2; n * n < N; n++) {
        if(p[n]) {
            for(int k = 2*n; k < N; k += n) {
                p[k] = false;
            }
        }
    }

    int q[N], q_size = 0;
    for(int i = 2; i < N; i++) {
        if(p[i]) q[q_size++] = i;
    }

    int D[3*N];
    for(int i = 0; i < 3*N; i++) D[i] = N;

    for(int idx = 0; idx < q_size; idx++) {
        int n = q[idx];
        D[3*n] = 1;
        for(int l = n - 1; l > 1; l--) {
            if(p[l]) break;
            D[3*l + 0] = D[3*(l+1) + 2];
            D[3*l + 1] = D[3*(l+1) + 0];
            D[3*l + 2] = D[3*(l+1) + 1];

            for(int kidx = 0; kidx < q_size; kidx++) {
                int k = q[kidx];
                if(l % k == 0) {
                    int v = (l / k < D[3*(l / k) + 2]) ? l / k : D[3*(l / k) + 2];
                    if(v <= D[3*l]) {
                        D[3*l + 0] = v;
                        D[3*l + 1] = D[3*(l / k) + 0];
                        D[3*l + 2] = D[3*(l / k) + 1];
                    }
                }
            }
        }
    }

    for(int n = 1; n < N; n++) {
        if(D[3*n + 0] > n) D[3*n + 0] = n;
        if(D[3*n + 1] > n) D[3*n + 1] = n;
        if(D[3*n + 2] > n) D[3*n + 2] = n;
    }

    int rounds;
    scanf("%d", &rounds);
    int o = 0, e = 0, i = 0;
    for(int r = 0; r < rounds; r++) {
        char c;
        int k;
        scanf(" %c %d", &c, &k);
        if(c == 'O') {
            o += D[3*k + 0];
            e += D[3*k + 1];
            i += D[3*k + 2];
        } else if(c == 'E') {
            e += D[3*k + 0];
            i += D[3*k + 1];
            o += D[3*k + 2];
        } else {
            i += D[3*k + 0];
            o += D[3*k + 1];
            e += D[3*k + 2];
        }
    }

    printf("%d %d %d\n", o, e, i);
    return 0;
}
