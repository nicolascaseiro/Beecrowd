#include <stdio.h>

int main()
{
    int x, y, m;
    
    while (scanf("%d %d %d", &x, &y, &m) == 3)
    {
        int a, b;
        for (int i = 0; i < m; ++i)
        {
            scanf("%d %d", &a, &b);
            if ((a <= x && b <= y) || (a <= y && b <= x))
                printf("Sim\n");
            else
                printf("Nao\n");
        }
    }

    return 0;
}
