#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <string.h>

/// Punto 1
int verCantArr(int arr[], int cantidad)
{
    int ingreso;
    int i = 0;
    char seguir = 's';

    while(seguir == 's' && i < cantidad)
    {
        printf("Ingrese un valor al arreglo: \n");
        fflush(stdin);
        scanf("%i", &ingreso);
        arr[i] = ingreso;
        i++;

        printf("Si desea seguir ingresando valores presione s: \n");
        fflush(stdin);
        scanf("%c", &seguir);
    }

    return i;
}

/// Punto 2
void mostrar_arr(int arr2[], int validos) {
    for (int i = 0; i < validos; i++) {
        printf("Posicion %i: %i \n", i, arr2[i]);
    }
}

/// Punto 3
int sumar_arr(int arr3[], int validos) {
    int suma = 0;
    for (int i = 0; i < validos; i++) {
        suma = suma + arr3[i];
    }
    return suma;
}

/// Punto 4
void arrToPila(int arr4[], int validos, Pila *pila) {
    int aux;
    for(int i = 0; i < validos; i++) {
        aux = arr4[i];
        apilar(pila, aux);
    }
    printf("Pila cargada: \n");
    mostrar(pila);
}

/// Punto 5
int cargar_arr(int arr5[], int cantidad) {
    float aux;
    int i = 0;
    int x = 0;
    float suma = 0;
    char seguir = 's';
    while(seguir == 's' && i < cantidad) {
        printf("Ingrese un numero: \n");
        fflush(stdin);
        scanf("%f", &aux);
        arr5[i] = aux;

        printf("Desea seguir cargando? Presione s: \n");
        fflush(stdin);
        scanf("%c", &seguir);
        i++;
    }

    for (x = 0; x < i; x++) {
        suma = suma + arr5[x];
    }
    return suma;
}

/// Punto 6
int buscar_letra(char arr6[], int cantidad, char elemento) {
    int i = 0;
    for(i = 0; i < cantidad; i++) {
        if(arr6[i] == elemento) {
            return 1;
        }
    }
    return 0;
}

/// Punto 7
void ordenear_arr(char arr7[], char *validos, char letra) {
    int i = *validos - 1;

     while (i >= 0 && arr7[i] > letra) {
        arr7[i + 1] = arr7[i];
        i--;
    }
    arr7[i + 1] = letra;
    (*validos)++;
}

void imprimirArreglo(char arr7[], int validos) {
    for (int i = 0; i < validos; i++) {
        printf("%c ", arr7[i]);
    }
    printf("\n");
}

/// Punto 8
char buscarMayor(char arr8[], int cantidad) {
    int i = 1;
    char aux = arr8[0];
    for(i = 1; i < cantidad; i++) {
        if(aux < arr8[i]) {
            aux = arr8[i];
        }
    }
    return aux;
}
/// Punto 9
int buscarCapicua(char arr9[], int validos)
{
    int i = 0;
    int j = validos - 1;

     while (i < j) {
        if (arr9[i] != arr9[j]) {
            return 0;
        }
        i++;
        j--;
    }

    return 1;
}

/// Punto 10
void reversar_arr(int arr10[], int validos) {
    int aux1;
    int aux2;
    int i = 0;
    int j = validos - 1;

    while(i < j) {
        aux1 = arr10[i];
        aux2 = arr10[j];
        arr10[i] = aux2;
        arr10[j] = aux1;
        i++;
        j--;
    }

    for (int x = 0; x < validos; x++) {
        printf("%i ", arr10[x]);
    }
    printf("\n");
}

/// Punto 11
void ordenamientoPorInsercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > clave) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = clave;
    }
}

void ordenamientoPorSeleccion(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

/// Punto 12
void intercalarArr(char arr12[], int dimArr, char aux12[], int dimAux)
{
    char arrMezclado[10];
    int h = 0;
    int i = 0;
    int j = 0;

    while((i < dimArr) &&(j < dimAux))
    {
        if(arr12[i] < aux12[j])
        {
            arrMezclado[h] = arr12[i];
            h++;
            i++;
        }
        else
        {
            arrMezclado[h] = aux12[j];
            h++;
            j++;
        }
    }

    for(int x = 0; x < h; x++)
    {
        printf("%c", arrMezclado[x]);
    }
}

/// Punto 13
void sumar_vectores(int arr13[], int validos) {
    int suma = 0;
    for(int i = 0; i <= validos; i++) {
        suma = suma + arr13[i];
        printf("La suma de los vectores es: %i \n", suma);
    }

    return suma;
}

int main()
{
/// Punto 1
    int arr1[5];
    int rta1 = verCantArr(arr1, 5);
    printf("Se ingresaron %i numeros \n", rta1);

/// Punto 2
    int arr2[5] = {1, 2, 3};
    mostrar_arr(arr2, 3);

/// Punto 3
    int arr3[5] = {9, 4, 7};
    int rta3 = sumar_arr(arr3, 3);
    printf("La suma de todos los elementos es: %i \n", rta3);

/// Punto 4
    int arr4[5] = {3, 6, 9};
    Pila pila;
    inicpila(&pila);
    arrToPila(arr4, 3, &pila);

/// Punto 5
    float arr5[100];
    float rta5 = cargar_arr(arr5, 100);
    printf("La suma es: %f", rta5);

/// Punto 6
    char arr6[10] = {'a', 'e', 'i', 'o', 'u'};
    char elemento;
    printf("Ingrese una letra a buscar: \n");
    fflush(stdin);
    scanf("%c", &elemento);
    int rta6 = buscar_letra(arr6, 10, elemento);
    if(rta6 == 1) {
        printf("Se encontro el elemento. \n");
    }
    else {
        printf("No se encontro el elemento. \n");
    }

/// Punto 7
    char arr7[10] = {'a', 'e', 'i', 'o', 'u'};
    int validos = 5;
    char letra;
    printf("Ingrese una letra: \n");
    fflush(stdin);
    scanf("%c", &letra);

    ordenear_arr(arr7, &validos, letra);
    imprimirArreglo(arr7, validos);

/// Punto 8
    char arr8[10] = {'a', 'z', 'e', 'f'};
    char rta8 = buscarMayor(arr8, 10);
    printf("La mayor letra ingresada es: %c \n", rta8);

/// Punto 9
    char arr9[5] = {'a', 'b', 'c', 'b', 'a'};
    int rta9 = buscarCapicua(arr9, 5);
    if(rta9 != 1) {
        printf("No es capicua");
    }
    else {
        printf("Es capicua");
    }

/// Punto 10
    int arr10[10] = {1, 2, 3, 4, 5};
    reversar_arr(arr10, 5);

/// Punto 11
    int arreglo11A[] = {12, 11, 13, 5, 6};
    int nA = sizeof(arreglo11A) / sizeof(arreglo11A[0]);

    printf("Arreglo original: ");
    imprimirArreglo(arreglo11A, nA);

    ordenamientoPorInsercion(arreglo11A, nA);

    printf("Arreglo ordenado: ");
    imprimirArreglo(arreglo11A, nA);

    -------------------------------------

    int arreglo11B[] = {64, 25, 12, 22, 11};
    int nB = sizeof(arreglo11B) / sizeof(arreglo11B[0]);

    printf("Arreglo original: ");
    imprimirArreglo(arreglo11B, nA);

    ordenamientoPorSeleccion(arreglo11B, nA);

    printf("Arreglo ordenado: ");
    imprimirArreglo(arreglo11B, nA);

/// Punto 12
    char arr12[10] = {'a', 'c', 'e'};
    char aux12[10] = {'b', 'd', 'f'};
    intercalarArr(arr12, 10, aux12, 10);

/// Punto 13
    int arr13[10] = {1, 5, 6, 7, 8};
    sumar_vectores(arr13, 5);
}
