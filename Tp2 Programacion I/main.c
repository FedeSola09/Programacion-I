#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/// PUNTO 1
void cargar_pila()
{
    int aux;
    char seguir = 's';
    Pila pila;
    inicpila(&pila);

    while(seguir == 's') {
        printf("Ingrese un numero: \n");
        fflush(stdin);
        scanf("%i", &aux);
        apilar(&pila, aux);
        printf("Ingrese s para continuar, otra letra para finalizar: \n");
        fflush(stdin);
        scanf("%c", &seguir);
    }

    printf("La pila cargada quedo asi: \n");
    mostrar(&pila);
}

/// PUNTO 2
void pasar_pila() {
    Pila pila1;
    inicpila(&pila1);
    Pila pila2;
    inicpila(&pila2);

    apilar(&pila1, 1);
    apilar(&pila1, 2);
    apilar(&pila1, 3);

    printf("Pila 1: \n");
    mostrar(&pila1);
    printf("Pila 2: \n");
    mostrar(&pila2);

    printf("Ahora pasamos todos los elementos de la pila 1, a la pila 2 ");
    printf("y volvemos a mostrar las pilas para verificar \n\n");

    while(!pilavacia(&pila1)) {
        apilar(&pila2, tope(&pila1));
        desapilar(&pila1);
    }

    printf("Pila 1: \n");
    mostrar(&pila1);
    printf("Pila 2: \n");
    mostrar(&pila2);
}

/// PUNTO 3
void copiar_pila() {
    Pila pila1;
    inicpila(&pila1);
    Pila pila2;
    inicpila(&pila2);
    Pila aux;
    inicpila(&aux);

    apilar(&pila1, 1);
    apilar(&pila1, 2);
    apilar(&pila1, 3);

    printf("Pila 1: \n");
    mostrar(&pila1);
    printf("Pila aux: \n");
    mostrar(&aux);
    printf("Pila 2: \n");
    mostrar(&pila2);

    printf("Ahora pasamos todos los elementos de la pila 1, a la pila aux,  ");
    printf("y luego a la 2 para conservar el orden \n\n");

    while(!pilavacia(&pila1)) {
        apilar(&aux, tope(&pila1));
        desapilar(&pila1);
    }

    printf("Pila 1: \n");
    mostrar(&pila1);
    printf("Pila aux: \n");
    mostrar(&aux);
    printf("Pila 2: \n");
    mostrar(&pila2);

    while(!pilavacia(&aux)) {
        apilar(&pila2, tope(&aux));
        desapilar(&aux);
    }

    printf("Pila 1: \n");
    mostrar(&pila1);
    printf("Pila aux: \n");
    mostrar(&aux);
    printf("Pila 2: \n");
    mostrar(&pila2);
}

/// PUNTO 4


/// PUNTO 5


/// PUNTO 6


/// PUNTO 7


/// PUNTO 8
int sumar_topes() {
    int retorno = 0;

    Pila pila;
    Pila aux;
    inicpila(&pila);
    inicpila(&aux);
    apilar(&pila, 2);
    apilar(&pila, 2);
    apilar(&pila, 2);
    apilar(&pila, 2);

    for(int i = 0; i < 2; i++) {
        retorno = retorno + tope(&pila);
        apilar(&aux, desapilar(&pila));
    }

    if(!pilavacia(&aux)) {
        apilar(&pila, desapilar(&aux));
    }

    return retorno;
}

/// PUNTO 9
float hacer_suma(Pila *pilaPunto9, Pila *aux9) {
    float suma = 0;
    while(!pilavacia(pilaPunto9)) {
        suma = suma + tope(pilaPunto9);
        apilar(aux9, desapilar(pilaPunto9));
    }
    while (!pilavacia(aux9)) {
        apilar(pilaPunto9, desapilar(aux9));
    }
    return suma;
}

float hacer_calculo(Pila *pilaPunto9, Pila *aux9) {
    int contador = 0;
    while(!pilavacia(pilaPunto9)) {
        contador++;
        apilar(aux9, desapilar(pilaPunto9));
    }
    while (!pilavacia(aux9)) {
        apilar(pilaPunto9, desapilar(aux9));
    }
    return contador;
}

float hacer_div(float suma, float cantidad) {
    float division = 0;
    division = suma / cantidad;
    return division;
}

float hacer_promedio(Pila *pilaPunto9, Pila *aux9) {
    float suma = hacer_suma(pilaPunto9, aux9);
    float cantidad = hacer_calculo(pilaPunto9, aux9);
    float div = hacer_div(suma, cantidad);
    return div;
}

/// PUNTO 10
int concatenar_pila(Pila *pilaPunto10) {
    Pila aux;
    inicpila(&aux);
    int numero = 0;

    while (!pilavacia(pilaPunto10)) {
        apilar(&aux, desapilar(pilaPunto10));
    }
    while (!pilavacia(&aux)) {
        numero = numero * 10 + tope(&aux);
        apilar(pilaPunto10, desapilar(&aux));
    }
    return numero;
}

int main()
{
    //Variables generales
    int opcion = 0;
    int cortar = 0;

    //Variables punto 8
    int rta8 = sumar_topes();

    //Variables punto 9
    float rta_suma;
    float rta_cant;
    float rta_div;
    float rta_prom;
    Pila pilaPunto9;
    Pila aux9;
    inicpila(&pilaPunto9);
    inicpila(&aux9);
    apilar(&pilaPunto9, 3);
    apilar(&pilaPunto9, 3);
    apilar(&pilaPunto9, 2);

    //Variables punto 10
    Pila pilaPunto10;
    inicpila(&pilaPunto10);
    apilar(&pilaPunto10, 1);
    apilar(&pilaPunto10, 4);
    apilar(&pilaPunto10, 6);
    apilar(&pilaPunto10, 7);
    apilar(&pilaPunto10, 5);
    int rta10 = concatenar_pila(&pilaPunto10);

    printf("Ingrese 1 para cargar una pila. \n");
    printf("Ingrese 2 pasar una pila entera a otra. \n");
    printf("Ingrese 3 pasar una pila entera a otra conservando el orden. \n");
    printf("Ingrese 4 BLANK \n");
    printf("Ingrese 5 BLANK \n");
    printf("Ingrese 6 BLANK \n");
    printf("Ingrese 7 BLANK \n");
    printf("Ingrese 8 sumar los topes de una pila \n");
    printf("Ingrese 9 sacar un promedio de los elementos de una pila \n");
    printf("Ingrese 10 concatenar varios numeros en un solo decimal \n");
    printf("\n \t Respuesta --> ");

    fflush(stdin);
    scanf("%i", &opcion);
    printf("\n");

    do
    {
        switch(opcion)
        {

        /// PUNTO 1
        case 1:
            cargar_pila();
            break;

        /// PUNTO 2
        case 2:
            pasar_pila();
            break;

        /// PUNTO 3
        case 3:
            copiar_pila();
            break;


        /// PUNTO 4
        case 4:

            break;


        /// PUNTO 5
        case 5:

            break;


        /// PUNTO 6
        case 6:

            break;


        /// PUNTO 7
        case 7:

            break;

        /// PUNTO 8
        case 8:
            printf("LA SUMA ES %i \n", rta8);
            break;

        /// PUNTO 9
        case 9:
            rta_suma = hacer_suma(&pilaPunto9, &aux9);
            rta_cant = hacer_calculo(&pilaPunto9, &aux9);
            rta_div = hacer_div(rta_suma, rta_cant);
            rta_prom = hacer_promedio(&pilaPunto9, &aux9);
            printf("EL PROMEDIO ES %f \n", rta_prom);
            break;


        /// PUNTO 10
        case 10:
            printf("EL NUMERO CONCATENADO ES: %i \n", rta10);
            break;


        default:
            printf("Ingrese un valor correcto.");
            break;

        }

        printf("Ingrese 0 para continuar, otro numero para finalizar: \n");
        fflush(stdin);
        scanf("%i", &cortar);

    }
    while(cortar == 0);
}
