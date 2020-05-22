#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>

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
    printf("7 - Imprimir vector\n");
    printf("0 - Salir\n");
}

/*FUNCION crearVector * /
/* Crea un vector aleatorio de n elementos */
/* Recibe el vector donde almacenar la información y el numero de elementos del vector */
void crearVector(int *(*vector[]), int n)
{
    time_t t;
    srand((unsigned) time(&t));
    for (int i = 0; i < n; i++)
        vector[i] = rand();
}

/*FUNCION crearVectorOrdenado * /
/* Crea un vector previamente ordenado de n elementos */
/* Recibe el vector donde almacenar la información y el numero de elementos del vector */
void crearVectorOrdenado(int *(*vector[]), int n)
{
    for (int i = 0; i < n; i++)
    {
        vector[i] = i*2;
    }
}

/*FUNCION printVector * /
/* Imprime el vector pasado como parametro siempre y cuando tenga menos de 100 elementos */
/* Recibe el vector donde almacenar la información y el numero de elementos del vector */
void printVector(int *vector, int n)
{
    int max = 0, min = INT_MAX;
    if (n <= 100)
    {
        for (int i = 0; i < n; i++)
        {
            printf("vector[%d] = %d\n", i, vector[i]);
        }

        for (int j = 0; j < n; j++)
        {
            if (vector[j] >= max)
                max = vector[j];

            if (vector[j] <= min)
                min = vector[j];
        }

        printf("Max: %d - Min: %d \n", max, min);
        
    }
    else
        printf("El vector es demasiado grande!\n\n");
    
    printf("\n");    
}

/*FUNCION ordSeleccion * /
/* Ordena el vector con un algoritmo de ordenacion por selección */
/* Recibe el vector donde almacenar la información, el numero de elementos del vector y un caracter de control que imprime paso a paso la ordenacion o no */
/* Devuelve el numero de comparaciones necesarias para ordenar el vector */
int ordSeleccion(int *(vector[]), int n, char snS)
{
    int contador = 0;
    int numPasosSeleccion = 1;
    clock_t clocks_elapsed;
    double time_elapsed;

    clocks_elapsed = clock();

    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (vector[j] < vector[min])
            {
                min = j;
                if (snS == 's')
                {
                    printf("--- PASO %d ---\n", numPasosSeleccion);
                    printVector(vector, n);
                    numPasosSeleccion++;  
                }
            }
            contador++;
        }
        if (i != min)
        {
            int aux = vector[i];
            vector[i] = vector[min];
            vector[min] = aux;
            if (snS == 's')
            {
                printf("--- PASO %d ---\n", numPasosSeleccion);
                printVector(vector, n);
                numPasosSeleccion++;  
            }
        }
    }

    clocks_elapsed = clock() - clocks_elapsed;
    time_elapsed = (double)clocks_elapsed / CLOCKS_PER_SEC;
    printf("\nTiempo transcurrido: %.3f segundos\n", time_elapsed);

    return contador;
}

/*FUNCION ordBurbuja * /
/* Ordena el vector con un algoritmo de ordenacion por burbuja */
/* Recibe el vector donde almacenar la información, el numero de elementos del vector y un caracter de control que imprime paso a paso la ordenacion o no */
/* Devuelve el numero de comparaciones necesarias para ordenar el vector */
int ordBurbuja(int *(vector[]), int n, char snB)
{
    int contador = 0;
    int numPasosBurbuja = 1;
    clock_t clocks_elapsed;
    double time_elapsed;

    clocks_elapsed = clock();

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++) 
        {
            if (vector[j] > vector[j + 1]) 
            {
                int aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
                if (snB == 's')
                {
                    printf("--- PASO %d ---\n", numPasosBurbuja);
                    printVector(vector, n);
                    numPasosBurbuja++;
                }
            }
            contador++;
        }
    }

    clocks_elapsed = clock() - clocks_elapsed;
    time_elapsed = (double)clocks_elapsed / CLOCKS_PER_SEC;
    printf("\nTiempo transcurrido: %.3f segundos\n", time_elapsed);
    return contador;
}

/*FUNCION ordInsercion * /
/* Ordena el vector con un algoritmo de ordenacion por inserción */
/* Recibe el vector donde almacenar la información, el numero de elementos del vector y un caracter de control que imprime paso a paso la ordenacion o no */
/* Devuelve el numero de comparaciones necesarias para ordenar el vector */
int ordInsercion(int *(vector[]), int n, char snI)
{
    int contador = 0;
    int numPasosInsercion = 1;
    int i, j, temp;
    clock_t clocks_elapsed;
    double time_elapsed;

    clocks_elapsed = clock();

    for (i = 0; i < n; i++)
    {
        temp = vector[i];
        j = i - 1;

        while (j >= 0 && vector[j] > temp)
        {
            if (snI == 's')
            {
                printf("--- PASO %d ---\n", numPasosInsercion);
                printVector(vector, n);
                numPasosInsercion++;
            }
            vector[j + 1] = vector[j];
            j--;
            contador++;
        }
        
        vector[j + 1] = temp;
    }
    clocks_elapsed = clock() - clocks_elapsed;
    time_elapsed = (double)clocks_elapsed / CLOCKS_PER_SEC;
    printf("\nTiempo transcurrido: %.3f segundos\n", time_elapsed);
    return contador;
}

/*FUNCION ordenado * /
/* Comprueba si un vector está ordenado o no */
/* Recibe el vector donde está la información y el numero de elementos del vector */
/* Devuelve un bool (True = ordenado, False = desordenado) */
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

/*FUNCION busDicotomica * /
/* Busca un numero dentro de un vector con un algoritmo de busqueda dicotomica */
/* Recibe el vector donde se almacena la información, el primer y el último numero del vector, el numero a buscar, un contador de numero de pasos realizados
/* y un caracter de control que imprime paso a paso la ordenacion o no */
/* Devuelve un int que controla si el numero se ha encontrado o no */
int busDicotomica(int arr[], int l, int r, int x, int *contador, char sn)
{ 
    int n = r + 1;
    int numPasosDico = 1;
    while (l <= r)
    { 
        *contador += 1;
        int mid = l + (r-l)/2; 
  
        if (arr[mid] == x)  
        {
            if (sn == 's')
            {
                printf("--- PASO %d ---\n", numPasosDico);
                printf("Numero a buscar: %d\n", x);
                printf("Numero actual: %d\n", arr[mid]);
                printf("Posicion del array: %d\n\n", mid);
                numPasosDico++;
            }
            return mid;
        }
  
        if (arr[mid] < x)
        {
            if (sn == 's')
            {
                printf("--- PASO %d ---\n", numPasosDico);
                printf("Numero a buscar: %d\n", x);
                printf("Numero actual: %d\n", arr[mid]);
                printf("Posicion del array: %d\n\n", mid);
                numPasosDico++;
                l = mid + 1;

            }
        }   

        else 
        {
            if (sn == 's')
            {
                printf("--- PASO %d ---\n", numPasosDico);
                printf("Numero a buscar: %d\n", x);
                printf("Numero actual: %d\n", arr[mid]);
                printf("Posicion del array: %d\n\n", mid);
                numPasosDico++;
            }
            r = mid - 1;
        }

    } 
    return -1;  
}