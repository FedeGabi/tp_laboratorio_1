/*
 * inputs.c
 *
 *  Created on: 6 jun. 2022
 *      Author: fedec
 */

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
    printf("1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto). \n");
    printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo texto). \n");
    printf("3. Alta de pasajero  \n");
    printf("4. Modificar datos de pasajero \n");
    printf("5. Baja de pasajero\n");
    printf("6. Listar pasajeros \n");
    printf("7. Ordenar pasajeros  \n");
    printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto). \n");
    printf("9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario)\n");
    printf("10. salir\n\n");
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

int ingresarInt(int *pInt, char msj [], char msjError[], int intentos)
{
    int retorno = -1;
    if (pInt != NULL && msj !=NULL && msjError != NULL && intentos>0)
    {
        int numero;
        int esNum;
        int i=0;
        do
        {
            printf("%s", msj);
            esNum = scanf("%d", &numero);
            fflush(stdin);
            if (numero < 0 || !esNum)
            {
                system("cls");
                printf("%s", msjError);
                system("pause");
                *pInt = 0;
                retorno = -1;
            }
            else if (!numero)
            {
                *pInt = 0;
                retorno = 0;
            }
            else
            {
                *pInt = numero;
                retorno = 1;
                i=intentos;
            }
            i++;
        }
        while(i<intentos);
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
        printf("tipo de pasajero\n\n");
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
                retorno=1;
                seguir=0;
            }
            else if(opcion==3)
            {
                strcpy(cadena,"En Vuelo" );
                retorno=1;
                seguir=0;
            }
            else if(opcion==4)
            {
                strcpy(cadena,"Demorado" );
                retorno=1;
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
