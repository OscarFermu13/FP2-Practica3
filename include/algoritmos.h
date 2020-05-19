#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <stdbool.h>
#include <stdio.h>

/* Prototipos */
void print_menu(void);

void crearVector(int *(*vector[]), int n);
int ordSeleccion(int *(vector[]), int n);
int ordBurbuja(int *(vector[]), int n);
int ordInsercion(int *(vector[]), int n);
void printVector(int *vector, int n);
int ordInsercion(int *(vector[]), int n);
bool ordenado (int array [], int n);
int binarySearch(int arr[], int l, int r, int x, int *contador); 

#endif // ALGORITMOS_H