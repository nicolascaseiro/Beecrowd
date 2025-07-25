#include <stdio.h>

int main() {
    int m, a, b, c;
    scanf("%d %d %d", &m, &a, &b);
    c = m - (a + b);
    int arr[3] = {a, b, c};

    for (int i = 0; i < 2; i++) {
        for (int j = i + 1; j < 3; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("%d\n", arr[2]);
    return 0;
}
