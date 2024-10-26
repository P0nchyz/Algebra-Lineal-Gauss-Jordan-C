#ifndef MATRICES_H
#define MATRICES_H

typedef struct Matriz
{
	unsigned int ancho;
	unsigned int alto;
	float **e;
} Matriz;

Matriz *crearMatriz(unsigned int ancho, unsigned int alto);

void eliminarMatriz(Matriz *A);

void imprimirMatriz(Matriz *A);

void llenarMatriz(Matriz *A);

Matriz *crearMatrizIdentidad(unsigned int tamano);

Matriz *copiarMatriz(Matriz *A);

#endif