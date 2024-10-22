#ifndef INVENTARIO_H
#define INVENTARIO_H

//  En este apartado .h declaramos las funciones
int ingresarProductos(char productos[10][50], float precios[10], int numProductos);
float calcularTotal(float precios[10], int numProductos);
int encontrarMasCaro(float precios[10], int numProductos);
int encontrarMasBarato(float precios[10], int numProductos);
float calcularPromedio(float precios[10], int numProductos);
int buscarProducto(char productos[10][50], int numProductos, char nombreBuscado[50]);

#endif
 