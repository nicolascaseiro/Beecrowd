#include <stdio.h>

int main()
{
    int vet[5] = { 300, 1500, 600, 1000, 150 };
    int n, ans, i;

    ans = 0;
    for (i = 0; i < 5; ++i)
        scanf("%d", &n), ans += n * vet[i];

    ans += 225;

    printf("%d\n", ans);

    return 0;
}
