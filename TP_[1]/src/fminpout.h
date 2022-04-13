/*
 * fminpout.h
 *
 *  Created on: 4 abr. 2022
 *      Author: Federico Muñoz 1G Dni 32378420
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "fmmath.h"
#ifndef FMINPOUT_H_
#define FMINPOUT_H_



#endif /* FMINPOUT_H_ */

/** \brief pide numero al usuario y lo guarda en la variable apuntada
 *
 * \param pCifra float* puntero a numero
 * \return int retorna 1 si la funcion concluye con exito
 *
 */
int ingresarCifra(float* pCifra);

/** \brief muestra un menu principal y se pide el ingreso de una de las opciones
 *
 * \param pKilometraje float numero recibido que se muestra en el menu
 * \param aerolineas float recibe valor aerolineas
 * \param latam float recibe valor latam
 * \return int retorna el valor elegido en el menu
 *
 */
int mostrarMenuPrincipal(float Kilometraje, float aerolineas, float latam);



/** \brief muestra un submenu con dos opciones
 *
 * \return int retorna la opcion elegida
 *
 */
float mostrarSubmenuPrecios();


/** \brief carga datos de manera forzada
 *
 * \param pKilometros float* carga variable kilometros
 * \param pPrecioAero float* carga variable Aerolineas
 * \param pPrecioLatam float* carga variable Latam
 * \param km float  kilometros
 * \param precio1 float precio1
 * \param precio2 float precio2
 * \return int
 *
 */
int cargaForzada(float* pKilometros, float* pPrecioAero, float* pPrecioLatam, float km, float precio1, float precio2);


/** \brief
 *
 * \param flag1 int* flag1
 * \param flag2 int* flag2
 * \param flag3 int* flag3
 * \param argumento int argumento para inicializar banderas en 1 o 0
 * \return int
 *
 */
int hardcodearBanderas(int* flag1, int* flag2, int* flag3, int argumento);


/** \brief toma los resultados a mostrar
 *
 * \param km float kilometros
 * \param precio float precio
 * \param rDesc float resultado del descuento
 * \param rInt float resultado del interes
 * \param rBtc float resultado Bitcoin
 * \param rUni float resultado precio unitario
 * \param mensaje char[] mensaje a mostrar
 * \return int retorna 1 si la funcion concluye satisfactoriamente
 *
 */
int informarResultados(float km, float precio,float rDesc, float rInt, float rBtc, float rUni, char mensaje[]);

/** \brief valida el ingreso de un char
 *
 * \param char1 caracter de referencia
 * \param char2 char caracter de referencia
 * \return char retorna el char coincidente con el ingreso
 *
 */
char ingresarChar(char char1, char char2);
