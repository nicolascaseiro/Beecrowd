#include <stdio.h>
#include <string.h>

int main() {
    
    int casos;
    scanf("%d", &casos);

    for (int i = 0; i < casos; i++) {
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        double resultado = (double)(d - b) / (c - a);
        char texto[50];
        snprintf(texto, sizeof(texto), "%.3lf", resultado);
        texto[strlen(texto) - 1] = '\0';
        for (int j = 0; texto[j] != '\0'; j++) {
            if (texto[j] == '.') texto[j] = ',';
        }
        printf("%s\n", texto);
    }
    return 0;
}
