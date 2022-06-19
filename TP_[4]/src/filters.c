/*
 * filters.c
 *
 *  Created on: 18 jun. 2022
 *      Author: fedec
 */
#include "filters.h"


int filtrarFirstClass(void* a)
{
	int retorno=0;
	if(a != NULL)
	{
		Passenger* pasajero = (Passenger*) a;
		if(pasajero->tipoPasajero ==1)
		{
			retorno=1;
		}
	}
	return retorno;
}
int filtrarExecutiveClass(void* a)
{
	int retorno=0;
	if(a != NULL)
	{
		Passenger* pasajero = (Passenger*) a;
		if(pasajero->tipoPasajero ==2)
		{
			retorno=1;
		}
	}
	return retorno;
}
int filtrarEconomyClass(void* a)
{
	int retorno=0;
	if(a != NULL)
	{
		Passenger* pasajero = (Passenger*) a;
		if(pasajero->tipoPasajero ==3)
		{
			retorno=1;
		}
	}
	return retorno;
}
int filtrarRangoPrecio(void* a, float b, float c)
{
	int retorno=0;
	if(a != NULL && b<c)
	{
		Passenger* pasajero = (Passenger*)a;
		if(pasajero->precio >= b && pasajero->precio <=c )
		{
			retorno=1;
		}
	}
	return retorno;
}





int filtrarAterrizado(void* a)
{
	int retorno=0;
	if(a != NULL)
	{
		Passenger* pasajero = (Passenger*) a;
		if(strcmp(pasajero->estadoVuelo,"Aterrizado")==0)
		{
			retorno=1;
		}
	}
	return retorno;
}
int filtrarEnHorario(void* a)
{
	int retorno=0;
	if(a != NULL)
	{
		Passenger* pasajero = (Passenger*) a;
		if(strcmp(pasajero->estadoVuelo,"En Horario")==0)
		{
			retorno=1;
		}
	}
	return retorno;
}
int filtrarEnVuelo(void* a)
{
	int retorno=0;
	if(a != NULL)
	{
		Passenger* pasajero = (Passenger*) a;
		if(strcmp(pasajero->estadoVuelo,"En Vuelo")==0)
		{
			retorno=1;
		}
	}
	return retorno;
}


int filtrarDemorado(void* a)
{
	int retorno=0;
	if(a != NULL)
	{
		Passenger* pasajero = (Passenger*) a;
		if(strcmp(pasajero->estadoVuelo,"Demorado")==0)
		{
			retorno=1;
		}
	}
	return retorno;
}
