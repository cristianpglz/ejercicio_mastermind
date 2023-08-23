#include "menus.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "proceso_frases.h"
void mostrarMenuInicio(int *opcion) {
    printf("Bienvenido a Frases Locas!\n");
    printf("1. Jugar\n");
    printf("2. Salir\n");
    printf("Elige una opción: ");
    scanf("%d", opcion);
    getchar(); // Consumir el salto de línea en el buffer
}



void mostrarMenuAgregarPalabra(int *opcion) {
    printf("Donde quieres agregar la palabra?\n");
    printf("1. Nombres\n");
    printf("2. Verbos\n");
    printf("3. Adjetivos\n");
    printf("4. Sectores especificos\n");
    printf("5. Salir\n");  // Agregar una opción para salir del bucle
    printf("Elige una opcion: ");
    scanf("%d", opcion);
    getchar(); // Consumir el salto de línea en el buffer
}


void iniciarJuego() {
    srand(time(NULL));

    int opcion;
    PalabrasUsuario palabrasUsuario; // Debes definir esta estructura según tu diseño
    TemporalCategory temporalCategory; // Debes definir esta estructura según tu diseño
    temporalCategory.numPalabrasTemporales = 0;

    while (1) {
        mostrarMenuInicio(&opcion);

        switch (opcion) {
            case 1:
                while (1) {
                    mostrarMenuAgregarPalabra(&opcion);
                    if (opcion >= 1 && opcion <= 4) {
                        if (temporalCategory.numPalabrasTemporales < MAX_PALABRAS_TEMPORALES) {
                            printf("Escribe la nueva palabra: ");
                            char nuevaPalabra[100];
                            scanf("%s", nuevaPalabra);
                            strcpy(temporalCategory.palabrasTemporales[temporalCategory.numPalabrasTemporales], nuevaPalabra);
                            temporalCategory.numPalabrasTemporales++;
                        } else {
                            printf("Límite de palabras temporales alcanzado.\n");
                        }
                    } else if (opcion == 5) {
                        break;
                    } else {
                        printf("Opción no válida.\n");
                    }
                }

                generarFrases(&palabrasUsuario, &temporalCategory);
                break;

            case 2:
                printf("Saliendo del juego.\n");
                exit(0);

            default:
                printf("Opción no válida.\n");
        }
    }
}