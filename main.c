#include <stdio.h>
#include <stdlib.h>

#include "lib/aumMatrices.h"
#include "gaussJordan.h"
#include "lib/opElementales.h"
#include "lib/matrices.h"

#include "equipos.h"

void callDeterminante();
void callPasoAPaso();
void callInversa();
void callSEL();


int main(int argc, char const *argv[])
{
	char operacion;
	if (argc < 2)
	{
		printf("Qué Desea Hacer?\n");
		printf("\t(d) Obtener determinante.\n");
		printf("\t(p) Gauss Jordan paso a paso.\n");
		printf("\t(i) Obtener la inversa.\n");
		printf("\t(s) Resolver Sistemas de ecuaciones.\n");
		scanf("%c", &operacion);
	}
	else
		operacion = argv[1][0];

	switch (operacion)
	{
	case 'd':
		callDeterminante();
		break;
	case 'p':
		callPasoAPaso();
		break;
	case 'i':
		callInversa();
		break;
	case 's':
		callSEL();
		break;
	default:
		break;
	}
}

void callDeterminante()
{
	int alto;
	printf("Alto: ");
	scanf("%d", &alto);
	int ancho;
	printf("Ancho: ");
	scanf("%d", &ancho);
	getc(stdin);
	Matriz *A = crearMatriz(alto, ancho);
	llenarMatriz(A);
	imprimirMatriz(A);
	float result = determinante(A);
	printf("%f", result);
}
void callPasoAPaso()
{
	int alto;
	printf("Alto: ");
	scanf("%d", &alto);
	int Ancho;
	printf("Ancho: ");
	scanf("%d", &Ancho);
	getc(stdin);

	AumMatriz *A = crearAumMatriz(Ancho, alto, Ancho);
	llenarAumMatriz(A);
	pasoAPaso(A);
}
void callInversa()
{
	int alto;
	printf("Alto: ");
	scanf("%d", &alto);
	int ancho;
	printf("Ancho: ");
	scanf("%d", &ancho);
	getc(stdin);
	Matriz *A = crearMatriz(alto, ancho);
	llenarMatriz(A);
	imprimirMatriz(A);
}
void callSEL()
{
	int alto;
	printf("Alto: ");
	scanf("%d", &alto);
	int ancho;
	printf("Ancho: ");
	scanf("%d", &ancho);
	getc(stdin);
	AumMatriz *A = crearAumMatriz(ancho, alto, 1);
	llenarAumMatriz(A);
	SEL(A);
}