#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "inputs.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE *pFile, LinkedList *pArrayListPassenger) {
	int retorno = 0;
	if (pFile != NULL && pArrayListPassenger != NULL) {
		Passenger *pasajero;
		char buffer[7][100];
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
				buffer[0], buffer[1], buffer[2], buffer[3], buffer[4],       //lectura fantasma
				buffer[5], buffer[6]);

		while (!feof(pFile)) {
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
					buffer[0], buffer[1], buffer[2], buffer[3], buffer[4],
					buffer[5], buffer[6]);

			pasajero =  Passenger_newParametros(buffer[0],
					buffer[1], buffer[2], buffer[3], buffer[4], buffer[5],
					buffer[6]);
			ll_add(pArrayListPassenger, pasajero);
			retorno=1;
		}
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

	return 1;
}

