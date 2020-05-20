#ifndef ALGORITMOS_H
#define ALGORITMOS_H

#include <stdbool.h>
#include <stdio.h>

/* Prototipos */
void print_menu(void);

void crearVector(int *(*vector[]), int n);
void crearVectorOrdenado(int *(*vector[]), int n);

int ordSeleccion(int *(vector[]), int n, char sn);
int ordBurbuja(int *(vector[]), int n, char sn);
int ordInsercion(int *(vector[]), int n, char sn);
int busDicotomica(int arr[], int l, int r, int x, int *contador, char sn); 

void printVector(int *vector, int n);
void printVectorExtra(int *vector, int n);
bool ordenado (int array [], int n);

#endif // ALGORITMOS_H