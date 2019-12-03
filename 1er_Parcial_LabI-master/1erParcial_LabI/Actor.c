#include "Actor.h"
#include <ctype.h>

void hardcodeActores(eActor lista[],int tama)
{
    int i;

    char auxNombre[5][21] = {"Carlos","Maria","Marta","Pedro","Esteban"};
    char auxApellido[5][21] = {"Gomez","Pugliese","Perez","Sanchez","Etcheverria"};
    char auxSexo[5] = {'H','M','M','H','M'};
    int auxCodigo[5] = {1,2,3,4,5};

    for(i=0; i<tama; i++)
    {
        strcpy(lista[i].nombre,auxNombre[i]);
        strcpy(lista[i].apellido,auxApellido[i]);
        lista[i].sexo = auxSexo[i];
        lista[i].codigo = auxCodigo[i];
        lista[i].estado = OCUPADO;
    }
}

void mostrarUnActor(eActor Actor)
{
    if(Actor.estado == OCUPADO)
    {
        printf("%d %15s %15s %10c\n",Actor.codigo,Actor.nombre, Actor.apellido, Actor.sexo);
    }
}

void cabeceraActores()
{
    char auxTitulo1 [10] = "ID";
    char auxTitulo2 [10] = "NOMBRE";
    char auxTitulo3 [10] = "APELLIDO";
    char auxTitulo4 [10] = "SEXO";

    printf("%s%15s%16s%12s\n",auxTitulo1,auxTitulo2,auxTitulo3,auxTitulo4);

}


void mostrarListadoActores(eActor listadoDeActores[], int tama)
{
    int i;

    cabeceraActores();

    for(i=0; i<tama; i++)
    {
        if(listadoDeActores[i].estado == OCUPADO)
        {
            mostrarUnActor(listadoDeActores[i]);
        }
    }
}



int eliminarActor(eActor listaActores[], int tama)
{
    int auxId;
    int i;
    int flag = 0 ;
    char respuesta;

    int quePaso = -1;

    mostrarListadoActores(listaActores,tama);
    auxId = getIntPos("\nIngrese el ID del actor que desea eliminar: ");

    for(i=0; i<tama; i++)
    {
        if(listaActores[i].codigo == auxId && listaActores[i].estado == OCUPADO)
        {
            flag = 1;
            system("cls");
            cabeceraActores();
            mostrarUnActor(listaActores[i]);

            respuesta = getChar("\nEsta seguro que desea eliminar este actor? S/N:");

            if(respuesta == 's' || respuesta == 'S')
            {
                listaActores[i].estado = LIBRE;
                quePaso = 1;
                printf("\n\nBaja realizada con exito.\n\n");
            }
            else
            {
                printf("\n\nBaja de actor cancelada\n\n");
                quePaso = 0;
            }
            break;
        }

    }

    if(flag == 0)
    {
        printf("\nNo se ha encontrado un actor correspondiente al ID ingresado\n\n");
    }

    return quePaso;

}


int buscarActorxId(eActor listaActores[], int tam, int id)
{
    int i;
    int retorno = -1;


    if(listaActores != NULL && tam > 0)
    {

        for(i=0; i<tam; i++)
        {
            if(listaActores[i].codigo == id && listaActores[i].estado == OCUPADO)
            {
                retorno = i;
                break;
            }
        }
    }


    return retorno;
}

int modificarActor(eActor listaActores[], int tam)
{
    int index;
    int quePaso = -1;
    char respuesta;
    eActor aux;
    int eleccion;

    int auxValidacion;

    mostrarListadoActores(listaActores,tam);

    eleccion = getIntPos("\nIngrese ID de actor que desea modificar:");

    index = buscarActorxId(listaActores,tam,eleccion);

    if(index!=-1)
    {
        system("cls");

        aux = listaActores[index];
        cabeceraActores();
        mostrarUnActor(aux);

        eleccion = getIntPos("\nQue desea modificar?\n1-Nombre\n2-Apellido\n3-Sexo\n\n");

        if(eleccion == 1)
        {
            system("cls");
            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
            gets(aux.nombre);

            auxValidacion = validar_string(aux.nombre);

            if(auxValidacion != 0)
            {
                respuesta = getChar("\nEsta seguro que desea modificar esta informacion? S/N :");

                if(respuesta == 's' || respuesta == 'S')
                {
                    corregirString(aux.nombre);
                    listaActores[index] = aux;
                    quePaso = 1;
                    printf("\n\nModificacion realizada con exito!\n\n");
                }
                else
                {
                    quePaso = 0;
                    printf("\n\nModificacion cancelada\n\n");
                }
            }
            else
            {
                printf("\nNombre ingresado invalido\n\n");
            }

        }

        else if(eleccion == 2)
        {
            system("cls");
            printf("Ingrese el nuevo apellido: ");
            fflush(stdin);
            gets(aux.apellido);

            auxValidacion = validar_string(aux.apellido);

            if(auxValidacion != 0)
            {
                respuesta = getChar("\nEsta seguro que desea modificar esta informacion? S/N :");

                if(respuesta=='s' || respuesta == 'S')
                {
                    corregirString(aux.apellido);
                    listaActores[index] = aux;
                    quePaso = 1;
                    printf("\n\nModificacion realizada con exito!\n\n");
                }
                else
                {
                    quePaso = 0;
                    printf("\n\nModificacion cancelada\n\n");
                }
            }
            else
            {
                printf("\nApellido ingresado invalido\n\n");
            }


        }
        else if(eleccion == 3)
        {
            system("cls");

            respuesta = getChar("\nEsta seguro que desea modificar esta informacion? S/N :");

            if(respuesta == 's'||respuesta == 'S')
            {
                if(listaActores[index].sexo == 'H')
                {
                    listaActores[index].sexo = 'M';
                }

                else if(listaActores[index].sexo == 'M')
                {
                    listaActores[index].sexo = 'H';
                }

                printf("\n\nModificacion realizada con exito\n\n");
            }

            else
            {
                printf("\n\nModificacion cancelada\n\n");
            }
        }

        else
        {
            printf("Opcion invalida. Operacion cancelada");
        }

    }
    else
    {
        printf("\nNo se ha encontrado un usuario correspondiente al ID ingresado\n\n");
    }
    return quePaso;
}

void inicializarActores(eActor listaActores[],int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        listaActores[i].estado = LIBRE;
        listaActores[i].codigo = 0;
    }
}



int getNewCodigo(eActor listaDeActores[], int tama)
{
    int retorno = -1;
    int flag = 0;
    int newId;

    int i;
    for(i=0; i<tama; i++)
    {
        if(flag == 0 || listaDeActores[i].codigo>newId)
        {
            newId = listaDeActores[i].codigo;
            flag = 1;
        }
    }
        retorno = newId;

    return retorno;
}



int buscarLibre(eActor listaActores[], int tam)
{

    int indice = -1;
    int i;

    for(i=0; i<tam; i++)
    {
        if(listaActores[i].estado != OCUPADO)
        {
            indice = i;
            break;
        }
    }
    return indice;

}

eActor cargarActor(eActor listaActores[],int tama)
{
    eActor miActor;

    miActor.codigo = generaId(listaActores,tama);

    pedirCadena("Ingrese nombre:",miActor.nombre);
    corregirString(miActor.nombre);

    pedirCadena("Ingrese apellido:",miActor.apellido);
    corregirString(miActor.apellido);

    miActor.sexo = getChar("Identifique el sexo del actor\n\nIngrese H para hombre o M para mujer:");

    while((miActor.sexo != 'H') && (miActor.sexo != 'M'))
    {

        miActor.sexo = getChar("Error. Reingrese una opcion valida.\nIngrese H para hombre o M para mujer:");
    }

   miActor.estado = OCUPADO;

   return miActor;
}

int altaActor(eActor listaActores[],int tama)
{
    int retorno = -1;
    int index;
    eActor auxActor;
    char respuesta;

    index = buscarLibre(listaActores,tama);

    if(index != -1)
    {
        printf("Se ha encontrado lugar para cargar actor\n\n");

        auxActor = cargarActor(listaActores,tama);

        printf("\n\nSe dara de alta al siguiente actor:\n");
        cabeceraActores();
        mostrarUnActor(auxActor);

        respuesta = getChar("\nDesea confirmar el alta del actor? S/N");

        while((respuesta != 'S') && (respuesta != 'N'))
        {
            respuesta = getChar("\n\nError. Reingrese una opcion valida:");
        }

        if(respuesta == 'S')
        {
            listaActores[index] = auxActor;
            printf("\n\nAlta realizada con exito\n\n");
            retorno = 1;
        }
        else if(respuesta == 'N')
        {
            printf("\n\nAlta de actor cancelada\n\n");
            retorno = 0;
        }

    }
    else
    {
        printf("\nNo se ha encontrado lugar para cargar actor\n\n");
    }


    return retorno;
}

int generaId(eActor listaDeActores[],int tama)
{
    int nuevoId;
    int i;
    int flag = 0;

    for(i=0;i<tama;i++)
    {
        if(flag == 0 || listaDeActores[i].codigo > nuevoId)
        {
            flag = 1;
            nuevoId = listaDeActores[i].codigo;
        }
    }

    nuevoId++;
    return nuevoId;
}

void ordenarActores(eActor listaActores[],int tama)
{
    int i,j;
    eActor auxActor;

    for(i=0;i<tama-1;i++)
    {
        for(j=i+1;j<tama;j++)
        {
            if(listaActores[i].estado == OCUPADO)
            {
                if(stricmp(listaActores[i].apellido,listaActores[j].apellido) > 0)
                {
                    auxActor = listaActores[i];
                    listaActores[i] = listaActores[j];
                    listaActores[j] = auxActor;
                }
                else if(stricmp(listaActores[i].apellido,listaActores[j].apellido) == 0)
                {
                    if(stricmp(listaActores[i].nombre,listaActores[j].nombre) > 0)
                    {
                        auxActor = listaActores[i];
                        listaActores[i] = listaActores[j];
                        listaActores[j] = auxActor;
                    }
                }
            }
        }
    }
}
