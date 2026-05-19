#include <stdio.h>
#include "datos.h"
#include "validaciones.h"

int main() {
    
    char nombreDelProducto[5][30];
    int tiempoUnitario[5] = {0};
    int recursosUnitarios[5] = {0};
    int cantidadDemandada[5] = {0};
    char nombreAEliminar[30];
    char nombreAEditar[30];
    int indiceEncontrado;
    int opcion;
    int tiempoLimite, recursosLimite;
    int sumaTiempo = 0;
    int sumaRecursos = 0;

    printf("Ingrese el disponible tiempo (Dias) de fabricacion: \n");
    tiempoLimite = pedirEnteroValido();

    printf("Ingrese los recursos disponibles necesarios: \n");
    recursosLimite = pedirEnteroValido();

    do {
        printf("Menu\n");
        printf("1. Ingresar Producto\n");
        printf("2. Editar Producto\n");
        printf("3. Eliminar Producto\n");
        printf("4. Ver Estado de Produccion\n");
        printf("5. Salir\n");
        printf("Seleccione una opcion: \n");
        opcion = pedirEnteroValido();

        switch(opcion) {
            case 1: 

                int indiceActual = buscarEspacioLibre(cantidadDemandada);
                if(indiceActual == -1) {
                    printf("\nInventario esta lleno\n");
                } else {
                    ingresarProducto(nombreDelProducto, tiempoUnitario, recursosUnitarios, cantidadDemandada, indiceActual, tiempoLimite, recursosLimite);
                }
                break;

            
            case 2:
                
                printf("\nEditar Producto\n");
                printf("Ingrese el nombre del producto para editar: \n");
                scanf("%s", nombreAEditar);
                while (getchar() != '\n');
                indiceEncontrado = buscarIndiceProducto(nombreAEditar, nombreDelProducto, cantidadDemandada);
                if (indiceEncontrado == -1) {
                    printf("No se encontro ningun producto con el nombre %s\n", nombreAEditar);
                } else {
                    editarProducto(tiempoUnitario, recursosUnitarios, cantidadDemandada, indiceEncontrado, tiempoLimite, recursosLimite);
                }

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
                
                calcularEstado(cantidadDemandada, tiempoUnitario, recursosUnitarios, &sumaTiempo, &sumaRecursos);
                
                printf("Tiempo total de fabricacion requerido: %d\n", sumaTiempo);
                printf("Cantidad de recursos necesarios: %d\n", sumaRecursos);

                if (sumaTiempo <= tiempoLimite && sumaRecursos <= recursosLimite) {
                    printf("\nSi cumple con la demanda\n");
                } else {
                    printf("\nNo cumple con la demanda\n");
                }
                break;

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