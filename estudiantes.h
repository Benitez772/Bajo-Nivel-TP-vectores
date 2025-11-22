#ifndef ESTUDIANTES_H
#define ESTUDIANTES_H

#include "materias.h"

typedef struct Estudiante
{
    int legajo;
    char nombre[50];
    int edad;
    MateriaEst *materias;
    struct Estudiante *siguiente;
} Estudiante;

// Lista de estudiantes
Estudiante *crearListaEstudiantes();
Estudiante *agregarEstudiante(Estudiante *head, int legajo, char *nombre, int edad);
Estudiante *eliminarEstudiante(Estudiante *head, int legajo);
void modificarEstudiante(Estudiante *e, char *nuevoNombre, int nuevaEdad);
void listarEstudiantes(Estudiante *head);

// Búsquedas
Estudiante *buscarEstudiante(Estudiante *head, int legajo);
Estudiante *buscarEstudiantePorNombre(Estudiante *head, char *nombre);
void buscarPorRangoEdad(Estudiante *head, int min, int max);

#endif