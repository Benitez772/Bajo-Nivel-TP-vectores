#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "materias.h"
#include "estudiantes.h"

// =====================
//   MATERIAS SISTEMA
// =====================

Materia *crearListaMaterias() { return NULL; }

Materia *buscarMateriaSistema(Materia *head, int id)
{
    while (head != NULL)
    {
        if (head->id == id)
            return head;
        head = head->siguiente;
    }
    return NULL;
}

Materia *agregarMateriaSistema(Materia *head, int id, char *nombre)
{
    if (buscarMateriaSistema(head, id))
    {
        printf("ERROR: ya existe la materia %d.\n", id);
        return head;
    }

    Materia *nuevo = malloc(sizeof(Materia));
    nuevo->id = id;
    strcpy(nuevo->nombre, nombre);
    nuevo->siguiente = NULL;

    if (head == NULL || id < head->id)
    {
        nuevo->siguiente = head;
        return nuevo;
    }

    Materia *actual = head;
    while (actual->siguiente != NULL && actual->siguiente->id < id)
        actual = actual->siguiente;

    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;

    return head;
}

void modificarMateriaSistema(Materia *head, int id, char *nuevoNombre)
{
    Materia *m = buscarMateriaSistema(head, id);
    if (!m)
    {
        printf("ERROR: la materia no existe.\n");
        return;
    }
    strcpy(m->nombre, nuevoNombre);
}

Materia *eliminarMateriaSistema(Materia *head, int id)
{
    if (!head)
        return NULL;

    if (head->id == id)
    {
        Materia *temp = head;
        head = head->siguiente;
        free(temp);
        return head;
    }

    Materia *actual = head;
    while (actual->siguiente != NULL && actual->siguiente->id != id)
        actual = actual->siguiente;

    if (!actual->siguiente)
        return head;

    Materia *temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    free(temp);

    return head;
}

void listarMateriasSistema(Materia *head)
{
    while (head)
    {
        printf("Materia ID %d - %s\n", head->id, head->nombre);
        head = head->siguiente;
    }
}

// ===============================
//   MATERIAS DEL ESTUDIANTE
// ===============================

int estudianteTieneMateria(Estudiante *e, int id)
{
    MateriaEst *m = e->materias;
    while (m)
    {
        if (m->id == id)
            return 1;
        m = m->siguiente;
    }
    return 0;
}

void agregarMateriaEstudiante(Estudiante *e, Materia *listaGlobal, int id)
{
    Materia *mg = buscarMateriaSistema(listaGlobal, id);
    if (!mg)
    {
        printf("ERROR: materia %d no existe en el sistema.\n", id);
        return;
    }

    if (estudianteTieneMateria(e, id))
    {
        printf("ERROR: el estudiante ya está anotado.\n");
        return;
    }

    MateriaEst *nuevo = malloc(sizeof(MateriaEst));
    nuevo->id = mg->id;
    strcpy(nuevo->nombre, mg->nombre);
    nuevo->nota = -1;
    nuevo->siguiente = NULL;

    if (!e->materias || id < e->materias->id)
    {
        nuevo->siguiente = e->materias;
        e->materias = nuevo;
        return;
    }

    MateriaEst *actual = e->materias;
    while (actual->siguiente && actual->siguiente->id < id)
        actual = actual->siguiente;

    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
}

void rendirMateria(Estudiante *e, int id, int nota)
{
    MateriaEst *m = e->materias;
    while (m)
    {
        if (m->id == id)
        {
            m->nota = nota;
            return;
        }
        m = m->siguiente;
    }
}

void listarMateriasEstudiante(Estudiante *e)
{
    MateriaEst *m = e->materias;
    while (m)
    {
        printf("Materia %d - %s - Nota: %d\n", m->id, m->nombre, m->nota);
        m = m->siguiente;
    }
}