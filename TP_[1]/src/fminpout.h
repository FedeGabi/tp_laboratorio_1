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
int mostrarSubmenuPrecios();


/** \brief muestra un menu de costos y se pide ingreso de una de las opciones
 *
 * \return char retorna el caracter seleccionado
 *
 */
char mostrarSubmenuCostos();


/** \brief carga datos de manera forzada
 *
 * \param pKilometros float* carga kilometros
 * \param pPrecioAero float* carga precio Aerolineas
 * \param pPrecioLatam float* carga precio Latam
 * \return int
 *
 */
int cargaForzada(float* pKilometros, float* pPrecioAero, float* pPrecioLatam);


/** \brief
 *
 * \param des1 int* flag descuento
 * \param des2 int* flag descuento2
 * \param inter1 int* flag interes
 * \param inter2 int* flag interes2
 * \param btc1 int* flag Bitcoin
 * \param btc2 int* flag Bitcoin2
 * \param uni1 int* flag precio unitario1
 * \param uni2 int* flag precio unitario2
 * \param argumento int argumento para inicializar banderas en 1 o 0
 * \return int
 *
 */
int hardcodearBanderas(int* des1, int* des2, int* inter1, int* inter2, int* btc1, int* btc2, int* uni1, int* uni2, int argumento);


/** \brief toma los resultados a mostrar
 *
 * \param km float kilometros
 * \param precio float precio
 * \param desc int flag descuento
 * \param inter int flag interes
 * \param btc int flag Bitcoin
 * \param uni int flag Precio unitario por Km
 * \param rDesc float resultado del descuento
 * \param rInt float resultado del interes
 * \param rBtc float resultado Bitcoin
 * \param rUni float resultado precio unitario
 * \param mensaje char[] mensaje a mostrar
 * \return int retorna 1 si la funcion concluye satisfactoriamente
 *
 */
int mostrarPrecios(float km, float precio, int desc, int inter, int btc, int uni,float rDesc, float rInt, float rBtc, float rUni, char mensaje[]);
