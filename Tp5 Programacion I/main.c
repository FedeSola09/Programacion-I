#include <stdio.h>
#include <stdlib.h>

///Punto 1
int cargarAlumno(int legajos[], int cantLeg, char nombres[20][30], int anios[]) {
    int i = 0;
    char seguir = 's';

    while(seguir == 's' && i < cantLeg) {

        printf("Ingrese un legajo: \n");
        fflush(stdin);
        scanf(" %d", &legajos[i]);

        printf("Ingrese un nombre: \n");
        fflush(stdin);
        scanf(" %s", &nombres[i]);

        printf("Ingrese una edad: \n");
        fflush(stdin);
        scanf(" %d", &anios[i]);

        i++;

        printf("Ingrese s para continuar . . . \n");
        fflush(stdin);
        scanf(" %c", &seguir);
    }
    return i;
}

///Punto 2
int retornarValorBuscado(int legajos[], int cantLeg, int valor) {
    int i = 0;

    for(i = 0; i < cantLeg; i++) {

        if(legajos[i] == valor) {
            return i;
        }
    }
    return 0;
}

///Punto 3
void buscarValorParalelo(int valor, int legajos[], int cantLeg, char nombres[20][30], int anios[]) {
    int i = 0;
    for(i = 0; i < cantLeg; i++) {

        if(i == valor) {
            printf("El nombre anclado a este legajo es: %s \n", &nombres[i]);
        }
    }
}

///Punto 4
void ordenamientoPorSeleccion(int legajos[], int cantLeg, char nombres[20][30], int anios[]) {
    for (int i = 0; i < cantLeg - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < cantLeg; j++) {
            if (strcmp(nombres[j], nombres[minIndex]) < 0) {
                minIndex = j;
            }
        }

        char temp[30];
        strcpy(temp, nombres[minIndex]);
        strcpy(nombres[minIndex], nombres[i]);
        strcpy(nombres[i], temp);
    }
}

void imprimirArreglo(char nombres[20][30], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s ", nombres[i]);
    }
    printf("\n");
}

///Punto 5
void mostrar(int legajos[], int cantLeg, char nombres[20][30], int anios[]) {
    int i = 0;

    for(i = 0; i < cantLeg; i++) {
        printf("\n");
        printf("Legajo: %d \n", legajos[i]);
        printf("Nombre: %s \n", nombres[i]);
        printf("Edad: %d \n", anios[i]);
        printf("\n\n");
    }
}

int main()
{
    //Simulacion de entidad alumno con arreglos paralelos
    int legajos[20];
    char nombres[20][30];
    int anios[20];

    ///Punto 1
    int validos = cargarAlumno(legajos, 20, nombres, anios);

    ///Punto 2
    int valor = 222;
    int rta2 = retornarValorBuscado(legajos, 20, valor);
    if(rta2 != 0) {
        printf("El valor buscado se encuentra en la posicion %d \n", rta2);
    }
    else {
        printf("No se encontro el valor buscado \n");
    }

    ///Punto 3
    buscarValorParalelo(rta2, legajos, 20, nombres, anios);

    ///Punto 4
    ordenamientoPorSeleccion(legajos, 20, nombres, anios);
    imprimirArreglo(nombres, 20);

    ///Punto 5
   // mostrar(legajos, validos, nombres, anios);

}
