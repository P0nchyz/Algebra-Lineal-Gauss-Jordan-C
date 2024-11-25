#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "aumMatrices.h"

AumMatriz *crearAumMatriz(unsigned int l_ancho, unsigned int alto, unsigned int r_ancho)
{
	AumMatriz *rAMatriz = malloc(sizeof(AumMatriz));
	rAMatriz->ancho = l_ancho + r_ancho;
	rAMatriz->alto = alto;
	rAMatriz->lMatriz = crearMatriz(l_ancho, alto);
	rAMatriz->rMatriz = crearMatriz(r_ancho, alto);
	return rAMatriz;
}

void eliminarAumMatriz(AumMatriz *A)
{
	eliminarMatriz(A->lMatriz);
	eliminarMatriz(A->rMatriz);
	free(A);
	A = NULL;
	return;
}

void imprimirAumMatriz(AumMatriz *A)
{
	printf("\n\t\b|-");
	for (int i = 0; i < A->lMatriz->ancho; i++)
		printf("\t");
	printf("||\t");
	for (int i = A->lMatriz->ancho; i < A->ancho; i++)
		printf("\t");
	printf("-|\n");
	for (int i = 0; i < A->alto; i++)
	{
		printf("\t\b|");
		for (int j = 0; j < A->lMatriz->ancho; j++)
		{
			float elemento = A->lMatriz->e[i][j];
			if (elemento == -0.0)
				elemento = 0.0;
			float distanceToInt = fabs((int)elemento - elemento);
			printf("%.*f\t", (distanceToInt < 0.0001) ? 10 : 10, elemento);
		}
		printf("||\t");
		for (int j = 0; j < A->rMatriz->ancho; j++)
		{
			float elemento = A->rMatriz->e[i][j];
			if (elemento == -0.0)
				elemento = 0.0;
			float distanceToInt = fabs((int)elemento - elemento);
			printf("%.*f\t", (distanceToInt < 0.0001) ? 0 : 2, elemento);
		}
		printf(" |\n");
	}
	printf("\t\b|-");
	for (int i = 0; i < A->lMatriz->ancho; i++)
		printf("\t");
	printf("||\t");
	for (int i = A->lMatriz->ancho; i < A->ancho; i++)
		printf("\t");
	printf("-|\n");
}

void llenarAumMatriz(AumMatriz *A)
{
	int tamanoBuffer = A->ancho * 16;
	char *buffer = malloc(tamanoBuffer * sizeof(char));
	for (int i = 0; i < A->alto; i++)
	{
		for (int j = 0; j < tamanoBuffer; j++)
			buffer[j] = 0;
		fgets(buffer, tamanoBuffer, stdin);
		char *sigNum = buffer;
		for (int j = 0; j < A->ancho; j++)
		{
			if (j < A->lMatriz->ancho)
				A->lMatriz->e[i][j] = strtof(sigNum, &sigNum);
			else
			{
				int offset = j - A->lMatriz->ancho;
				A->rMatriz->e[i][offset] = strtof(sigNum, &sigNum);
			}
		}
	}
}

AumMatriz *copiarAumMatriz(AumMatriz *A)
{
	AumMatriz *cpAMatriz = crearAumMatriz(A->lMatriz->ancho, A->alto, A->rMatriz->ancho);
	cpAMatriz->lMatriz = copiarMatriz(A->lMatriz);
	cpAMatriz->rMatriz = copiarMatriz(A->rMatriz);
	return cpAMatriz;
}

bool esAumMatrizIgual(AumMatriz *A, AumMatriz *B)
{
	if ((A->alto != B->alto) || (A->ancho != B->ancho))
		return false;
	if ((!esMatrizIgual(A->lMatriz, B->lMatriz)) || !esMatrizIgual(A->rMatriz, B->rMatriz))
		return false;
	return true;
}