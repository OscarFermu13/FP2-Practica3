#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/algoritmos.h"

/* Programa Principal */
int main() {
	int opcion, vector[100000], contador;
	char enter;

	/* Cargar el menu principal */
	print_menu();
	scanf("%d", &opcion);
	scanf("%c", &enter);

	int n = 10;

	crearVector(&vector, n);

	while (opcion != 0)
	{
		switch (opcion)
		{
			case 1:
				printf("\n\n---  Generar vector aleatorio ---\n");
				crearVector(&vector, n);
				printf("Vector aleatorio de %d posiciones generado!\n\n", n);
				break;

			case 2:
				printf("\n\n---  Ordenacion por seleccion ---\n");
				contador = 0;
				contador = ordSeleccion(&vector, n);
				printVector(vector, n);
				printf("\nContador: %d\n\n", contador);
				break;

			case 3:
				printf("\n\n---  Ordenacion por burbuja ---\n");
				contador = 0;
				contador = ordBurbuja(&vector, n);
				printVector(vector, n);
				printf("\nContador: %d\n\n", contador);
				break;

			case 4:
				printf("\n\n---  Ordenacion por insercion ---\n");
				//contador = ordInsercion(&vector, n);
				printVector(vector, n);
				printf("\nContador: %d\n\n", contador);
				break;

			case 5:
				printf("\n\n---  Busqueda dicotomica ---\n");
				break;

			case 9:
				printf("\n");
				printVector(vector, n);
				break;

			case 0:
				opcion = 0;
				break;
			
			default:
				break;
		}

		print_menu();
		scanf("%d", &opcion);
		scanf("%c", &enter);
	}
}
