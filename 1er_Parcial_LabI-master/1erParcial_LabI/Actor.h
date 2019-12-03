#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Pelicula.h"

#define OCUPADO 1
#define LIBRE 0

typedef struct
{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;

    int estado;

}eActor;

void hardcodeActores(eActor lista[],int);
void inicializarActores(eActor[],int);
void mostrarListadoActores(eActor[],int);
void mostrarUnActor(eActor);
int eliminarActor(eActor[], int);
int buscarActorxId(eActor[], int, int);
int modificarActor(eActor[], int);

eActor cargarActor(eActor[], int);
int getNewCodigo(eActor[], int);
int buscarLibre(eActor[], int);
int altaActor(eActor[],int);
void ordenarActores(eActor[],int);

int generaId(eActor[],int);



