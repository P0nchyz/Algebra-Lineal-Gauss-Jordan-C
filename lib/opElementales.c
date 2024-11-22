#include <stdlib.h>
#include "opElementales.h"

void cambiarFilas(AumMatriz *A, int deFila, int aFila)
{
	for (int j = 0; j < A->ancho; j++)
	{
		if (j < A->lMatriz->ancho)
		{
			float temp = A->lMatriz->e[deFila][j];
			A->lMatriz->e[deFila][j] = A->lMatriz->e[aFila][j];
			A->lMatriz->e[aFila][j] = temp;
		}
		else
		{
			int offset = j - A->lMatriz->ancho;
			float temp = A->rMatriz->e[deFila][offset];
			A->rMatriz->e[deFila][offset] = A->rMatriz->e[aFila][offset];
			A->rMatriz->e[aFila][offset] = temp;
		}
	}
	return;
}

void multFila(AumMatriz *A, int fila, float factor)
{
	for (int j = 0; j < A->ancho; j++)
	{
		if (j < A->lMatriz->ancho)
			A->lMatriz->e[fila][j] *= factor;
		else
		{
			int offset = j - A->lMatriz->ancho;
			A->rMatriz->e[fila][offset] *= factor;
		}
	}
	return;
}

void sumaFilas(AumMatriz *A, int aFila, float factor, int sumFila)
{
	float *aux = malloc(A->ancho * sizeof(float));
	for (int j = 0; j < A->ancho; j++)
	{
		if (j < A->lMatriz->ancho)
			aux[j] = A->lMatriz->e[sumFila][j];
		else
		{
			int offset = j - A->lMatriz->ancho;
			aux[j] = A->rMatriz->e[sumFila][offset];
		}
	}

	for (int j = 0; j < A->ancho; j++)
	{
		if (j < A->lMatriz->ancho)
		{
			A->lMatriz->e[aFila][j] += factor * aux[j];
		}
		else
		{
			int offset = j - A->lMatriz->ancho;
			A->rMatriz->e[aFila][offset] += factor * aux[j];
		}
	}
	return;
}

void cambiarColumnas(Matriz *A, int deCol, int aCol)
{
	for (int i = 0; i < A->alto; i++)
	{
		float temp = A->e[i][deCol];
		A->e[i][deCol] = A->e[i][aCol];
		A->e[i][aCol] = temp;
	}
	return;
}

void multColumnas(Matriz *A, int col, float factor)
{
	for (int i = 0; i < A->alto; i++)
	{
		A->e[i][col] *= factor;
	}
	return;
}

void sumaColumnas(Matriz *A, int aCol, float factor, int sumCol)
{
	// TODO
	return;
}
