/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "Passenger.h"
#include "LinkedList.h"
#include "inputs.h"

/////////////////  CONSTRUCTORES    /////////////////

Passenger* Passenger_new() {
	Passenger *pasajero = (Passenger*) calloc(sizeof(Passenger), 1);
	return pasajero;
}

Passenger* Passenger_newParametros(char *idStr, char *nombreStr,
		char *apellidoStr, char *strPrecio, char *strFlyCode,
		char *strTipoPasajero, char *strEstVue) {

	Passenger *pasajero = Passenger_new();

	int auxId;
	float auxPrecio;

	auxId = atoi(idStr);
	auxPrecio = atof(strPrecio);

	if (pasajero != NULL && idStr != NULL && nombreStr != NULL
			&& apellidoStr != NULL && strPrecio != NULL && strFlyCode != NULL
			&& strTipoPasajero != NULL && strEstVue != NULL) {
		if (!(Passenger_setId(pasajero, auxId)
				&& Passenger_setNombre(pasajero, nombreStr)
				&& Passenger_setApellido(pasajero, apellidoStr)
				&& Passenger_setPrecio(pasajero, auxPrecio)
				&& Passenger_setCodigoVuelo(pasajero, strFlyCode)
				&& Passenger_setTipoPasajero(pasajero, strTipoPasajero)
				&& Passenger_setEstadoVuelo(pasajero, strEstVue))) {
			pasajero = NULL;
		}
	}
	return pasajero;
}

/////////////////  SETTERS & GETTERS    /////////////////

int Passenger_setId(Passenger *this, int id) {
	int retorno = 0;
	if (this != NULL && id > 0) {
		this->id = id;
		retorno = 1;
	}
	return retorno;
}

int Passenger_getId(Passenger *this, int *id) {
	int retorno = 0;
	if (this != NULL) {
		*id = this->id;
		retorno = 1;
	}
	return retorno;
}

int Passenger_setNombre(Passenger *this, char *nombre) {
	int retorno = 0;
	if (this != NULL && nombre != NULL && strlen(nombre) < 50
			&& strlen(nombre) > 1) {
		nombre = strlwr(nombre);
		nombre[0] = toupper(nombre[0]);
		strcpy(this->nombre, nombre);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getNombre(Passenger *this, char *nombre) {
	int retorno = 0;
	if (this != NULL && nombre != NULL) {
		strcpy(nombre, this->nombre);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setApellido(Passenger *this, char *apellido) {
	int retorno = 0;
	if (this != NULL && apellido != NULL && strlen(apellido) < 50
			&& strlen(apellido) > 1) {
		apellido = strlwr(apellido);
		apellido[0] = toupper(apellido[0]);
		strcpy(this->apellido, apellido);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getApellido(Passenger *this, char *apellido) {
	int retorno = 0;
	if (this != NULL && apellido != NULL) {
		strcpy(apellido, this->apellido);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger *this, char *codigoVuelo) {
	int retorno = 0;
	if (this != NULL && codigoVuelo != NULL && strlen(codigoVuelo) == 7) {
		strupr(codigoVuelo);
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getCodigoVuelo(Passenger *this, char *codigoVuelo) {
	int retorno = 0;
	if (this != NULL && codigoVuelo != NULL) {
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno = 1;
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger *this, char *tipoPasajero) {
	int retorno = 0;
	if (this != NULL && tipoPasajero != NULL) {
		if (strcmp(tipoPasajero, "FirstClass") == 0) {
			this->tipoPasajero = 1;
			retorno = 1;
		} else if (strcmp(tipoPasajero, "ExecutiveClass") == 0) {
			this->tipoPasajero = 2;
			retorno = 1;
		} else if (strcmp(tipoPasajero, "EconomyClass") == 0) {
			this->tipoPasajero = 3;
			retorno = 1;
		}
	}
	return retorno;
}

int Passenger_getTipoPasajero(Passenger *this, char *tipoPasajero) {
	int retorno = 0;
	if (this != NULL && tipoPasajero != NULL) {
		if (this->tipoPasajero == 1) {
			strcpy(tipoPasajero, "FirstClass");
			retorno = 1;
		} else if (this->tipoPasajero == 2) {
			strcpy(tipoPasajero, "ExecutiveClass");
			retorno = 1;
		} else if (this->tipoPasajero == 3) {
			strcpy(tipoPasajero, "EconomyClass");
			retorno = 1;
		}
	}
	return retorno;
}

int Passenger_setPrecio(Passenger *this, float precio) {
	int retorno = 0;
	if (this != NULL && precio > 0) {
		this->precio = precio;
		retorno = 1;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger *this, float *precio) {
	int retorno = 0;
	if (this != NULL && precio != NULL) {
		*precio = this->precio;
		retorno = 1;
	}
	return retorno;
}

int Passenger_setEstadoVuelo(Passenger *this, char *estadoVuelo) {
	int retorno = 0;
	if (this != NULL && (strlen(estadoVuelo) < 20 && strlen(estadoVuelo) > 4)) {
		strcpy(this->estadoVuelo, estadoVuelo);
		retorno = 1;
	}
	return retorno;
}

int Passenger_getEstadoVuelo(Passenger *this, char *estadoVuelo) {
	int retorno = 0;
	if (this != NULL && estadoVuelo != NULL) {
		strcpy(estadoVuelo, this->estadoVuelo);
		retorno = 1;
	}
	return retorno;
}

//DESTROY

void Passenger_delete(Passenger *passenger) {
	free(passenger);
}

/////////////////    MOSTRAR PASSENGER    /////////////////

void mostrarPassenger(Passenger *pasajero) {
	if (pasajero != NULL) {
		char auxCadena[20];
		Passenger_getTipoPasajero(pasajero, auxCadena);
		printf("%d, %s, %s, %.0f, %s, %s %s\n", pasajero->id, pasajero->nombre,
				pasajero->apellido, pasajero->precio, pasajero->codigoVuelo,
				auxCadena, pasajero->estadoVuelo);
	}
}

/////////////////     CARGA      /////////////////

int findPassengerById(LinkedList *pArrayListPassenger, int id) {
	int indice = -1;
	Passenger *pasajero;
	if (pArrayListPassenger != NULL && id > 0) {
		for (int i = 0; i < ll_len(pArrayListPassenger); i++) {
			pasajero = ll_get(pArrayListPassenger, i);
			if (pasajero->id == id) {
				indice = i;
				break;
			}
		}
	}
	pasajero = NULL;
	return indice;
}
