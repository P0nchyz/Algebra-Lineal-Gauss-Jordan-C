#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "matrices.h"

Matriz *crearMatriz(unsigned int ancho, unsigned int alto)
{
	Matriz *rMatriz;
	rMatriz = malloc(sizeof(Matriz));
	rMatriz->ancho = ancho;
	rMatriz->alto = alto;
	rMatriz->e = malloc(alto * sizeof(float *));
	for (int i = 0; i < alto; i++)
	{
		rMatriz->e[i] = malloc(ancho * sizeof(float));
	}
	return rMatriz;
}

void eliminarMatriz(Matriz *A)
{
	for (int i = 0; i < A->alto; i++)
	{
		free(A->e[i]);
		A->e[i] = NULL;
	}
	free(A->e);
	A->e = NULL;
	free(A);
	A = NULL;
	return;
}

void imprimirMatriz(Matriz *A)
{
	printf("\n\t\b|-");
	for (int i = 0; i < A->ancho; i++)
		printf("\t");
	printf("-|\n");
	for (int i = 0; i < A->alto; i++)
	{
		printf("\t\b|");
		for (int j = 0; j < A->ancho; j++)
		{
			if (A->e[i][j] == -0.0)
				A->e[i][j] = 0.0;
			float distanceToInt = fabs((int)A->e[i][j] - A->e[i][j]);
			printf("%.*f\t", (distanceToInt < 0.0001) ? 0 : 2, A->e[i][j]);
		}
		printf(" |\n");
	}
	printf("\t\b|-");
	for (int i = 0; i < A->ancho; i++)
		printf("\t");
	printf("-|\n");
}

void llenarMatriz(Matriz *A)
{
	int tamanoBuffer = A->ancho * 16;
	char *buffer = malloc(tamanoBuffer * sizeof(char));
	for (int i = 0; i < A->alto; i++)
	{
		for (int j = 0; j < tamanoBuffer; j++)
			buffer[j] = 0;
		fgets(buffer, tamanoBuffer, stdin);
		char *sigNumero = buffer;
		for (int j = 0; j < A->ancho; j++)
			A->e[i][j] = strtof(sigNumero, &sigNumero);
	}
}

Matriz *crearMatrizIdentidad(unsigned int tamano)
{
	Matriz *matrizID = crearMatriz(tamano, tamano);
	for (int i = 0; i < tamano; i++)
	{
		for (int j = 0; j < tamano; j++)
		{
			matrizID->e[i][j] = (i == j) ? 1 : 0;
		}
	}
	return matrizID;
}

Matriz *copiarMatriz(Matriz *A)
{
	Matriz *copiaMatriz = crearMatriz(A->ancho, A->alto);
	for (int i = 0; i < A->alto; i++)
	{
		for (int j = 0; j < A->ancho; j++)
		{
			copiaMatriz->e[i][j] = A->e[i][j];
		}
	}
	return copiaMatriz;
}

bool esMatrizIgual(Matriz *A, Matriz *B)
{
	if ((A->alto != B->alto) || (A->ancho != B->ancho))
		return false;
	for (int i = 0; i < A->alto; i++)
	{
		for (int j = 0; j < A->ancho; j++)
		{
			if (A->e[i][j] != B->e[i][j])
				return false;
		}
	}
	return true;
}