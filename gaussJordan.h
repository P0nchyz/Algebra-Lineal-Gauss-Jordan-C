#include "lib/aumMatrices.h"

typedef struct Pivote
{
	int i;
	int j;
} Pivote;


/// @brief Realiza el algoritmo de Gauss Jordan en una matriz cualquiera
/// @param A Matriz aumentada, en lMatriz debe estar la matriz deseada
/// @return 0 si se completo, 1 si no
int gaussJordan(AumMatriz *A);

int gaussJordanNoI(AumMatriz *A);