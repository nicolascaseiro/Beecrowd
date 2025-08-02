#include <stdio.h>
#include <string.h>

int m[9][9];

int valid(int x, int y){
    
    if(x < 1 || x > 8 || y < 1 || y > 8) 
        return 0;
    if(x + 1 <= 8 && y + 1 <= 8)
    {
        if(m[x+1][y+1] == 1) 
            return 0;
    }
    if(x + 1 <= 8 && y - 1 >= 1)
    {
        if(m[x+1][y-1] == 1) 
            return 0;
    }
    return 1;
}

int main() {
    
    char c[10];
    int t = 1;
    scanf("%s", c);
    while(strlen(c) > 1)
    {
        for(int i = 0; i <= 8; i++)
            for(int j = 0; j <= 8; j++)
                m[i][j] = 0;
        int x = c[0] - '0';
        int y = c[1] - 'a' + 1;

        for(int i = 0; i < 8; i++)
        {
            char s[10];
            scanf("%s", s);
            int a = s[0] - '0';
            int b = s[1] - 'a' + 1;
            m[a][b] = 1;
        }
        int ans = 8;
        if(!valid(x-1, y-2)) ans--;
        if(!valid(x-2, y-1)) ans--;
        if(!valid(x-2, y+1)) ans--;
        if(!valid(x-1, y+2)) ans--;
        if(!valid(x+1, y+2)) ans--;
        if(!valid(x+2, y+1)) ans--;
        if(!valid(x+2, y-1)) ans--;
        if(!valid(x+1, y-2)) ans--;

        printf("Caso de Teste #%d: %d movimento(s).\n", t, ans);
        t++;
        scanf("%s", c);
    }
    return 0;
}
