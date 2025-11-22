#ifndef MATERIAS_H
#define MATERIAS_H

typedef struct Materia
{
    int id;
    char nombre[50];
    struct Materia *siguiente;
} Materia;

typedef struct MateriaEst
{
    int id;
    char nombre[50];
    int nota;
    struct MateriaEst *siguiente;
} MateriaEst;

// Lista global de materias
Materia *crearListaMaterias();
Materia *agregarMateriaSistema(Materia *head, int id, char *nombre);
Materia *eliminarMateriaSistema(Materia *head, int id);
void modificarMateriaSistema(Materia *head, int id, char *nuevoNombre);
void listarMateriasSistema(Materia *head);
Materia *buscarMateriaSistema(Materia *head, int id);

// Lista de materias del estudiante
int estudianteTieneMateria(struct Estudiante *e, int id);
void agregarMateriaEstudiante(struct Estudiante *e, Materia *listaGlobal, int id);
void rendirMateria(struct Estudiante *e, int id, int nota);
void listarMateriasEstudiante(struct Estudiante *e);

#endif