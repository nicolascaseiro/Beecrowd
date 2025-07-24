#include <stdio.h>

#define MAX 101
#define false 0
#define true 1

typedef struct figurinha{

	_Bool figCarimbada;
	_Bool figPossuida;

} figurinha;

figurinha album[MAX] = { false };

int main ()
{

	unsigned short i, tmp;
	unsigned short qtsFigurinhas;
	unsigned short qtsFigurinhasCompradas;
	unsigned short qtsFigurinhasCarimbadas;

	scanf("%hu %hu %hu", &qtsFigurinhas, &qtsFigurinhasCarimbadas, &qtsFigurinhasCompradas);

	for (i = 0; i < qtsFigurinhasCarimbadas; ++i)
	{

		scanf("%hu", &tmp);
		album[tmp].figCarimbada = true;

	}

	for (i = 0; i < qtsFigurinhasCompradas; ++i)
	{

		scanf("%hu", &tmp);
		album[tmp].figPossuida = true;

	}

	for (i = 1; i <= qtsFigurinhas; ++i)
		if (album[i].figPossuida && album[i].figCarimbada)
			qtsFigurinhasCarimbadas--;


	printf("%hu\n", qtsFigurinhasCarimbadas);
}
