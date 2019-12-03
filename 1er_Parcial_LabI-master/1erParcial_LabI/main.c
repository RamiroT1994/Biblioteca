#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "Elenco.h"

#define TAMP 10
#define TAMG 5
#define TAMA 10
#define TAME 10

int main()
{
    int opcion;

    eActor listaActores[TAMA];
    ePelicula listaPeliculas[TAMP];
    eGenero listaGeneros[TAMG];
    eElenco listaElencos[TAME];

    inicializarActores(listaActores,TAMA);
    inicializarElencos(listaElencos,TAME);

    hardcodeActores(listaActores,5);
    hardcodePeliculas(listaPeliculas,TAMP);
    hardcodeGenero(listaGeneros,TAMG);

    do
    {
        system("cls");
        opcion = menu("Seleccione una opcion: ");

        switch(opcion)
        {
            case 1:
                system("cls");
                altaActor(listaActores,TAMA);
                system("pause");
                break;
            case 2:
                system("cls");
                eliminarActor(listaActores,TAMA);
                system("pause");
                break;
            case 3:
                system("cls");
                modificarActor(listaActores,TAMA);
                system("pause");
                break;
            case 4:
                system("cls");
                mostrarListadoActores(listaActores,TAMA);
                printf("\n");
                system("pause");
                break;
            case 5:
                system("cls");
                mostrarUnElenco(listaPeliculas,TAMP,listaActores,TAMA,listaGeneros,TAMG);
                system("pause");
                break;
            case 6:
                system("cls");

                system("pause");
                break;
            case 7:
                system("cls");
                printf("Cerrando programa...\n\nHasta luego!\n\n");
                system("pause");
                break;
            default:
                system("cls");
                printf("INVALIDO, REINGRESE OPCION VALIDA\n\n");
                system("pause");
        }

    }while(opcion != 7);

    return 0;
}
