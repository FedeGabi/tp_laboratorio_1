/*
 * ArrayPasseger.h
 *
 *  Created on: 15 may. 2022
 *      Author: Federico Muñoz
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "typePassenger.h"
#include "statusFlight.h"

struct
{
    int id;
    char name[51];
    char lastName[51];
    float price;
    char flycode[10];
    int typePassenger;
    int statusFlight;
    int isEmpty;
} typedef Passenger;


/** \brief menu que muestra una lista de parametros de un usuario a modificar, imprimiento en tiempo real cada modificacion ingresada
 *
 * \param list[] Passenger array pasajeros
 * \param tipos[] eTypePassenger array de tipos de pasajeros
 * \param tamType int tamaño del array tipo pasajero
 * \param status[] eStatusFlight array de status flight
 * \param tamStatus int tamaño del array status
 * \param indice indice de la posicion del pasajero
 * \return int 1 si concluye satisfactoriamente
 *
 */
int menuModificarPassenger(Passenger list[], eTypePassenger tipos[], int tamType, eStatusFlight status[], int tamStatus, int indice);

/** \brief brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in al
 *
 * \param list Passenger* Pointer to array of passenger
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initPassengers(Passenger *list, int len);


/** \brief \brief add in a existing list of passengers the values received as parameters
* in the first empty position
 *
 * \param list Passenger*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param price float
 * \param typePassenger int
 * \param flycode[] char
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
 */
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[]);

/** \brief
 *
 * \param list Passenger*
 * \param len int
 * \param tipos[] eTypePassenger
 * \param tamType int
 * \param status[] eStatusFlight
 * \param tamStatus int
 * \return int
 *
 */
int cargarParametrosPassenger(Passenger* list, int len, eTypePassenger tipos[], int tamType, eStatusFlight status[], int tamStatus);

/** \brief modifica los parametros de un usuario ingresado
 *
 * \param list Passenger* array de pasajeros
 * \param len int tamaño del array pasajeros
 * \param id int id correspondiente al pasajero
 * \param tipos[] eTypePassenger array de tipos de pasajeros
 * \param tamType int tamaño del array tipo de pasajeros
 * \param status[] eStatusFlight array de estados de vuelo
 * \param tamStatus int tamaño del array estados de vuelo
 * \return int 1 si carga parametros correctamente
 *
 */
int modificarPassenger(Passenger* list, int len, int id, eTypePassenger tipos[], int tamType, eStatusFlight status[], int tamStatus);

/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger *list, int len, int id);

/** \brief busca el primer espacio vacio del array
 *
 * \param list Passenger*
 * \param len int
 * \return int retorna el indice encontrado
 *
 */
int findPassengerEmpty(Passenger *list, int len);

/** \brief busca el primer espacio no vacio
 *
 * \param list Passenger*
 * \param len int
 * \return int retorna el indice encontrado
 *
 */
int findPassengerNoEmpty(Passenger *list, int len);

/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger *list, int len, int id, eTypePassenger tipos[], int tamType, eStatusFlight status[], int tamStatus);

/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByName(Passenger* list, int len, int order);

/** \brief informa promedio de precios de pasajes, el total de los pasajes y muestra los pasajeros q superan ese promedio
 *
 * \param list[] Passenger array de pasajeros
 * \param lenth int tamañod e array pasajeros
 * \param type[] eTypePassenger array tipo de pasajeros
 * \param tamType int tamaño de array tipo pasajeros
 * \param status[] eStatusFlight array estados de vuelo
 * \param tamStatus int tamaño array estados de vuelo
 * \return int retorna 1 si informa
 *
 */
int informarPromedios(Passenger list[], int lenth, eTypePassenger type[], int tamType, eStatusFlight status[], int tamStatus);

/** \brief muestra todos los pasajeros ingresados y cada uno de sus campos
 *
 * \param list[] Passenger array de pasajeros
 * \param lenth int tamañod e array pasajeros
 * \param type[] eTypePassenger array tipo de pasajeros
 * \param tamType int tamaño de array tipo pasajeros
 * \param status[] eStatusFlight array estados de vuelo
 * \param tamStatus int tamaño array estados de vuelo
 * \return int retorna 1 o 0
 *
 */
int printPassengersExtended(Passenger* list, int lenth, eTypePassenger type[], int tamType, eStatusFlight status[], int tamStatus);

/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassengers(Passenger* list, int lenth);

/** \brief muestra un pasajero con todos sus campos
 *
 * \param passenger Passenger
 * \param type[] eTypePassenger
 * \param tamType int
 * \param status[] eStatusFlight
 * \param tamStatus int
 * \return void
 *
 */
void printOnePassengerExtended(Passenger passenger, eTypePassenger type[], int tamType, eStatusFlight status[], int tamStatus);


/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order);

/** \brief muestra un menu de ordenamiento y pide un ingreso al usuario
 *
 * \return int retorna la opcion seleccionada
 *
 */
int mostrarMenuOrdenamientos();

/** \brief valida si el codigo de vuelo ya existe
 *
 * \param list[] Passenger
 * \param len int
 * \param flyCode[] char
 * \return int devuelve 1 si logra validar
 *
 */
int validarFlycode(Passenger list[], int len, char flyCode[]);

/** \brief pide el ingreso de codigo de vuelo validando si no se ingreso uno ya existente
 *
 * \param list[] Passenger
 * \param len int
 * \param cadena[] char
 * \param tamMin int
 * \param tamMax int
 * \return int 0 si no se logro inrgesar, 1 si se el programa finalizo correctamente
 *
 */
int ingresarValidarFlycode(Passenger list[], int len, char cadena[], int tamMin, int tamMax);

/** \brief muestra menu con opciones de ordenamiento y genera el resultado
 *
 * \param list[] Passenger
 * \param len int
 * \param type[] eTypePassenger
 * \param tamType int
 * \param status[] eStatusFlight
 * \param tamStatus int
 * \return int
 *
 */
int ejecutarOrdenamientos(Passenger list[], int len, eTypePassenger type[], int tamType, eStatusFlight status[], int tamStatus);

#endif /* ARRAYPASSENGER_H_ */
