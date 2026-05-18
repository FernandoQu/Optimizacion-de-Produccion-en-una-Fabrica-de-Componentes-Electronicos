#include <stdio.h>
#include "datos.h"

int main() {
    
    char nombreDelProducto[5][50];
    int tiempoUnitario[5] = {0};
    int recursosUnitarios[5] = {0};
    int cantidadDemandada[5] = {0};

    int opcion;
    int tiempoLimite, recursosLimite;

    printf("Ingrese el tiempo de fabricacion: ");
    tiempoLimite = pedirEnteroValido();

    printf("Ingrese los recursos necesarios: ");
    recursosLimite = pedirEnteroValido();

    do {
        printf("Menu\n");
        printf("1. Ingresar Producto\n");
        printf("2. Editar Producto\n");
        printf("3. Eliminar Producto\n");
        printf("4. Ver Estado de Producción\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1: {
                int indiceActual = -1;
                for(int i = 0; i < 5; i++) {
                    if(cantidadDemandada[i] == 0) { 
                        indiceActual = i;
                        break; 
                    }
                }
                if(indiceActual == -1) {
                    printf("\n¡Alerta: Inventario lleno! Debe eliminar un producto primero.\n");
                } else {
                    
                    ingresarProducto(nombreDelProducto, tiempoUnitario, recursosUnitarios, cantidadDemandada, indiceActual);
                }
                break;
            }
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                printf("Saliendo del sistema...\n");
                break;
            default:
                printf("Opcion no valida.\n");
        }
    } while(opcion != 5);

    return 0;
}