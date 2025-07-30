#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define UM "um"
#define DOIS "dois"
#define TRES "tres"
#define CIRCULO 'c'
#define TRIANGULO 't'
#define QUADRADO 'q'
#define TAM 3

struct node {
    int data;
    struct node* next;
};

typedef struct node Node;

typedef struct {
    Node* head;
    Node* tail;
} Lista;

int mapear_numero(char* numero) {
    if (strcmp(numero, UM) == 0) return 0;
    if (strcmp(numero, DOIS) == 0) return 1;
    return 2;
}

int mapear_figura(char* figura) {
    if (figura[0] == CIRCULO) return 0;
    if (figura[0] == TRIANGULO) return 1;
    return 2;
}

bool tem_todas_cartas(int baralho[TAM][TAM]) {
    for (int f=0; f<TAM; f++)
        for (int n=0; n<TAM; n++)
            if (baralho[f][n] == 0) return false;
    return true;
}

void contar_sets_linhas(int baralho[TAM][TAM], int* total) {
    for (int f=0; f<TAM; f++)
        while(baralho[f][0]>0 && baralho[f][1]>0 && baralho[f][2]>0) {
            (*total)++;
            baralho[f][0]--;
            baralho[f][1]--;
            baralho[f][2]--;
        }
}

void contar_sets_colunas(int baralho[TAM][TAM], int* total) {
    for (int n=0; n<TAM; n++)
        while(baralho[0][n]>0 && baralho[1][n]>0 && baralho[2][n]>0) {
            (*total)++;
            baralho[0][n]--;
            baralho[1][n]--;
            baralho[2][n]--;
        }
}

void contar_sets_diagonal_principal(int baralho[TAM][TAM], int* total) {
    while(baralho[0][0]>0 && baralho[1][1]>0 && baralho[2][2]>0) {
        (*total)++;
        baralho[0][0]--;
        baralho[1][1]--;
        baralho[2][2]--;
    }
}

void contar_sets_diagonal_secundaria(int baralho[TAM][TAM], int* total) {
    while(baralho[0][2]>0 && baralho[1][1]>0 && baralho[2][0]>0) {
        (*total)++;
        baralho[0][2]--;
        baralho[1][1]--;
        baralho[2][0]--;
    }
}

void contar_sets_mesmo_indice(int baralho[TAM][TAM], int* total) {
    for (int f=0; f<TAM; f++)
        for (int n=0; n<TAM; n++) {
            if (baralho[f][n] >= 3) {
                (*total) += baralho[f][n]/3;
                baralho[f][n] %= 3;
            }
        }
}

void contar_sets_indices_diferentes(int baralho[TAM][TAM], int* total) {
    while(baralho[0][0]>0 && baralho[1][2]>0 && baralho[2][1]>0) {
        (*total)++;
        baralho[0][0]--;
        baralho[1][2]--;
        baralho[2][1]--;
    }
    while(baralho[0][2]>0 && baralho[1][0]>0 && baralho[2][1]>0) {
        (*total)++;
        baralho[0][2]--;
        baralho[1][0]--;
        baralho[2][1]--;
    }
    while(baralho[0][1]>0 && baralho[1][0]>0 && baralho[2][2]>0) {
        (*total)++;
        baralho[0][1]--;
        baralho[1][0]--;
        baralho[2][2]--;
    }
    while(baralho[0][1]>0 && baralho[1][2]>0 && baralho[2][0]>0) {
        (*total)++;
        baralho[0][1]--;
        baralho[1][2]--;
        baralho[2][0]--;
    }
}

void contar_sets_resto(int baralho[TAM][TAM], int* total) {
    int soma = 0;
    for (int f=0; f<TAM; f++)
        for (int n=0; n<TAM; n++)
            soma += baralho[f][n];

    if (soma > 3 && soma < 6) (*total)++;
    else if (soma == 6) {
        if (baralho[0][2]>0 && baralho[1][0]>0 && baralho[1][1]>0 && baralho[2][2]>0) (*total) += 2;
        else if (baralho[0][0]>0 && baralho[1][1]>0 && baralho[1][2]>0 && baralho[2][0]>0) (*total) += 2;
        else if (baralho[0][1]>0 && baralho[1][0]>0 && baralho[1][2]>0 && baralho[2][1]>0) (*total) += 2;
        else (*total)++;
    }
    else if (soma > 6 && soma < 9) (*total) += 2;
}

int total_sets(int baralho[TAM][TAM]) {
    int total = 0;
    bool todas = tem_todas_cartas(baralho);
    contar_sets_linhas(baralho, &total);
    contar_sets_colunas(baralho, &total);
    contar_sets_diagonal_principal(baralho, &total);
    contar_sets_diagonal_secundaria(baralho, &total);
    contar_sets_mesmo_indice(baralho, &total);
    contar_sets_indices_diferentes(baralho, &total);
    if (todas) contar_sets_resto(baralho, &total);
    return total;
}

void adicionar(Lista* lista, int data) {
    Node* novo = (Node*) malloc(sizeof(Node));
    novo->data = data;
    novo->next = NULL;
    if (lista->head == NULL) {
        lista->head = lista->tail = novo;
    } else {
        lista->tail->next = novo;
        lista->tail = novo;
    }
}

void imprimir_lista(Lista* lista) {
    Node* atual = lista->head;
    while (atual != NULL) {
        printf("%d\n", atual->data);
        atual = atual->next;
    }
}

int main() {
    int n;
    Lista* resultados = (Lista*) malloc(sizeof(Lista));
    resultados->head = resultados->tail = NULL;

    while (true) {
        scanf("%d", &n);
        if (n == 0) break;
        int baralho[TAM][TAM] = {{0}};
        char numero[10], figura[15];
        for (int i = 0; i < n; i++) {
            scanf("%s %s", numero, figura);
            int ni = mapear_numero(numero);
            int fi = mapear_figura(figura);
            baralho[fi][ni]++;
        }
        int res = total_sets(baralho);
        adicionar(resultados, res);
    }
    imprimir_lista(resultados);
    free(resultados);
    return 0;
}
