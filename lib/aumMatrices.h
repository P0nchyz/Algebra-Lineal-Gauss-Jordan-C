#ifndef AUMMATRICES_H
#define AUMMATRICES_H


#include "matrices.h"

/// @brief Estructura que contiene apuntadores a dos matrices, asi como el tamaño de la matriz formada al aumentarlas
///
/// El ancho debe ser la suma de los anchos de ambas matrices
///
/// El alto debe ser el mismo en ambas matrices
typedef struct AumMatriz
{
	// El ancho de ambas matrices
	unsigned int ancho;
	unsigned int alto;
	// Apuntador a la matriz izquierda
	Matriz *lMatriz;
	// Apuntador a la matriz derecha
	Matriz *rMatriz;
} AumMatriz;

/// @brief Asigna memoria a una matriz aumentada, y a sus dos matrices internas
/// @param l_ancho Ancho de la matriz izquierda
/// @param alto Alto de ambas matrices
/// @param r_ancho Ancho de la matriz derecha
/// @return Apuntador a la matriz aumentada
AumMatriz *crearAumMatriz(unsigned int l_ancho, unsigned int alto, unsigned int r_ancho);

/// @brief Libera la memoria de la matriz aumentada y ambas matrices internas
/// @param A Apuntador a la matriz aumentada a eliminar (Asignado NULL una vez eliminadas)
void eliminarAumMatriz(AumMatriz *A);

/// @brief Imprimir una matriz aumentada con formato a la salida estandar
///
/// Imprime ambas matrices lado a lado separadas por un divisor
/// @param A Apuntador a la matriz aumentada a imprimir
void imprimirAumMatriz(AumMatriz *A);

/// @brief Llena los datos de una matriz aumentada usando la entrada estandar
///
/// Se llenan los datos de la fila de la matriz izquierda, despues los de la matriz derecha
///
/// y despues de un enter los de la siguiente fila
/// @param A 
void llenarAumMatriz(AumMatriz *A);

/// @brief Copia los datos de una matriz aumentada y ambas de sus submatrices a una nueva matriz aumentada
/// @param A Apuntador a la matriz aumentada a copiar (No se modificara)
/// @return Apuntador a una nueva matriz aumentada con todos los datos de A
AumMatriz *copiarAumMatriz(AumMatriz *A);

#endif