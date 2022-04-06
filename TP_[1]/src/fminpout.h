/*
 * fminpout.h
 *
 *  Created on: 4 abr. 2022
 *      Author: Federico Muñoz 1G Dni 32378420
 */
#include <stdio.h>
#include <stdlib.h>
#include "fmmath.h"
#ifndef FMINPOUT_H_
#define FMINPOUT_H_



#endif /* FMINPOUT_H_ */

/** \brief muestra un menu principal y se pide el ingreso de una de las opciones
 *
 * \param pKilometraje float numero recibido que se muestra en el menu
 * \return int retorna el valor elegido en el menu
 *
 */
int mostrarMenuPrincipal(float kilometraje);



/** \brief muestra un submenu con dos opciones
 *
 * \param aerolineas float recibe un flotante como parametro y este se muestra en el menu
 * \param latam float recibe un flotante como parametro y este se muestra en el menu
 * \return int retorna la opcion elegida
 *
 */
int mostrarSubmenuPrecios(float aerolineas, float latam);


/** \brief muestra un menu de costos y se pide ingreso de una de las opciones
 *
 * \return char retorna el caracter seleccionado
 *
 */
char mostrarSubmenuCostos();


/** \brief pide numero al usuario y lo guarda en la variable apuntada
 *
 * \param pCifra float* puntero a numero
 * \return int retorna 1 si la funcion concluye con exito
 *
 */
int ingresarCifra(float* pCifra);

/** \brief carga datos de manera forzada para ser calculados
 *
 * \param pKilometros float* puntero a variable kilometros
 * \param pPrecioAero float* puntero a variable precio Aerolineas
 * \param pPrecioLatam float* puntero a variable precio Latam
 * \return int retorna 1 si la funcion concluye satisfactoriamente
 *
 */
int cargaForzada(float* pKilometros, float* pPrecioAero, float* pPrecioLatam);


/** \brief recibe datos los calcula y los muestra por pantalla
 *
 * \param kilometros float
 * \param precioAerolineas float
 * \param precioLatamLatam float
 * \return int retorna 1 si la funcion concluye satisfactoriamente
 *
 */
int mostrarResultadosF(float kilometros, float precioAerolineas, float precioLatamLatam);
