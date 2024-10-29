#include <stdlib.h>
#include "lib/matrices.h"
#include "lib/aumMatrices.h"
#include "gaussJordan.h"

Matriz *inversa(Matriz *A)
{
	if (A->ancho != A->alto)
		return NULL;
	AumMatriz *matrizAumentada = crearAumMatriz(A->ancho, A->alto, A->ancho);
	matrizAumentada->lMatriz = copiarMatriz(A);
	matrizAumentada->rMatriz = crearMatrizIdentidad(A->ancho);
	gaussJordan(matrizAumentada);
	Matriz *id = crearMatrizIdentidad(A->alto);
	if (!esMatrizIgual(matrizAumentada->lMatriz, id))
	{
		return NULL;
	}
	eliminarMatriz(id);
	Matriz *retMatriz = copiarMatriz(matrizAumentada->rMatriz);
	eliminarAumMatriz(matrizAumentada);
	return retMatriz;
}