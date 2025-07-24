#include <stdio.h>
#include <math.h>

int main ()
{

	unsigned numeroA, numeroB;
	unsigned short casos;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf("%u %u", &numeroA, &numeroB);

		printf("%.f\n", (floor(log10(pow(numeroA, numeroB)))) + 1);

	}
	return 0;
}
