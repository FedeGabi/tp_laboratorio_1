/*
 * inputs.c
 *
 *  Created on: 15 may. 2022
 *      Author: fedec
 */

#include "inputs.h"

int incrementarId()
{
    static int id = 2000;
    id++;
    return id;
}

int mostrarMenuPrincipal()
{
    system("cls");
    int opcion=0;
    printf("\n                      ****************************                      \n");
    printf("                      ****** ABM PASSENGERS ******                     \n");
    printf("                      ****************************                     \n\n");
    printf("1. ALTAS\n");
    printf("2. MODIFICACION\n");
    printf("3. BAJA\n");
    printf("4. INFORMAR\n");
    printf("5. CARGA FORZADA\n\n");
    printf("INGRESE OPCION: ");
    scanf("%d", &opcion);
    fflush(stdin);
    return opcion;
}



int ingresarFloat(float *pFloat, char msj [], char msjError[], int intentos)
{
    int retorno = -1;
    if (pFloat != NULL && msj !=NULL && msjError != NULL && intentos>0)
    {
        float numero;
        int esNum;
        int i=0;
        do
        {
            system("cls");
            printf("%s", msj);
            esNum = scanf("%f", &numero);
            fflush(stdin);
            if (numero < 0 || !esNum)
            {
                system("cls");
                printf("%s", msjError);
                system("pause");
                *pFloat = 0;
                retorno = -1;
            }
            else if (!numero)
            {
                *pFloat = 0;
                retorno = 0;
            }
            else
            {
                *pFloat = numero;
                retorno = 1;
                i=intentos;
            }
            i++;
        }
        while(i<intentos);
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

int ingresarValidarCadena(char cadena[],int tamMin ,int tamMax, char msj[], char msjError[], int intentos)
{
    int retorno=0;
    char aux[400];
    int i=0;
    if(cadena != NULL && tamMin >0 && tamMax >0 && msj != NULL && msjError != NULL && intentos >0)
    {
        do
        { system("cls");
            printf("%s", msj);
            fflush(stdin);
            gets(aux);
            if(strlen(aux)>tamMax || strlen(aux)<tamMin)
            {
                printf("%s", msjError);
                system("pause");
                retorno=0;
            }
            else
            {
                strcpy(cadena, aux);
                retorno=1;
                break;
            }
            i++;
        }
        while(i<intentos);
    }
    return retorno;
}

int ingresarValidarNombre(char cadena[],int tamMin ,int tamMax, char msj[], char msjError[])
{
    int retorno=0;
    char aux[400];
    int seguir=1;
    if(cadena != NULL && tamMin >0 && tamMax >0 && msj != NULL && msjError != NULL)
    {
        do
        { system("cls");
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
            else{
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
    char auxNombreApellido[LEN_NAME + LEN_LASTNAME];
    if(cadena1!=NULL && cadena2!=NULL)
    {
       strcpy(auxNombreApellido, strlwr(cadena2));
       strcat(auxNombreApellido, ", ");
       strcat(auxNombreApellido, strlwr(cadena1));
       auxNombreApellido[0]=toupper(auxNombreApellido[0]);
       for(int i=0; i<strlen(auxNombreApellido);i++)
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
            else{
                seguir=0;
                retorno=1;
            }
        }while(seguir);
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
