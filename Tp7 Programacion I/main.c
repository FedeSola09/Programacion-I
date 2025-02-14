
#include <stdio.h>
#include <stdlib.h>
#include "string.h"

///Punto 1
void cargarElemento(char archivo[])
{
    int num = 9;

    FILE *archi;
    archi = fopen("archivo.bin", "ab");
    if(archi != NULL)
    {
        fwrite(&num, sizeof(int), 1, archi);
    }
    else
    {
        printf("El archivo no puede ser abierto.");
    }
    fclose(archi);
}

///Punto 2
void mostrarElemento(char archivo[])
{
    int num;

    FILE *archi;
    archi = fopen("archivo.bin", "rb");
    if(archi != NULL)
    {
        fread(&num, sizeof(int), 1, archi);
        printf("Dato: %d \n", num);
    }
    else
    {
        printf("El archivo no puede ser abierto.");
    }
    fclose(archi);
}

///Punto 3
int contarElemento(char archivo[])
{
    int num;
    int contador = 0;

    FILE *archi;
    archi = fopen("archivo.bin", "rb");
    if(archi != NULL)
    {
        fread(&num, sizeof(int), 1, archi);
        contador++;
    }
    else
    {
        printf("El archivo no puede ser abierto.");
    }
    fclose(archi);

    return contador;
}

typedef struct
{
    char nombreYapellido[30];
    int edad;
    int anio;
} Alumno;

///Punto 4
void cargarAlumno(char archive[])
{
    char seguir = 'n';
    Alumno estudiante;

    FILE *archi;
    archi = fopen("alumnos.bin", "wb");
    if(archi != NULL)
    {

        printf("Ingrese s para cargar alumnos: \n");
        fflush(stdin);
        scanf(" %c", &seguir);

        while(seguir == 's')
        {
            puts("----------------------------------- \n");
            printf("Ingrese un nombre y apellido: \n");
            fflush(stdin);
            gets(&estudiante.nombreYapellido);

            printf("Ingrese la edad: \n");
            fflush(stdin);
            scanf(" %d", &estudiante.edad);

            printf("Ingrese el anio de nacimiento: \n");
            fflush(stdin);
            scanf(" %d", &estudiante.anio);
            puts("----------------------------------- \n");

            fwrite(&estudiante, sizeof(Alumno), 1, archi);

            printf("Ingrese s para continuar: \n");
            fflush(stdin);
            scanf(" %c", &seguir);
        }

    }
    else
    {
        printf("El archivo no puede ser abierto.");
    }
    fclose(archi);
}

///Punto 5
void mostrar(Alumno estudiante)
{
    puts("-------------------------------------------- \n");
    printf("Nombre y apellido:  %s \n", estudiante.nombreYapellido);
    printf("Edad:               %d \n", estudiante.edad);
    printf("Anio de nacimiento: %d \n", estudiante.anio);
    puts("-------------------------------------------- \n");
}

void mostrarAlumno(char archive)
{

    FILE *archi;
    Alumno estudiante;
    archi = fopen("alumnos.bin", "rb");

    if(archi != NULL)
    {

        while(!feof(archi))
        {
            fread(&estudiante, sizeof(Alumno), 1, archi);
            if(!feof(archi))
            {
                mostrar(estudiante);
            }
        }
    }
    else
    {
        printf("El archivo no puede ser abierto.");
    }
    fclose(archi);
}

///Punto 6
void cargarAlumno_eof(char archive[])
{
    Alumno estudiante;

    FILE *archi;
    archi = fopen("alumnos.bin", "ab");
    if(archi != NULL)
    {

        puts("----------------------------------- \n");
        printf("Ingrese un nombre y apellido: \n");
        fflush(stdin);
        gets(&estudiante.nombreYapellido);

        printf("Ingrese la edad: \n");
        fflush(stdin);
        scanf(" %d", &estudiante.edad);

        printf("Ingrese el anio de nacimiento: \n");
        fflush(stdin);
        scanf(" %d", &estudiante.anio);
        puts("----------------------------------- \n");

        fwrite(&estudiante, sizeof(Alumno), 1, archi);
    }
    else
    {
        printf("El archivo no puede ser abierto.");
    }
    fclose(archi);
}

///Punto 7
//int cargarPila(Pila *pila, char archive[]) {
//    inicpila(pila);
//    int mayorEdad = 18;
//    int aux = 0;
//    Alumno estudiante;
//
//    FILE *archi;
//    archi = fopen("alumnos.bin", "rb");
//
//    if(archi != NULL) {
//
//        while(!feof(archi)) {
//            fread(&estudiante, sizeof(Alumno), 1, archi);
//
//            if(estudiante.edad > 18) {
//                aux = estudiante.anio;
//                apilar(pila, aux);
//            }
//        }
//    }
//    else {
//        printf("El archivo no puede ser abierto.");
//    }
//    fclose(archi);
//    mostrar(pila);
//}

///Punto 8
int verificarEdad(int edad, char archive[])
{
    int contador = 0;
    Alumno estudiante;

    FILE *archi;
    archi = fopen("alumnos.bin", "rb");

    if(archi != NULL)
    {

        while(!feof(archi))
        {
            fread(&estudiante, sizeof(Alumno), 1, archi);

            if(estudiante.edad > edad)
            {
                contador++;
            }
        }
    }
    else
    {
        printf("El archivo no puede ser abierto.");
    }
    fclose(archi);

    return contador;
}

///Punto 9
int rangoDeEdad(int edadMin, int edadMax, char archive[])
{
    int contador = 0;
    Alumno estudiante;

    FILE *archi;
    archi = fopen("alumnos.bin", "rb");

    if(archi != NULL)
    {

        while(!feof(archi))
        {
            fread(&estudiante, sizeof(Alumno), 1, archi);

            if((estudiante.edad < edadMax) && (estudiante.edad > edadMin))
            {
                contador++;
            }
        }
    }
    else
    {
        printf("El archivo no puede ser abierto.");
    }
    fclose(archi);

    return contador;
}

///Punto 10
int mostrarMayor(char archive[])
{
    Alumno estudiante;
    int mayor = 0;

    FILE *archi;
    archi = fopen("alumnos.bin", "rb");

    if(archi != NULL)
    {

        while(!feof(archi))
        {
            fread(&estudiante, sizeof(Alumno), 1, archi);

            if(estudiante.edad > mayor)
            {
                mayor = estudiante.edad;
            }
        }
    }
    else
    {
        printf("El archivo no puede ser abierto.");
    }
    fclose(archi);

    return mayor;
}

///Punto 11
int filtrarXanio(int anioBuscado, char archive[])
{
    int contador = 0;
    Alumno estudiante;

    FILE *archi;
    archi = fopen("alumnos.bin", "rb");

    if(archi != NULL)
    {

        while(!feof(archi))
        {
            fread(&estudiante, sizeof(Alumno), 1, archi);

            if(estudiante.anio == anioBuscado)
            {
                contador++;
            }
        }
    }
    else
    {
        printf("El archivo no puede ser abierto.");
    }

    fclose(archi);
    return contador;
}

///Punto 12
void cargarCurso(Alumno curso[], int dim, char archive[])
{

    FILE *archi;
    archi = fopen("alumnos.bin", "ab");

    if(archi != NULL)
    {
        fwrite(curso, sizeof(Alumno), dim, archi);
    }
    else
    {
        printf("El archivo no puede ser abierto.");
    }

    fclose(archi);
}

void descargarCurso(Alumno aula[], int dim, char archive[])
{

    FILE *archi;
    archi = fopen("alumnos.bin", "rb");

    if(archi != NULL)
    {
        int i = 0;
        Alumno estudiante;

        while (i < dim && fread(&estudiante, sizeof(Alumno), 1, archi) == 1)
        {
            if (estudiante.anio != 2003)
            {
                aula[i] = estudiante;
                i++;
            }
        }

        fclose(archi);
    }
    else
    {
        printf("El archivo no puede ser abierto.\n");
    }
}

void mostrarArreglo(Alumno aula[], int dim)
{
    for(int i = 0; i < dim; i++)
    {
        printf("Nombre y apellido:  %s \n", aula[i].nombreYapellido);
        printf("Edad:               %d \n", aula[i].edad);
        printf("Anio de nacimiento: %d \n", aula[i].anio);
        printf("\n");
    }
}

///Punto 13
int contarAlumnos(char archive[])
{
    int rta = 0;
    Alumno estudiante;

    FILE *archi;
    archi = fopen("alumnos.bin", "rb");

    if(archi != NULL)
    {
        fseek(archi, 0, SEEK_SET);

        while(!feof(archi))
        {
            fread(&estudiante, sizeof(Alumno), 1, archi);
        }
    }
    else
    {
        printf("No es posible abrir el archivo.");
    }

    rta = ftell(archi);
    fclose(archi);
    return rta / sizeof(Alumno);
}

///Punto 14
void mostrarPosicion(int posicion, char archive[])
{
    Alumno estudiante;
    int contador = 0;

    FILE *archi;
    archi = fopen("alumnos.bin", "rb");

    if(archi != NULL)
    {

        while(!feof(archi))
        {
            fread(&estudiante, sizeof(Alumno), 1, archi);
            contador++;

            if(contador == posicion)
            {
                mostrar(estudiante);
            }
        }
    }
    else
    {
        printf("El archivo no puede ser abierto.\n");
    }

    fclose(archi);
}

///Punto 15
void modificarAlumno(char *nombre, char archive[]) {

    FILE *archi = fopen;
    archi = fopen("alumnos.bin", "r+b");

    if (archi != NULL) {

    Alumno estudiante;
    int encontrado = 0;

    while (fread(&estudiante, sizeof(Alumno), 1, archi)) {
        if (strcmp(estudiante.nombreYapellido, nombre) == 0) {
            encontrado = 1;
            fseek(archi, -sizeof(Alumno), SEEK_CUR);

            int opcion;
            do {
                printf("Ingrese 1 para modificar el nombre: \n");
                printf("Ingrese 2 para modificar la edad: \n");
                printf("Ingrese 3 para modificar el anio: \n");
                printf("Ingrese 4 para salir: \n");

                scanf("%d", &opcion);
                fflush(stdin);

                switch (opcion) {
                    case 1:
                        printf("Ingrese el nuevo nombre: ");
                        fgets(estudiante.nombreYapellido, sizeof(estudiante.nombreYapellido), stdin);
                        estudiante.nombreYapellido[strcspn(estudiante.nombreYapellido, "\n")] = 0;
                        break;
                    case 2:
                        printf("Ingrese la nueva edad: ");
                        scanf("%d", &estudiante.edad);
                        fflush(stdin);
                        break;
                    case 3:
                        printf("Ingrese el nuevo año: ");
                        scanf("%d", &estudiante.anio);
                        fflush(stdin);
                        break;
                    case 4:
                        printf("Saliendo...\n");
                        break;
                    default:
                        printf("Opción inválida.\n");
                }

                fwrite(&estudiante, sizeof(Alumno), 1, archi);
                fseek(archi, 0, SEEK_CUR);

            } while (opcion != 4);

            break;
        }
    }

    }
    else {
        printf("El archivo no puede ser abierto.\n");
    }

    fclose(archi);
}

int main()
{
    char archivo[30] = {"archivo.bin"};
    char archive[30] = {"alumnos.bin"};

        ///Punto 1
        cargarElemento(archivo);

        ///Punto 2
        mostrarElemento(archivo);

        ///Punto 3
        int rta3 = contarElemento(archivo);
        printf("Existen %d registros \n", rta3);

    ///Punto 4
    //cargarAlumno(archive);

    ///Punto 5
    printf("PUNTO 5: \n");
    mostrarAlumno(archive);

    ///Punto 6
    printf("PUNTO 6: \n");
    cargarAlumno_eof(archive);
    mostrarAlumno(archive);

    ///Punto 7
    // NO CREE LA VARIABLE LEGAJO DESDE UN PRINCIPIO (NO LA VI EN LA GUIA) POR LO QUE GUARDO LOS AÑOS PARA NO TENER QUE MODIFICAR TODA LA GUIA DE 0
    printf("PUNTO 7: \n");
    Pila pila;
    cargarPila(&pila, archive);

    ///Punto 8
    printf("PUNTO 8: \n");
    int edad = 18;
    int rta8 = verificarEdad(edad, archive);
    printf("Existen %d alumnos mayores a esa edad. \n", rta8);

    ///Punto 9
    printf("PUNTO 9: \n");
    int edadMin = 17;
    int edadMax = 25;
    int rta9 = rangoDeEdad(edadMin, edadMax, archive);
    printf("Existen %d alumnos entre las edades ingresadas. \n", rta9);

    ///Punto 10
    printf("PUNTO 10: \n");
    int rta10 = mostrarMayor(archive);
    printf("El mayor de edad tiene %d años \n", rta10);

    ///Punto 11
    printf("PUNTO 11: \n");
    int anioBuscado = 2004;
    int rta11 = filtrarXanio(anioBuscado, archive);
    printf("Se encontraron %d alumnos del año buscado. \n", rta11);

    ///Punto 12
    printf("PUNTO 12: \n");
    Alumno curso[5] = {
        {"Juan Perez", 20, 2003},
        {"Maria Gomez", 22, 2002},
        {"Carlos Lopez", 19, 2004},
        {"Ana Martinez", 21, 2003},
        {"Luis Fernandez", 23, 2001}
    };

    cargarCurso(curso, 5, archive);
    mostrarAlumno(archive);

    printf("PUNTO 12B: \n");
    Alumno aula[5];
    descargarCurso(aula, 5, archive);
    mostrarArreglo(aula, 5);

    ///Punto 13
    int rta13 = contarAlumnos(archive);
    printf("Estan cargados %d registros \n", rta13);

    ///Punto 14
    int posicion = 4;
    mostrarPosicion(posicion, archive);

    ///Punto 15
    char nombre[10];
    printf("Ingrese el nombre del alumno a modificar: \n");
    fflush(stdin);
    gets(&nombre);
    modificarAlumno(&nombre, archive);
    mostrarAlumno(archive);

    ///Punto 16



}
