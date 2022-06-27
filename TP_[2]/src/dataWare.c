/*
 * dataWare.c
 *
 *  Created on: 15 may. 2022
 *      Author: Federico Muñoz
 */

#include "dataWare.h"

char name[20][51] = { "gustavo", "patricia", "pedro", "fernando", "lorena",
		"damian", "gisela", "norberto", "luis", "mirtha", "pedro", "patricio",
		"gonzalo", "facundo", "anastacia", "camila", "garbiela", "nestor",
		"lara", "monica" };

char lastName[20][51] = { "fernandez", "Diaz", "cordoba", "tortora",
		"gallinger", "zotelo", "Anderson", "bologna", "fernandez", "munoz",
		"gonzalez", "smith", "perez", "medina", "robledo", "sosa", "zanetti",
		"jimenez", "coria", "culini" };

float price[20] = { 112.25, 145.45, 875.25, 362.5, 741.98, 199.3, 452.66, 158.7,
		223.5, 331.4, 212.25, 745.45, 475.25, 162.5, 341.98, 199.3, 752.66,
		158.7, 923.5, 431.4 };

char flycode[20][10] = { "uhj456s", "hhd564d", "plk567e", "asd7342", "jahi345",
		"kjd5j43", "sjph333", "plk00v9", "wese221", "uyas123", "ugg5f56", "bhuu864",
		"pgzh667", "hjh7x88", "jakiv45", "kjd0o09", "uyh3693", "p4lp009", "ws9d341",
		"all8231" };

int typePassenger[20] = { 3, 2, 1, 2, 1, 2, 1, 2, 3, 3, 3, 2, 1, 2, 1, 2, 1, 2,
		3, 3 };
int statusFlight[20] = { 20, 10, 20, 20, 130, 10, 20, 10, 30, 30, 20, 10, 30,
		20, 10, 30, 10, 10, 30, 20 };

int hardcodearPassengers(Passenger *list, int len, int cant) {
	if (list != NULL && len > 0 && cant > 0 && cant <= len) {
		for (int i = 0; i < cant; i++) {
			list[i].id = incrementarId();
			strcpy(list[i].name, name[i]);
			strcpy(list[i].lastName, lastName[i]);
			list[i].price = price[i];
			strcpy(list[i].flycode, flycode[i]);
			list[i].typePassenger = typePassenger[i];
			list[i].statusFlight = statusFlight[i];
			list[i].isEmpty = 0;
		}
	}
	return 0;
}

int idType[3] = { 1, 2, 3 };
char descripcionType[3][20] = { "TURISTA", "EJECUTIVO", "1ra CLASE" };

int idStatus[3] = { 10, 20, 30 };
char descripcionStatus[3][20] = { "ACTIVO", "DEMORADO", "EN DESTINO" };

int hardcodearTypePassenger(eTypePassenger *listType, int tamType) {
	int retorno = 0;
	if (listType != NULL && tamType > 0) {
		for (int i = 0; i < tamType; i++) {
			listType[i].id = idType[i];
			strcpy(listType[i].descripcion, descripcionType[i]);
		}
		retorno = 1;
	}
	return retorno;
}

int hardcodearStatus(eStatusFlight *listStatus, int tamStatus) {
	int retorno = 0;
	if (listStatus != NULL && tamStatus > 0) {
		for (int i = 0; i < tamStatus; i++) {
			listStatus[i].id = idStatus[i];
			strcpy(listStatus[i].descripcion, descripcionStatus[i]);
		}
		retorno = 1;
	}
	return retorno;
}

