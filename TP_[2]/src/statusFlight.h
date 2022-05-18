/*
 * statusFlight.h
 *
 *  Created on: 15 may. 2022
 *      Author: fedec
 */

#ifndef STATUSFLIGHT_H_
#define STATUSFLIGHT_H_

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "inputs.h"

typedef struct{
    int id;
    char descripcion[20];
}eStatusFlight;

/** \brief recibe un ID y devuelve el indice del array en el que se encuentra
 *
 * \param list[] eStatusFlight
 * \param tamStatus int
 * \param id int
 * \param pIndice int*
 * \return int
 *
 */
int buscarStatusFlightId(eStatusFlight list[], int tamStatus, int id, int* pIndice);

/** \brief valida la existencia de un ID ingresado
 *
 * \param list[] eStatusFlight
 * \param tamStatus int
 * \param id int
 * \return int
 *
 */
int validarStatusFlight(eStatusFlight list[], int tamStatus, int id);

/** \brief recorre el array statusFlight y devuelve una cadena de caracteres si el id ingresado coincide con el ID de la estructura.
 *
 * \param list[] eStatusFlight
 * \param descripcion[] char
 * \param id int
 * \param tamStatus int
 * \return int 1 si la funcion encuentra el ID y devuelve la cadena, de lo contrario retorna 0
 *
 */
int cargarDescripcionStatusFlight(eStatusFlight list[], char descripcion[], int id, int tamStatus);

/** \brief recibe un array StatusFlight y los muestra
 *
 * \param list[] eStatusFlight
 * \param tamStatus int
 * \return int
 *
 */
int listarStatusFlight(eStatusFlight list[],int tamStatus);

/** \brief muestra un solo estado de vuelo
 *
 * \param tipo eStatusFlight
 * \return void
 *
 */
void mostrarStatusFlight(eStatusFlight statusFlight);

/** \brief muestra un menu y solicita al usuario q ingrese una opcion
 *
 * \param status eStatusFlight
 * \param tamStatus int
 * \return int retorna la opcion seleccionada
 *
 */
int menuStatusFlight(eStatusFlight status[], int tamStatus);

#endif /* STATUSFLIGHT_H_ */
