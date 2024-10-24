/*
Gauss_Jordan.c
ALGEBRA LINEAL
Creado por el Grupo 2CM1
Fecha: 22 de Octubre de 2024
Profesor: Tlatoani de Jesus Reyes Bermejo

Compilación
	Windows:
		gcc -o Gauss_Jordan.exe Gauss_Jordan.c
	Linux:
		gcc -o Gauss_Jordan.out Gauss_Jordan.c
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ancho;
	int alto;
	float **e; // Arreglo bidimensional
} Matriz;

void llenarMatriz(Matriz *A);

void imprimirMatriz(Matriz *A);

void cambiar_renglones(Matriz *A, int i, int j);

void hacer_unos(Matriz *A, int i, int j);

void ceros_abajo(Matriz *A, int i);

void ceros_arriba(Matriz *A, int n);


/*
Hecho por:
	- Islas Martinez Ana Karen
	- Rodriguez Flores Angel Isaias
	- Martinez Gonzáles Emiliano Amilcar
	- Vergara Gamboa José Alfonso
*/
int main(int argc, char *argv[])
{
	// Inicializamos la matriz A
	Matriz A;
	printf("Alto: ");
	scanf("%d", &A.alto);
	printf("Ancho: ");
	scanf("%d", &A.ancho);
	getc(stdin);

	// Alocamos memoria para los elementos
	A.e = malloc(A.alto * sizeof(float *));
	for (int i = 0; i < A.alto; i++)
	{
		A.e[i] = malloc(A.ancho * sizeof(float));
	}
	// Recibimos los valores de los elementos de la entrada estandar
	llenarMatriz(&A);
	// Imprimimos la matriz obtenida
	imprimirMatriz(&A);

	// Avanzamos por columna
	for (int i = 0; i < A.ancho; i++)
	{
		cambiar_renglones(&A, i, i);
		hacer_unos(&A, i, i);
		ceros_abajo(&A, i);
		ceros_arriba(&A, i);
	}
	// Imprimimos la matriz escalonada
	imprimirMatriz(&A);
}

void llenarMatriz(Matriz *A)
{
	printf("Introduzca los elementos de cada fila separados por espacios.\n");
	int tamanoBuffer = A->ancho * 16;
	char *buffer = malloc(tamanoBuffer * sizeof(char));
	for (int i = 0; i < A->alto; i++)
	{
		for (int j = 0; j < tamanoBuffer; j++)
			buffer[j] = 0;
		fgets(buffer, tamanoBuffer, stdin);
		char *sigNumero = buffer;
		for (int j = 0; j < A->ancho; j++)
			A->e[i][j] = strtof(sigNumero, &sigNumero);
	}

}

void imprimirMatriz(Matriz *A)
{
	printf("\t\b┏");
	for (int i = 0; i < A->ancho; i++)
		printf("\t");
	printf(" ┓\n");
	for (int i = 0; i < A->alto; i++)
	{
		printf("\t\b┃");
		for (int j = 0; j < A->ancho; j++)
		{
			if (A->e[i][j] == -0.0)
				A->e[i][j] = 0.0;
			float distanceToInt = fabs((int)A->e[i][j] - A->e[i][j]);
			printf("%.*f\t", (distanceToInt < 0.009) ? 0 : 2, A->e[i][j]);
		}
		printf(" ┃\n");
	}
	printf("\t\b┗");
	for (int i = 0; i < A->ancho; i++)
		printf("\t");
	printf(" ┛\n");
}

/*
Hecho por SubEquipo 1
Conformado por:
	- Ceballos Mendoza Axel Ivan
	- Fernandez Torres Rodrigo
	- Reynoso Galindo Adriel Emilio
	- Rodríguez Flores Angel Isaías
	- Martinez Gonzáles Emiliano Amilcar
	- Segundo Cantero Jonathan Axel
	- Valencia Reséndiz Carlos Alfonso
*/
void cambiar_renglones(Matriz *A, int i, int j)
{
	if (i != j)
		return;
	if (A->e[i][j] != 0)
		return;
	for (int k = i; k < A->alto; k++)
	{
		if (A->e[k][j] != 0)
		{
			for (int l = 0; l < A->ancho; l++)
			{
				float aux = A->e[k][l];
				A->e[k][l] = A->e[i][l];
				A->e[i][l] = aux;
			}
			return;
		}
	}
	printf("No invertible.\n");
	imprimirMatriz(A);
	exit(1);
}

/*
Hecho por SubEquipo 2
Conformado por:
	- Islas Martinez Ana Karen
	...
	- Vergara Gamboa José Alfonso
*/
void hacer_unos(Matriz *A, int i, int j)
{
	if (i != j)
		return;
	float piv = A->e[i][j];
	for (int k = 0; k < A->ancho; k++)
	{
		A->e[i][k] /= piv;
	}
}

/*
Hecho por SubEquipo 3
Conformado por:
	- Islas Solis Emir
	- Ramirez Blanco Emiliano
	- Romero Arreola Fernado Rivaul
	- Sanchez Gutierrez Fernando Uriel
	- Sánchez Reyes Danuel Aberto
	- Tapia Tapia Mario Ivan
*/
void ceros_abajo(Matriz *A, int i)
{
	for (int k = i + 1; k < A->alto; k++)
	{
		float factor = A->e[k][i];
		for (int j = 0; j < A->ancho; j++)
		{
			A->e[k][j] -= factor * A->e[i][j];
		}
	}
}

/*
Hecho por SubEquipo 4
Conformado por:
	- Calleja Ávila Angel Antonio
	- Córdoba Arévalo Citlalli Guadalupe
	- Hernandez Zamora Valeria
	- Martinez Rios Fatima
	- Rosas Archundia Isaac Amed
	- Vásquez Adrés Rajiv Eduardo
*/
void ceros_arriba(Matriz *A, int i) {
	for (int k = 0; k < i; k++) { 
		float factor = A->e[k][i]; 

		for (int j = 0; j < A->ancho; j++) { 
			A->e[k][j] -= factor * A->e[i][j]; 
		}
	}
}
