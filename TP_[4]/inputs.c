#include "inputs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"


int menu()
{
    system("cls");
    int opcion;
    printf("1. Mostrar elementos del LinkedList UNO. \n");
    printf("2. Mostrar elementos del LinkedList DOS. \n");
    printf("3. Ordenar elementos del LinkedList UNO. \n");
    printf("4. Clonar LinkedList UNO en LinkedList DOS y mostrar \n");
    printf("5. Generar una sub-lista en LinkedList DOS y mostrar\n");
    printf("6. Setear a PEDRITO en indice 995 de LinkedList UNO\n");
    printf("7. Remover un pasajero de Linkedlist UNO en indice 995 \n");
    printf("8. Mostrar Indice de LORENITA usando ll_indexOf() \n");
    printf("9. Agregar a LORENITA al final del LinkedList UNO usando ll_add()  \n");
    printf("10. Verificar si PEDRITO esta dentro del LinkedList UNO\n");
    printf("11. Agregar a PEDRITO al LinkedList UNO en indice 997 con ll_push() \n");
    printf("12. Verificar si LinkedList UNO esta vacio. \n");
    printf("13. Mostrar y eliminar un elemento de LinkedList UNO en el indice 998 con ll_pop()  \n");
    printf("14. Verificar si todos los elementos de LinkedList Auxiliar estan contenidos dentro de LinkedList UNO  \n");
    printf("15. Generar un LinkedList DOS, FILTRANDO elementos apartir del LinkedList UNO\n");
    printf("16. Utilizar ll_clean() para limpiar LinkedList\n");
    printf("17. Eliminar LinkedList UNO, LinkedList DOS y salir\n\n");
    scanf("%d", &opcion);
    return opcion;
}

int menuEditPassenger()
{
    system("cls");
    int opcion;
    printf("1. Editar Nombre\n");
    printf("2. Editar Apellido\n");
    printf("3. Editar Precio\n");
    printf("4. Editar Codigo de vuelo\n");
    printf("5. Editar Tipo de Pasajero\n");
    printf("6. Editar Estado de Vuelo \n");
    printf("7. salir\n\n");
    scanf("%d", &opcion);
    return opcion;
}

int menuClear()
{
    system("cls");
    int opcion;
    printf("1. Limpiar LinkedList 1\n");
    printf("2. Limpiar LinkedList AUXILIAR\n");
    printf("3. Volver al menu anterior\n");
    scanf("%d", &opcion);
    return opcion;
}

int menuOrdenamiento()
{
    system("cls");
    int opcion;
    printf("1. Ordenar por ID\n");
    printf("2. Ordenar por nombre\n");
    printf("3. Ordenar por Apellido\n");
    printf("4. Ordenar por Precio\n");
    printf("5. Ordenar por Codigo de vuelo\n");
    printf("6. Ordenar por Tipo de Pasajero\n");
    printf("7. Ordenar por Estado de Vuelo \n");
    printf("8. salir\n\n");
    scanf("%d", &opcion);
    return opcion;
}


int menuFiltrarNuevoLinkedList()
{
    system("cls");
    int opcion;
    printf("1. filtrar por Tipo de pasajero\n");
    printf("2. filtrar por estado Vuelo\n");
    printf("3. salir\n\n");
    scanf("%d", &opcion);
    return opcion;
}


int ingresarFloat(float *pFloat, char msj [])
{
    int retorno = -1;
    if (pFloat != NULL && msj !=NULL)
    {
        float numero;
        int esNum;
        int seguir=1;
        do
        {
            system("cls");
            printf("%s", msj);
            esNum = scanf("%f", &numero);
            fflush(stdin);
            if (numero <= 0 || !esNum)
            {
                system("cls");
                seguir=confirmar("\nError, solo se admiten valores numericos positivos. Desea reingresar? (s o n): ");
                *pFloat = 0;
                retorno = 0;
            }
            else
            {
                *pFloat = numero;
                retorno = 1;
                seguir=0;
            }
        }
        while(seguir==1);
    }
    return retorno;
}

int ingresarInt(int *pInt, char msj [])
{
    int retorno = -1;
    if (pInt != NULL && msj !=NULL)
    {
        int numero;
        int esNum;
        int seguir=1;
        do
        {
            printf("%s", msj);
            esNum = scanf("%d", &numero);
            fflush(stdin);
            if (numero < 0 || !esNum)
            {
                system("cls");
                seguir=confirmar("\nError, solo se admiten valores numericos positivos. Desea reingresar? (s o n): ");
                *pInt = 0;
                retorno = -1;
            }
            else if (!numero)
            {
                *pInt = 0;
                retorno = 1;
               seguir=0;
            }
            else
            {
                *pInt = numero;
                retorno = 1;
                seguir=0;
            }
        }
        while(seguir==1);
    }
    return retorno;
}

int ingresarValidarCadena(char cadena[],int tamMin,int tamMax, char msj[], char msjError[])
{
    int retorno=0;
    char aux[400];
    int seguir=1;
    if(cadena != NULL && tamMin >0 && tamMax >0 && msj != NULL && msjError != NULL)
    {
        do
        {
            system("cls");
            printf("%s", msj);
            fflush(stdin);
            gets(aux);
            if(strlen(aux)>tamMax || strlen(aux)<tamMin)
            {
                printf("%s", msjError);
                seguir=confirmar("\nDesea ingresar nuevamente? (s o n): ");
                retorno=0;
            }
            else
            {
                strcpy(cadena, aux);
                seguir=0;
                retorno=1;
                break;
            }
        }
        while(seguir==1);
    }
    return retorno;
}

int ingresarValidarNombre(char cadena[],int tamMin,int tamMax, char msj[])
{
    int retorno=0;
    char aux[400];
    int seguir=1;
    if(cadena != NULL && tamMin >0 && tamMax >0 && msj != NULL )
    {
        do
        {
            system("cls");
            printf("%s", msj);
            fflush(stdin);
            gets(aux);
            if(validarLetras(aux)==0)
            {
                system("cls");
                printf("\nNO SE ADMITEN VALORES NUMERICOS\n");
                seguir=confirmar("\nDESEA VOLVER A INGRESAR? (S o N): ");
                retorno=0;
            }
            else if(strlen(aux)>tamMax || strlen(aux)<tamMin)
            {
                printf("\nDEBE TENER UNA EXTENCION MAYOR A %d Y MENOR A %d LETRAS", tamMin, tamMax);
                seguir=confirmar("\nDESEA VOLVER A INGRESAR? (S o N): ");
                retorno=0;
            }
            else
            {
                strcpy(cadena, aux);
                retorno=1;
                seguir=0;
                break;
            }
        }
        while(seguir);
    }
    return retorno;
}

int validarLetras(char cadena[])
{
    int retorno=-1;
    if(cadena!= NULL)
    {
        retorno=1;
        for(int i=0; i<strlen(cadena); i++)
        {
            if(tolower(cadena[i]) < 97 || tolower(cadena[i]) >122)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int formatearNombres(char pResultado[], char cadena1[], char cadena2 [])
{
    int retorno=0;
    char auxNombreApellido[strlen(cadena1) + strlen(cadena2)];
    if(cadena1!=NULL && cadena2!=NULL)
    {
        strcpy(auxNombreApellido, strlwr(cadena2));
        strcat(auxNombreApellido, ", ");
        strcat(auxNombreApellido, strlwr(cadena1));
        auxNombreApellido[0]=toupper(auxNombreApellido[0]);
        for(int i=0; i<strlen(auxNombreApellido); i++)
        {
            if(auxNombreApellido[i]==' ')
            {
                auxNombreApellido[i+1]=toupper(auxNombreApellido[i+1]);
                break;
            }
        }
        strcpy(pResultado, auxNombreApellido);
        retorno=1;
    }
    return retorno;
}


int menuIngresarTipoPasajero(char* cadena)
{
    int retorno=0;
    int seguir=1;
    if(cadena != NULL)
    {
        int opcion;
        system("cls");
        printf("tipo de pasajero\n\n");
        printf("1. FirstClass\n");
        printf("2. ExecutiveClass\n");
        printf("3. EconomyClass\n\n");
        printf("ingrese opcion: ");
        scanf("%d",&opcion);
        do
        {
            if(opcion==1)
            {
                strcpy(cadena,"FirstClass" );
                retorno=1;
                seguir=0;
            }
            else if(opcion==2)
            {
                strcpy(cadena,"ExecutiveClass" );
                retorno=2;
                seguir=0;
            }
            else if(opcion==3)
            {
                strcpy(cadena,"EconomyClass" );
                retorno=3;
                seguir=0;
            }
            else
            {
                seguir=confirmar("\nOpcion invalida, desea reingresar? (s o n): ");
            }

        }
        while(seguir==1);
    }
    return retorno;
}

int menuIngresarEstadoVuelo(char* cadena)
{
    int retorno=0;
    int seguir=1;
    if(cadena != NULL)
    {
        int opcion;
        system("cls");
        printf("Estado de vuelo\n\n");
        printf("1. Aterrizado\n");
        printf("2. En Horario\n");
        printf("3. En Vuelo\n");
        printf("4. Demorado\n\n");
        printf("ingrese opcion: ");
        scanf("%d",&opcion);
        do
        {
            if(opcion==1)
            {
                strcpy(cadena,"Aterrizado" );
                retorno=1;
                seguir=0;
            }
            else if(opcion==2)
            {
                strcpy(cadena,"En Horario" );
                retorno=2;
                seguir=0;
            }
            else if(opcion==3)
            {
                strcpy(cadena,"En Vuelo" );
                retorno=3;
                seguir=0;
            }
            else if(opcion==4)
            {
                strcpy(cadena,"Demorado" );
                retorno=4;
                seguir=0;
            }
            else
            {
                seguir=confirmar("\nOpcion invalida, desea reingresar? (s o n): ");
            }

        }
        while(seguir==1);
    }
    return retorno;
}

int ingresarValidarCaracter(char msj[], char msjError[], char rangMin, char rangMax)
{
    int retorno=0;
    char caracter;
    int seguir=1;
    if(msj != NULL && msjError != NULL)
    {
        do
        {
            printf("%s",msj);
            fflush(stdin);
            caracter=getchar();
            if(tolower(caracter)<tolower(rangMin) || tolower(caracter)>tolower(rangMax))
            {
                printf("%s\n", msjError);
                seguir=confirmar("intentar nuevamente? (s o n)\n");
            }
            else
            {
                seguir=0;
                retorno=1;
            }
        }
        while(seguir);
    }
    return retorno;
}

int confirmar(char msj[])
{
    int respuesta=-1;
    char opcion;
    printf("%s", msj);
    fflush(stdin);
    opcion=getchar();
    if(tolower(opcion)=='s')
    {
        respuesta=1;
    }
    else
    {
        respuesta=0;
    }
    return respuesta;
}



int ingresarValidarCadenaFloat(char cadena[],int tamMin,int tamMax, char msj[])
{
    int retorno=0;
    char aux[400];
    int seguir=1;
    int tieneLetras=0;
    if(cadena != NULL && tamMin >0 && tamMax >0 && msj != NULL)
    {
        do
        {
            system("cls");
            printf("%s", msj);
            fflush(stdin);
            gets(aux);
            for(int i =0; i <strlen(aux); i++ )
            {
                if(aux[i]==',' || isalpha(aux[i])!=0)
                {
                    tieneLetras=1;
                    printf("flag contiene letras?: %d, isAlpha de aux[%d],  caracter: %c\n", tieneLetras, i, aux[i]);
                    break;
                }
            }
            if(tieneLetras==1 || strlen(aux)>tamMax || strlen(aux)<tamMin)
            {
                system("cls");
                printf("\nError, Solo se admiten valores numericos");
                seguir=confirmar("\nIngresar nuevamente? (s o n): ");
                retorno=0;
            }
            else
            {
                strcpy(cadena, aux);
                retorno=1;
                seguir=0;
                break;
            }
        }
        while(seguir==1);
    }
    return retorno;
}



int ingresarValidarCadenaInt(char cadena[],int tamMin,int tamMax, char msj[])
{
    int retorno=0;
    char aux[400];
    int seguir=1;
    int tieneLetras=0;
    if(cadena != NULL && tamMin >0 && tamMax >0 && msj != NULL)
    {
        do
        {
            system("cls");
            printf("%s", msj);
            fflush(stdin);
            gets(aux);
            for(int i =0; i <strlen(aux); i++ )
            {
                if(aux[i]==',' || aux[i] =='.'|| isalpha(aux[i])!=0)
                {
                    tieneLetras=1;
                    break;
                }
            }
            if(tieneLetras==1 || strlen(aux)>tamMax || strlen(aux)<tamMin)
            {
                system("cls");
                printf("\nError, Solo se admiten valores numericos sin decimales");
                seguir=confirmar("\nIngresar nuevamente? (s o n): ");
                retorno=0;
            }
            else
            {
                strcpy(cadena, aux);
                retorno=1;
                seguir=0;
                break;
            }
        }
        while(seguir==1);
    }
    return retorno;
}

int ingresarIntDevCad(char* cadena, LinkedList* pArrayListPassenger)
{
    int retorno=0;
    int id;
    if(cadena != NULL)
    {
        id = (ll_len(pArrayListPassenger)+1);
        itoa(id, cadena, 10);
    }
    return retorno;
}
