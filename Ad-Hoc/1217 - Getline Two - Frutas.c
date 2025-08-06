#include <string.h>
#include <stdio.h>

int main() {
    
    char *pos;
    char linha[10000];
    double V, pesoPorDia, gastoPorDia;
    int N, fruta;

    scanf("%d\n", &N);

    pesoPorDia = 0.0;
    gastoPorDia = 0.0;
    
    for(int i = 1; i <= N; ++i){
        scanf("%lf\n", &V);
        scanf("%[^\n]", &linha);

        fruta = 1;
        pos = strchr(linha, ' ');
        while(pos != NULL){
            ++fruta;
            pos = strchr(pos + 1, ' ');
        }

        printf("day %d: %d kg\n", i, fruta);

        pesoPorDia += fruta;
        gastoPorDia += V;
    }

    pesoPorDia /= N;
    gastoPorDia /= N;

    printf("%.2lf kg by day\nR$ %.2lf by day\n", pesoPorDia, gastoPorDia);

    return 0;
}
