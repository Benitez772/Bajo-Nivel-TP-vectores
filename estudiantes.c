#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudiantes.h"

Estudiante *crearListaEstudiantes() { return NULL; }

Estudiante *buscarEstudiante(Estudiante *head, int legajo)
{
    while (head)
    {
        if (head->legajo == legajo)
            return head;
        head = head->siguiente;
    }
    return NULL;
}

Estudiante *agregarEstudiante(Estudiante *head, int legajo, char *nombre, int edad)
{
    if (buscarEstudiante(head, legajo))
    {
        printf("ERROR: legajo duplicado.\n");
        return head;
    }

    Estudiante *nuevo = malloc(sizeof(Estudiante));
    nuevo->legajo = legajo;
    strcpy(nuevo->nombre, nombre);
    nuevo->edad = edad;
    nuevo->materias = NULL;
    nuevo->siguiente = NULL;

    if (!head || legajo < head->legajo)
    {
        nuevo->siguiente = head;
        return nuevo;
    }

    Estudiante *actual = head;
    while (actual->siguiente && actual->siguiente->legajo < legajo)
        actual = actual->siguiente;

    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;

    return head;
}

void listarEstudiantes(Estudiante *head)
{
    while (head)
    {
        printf("Legajo %d - %s - Edad %d\n", head->legajo, head->nombre, head->edad);
        head = head->siguiente;
    }
}

void modificarEstudiante(Estudiante *e, char *nuevoNombre, int nuevaEdad)
{
    strcpy(e->nombre, nuevoNombre);
    e->edad = nuevaEdad;
}

Estudiante *eliminarEstudiante(Estudiante *head, int legajo)
{
    if (!head)
        return NULL;

    if (head->legajo == legajo)
    {
        Estudiante *temp = head;
        head = head->siguiente;
        free(temp);
        return head;
    }

    Estudiante *actual = head;
    while (actual->siguiente && actual->siguiente->legajo != legajo)
        actual = actual->siguiente;

    if (!actual->siguiente)
        return head;

    Estudiante *temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    free(temp);

    return head;
}

Estudiante *buscarEstudiantePorNombre(Estudiante *head, char *nombre)
{
    while (head)
    {
        if (strcmp(head->nombre, nombre) == 0)
            return head;
        head = head->siguiente;
    }
    return NULL;
}

void buscarPorRangoEdad(Estudiante *head, int min, int max)
{
    while (head)
    {
        if (head->edad >= min && head->edad <= max)
            printf("Legajo %d - %s - Edad %d\n", head->legajo, head->nombre, head->edad);

        head = head->siguiente;
    }
}