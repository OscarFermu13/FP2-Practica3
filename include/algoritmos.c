#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#include "algoritmos.h"

/* FUNCION print_menu */
/* Imprime el menu principal */
void print_menu(void)
{
    printf("----- MENU ----- \n");
    printf("1 - Generar vector aleatorio\n");
    printf("2 - Ordenacion por seleccion\n");
    printf("3 - Ordenacion por burbuja\n");
    printf("4 - Ordenacion por insercion\n");
    printf("5 - Busqueda dicotomica\n");
    printf("0 - Salir\n");
}

void crearVector(int *(*vector[]), int n)
{
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < n; i++)
    {
        vector[i] = rand();
    }
}

void printVector(int *vector, int n)
{
    if (n <= 100)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d\n", vector[i]);
        }
    }
    else
        printf("El vector es demasiado grande!\n\n");
    
    printf("\n");    
}

int ordSeleccion(int *(vector[]), int n)
{
    int contador = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vector[j] < vector[min])
            {
                min = j;
                contador++;
            }
        }
        if (i != min)
        {
            int aux = vector[i];
            vector[i] = vector[min];
            vector[min] = aux;
        }
    }
    return contador;
}

int ordBurbuja(int *(vector[]), int n)
{
    int contador = 0;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++) 
        {
            if (vector[j] > vector[j + 1]) 
            {
                int aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
                contador++;
            }
        }
    }

    return contador;
}