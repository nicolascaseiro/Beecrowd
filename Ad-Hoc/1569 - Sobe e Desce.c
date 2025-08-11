#include <stdio.h>

int pos[1000010];
int caminho[101];
int usado[101], contador = 1;

void scanint(int *x){
    register int ccc = getchar(), num = 0;
    while(ccc < '0' || ccc > '9') ccc = getchar();
    while(ccc >= '0' && ccc <= '9'){
        num = num * 10 + (ccc - '0');
        ccc = getchar();
    }
    *x = num;
}

int main(){
    int T;
    scanint(&T);
    while(T--){
        int jogadores, cobras_escadas, jogadas;
        scanint(&jogadores); scanint(&cobras_escadas); scanint(&jogadas);

        contador++;
        for(int i = 0; i < cobras_escadas; i++){
            int inicio, fim;
            scanint(&inicio); scanint(&fim);
            usado[inicio] = contador;
            caminho[inicio] = fim;
        }

        for(int i = 1; i <= jogadores; i++)
            pos[i] = 1;

        int jogador_atual = 1;
        int venceu = 0;

        while(jogadas--){
            int dado;
            scanint(&dado);

            if(venceu) continue;

            pos[jogador_atual] += dado;
            if(usado[pos[jogador_atual]] == contador)
                pos[jogador_atual] = caminho[pos[jogador_atual]];

            if(pos[jogador_atual] >= 100){
                pos[jogador_atual] = 100;
                venceu = 1;
            }

            jogador_atual++;
            if(jogador_atual > jogadores) jogador_atual = 1;
        }

        for(int i = 1; i <= jogadores; i++){
            printf("Position of player %d is %d.\n", i, pos[i]);
        }
    }

    return 0;
}
