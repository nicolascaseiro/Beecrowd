#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXN 1000
#define MAXCUBOS 10000
#define STRLEN 7

typedef struct {
    char cubos[MAXCUBOS][STRLEN];
    int size;
} Set;

int set_contains(Set *set, char *s){
    int i;
    for(i=0; i<set->size; i++){
        if(strcmp(set->cubos[i], s)==0) return 1;
    }
    return 0;
}

void set_insert(Set *set, char *s){
    if(set_contains(set, s)) return;
    if(set->size < MAXCUBOS){
        strcpy(set->cubos[set->size], s);
        set->size++;
    }
}

typedef struct {
    char data[MAXCUBOS][STRLEN];
    int front, rear;
} Queue;

void q_init(Queue *q){
    q->front = 0; q->rear = 0;
}

int q_empty(Queue *q){
    return q->front == q->rear;
}

int q_push(Queue *q, char *s){
    int next = (q->rear + 1) % MAXCUBOS;
    if(next == q->front) return 0;
    strcpy(q->data[q->rear], s);
    q->rear = next;
    return 1;
}

int q_pop(Queue *q, char *out){
    if(q_empty(q)) return 0;
    strcpy(out, q->data[q->front]);
    q->front = (q->front +1) % MAXCUBOS;
    return 1;
}

typedef struct {
    char cubos[MAXCUBOS][STRLEN];
    int size;
} VisitedSet;

int vis_contains(VisitedSet *vis, char *s){
    int i;
    for(i=0; i<vis->size; i++){
        if(strcmp(vis->cubos[i], s)==0) return 1;
    }
    return 0;
}

void vis_insert(VisitedSet *vis, char *s){
    if(vis_contains(vis, s)) return;
    if(vis->size < MAXCUBOS){
        strcpy(vis->cubos[vis->size], s);
        vis->size++;
    }
}

void rota(Set *cubos, char *s){
    Queue fila;
    VisitedSet vis;
    char cur[STRLEN], a[STRLEN];
    q_init(&fila);
    vis.size = 0;

    q_push(&fila, s);

    while(!q_empty(&fila)){
        q_pop(&fila, cur);
        if(set_contains(cubos, cur)) return;

        strcpy(a, cur);
        for(int i=0; i<3; i++){
            char c = a[4];
            a[4] = a[3];
            a[3] = a[2];
            a[2] = a[1];
            a[1] = c;
            if(!vis_contains(&vis, a)){
                vis_insert(&vis, a);
                q_push(&fila, a);
            }
        }

        strcpy(a, cur);
        for(int i=0; i<3; i++){
            char c = a[3];
            a[3] = a[5];
            a[5] = a[1];
            a[1] = a[0];
            a[0] = c;
            if(!vis_contains(&vis, a)){
                vis_insert(&vis, a);
                q_push(&fila, a);
            }
        }
    }
    set_insert(cubos, s);
}

int main(){
    
    int n;
    char s[STRLEN];
    while(scanf("%d", &n) == 1 && n){
        Set cubos;
        cubos.size = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<6; j++){
                scanf(" %c", &s[j]);
            }
            s[6] = '\0';
            if(cubos.size > 0){
                rota(&cubos, s);
            } else {
                set_insert(&cubos, s);
            }
        }
        printf("%d\n", cubos.size);
    }
    return 0;
}
