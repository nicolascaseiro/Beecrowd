#include <stdio.h>
#include <math.h>

int main() {
    
    long long N;
    while (scanf("%lld", &N) == 1) {
        if (N == 0) break;

        long long postes[N];
        long long index_primeiro_poste = -1;

        for (long long i = 0; i < N; i++) {
            scanf("%lld", &postes[i]);
            if (postes[i] == 1) index_primeiro_poste = i;
        }

        if (index_primeiro_poste == -1) {
            printf("%lld\n", (long long)ceil(N / 2.0));
            continue;
        }

        long long num_passos = N, i = index_primeiro_poste, quebrados = 0;
        long long resp = 0;

        while (num_passos > 0) {
            if (postes[i] == 0) {
                quebrados++;
            } else {
                quebrados = 0;
            }

            if (quebrados == 2) {
                postes[i] = 1;
                resp++;
                quebrados = 0;
            }

            i++;
            num_passos--;

            if (i == N) i = 0;
        }

        printf("%lld\n", resp);
    }

    return 0;
}
