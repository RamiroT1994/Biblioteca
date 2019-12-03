#include <stdio.h>
#include <stdlib.h>

int menu(char mensaje[]);

int main()
{
    int opcion;

    do
    {
        system("cls");
        //opcion = menu("Seleccione una opcion: ");

        switch(opcion)
        {
            case 1:
                system("cls");
                printf("ALTA\n\n");
                system("pause");
                break;
            case 2:
                printf("BAJA");
                break;
            case 3:
                printf("MODIFICAR");
                break;
            case 4:
                printf("LISTADO");
                break;
            case 5:
                printf("SALIR");
                break;
        }

    }while(opcion != 5);

    return 0;
}

int menu(char mensaje[])
{
    int opcion;

    printf("1- Alta actor\n");
    printf("2- Baja actor\n");
    printf("3- Modificar actor\n");
    printf("4- Listar actores\n\n");
    printf("5- Salir\n\n");

    //opcion = getIntPos(mensaje);

    return opcion;
}
