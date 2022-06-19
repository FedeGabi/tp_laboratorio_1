/*
 * typePassenger.h
 *
 *  Created on: 15 may. 2022
 *      Author: fedec
 */

#ifndef TYPEPASSENGER_H_
#define TYPEPASSENGER_H_

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "inputs.h"

typedef struct{
    int id;
    char descripcion[20];
}eTypePassenger;



/** \brief recibe un ID y devuelve el indice del array en el que se encuentra
 *
 * \param list[] eTypePassenger
 * \param tamType int
 * \param id int
 * \param pIndice int*
 * \return int
 *
 */
int buscarTypePassengerId(eTypePassenger list[], int tamType, int id, int* pIndice);

/** \brief valida la existencia de un ID ingresado
 *
 * \param list[] eTypePassenger
 * \param tamType int
 * \param id int
 * \return int
 *
 */
int validarTypePassenger(eTypePassenger list[], int tamType, int id);

/** \brief recorre el array typePassenger y devuelve una cadena de caracteres si el id ingresado coincide con el ID de la estructura.
 *
 * \param list[] eTypePassenger
 * \param descripcion[] char
 * \param id int
 * \param tamType int
 * \return int 1 si la funcion encuentra el ID y devuelve la cadena, de lo contrario retorna 0
 *
 */
int cargarDescripcionTypePassenger(eTypePassenger list[], char descripcion[], int id, int tamType);

/** \brief recibe un array typePassenger y los muestra
 *
 * \param list[] eTypePassenger
 * \param tamType int
 * \return int
 *
 */
int listarTypePassenger(eTypePassenger list[],int tamType);

/** \brief muestra un solo tipo de pasajero
 *
 * \param tipo eTypePassenger
 * \return void
 *
 */
void mostrarTypePassenger(eTypePassenger tipo);

/** \brief muestra un menu y solicita al usuario q ingrese una opcion
 *
 * \param list[] eTypePassenger
 * \param tamType int
 * \return int retorna la opcion seleccionada
 *
 */
int menuTypePassenger(eTypePassenger list[], int tamType);

#endif /* TYPEPASSENGER_H_ */
