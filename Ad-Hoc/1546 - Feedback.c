#include <stdio.h>

int main() {

    int ordem;
    scanf("%d", &ordem);
    for (int i = 0; i < ordem; i++) {
        int subordem;
        scanf("%d", &subordem);
        for (int j = 0; j < subordem; j++) {
            int problema;
            scanf("%d", &problema);
            if (problema == 1) printf("Rolien\n");
            else if (problema == 2) printf("Naej\n");
            else if (problema == 3) printf("Elehcim\n");
            else if (problema == 4) printf("Odranoel\n");
        }
    }
    return 0;
}
