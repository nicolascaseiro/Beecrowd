#include <stdio.h>
#include <string.h>

#define MAXC (201)
#define MAXP (100)

char palavras[MAXP][MAXC];
int qtd_palavras;
int mapa_palavras[MAXP];

char mapa_a[256], mapa_b[256];
int mapa_a_qtd[256], mapa_b_qtd[256];
int sol_encontrada = 0;
int ambigua = 0;

#define qtd_palavras_chave (12)
char palavras_chave[qtd_palavras_chave][MAXC] = {
    {"be"},{"will"},{"our"},{"rum"},{"dead"},{"hook"},
    {"ship"},{"blood"},{"sable"},{"avenge"},{"parrot"},{"captain"}
};
char solucao[256];
int vistos[256];

void mapear_recursivo(int indice_chave)
{
    int i;
    int indice_palavra;
    char c;
    int sem_mapeamento = 0;

    for (c = 'a'; c <= 'z' && !sem_mapeamento; c++) {
        sem_mapeamento = (vistos[c] && !mapa_a_qtd[c]);
    }

    if (!sem_mapeamento) {
        if (sol_encontrada) {
            int igual = 1;
            for (c = 'a'; c <= 'z' && igual; c++) {
                igual = mapa_a[c] == solucao[c];
            }
            if (!igual) {
                ambigua = 1;
            }
        } else {
            sol_encontrada = 1;
            for (c = 'a'; c <= 'z'; c++) {
                solucao[c] = mapa_a[c];
            }
        }

    } else if (indice_chave < qtd_palavras_chave) {

        for (indice_palavra = 0; indice_palavra < qtd_palavras && !ambigua; indice_palavra++) {
            if (mapa_palavras[indice_palavra] == 0 && strlen(palavras[indice_palavra]) == strlen(palavras_chave[indice_chave])) {
                int corresponde = 1, ultimo = -1;
                for (i = 0; i < strlen(palavras_chave[indice_chave]) && corresponde; i++) {
                    corresponde = !((mapa_a_qtd[palavras[indice_palavra][i]] && 
                                     (mapa_a[palavras[indice_palavra][i]] != palavras_chave[indice_chave][i])) ||
                                    (mapa_b_qtd[palavras_chave[indice_chave][i]] &&
                                     (mapa_b[palavras_chave[indice_chave][i]] != palavras[indice_palavra][i])));
                    if (corresponde) {
                        mapa_a_qtd[palavras[indice_palavra][i]]++;
                        mapa_a[palavras[indice_palavra][i]] = palavras_chave[indice_chave][i];
                        mapa_b_qtd[palavras_chave[indice_chave][i]]++;
                        mapa_b[palavras_chave[indice_chave][i]] = palavras[indice_palavra][i];
                        ultimo = i;
                    }
                }

                if (corresponde) {
                    mapa_palavras[indice_palavra] = 1;
                    mapear_recursivo(indice_chave + 1);
                    mapa_palavras[indice_palavra] = 0;
                }
                for (i = 0; i < ultimo + 1; i++) {
                    mapa_a_qtd[palavras[indice_palavra][i]]--;
                    mapa_b_qtd[palavras_chave[indice_chave][i]]--;
                }
            }
        }

        mapear_recursivo(indice_chave + 1);
    }
}

int main()
{
    char c;
    int i, j;
    qtd_palavras = 0;
    for (c = 'a'; c <= 'z'; c++) {
        vistos[c] = 0;
    }
    while (scanf("%s", palavras[qtd_palavras]) != EOF) {
        for (i = 0; i < strlen(palavras[qtd_palavras]); i++) {
            vistos[palavras[qtd_palavras][i]] = 1;
        }
        qtd_palavras++;
    }

    for (c = 'a'; c <= 'z'; c++) {
        mapa_a_qtd[c] = mapa_b_qtd[c] = 0;
    }

    for (i = 0; i < qtd_palavras; i++) {
        mapa_palavras[i] = 0;
    }

    mapear_recursivo(0);

    if (!ambigua && sol_encontrada) {
        for (i = 0; i < qtd_palavras; i++) {
            for (j = 0; j < strlen(palavras[i]); j++)
                printf("%c", solucao[palavras[i][j]]);
            if (i < qtd_palavras - 1) printf(" ");
        }
        printf("\n");
    } else {
        printf("Impossible\n");
    }

    return 0;
}
