#include <stdio.h>
#include <stdlib.h>

int cmp_int(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main() {
    
    int a, b, c;

    while (scanf("%d %d %d", &a, &b, &c) == 3 && a != 0) {
        int numbers[3] = {a, b, c};
        int unique[3];
        int unique_count = 0;

        for (int i = 0; i < 3; i++) {
            int found = 0;
            for (int j = 0; j < unique_count; j++) {
                if (numbers[i] == unique[j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) unique[unique_count++] = numbers[i];
        }

        if (unique_count == 3) {
            printf("1 1 2\n");
            continue;
        }

        if (unique_count == 2) {
            int rep, alone;

            if (a == b) {
                rep = a; alone = c;
            } else if (a == c) {
                rep = a; alone = b;
            } else {
                rep = b; alone = a;
            }

            if (rep == 13 && alone == 12) {
                printf("1 1 1\n");
                continue;
            } else if (alone == 13) {
                int resp[3] = {rep + 1, rep + 1, 1};
                qsort(resp, 3, sizeof(int), cmp_int);
                printf("%d %d %d\n", resp[0], resp[1], resp[2]);
            } else {
                if (alone + 1 == rep) alone++;
                int resp[3] = {rep, rep, alone + 1};
                qsort(resp, 3, sizeof(int), cmp_int);
                printf("%d %d %d\n", resp[0], resp[1], resp[2]);
            }
            continue;
        }

        if (a == 13) {
            printf("*\n");
        } else {
            printf("%d %d %d\n", a + 1, a + 1, a + 1);
        }
    }

    return 0;
}
