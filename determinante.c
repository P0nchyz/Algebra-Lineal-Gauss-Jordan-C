#include <math.h>
#include "lib/matrices.h"


float determinante(Matriz *A)
{
	// Verificamos si la matriz es Cuadrada
	if (A -> alto != A -> ancho) return 0;
	// Caso base 1x1
	if (A -> alto == 1) return A->e[0][0];
	// Caso base 2x2
	if (A -> alto == 2)
	{
		return (A->e[0][0] * A->e[1][1]) - (A->e[0][1] * A->e[1][0]);
	}
	
	float resultado = 0;
	int n = A->alto;
	
	// Submatriz de tamano (n -1) * (n - 1) 

	for (int j = 0; j < n; j++)
	{
		Matriz *sub = crearMatriz(n - 1, n - 1);
		//Submatriz excluyendo primera fila y la columna j
		int sub_i = 0;
		for (int i = 1; i < n; i++)
		{
			int sub_j = 0;
			for (int k = 0; k < n; k++) {
				if (k == j) continue;
				sub->e[sub_i][sub_j] = A->e[i][k];
				sub_j++;
			}
			sub_i++;
		}
		//Usamos la recursividad para calcular el det de la submatriz, ademas de 
		//Aplicar la operacion (-1)^(columna) para alternar los signos en el desarrollo (+ - + - + -.. etc)
		resultado += pow(-1, j) * A->e[0][j] * determinante(sub);
		eliminarMatriz(sub);
	}


	return resultado;
}
