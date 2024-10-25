#include <stdio.h>
#include <string.h>
#include "funciones.h"

#include <stdio.h>
#include <string.h>
#include "funciones.h"

int ingresarProductos(char productos[10][50], float precios[10], int numProductos) {

     do {
        printf("Cuantos productos desea ingresar? (Maximo 10): ");
        scanf("%d", &numProductos);
        if (numProductos <= 0 || numProductos > 10 || numProductos > 20) {
            printf("Numero de productos no valido. Ingrese un numero entre 1 y 10.\n");
        }
    } while (numProductos <= 0 || numProductos > 10);

    // Limpiar el búfer de entrada después de scanf
    while (getchar() != '\n');

    for (int i = 0; i < numProductos; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        fgets(productos[i], 50, stdin); // Leer el nombre del producto con espacios
        productos[i][strcspn(productos[i], "\n")] = 0; // Eliminar el salto de línea

        do {
            printf("Ingrese el precio del producto %d: ", i + 1);
            scanf("%f", &precios[i]);
            if (precios[i] < 0) { // Verificar si el precio es negativo
                printf("El precio no puede ser negativo. Intente nuevamente.\n");
            }
            // Limpiar el búfer de entrada antes de la siguiente iteración
            while (getchar() != '\n'); 
        } while (precios[i] < 0); // Validar el precio nuevamente
    }
    
    return 0; // Éxito
}


float calcularTotal(float precios[10], int numProductos) {
    float total = 0;
    for (int i = 0; i < numProductos; i++) {
        total += precios[i];
    }
    return total;
}

int encontrarMasCaro(float precios[10], int numProductos) {
    int indiceMasCaro = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] > precios[indiceMasCaro]) {
            indiceMasCaro = i;
        }
    }
    return indiceMasCaro; //regresa el mas caro
}

int encontrarMasBarato(float precios[10], int numProductos) {
    int indiceMasBarato = 0;
    for (int i = 1; i < numProductos; i++) {
        if (precios[i] < precios[indiceMasBarato]) {
            indiceMasBarato = i;
        }
    }
    return indiceMasBarato;
}

float calcularPromedio(float precios[10], int numProductos) {
    float total = calcularTotal(precios, numProductos);
    return total / numProductos;
}

int buscarProducto(char productos[10][50], int numProductos, char nombreBuscado[50]) {
    for (int i = 0; i < numProductos; i++) {
        if (strcmp(productos[i], nombreBuscado) == 0) {
            return i;
        }
    }
    return -1; // Producto no encontrado
}
