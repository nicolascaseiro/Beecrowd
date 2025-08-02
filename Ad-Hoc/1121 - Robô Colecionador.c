#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX 102

char arena[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool andarParaFrente(int *linha, int *coluna, int direcao)
{
    if (!arena[*linha + dx[direcao]][*coluna + dy[direcao]])
        return false;
    if (arena[*linha + dx[direcao]][*coluna + dy[direcao]] == '#')
        return false;

    *linha += dx[direcao];
    *coluna += dy[direcao];

    if (arena[*linha][*coluna] == '*')
    {
        arena[*linha][*coluna] = '.';
        return true;
    }

    return false;
}

int main(void)
{
    char str[50001];
    int linhas, colunas, numComandos;
    
    while (scanf("%d %d %d", &linhas, &colunas, &numComandos) && linhas && colunas && numComandos)
    {
        int direcao = -1;
        int i, j;
        int linhaAtual = 0, colunaAtual = 0;
        int colecionadas = 0;

        memset(arena, 0, sizeof(arena));

        for (i = 1; i <= linhas; ++i)
        {
            scanf("%s", arena[i] + 1);
            for (j = 1; direcao < 0 && j <= colunas; ++j)
            {
                switch (arena[i][j])
                {
                    case 'N': direcao = 0; break;
                    case 'L': direcao = 1; break;
                    case 'S': direcao = 2; break;
                    case 'O': direcao = 3; break;
                }
                if (direcao >= 0)
                {
                    linhaAtual = i;
                    colunaAtual = j;
                }
            }
        }

        scanf("%s", str);

        for (i = 0; str[i]; ++i)
        {
            if (str[i] == 'F')
                colecionadas += andarParaFrente(&linhaAtual, &colunaAtual, direcao);
            else
                direcao = (str[i] == 'D') ? (direcao + 1) % 4 : (direcao + 3) % 4;
        }

        printf("%d\n", colecionadas);
    }

    return 0;
}
