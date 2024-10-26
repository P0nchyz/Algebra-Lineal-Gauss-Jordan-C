#ifndef OPELEMENTALES_H
#define OPELEMENTALES_H

#include "aumMatrices.h"
#include "matrices.h"

/// @brief Intercambia dos filas en ambas matrices de una matriz aumentada
/// @param A Apuntador a la matriz aumentada en la que se realizara la operación
/// @param deFila Posición de fila que se intercambiara
/// @param aFila Posición de fila que se intercambiara
void cambiarFilas(AumMatriz *A, int deFila, int aFila);

/// @brief Multiplica toda la fila de una matriz aumentada por un escalar
/// @param A Apuntador a la matriz aumentada
/// @param fila Posición de la fila que se multiplicara
/// @param factor Escalar
void multFila(AumMatriz *A, int fila, float factor);

/// @brief Suma una fila de origen mas otra fila que sera multiplicada por un factor, y se coloca el resultado en la fila de orige
/// @param A Apuntador a la matriz aumentada
/// @param aFila Fila de origen, en la cual quedara el resultado final
/// @param factor Escalar
/// @param sumFila Fila que se multiplicara por el factor y se sumara a la fila de origen (No sera afectada en la matriz original)
void sumaFilas(AumMatriz *A, int aFila, float factor, int sumFila);

/// @brief Intercambia dos columnas en una Matriz
/// @param A Apuntador a Matriz en la que se realizara la operación
/// @param deCol Posición de columna a intercambiar
/// @param aCol Posición de columna a intercambiar
void cambiarColumnas(Matriz *A, int deCol, int aCol);

/// @brief Multiplica una columna por un numero escalar
/// @param A Apuntador a matriz
/// @param col Posición de columan que se multiplicara
/// @param factor Escalar
void multColumnas(Matriz *A, int col, float factor);

// aCol + (factor * sumCol) -> aCol
void sumaColumnas(Matriz *A, int aCol, float factor, int sumCol);

#endif