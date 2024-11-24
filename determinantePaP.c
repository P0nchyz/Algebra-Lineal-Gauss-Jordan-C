/*Aqui esta la funcion principal para calcular el
determinante paso a paso. */


#include <math.h>
#include "lib/matrices.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/opElementales.h"
#include "equipos.h"

// Función para calcular la determinante
float determinantePaP(Matriz *A) {
    // Verificamos si la matriz es cuadrada
    if (A->ancho != A->alto) return 0;
    // Caso base 1x1
    if (A->alto == 1) {
        printf("Caso base 1x1. Matriz:\n");
        imprimirMatriz(A);
        printf("Determinante = %.2f\n\n", A->e[0][0]);
        return A->e[0][0];
    }
    // Caso base 2x2
    if (A->alto == 2) {
        printf("Caso base 2x2. Matriz:\n");
        imprimirMatriz(A);
        float determinante = A->e[0][0] * A->e[1][1] - A->e[0][1] * A->e[1][0];
        printf("Determinante = %.2f\n\n", determinante);
        return determinante;
    }

    float resultado = 0;
    int n = A->alto;

    // Submatriz de tamaño (n-1) x (n-1)
    Matriz *sub = crearMatriz(n - 1, n - 1);

    for (int j = 0; j < n; j++) {
        // Construimos la submatriz excluyendo la primera fila y la columna j
        for (int i = 1; i < n; i++) {
            int sub_j = 0;
            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                sub->e[i - 1][sub_j++] = A->e[i][k];
            }
        }

        printf("Submatriz excluyendo columna %d:\n", j + 1);
        imprimirMatriz(sub);

        // Calculamos la determinante de la submatriz recursivamente
        float subDet = determinantePaP(sub);
        printf("Sub-determinante = %.2f\n", subDet);

        printf("Producto = %.2f * %.2f * %.2f = %.2f\n\n", pow(-1, j), A->e[0][j], subDet, pow(-1, j) * A->e[0][j] * subDet);

        resultado += pow(-1, j) * A->e[0][j] * subDet;
    }

    // Liberamos la memoria de la submatriz
    eliminarMatriz(sub);

    return resultado;
}

// Menú de operaciones paso a paso
void pasoAPaso(Matriz *mat) {
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
                    for (unsigned int j = 0; j < mat->ancho; j++) {
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
                    for (unsigned int j = 0; j < mat->ancho; j++) {
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
                    for (unsigned int j = 0; j < mat->ancho; j++) {
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
                    for (unsigned int j = 0; j < mat->ancho; j++) {
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
                    for (unsigned int j = 0; j < mat->ancho; j++) {
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