#ifndef OPELEMENTALES_H
#define OPELEMENTALES_H

#include "aumMatrices.h"
#include "matrices.h"

void cambiarFilas(AumMatriz *A, int deFila, int aFila);

void multFila(AumMatriz *A, int fila, float factor);

// aFila + (factor * sumFila) -> aFila
void sumaFilas(AumMatriz *A, int aFila, float factor, int sumFila);

void cambiarColumnas(Matriz *A, int deCol, int aCol);

void multColumnas(Matriz *A, int col, float factor);

// aCol + (factor * sumCol) -> aCol
void sumaColumnas(Matriz *A, int aCol, float factor, int sumCol);

#endif