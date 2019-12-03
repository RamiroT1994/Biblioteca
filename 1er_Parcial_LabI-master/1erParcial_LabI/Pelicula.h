#include <stdio.h>
#include <stdlib.h>
#include "Genero.h"
typedef struct
{
    int codigo;
    char descripcion[51];
    int duracion;
    int idGenero;

}ePelicula;


void listarPeliculas(ePelicula[],int,eGenero[],int);
void hardcodePeliculas(ePelicula lista[],int);
void mostrarUnaPeli(ePelicula,eGenero);
int buscarPeliculaxId(ePelicula[],int,int);
