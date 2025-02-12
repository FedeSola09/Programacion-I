#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"

int const FILA = 10;
int const COLU = 100;

/// Punto 1
void cargarMatriz(int matriz1[FILA][COLU]) {
    int valor;
    int i = 0;
    int j = 0;

    for(i = 0; i < FILA; i++) {

        for(j = 0; j <
        COLU; j++){
            printf("Ingrese un numero a la matriz: \n");
            fflush(stdin);
            scanf("%d", &valor);
            matriz1[i][j] = valor;
        }
    }
}

/// Punto 2
void mostrarMatriz(int matriz1[FILA][COLU]) {
    for(int i = 0; i < FILA; i++) {

        for(int j = 0; j < COLU; j++) {
            printf(" |%d| ", matriz1[i][j]);
        }
    }
}

/// Punto 3
void cargarMatrizAleat(int matriz3[FILA][COLU]) {
    srand(time(NULL));
    int valor = 1 + rand() % 10;
    int i = 0;
    int j = 0;

    for(i = 0; i < FILA; i++) {

        for(j = 0; j <
        COLU; j++){
            matriz3[i][j] = valor;
        }
    }
}

/// Punto 4
int sumarContenido(int matriz1[FILA][COLU]) {
    int i = 0;
    int j = 0;
    int suma = 0;

    for(i = 0; i < FILA; i++) {

        for(j = 0; j < COLU; j++) {
            suma = suma + matriz1[i][j];
        }
    }
    return suma;
}

/// Punto 5
float promedioMatriz(int matriz5[FILA][COLU]) {
    int i = 0;
    int j = 0;
    int suma = 0;

    for(i = 0; i < FILA; i++) {

        for(j = 0; j < COLU; j++) {
            suma = suma + matriz5[i][j];
        }
    }

    return (float) suma / (FILA * COLU);
}

/// Punto 6
int buscarElemento(int matriz6[FILA][COLU], int datoBuscado) {
    int i = 0;
    int j = 0;
    int flag = 0;

    for(i = 0; i < FILA; i++) {

        for(j = 0; j < COLU; j++) {

            if(matriz6[i][j] == datoBuscado) {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

/// Punto 7
int cargarString(char matriz7[], int dim) {
    int i = 0;
    char seguir = 's';

    while(seguir == 's' && i < dim)
    {
        printf("Ingrese una palabra: \n");
        fflush(stdin);
        scanf(" %c", &matriz7[i]);

        printf("Ingrese S para continuar: \n");
        fflush(stdin);
        scanf(" %c", &seguir);

        i++;
    }

        return i;
}

/// Punto 8
void mostrarString(char matriz8[], int dim) {
    int i = 0;

    printf("Contenido del arreglo: \n");
    for(i = 0; i < dim; i++) {
        printf("%c", matriz8[i]);
    }
}

/// Punto 9
int buscarEnArreglo(char matriz9[FILA][COLU], int cantPalabras, char aux[]) {

    for (int i = 0; i < cantPalabras; i++)
    {

        if (strcmp(matriz9[i], aux) == 0)
        {
            return i;
        }
    }

    return -1;
}

/// Punto 10
// No lo hago porque es lo mismo que el punto anterior.

/// Punto 11
void ordenamientoPorSeleccion(char *matriz11[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(matriz11[j], matriz11[minIndex]) < 0)
            {
                minIndex = j;
            }
        }
        char *temp = matriz11[minIndex];
        matriz11[minIndex] = matriz11[i];
        matriz11[i] = temp;
    }
}

void imprimirArreglo(char *matriz11[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s ", matriz11[i]);
    }
    printf("\n");
}

int main()
{
/// Punto 1
    int matriz1[3][3];
    cargarMatriz(matriz1);

/// Punto 2
    mostrarMatriz(matriz1);

/// Punto 3
    int matriz3[3][3];
    cargarMatrizAleat(matriz3);

/// Punto 4
    int matriz1[3][3];
    cargarMatriz(matriz1);
    int rta4 = sumarContenido(matriz1);
    printf("La suma de la matriz es: %d \n", rta4);

/// Punto 5
    int matriz5[3][3] = {
                            {1, 2, 3},
                            {3, 2, 1},
                            {6, 6, 3}
                        };
    float rta5 = promedioMatriz(matriz5);
    printf("El promedio de la matriz es: %f \n", rta5);

/// Punto 6
    int matriz6[3][3] = {
                            {2, 4, 6},
                            {8, 10, 12},
                            {14, 16, 18}
                        };
    int datoBuscado = 19;
    int rta6 = buscarElemento(matriz6, datoBuscado);

    if(rta6 == 0) {
        printf("No se encontro el valor. \n");
    }
    else {
        printf("Se encontro el valor. \n");
    }

/// Punto 7
    char matriz7[5];
    int rta7 = cargarString(matriz7, 5);
    printf("Se cargaron %d palabras \n", rta7);

/// Punto 8
    char matriz8[35] = {"Hola! como estas?"};
    mostrarString(matriz8, 35);

/// Punto 9
    char matriz9[10][100] = { {"uno"}, {"dos"}, {"tres"}, {"cuatro"}, {"cinco"} };
    char aux[100] = {"cuatro"};
    int rta9 = buscarEnArreglo(matriz9, 5, aux);

    if (rta9 != -1)
    {
        printf("La palabra '%s' se encuentra en la fila %d.\n", aux, rta9);
    }
    else
    {
        printf("La palabra '%s' no se encuentra en la matriz.\n", aux);
    }

/// Punto 10
    // No lo hago porque es lo mismo que el punto anterior.

/// Punto 11
    char *matriz11[] = {"uno", "dos", "tres", "cuatro", "cinco"};
    int n = sizeof(matriz11) / sizeof(matriz11[0]);

    printf("Arreglo original: ");
    imprimirArreglo(matriz11, n);

    ordenamientoPorSeleccion(matriz11, n);

    printf("Arreglo ordenado: ");
    imprimirArreglo(matriz11, n);
}
