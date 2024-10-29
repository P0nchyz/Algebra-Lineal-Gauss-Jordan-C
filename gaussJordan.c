
#include "lib/aumMatrices.h"
#include "gaussJordan.h"
#include "lib/opElementales.h"

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

int validar(AumMatriz *A, Pivote *piv)
{
	if (0 != A->lMatriz->e[piv->i][piv->j])
		return 0;

	for (int l = piv->j; l < A->lMatriz->ancho; l++)
	{
		for (int k = piv->i; k < A->alto; k++)
		{
			if (0 != A->lMatriz->e[k][l])
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