#include <stdio.h>

int main() {
    
    int T;
    scanf("%d", &T);
    int mat[10][10];
    while (T--) {
        scanf("%d", &mat[0][0]);
        scanf("%d %d", &mat[2][0], &mat[2][2]);
        scanf("%d %d %d", &mat[4][0], &mat[4][2], &mat[4][4]);
        scanf("%d %d %d %d", &mat[6][0], &mat[6][2], &mat[6][4], &mat[6][6]);
        scanf("%d %d %d %d %d", &mat[8][0], &mat[8][2], &mat[8][4], &mat[8][6], &mat[8][8]);

        for (int i = 1; i < 8; i += 2) {
            mat[8][i] = (mat[6][i - 1] - mat[8][i - 1] - mat[8][i + 1]) / 2;
        }

        for (int i = 7; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                mat[i][j] = mat[i + 1][j] + mat[i + 1][j + 1];
            }
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < i; j++) {
                printf("%d ", mat[i][j]);
            }
            printf("%d\n", mat[i][i]);
        }
    }
    return 0;
}
