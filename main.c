#include <stdio.h>
#include <stdlib.h>

#include "lib/aumMatrices.h"
#include "lib/opElementales.h"
#include "lib/matrices.h"

typedef struct Pivote
{
	int i;
	int j;
} Pivote;

void validar(AumMatriz *A, Pivote *piv);

void hacer_unos(AumMatriz *A, Pivote *piv);

void ceros_abajo(AumMatriz *A, Pivote *piv);

void ceros_arriba(AumMatriz *A, Pivote *piv);

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


	for (Pivote piv = {0, 0}; (piv.i < A->alto) && (piv.j < A->lMatriz->ancho); piv.i++, piv.j++)
	{
		validar(A, &piv);
		hacer_unos(A, &piv);
		ceros_abajo(A, &piv);
		ceros_arriba(A, &piv);
	}
	imprimirAumMatriz(A);
	return 0;
}

void validar(AumMatriz *A, Pivote *piv)
{
	if (0 != A->lMatriz->e[piv->i][piv->j])
		return;

	for (int l = piv->j; l < A->lMatriz->ancho; l++)
	{
		for (int k = piv->i; k < A->alto; k++)
		{
			if (0 != A->lMatriz->e[k][l])
			{
				cambiarFilas(A, piv->i, k);
				return;
			}
		}
		piv->j++;
	}
	imprimirAumMatriz(A);
	exit(1);
}

void hacer_unos(AumMatriz *A, Pivote *piv)
{
	float factor = A->lMatriz->e[piv->i][piv->j];
	multFila(A, piv->i, 1/factor);
	return;
}

void ceros_abajo(AumMatriz *A, Pivote *piv)
{
	for (int k = piv->i + 1; k < A->alto; k++)
	{
		float factor = A->lMatriz->e[k][piv->j];
		sumaFilas(A, k, -factor, piv->i);
	}
	return;
}

void ceros_arriba(AumMatriz *A, Pivote *piv)
{
	for (int k = 0; k < piv->i; k++)
	{
		float factor = A->lMatriz->e[k][piv->j];
		sumaFilas(A, k, -factor, piv->i);
	}
	return;
}