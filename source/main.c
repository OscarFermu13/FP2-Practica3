#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../include/algoritmos.h"

/* Programa Principal */
int main() {
	int opcion, vector[100000], numero, contadorSeleccion;
	char enter, sino;
	int n;

	printf("\n\n --- ORDENACIO, CERCA I COST --- \n");
	printf("Numero de elementos del vector? (Multiplo de 10)\n");
	scanf("%d", &n);

	/* Cargar el menu principal */
	print_menu();
	scanf("%d", &opcion);
	scanf("%c", &enter);


	crearVector(vector, n);

	while (opcion != 0)
	{
		switch (opcion)
		{
			case 1:
				printf("\n\n---  Generar vector aleatorio ---\n");
				crearVector(vector, n);
				printf("Vector aleatorio de %d posiciones generado!\n\n", n);
				break;

			case 2:
				printf("\n\n---  Ordenacion por seleccion ---\n");
				printf("Desea ver el procedimiento paso a paso? (s/n)\n");
				scanf("%s", &sino);
				contadorSeleccion = 0;
				contadorSeleccion = ordSeleccion(vector, n, sino);
				printf("--- VECTOR ORDENADO ---\n");
				printVector(vector, n);
				printf("\nContador: %d\n\n", contadorSeleccion);
				break;


			case 3:
				printf("\n\n---  Ordenacion por burbuja ---\n");
				printf("Desea ver el procedimiento paso a paso? (s/n)\n");
				scanf("%s", &sino);
				int contadorBurbuja = 0;
				contadorBurbuja = ordBurbuja(vector, n, sino);
				printf("--- VECTOR ORDENADO ---\n");
				printVector(vector, n);
				printf("\nContador: %d\n\n", contadorBurbuja);
				break;
			case 4:
				printf("\n\n---  Ordenacion por insercion ---\n");
				printf("Desea ver el procedimiento paso a paso? (s/n)\n");
				scanf("%s", &sino);
				int contadorInsercion = 0;
				contadorInsercion = ordInsercion(vector, n, sino);
				printf("--- VECTOR ORDENADO ---\n");
				printVector(vector, n);
				printf("\nContador: %d\n\n", contadorInsercion);
				break;


			case 5:
				printf("\n\n---  Busqueda dicotomica ---\n");
				printf("Introduce el numero deseado (positivo):\n");
				scanf("%d", &numero);
				if (!ordenado(vector, n))
				{
					printf("El vector esta desordenado, utiliza la opcion 2, 3 o 4 para ordenarlo\n\n");
					break;
				}
				else
				{
					
					int contdicotomica = 0;
					printf("Desea ver el procedimiento paso a paso? (s/n)\n");
					scanf("%s", &sino);
					int dicotomica = busDicotomica(vector, 0, n - 1, numero, &contdicotomica, sino);

					if(dicotomica != -1)
					{
						printf("El numero %d esta en la posicion %d.\n", numero, dicotomica);
						printf("Contador: %d\n\n", contdicotomica);
					}
					else
						printf("El numero %d no se encuentra en el array.\n", numero);
					break;
				}


			case 7: 
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
