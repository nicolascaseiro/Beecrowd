#include <stdio.h>
#include <stdlib.h>

#define MAX 10005

int min (int a, int b) {
    if (a < b) 
		return a;
    else 
		return b;
}

int usado (int q, int M, int L) {
    if (q < M/L) 
		return q;
    else 
		return M/L;
}

int preenche (int *v, int M, int N, int L) {
    int tabuas = 0;
    int i = N/100, j, q;
    q = usado (v[i-1], M, L);
    M -= q*L;
    tabuas += q;
    i--;
    j = N/100-i;
    while (i > j && M > 0) {
        q = usado (min (v[i-1], v[j-1]), M, L); 
        M -= q*L;
        tabuas += 2*q;
        i--;
        j++;
    }
    if (i == j && M > 0) {
        q = usado (v[j-1]/2, M, L); 
        M -= q*L;
        tabuas += 2*q;
        i--;
        j++;
    }  
    if (M == 0) 
		return tabuas;
    else 
		return -1; 
}
 
int main () {
    int M, N, L, K, tabuas[MAX], tabua, i, horiz, vert;
    scanf ("%d %d", &M, &N);
    while (M > 0 || N > 0) {
        scanf ("%d %d", &L, &K);
        M = M*100;
        N = N*100;
        for (i = 0; i < MAX; i++) 
			tabuas[i] = 0;
        for (i = 0; i < K; i++) {
            scanf ("%d", &tabua);
            tabuas[tabua-1]++;
        }
        horiz = preenche(tabuas, M, N, L);
        vert = preenche(tabuas, N, M, L);
        if (horiz > 0)
            if (vert > 0) 
				printf ("%d\n", min (horiz, vert));
            else
				printf ("%d\n", horiz);
        else
            if (vert > 0) 
				printf ("%d\n", vert);
            else 
				printf ("impossivel\n");
        scanf ("%d %d", &M, &N);
    }
    return 0;
}
