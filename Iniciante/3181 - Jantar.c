#include <stdio.h>
#include <string.h>
#include <assert.h>

#define MAX_pessoas 500
#define ANO_MIN 1928
#define ANO_MAX 2008

int F[MAX_pessoas][MAX_pessoas];
int m, c;

int G[MAX_pessoas];
int M[3][MAX_pessoas];

int conta_grupo(int g) {
  int c = 0;
  for (int a = 0; a < m; ++a) if (G[a] == g) c++;
  return c;
}

int verifica_contagem() {
  return (3 * conta_grupo(1) <= 2 * m) && (3 * conta_grupo(2) <= 2 * m);
}

int verifica(int Y, int a, int b) {
  assert(a != b);
  if (G[a] > 0 && G[a] == G[b]) {
    if (G[a] == 1 && F[a][b] >= Y) return 0;
    if (G[a] == 2 && F[a][b] <  Y) return 0;
  }
  return 1;
}

int verifica_pessoa(int Y, int a) {
  for (int b = 0; b < m; ++b)
    if (a != b && !verifica(Y, a, b))
      return 0;
  return 1;
}

int verifica_geral(int Y) {
  for (int a = 0; a < m; ++a)
    if (!verifica_pessoa(Y, a))
      return 0;
  return 1;
}

int coloca(int Y, int a, int g) {
  if (G[a] == g) return 1;
  if (G[a]) return 0;
  G[a] = g;
  if (!verifica_contagem() || !verifica_pessoa(Y, a)) return 0;
  for (int b = 0; b < m; ++b)
    if (a != b)
      if ((g == 1 && F[a][b] >= Y) || (g == 2 && F[a][b] < Y))
        if (!coloca(Y, b, 3 - g))
          return 0;
  return 1;
}

int resolve(int Y) {
  for (int a = 0; a < m; ++a) {
    if (!G[a]) {
      int backup[MAX_pessoas];
      memcpy(backup, G, sizeof(int) * m);
      for (int g = 1; g <= 2; ++g) {
        if (coloca(Y, a, g) && resolve(Y)) return 1;
        memcpy(G, backup, sizeof(int) * m);
      }
      return 0;
    }
  }
  assert(verifica_geral(Y));
  return 1;
}

int sulve(int Y) {
  memset(G, 0, sizeof(int) * m);
  memset(M[1], 0, sizeof(int) * m);
  memset(M[2], 0, sizeof(int) * m);
  for (int a = 0; a < m; ++a)
    for (int b = 0; b < m; ++b)
      if (a != b) {
        if (F[a][b] < Y) M[1][a]++;
        if (F[a][b] >= Y) M[2][a]++;
      }
  for (int a = 0; a < m; ++a) {
    if (3 * (M[1][a] + 1) < m)
      if (!coloca(Y, a, 2)) return 0;
    if (3 * (M[2][a] + 1) < m)
      if (!coloca(Y, a, 1)) return 0;
  }
  return resolve(Y);
}

int main() {
  scanf("%d %d", &m, &c);
  for (int a = 0; a < m; ++a)
    for (int b = 0; b < m; ++b)
      F[a][b] = ANO_MAX;
  for (int i = 0; i < c; ++i) {
    int a, b, y;
    scanf("%d %d %d", &a, &b, &y);
    F[a-1][b-1] = F[b-1][a-1] = y;
  }
  int Y;
  for (Y = ANO_MIN; Y <= ANO_MAX; ++Y)
    if (sulve(Y)) break;
  if (Y <= ANO_MAX) printf("%d\n", Y);
  else              printf("Impossible\n");
  return 0;
}
