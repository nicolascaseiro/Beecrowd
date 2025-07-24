#include <stdio.h>
#include <string.h>

#define MAX 110000

int eh_vogal(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int eh_letra(char c) {
    return c >= 'a' && c <= 'z';
}

int main() {
    char chave[50];
    int n;
    char mensagem[MAX];

    scanf("%s", chave);
    scanf("%d", &n);
    getchar();

    int tam_chave = strlen(chave);

    for (int i = 0; i < n; i++) {
        fgets(mensagem, MAX, stdin);
        mensagem[strcspn(mensagem, "\n")] = 0;

        char resultado[MAX];
        int pos = 0;
        int indice_chave = 0;

        int inicio_palavra = 1;
        int criptografar = 0;

        for (int j = 0; mensagem[j] != '\0'; j++) {
            char c = mensagem[j];

            if (c == ' ') {
                resultado[pos++] = ' ';
                inicio_palavra = 1;
                criptografar = 0;
            } else {
                if (inicio_palavra) {
                    criptografar = !eh_vogal(c);
                    inicio_palavra = 0;
                }

                if (criptografar) {
                    int deslocamento = chave[indice_chave % tam_chave] - 'a';
                    char novo = ((c - 'a' + deslocamento) % 26) + 'a';
                    resultado[pos++] = novo;
                    indice_chave++;
                } else {
                    resultado[pos++] = c;
                }
            }
        }

        resultado[pos] = '\0';
        printf("%s\n", resultado);
    }

    return 0;
}
