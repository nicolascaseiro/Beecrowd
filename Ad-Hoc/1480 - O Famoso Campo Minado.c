#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MINA -2
#define DICA -3
#define COBERTO -1

int n, m, k, M[22][22], eh_mina[22][22];

int dentro(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= m);
}

int main() {
    while(1) {
        if (scanf("%d %d %d", &n, &m, &k) != 3) break;
        if (!(n || m || k)) break;
        memset(M, 0, sizeof M);
        memset(eh_mina, 0, sizeof eh_mina);
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                int ch = getchar();
                while(ch == '\n' || ch == ' ') ch = getchar();
                if(isdigit(ch)) M[i][j] = ch - '0';
                else M[i][j] = COBERTO;
            }
        }
        for(int i = 0; i < k; i++) {
            int a, b;
            scanf("%d %d", &a, &b);
            eh_mina[a][b] = 1;
        }
        for(int a = 1; a <= n * m; a++) {
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    if(M[i][j] >= 0) {
                        int coberto = 0, mina = 0;
                        for(int p = -1; p <= 1; p++) {
                            for(int q = -1; q <= 1; q++) {
                                int x = i + p, y = j + q;
                                if(!dentro(x, y)) continue;
                                if(M[x][y] == MINA) mina++;
                                else if(M[x][y] == COBERTO) coberto++;
                            }
                        }
                        if(mina == M[i][j]) {
                            for(int p = -1; p <= 1; p++) {
                                for(int q = -1; q <= 1; q++) {
                                    int x = i + p, y = j + q;
                                    if(!dentro(x, y)) continue;
                                    if(M[x][y] == COBERTO) M[x][y] = DICA;
                                }
                            }
                        } else if(coberto + mina == M[i][j]) {
                            for(int p = -1; p <= 1; p++) {
                                for(int q = -1; q <= 1; q++) {
                                    int x = i + p, y = j + q;
                                    if(!dentro(x, y)) continue;
                                    if(M[x][y] == COBERTO) M[x][y] = MINA;
                                }
                            }
                        }
                    }
                }
            }
            for(int i = 1; i <= n; i++) {
                for(int j = 1; j <= m; j++) {
                    if(M[i][j] == DICA) {
                        int soma = 0;
                        for(int p = -1; p <= 1; p++) {
                            for(int q = -1; q <= 1; q++) {
                                int x = i + p, y = j + q;
                                if(dentro(x, y)) soma += eh_mina[x][y];
                            }
                        }
                        M[i][j] = soma;
                    }
                }
            }
        }
        int ok = 1;
        for(int i = 1; i <= n && ok; i++) {
            for(int j = 1; j <= m && ok; j++) {
                if(M[i][j] == COBERTO) ok = 0;
            }
        }
        if(ok) printf("Possivel\n");
        else printf("Impossivel\n");
    }
    return 0;
}
