#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Pelicula.h"

void listarPeliculas(ePelicula listaPeliculas[],int tamp,eGenero listaGeneros[], int tamg)
{
    int i,j;

    char auxTitulo1 [10] = "ID";
    char auxTitulo2 [10] = "NOMBRE";
    char auxTitulo3 [10] = "DURACION";
    char auxTitulo4 [10] = "GENERO";

    printf("%s%15s%16s%15s\n",auxTitulo1,auxTitulo2,auxTitulo3,auxTitulo4);

    for(i=0; i<tamp; i++)
    {
        printf("%d%15s%10d Min",listaPeliculas[i].codigo,listaPeliculas[i].descripcion,listaPeliculas[i].duracion);

        for(j=0; j<tamg; j++)
        {
            if(listaPeliculas[i].idGenero == listaGeneros[j].id)
            {
                printf("%20s\n",listaGeneros[j].descripcion);
            }
        }
    }
}

void hardcodePeliculas(ePelicula lista[],int tamp)
{
    int i;

    int auxCodigo[10] = {100,101,102,103,104,105,106,107,108,109};
    char auxDescripcion[10][51] = {"Indiana Jones","Interestellar","Ace Ventura","Iron Man","Remember Me","Fast & Furious","El Conjuro","Anabelle","Spider-Man","Karate Kid"};
    int auxDuracion[10] = {150,121,87,123,101,147,95,74,118,109};
    int auxIdGenero[10] = {911,915,913,915,914,911,912,912,915,911};

    for(i=0; i<tamp; i++)
    {
        lista[i].codigo = auxCodigo[i];
        strcpy(lista[i].descripcion,auxDescripcion[i]);
        lista[i].duracion = auxDuracion[i];
        lista[i].idGenero = auxIdGenero[i];

    }
}


void mostrarUnaPeli(ePelicula Pelicula,eGenero Genero)
{
    printf("%d%15s%11dMin.",Pelicula.codigo,Pelicula.descripcion,Pelicula.duracion);

    if(Pelicula.idGenero == Genero.id)
    {
        printf("%15s\n",Genero.descripcion);
    }
}


int buscarPeliculaxId(ePelicula lista[],int tamp,int id)
{
    int retorno = -1;
    int i;

    for(i=0;i<tamp;i++)
    {
        if(lista[i].codigo == id)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}
