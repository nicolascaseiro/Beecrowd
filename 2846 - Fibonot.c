#include <stdio.h>
#include <stdbool.h>

#define MAX 1000000

bool fib[MAX] = {false};

void generateFibonacci() {
    int i, t1 = 1, t2 = 1, nextTerm;

    fib[t1] = true;
    fib[t2] = true;

    for (i = 1; i <= MAX; i++) {
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        if (nextTerm < MAX) {
            fib[nextTerm] = true;
        } else {
            break;
        }
    }
}

int fibonot(int k) {
    generateFibonacci();

    int count = 0;
    for (int i = 1; i < MAX; i++) {
        if (!fib[i]) {
            count++;
            if (count == k) {
                return i;
            }
        }
    }

    return -1;
}

int main() {
    int k;
    scanf("%d", &k);
    printf("%d\n", fibonot(k));

    return 0;
}
