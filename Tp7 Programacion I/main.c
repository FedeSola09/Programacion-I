#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    char archivo[30] = {"archivo.bin"};
    char archive[30] = {"alumnos.bin"};
    /*
        ///Punto 1
        cargarElemento(archivo);

        ///Punto 2
        mostrarElemento(archivo);

        ///Punto 3
        int rta3 = contarElemento(archivo);
        printf("Existen %d registros \n", rta3);
    */
    ///Punto 4
    cargarAlumno(archive);

    ///Punto 5
    printf("PUNTO 5: \n");
    mostrarAlumno(archive);

    ///Punto 6
    printf("PUNTO 6: \n");
    cargarAlumno_eof(archive);
    mostrarAlumno(archive);

    ///Punto 7

    ///Punto 8

    ///Punto 9

    ///Punto 10

    ///Punto 11

    ///Punto 12

    ///Punto 13

    ///Punto 14

    ///Punto 15

    ///Punto 16

    ///Punto 17


}
