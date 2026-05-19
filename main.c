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
    int indiceActual;
    int indiceEncontrado;
    int opcion;
    int tiempoLimite, recursosLimite;
    int sumaTiempo = 0;
    int sumaRecursos = 0;


    tiempoLimite = limiteDeTiempo();
    recursosLimite = limiteDeRecursos();

    do {
        
        opcion = desplegarMenu();

        switch(opcion) {
            case 1: 

                indiceActual = buscarEspacioLibre(cantidadDemandada);
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