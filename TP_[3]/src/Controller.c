#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "ordenamientos.h"
#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPassenger)
{
    int retorno=0;
    if(path != NULL && pArrayListPassenger != NULL)
    {
        FILE* pFile = fopen(path, "r");
        if(pFile!= NULL)
        {
            if(!parser_PassengerFromText(pFile, pArrayListPassenger))
            {

            }
            fclose(pFile);
            pFile=NULL;
            retorno=1;
        }
    }
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListPassenger)
{
    int retorno=0;
    if(path != NULL && pArrayListPassenger != NULL)
    {
        FILE* pFile = fopen(path, "rb");
        if(pFile != NULL)
        {
            if(parser_PassengerFromBinary(pFile, pArrayListPassenger))
            {
                retorno=1;
            }
            else
            {

            }
        }
        fclose(pFile);
        pFile=NULL;
    }
    return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
    int retorno=0;
    Passenger* pasajero=Passenger_new();
    if(pArrayListPassenger != NULL && pasajero != NULL)
    {
        int idNext;
        char auxNombre[50];
        char auxApellido[50];
        float auxPrecio;
        char tipoPasajero[50];
        char codigoVuelo[50];
        char estadoVuelo[50];
        if(
            ingresarValidarNombre(auxNombre, 2, 50, "\nIngrese nombre: " ) &&
            ingresarValidarNombre(auxApellido, 2, 50, "\nIngrese apellido: " ) &&
            ingresarFloat(&auxPrecio, "\nIngrese Precio: ") &&
            ingresarValidarCadena(codigoVuelo, 7, 7,"\nIngrese codigo de vuelo: ", "\nError, el codigo de vuelo debe tener 7 caracteres") &&
            menuIngresarTipoPasajero(tipoPasajero) &&
            menuIngresarEstadoVuelo(estadoVuelo))
        {
            if((    Passenger_setNombre(pasajero, auxNombre) &&
                    Passenger_setApellido(pasajero, auxApellido) &&
                    Passenger_setPrecio(pasajero, auxPrecio) &&
                    Passenger_setTipoPasajero(pasajero, tipoPasajero) &&
                    Passenger_setCodigoVuelo(pasajero, codigoVuelo) &&
                    Passenger_setEstadoVuelo(pasajero, estadoVuelo)))
            {
                idNext=controller_mayorId();
                Passenger_setId(pasajero, (idNext+1));
                ll_add(pArrayListPassenger, pasajero);
                controller_saveAsText("idNext.csv", pArrayListPassenger); // guardo la nueva cantidad de IDs en el archivo dedicado
                retorno=1;
            }
        }
        else
        {
            printf("\nAlta cancelada");
        }
        pasajero=NULL;
    }
    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    int retorno=0;
    int seguir=1;
    int id;
    int index;
    char auxNombre[50];
    char auxApellido[50];
    float auxPrecio;
    char tipoPasajero[50];
    char codigoVuelo[50];
    char estadoVuelo[50];
    Passenger* pasajero;
    if(pArrayListPassenger != NULL)
    {
        controller_ListPassenger(pArrayListPassenger);
        if(ingresarInt(&id, "\n Ingrese ID del Pasajero: ", "\nError, solo se admiten valores numericos positivos",2))
        {
            index=findPassengerById(pArrayListPassenger, id);
            if(index==-1)
            {
                printf("\nEL ID NO COINCIDE CON NINGUN PASAJERO EXISTENTE\n");
                system("pause");
            }
            else
            {
                system("cls");
                pasajero=ll_get(pArrayListPassenger, index);
                mostrarPassenger(pasajero);
                if(pasajero!= NULL && confirmar("\nDesea editar este Pasajero? (s o n): "))
                {
                    do
                    {
                        mostrarPassenger(pasajero);
                        printf("\n");
                        switch(menuEditPassenger())
                        {
                        case 1:
                            if(ingresarValidarNombre(auxNombre, 2, 50, "\nIngrese nombre: ") &&
                                    Passenger_setNombre(pasajero, auxNombre))
                            {
                                printf("\nNombre editado con exito\n");
                                system("pause");
                            }
                            else
                            {
                                printf("\nModificacion cancelada\n");
                                system("pause");
                            }
                            break;
                        case 2:
                            if(ingresarValidarNombre(auxApellido, 2, 50, "\nIngrese nombre: ") &&
                                    Passenger_setApellido(pasajero, auxApellido))
                            {
                                printf("\nApellido editado con exito\n");
                                system("pause");
                            }
                            else
                            {
                                printf("\nModificacion cancelada\n");
                                system("pause");
                            }
                            break;
                        case 3:
                            if(ingresarFloat(&auxPrecio, "\nIngrese Precio: ") &&
                                    Passenger_setPrecio(pasajero, auxPrecio))
                            {
                                printf("\nPrecio editado con exito\n");
                                system("pause");
                            }
                            else
                            {
                                printf("\nModificacion cancelada\n");
                                system("pause");
                            }
                            break;
                        case 4:
                            if(ingresarValidarCadena(codigoVuelo, 7, 7, "\nIngrese codigo de vuelo: ", "\nError, el codigo de vuelo debe contener 7 caracteres") &&
                                    Passenger_setCodigoVuelo(pasajero, codigoVuelo))
                            {
                                printf("\nCodigo de vuelo editado con exito\n");
                                system("pause");
                            }
                            else
                            {
                                printf("\nModificacion cancelada\n");
                                system("pause");
                            }
                            break;
                        case 5:
                            if(menuIngresarTipoPasajero(tipoPasajero))
                            {
                                Passenger_setTipoPasajero(pasajero, tipoPasajero);
                                printf("\nTipo de pasajero editado con exito\n");
                                system("pause");
                            }
                            else
                            {
                                printf("\nModificacion cancelada\n");
                                system("pause");
                            }
                            break;
                        case 6:
                            if(menuIngresarEstadoVuelo(estadoVuelo))
                            {
                                Passenger_setTipoPasajero(pasajero, estadoVuelo);
                            }
                            else
                            {
                                printf("\nModificacion cancelada\n");
                                system("pause");
                            }
                            break;
                        case 7:
                            seguir=0;
                            break;
                        }
                    }
                    while(seguir==1);
                }
            }
        }
        else
        {
            printf("\nModificacion cancelada");
            system("pause");
        }
    }
    return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    int id;
    int index;
    Passenger* pasajero;
    if(pArrayListPassenger != NULL)
    {
        controller_ListPassenger(pArrayListPassenger);
        if(ingresarInt(&id, "\n Ingrese ID del Pasajero: ", "\nError, solo se admiten valores numericos positivos",2))
        {
            index=findPassengerById(pArrayListPassenger, id);
            if(index==-1)
            {
                printf("\nEL ID NO COINCIDE CON NINGUN PASAJERO EXISTENTE\n");
                system("pause");
            }
            else
            {
                system("cls");
                pasajero=ll_get(pArrayListPassenger, index);
                mostrarPassenger(pasajero);
                if(pasajero!= NULL && confirmar("\nDesea eliminar este Pasajero? (s o n): "))
                {
                    ll_remove(pArrayListPassenger, index);
                }
            }
        }
    }
    return 1;
}


/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
    int retorno = 0;
    int len;
    Passenger* pasajero = Passenger_new();
    if (pArrayListPassenger != NULL && pasajero != NULL)
    {
        len= ll_len(pArrayListPassenger);
        for (int i = 0; i < len ; i++)
        {
            pasajero=(Passenger*)ll_get(pArrayListPassenger, i);
            mostrarPassenger(pasajero);
            retorno = 1;
        }
    }
    pasajero=NULL;
    system("pause");
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    int retorno=0;
    if(pArrayListPassenger)
    {
        ll_sort(pArrayListPassenger, passengerSortPrecio, 0);
        retorno=1;
    }
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListPassenger)
{
    int retorno=0;
    Passenger* pasajero= Passenger_new();
    char auxTipoPasajero[20];
    if(path != NULL && pArrayListPassenger != NULL && pasajero != NULL)
    {
        FILE* pFile= fopen(path, "w");
        fprintf(pFile,"ID,NOMBRE,APELLIDO,PRECIO,CODVUELO,TIPO,ESTADO\n");
        for(int i=0; i<ll_len(pArrayListPassenger); i++)
        {

            pasajero= (Passenger*)ll_get(pArrayListPassenger, i);
            Passenger_getTipoPasajero(pasajero, auxTipoPasajero);
            fprintf(pFile,"%d,%s,%s,%.0f,%s,%s,%s\n",pasajero->id, pasajero->nombre, pasajero->apellido,
                    pasajero->precio, pasajero->codigoVuelo, auxTipoPasajero,
                    pasajero->estadoVuelo);
        }
        fclose(pFile);
        retorno=1;
    }
    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListPassenger)
{
    int retorno=0;
    Passenger* auxPasajero = Passenger_new();
    if(path != NULL && pArrayListPassenger != NULL && auxPasajero != NULL)
    {
        FILE* pFile = fopen(path, "wb");
        if(pFile != NULL)
        {
            for(int i=0; i< ll_len(pArrayListPassenger); i++)
            {
                auxPasajero= (Passenger*)ll_get(pArrayListPassenger, i);
                fwrite(auxPasajero, sizeof(Passenger), 1, pFile);
            }
            auxPasajero=NULL;
            fclose(pFile);
            pFile=NULL;
            retorno=1;
        }
    }
    return retorno;
}

//////////////     CONTROLLER SAVES IDs        ////////////



int controller_mayorId()
{
    int cant=0;
    int maxID=0;
    char buffer[7][100];
    Passenger* pasajero = Passenger_new();
    FILE* pFile = fopen("idNext.csv", "r"); // abro modo lectura el archivo dedicado a guardar los IDs
    if(pFile==NULL)
    {
        printf("\n[error 1111]No se pudo reservar memoria");
        exit(1);
    }
    cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                  buffer[0], buffer[1], buffer[2],
                  buffer[3], buffer[4],                              //lectura fantasma
                  buffer[5], buffer[6]);
    while (!feof(pFile))
    {

        cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
                      buffer[0], buffer[1], buffer[2],
                      buffer[3], buffer[4],                 //guardo datos en buffer
                      buffer[5], buffer[6]);

        if (cant == 7 && pasajero != NULL)
        {
            pasajero = Passenger_newParametros(buffer[0], buffer[1],
                                               buffer[2], buffer[3],       //agrego los parametros al Passenger auxiliar
                                               buffer[4], buffer[5],
                                               buffer[6]);
            if(pasajero->id >maxID)
            {
                maxID=pasajero->id;  //recorro el array evaluando condicion de mayor numero y asignando ese mayor a la variable
            }
        }
    }
    fclose(pFile);
    return maxID; //retorno el valor del id mas alto
}
