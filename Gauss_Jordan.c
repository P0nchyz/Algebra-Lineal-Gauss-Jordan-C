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

typedef struct Matriz
{
	int ancho;
	int alto;
	float **e; // Arreglo bidimensional
} Matriz;

typedef struct Pivote
{
	int i;
	int j;
} Pivote;

void llenarMatriz(Matriz *A);

void imprimirMatriz(Matriz *A);

void cambiar_renglones(Matriz *A, Pivote *piv);

void hacer_unos(Matriz *A, Pivote *piv);

void ceros_abajo(Matriz *A, Pivote *piv);

void ceros_arriba(Matriz *A, Pivote *piv);


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
	
	for (Pivote piv = {0, 0}; (piv.i < A.alto) && (piv.j < A.ancho); piv.i++, piv.j++)
	{
		cambiar_renglones(&A, &piv);
		hacer_unos(&A, &piv);
		ceros_abajo(&A, &piv);
		ceros_arriba(&A, &piv);
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
	printf("\n\t\b|-");
	for (int i = 0; i < A->ancho; i++)
		printf("\t");
	printf("-|\n");
	for (int i = 0; i < A->alto; i++)
	{
		printf("\t\b|");
		for (int j = 0; j < A->ancho; j++)
		{
			if (A->e[i][j] == -0.0)
				A->e[i][j] = 0.0;
			float distanceToInt = fabs((int)A->e[i][j] - A->e[i][j]);
			printf("%.*f\t", (distanceToInt < 0.009) ? 0 : 2, A->e[i][j]);
		}
		printf(" |\n");
	}
	printf("\t\b|-");
	for (int i = 0; i < A->ancho; i++)
		printf("\t");
	printf("-|\n");
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
void cambiar_renglones(Matriz *A, Pivote *piv)
{
	if (A->e[piv->i][piv->j] != 0)
		return;

	for (int l = piv->j; l < A->ancho; l++)
	{
		for (int k = piv->i; k < A->alto; k++)
		{
			if (0 != A->e[k][l])
			{
				for (int m = 0; m < A->ancho; m++)
				{
					float aux = A->e[k][m];
					A->e[k][m] = A->e[piv->i][m];
					A->e[piv->i][m] = aux;
				}
				return;
			}
		}
		piv->j++;
	}
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
void hacer_unos(Matriz *A, Pivote *piv)
{
	float factor = A->e[piv->i][piv->j];
	for (int k = 0; k < A->ancho; k++)
	{
		A->e[piv->i][k] /= factor;
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
void ceros_abajo(Matriz *A, Pivote *piv)
{
	for (int k = piv->i + 1; k < A->alto; k++)
	{
		float factor = A->e[k][piv->j];
		for (int l = 0; l < A->ancho; l++)
		{
			A->e[k][l] -= factor * A->e[piv->i][l];
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
void ceros_arriba(Matriz *A, Pivote *piv) {
	for (int k = 0; k < piv->i; k++) { 
		float factor = A->e[k][piv->i]; 

		for (int l = 0; l < A->ancho; l++) { 
			A->e[k][l] -= factor * A->e[piv->i][l]; 
		}
	}
}
