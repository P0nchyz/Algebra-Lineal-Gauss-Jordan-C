
#include "lib/aumMatrices.h"
#include "gaussJordan.h"
#include "lib/opElementales.h"
#include <math.h>
#include <stdlib.h>

int validar(AumMatriz *A, Pivote *piv);

void hacer_unos(AumMatriz *A, Pivote *piv);

void ceros_abajo(AumMatriz *A, Pivote *piv);

void ceros_arriba(AumMatriz *A, Pivote *piv);

int gaussJordan(AumMatriz *A)
{
	A->rMatriz = crearMatrizIdentidad(A->alto);
	for (Pivote piv = {0, 0}; (piv.i < A->alto) && (piv.j < A->lMatriz->ancho); piv.i++, piv.j++)
	{
		if (validar(A, &piv) == 1)
			return 1;
		hacer_unos(A, &piv);
		ceros_abajo(A, &piv);
		ceros_arriba(A, &piv);
	}
	return 0;
}

int gaussJordanNoI(AumMatriz *A)
{
	for (Pivote piv = {0, 0}; (piv.i < A->alto) && (piv.j < A->lMatriz->ancho); piv.i++, piv.j++)
	{
		if (validar(A, &piv) == 1)
			return 1;
		hacer_unos(A, &piv);
		ceros_abajo(A, &piv);
		ceros_arriba(A, &piv);
	}
	return 0;
}

int validar(AumMatriz *A, Pivote *piv)
{
	if (fabsf(A->lMatriz->e[piv->i][piv->j]) >= 0.01)
		return 0;

	for (int l = piv->j; l < A->lMatriz->ancho; l++)
	{
		for (int k = piv->i; k < A->alto; k++)
		{
			if (fabsf(A->lMatriz->e[k][l]) >= 0.01)
			{
				cambiarFilas(A, piv->i, k);
				return 0;
			}
		}
		piv->j++;
	}
	return 1;
}

void hacer_unos(AumMatriz *A, Pivote *piv)
{
	float factor = A->lMatriz->e[piv->i][piv->j];
	multFila(A, piv->i, 1/factor);
	if (fabsf(1 - A->lMatriz->e[piv->i][piv->j]) < 0.01)
		A->lMatriz->e[piv->i][piv->j] = 1;
	return;
}

void ceros_abajo(AumMatriz *A, Pivote *piv)
{
	for (int k = piv->i + 1; k < A->alto; k++)
	{
		float factor = A->lMatriz->e[k][piv->j];
		sumaFilas(A, k, -factor, piv->i);
		if (fabsf(A->lMatriz->e[k][piv->j]) < 0.01)
			A->lMatriz->e[k][piv->j] = 0;
	}
	return;
}

void ceros_arriba(AumMatriz *A, Pivote *piv)
{
	for (int k = 0; k < piv->i; k++)
	{
		float factor = A->lMatriz->e[k][piv->j];
		sumaFilas(A, k, -factor, piv->i);
		if (fabsf(A->lMatriz->e[k][piv->j]) < 0.01)
			A->lMatriz->e[k][piv->j] = 0;
	}
	return;
}
