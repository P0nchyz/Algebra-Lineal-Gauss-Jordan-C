#include <stdio.h>
#include <stdlib.h>

#include "lib/aumMatrices.h"
#include "gaussJordan.h"
#include "lib/opElementales.h"
#include "lib/matrices.h"
#include "lib/subMatriz.h"

#include "equipos.h"

void callDeterminante();
void callPasoAPaso();
void callInversa();
void callSEL();
void calldeterminantePaP();


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
	Matriz *matrizInversa = inversa(A);
	if (NULL == matrizInversa)
	{
		printf("Matriz no Invertible.\n");
		return;
	}
	printf("Matriz Inversa:\n");
	imprimirMatriz(matrizInversa);	
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

/*Se agrego la funcion calldeterminantesPaP aunque 
la verdad no estoy muy seguro si si va asi*/
void calldeterminantePaP()
{
    int alto, ancho;

    // Solicitar las dimensiones de la matriz
    printf("Alto: ");
    scanf("%d", &alto);
    printf("Ancho: ");
    scanf("%d", &ancho);
    getc(stdin); // Consumir el salto de línea sobrante

    // Verificar si la matriz es cuadrada
    if (alto != ancho)
    {
        printf("Error: La matriz debe ser cuadrada para calcular el determinante.\n");
        return;
    }

    // Crear la matriz
    SubMatriz *A = crearSubMatriz(ancho, alto, ancho);
    if (!A)
    {
        printf("Error al crear la matriz.\n");
        return;
    }

    // Llenar la matriz con datos ingresados por el usuario
    llenarAumMatriz(A);

    // Mostrar la matriz ingresada (opcional, para confirmación)
    printf("\nMatriz ingresada:\n");
    imprimirAumMatriz(A);

    // Calcular y mostrar el determinante paso a paso
    printf("\nCalculando la determinante paso a paso\n");
    float resultado = determinantePaP(A); 
    printf("\nLa determinante de la matriz es: %.2f\n", resultado);

    // Liberar memoria
    eliminarAumMatriz(A);
}
