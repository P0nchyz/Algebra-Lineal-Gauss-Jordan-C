#ifndef AUMMATRICES_H
#define AUMMATRICES_H


#include "matrices.h"

typedef struct AumMatriz
{
	// El ancho de ambas matrices
	unsigned int ancho;
	unsigned int alto;
	Matriz *lMatriz;
	Matriz *rMatriz;
} AumMatriz;

AumMatriz *crearAumMatriz(unsigned int l_ancho, unsigned int alto, unsigned int r_ancho);

void eliminarAumMatriz(AumMatriz *A);

void imprimirAumMatriz(AumMatriz *A);

void llenarAumMatriz(AumMatriz *A);

AumMatriz *copiarAumMatriz(AumMatriz *A);

#endif