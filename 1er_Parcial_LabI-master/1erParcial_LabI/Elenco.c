#include "Elenco.h"

void inicializarElencos(eElenco lista[],int tame)
{
    int i;

    for(i=0;i<tame;i++)
    {
        lista[i].estado = LIBRE;
    }
}

void hardcodeElencos(eElenco lista[],int tame)
{
    int i;
    int codeActor[5] = {3,1,5,4,2};
    int codePelicula[5] = {109,105,107,102,101};
    int valor[5] = {175000,225000,134500,345000,115325};

    for(i=0;i<tame;i++)
    {
        lista[i].codigoActor = codeActor[i];
        lista[i].codigoPelicula = codePelicula[i];
        lista[i].valorContrato = valor[i];
        lista[i].estado = OCUPADO;
    }

}

int GenerarElenco(eActor listaActores[],int tama,ePelicula listaPeliculas[],int tamp,eGenero listaGenero[],int tamg)
{
    int i;
    int retorno = -1;
    int auxiliarId;

    listarPeliculas(listaPeliculas,tamp,listaGenero,tamg);

    auxiliarId = getIntPos("\nSeleccione ID de pelicula a la cual desea generarle elenco: ");

    if(buscarPeliculaxId(listaPeliculas,tamp,auxiliarId) != -1)
    {
        printf("Pelicula encontrada!\n\n");

        mostrarListadoActores(listaActores,tama);

        auxiliarId = getInt("Seleccione ID de actor que sera parte del elenco:");

        buscarActorxId(listaActores,tama,auxiliarId);

        if(buscarActorxId(listaActores,tama,auxiliarId) != -1)
        {
            printf("Se generara el siguiente elenco:");

        }
    }
    else
    {
        printf("No se ha encontrado pelicula con el ID ingresado\n\n");
    }



    return retorno;
}


void mostraUnElenco(eElenco elenco, ePelicula peliculas[],int tamp,eActor actores[],int tama,eGenero generos[],int tamg)
{
    int i;
    int auxRetorno;

    if(elenco.estado != LIBRE)
    {
        auxRetorno = buscarPeliculaxId(peliculas,tamp,elenco.codigoPelicula);

        if(auxRetorno != -1)
        {
            auxRetorno = buscarActorxId(actores,tama,elenco.codigoActor);

            if(auxRetorno != -1)
            {
                printf("Peli:%s nombre actor:%s apellido actor:%s genero:%s contrato:%d\n",peliculas.descripcion,actores.nombre,actores.apellido,generos.descripcion,elenco.valorContrato);
            }
        }
    }

}
