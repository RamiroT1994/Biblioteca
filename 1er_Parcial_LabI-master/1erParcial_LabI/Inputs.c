#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "Inputs.h"

int menu(char mensaje[])
{
    int opcion;

    printf("*********GESTION DE ACTORES*********\n\n");

    printf("1- Alta actor\n");
    printf("2- Baja actor\n");
    printf("3- Modificar actor\n");
    printf("4- Listar actores\n\n");

    printf("*********GESTION DE ELENCOS*********\n\n");

    printf("5- Generar elenco\n");
    printf("6- Listar elencos\n\n");

    printf("7- Salir\n\n");

    opcion = getIntPos(mensaje);

    return opcion;
}

int getIntPos(char* mensaje)
{
    int validacion;
    int retorno = -1;

    char numero[10];
    printf(mensaje);
    gets(numero);

    validacion = validar_numero_positivo(numero);

    if(validacion != -1)
    {
        retorno = atoi(numero);
    }

    return retorno;
}

int validar_numero_positivo(char numero[])
{
    int i;

    for(i=0; i<strlen(numero); i++)
    {
        if(!(isdigit(numero[i])))
        {
            return -1;
        }
    }

    return 1;
}

int getInt(char* mensaje)
{
    char numero[10];
    int validacion;
    int retorno = NULL;

    printf(mensaje);
    gets(numero);

    validacion = validar_numero_entero(numero);

    if(validacion != NULL)
    {
        retorno = atoi(numero);
    }

    return retorno;
}

int validar_numero_entero(char numero[])
{
    int i;

    for(i=0; i<strlen(numero); i++)
    {
        if((isdigit(numero[i])) || (strlen(numero) > 1 && numero[0] == '-'))
        {
            return 1;
        }
    }

    return NULL;
}

int getDesdeHasta(char* mensaje,int desde,int hasta)
{
    int retorno = -1;
    int validacion;
    char numero[10];
    int num_parseado;

    printf(mensaje);
    gets(numero);

    validacion = validar_numero_entero(numero);

    if(validacion != NULL)
    {
        num_parseado = atoi(numero);
        retorno = 0;

        if(num_parseado >= desde && num_parseado <= hasta)
        {
            retorno = num_parseado;
        }

    }


    return retorno;
}


float getFloat(char* mensaje)
{
    int validacion;
    float retorno = -1;

    char numero[20];
    printf(mensaje);
    gets(numero);

    validacion = validar_flotante(numero);

    if(validacion != -1)
    {
        retorno = atof(numero);
    }

    return retorno;
}


int validar_flotante(char numero[])
{
    int i;
    int aux;

    for(i=0; i<strlen(numero); i++)
    {
        if(numero[i] == ',')
        {
            numero[i] = '.';
        }
    }

    aux = isDigitOrPoint(numero);

    return aux;
}



int isDigitOrPoint(char* cadena)
{
    int retorno;
    int i;

    if((cadena[0] >= 48 && cadena[0] <= 57) || (cadena[0] == 45) )
    {
        for(i=1; i<strlen(cadena); i++)
        {
            if((cadena[i] >= 48 && cadena[i] <= 57) || (cadena[i] == 46))
            {
                retorno = 1;
            }
            else
            {
                retorno = -1;
                break;
            }
        }
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}


char getChar(char* mensaje)
{
    char letra;
    int aux;

    printf(mensaje);
    fflush(stdin);

    letra = getch();
    aux = isalpha(letra);

    if(aux != 0)
    {
        return letra;
    }
    else
    {
        return NULL;
    }

}


int validar_char(char caracter)
{
    int retorno = -1;
    char aux;

    aux = isalpha(caracter);

    /*Si retorno es distinto de 0(FALSO), porque es una letra...*/
    if(aux != 0)
    {
        retorno = 1;
    }
    else
    {
        retorno = -1;
    }

    return retorno;
}


int getString(char cadena[])
{
    int i;
    int flag = 0;
    int esEspacio = 0;
    int tam = strlen(cadena);

    for(i=0; i<tam; i++)
    {
        if(cadena[i] != '\0')
        {
            if ((cadena[i]<'a' || cadena[i]>'z') && (cadena[i]<'A'||cadena[i]>'Z') && cadena[i]!=' ')
            {
                flag = -1;
            }
            if(cadena[i]!=' ')
            {
                esEspacio = -1;
            }
        }
    }
    if(esEspacio == 0)
    {
        flag = -1;
    }
    return flag;
}


void pedirCadena (char mensaje[], char cadena[])
{
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cadena);
    while(getString(cadena)== -1)
    {
        printf("Error. Ingrese solo letras!\n");
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", cadena);
    }

}

int validar_string(char* cadena)
{
    int i;
    int retorno = 1;

    for(i=0; i<strlen(cadena) ;i++)
    {
        if( !(isalpha(cadena[i])) && !(isspace(cadena[i])) )
        {
            retorno = 0;
            break;
        }
    }

    return retorno;
}

void corregirString(char* cadena)
{
    int i;

    cadena = strlwr(cadena);
    cadena[0] = toupper(cadena[0]);

    for(i=0; i<strlen(cadena); i++)
    {
        if(cadena[i]!='\0')
        {
            if(isspace(cadena[i]))
            {
                cadena[i+1] = toupper(cadena[i+1]);
            }
        }
    }
}
