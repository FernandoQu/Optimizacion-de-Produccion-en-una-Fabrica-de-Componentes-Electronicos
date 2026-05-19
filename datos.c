#include <stdio.h>
#include "datos.h"
#include "validaciones.h"

int desplegarMenu(){
    int opcion;
    printf("Menu\n");
    printf("1. Ingresar Producto\n");
    printf("2. Editar Producto\n");
    printf("3. Eliminar Producto\n");
    printf("4. Ver Estado de Produccion\n");
    printf("5. Salir\n");
    printf("Seleccione una opcion: \n");
    opcion = pedirEnteroValido();
    return opcion;
}
int limiteDeTiempo(){
    int tiempo;
    printf("Ingrese el disponible tiempo (Dias) de fabricacion: \n");
    tiempo = pedirEnteroValido();
    return tiempo;
}

int limiteDeRecursos(){
    int recursos;
    printf("Ingrese los recursos disponibles necesarios: \n");
    recursos = pedirEnteroValido();
    return recursos;
}
void ingresarProducto(char nombres[][30], int tiempos[], int recursos[], int cantidades[], int indiceActual, int tiempoLimite, int recursosLimite) {
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
    
    do {
        printf("Ingrese el tiempo unitario de fabricacion: \n");
        tiempos[indiceActual] = pedirEnteroValido();
        if (tiempos[indiceActual] > tiempoLimite) {
            printf("El tiempo unitario excede el limite de la fabrica\n");
        }
    } while (tiempos[indiceActual] > tiempoLimite);
    
    do {
        printf("Ingrese los recursos unitarios necesarios: \n");
        recursos[indiceActual] = pedirEnteroValido();
        if (recursos[indiceActual] > recursosLimite) {
            printf("Los recursos unitarios exceden el limite de la fabrica\n");
        }
    } while (recursos[indiceActual] > recursosLimite);
    
    printf("Ingrese la cantidad demandada: \n");
    cantidades[indiceActual] = pedirEnteroValido();
}

void editarProducto(int tiempos[], int recursos[], int cantidades[], int indiceEncontrado, int tiempoLimite, int recursosLimite) {
    do {
        printf("Ingrese el nuevo tiempo unitario de fabricacion: \n");
        tiempos[indiceEncontrado] = pedirEnteroValido();
        if (tiempos[indiceEncontrado] > tiempoLimite) {
            printf("El tiempo unitario excede el limite de la fabrica\n");
        }
    } while (tiempos[indiceEncontrado] > tiempoLimite);
    
    do {
        printf("Ingrese los nuevos recursos unitarios necesarios: \n");
        recursos[indiceEncontrado] = pedirEnteroValido();
        if (recursos[indiceEncontrado] > recursosLimite) {
            printf("Los recursos unitarios exceden el limite de la fabrica\n");
        }
    } while (recursos[indiceEncontrado] > recursosLimite);
    
    printf("Ingrese la nueva cantidad demandada: \n");
    cantidades[indiceEncontrado] = pedirEnteroValido();
}

void calcularEstado(int cantidades[], int tiempos[], int recursos[], int *totalTiempo, int *totalRecursos) {
    *totalTiempo = 0;
    *totalRecursos = 0;
    
    for(int i = 0; i < 5; i++) {
        if(cantidades[i] > 0) {
            *totalTiempo = *totalTiempo + (tiempos[i] * cantidades[i]);
            *totalRecursos = *totalRecursos + (recursos[i] * cantidades[i]);
        }
    }
}