#include <stdio.h>

int teste(int H, int Z, int L);

int main() {
    
    int H, Z, L;
    scanf("%d %d %d\n", &H, &Z, &L);
    printf(teste(H, Z, L));
    
    return 0;
}

int teste(int H, int Z, int L){
    
    if(H < Z && H > L){
        printf("huguinho\n");
    }
    if(Z < H && Z > L){
        printf("zezinho\n");
    }
    if(L < H && L > Z){
        printf("luisinho\n");
    }
    if(H > Z && H < L){
        printf("huguinho\n");
    }
    if(Z > H && Z < L){
        printf("zezinho\n");
    }
    if(L > H && L < Z){
        printf("luisinho\n");
    }
    
    return 0;
}
