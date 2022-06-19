/*
 * statusFlight.c
 *
 *  Created on: 15 may. 2022
 *      Author: fedec
 */

#include "statusFlight.h"

int buscarStatusFlightId(eStatusFlight list[], int tamStatus, int id, int* pIndice)
{
    int retorno = 0;
    if( list != NULL && pIndice != NULL && tamStatus > 0 )
    {
        *pIndice = -1;
        for(int i=0; i < tamStatus; i++)
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

int validarStatusFlight(eStatusFlight list[], int tamStatus, int id)
{
    int retorno = 0;
    if( list != NULL && tamStatus > 0 && id>0 )
    {
        for(int i=0; i < tamStatus; i++)
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

int cargarDescripcionStatusFlight(eStatusFlight list[], char descripcion[], int id, int tamStatus)
{
    int retorno=0;
    if(list != NULL && descripcion != NULL && tamStatus>0 && id>0)
    {
        for(int i=0; i<tamStatus; i++)
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

int listarStatusFlight(eStatusFlight list[],int tamStatus)
{
    int retorno=0;
    if(list != NULL && tamStatus>0)
    {
        system("cls");
        printf("ID            STATUS\n");
        printf("-----------------------\n\n");
        for(int i=0 ; i<tamStatus ; i++)
        {

                mostrarStatusFlight(list[i]);
                retorno=1;
        }
    }
    return retorno;
}

void mostrarStatusFlight(eStatusFlight statusFlight)
{
    printf("%d  |   %10s   \n", statusFlight.id, statusFlight.descripcion);
}


int menuStatusFlight(eStatusFlight status[], int tamStatus)
{
    int opcion=0;
    int seguir=1;
    if(status!= NULL && tamStatus>0)
       {
           do{
                listarStatusFlight(status, tamStatus);
                printf("\nINGRESE ESTADO DE VUELO: ");
                scanf("%d", &opcion);
                if(validarStatusFlight(status, tamStatus, opcion))
                {
                    seguir=0;
                }
                else{
                    printf("\nEstado de vuelo invalido\n");
                    seguir=confirmar("desea volver a ingresar? (s o n): ");
                    opcion=0;
                }
           }while(seguir);

       }
       return opcion;
 }
