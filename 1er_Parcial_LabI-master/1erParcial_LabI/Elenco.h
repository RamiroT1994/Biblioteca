#include <stdio.h>
#include <stdlib.h>
#include "Actor.h"

#define OCUPADO 1
#define LIBRE 0

typedef struct
{
    int codigoActor;
    int codigoPelicula;
    int valorContrato;

    int estado;
}eElenco;

void inicializarElencos(eElenco lista[],int tame);
void hardcodeElencos(eElenco lista[],int tame);

int GenerarElenco(eActor listaActores[],int tama,ePelicula listaPeliculas[],int tamp,eGenero listaGenero[],int tamg);
void mostrarUnElenco(ePelicula listaPeliculas[],int tamp,eActor listaActores[],int tama,eGenero listaGeneros[],int tamg);
