/*Aqui esta la funcion principal para calcular el
determinante paso a paso. */


#include <math.h>
#include "lib/matrices.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "lib/subMatriz.h"
#include "lib/opElementales.h"
#include "equipos.h"

// Función para calcular la determinante
float determinantePaP(SubMatriz *A) {
    // Verificamos si la matriz es cuadrada
    if (A->n != A->n) return 0;
    // Caso base 1x1
    if (A->n == 1) {
        printf("Caso base 1x1. Matriz:\n");
        mostrarMatriz(A);
        printf("Determinante = %.2f\n\n", A->e[0][0]);
        return A->e[0][0];
    }
    // Caso base 2x2
    if (A->n == 2) {
        printf("Caso base 2x2. Matriz:\n");
        mostrarMatriz(A);
        float determinante = A->e[0][0] * A->e[1][1] - A->e[0][1] * A->e[1][0];
        printf("Determinante = %.2f\n\n", determinante);
        return determinante;
    }

    float resultado = 0;
    int n = A->n;

    // Submatriz de tamaño (n-1) x (n-1)
    Matriz *sub = crearMatriz(n - 1, n - 1);

    for (int j = 0; j < n; j++) {
        // Construimos la submatriz excluyendo la primera fila y la columna j
        int sub_i = 0;
        for (int i = 1; i < n; i++) {
            int sub_j = 0;
            for (int k = 0; k < n; k++) {
                if (k == j) continue;
                sub->e[sub_i][sub_j] = A->e[i][k];
                sub_j++;
            }
            sub_i++;
        }

        printf("Submatriz excluyendo columna %d:\n", j + 1);
        mostrarMatriz(sub);

        // Calculamos la determinante de la submatriz recursivamente
        float subDet = det(sub);
        printf("Sub-determinante = %.2f\n", subDet);
        printf("Producto = %.2f * %.2f * %.2f = %.2f\n\n", pow(-1, j), A->e[0][j], subDet, pow(-1, j) * A->e[0][j] * subDet);

        resultado += pow(-1, j) * A->e[0][j] * subDet;
    }

    // Liberamos la memoria de la submatriz
    for (int i = 0; i < n - 1; i++) {
        free(sub->e[i]);
    }
    free(sub->e);

    return resultado;
}