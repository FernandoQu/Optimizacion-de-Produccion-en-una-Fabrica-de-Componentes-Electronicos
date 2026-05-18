#include <stdio.h>

void ingresarProducto(char nombres[][50], int tiempos[], int recursos[], int cantidades[], int indiceActual) {
    
    printf("Datos del producto%d\n", indiceActual + 1);
    
    printf("Ingrese el nombre del producto: \n");
    scanf("%s", nombres[indiceActual]); 
    
    printf("Ingrese el tiempo unitario de fabricacion: \n");
    scanf("%d", &tiempos[indiceActual]);
    
    printf("Ingrese los recursos unitarios necesarios: \n");
    scanf("%d", &recursos[indiceActual]);
    
    printf("Ingrese la cantidad demandada: \n");
    scanf("%d", &cantidades[indiceActual]);
}