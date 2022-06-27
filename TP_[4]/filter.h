#ifndef FILTER_H_INCLUDED
#define FILTER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "Passenger.h"

int filtrarFirstClass(void* a);
int filtrarExecutiveClass(void* a);
int filtrarEconomyClass(void* a);
int filtrarRangoPrecio(void* a, float b, float c);
int filtrarDemorado(void* a);
int filtrarEnVuelo(void* a);
int filtrarEnHorario(void* a);
int filtrarAterrizado(void* a);

#endif // FILTER_H_INCLUDED
