/*
 * typePassenger.c
 *
 *  Created on: 15 may. 2022
 *      Author: fedec
 */

#include "typePassenger.h"

int menuTypePassenger(eTypePassenger list[], int tamType)
{
    int opcion=0;
    int seguir=1;
    if(list!= NULL && tamType>0)
       {
           do{
                listarTypePassenger(list, tamType);
                printf("\nINGRESE TIPO DE PASAJERO: ");
                scanf("%d", &opcion);
                if(validarTypePassenger(list, tamType,opcion))
                {
                    seguir=0;
                }
                else{
                    printf("\nTipo de pasajero invalido\n");
                    seguir=confirmar("desea volver a ingresar? (s o n): ");
                    opcion=0;
                }
           }while(seguir);
       }
       return opcion;
 }


int buscarTypePassengerId(eTypePassenger list[], int tamType, int id, int* pIndice)
{
    int retorno = 0;
    if( list != NULL && pIndice != NULL && tamType > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tamType; i++)
        {
            if(list[i].id == id)
            {
                *pIndice = i;
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int validarTypePassenger(eTypePassenger list[], int tamType, int id)
{
    int retorno = 0;
    if( list != NULL && tamType > 0 && id>0 )
    {
        for(int i=0; i < tamType; i++)
        {
            if(list[i].id == id)
            {
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int cargarDescripcionTypePassenger(eTypePassenger list[], char descripcion[], int id, int tamType)
{
    int retorno=0;
    if(list != NULL && descripcion != NULL && tamType>0 && id>0)
    {
        for(int i=0; i<tamType; i++)
        {
            if(list[i].id == id)
            {
                strcpy(descripcion, list[i].descripcion);
                retorno=1;
                break;
            }
        }
    }
    return retorno;
}

int listarTypePassenger(eTypePassenger list[],int tamType)
{
    int retorno=0;
    if(list != NULL && tamType>0)
    {
        system("cls");
        printf("ID            TYPE\n");
        printf("-----------------------\n\n");
        for(int i=0 ; i<tamType ; i++)
        {
                mostrarTypePassenger(list[i]);
                retorno=1;
        }
    }
    return retorno;
}

void mostrarTypePassenger(eTypePassenger tipo)
{
    printf("%d  |   %10s   \n", tipo.id, tipo.descripcion);
}

