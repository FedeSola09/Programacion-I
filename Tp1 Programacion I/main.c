#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// Punto 1 //*
int devolver_random() {
    int numero;
    srand(time(NULL));
	numero = rand() % 100;
	return numero;
}

/// Punto 2 //*
int mostrar_mayor_y_menor(int num1, int num2, int num3) {
    if((num1 < num2) && (num1 < num3)) {
        printf("EL MENOR NUMERO ES: %i \n", num1);
    }
    else if((num2 < num1) && (num2 < num3)) {
        printf("EL MENOR NUMERO ES: %i \n", num2);
    }
    else {
        printf("EL MENOR NUMERO ES: %i \n", num3);
    }

    if((num1 > num2) && (num1 > num3)) {
        printf("EL MAYOR NUMERO ES: %i \n", num1);
    }
    else if((num2 > num1) && (num2 > num3)) {
        printf("EL MAYOR NUMERO ES: %i \n", num2);
    }
    else {
        printf("EL MAYOR NUMERO ES: %i \n", num3);
    }
}

/// Punto 3 //*
int sumar_anteriores(int numN) {
    int menos1 = numN - 1;
    int menos2 = numN - 2;
    int rta = menos1 + menos2;
    return rta;
}

/// Punto 4 //*
int tabla_multiplicar(int multiplicado) {
    int rta = 1;
    for(int i = 1; i < 11; i++) {
        rta = multiplicado * i;
        printf("%i x %i = %i \n", multiplicado, i, rta);
    }
}

/// Punto 5 //*
float calculadora(float numero1, float numero2) {
    int opcion = 0;
    float rta = 0;
    printf("Ingrese 1 para sumar. \n");
    printf("\n Ingrese 2 para restar. \n");
    printf("\n Ingrese 3 para multiplicar. \n");
    printf("\n Ingrese 4 para dividir. \n\n");
    scanf("%i", &opcion);

    switch(opcion) {
    case 1:
        rta = numero1 + numero2;
        break;

    case 2:
        rta = numero1 - numero2;
        break;

    case 3:
        rta = numero1 * numero2;
        break;

    case 4:
        rta = numero1 / numero2;
        break;

    default:
        printf("Ingrese un numero valido.");
        break;
    }
    return rta;
}

/// Punto 6 //*
int negar_num(int *numero) {
    int rta = *numero * (-1);
    return rta;
}

/// Punto 7 //*
int cargar_numeros(int *numeroUno, int *numeroDos) {
    printf("Ingrese un valor para el primer numero: ");
    scanf("%i", &numeroUno);
    printf("Ingrese un valor para el segundo numero: ");
    scanf("%i", &numeroDos);
    printf("numeroUno = %i \n", numeroUno);
    printf("numeroDos = %i \n", numeroDos);
}

/// MAIN //*
int main()
{
    /// Punto 1 //*
    int rta1 = devolver_random();
    printf("PUNTO 1 -------------------------------- \n\n");
    printf("EL NUMERO RANDOM ELEGIDO ES: %i \n", rta1);

    /// Punto 2 //*
    int num1 = 73;
    int num2 = 11;
    int num3 = 3;
    printf("\nPUNTO 2 -------------------------------- \n\n");
    int rta2 = mostrar_mayor_y_menor(num1, num2, num3);

    /// Punto 3 //*
    printf("\nPUNTO 3 -------------------------------- \n\n");
    int numN;
    printf("Ingrese un numero: ");
    scanf("%i", &numN);
    int rta3 = sumar_anteriores(numN);
    printf("LA SUMA DE LOS DOS ANTERIORES DE %i ES: %i \n", numN, rta3);

    /// Punto 4 //*
    printf("\nPUNTO 4 -------------------------------- \n\n");
    int multiplicado;
    printf("Ingrese un numero: ");
    scanf("%i", &multiplicado);
    tabla_multiplicar(multiplicado);

    /// Punto 5 //*
    printf("\nPUNTO 5 -------------------------------- \n\n");
    float numero1 = 0;
    float numero2 = 0;
    printf("Ingrese el primer numero: \n");
    scanf("%i", &numero1);
    printf("Ingrese el segundo numero: \n");
    scanf("%i", &numero2);
    float rta5 = calculadora(numero1, numero2);
    printf("\n RESPUESTA = %i", rta5);

    /// Punto 6 //*
    printf("\nPUNTO 6 -------------------------------- \n\n");
    int numero = 5;
    int rta6 = negar_num(&numero);
    printf("Numero original = %i \n", numero);
    printf("Numero negado = %i \n", rta6);

    /// Punto 7 //*
    int numeroUno;
    int numeroDos;
    cargar_numeros(&numeroUno, &numeroDos);
}


