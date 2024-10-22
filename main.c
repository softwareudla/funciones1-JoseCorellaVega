#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main() {
    char productos[10][50]; // Arreglo de nombres de productos
    float precios[10];      // Arreglo de precios de productos
    int numProductos = 0, indice;
    char nombreBuscado[50];

    // Imprimir un mensaje para solicitar el número de productos a ingresar
    printf("¿Cuantos productos desea ingresar (maximo 10)? ");
    scanf("%d", &numProductos);
    getchar(); 
    if (numProductos > 10) numProductos = 10;

    
    ingresarProductos(productos, precios, numProductos);

    // Mostramos el total del inventario con los valores y datos ingresados
    printf("\nEl precio total del inventario es: %.2f\n", calcularTotal(precios, numProductos));

    
    indice = encontrarMasCaro(precios, numProductos);
    printf("El producto mas caro es: %s con un precio de %.2f\n", productos[indice], precios[indice]);

    indice = encontrarMasBarato(precios, numProductos);
    printf("El producto mas barato es: %s con un precio de %.2f\n", productos[indice], precios[indice]);

    // Mostraramos el precio promedio de todo
    printf("El precio promedio es: %.2f\n", calcularPromedio(precios, numProductos));

    // Buscar un producto por nombre en el inventario ingresado
    printf("\nIngrese el nombre del producto a buscar: ");
    fgets(nombreBuscado, 50, stdin);
    nombreBuscado[strcspn(nombreBuscado, "\n")] = 0; 
    indice = buscarProducto(productos, numProductos, nombreBuscado);
    if (indice != -1) {
        printf("El precio de %s es: %.2f\n", productos[indice], precios[indice]);
    } else {
        printf("Producto no encontrado.\n");
    }

    return 0;
}
