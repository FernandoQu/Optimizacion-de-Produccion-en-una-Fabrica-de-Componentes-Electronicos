#include <stdio.h>

int pedirEnteroValido() {
    int numero;
    int escaneados;

    do {
        escaneados = scanf("%d", &numero);

        if (escaneados != 1) {
            printf("Ingrese solo numeros");
            while (getchar() != '\n'); 
        } else if (numero <= 0) {
            printf("Debe de ingresar un numero mayor a 0");
        }

    } while (escaneados != 1 || numero <= 0);

    return numero;
}

int buscarEspacioLibre(int cantidades[]) {
    for(int i = 0; i < 5; i++) {
        if(cantidades[i] == 0) { 
            return i;
        }
    }
    return -1;
}

int esSoloLetras(char cadena[]) {
    int i = 0;
    while (cadena[i] != '\0') {
        char letra = cadena[i];

        if (!((letra >= 'A' && letra <= 'Z') || (letra >= 'a' && letra <= 'z') || letra == ' ')) {
            return 0;
        }
        i++;
    }
    return 1;
}

int existeProducto(char nombreBuscado[], char matrizNombres[][15]) {
    for (int i = 0; i < 5; i++) {
        int sonIguales = 1;
        int j = 0;
        while (nombreBuscado[j] != '\0' || matrizNombres[i][j] != '\0') {
            if (nombreBuscado[j] != matrizNombres[i][j]) {
                sonIguales = 0;
                break;
            }
            j++;
        }
        if (sonIguales == 1 && matrizNombres[i][0] != '\0') {
            return 1; 
        }
    }
    return 0;
}

int validarLongitud(char cadena[]) {
    int contador = 0;

    while (cadena[contador] != '\0') {
        contador++;
    }

    if (contador < 2 || contador >= 15) {
        return 0;
    }
    return 1;
}

int buscarIndiceProducto(char nombreBuscado[], char matrizNombres[][50], int cantidades[]) {
    for (int i = 0; i < 5; i++) {
        // Solo buscamos en los espacios que sí tienen un producto (cantidad > 0)
        if (cantidades[i] > 0) {
            int sonIguales = 1;
            int j = 0;
            while (nombreBuscado[j] != '\0' || matrizNombres[i][j] != '\0') {
                if (nombreBuscado[j] != matrizNombres[i][j]) {
                    sonIguales = 0;
                    break;
                }
                j++;
            }
            if (sonIguales == 1) {
                return i; // ¡Lo encontramos! Devolvemos la posición
            }
        }
    }
    return -1; // No se encontró en ningún lado
}