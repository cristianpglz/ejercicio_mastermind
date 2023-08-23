#include "proceso_frases.h"
#include <string.h>
#include <stdio.h>

const char *nombresOriginales[] = {"Carlos", "Maria", "perro", "gato", "elefante"};
const char *verbosOriginales[] = {"corrió", "saltó", "nadó", "bailó", "cantó"};
const char *adjetivosOriginales[] = {"feliz", "grande", "pequeño", "rápido", "brillante"};
const char *sectoresEspecificosOriginales[] = {"computadora", "ciencia", "cocina", "arte", "deporte"};

const int NUM_NOMBRES_ORIGINALES = sizeof(nombresOriginales) / sizeof(nombresOriginales[0]);
const int NUM_VERBOS_ORIGINALES = sizeof(verbosOriginales) / sizeof(verbosOriginales[0]);
const int NUM_ADJETIVOS_ORIGINALES = sizeof(adjetivosOriginales) / sizeof(adjetivosOriginales[0]);
const int NUM_SECTORES_ESPECIFICOS_ORIGINALES = sizeof(sectoresEspecificosOriginales) / sizeof(sectoresEspecificosOriginales[0]);

// Función para generar frases
void generarFrases(PalabrasUsuario *palabrasUsuario, TemporalCategory *temporalCategory) {
    const char *frases[MAX_FRASES_GENERADAS];
    for (int i = 0; i < MAX_FRASES_GENERADAS; i++) {
        frases[i] = generarFrase(palabrasUsuario, temporalCategory->palabrasTemporales, temporalCategory->numPalabrasTemporales);
    }

    printf("Frases generadas:\n");
    for (int i = 0; i < MAX_FRASES_GENERADAS; i++) {
        printf("%d. %s\n", i + 1, frases[i]);
    }
}
