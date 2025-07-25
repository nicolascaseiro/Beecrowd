#include <stdio.h>

int main() {
    int ent[7];
    for (int i = 1; i <= 6; i++) {
        scanf("%d", &ent[i]);
    }
    int heax = ent[1] + ent[2] + ent[3] + ent[6];
    int ow = ent[4] + ent[5];
    if (heax >= ow) {
        printf("Middle-earth is safe.\n");
    } else {
        printf("Sauron has returned.\n");
    }
    return 0;
}
