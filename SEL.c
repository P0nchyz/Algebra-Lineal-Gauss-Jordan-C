#include <stdio.h>
#include <stdlib.h>

#include "gaussJordan.h"

void imprimirSolucion(AumMatriz *A);

int SEL(AumMatriz *A) {
	imprimirAumMatriz(A);
	gaussJordanNoI(A);
	imprimirAumMatriz(A);
	// coeficientes de exactamente una columna
	if (A->rMatriz->ancho != 1) {
		printf("Error: Los coeficientes deben estar exactamente en una columna.\n");
		return -1; 
	}

	int filasNoNulas = 0;
	int columnasCoeficientes = A->lMatriz->ancho;
	int numeroVariables = columnasCoeficientes;  // Número de incógnitas

	for (int i = 0; i < A->alto; i++) {
		int filaEsCero = 1;
		for (int j = 0; j < columnasCoeficientes; j++) {
			if (A->lMatriz->e[i][j] != 0) {
				filaEsCero = 0;
				break;
			}
		}

		if (filaEsCero && A->rMatriz->e[i][0] != 0) {
			// Si hay una fila de ceros en lMatriz y el término independiente no es cero
			printf("Sistema sin solución\n");
			return 0;  // Sistema sin solución
			
		}

		if (!filaEsCero) filasNoNulas++;
	}

	if (filasNoNulas < numeroVariables) {
		// Si hay más incógnitas que filas no nulas
		printf("Sistema con soluciones infinitas");
		return 2;  // Sistema con soluciones infinitas
	}

	imprimirSolucion(A);
	return 1;  // Sistema con una única solución
}

void imprimirSolucion(AumMatriz *A) {
	printf("Solución única encontrada: (");

	for (int i = 0; i < A->alto; i++) {
		printf("%.2f", A->rMatriz->e[i][0]);
		if (i < A->alto - 1) {
			printf(", ");
		}
	}

	printf(")\n");
}
