#include <stdio.h>
#include <stdlib.h>

typedef struct {
int id;
char nombre [20];
char posicion [20];
int edad;
int puntosGanados;
} Jugador;

typedef struct {
char nombreEquipo[20];
int puntosGanados;
Jugador dato[25];
int valEquipo;
} Equipo;

/// Punto 1
int cargarJugador(Jugador arregloJugador[], int dim) {

    int i = 0;
    char seguir = 'n';

    printf("Ingrese s para cargar un jugador: \n");
    fflush(stdin);
    scanf("%c", &seguir);

    while(seguir == 's' && i < dim)
    {
        printf("Ingrese un ID: \n");
        fflush(stdin);
        scanf("%d", &arregloJugador[i].id);

        printf("Ingrese un nombre: \n");
        fflush(stdin);
        gets(arregloJugador[i].nombre);

        printf("Ingrese una posicion: \n");
        fflush(stdin);
        gets(arregloJugador[i].posicion);

        do {
        printf("Ingrese una edad: \n");
        fflush(stdin);
        scanf("%d", &arregloJugador[i].edad);

            if (arregloJugador[i].edad < 15 || arregloJugador[i].edad > 45) {
                printf("Ingrese una edad valida. \n");
            }
        } while (arregloJugador[i].edad < 15 || arregloJugador[i].edad > 45);

        printf("Ingrese los puntos ganados: \n");
        fflush(stdin);
        scanf("%d", &arregloJugador[i].puntosGanados);

        i++;

        printf("Ingrese s para continuar cargando: \n");
        fflush(stdin);
        scanf(" %c", &seguir);
    }

    return i;
}

int cargarEquipo(Equipo arregloEquipo[], int dim) {

    int i = 0;
    char seguir = 'n';

    printf("Ingrese s para cargar un equipo: \n");
    fflush(stdin);
    scanf("%c", &seguir);

    while(seguir == 's' && i < dim)
    {
        printf("Ingrese el nombre: \n");
        fflush(stdin);
        gets(arregloEquipo[i].nombreEquipo);

        printf("Ingrese los puntos ganados: \n");
        fflush(stdin);
        scanf("%d", &arregloEquipo[i].puntosGanados);

        printf("Ingrese un jugador: \n");
        fflush(stdin);
        gets(arregloEquipo[i].dato[0].nombre);

        printf("Ingrese el valor del equipo: \n");
        fflush(stdin);
        scanf("%d", &arregloEquipo[i].valEquipo);

        i++;

        printf("Ingrese s para continuar cargando: \n");
        fflush(stdin);
        scanf(" %c", &seguir);
    }

    return i;
}

///Punto 2
Equipo buscarGanador(Equipo arregloEquipo[], int validos) {

    Equipo ganador = arregloEquipo[0];

    for(int i = 1; i < validos; i++) {

        if(arregloEquipo[i].puntosGanados > ganador.puntosGanados) {
            ganador = arregloEquipo[i];
        }
    }

    return ganador;
}

///Punto 3
void copiarEquipos(Equipo arregloEquipo[], int validos, char archivoEquipo[]) {

    int i = 0;

    FILE *archi;
    archi = fopen("archivoEquipo.bin", "wb");

    if(archi != NULL) {

        while(i <= validos) {
            Equipo e = arregloEquipo[i];
            fwrite(&e, sizeof(Equipo), 1, archi);
            i++;
        }
    }
    else {
        printf("El archivo no puede ser abierto. \n");
    }
    fclose(archi);
}

///Punto 4

void mostrarJugadores(char archivoJugador[]) {

    Jugador j;

    FILE *archi;
    archi = fopen("archivoJugador.bin", "rb");

    if(archi != NULL) {

        while(!feof(archi)) {

            fread(&j, sizeof(Jugador), 1, archi);

            printf("ID: %d \n", j.id);
            printf("Nombre: %s \n", j.nombre);
            printf("Edad: %d \n", j.edad);
            printf("Posicion: %s \n", j.posicion);
            printf("Puntos ganados: %d \n", j.puntosGanados);
        }
    }
    else {
        printf("El archivo no puede ser abierto. \n");
    }
    fclose(archi);
}

void mostrarEquipos(int validos, char archivoEquipo[]) {

    Equipo e;
    Jugador j;

    FILE *archi;
    archi = fopen("archivoEquipo.bin", "rb");

    if(archi != NULL) {

        while(!feof(archi)) {
        fread(&e, sizeof(Equipo), 1, archi);

        printf("Nombre del equipo: %s \n", e.nombreEquipo);
        printf("Puntos ganados:    %d \n", e.puntosGanados);
        printf("Valor del equipo:  %d \n", e.valEquipo);
        printf("Jugadores: ");
            for(int i = 0; i < validos; i++) {

                if(e.dato == j.nombre) {
                    printf("%s \n", j.nombre);
                }
            }
        }
    }
    else {
        printf("El archivo no puede ser abierto. \n");
    }
    fclose(archi);
}

///Punto 5
int promedioEquipos(int equiposValidos, char archivoEquipo[]) {

    int suma = 0;
    Equipo e;

    FILE *archi;
    archi = fopen("archivoEquipo.bin", "rb");

    if(archi != NULL) {

        while(!feof(archi)) {
            fread(&e, sizeof(Equipo), 1, archi);
            suma = suma + e.valEquipo;
        }
    }
    else {
        printf("El archivo no puede ser abierto. \n");
    }

    fclose(archi);
    int rta = suma / equiposValidos;
    return rta;
}

int contarJugadoresRecursivo(Equipo seleccion, int i) {

    if(seleccion.dato[i].id == 0) {
        return i;
    }

    return contarJugadoresRecursivo(seleccion, i + 1);
}

int main()
{
    ///Punto 1
    Jugador arregloJugador[30];
    Equipo arregloEquipo[30];

    for (int i = 0; i < 30; i++) {
    arregloEquipo[i].puntosGanados = 0;
    }

    int jugadoresValidos = cargarJugador(arregloJugador, 30);
    int equiposValidos = cargarEquipo(arregloEquipo, 30);

    ///Punto 2
    Equipo rta2 = buscarGanador(arregloEquipo, equiposValidos);
    printf("El equipo ganador es %s con %d puntos obtenidos.\n", rta2.nombreEquipo, rta2.puntosGanados);

    ///Punto 3
    char archivoJugador[30] = {"archivoJugador.bin"};
    char archivoEquipo[30] = {"archivoEquipo.bin"};
    copiarEquipos(arregloEquipo, equiposValidos, archivoEquipo);

    ///Punto 4
    mostrarEquipos(equiposValidos, archivoEquipo);
    mostrarJugadores(archivoJugador);

    ///Punto 5
    int prom = promedioEquipos(equiposValidos, archivoEquipo);
    printf("El promedio es: %d \n", prom);

    ///Punto 6
    int i = 0;

    Jugador p1 = {1, "Federico", "central", 20, 13};
    Jugador p2 = {2, "Matias", "arquero", 22, 0};
    Jugador p3 = {3, "Jose", "mediocampista", 29, 22};

    Equipo seleccion = {"Seleccion Argentina", 3, {p1, p2, p3}, 430};

    int rta6 = contarJugadoresRecursivo(seleccion, i);
    printf("Existen %d jugadores cargados. \n", rta6);
}
