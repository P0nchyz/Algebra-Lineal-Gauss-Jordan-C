/*Submatriz paso a paso.
esta funcion creara las submatrices para el paso a paso*/


#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "subMatriz.h"

// Crear una submatriz
SubMatriz *crearSubMatriz(unsigned int n) {
    SubMatriz *mat = (SubMatriz *)malloc(sizeof(SubMatriz));
    mat->n = n;
    mat->e = (float **)malloc(n * sizeof(float *));
    for (unsigned int i = 0; i < n; i++) {
        mat->e[i] = (float *)malloc(n * sizeof(float));
    }
    return mat;
}

// Liberar memoria de la submatriz
void eliminarSubMatriz(SubMatriz *mat) {
    for (unsigned int i = 0; i < mat->n; i++) {
        free(mat->e[i]);
    }
    free(mat->e);
    free(mat);
}

// Imprimir la matriz
void imprimirSubMatriz(SubMatriz *mat) {
    printf("Matriz (%dx%d):\n", mat->n, mat->n);
    for (unsigned int i = 0; i < mat->n; i++) {
        for (unsigned int j = 0; j < mat->n; j++) {
            printf("%.2f ", mat->e[i][j]);
        }
        printf("\n");
    }
}

// Verificar si una fila es válida
bool esFilaValida(SubMatriz *mat, int fila) {
    return (fila >= 0 && fila < mat->n);
}

// Función para mostrar una matriz
void mostrarMatriz(Matriz *mat) {
    for (int i = 0; i < mat->alto; i++) {
        for (int j = 0; j < mat->ancho; j++) {
            printf("%8.2f ", mat->e[i][j]);
        }
        printf("\n");
    }
}


// Menú de operaciones paso a paso
void pasoAPaso(SubMatriz *mat) {
    imprimirSubMatriz(mat);
    int opc = 0;

    while (opc == 0) {
        printf("\nSeleccione una operación:\n");
        printf("1. Sumar filas\n");
        printf("2. Restar filas\n");
        printf("3. Multiplicar fila\n");
        printf("4. Dividir fila\n");
        printf("5. Cambiar filas\n");
        printf("6. Salir\n");
        int op;
        scanf("%d", &op);

        int fila1, fila2;
        float factor;
        switch (op) {
            case 1:
                printf("Suma de filas: Ri + k*Rj -> Ri\n");
                printf("Fila a modificar (Ri): ");
                scanf("%d", &fila1);
                printf("Factor (k): ");
                scanf("%f", &factor);
                printf("Fila a sumar (Rj): ");
                scanf("%d", &fila2);
                fila1--;
                fila2--;

                if (esFilaValida(mat, fila1) && esFilaValida(mat, fila2)) {
                    for (unsigned int j = 0; j < mat->n; j++) {
                        mat->e[fila1][j] += factor * mat->e[fila2][j];
                    }
                    imprimirSubMatriz(mat);
                } else {
                    printf("Filas inválidas.\n");
                }
                break;

            case 2:
                printf("Resta de filas: Ri - k*Rj -> Ri\n");
                printf("Fila a modificar (Ri): ");
                scanf("%d", &fila1);
                printf("Factor (k): ");
                scanf("%f", &factor);
                printf("Fila a restar (Rj): ");
                scanf("%d", &fila2);
                fila1--;
                fila2--;

                if (esFilaValida(mat, fila1) && esFilaValida(mat, fila2)) {
                    for (unsigned int j = 0; j < mat->n; j++) {
                        mat->e[fila1][j] -= factor * mat->e[fila2][j];
                    }
                    imprimirSubMatriz(mat);
                } else {
                    printf("Filas inválidas.\n");
                }
                break;

            case 3:
                printf("Multiplicación de fila: k*Ri -> Ri\n");
                printf("Fila a modificar (Ri): ");
                scanf("%d", &fila1);
                printf("Factor (k): ");
                scanf("%f", &factor);
                fila1--;

                if (esFilaValida(mat, fila1)) {
                    for (unsigned int j = 0; j < mat->n; j++) {
                        mat->e[fila1][j] *= factor;
                    }
                    imprimirSubMatriz(mat);
                } else {
                    printf("Fila inválida.\n");
                }
                break;

            case 4:
                printf("División de fila: Ri / k -> Ri\n");
                printf("Fila a modificar (Ri): ");
                scanf("%d", &fila1);
                printf("Factor (k): ");
                scanf("%f", &factor);
                fila1--;

                if (esFilaValida(mat, fila1) && factor != 0) {
                    for (unsigned int j = 0; j < mat->n; j++) {
                        mat->e[fila1][j] /= factor;
                    }
                    imprimirSubMatriz(mat);
                } else {
                    printf("Fila inválida o factor inválido.\n");
                }
                break;

            case 5:
                printf("Intercambiar filas: Ri <-> Rj\n");
                printf("Primera fila (Ri): ");
                scanf("%d", &fila1);
                printf("Segunda fila (Rj): ");
                scanf("%d", &fila2);
                fila1--;
                fila2--;

                if (esFilaValida(mat, fila1) && esFilaValida(mat, fila2)) {
                    for (unsigned int j = 0; j < mat->n; j++) {
                        float temp = mat->e[fila1][j];
                        mat->e[fila1][j] = mat->e[fila2][j];
                        mat->e[fila2][j] = temp;
                    }
                    imprimirSubMatriz(mat);
                } else {
                    printf("Filas inválidas.\n");
                }
                break;

            case 6:
                printf("Saliendo...\n");
                opc = 1;
                break;

            default:
                printf("Opción no válida.\n");
                break;
        }
    }
}