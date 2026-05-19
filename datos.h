#ifndef DATOS_H
#define DATOS_H

int desplegarMenu();
int limiteDeTiempo();
int limiteDeRecursos();
void ingresarProducto(char nombres[][30], int tiempos[], int recursos[], int cantidades[], int indiceActual, int tiempoLimite, int recursosLimite);
void calcularEstado(int cantidades[], int tiempos[], int recursos[], int *totalTiempo, int *totalRecursos);
void editarProducto(int tiempos[], int recursos[], int cantidades[], int indiceEncontrado, int tiempoLimite, int recursosLimite);

#endif