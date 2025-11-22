#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Materia
{
    int id;
    char nombre[50];
    int nota; // -1 si no la rindió aún
    struct Materia *siguiente;
} Materia;

typedef struct Estudiante
{
    int legajo;
    char nombre[50];
    int edad;
    Materia *materias; // lista de materias del estudiante
    struct Estudiante *siguiente;
} Estudiante;

Estudiante *crearListaEstudiantes()
{
    return NULL;
}

Materia *crearListaMaterias()
{
    return NULL;
}

Estudiante *agregarEstudiante(Estudiante *head, int legajo, char *nombre, int edad)
{
    Estudiante *nuevo = malloc(sizeof(Estudiante));
    nuevo->legajo = legajo;
    strcpy(nuevo->nombre, nombre);
    nuevo->edad = edad;
    nuevo->materias = NULL;
    nuevo->siguiente = NULL;

    // Caso: lista vacía o nuevo va primero (ordenado por legajo)
    if (head == NULL || legajo < head->legajo)
    {
        nuevo->siguiente = head;
        return nuevo;
    }

    Estudiante *actual = head;
    while (actual->siguiente != NULL && actual->siguiente->legajo < legajo)
    {
        actual = actual->siguiente;
    }

    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;

    return head;
}

void listarEstudiantes(Estudiante *head)
{
    Estudiante *actual = head;
    while (actual != NULL)
    {
        printf("Legajo: %d - Nombre: %s - Edad: %d\n",
               actual->legajo, actual->nombre, actual->edad);
        actual = actual->siguiente;
    }
}

Estudiante *buscarEstudiantePorNombre(Estudiante *head, char *nombre)
{
    Estudiante *actual = head;
    while (actual != NULL)
    {
        if (strcmp(actual->nombre, nombre) == 0)
        {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL;
}

void buscarPorRangoEdad(Estudiante *head, int min, int max)
{
    Estudiante *actual = head;
    while (actual != NULL)
    {
        if (actual->edad >= min && actual->edad <= max)
        {
            printf("Legajo: %d - Nombre: %s - Edad: %d\n",
                   actual->legajo, actual->nombre, actual->edad);
        }
        actual = actual->siguiente;
    }
}

void modificarEstudiante(Estudiante *e, char *nuevoNombre, int nuevaEdad)
{
    strcpy(e->nombre, nuevoNombre);
    e->edad = nuevaEdad;
}

Estudiante *eliminarEstudiante(Estudiante *head, int legajo)
{
    if (head == NULL)
        return NULL;

    if (head->legajo == legajo)
    {
        Estudiante *temp = head;
        head = head->siguiente;
        free(temp);
        return head;
    }

    Estudiante *actual = head;
    while (actual->siguiente != NULL && actual->siguiente->legajo != legajo)
    {
        actual = actual->siguiente;
    }

    if (actual->siguiente == NULL)
        return head;

    Estudiante *temp = actual->siguiente;
    actual->siguiente = temp->siguiente;
    free(temp);

    return head;
}

void agregarMateria(Estudiante *e, int id, char *nombre)
{
    Materia *nuevo = malloc(sizeof(Materia));
    nuevo->id = id;
    strcpy(nuevo->nombre, nombre);
    nuevo->nota = -1;
    nuevo->siguiente = NULL;

    if (e->materias == NULL || id < e->materias->id)
    {
        nuevo->siguiente = e->materias;
        e->materias = nuevo;
        return;
    }

    Materia *actual = e->materias;
    while (actual->siguiente != NULL && actual->siguiente->id < id)
    {
        actual = actual->siguiente;
    }

    nuevo->siguiente = actual->siguiente;
    actual->siguiente = nuevo;
}

void rendirMateria(Estudiante *e, int idMateria, int nota)
{
    Materia *m = e->materias;
    while (m != NULL)
    {
        if (m->id == idMateria)
        {
            m->nota = nota;
            return;
        }
        m = m->siguiente;
    }
}

void listarMaterias(Estudiante *e)
{
    Materia *m = e->materias;
    while (m != NULL)
    {
        printf("Materia %d - %s - Nota: %d\n", m->id, m->nombre, m->nota);
        m = m->siguiente;
    }
}