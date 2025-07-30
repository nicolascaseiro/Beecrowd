#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI 3.1415
#endif

#define MAX 505
#define INF 1e9
#define EPS 1e-8

typedef struct {
    int x, y;
} Celula;

typedef struct {
    double inicio, fim;
} Intervalo;

double altura[MAX][MAX], inundacao[MAX][MAX], desinundacao[MAX][MAX];
double vis[MAX][MAX], vis_rev[MAX][MAX];
double a, m;
int W, H, X, Y;

Celula dir[4] = {{0,-1}, {0,1}, {-1,0}, {1,0}};

Intervalo tentar_arco(Celula a_c, Celula b_c) {
    if (fabs(altura[a_c.y][a_c.x] - altura[b_c.y][b_c.x]) > 1.0 + EPS)
        return (Intervalo){0, 0};
    double inferior = inundacao[a_c.y][a_c.x] > inundacao[b_c.y][b_c.x] ? inundacao[a_c.y][a_c.x] + 1.0 : inundacao[b_c.y][b_c.x] + 1.0;
    double superior = desinundacao[a_c.y][a_c.x] < desinundacao[b_c.y][b_c.x] ? desinundacao[a_c.y][a_c.x] - m : desinundacao[b_c.y][b_c.x] - m;
    if (inferior - superior > EPS) return (Intervalo){0, 0};
    return (Intervalo){inferior, superior};
}

double tempo_inundacao(double h) {
    if (h > a + EPS) return -1000;
    double v = (2.0 * h / a) - 1.0;
    if (v < -1.0) v = -1.0;
    else if (v > 1.0) v = 1.0;
    return (6.0 / M_PI) * acos(v);
}

typedef struct {
    Intervalo intervalo[4];
    Celula viz[4];
} Vertice;

Vertice grafo[MAX][MAX];
Vertice grafo_rev[MAX][MAX];

typedef struct {
    int x, y;
} FilaElem;

FilaElem fila[MAX*MAX];

void bfs() {
    int ini = 0, fim = 0;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            vis[i][j] = INF;

    vis[Y][X] = 0.0;
    fila[fim++] = (FilaElem){X, Y};

    while (ini < fim) {
        FilaElem e = fila[ini++];
        double t = vis[e.y][e.x];

        for (int k = 0; k < 4; k++) {
            Celula u = grafo[e.y][e.x].viz[k];
            Intervalo inter = grafo[e.y][e.x].intervalo[k];
            if (inter.inicio == 0 && inter.fim == 0) continue;
            if (t - inter.fim > EPS) continue;
            double prox_t = t > inter.inicio ? t + m : inter.inicio + m;
            if (prox_t + EPS < vis[u.y][u.x]) {
                vis[u.y][u.x] = prox_t;
                fila[fim].x = u.x;
                fila[fim].y = u.y;
                fim++;
            }
        }
    }
}

void bfs_rev() {
    int ini = 0, fim = 0;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            vis_rev[i][j] = -INF;

    vis_rev[Y][X] = 12.0;
    fila[fim++] = (FilaElem){X, Y};

    while (ini < fim) {
        FilaElem e = fila[ini++];
        double t = vis_rev[e.y][e.x];

        for (int k = 0; k < 4; k++) {
            Celula u = grafo_rev[e.y][e.x].viz[k];
            Intervalo inter = grafo_rev[e.y][e.x].intervalo[k];
            if (inter.inicio == 0 && inter.fim == 0) continue;
            if (inter.inicio - t > EPS) continue;
            double prox_t = t < inter.fim ? t - m : inter.fim - m;
            if (prox_t - vis_rev[u.y][u.x] > EPS) {
                vis_rev[u.y][u.x] = prox_t;
                fila[fim].x = u.x;
                fila[fim].y = u.y;
                fim++;
            }
        }
    }
}

long long obter_melhor() {
    long long melhor = 0;
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            if (vis[i][j] - vis_rev[i][j] <= EPS) {
                long long dx = j - X;
                long long dy = i - Y;
                long long dist = dx * dx + dy * dy;
                if (dist > melhor) melhor = dist;
            }
        }
    }
    return melhor;
}

int main() {
    scanf("%lf %lf", &a, &m);
    m /= 3600.0;
    scanf("%d %d %d %d", &W, &H, &X, &Y);
    X++; Y++;

    for (int i = 0; i <= H + 1; i++)
        for (int j = 0; j <= W + 1; j++)
            altura[i][j] = 100.0;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            double h;
            scanf("%lf", &h);
            altura[i][j] = h / 1000.0;
        }
    }

    for (int i = 0; i <= H + 1; i++) {
        for (int j = 0; j <= W + 1; j++) {
            inundacao[i][j] = tempo_inundacao(altura[i][j]);
            desinundacao[i][j] = 12.0 - inundacao[i][j];
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            for (int k = 0; k < 4; k++) {
                Celula u = {j, i};
                Celula v = {j + dir[k].x, i + dir[k].y};
                Intervalo inter = tentar_arco(u, v);

                grafo[i][j].viz[k] = v;
                grafo[i][j].intervalo[k] = inter;

                int rev_k = k ^ 1;
                grafo_rev[v.y][v.x].viz[rev_k] = u;
                grafo_rev[v.y][v.x].intervalo[rev_k] = inter;
            }
        }
    }

    bfs();
    bfs_rev();

    long long r = obter_melhor();
    printf("%.8f\n", sqrt((double)r) * 10.0);

    return 0;
}
