#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "input.h"

typedef struct
{
    char nombre[20];
    char apellido[20];
    int edad;
    float sueldo;

    int estado;

}eEmpleado;

int empleado_setNombre(eEmpleado,char*);
int empleado_setApellido(eEmpleado,char*);
int empleado_setEdad(eEmpleado,int);
int empleado_setSueldo(eEmpleado,float);

int empleado_getNombre(eEmpleado,char*);
int empleado_getApellido(eEmpleado,char*);
int empleado_getEdad(eEmpleado,int*);
int empleado_getSueldo(eEmpleado,float*);

//void empleado_getAll(eEmpleado);
void mostrarEmpleado(eEmpleado);

int main()
{
    char* auxString;
    int auxEntero;
    float auxFloat;

    eEmpleado empleado;

    printf("*********ALTA DE EMPLEADO**********\n\n");


    auxString = getString("Ingrese nombre: ","Error. Reingrese un nombre valido: ");
    auxEntero = empleado_setNombre(empleado,auxString);

    auxString = getString("Ingrese apellido: ","Error. Reingrese un apellido valido: ");
    auxEntero = empleado_setApellido(empleado,auxString);

    auxEntero = getInt("Ingrese edad: ","Error. Reingrese una edad valida: ",18,40);
    auxEntero = empleado_setEdad(empleado,auxEntero);

    auxFloat = getFloat("Ingrese sueldo: ","Error. Reingrese un sueldo valdio: ",5000,10000);
    auxEntero = empleado_setSueldo(empleado,auxFloat);

    empleado.estado = 1;

    printf("\n\n************SE HA DADO DE ALTA AL EMPLEADO************\n\n");

    system("pause");
    system("cls");

    mostrarEmpleado(empleado);



    return 0;
}

int empleado_setNombre(eEmpleado emp,char* cadena)
{
    int retorno = -1;

    if(cadena != NULL)
    {
        strcpy(emp.nombre,cadena);

        retorno = 0;
    }

    return retorno;
}

int empleado_setApellido(eEmpleado emp,char* cadena)
{
    int retorno = -1;

    if(cadena != NULL)
    {
        strcpy(emp.apellido,cadena);
        retorno = 0;
    }

    return retorno;
}

int empleado_setEdad(eEmpleado emp,int numero)
{
    int retorno = -1;

    if(emp.estado != 1)
    {
        emp.edad = numero;
        retorno = 0;
    }

    return retorno;
}

int empleado_setSueldo(eEmpleado emp,float numero)
{
    int retorno = -1;

    if(emp.estado != 1)
    {
        emp.sueldo = numero;
        retorno = 0;
    }

    return retorno;
}

int empleado_getNombre(eEmpleado emp,char* cadena)
{
    int retorno = -1;

    if(cadena != NULL)
    {
        retorno = 0;
        strcpy(cadena,emp.nombre);
    }

    return retorno;
}


int empleado_getApellido(eEmpleado emp,char* cadena)
{
    int retorno = -1;

    if(cadena != NULL)
    {
        retorno = 0;
        strcpy(cadena,emp.apellido);
    }

    return retorno;
}

int empleado_getEdad(eEmpleado emp, int* numero)
{
    int retorno = -1;

    if(numero != NULL)
    {
        retorno = 0;
        *numero = emp.edad;
    }

    return retorno;
}

int empleado_getSueldo(eEmpleado emp, float* numero)
{
    int retorno = -1;

    if(numero != NULL)
    {
        retorno = 0;
        *numero = emp.sueldo;
    }

    return retorno;
}

/*void empleado_getAll(eEmpleado emp)
{
    int auxEntero;

    int* auxEdad;
    float* auxSueldo;
    char* auxNombre;
    char* auxApellido;

    auxEntero = empleado_getNombre(emp,auxNombre);
    auxEntero = empleado_getApellido(emp,auxApellido);
    auxEntero = empleado_getEdad(emp,auxEdad);
    auxEntero = empleado_getSueldo(emp,auxSueldo);

    printf("Nombre: %s\nApellido: %s\nEdad: %d\nSueldo: %.2f\n\n",auxNombre,auxApellido,*auxEdad,*auxSueldo);

}
*/
void mostrarEmpleado(eEmpleado empleado)
{
    printf("Nombre:%s Apellido:%s Edad:%d Sueldo:%.2f",empleado.nombre,empleado.apellido,empleado.edad,empleado.sueldo);
}
