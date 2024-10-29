#include <stdio.h>
#include <stdlib.h>

#include "lib/aumMatrices.h"
#include "gaussJordan.h"
#include "lib/opElementales.h"
#include "lib/matrices.h"


int main(int argc, char const *argv[])
{
	int alto;
	printf("Alto: ");
	scanf("%d", &alto);
	printf("Ancho: ");
	int Ancho;
	scanf("%d", &Ancho);
	getc(stdin);

	AumMatriz *A = crearAumMatriz(Ancho, alto, Ancho);
	llenarAumMatriz(A);
	A->rMatriz = crearMatrizIdentidad(alto);
	imprimirAumMatriz(A);

	gaussJordan(A);

	imprimirAumMatriz(A);
}