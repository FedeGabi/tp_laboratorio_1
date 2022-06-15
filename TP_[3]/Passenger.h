/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"

typedef struct {
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[7];
	int tipoPasajero;
	char estadoVuelo[50];
} Passenger;

Passenger* Passenger_new();

Passenger* Passenger_newParametros(char *idStr, char *nombreStr,
		char *apellidoStr, char *strPrecio,
		char *strFlyCode, char *strTipoPasajero,
		char *strEstVue);

void Passenger_delete(Passenger *passenger);

int Passenger_setId(Passenger *this, int id);
int Passenger_getId(Passenger *this, int *id);

int Passenger_setNombre(Passenger *this, char *nombre);
int Passenger_getNombre(Passenger *this, char *nombre);

int Passenger_setApellido(Passenger *this, char *apellido);
int Passenger_getApellido(Passenger *this, char *apellido);

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo);
int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo);

int Passenger_setTipoPasajero(Passenger *this, char *tipoPasajero);
int Passenger_getTipoPasajero(Passenger *this, char *tipoPasajero);

int Passenger_setPrecio(Passenger *this, float precio);
int Passenger_getPrecio(Passenger *this, float *precio);

int Passenger_setEstadoVuelo(Passenger *this, char *estadoVuelo);
int Passenger_getEstadoVuelo(Passenger *this, char *estadoVuelo);

int mostrarPassengersList(LinkedList *listaPasajeros);
void mostrarPassenger(Passenger *pasajero);

int incrementarId(LinkedList* pArrayListPassenger);
int findPassengerById(LinkedList *pArrayListPassenger, int id);

#endif /* PASSENGER_H_ */
