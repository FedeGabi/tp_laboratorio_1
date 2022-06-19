#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "inputs.h"
#include "Parser.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE *pFile, LinkedList *pArrayListPassenger) {
	int retorno = 0;
	Passenger *pasajero;
	if (pFile != NULL && pArrayListPassenger != NULL) {
		int cant;
		char buffer[7][100];
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", buffer[0],
				buffer[1], buffer[2], buffer[3], buffer[4],   //lectura fantasma
				buffer[5], buffer[6]);
		ll_clear(pArrayListPassenger);
		while (!feof(pFile)) {

			cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					buffer[0], buffer[1], buffer[2], buffer[3], buffer[4],
					buffer[5], buffer[6]);

			if (cant == 7 && pasajero != NULL) {
				pasajero = Passenger_newParametros(buffer[0], buffer[1],
						buffer[2], buffer[3], buffer[4], buffer[5], buffer[6]);
				ll_add(pArrayListPassenger, pasajero);
				retorno = 1;

			} else {
				printf("[error] - parser no completado\n");
				exit(1);
			}
		}
		//Passenger_delete(pasajero);
		pasajero = NULL;
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE *pFile, LinkedList *pArrayListPassenger) {

	int retorno = 0;
	int cant = 0;
	Passenger *auxPassenger = NULL;
	if (pFile != NULL && pArrayListPassenger != NULL) {
		ll_clear(pArrayListPassenger);
		while (!feof(pFile)) {
			auxPassenger = Passenger_new();
			cant = fread(auxPassenger, sizeof(Passenger), 1, pFile);
			if (cant != 1) {
				break;
			}
			ll_add(pArrayListPassenger, auxPassenger);
			retorno = 1;
		}
		auxPassenger = NULL;
	}
	return retorno;
}

