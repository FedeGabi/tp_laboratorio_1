#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "dataWare.h"
#include "ArrayPassenger.h"
#include "statusFlight.h"
#include "typePassenger.h"
#define TAM_PAS 20
#define TAM_TYPE 3
#define TAM_STATUS 3

int main()
{
    char seguir='s';
    int id;
    Passenger listPassenger[TAM_PAS];
    initPassengers(listPassenger,TAM_PAS);
    eTypePassenger listaTipos[TAM_TYPE];
    eStatusFlight listStatus[TAM_STATUS];
    hardcodearPassengers(listPassenger,TAM_PAS,20);
    hardcodearTypePassenger(listaTipos, TAM_TYPE);
    hardcodearStatus(listStatus, TAM_STATUS);
    do
    {
        switch(mostrarMenuPrincipal())
        {
        case 1:
            cargarParametrosPassenger(listPassenger, TAM_PAS, listaTipos, TAM_TYPE, listStatus, TAM_STATUS);
            break;
        case 2:
            if(findPassengerNoEmpty(listPassenger, TAM_PAS)>-1)
            {
                printPassengersExtended(listPassenger, TAM_PAS, listaTipos, TAM_TYPE, listStatus, TAM_STATUS);
                ingresarInt(&id, MG_NUM_ID, MG_ERROR_NUM, 3);
                modificarPassenger(listPassenger, TAM_PAS, id, listaTipos, TAM_TYPE, listStatus, TAM_STATUS);
                id=0;
            }
            else
            {
                printf("\nNO SE HAN INGRESADO PASAJEROS\n");
                system("pause");
            }
            break;
        case 3:
            if(findPassengerNoEmpty(listPassenger, TAM_PAS)>-1)
            {
                printPassengersExtended(listPassenger, TAM_PAS, listaTipos, TAM_TYPE, listStatus, TAM_STATUS);
                ingresarInt(&id, MG_NUM_ID, MG_ERROR_NUM, 3);
                removePassenger(listPassenger, TAM_PAS,id,listaTipos,TAM_TYPE,listStatus,TAM_STATUS);
                id=0;
            }
            else
            {
                printf("\nNO SE HAN INGRESADO PASAJEROS\n");
                system("pause");
            }

            break;
        case 4:
            ejecutarOrdenamientos(listPassenger, TAM_PAS, listaTipos, TAM_TYPE, listStatus, TAM_STATUS);
            break;
        default:
            system("cls");
            printf("\nOPCION INVALIDA\n");
            system("pause");
            break;
        }
    }
    while(seguir == 's');


    return 0;
}
