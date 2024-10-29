//Ana Karen Islas Mart�nez
//Joshua
//Jose Vergara 
//Guillermo Heredia Cano

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "lib/aumMatrices.h"
#include "lib/opElementales.h"
#include "lib/matrices.h"
#include "equipos.h"

bool esFilaValida(AumMatriz *A, int fila);

void pasoAPaso(AumMatriz *A)
{
	imprimirAumMatriz(A);
	int op;
	int opc = 0;
	while (opc == 0)
	{
		printf ("Seleccione una operacion para la matriz porfavor :)\n");
		printf ("1.Sumar filas \n");
		printf ("2.Restar filas \n");
		printf ("3.Dividir fila \n");
		printf ("4.Multiplicar fila \n");
		printf ("5.Mover filas \n");
		printf ("6.Desechar \n");
		printf ("7.Salir\n");
		scanf ("%d", &op);

		int fila1,fila2;
		float factor;
		switch (op)
		{
			case 1:
			//Sumar filas
			printf("Formula: Ri + k*Rj -> R1\n");
			printf("Dame la fila a modificar (Ri)\n");
			scanf("%d",&fila1);
			fila1--;
			printf("Dame un numero por el cual multiplica la segunda fila(k)\n");
			scanf("%f", &factor);
			printf("Dame la segunda fila (Rj)\n");
			scanf("%d", &fila2);
			fila2--;
			
			if (esFilaValida(A, fila1) || esFilaValida(A, fila2))
			{
				sumaFilas(A, fila1, factor, fila2);
				imprimirAumMatriz(A);
				break;
			}
			printf("Fila invalida.\n");
			break;

			case 2:
			//Restar filas
			printf("Formula: Ri - k*Rj -> Ri\n");
			printf("Dame la fila a modificar (Ri)\n");
			scanf("%d", &fila1);
			fila1--;
			printf("Dame un numero por el cual multiplica la segunda fila(k)\n");
			scanf("%f", &factor);
			printf("Dame Rj\n");
			scanf("%d", &fila2);
			fila2--;

			if (esFilaValida(A, fila1) || esFilaValida(A, fila2))
			{
				sumaFilas(A, fila1, -factor, fila2);
				imprimirAumMatriz(A);
				break;
			}
			printf("Fila invalida.\n");
			break;

			case 3:
			//Dividir filas
			printf("Formula: Ri / k -> Ri\n");
			printf("Dame la fila a modificar (Ri)\n");
			scanf("%d",&fila1);
			fila1--;
			printf("Dame un numero por el cual dividir la fila(k)\n");
			scanf("%f",&factor);
			if (esFilaValida(A, fila1))
			{
			multFila(A, fila1 , 1/factor);
			imprimirAumMatriz(A);
			break;
			}
			printf("Fila invalida.\n");
			break;

			case 4:
			//Multiplicar filas
			printf("Formula: k*Ri -> Ri\n");
			printf("Dame la fila a modificar (Ri)\n");
			scanf("%d", &fila1);
			fila1--;
			printf("Dame un numero por el cual multiplicar la fila(k)\n");
			scanf("%f", &factor);
			if (esFilaValida(A, fila1))
			{
				multFila(A, fila1,factor);
				imprimirAumMatriz(A);
				break;
			}
			printf("Fila invalida.\n");
			break;

			case 5:
			//Mover
			printf("dame la primera fila\n");
			scanf("%d",&fila1);
			fila1--;
			printf("dame la segunda fila\n");
			scanf("%d",&fila2);
			fila2--;
			if (esFilaValida(A, fila1) || esFilaValida(A, fila2))
			{
				cambiarFilas(A, fila1, fila2);
				imprimirAumMatriz(A);
				break;
			}
			printf("Fila invalida.\n");
			break;

			case 6:
			//Desechar	
			eliminarAumMatriz(A);
			opc = 1;
			break;

			case 7:
			//Salir
			printf ("hasta luego T-T");
			opc = 1;
			break;

			default:
			printf ("eso no existe unu\n");
			break;
		}
	}
	return;
}


bool esFilaValida(AumMatriz *A, int fila)
{
	if (fila > A->alto || fila < 0)
		return false;
	return true;
}