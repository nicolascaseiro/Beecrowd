#include <stdio.h>

#define MAXN (13)
#define MAXC (7)
#define INF (1<<29)

int grafo[MAXN][MAXN];
int num_vertices, num_arestas, i_aux, resultado, custo_fixo;
int custo_total[1<<MAXN];
int dp[1<<MAXN][1<<MAXC];
int componente[MAXN];

int dfs(int vertice, int cor) {
	int i, tamanho = 1;
	componente[vertice] = cor;
	for (i = 0; i < num_vertices; i++) 
		if (grafo[vertice][i] < INF && componente[i] == -1) {
			tamanho += dfs(i, cor);
		}
	return tamanho;
}

int main() {
	int i, j, k, l;
	int mascara_paridade = 0, custo_conectado = 0, num_componentes = 0;
	scanf("%d %d", &num_vertices, &num_arestas);

	for (i = 0; i < num_vertices; i++) 
		for (j = 0; j < num_vertices; j++) 
			grafo[i][j] = INF;

	for (i = 0; i < num_arestas; i++) {
		int destino, origem, custo;
		scanf("%d %d %d", &origem, &destino, &custo);
		origem--; destino--;
		grafo[origem][destino] = grafo[destino][origem] = custo;
		custo_conectado += custo;
		mascara_paridade ^= (1 << destino) ^ (1 << origem);
	}

	for (i = 0; i < num_vertices; i++) componente[i] = -1;
	for (i = 0; i < num_vertices; i++) {
		if (componente[i] == -1) {
			if (dfs(i, num_componentes) > 1) {
				num_componentes++;
			} else {
				componente[i] = -1;
			}
		}
	}

	if (componente[0] == -1) componente[0] = num_componentes++;

	scanf("%d", &custo_fixo);
	for (i = 0; i < custo_fixo; i++) {
		int origem, destino, custo;
		scanf("%d %d %d", &origem, &destino, &custo);
		origem--; destino--;
		if (custo < grafo[origem][destino]) {
			grafo[origem][destino] = grafo[destino][origem] = custo;
		}
	}

	for (k = 0; k < num_vertices; k++) 
		for (i = 0; i < num_vertices; i++) 
			for (j = 0; j < num_vertices; j++) 
				if (grafo[i][k] + grafo[k][j] < grafo[i][j]) {
					grafo[i][j] = grafo[i][k] + grafo[k][j];
				}

	for (i = 0; i < (1 << num_vertices); i++)
		for (j = 0; j < (1 << num_componentes); j++)
			dp[i][j] = INF;

	for (i = 0; i < num_componentes; i++)
		dp[mascara_paridade][1 << i] = 0;

	for (j = 1; j < (1 << num_componentes); j++)	
		for (i = 0; i < (1 << num_vertices); i++)
			for (k = 0; k < num_vertices; k++)
				if (j & (1 << componente[k])) {
					for (l = 0; l < num_vertices; l++)
						if (l != k && grafo[k][l] < INF && componente[k] != componente[l] && (j & (1 << componente[l]))) {
							int custo = grafo[k][l] + dp[i ^ (1 << k) ^ (1 << l)][j ^ (1 << componente[k])];
							if (custo < dp[i][j]) dp[i][j] = custo;
						}
				}

	for (i = 0; i < (1 << num_vertices); i++) 
		custo_total[i] = dp[i][(1 << num_componentes) - 1];

	for (i = (1 << num_vertices) - 1; i >= 0; i--) 
		for (j = 0; j < num_vertices; j++)
			if (!(i & (1 << j)))
				for (k = j + 1; k < num_vertices; k++)
					if (!(i & (1 << k))) {
						int custo = grafo[j][k] + custo_total[i ^ (1 << j) ^ (1 << k)];
						if (custo < custo_total[i])
							custo_total[i] = custo; 
					}

	printf("%d\n", custo_total[0] + custo_conectado);
	return 0;
}
