/*
 * ArrayPassenger.c
 *
 *  Created on: 15 may. 2022
 *      Author: fedec
 */

#include "ArrayPassenger.h"

int menuModificarPassenger(Passenger list[], eTypePassenger tipos[], int tamType, eStatusFlight status[], int tamStatus, int indice)
{
    system("cls");
    int opcion=0;
    printf("ID                  NOMBRE        PRECIO      CODIGO           TIPO        ESTADO VUELO\n\n");
    printf("----------------------------------------------------------------------------------------\n");
    printOnePassengerExtended(list[indice], tipos, tamType, status, tamStatus);
    printf("\n\n");
    printf("1. MODIFICAR NOMBRE\n");
    printf("2. MODIFICAR APELLIDO\n");
    printf("3. MODIFICAR PRECIO\n");
    printf("4. MODIFICAR CODIGO DE VUELO\n");
    printf("5. MODIFICAR TIPO DE PASAJERO\n");
    printf("6. MODIFICAR ESTADO DE VUELO\n");
    printf("7. MENU PRINCIPAL\n\n");
    printf("INGRESE OPCION: ");
    scanf("%d", &opcion);
    fflush(stdin);
    return opcion;
}

int mostrarMenuOrdenamientos()
{
    system("cls");
    int opcion=-1;
    printf("\n");
    printf("1. ORDENAMIENTO PASAJEROS ALFABETICAMENTE.\n");
    printf("2. TOTAL Y PROMEDIO DE LOS PRECIOS DE LOS PASAJES Y LA CANTIDAD DE PASAJEROS QUE SUPERAN ESE PROMEDIO.\n");
    printf("3. LISTADO POR ESTADO DE VUELO ACTIVO Y CODIGO DE VUELO\n");
    printf("4. MENU PRINCIPAL\n\n");
    printf("INGRESE OPCION: ");
    scanf("%d", &opcion);
    fflush(stdin);
    return opcion;
}


int initPassengers(Passenger *list, int len)
{
    int retorno = -1;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            list[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[])
{
    int retorno = -1;
    int indice;
    if (list != NULL && len > 0 && name != NULL && lastName != NULL && price > 0)
    {
        indice=findPassengerEmpty(list,len);
        list[indice].id=incrementarId();
        strcpy(list[indice].name, name);
        strcpy(list[indice].lastName, lastName);
        list[indice].price=price;
        list[indice].typePassenger=typePassenger;
        retorno = 0;
    }
    return retorno;
}

int cargarParametrosPassenger(Passenger* list, int len, eTypePassenger tipos[], int tamType, eStatusFlight status[], int tamStatus)
{
    int retorno=0;
    if(list != NULL && len > 0 && tipos!= NULL && tamType >0 && status!= NULL && tamStatus >0 )
    {
        int contadorIngresos=0;
        int indice;
        int opcion;
        Passenger auxPasseger;
        indice=findPassengerEmpty(list, len);
        if(indice==-1)
        {
            system("cls");
            printf("NO HAY ESPACIO\n");
        }
        else
        {
            system("cls");
            if(ingresarValidarNombre(auxPasseger.name, 3, LEN_NAME, MG_NAME, MG_ERROR_NAMES))
            {
                contadorIngresos++;
                if(ingresarValidarNombre(auxPasseger.lastName, 3, LEN_LASTNAME, MG_LASTNAME, MG_ERROR_NAMES))
                {
                    contadorIngresos++;
                    if(ingresarFloat(&auxPasseger.price, MG_PRICE, MG_ERROR_NUM,3)==1)
                    {
                        contadorIngresos++;
                        if(ingresarValidarFlycode(list, len, auxPasseger.flycode, 3, 10))
                        {
                            contadorIngresos++;
                            opcion=menuTypePassenger(tipos, tamType);
                            if(opcion)
                            {
                                auxPasseger.typePassenger=opcion;
                                opcion=0;
                                contadorIngresos++;
                                system("cls");
                                opcion=menuStatusFlight(status, tamStatus);
                                if(opcion)
                                {
                                    contadorIngresos++;
                                    auxPasseger.statusFlight=opcion;
                                    auxPasseger.isEmpty=0;
                                    auxPasseger.id=incrementarId();
                                    list[indice]=auxPasseger;
                                    system("cls");
                                    printf("CARGA EXITOSA\n");
                                }
                            }
                        }
                    }
                }
            }
            if(contadorIngresos<6)
            {
                system("cls");
                printf("\nALTA CANCELADA...\n");
                retorno=0;
            }
        }
    }
    system("pause");
    return retorno;
}

int modificarPassenger(Passenger* list, int len, int id, eTypePassenger tipos[], int tamType, eStatusFlight status[], int tamStatus)
{
    int retorno = -1;
    if (list != NULL && len > 0 && id >0 && tipos != NULL && tamType >0 && status != NULL && tamStatus>0)
    {
        int indice;
        char seguir= 's';
        int validadorIngresos=0;
        float auxFloat;
        int opcion;
        indice=findPassengerById(list, len, id);
        if(indice>-1)
        {
            system("cls");
            printf("ID                  NOMBRE        PRECIO      CODIGO           TIPO        ESTADO VUELO\n\n");
            printf("----------------------------------------------------------------------------------------\n");
            printOnePassengerExtended(list[indice], tipos, tamType, status, tamStatus);
            if(confirmar("\n modificar pasajero? (s o n)\n")==1)
            {
                do
                {
                    switch(menuModificarPassenger(list, tipos, tamType, status, tamStatus, indice))
                    {
                    case 1:
                        if(ingresarValidarNombre(list[indice].name, 3, LEN_NAME, MG_NAME, MG_ERROR_NAMES))
                        {
                            system("cls");
                            printf("MODIFICACION EXITOSA\n");
                            system("pause");
                            validadorIngresos++;
                        }
                        else
                        {
                            system("cls");
                            printf("NO SE HA MODIFICADO EL NOMBRE\n");
                            system("pause");
                        }
                        break;
                    case 2:
                        if(ingresarValidarNombre(list[indice].lastName, 3, LEN_LASTNAME, MG_LASTNAME, MG_ERROR_NAMES))
                        {
                            system("cls");
                            printf("MODIFICACION EXITOSA\n");
                            system("pause");
                            validadorIngresos++;
                        }
                        else
                        {
                            system("cls");
                            printf("NO SE HA MODIFICADO EL APELLIDO\n");
                            system("pause");
                        }
                        break;
                    case 3:
                        if(ingresarFloat(&auxFloat, "\nIngrese nuevo precio: ", MG_ERROR_NUM, 3)!= -1)
                        {
                            list[indice].price=auxFloat;
                            system("cls");
                            printf("\nMODIFICACION EXITOSA\n");
                            system("pause");
                            validadorIngresos++;
                        }
                        else
                        {
                            system("cls");
                            printf("NO SE HA MODIFICADO EL PRECIO\n");
                            system("pause");
                        }
                        break;
                    case 4:
                        if(ingresarValidarFlycode(list, len, list[indice].flycode, 3, 10))
                        {
                            system("cls");
                            printf("MODIFICACION EXITOSA\n");
                            system("pause");
                            validadorIngresos++;
                        }
                        else
                        {
                            system("cls");
                            printf("NO SE HA MODIFICADO EL CODIGO DE VUELO\n");
                            system("pause");
                        }
                        break;
                    case 5:
                        opcion=menuTypePassenger(tipos, tamType);
                        if(opcion)
                        {
                            list[indice].typePassenger=opcion;
                        }
                        opcion=0;
                        break;
                    case 6:
                        opcion=menuStatusFlight(status, tamStatus);
                        if(opcion)
                        {
                            list[indice].statusFlight=opcion;
                        }
                        opcion=0;
                        break;
                    case 7:
                        seguir='n';
                        break;
                    }
                }
                while(seguir=='s');
            }
            else
            {
                system("cls");
                printf("MODIFICACION CANCELADA\n");
                system("pause");
            }
        }
        else
        {
            system("cls");
            printf("\nEL ID %d, NO EXISTE EN EL SISTEMA\n", id);
            system("pause");
        }
    }
    return retorno;
}

int findPassengerById(Passenger *list, int len, int id)
{
    int indice = -1;
    if (list != NULL && len > 0 && id > 0)
    {
        for (int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0 && list[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int findPassengerEmpty(Passenger *list, int len)
{
    int indice = -1;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 1)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int findPassengerNoEmpty(Passenger *list, int len)
{
    int indice = -1;
    if (list != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
        {
            if (list[i].isEmpty == 0)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int removePassenger(Passenger *list, int len, int id, eTypePassenger tipos[], int tamType, eStatusFlight status[], int tamStatus)
{
    int retorno = -1;
    int indice;
    if (list != NULL && len > 0 && id > 0)
    {

        indice=findPassengerById(list, len, id);
        if(indice>-1)
        {
            system("cls");
            printf("ID                  NOMBRE        PRECIO      CODIGO           TIPO        ESTADO VUELO\n\n");
            printf("----------------------------------------------------------------------------------------\n");
            printOnePassengerExtended(list[indice], tipos, tamType, status, tamStatus);
            if(confirmar("\n confirmar eliminacion?\n")==1)
            {
                list[indice].isEmpty=1;
                system("cls");
                printf("\nBAJA EXITOSA\n");
            }
            else
            {
                system("cls");
                printf("BAJA CANCELADA\n");
            }

        }
        else
        {
            printf("\nEL ID %d, NO EXISTE EN EL SISTEMA\n", id);
        }
    }
    system("pause");
    return retorno;
}
int sortPassengersByName(Passenger* list, int len, int order)
{
    int retorno=0;
    Passenger auxPassenger;
    if(list!=NULL && len>0 && (order==0 || order==1))
    {
        for(int i=0; i<len-1 ; i++)
        {
            for(int j=i+1; j<len ; j++)
            {
                if(order==1)
                {
                    if((strcmp(strlwr(list[i].lastName), strlwr(list[j].lastName)) > 0) ||
                            (strcmp(strlwr(list[i].lastName), strlwr(list[j].lastName)) > 0 &&
                             list[i].typePassenger > list[j].typePassenger))
                    {
                        auxPassenger=list[i];
                        list[i]=list[j];
                        list[j]=auxPassenger;
                    }
                }
                else
                {
                    if((strcmp(strlwr(list[i].lastName), strlwr(list[j].lastName)) < 0) ||
                            (strcmp(strlwr(list[i].lastName), strlwr(list[j].lastName)) < 0 &&
                             list[i].typePassenger > list[j].typePassenger))
                    {
                        auxPassenger=list[i];
                        list[i]=list[j];
                        list[j]=auxPassenger;
                    }
                }
            }
        }
        retorno=1;
    }
    return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
    int retorno=0;
    int flag=0;
    Passenger auxPassenger;
    if(list!=NULL && len>0 && (order==0 || order==1))
    {
        for(int i=0; i<len ; i++)
        {
            if(list[i].statusFlight==10)
            {
                flag=1;
                break;
            }
        }
        if(flag)
        {
            for(int i=0; i<len-1 ; i++)
            {
                for(int j=i+1; j<len ; j++)
                {
                    if(order==1)
                    {
                        if(list[i].statusFlight > list[j].statusFlight ||
                                (list[i].statusFlight > list[j].statusFlight &&
                                 strcmp(strlwr(list[i].flycode), strlwr(list[j].flycode)) > 0))
                        {
                            auxPassenger=list[i];
                            list[i]=list[j];
                            list[j]=auxPassenger;
                        }

                    }
                    else if(order == 0)
                    {
                        if(list[i].statusFlight < list[j].statusFlight ||
                                (list[i].statusFlight < list[j].statusFlight &&
                                 strcmp(strlwr(list[i].flycode), strlwr(list[j].flycode)) < 0))
                        {
                            auxPassenger=list[i];
                            list[i]=list[j];
                            list[j]=auxPassenger;
                        }
                    }
                }
            }
            retorno=1;
        }
    }
    return retorno;
}

int informarPromedios(Passenger list[], int lenth, eTypePassenger type[], int tamType, eStatusFlight status[], int tamStatus)
{
    int retorno;
    if(list!= NULL && lenth >0 && type != NULL && tamType > 0 && status != NULL && tamStatus>0)
    {
        float promedios=0;
        float totalPrecios=0;
        int contadorPassenger=0;
        int cantidadPassengerMayorPromedio=0;

        for(int i=0; i<lenth ; i++)
        {
            if(list[i].isEmpty==0)
            {
                totalPrecios= totalPrecios + list[i].price;
                contadorPassenger++;
            }
        }
        if(contadorPassenger)
        {
            promedios = totalPrecios/(float)contadorPassenger;
            for(int i=0; i<lenth ; i++)
            {
                if(list[i].isEmpty==0 && list[i].price > promedios)
                {

                    cantidadPassengerMayorPromedio++;
                }
            }
            system("cls");
            printf("\n");
            printf("TOTAL DE PRECIOS: $%.2f \n",totalPrecios );
            printf("\n");
            printf("PROMEDIO DE PRECIOS: $%.2f \n",promedios );
            printf("\n");
            if(cantidadPassengerMayorPromedio)
            {
                printf("HAY %d PASAJEROS QUE SUPERAN EL PRECIO PROMEDIO. SE DETALLAN A CONTINUACION: \n",cantidadPassengerMayorPromedio );
                printf("\n");
                printf("ID                  NOMBRE        PRECIO      CODIGO           TIPO        ESTADO VUELO\n\n");
                printf("----------------------------------------------------------------------------------------\n");
                for(int i=0; i<lenth ; i++)
                {
                    if(list[i].isEmpty==0 && list[i].price > promedios)
                    {

                        printOnePassengerExtended(list[i], type, tamType, status, tamStatus);
                    }
                }
            }
            else
            {
                printf("NO HAY PASAJEROS QUE SUPEREN EL PROMEDIO DE PRECIOS \n");
            }
            retorno=1;
        }
        retorno=0;
    }
    printf("\n");
    return retorno;
}
int printPassengersExtended(Passenger* list, int lenth, eTypePassenger type[], int tamType, eStatusFlight status[], int tamStatus)
{
    int retorno=0;
    if(list!= NULL && lenth>0)
    {
        system("cls");
        printf("\n                            ****************************                      \n");
        printf("                            ***** LIST PASSENGERS ******                     \n");
        printf("                            ****************************                     \n\n");
        printf("ID                  NOMBRE        PRECIO      CODIGO           TIPO        ESTADO VUELO\n\n");
        printf("----------------------------------------------------------------------------------------\n");
        for(int i=0; i<lenth; i++)
        {
            if(list[i].isEmpty==0)
            {
                printOnePassengerExtended(list[i],type,tamType, status, tamStatus);
            }
        }
        printf("\n\n");
        retorno=1;
    }
    return retorno;
}

void printOnePassengerExtended(Passenger passenger, eTypePassenger type[], int tamType, eStatusFlight status[], int tamStatus)
{
    char auxCadena[LEN_NAME + LEN_LASTNAME];
    char auxtype[20];
    char auxStatus[20];
    cargarDescripcionTypePassenger(type, auxtype,passenger.typePassenger, tamType);
    cargarDescripcionStatusFlight(status, auxStatus,passenger.statusFlight, tamStatus);
    formatearNombres(auxCadena, passenger.name, passenger.lastName);
    printf("%d      %20s    $%.2f     %7s  %15s %15s\n",
           passenger.id,
           auxCadena,
           passenger.price,
           strupr(passenger.flycode),
           auxtype,
           auxStatus);
}

int ingresarValidarFlycode(Passenger list[], int len, char cadena[], int tamMin, int tamMax)
{
    int retorno=0;
    char aux[400];
    int seguir=1;
    if(cadena != NULL && len >0 && cadena != NULL && tamMin >0 && tamMax >0)
    {
        do
        {
            system("cls");
            printf("\nINGRESE CODIGO DE VUELO: ");
            fflush(stdin);
            gets(aux);
            if(strlen(aux)<tamMin || strlen(aux)> tamMax)
            {
                printf("\nCODIGO INVALIDO, SE DEBE INGRESAR UN CODIGO CON MAS DE 2, Y MENOS DE 10 CARACTERES...");
                seguir=confirmar("\nDesea ingresar codigo nuevamente? (S o N): ");
                retorno=0;
            }
            else if(validarFlycode(list, len, aux)==0)
            {
                printf("\nEL CODIGO DE VUELO YA EXISTE EN EL SISTEMA ");
                seguir=confirmar("\nDesea ingresar codigo nuevamente? (S o N): ");
                retorno=0;
            }
            else
            {
                strcpy(cadena, aux);
                retorno=1;
                break;
            }
        }
        while(seguir);
    }
    return retorno;
}


int validarFlycode(Passenger list[], int len, char flycode[])
{
    int retorno=-1;
    if(list!= NULL && len>0)
    {
        retorno=1;
        for(int i=0; i<len; i++)
        {
            if(strcmp(strlwr(list[i].flycode), (strlwr(flycode)))== 0)
            {
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}

int ejecutarOrdenamientos(Passenger list[], int len, eTypePassenger type[], int tamType, eStatusFlight status[], int tamStatus)
{
    int retorno=0;
    if(list!= NULL && len >0 && type != NULL && tamType>0 && status != NULL && tamStatus>0)
    {
        int seguir=1;
        do{
            if(findPassengerNoEmpty(list, len)>-1)
            {
                switch(mostrarMenuOrdenamientos())
                {
                case 1:
                    sortPassengersByName(list,len,1);
                    printPassengersExtended(list, len, type, tamType, status, tamStatus);
                    system("pause");
                    break;
                case 2:
                    informarPromedios(list, len, type, tamType, status, tamStatus);
                    system("pause");
                    break;
                case 3:
                    if(sortPassengersByCode(list, len , 1))
                    {
                        printPassengersExtended(list, len, type, tamType, status, tamStatus);
                    }
                    else{
                        printf("\nNO EXISTEN PASAJEROS CON ESTADO DE VUELO ACTIVO\n");

                    }
                    system("pause");
                    printf("\n\n");
                    break;
                case 4:
                    seguir=0;
                    break;
                default :
                    system("cls");
                    printf("\nOPCION INVALIDA...\n");
                    system("pause");
                    break;
                }
                retorno=1;
            }
            else
            {
            printf("\nNO SE HAN INGRESADO PASAJEROS\n");
            system("pause");
            seguir=0;
            }

        }while(seguir==1);
    }
    return retorno;
}

