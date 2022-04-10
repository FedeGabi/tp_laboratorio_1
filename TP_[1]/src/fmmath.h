/*
 * fmmath.h
 *
 *  Created on: 4 abr. 2022
 *      Author: Federico Muñoz 1G Dni 32378420
 */

#include <stdio.h>
#include <stdlib.h>
#ifndef FMMATH_H_
#define FMMATH_H_



#endif /* FMMATH_H_ */

/** \brief recibe monto y porcentaje de descuento a ser aplicado
 *
 * \param monto float cifra a la cual se le calcula el descuento
 * \param descuentoAsig float porcentaje de descuento
 * \param resultado float* puntero a resultado
 * \return int retorna 1 si la funcion concluye satisfactoriamente
 *
 */
int calcularDescuento(float monto, float descuentoAsig, float* pResultado);


/** \brief recibe monto e interes a ser aplicado
 *
 * \param monto float cifra a la cual se le calcula interes
 * \param interesAsig float porcentaje de interes
 * \param resultado float* puntero a resultado
 * \return int retorna 1 si la funcion concluye satisfactoriamente
 *
 */
int calcularInteres(float monto, float interesAsig, float* pResultado);

/** \brief calcula monto de Bitcoin por cantidad de pesos ingresados
 *
 * \param monto float monto en pesos ingresado
 * \param valorUnBtc float precio unitario Bitcoin
 * \param resultado float* puntero a variable resultado
 * \return int retorna 1 si la funcion concluye satisfactoriamente
 *
 */
int calcularBtc(float monto, float valorUnBtc, float* pResultado);


/** \brief calcula la diferencia del numero mas grande, menos el mas chico
 *
 * \param monto1 float monto1
 * \param monto2 float monto2
 * \param resultado float* puntero a resultado
 * \return int retorna 0 si monto1 es mas grande que monto2. Y rtorna 1 si el monto2 es mas grande que monto1
 *
 */
int diferenciaPrecio(float monto1, float monto2, float* pResultado);


/** \brief precio calcula el precio unitario entre dos montos
 *
 * \param precio float precio
 * \param kilometros float kilomeros
 * \param resultado float* puntero a resultado
 * \return int retorna 1 si la funcion concluye satisfactoriamente
 *
 */
int calcularPrecioUnitario(float precio, float kilometros, float* pResultado);
