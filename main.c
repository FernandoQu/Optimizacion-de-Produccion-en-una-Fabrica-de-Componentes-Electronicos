#include <stdio.h>
#include "datos.h"
#include "validaciones.h"

int main() {
    
    char nombreDelProducto[5][30];
    int tiempoUnitario[5] = {0};
    int recursosUnitarios[5] = {0};
    int cantidadDemandada[5] = {0};
    char nombreAEliminar[30];
    int indiceEncontrado;
    int opcion;
    int tiempoLimite, recursosLimite;

    printf("Ingrese el disponible tiempo de fabricacion: \n");
    tiempoLimite = pedirEnteroValido();

    printf("Ingrese los recursos disponibles necesarios: \n");
    recursosLimite = pedirEnteroValido();

    do {
        printf("Menu\n");
        printf("1. Ingresar Producto\n");
        printf("2. Editar Producto\n");
        printf("3. Eliminar Producto\n");
        printf("4. Ver Estado de Producción\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: ");
        opcion = pedirEnteroValido();

        switch(opcion) {
            case 1: 

                int indiceActual = buscarEspacioLibre(cantidadDemandada);
                if(indiceActual == -1) {
                    printf("\nInventario esta lleno\n");
                } else {
                    ingresarProducto(nombreDelProducto, tiempoUnitario, recursosUnitarios, cantidadDemandada, indiceActual);
                }
                break;

            
            case 2:
                
                break;
            case 3:

                printf("\nEliminar Producto\n");
                printf("Ingrese el nombre del producto para eliminar: \n");
                scanf("%s", nombreAEliminar);
                while (getchar() != '\n');

                indiceEncontrado = buscarIndiceProducto(nombreAEliminar, nombreDelProducto, cantidadDemandada);

                if (indiceEncontrado == -1) {
                    printf("No se encontro ningun producto con el nombre %s\n", nombreAEliminar);
                } else {

                    cantidadDemandada[indiceEncontrado] = 0;
                    nombreDelProducto[indiceEncontrado][0] = '\0'; 
                    printf("\nEl producto %s ha sido eliminado\n", nombreAEliminar);

                }
                break;

            case 4:
                
                break;
            case 5:
                printf("Saliendo\n");
                break;
            default:
                printf("Opcion no valida\n");
        }
    } while(opcion != 5);

    return 0;
}