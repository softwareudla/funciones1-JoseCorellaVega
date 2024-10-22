#include <stdio.h>
#include <string.h>
#include "funciones.h"

int ingresarProductos(char productos[10][50], float precios[10], int numProductos) {
    if (numProductos <= 0 || numProductos > 10) {
        return -1; // Error en la cantidad de productos
    }
    for (int i = 0; i < numProductos; i++) {
        printf("Ingrese el nombre del producto %d: ", i + 1);
        fgets(productos[i], 50, stdin); // Leer el nombre del producto con espacios
        productos[i][strcspn(productos[i], "\n")] = 0; // Eliminar el salto de línea

        do {
            printf("Ingrese el precio del producto %d: ", i + 1);
            scanf("%f", &precios[i]);
            if (precios[i] < 0) { // Cambiar precios a precios[i]
                printf("El precio no puede ser negativo. Intente nuevamente.\n");
            }
        } while (precios[i] < 0); // Cambiar precios a precios[i]
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
    return indiceMasCaro;
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
