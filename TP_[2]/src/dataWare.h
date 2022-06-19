/*
 * dataWare.h
 *
 *  Created on: 15 may. 2022
 *      Author: fedec
 */

#ifndef DATAWARE_H_
#define DATAWARE_H_

#include <string.h>
#include <ctype.h>
#include "ArrayPassenger.h"
#include "statusFlight.h"
#include "inputs.h"

/** \brief carga de manera automatica todos los valores
 *
 * \param list Passenger* puntero q escribe en el array de Passenger
 * \param len int tamaño del array
 * \param cant int cantidad de datos q se desea cargar
 * \return int retorna 1 si la funcion concluyo satisfactoriamente
 *
 */
int hardcodearPassengers(Passenger* list,int len, int cant);
/** \brief carga de manera automatica valores en array statusFlight
 *
 * \param listStatus eStatusFlight*
 * \param tamStatus int
 * \return int int retorna 1 si la funcion concluyo satisfactoriamente
 *
 */
int hardcodearStatus(eStatusFlight* listStatus, int tamStatus);
/** \brief carga de manera automatinca valores en array typePassenger
 *
 * \param listType eTypePassenger*
 * \param tamType int
 * \return int int retorna 1 si la funcion concluyo satisfactoriamente
 *
 */
int hardcodearTypePassenger(eTypePassenger* listType, int tamType);

#endif /* DATAWARE_H_ */
