#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

typedef struct {
    ll largura;
    ll altura;
    ll comprimento;
    ll volume;
} Caixa;

int cmp_ll(const void *a, const void *b) {
    ll x = *(ll*)a;
    ll y = *(ll*)b;
    if (x < y) return -1;
    else if (x > y) return 1;
    return 0;
}

int verificar(Caixa *c1, ll largura, ll altura, ll comprimento) {
    return (c1->largura >= largura && c1->altura >= altura && c1->comprimento >= comprimento);
}

int encaixa(Caixa *c1, Caixa *c2) {
    
    if (c1->volume < c2->volume) return 0;
    if (verificar(c1, c2->largura, c2->altura, c2->comprimento)) return 1;
    if (verificar(c1, c2->largura, c2->comprimento, c2->altura)) return 1;
    if (verificar(c1, c2->comprimento, c2->altura, c2->largura)) return 1;
    if (verificar(c1, c2->comprimento, c2->largura, c2->altura)) return 1;
    if (verificar(c1, c2->altura, c2->comprimento, c2->largura)) return 1;
    if (verificar(c1, c2->altura, c2->largura, c2->comprimento)) return 1;
    return 0;
}

typedef struct {
    ll dimensoes[3];
    ll quantidade;
} CaixaInfo;

int main() {
    
    ll n_itens, qtd;
    while (1) {
        if (scanf("%lld %lld", &n_itens, &qtd) != 2) break;
        if (n_itens == 0 && qtd == 0) break;

        ll x, y, z;
        scanf("%lld %lld %lld", &x, &y, &z);
        Caixa item = {x, y, z, x * y * z};

        CaixaInfo caixas[10000];
        int caixas_count = 0;

        for (ll i = 0; i < qtd; i++) {
            ll dim[3];
            scanf("%lld %lld %lld", &dim[0], &dim[1], &dim[2]);
            qsort(dim, 3, sizeof(ll), cmp_ll);

            int found = 0;
            for (int j = 0; j < caixas_count; j++) {
                if (caixas[j].dimensoes[0] == dim[0] &&
                    caixas[j].dimensoes[1] == dim[1] &&
                    caixas[j].dimensoes[2] == dim[2]) {
                    caixas[j].quantidade++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                caixas[caixas_count].dimensoes[0] = dim[0];
                caixas[caixas_count].dimensoes[1] = dim[1];
                caixas[caixas_count].dimensoes[2] = dim[2];
                caixas[caixas_count].quantidade = 1;
                caixas_count++;
            }
        }

        ll ans = -1;
        for (int i = 0; i < caixas_count; i++) {
            if (caixas[i].quantidade < n_itens) continue;

            Caixa c = {caixas[i].dimensoes[0], caixas[i].dimensoes[1], caixas[i].dimensoes[2],
                       caixas[i].dimensoes[0] * caixas[i].dimensoes[1] * caixas[i].dimensoes[2]};

            if (encaixa(&c, &item)) {
                ll diff = c.volume - item.volume;
                if (ans == -1 || diff < ans) ans = diff;
            }
        }

        if (ans == -1)
            printf("impossible\n");
        else
            printf("%lld\n", ans);
    }
    return 0;
}
