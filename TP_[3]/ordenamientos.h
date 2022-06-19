/*
 * ordenamientos.h
 *
 *  Created on: 7 jun. 2022
 *      Author: fedec
 */

#ifndef ORDENAMIENTOS_H_
#define ORDENAMIENTOS_H_
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "Passenger.h"

int passengerSortNombre(void* a, void* b);
int passengerSortApellido(void* a, void* b);
int passengerSortPrecio(void* a, void* b);
int passengerSortCodigoVuelo(void* a, void* b);
int passengerSortId(void* a, void* b);
int passengerSortEstadoVuelo(void* a, void* b);
int passengerSortTipoPasajero(void* a, void* b);

#endif /* ORDENAMIENTOS_H_ */
