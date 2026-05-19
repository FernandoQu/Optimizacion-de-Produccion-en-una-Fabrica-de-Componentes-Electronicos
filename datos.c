#include <stdio.h>
#include "datos.h"
#include "validaciones.h"

void ingresarProducto(char nombres[][30], int tiempos[], int recursos[], int cantidades[], int indiceActual) {
    char nombreTemporal[30];
    int nombreValido = 0;

    printf("Datos del producto %d\n", indiceActual + 1);
    
    do {
        printf("Ingrese el nombre del producto: \n");
        scanf("%s", nombreTemporal); 
        while (getchar() != '\n');

        if (validarLongitud(nombreTemporal) == 0) {
            printf("El nombre debe tener entre 2 y 30 letras\n");
        } else if (esSoloLetras(nombreTemporal) == 0) {
            printf("El nombre solo debe contener letras\n");
        } else if (existeProducto(nombreTemporal, nombres) == 1) {
            printf("El producto ya existe\n");
        } else {
            nombreValido = 1;
        }

    } while (nombreValido == 0);

    int j = 0;
    while (nombreTemporal[j] != '\0') {
        nombres[indiceActual][j] = nombreTemporal[j];
        j++;
    }
    nombres[indiceActual][j] = '\0';
    
    printf("Ingrese el tiempo unitario de fabricacion: \n");
    tiempos[indiceActual] = pedirEnteroValido();
    
    printf("Ingrese los recursos unitarios necesarios: \n");
    recursos[indiceActual] = pedirEnteroValido();
    
    printf("Ingrese la cantidad demandada: \n");
    cantidades[indiceActual] = pedirEnteroValido();
}