#include <stdio.h>

int main() {
    int n, a, b;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a);
        switch (a) {
            case 1: b = 0; break;
            case 2: b = 6; break;
            case 3: b = 12; break;
            case 4: b = 90; break;
            case 5: b = 360; break;
            case 6: b = 2040; break;
            case 7: b = 10080; break;
            case 8: b = 54810; break;
            case 9: b = 290640; break;
            case 10: b = 1588356; break;
            case 11: b = 8676360; break;
            case 12: b = 47977776; break;
            case 13: b = 266378112; break;
            default: b = 1488801600; break;
        }
        printf("%d\n", b);
    }

    return 0;
}
