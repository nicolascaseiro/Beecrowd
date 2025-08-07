#include <stdio.h>

#define rep(i,a,b) for(int i = (a); i < (b); i++)

int main() {
    
    int P, S, Q;
    while(scanf("%d %d", &P, &S) == 2 && (P + S) != 0) {
        int t1, t2, t3;
        scanf("%d %d %d", &t1, &t2, &t3);

        int trapped[P];
        int place[P];

        rep(i, 0, P) {
            trapped[i] = 0;
            place[i] = 0;
        }

        scanf("%d", &Q);
        int d1, d2, mov, p = 0;

        while(Q--) {
            scanf("%d %d", &d1, &d2);
            mov = d1 + d2;

            while(trapped[p]) {
                trapped[p]--;
                p++;
                if(p == P) p = 0;
            }

            place[p] += mov;

            if(place[p] == t1 || place[p] == t2 || place[p] == t3)
                trapped[p] = 1;

            if(place[p] > S)
                printf("%d\n", p + 1);

            p++;
            if(p == P) p = 0;
        }
    }

    return 0;
}
