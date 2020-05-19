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

int ordInsercion(int *(vector[]), int n)
{
    int contador = 0;
    int min; 

    for (int i = 0; i < n - 1; i++)
    {
        min = vector[i];
        int posicion = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vector[j] < min)
            {
                min = vector[j];
                posicion = j;
                contador++;
            }
        }
        vector[posicion] = vector[i];
        vector[i] = min;

    }
    return contador;
}

bool ordenado (int array [], int n)
{
    int i;
    for (i = 0; i < (n - 1); i++)
    {
        if (array[i]>array[i + 1])
        {
            return false;
        }
    }
    return true;
}

int binarySearch(int arr[], int l, int r, int x, int *contador) 
{ 
  while (l <= r) 
  { 
    *contador += 1;
    int mid = l + (r-l)/2; 
  
    if (arr[mid] == x)  
    {
        return mid;
    }
  
    if (arr[mid] < x)
    {
        l = mid + 1;
    }   

    else 
    {
        r = mid - 1;
    }
  } 
    return -1;  
} 