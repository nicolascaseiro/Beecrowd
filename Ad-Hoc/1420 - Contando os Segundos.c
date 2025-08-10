#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int dia_semana, dia, mes, segundos_fixos, ano, hora, minuto, segundo;
} momento;

momento instante_atual, instante_acumulado;
int fim_de_mes[12] = {132, 230, 332, 431, 532, 631,
                      732, 832, 931, 1032, 1131, 1232};

void incrementa_tempo(void) {
  int i, j;
  instante_acumulado.segundo++;
  if (instante_acumulado.segundo == 60) {
    instante_acumulado.segundo = 0;
    instante_acumulado.minuto++;
    if (instante_acumulado.minuto == 60) {
      instante_acumulado.minuto = 0;
      instante_acumulado.hora++;
      if (instante_acumulado.hora == 24) {
        instante_acumulado.hora = 0;
        instante_acumulado.dia_semana = (instante_acumulado.dia_semana + 1) % 7;
        instante_acumulado.dia++;
        j = 100 * instante_acumulado.mes + instante_acumulado.dia;
        for (i = 0; (i < 12) && (j != fim_de_mes[i]); i++);
        if ((i < 12) || ((j == 229) && (instante_acumulado.ano % 4))) {
          instante_acumulado.dia = 1;
          instante_acumulado.mes++;
          if (instante_acumulado.mes == 13) {
            instante_acumulado.mes = 1;
            instante_acumulado.ano++;
          }
        }
      }
    }
  }
}

int main() {
    
  long segundos_adicionados, contador_segundos;
  int i, previsao_numero = 0;

  char nomes_dia_semana[7][4] = {"SAB", "DOM", "SEG", "TER", "QUA", "QUI", "SEX"};
  char nomes_mes[12][4] = {"JAN", "FEV", "MAR", "ABR", "MAI", "JUN",
                          "JUL", "AGO", "SET", "OUT", "NOV", "DEZ"};

  char entrada_dia_semana[4], entrada_mes[4], linha[256];

  while (1) {
    if (!fgets(linha, sizeof(linha), stdin)) break;
    if (linha[0] == 'F') break;

    for (i = 0; i < 3; i++) entrada_dia_semana[i] = linha[i];
    entrada_dia_semana[3] = '\0';

    for (i = 0; i < 7 && strcmp(entrada_dia_semana, nomes_dia_semana[i]) != 0; i++);
    if (i == 7) return 1;
    instante_atual.dia_semana = i;

    instante_atual.dia = 10 * (linha[4] - '0') + (linha[5] - '0');

    for (i = 0; i < 3; i++) entrada_mes[i] = linha[i + 6];
    entrada_mes[3] = '\0';

    for (i = 0; i < 12 && strcmp(entrada_mes, nomes_mes[i]) != 0; i++);
    if (i == 12) return 1;
    instante_atual.mes = i + 1;

    instante_atual.segundos_fixos = 20;
    instante_atual.ano = 10 * (linha[11] - '0') + (linha[12] - '0');
    instante_atual.hora = 10 * (linha[14] - '0') + (linha[15] - '0');
    instante_atual.minuto = 10 * (linha[17] - '0') + (linha[18] - '0');
    instante_atual.segundo = 10 * (linha[20] - '0') + (linha[21] - '0');

    printf("Previsao #%d\n", ++previsao_numero);

    for (i = 0; i < 5; i++) {
      instante_acumulado = instante_atual;
      if (scanf("%ld", &segundos_adicionados) != 1) return 1;
      getchar();

      for (contador_segundos = 0; contador_segundos < segundos_adicionados; contador_segundos++) {
        incrementa_tempo();
      }

      printf("%s,%02d%s%02d%02d:%02d:%02d:%02d\n",
             nomes_dia_semana[instante_acumulado.dia_semana],
             instante_acumulado.dia,
             nomes_mes[instante_acumulado.mes - 1],
             instante_acumulado.segundos_fixos,
             instante_acumulado.ano,
             instante_acumulado.hora,
             instante_acumulado.minuto,
             instante_acumulado.segundo);
    }
  }
  return 0;
}
