#include <stdio.h>
#include <string.h>

int soma[6001];

int checa(int x) {
    
    int freq[10];
    memset(freq, 0, sizeof(freq));
    while (x > 0) {
        freq[x % 10]++;
        x /= 10;
    }
    for (int i = 0; i < 10; i++) {
        if (freq[i] >= 2) {
            return 0;
        }
    }
    return 1;
}

int main() {
    
    soma[0] = 0;
    for (int i = 1; i <= 5000; i++) {
        soma[i] = soma[i - 1] + checa(i);
    }
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF) {
        printf("%d\n", soma[m] - soma[n - 1]);
    }
    return 0;
}
