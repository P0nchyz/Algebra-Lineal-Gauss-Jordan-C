/*El header para la determinante paso a paso.*/

#ifndef SUBMATRICES_H
#define SUBMATRICES_H

#include <stdbool.h>
#include "matrices.h"


typedef struct SubMatriz {
    unsigned int n;   
    float **e;        
} SubMatriz;


/// @brief Asigna memoria para una Matriz y devuelve un apuntador a la Matriz
/// @param ancho Numero de Columnas
/// @param alto Numero de Filas
/// @return Apuntador a la Matriz Creada
Matriz *crearMatriz(unsigned int ancho, unsigned int alto);

/// @brief Libera el espacio que ocupaba una Matriz y sus elementos
/// @param A Apuntador a la Matriz a eliminar (Es asignado NULL una vez eliminada)
void eliminarMatriz(Matriz *A);

/// @brief Imprime Matriz con formato a la salida estandar
///
/// Si el numero es lo suficientemente cercano a un entero lo mostrara sin puntos decimales.
/// @param A Apuntador a la Matriz a imprimir
void imprimirMatriz(Matriz *A);

/// @brief Llena los datos de una Matriz con la entrada estandar
///
/// Al ingresar los datos cada elemento debe estar separado por un espacio.
///
/// Y cada columna debe estar separada por un enter.
///
/// Si faltan datos se pondra su valor en cero, si sobran no se incluiran
/// @param A Apuntador a la Matriz a llenar
void llenarMatriz(Matriz *A);

/// @brief Crea una matriz identidad del tamaño especificado
/// @param tamano Tamaño de la matriz (Cuadrada)
/// @return Apuntador a la Matriz identidad
Matriz *crearMatrizIdentidad(unsigned int tamano);

/// @brief Crea una nueva Matriz y copia todos los datos de otra Matriz
/// @param A Matriz a copiar, no sera modificada
/// @return Apuntador a nueva Matriz con los datos y tamaño de la que se copio
Matriz *copiarMatriz(Matriz *A);

bool esMatrizIgual(Matriz *A, Matriz *B);

#endif