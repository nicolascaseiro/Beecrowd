#include <stdio.h>
#include <string.h>

#define MAXN 41
#define ADD 640000
#define MAXP (MAXN + 1)

int V[MAXN];
int freq[2 * ADD + 1][2];
int NT, N, M, C, iteracao = 0;

int p1[MAXP], p2[MAXP];
int positivo1[MAXP], positivo2[MAXP];
int negativo1[MAXP], negativo2[MAXP];

int checa(int val, int id) {
    val += ADD;
    if (val < 0) return 0;
    return (freq[val][id] == iteracao);
}

void adiciona1(int pos, int val, int bitmask) {
    if (pos == N) {
        freq[val + ADD][0] = iteracao;
        return;
    }
    adiciona1(pos + 1, val + p1[pos], bitmask | (1 << pos));
    adiciona1(pos + 1, val - p1[pos], bitmask);
}

void adiciona2(int pos, int val, int bitmask) {
    if (pos == M) {
        freq[val + ADD][1] = iteracao;
        return;
    }
    adiciona2(pos + 1, val + p2[pos], bitmask | (1 << pos));
    adiciona2(pos + 1, val - p2[pos], bitmask);
}

void checa1(int pos, int val, int bitmask) {
    if (pos == N) {
        if (!checa(C - val, 1)) return;
        for (int i = 0; i < N; i++) {
            if (bitmask & (1 << i)) {
                positivo1[i]++;
            } else {
                negativo1[i]++;
            }
        }
        return;
    }
    checa1(pos + 1, val + p1[pos], bitmask | (1 << pos));
    checa1(pos + 1, val - p1[pos], bitmask);
}

void checa2(int pos, int val, int bitmask) {
    if (pos == M) {
        if (!checa(C - val, 0)) return;
        for (int i = 0; i < M; i++) {
            if (bitmask & (1 << i)) {
                positivo2[i]++;
            } else {
                negativo2[i]++;
            }
        }
        return;
    }
    checa2(pos + 1, val + p2[pos], bitmask | (1 << pos));
    checa2(pos + 1, val - p2[pos], bitmask);
}

int main() {
    while (scanf("%d %d", &NT, &C) == 2 && (NT || C)) {
        iteracao++;

        N = NT / 2;
        M = NT - N;

        for (int i = 0; i < N; i++) {
            scanf("%d", &p1[i]);
            positivo1[i] = 0;
            negativo1[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            scanf("%d", &p2[i]);
            positivo2[i] = 0;
            negativo2[i] = 0;
        }

        adiciona1(0, 0, 0);
        adiciona2(0, 0, 0);
        checa1(0, 0, 0);
        checa2(0, 0, 0);

        int flag = 0;
        for (int i = 0; i < N; i++) {
            if (positivo1[i] == 0 && negativo1[i] == 0) {
                flag = 1;
            }
        }
        for (int i = 0; i < M; i++) {
            if (positivo2[i] == 0 && negativo2[i] == 0) {
                flag = 1;
            }
        }

        if (flag) {
            printf("*\n");
            continue;
        }

        for (int i = 0; i < N; i++) {
            if (positivo1[i] && negativo1[i] == 0) {
                printf("+");
            } else if (positivo1[i] == 0 && negativo1[i]) {
                printf("-");
            } else {
                printf("?");
            }
        }

        for (int i = 0; i < M; i++) {
            if (positivo2[i] && negativo2[i] == 0) {
                printf("+");
            } else if (positivo2[i] == 0 && negativo2[i]) {
                printf("-");
            } else {
                printf("?");
            }
        }

        printf("\n");
    }

    return 0;
}
