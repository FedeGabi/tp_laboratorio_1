/*
 * ordenamientos.c
 *
 *  Created on: 7 jun. 2022
 *      Author: fedec
 */

#include "ordenamientos.h"

int passengerSortNombre(void *a, void *b) {
	int retorno = 0;
	if (a != NULL && b != NULL) {
		Passenger *pasajero1 = (Passenger*) a;
		Passenger *pasajero2 = (Passenger*) b;
		retorno = strcmp(pasajero1->nombre, pasajero2->nombre);
	}
	return retorno;
}

int passengerSortApellido(void *a, void *b) {
	int retorno = 0;
	if (a != NULL && b != NULL) {
		Passenger *pasajero1 = (Passenger*) a;
		Passenger *pasajero2 = (Passenger*) b;
		retorno = strcmp(pasajero1->apellido, pasajero2->apellido);
	}
	return retorno;
}

int passengerSortPrecio(void *a, void *b) {
	int retorno = -2;
	if (a != NULL && b != NULL) {
		Passenger *pasajero1 = (Passenger*) a;
		Passenger *pasajero2 = (Passenger*) b;
		if (pasajero1->precio > pasajero2->precio) {
			retorno = 1;
		} else if (pasajero1->precio < pasajero2->precio) {
			retorno = -1;
		} else if (pasajero1->precio == pasajero2->precio) {
			retorno = 0;
		}
	}
	return retorno;
}

int passengerSortCodigoVuelo(void *a, void *b) {
	int retorno = -2;
	if (a != NULL && b != NULL) {
		Passenger *pasajero1 = (Passenger*) a;
		Passenger *pasajero2 = (Passenger*) b;
		if (strcmp(pasajero1->codigoVuelo, pasajero2->codigoVuelo) == 1) {
			retorno = 1;
		} else if (strcmp(pasajero1->codigoVuelo, pasajero2->codigoVuelo)
				== -1) {
			retorno = -1;
		} else if (strcmp(pasajero1->codigoVuelo, pasajero2->codigoVuelo)
				== 0) {
			retorno = 0;
		}
	}
	return retorno;
}

int passengerSortEstadoVuelo(void *a, void *b) {
	int retorno = -2;
	if (a != NULL && b != NULL) {
		Passenger *pasajero1 = (Passenger*) a;
		Passenger *pasajero2 = (Passenger*) b;
		if (strcmp(pasajero1->estadoVuelo, pasajero2->estadoVuelo) == 1) {
			retorno = 1;
		} else if (strcmp(pasajero1->estadoVuelo, pasajero2->estadoVuelo)
				== -1) {
			retorno = -1;
		} else if (strcmp(pasajero1->estadoVuelo, pasajero2->estadoVuelo)
				== 0) {
			retorno = 0;
		}
	}
	return retorno;
}

int passengerSortTipoPasajero(void *a, void *b) {
	int retorno = -2;
	if (a != NULL && b != NULL) {
		Passenger *pasajero1 = (Passenger*) a;
		Passenger *pasajero2 = (Passenger*) b;
		if (pasajero1->tipoPasajero < pasajero2->tipoPasajero) {
			retorno = 1;
		} else if (pasajero1->tipoPasajero > pasajero2->tipoPasajero) {
			retorno = -1;
		} else if (pasajero1->tipoPasajero == pasajero2->tipoPasajero) {
			retorno = 0;
		}
	}
	return retorno;
}

int passengerSortId(void *a, void *b) {
	int retorno = -2;
	if (a != NULL && b != NULL) {
		Passenger *pasajero1 = (Passenger*) a;
		Passenger *pasajero2 = (Passenger*) b;
		if (pasajero1->id > pasajero2->id) {
			retorno = 1;
		} else if (pasajero1->precio < pasajero2->precio) {
			retorno = 0;
		}
	}
	return retorno;
}
