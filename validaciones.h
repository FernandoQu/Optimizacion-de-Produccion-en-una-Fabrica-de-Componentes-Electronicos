#ifndef VALIDACIONES_H
#define VALIDACIONES_H

int pedirEnteroValido();
int esSoloLetras(char cadena[]);
int existeProducto(char nombreBuscado[], char matrizNombres[][15]);
int buscarEspacioLibre(int cantidades[]);
int validarLongitud(char cadena[]);
int buscarIndiceProducto(char nombreBuscado[], char matrizNombres[][50], int cantidades[]);

#endif