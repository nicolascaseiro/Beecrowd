#include <stdio.h>
#include <string.h>

int main ()
{

	char pergunta[10];

	while (scanf(" %[^\n]", pergunta) != EOF)
	{

		if (strcmp(pergunta, "esquerda") == 0)
			printf("ingles\n");
		else if (strcmp(pergunta, "direita") == 0)
			printf("frances\n");
		else if (strcmp(pergunta, "nenhuma") == 0)
			printf("portugues\n");
		else if (strcmp(pergunta, "as duas") == 0)
			printf("caiu\n");

	}
	return 0;

}
