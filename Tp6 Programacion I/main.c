#include <stdio.h>
#include <stdlib.h>
#include "string.h"

typedef struct {
int matricula;
char nombre[30];
char genero;
}Alumno;

///Punto 1
int cargarAlumnos(Alumno estudiantes[], int dim) {
    char seguir = 's';
    int i = 0;

    while(seguir == 's' && i < dim) {
        printf("Ingrese una matricula: \n");
        fflush(stdin);
        scanf(" %d", &estudiantes[i].matricula);

        printf("Ingrese un nombre: \n");
        fflush(stdin);
        scanf(" %s", &estudiantes[i].nombre);

        printf("Ingrese el genero: \n");
        fflush(stdin);
        scanf(" %c", &estudiantes[i].genero);

        i++;

        printf("Ingrese s para continuar . . . \n");
        fflush(stdin);
        scanf(" %c", &seguir);
    }
    return i;
}

///Punto 2
void mostrarEstudiantes(Alumno estudiantes[], int validos) {
    int i = 0;

    for(i = 0; i < validos; i++) {
        printf("Matricula: %d \n", estudiantes[i].matricula);
        printf("Nombre: %s \n", estudiantes[i].nombre);
        printf("Genero: %c \n", estudiantes[i].genero);
        printf("\n");
    }
}

///Punto 3
void buscarPorMatricula(Alumno estudiantes[], int validos, int tuition) {
    for(int i = 0; i < validos; i++) {

        printf("MATRICULADA ENCONTRADA! \nDATOS DE LA MISMA: \n\n");
        if(estudiantes[i].matricula == tuition) {
            printf("Matricula: %d \n", estudiantes[i].matricula);
            printf("Nombre: %s \n", estudiantes[i].nombre);
            printf("Genero: %c \n", estudiantes[i].genero);
            printf("\n");
        }
    }
}

///Punto 4
void ordenamientoPorSeleccion(Alumno estudiantes[], int validos) {
    for (int i = 0; i < validos - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < validos; j++) {
            if (estudiantes[j].matricula < estudiantes[minIndex].matricula) {
                minIndex = j;
            }
        }

        Alumno temp = estudiantes[minIndex];
        estudiantes[minIndex] = estudiantes[i];
        estudiantes[i] = temp;
    }
}

void imprimirArreglo(Alumno estudiantes[], int validos) {
    for (int i = 0; i < validos; i++) {
        printf("%d ", estudiantes[i].matricula);
    }
    printf("\n");
}

///Punto 5
void buscarPorGenero(Alumno estudiantes[], int validos, char genre) {
    for(int i = 0; i < validos; i++) {

        printf("FILTRADO POR GENERO: \n\n");
        if(estudiantes[i].genero == genre) {
            printf("Matricula: %d \n", estudiantes[i].matricula);
            printf("Nombre: %s \n", estudiantes[i].nombre);
            printf("Genero: %c \n", estudiantes[i].genero);
            printf("\n");
        }
    }
}

///Punto 6
void cargarNuevoAlumno(Alumno *nuevoAlumno) {
    printf("Ingrese una matricula: \n");
    fflush(stdin);
    scanf(" %d", &nuevoAlumno->matricula);

    printf("Ingrese un nombre: \n");
    fflush(stdin);
    scanf(" %s", &nuevoAlumno->nombre);

    printf("Ingrese el genero: \n");
    fflush(stdin);
    scanf(" %c", &nuevoAlumno->genero);
}

void insertarNuevoAlumno(Alumno estudiantes[], int *validos, Alumno nuevoAlumno) {
    if (*validos < 20) {
        estudiantes[*validos] = nuevoAlumno;
        (*validos)++;
        ordenamientoPorSeleccion(estudiantes, *validos);
        imprimirArreglo(estudiantes, *validos);
    }
}

///Punto 7
void ordenamientoPorInsercion(Alumno estudiantes[], int validos) {
    for (int i = 1; i < validos; i++) {
        Alumno clave = estudiantes[i];
        int j = i - 1;

        while (j >= 0 && strcmp(estudiantes[j].nombre, clave.nombre) > 0) {
            estudiantes[j + 1] = estudiantes[j];
            j--;
        }

        estudiantes[j + 1] = clave;
    }
}

void imprimirArreglo2(Alumno estudiantes[], int validos) {
    for (int i = 0; i < validos; i++) {
        printf("%s \n", estudiantes[i].nombre);
    }
    printf("\n");
}

///Punto 8
int contarPorGenero(Alumno estudiantes[], int validos, char genre2) {
    int contador = 0;
    for(int i = 0; i < validos; i++) {

        if(estudiantes[i].genero == genre2) {
            contador++;
        }
    }
    return contador;
}

int main()
{

    ///Punto 1
    Alumno estudiantes[20];
    int validos = cargarAlumnos(estudiantes, 20);

    ///Punto 3
    int tuition = 321;

    ///Punto 5
    char genre = 'm';

    ///Punto 6
    Alumno nuevoAlumno;

    ///Punto 8
    char genre2 = 'm';
    int rta8 = contarPorGenero(estudiantes, validos, genre2);

    ///Punto 9
    int opcion = 0;
    printf("Ingrese 1 para acceder al punto 1 \n");
    printf("Ingrese 2 para acceder al punto 2 \n");
    printf("Ingrese 3 para acceder al punto 3 \n");
    printf("Ingrese 4 para acceder al punto 4 \n");
    printf("Ingrese 5 para acceder al punto 5 \n");
    printf("Ingrese 6 para acceder al punto 6 \n");
    printf("Ingrese 7 para acceder al punto 7 \n");
    printf("Ingrese 8 para acceder al punto 8 \n");

    switch(opcion) {

    case 1:
        cargarAlumnos(estudiantes, 20);
        break;

    case 2:
        mostrarEstudiantes(estudiantes, validos);
        break;

    case 3:
        buscarPorMatricula(estudiantes, validos, tuition);
        break;

    case 4:
        ordenamientoPorSeleccion(estudiantes, validos);
        printf("Arreglo ordenado: \n");
        imprimirArreglo(estudiantes, validos);
        break;

    case 5:
        buscarPorGenero(estudiantes, validos, genre);
        break;

    case 6:
        cargarNuevoAlumno(&nuevoAlumno);
        insertarNuevoAlumno(estudiantes, &validos, nuevoAlumno);
        break;

    case 7:
        ordenamientoPorInsercion(estudiantes, validos);
        printf("Arreglo ordenado: ");
        imprimirArreglo2(estudiantes, validos);
        break;

    case 8:
        contarPorGenero(estudiantes, validos, genre2);
        printf("Existen %d alumnos del genero seleccionado \n", rta8);
        break;
    }
}

