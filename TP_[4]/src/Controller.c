#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "Passenger.h"
#include "Parser.h"
#include "ordenamientos.h"
#include "Controller.h"
#include "filters.h"
#include "LinkedList.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char *path, LinkedList *pArrayListPassenger) {
	int retorno = 0;
	if (path != NULL && pArrayListPassenger != NULL) {
		FILE *pFile = fopen(path, "r");
		if (pFile != NULL) {												// recorro el archivo de texto
			if (!parser_PassengerFromText(pFile, pArrayListPassenger)) {   //con parser cargo lo q hay en el archivo un array de pasajeros

			}
			fclose(pFile);
			pFile = NULL;
			retorno = 1;
		}
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListPassenger) {
	int retorno = 0;
	if (path != NULL && pArrayListPassenger != NULL) {
		FILE *pFile = fopen(path, "rb");
		if (pFile != NULL) {
			if (parser_PassengerFromBinary(pFile, pArrayListPassenger)) {
				retorno = 1;
			} else {

			}
		}
		fclose(pFile);
		pFile = NULL;
	}
	return retorno;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList *pArrayListPassenger) {
	int retorno = 0;
	Passenger *pasajero = Passenger_new();
	if (pArrayListPassenger != NULL && pasajero != NULL) {
		int idNext;
		char auxNombre[50];
		char auxApellido[50];
		float auxPrecio;
		char tipoPasajero[50];
		char codigoVuelo[50];
		char estadoVuelo[50];
		if (ingresarValidarNombre(auxNombre, 2, 50, "\nIngrese nombre: ")
				&& ingresarValidarNombre(auxApellido, 2, 50,"\nIngrese apellido: ")
				&& ingresarFloat(&auxPrecio, "\nIngrese Precio: ")
				&& ingresarValidarCadena(codigoVuelo, 7, 7,"\nIngrese codigo de vuelo: ","\nError, el codigo de vuelo debe tener 7 caracteres")
				&& menuIngresarTipoPasajero(tipoPasajero)
				&& menuIngresarEstadoVuelo(estadoVuelo))
		{
			if ((Passenger_setNombre(pasajero, auxNombre)
					&& Passenger_setApellido(pasajero, auxApellido)
					&& Passenger_setPrecio(pasajero, auxPrecio)
					&& Passenger_setTipoPasajero(pasajero, tipoPasajero)
					&& Passenger_setCodigoVuelo(pasajero, codigoVuelo)
					&& Passenger_setEstadoVuelo(pasajero, estadoVuelo)))
			{
				idNext = controller_mayorId();  // genero el ingremento del ID
				Passenger_setId(pasajero, (idNext + 1));
				ll_add(pArrayListPassenger, pasajero);
				controller_saveAsText("idNext.csv", pArrayListPassenger);// guardo la nueva cantidad de IDs en el archivo dedicad
				retorno = 1;
			}
		}
		else
		{
			printf("\nAlta cancelada");
		}
	}
	return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList *pArrayListPassenger) {
	int retorno = 0;
	int seguir = 1;
	int id;
	int index;
	char auxNombre[50];
	char auxApellido[50];
	float auxPrecio;
	char tipoPasajero[50];
	char codigoVuelo[50];
	char estadoVuelo[50];
	Passenger *pasajero;
	if (pArrayListPassenger != NULL) {
		controller_ListPassenger(pArrayListPassenger);
		if (ingresarInt(&id, "\n Ingrese ID del Pasajero: ")) {
			index = findPassengerById(pArrayListPassenger, id);  // busco un elemento por ID y devuelvo su indice
			if (index == -1) {
				printf("\nEL ID NO COINCIDE CON NINGUN PASAJERO EXISTENTE\n");
				system("pause");
			} else {
				system("cls");
				pasajero = ll_get(pArrayListPassenger, index); //con el indice ingresado busco el elemento y lo retorno a pasajero
				mostrarPassenger(pasajero);
				if (pasajero != NULL
						&& confirmar(
								"\nDesea editar este Pasajero? (s o n): ")) {
					do {
						mostrarPassenger(pasajero);
						printf("\n");
						switch (menuEditPassenger()) {
						case 1:
							if (ingresarValidarNombre(auxNombre, 2, 50,   //valido q el nombre ingresado sea un dato valido
									"\nIngrese nombre: ")
									&& Passenger_setNombre(pasajero, // lo seteo en el aux pasajero
											auxNombre)) {
								printf("\nNombre editado con exito\n");
								system("pause");
							} else {
								printf("\nModificacion cancelada\n");
								system("pause");
							}
							break;
						case 2:
							if (ingresarValidarNombre(auxApellido, 2, 50,
									"\nIngrese nombre: ")
									&& Passenger_setApellido(pasajero,
											auxApellido)) {
								printf("\nApellido editado con exito\n");
								system("pause");
							} else {
								printf("\nModificacion cancelada\n");
								system("pause");
							}
							break;
						case 3:
							if (ingresarFloat(&auxPrecio, "\nIngrese Precio: ")
									&& Passenger_setPrecio(pasajero,
											auxPrecio)) {
								printf("\nPrecio editado con exito\n");
								system("pause");
							} else {
								printf("\nModificacion cancelada\n");
								system("pause");
							}
							break;
						case 4:
							if (ingresarValidarCadena(codigoVuelo, 7, 7,
									"\nIngrese codigo de vuelo: ",
									"\nError, el codigo de vuelo debe contener 7 caracteres")
									&& Passenger_setCodigoVuelo(pasajero,
											codigoVuelo)) {
								printf("\nCodigo de vuelo editado con exito\n");
								system("pause");
							} else {
								printf("\nModificacion cancelada\n");
								system("pause");
							}
							break;
						case 5:
							if (menuIngresarTipoPasajero(tipoPasajero)) {
								Passenger_setTipoPasajero(pasajero,
										tipoPasajero);
								printf(
										"\nTipo de pasajero editado con exito\n");
								system("pause");
							} else {
								printf("\nModificacion cancelada\n");
								system("pause");
							}
							break;
						case 6:
							if (menuIngresarEstadoVuelo(estadoVuelo)) {
								Passenger_setTipoPasajero(pasajero,
										estadoVuelo);
							} else {
								printf("\nModificacion cancelada\n");
								system("pause");
							}
							break;
						case 7:
							seguir = 0;
							break;
						}
					} while (seguir == 1);
				}
			}
		} else {
			printf("\nModificacion cancelada");
			system("pause");
		}
	}
	return retorno;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList *pArrayListPassenger) {
	int id;
	int index;
	Passenger *pasajero =  Passenger_new();
	if (pArrayListPassenger != NULL) {
		controller_ListPassenger(pArrayListPassenger);  //muestro la lista de pasajeros
		if (ingresarInt(&id, "\n Ingrese ID del Pasajero: ")) {
			index = findPassengerById(pArrayListPassenger, id);  //muestro al pasajero asociado con el ID ingresado
			if (index == -1) {
				printf("\nEL ID NO COINCIDE CON NINGUN PASAJERO EXISTENTE\n");
				system("pause");
			} else {
				system("cls");
				pasajero = ll_get(pArrayListPassenger, index);
				mostrarPassenger(pasajero);
				if (pasajero != NULL
						&& confirmar(
								"\nDesea eliminar este Pasajero? (s o n): ")) {
					ll_remove(pArrayListPassenger, index);			// elimino el elemento pasajero
				}
			}
		}
	}
	return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList *pArrayListPassenger) {
	int retorno = 0;
	int len;
	Passenger *pasajero = Passenger_new();
	if (pArrayListPassenger != NULL && pasajero != NULL) {
		len = ll_len(pArrayListPassenger);
		for (int i = 0; i < len; i++) {
			pasajero = (Passenger*) ll_get(pArrayListPassenger, i);		//muestro array de pasajeros
			mostrarPassenger(pasajero);
			retorno = 1;
		}
	}
	system("pause");
	return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList *pArrayListPassenger) {
	int retorno = 0;
	int seguir = 1;
	if (pArrayListPassenger != NULL) {
		do {
			switch (menuOrdenamiento()) {
			case 1:
				printf("\nOrdenando, aguarde unos segundos...\n");
				ll_sort(pArrayListPassenger, passengerSortId, 1); // ordenamiento por ID
				seguir = 0;
				break;
			case 2:
				printf("\nOrdenando, aguarde unos segundos...\n");
				ll_sort(pArrayListPassenger, passengerSortNombre, 1); //ordenamiento por nombre
				seguir = 0;
				break;
			case 3:
				printf("\nOrdenando, aguarde unos segundos...\n");
				ll_sort(pArrayListPassenger, passengerSortApellido, 1); // ordenamiento por apellido
				seguir = 0;
				break;
			case 4:
				printf("\nOrdenando, aguarde unos segundos...\n");
				ll_sort(pArrayListPassenger, passengerSortPrecio, 1); // ordenamiento por precio
				seguir = 0;
				break;
			case 5:
				printf("\nOrdenando, aguarde unos segundos...\n");
				ll_sort(pArrayListPassenger, passengerSortCodigoVuelo, 1); //ordenamiento por codigo de vuelo
				seguir = 0;
				break;
			case 6:
				printf("\nOrdenando, aguarde unos segundos...\n");
				ll_sort(pArrayListPassenger, passengerSortTipoPasajero, 1); // ordenamiento por tipo de pasajero
				seguir = 0;
				break;
			case 7:
				printf("\nOrdenando, aguarde unos segundos...\n");
				ll_sort(pArrayListPassenger, passengerSortEstadoVuelo, 1); // ordenamiento po estado de vuelo
				seguir = 0;
				break;
			case 8:
				seguir = 0;
				break;
			default:
				seguir = confirmar(
						"\nOpcion invalida. Desea reingresar? (s o n): ");
				break;
			}
		} while (seguir == 1);
		controller_ListPassenger(pArrayListPassenger); // muestro la lista ordenada
		retorno = 1;
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListPassenger) {
	int retorno = 0;
	Passenger *pasajero = Passenger_new();
	char auxTipoPasajero[20];
	if (path != NULL && pArrayListPassenger != NULL && pasajero != NULL) {
		FILE *pFile = fopen(path, "w");
		fprintf(pFile, "ID,NOMBRE,APELLIDO,PRECIO,CODVUELO,TIPO,ESTADO\n"); //formateo el encabezado
		for (int i = 0; i < ll_len(pArrayListPassenger); i++) { 		//recorro el array de pasajeros

			pasajero = (Passenger*) ll_get(pArrayListPassenger, i); //busco el elemento en el indice i y lo retorno en auxiliar pasajero
			Passenger_getTipoPasajero(pasajero, auxTipoPasajero);
			fprintf(pFile, "%d,%s,%s,%.0f,%s,%s,%s\n", pasajero->id,
					pasajero->nombre, pasajero->apellido, pasajero->precio,
					pasajero->codigoVuelo, auxTipoPasajero,
					pasajero->estadoVuelo);
		}
		ll_clear(pArrayListPassenger);
		printf("\nARCHIVO GUARDADO CON EXITO!\n");
		system("pause");
		fclose(pFile);
		retorno = 1;
	}
	return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListPassenger) {
	int retorno = 0;
	Passenger *auxPasajero = Passenger_new();
	if (path != NULL && pArrayListPassenger != NULL && auxPasajero != NULL) {
		FILE *pFile = fopen(path, "wb");										// abro el archivo en modo escritura binaria
		if (pFile != NULL) {				/// recorro el arhivo
			for (int i = 0; i < ll_len(pArrayListPassenger); i++) {
				auxPasajero = (Passenger*) ll_get(pArrayListPassenger, i);  // busco el elemento en indice i y lo retorno al auxiliar
				fwrite(auxPasajero, sizeof(Passenger), 1, pFile);  //escribo el contenido de auxPasajero en el archivo binario
			}
			printf("\nARCHIVO GUARDADO CON EXITO!\n");
			system("pause");
			auxPasajero = NULL;
			fclose(pFile);
			pFile = NULL;
			retorno = 1;
		}
	}
	return retorno;
}

//////////////     CONTROLLER SAVES IDs        ////////////

/** \brief devuelve el id mas grande de un archivo.csv
 *
 * \return int retorna el valor ID mas alto
 *
 */
int controller_mayorId() {
	int cant = 0;
	int maxID = 0;
	char buffer[7][100];
	Passenger *pasajero = Passenger_new();
	FILE *pFile = fopen("idNext.csv", "r"); // abro modo lectura el archivo dedicado q contiene los IDs
	if (pFile == NULL) {
		printf("\nNo se pudo reservar memoria");
		exit(1);
	}
	cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
			buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], //lectura fantasma
			buffer[5], buffer[6]);
	while (!feof(pFile)) {

		cant = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",
				buffer[0], buffer[1], buffer[2], buffer[3], buffer[4], //guardo datos en buffer
				buffer[5], buffer[6]);

		if (cant == 7 && pasajero != NULL) {
			pasajero = Passenger_newParametros(buffer[0], buffer[1], buffer[2],
					buffer[3],     //agrego los parametros al Passenger auxiliar
					buffer[4], buffer[5], buffer[6]);
			if (pasajero->id > maxID) {
				maxID = pasajero->id; //recorro el array evaluando condicion de mayor numero y asignando ese mayor a la variable
			}
		}
	}
	pasajero = NULL;
	fclose(pFile);
	return maxID; //retorno el valor del id mas alto
}

/////////////      filtrar      /////////////

LinkedList* controllerFilter(LinkedList *pArrayListPassenger) {
	int seguir = 1;
	int opcion;
	char auxCad[20];
	LinkedList* nuevaLista=NULL;
	if (pArrayListPassenger != NULL) {
		do {
			switch (menuFiltrarNuevoLinkedList()) {
			case 1:
				opcion = menuIngresarTipoPasajero(auxCad);
				if (opcion == 1) {
					nuevaLista = ll_filter(pArrayListPassenger,	filtrarFirstClass); // filtro por tipo primera clase
				} else if (opcion == 2) {
					nuevaLista = ll_filter(pArrayListPassenger,filtrarExecutiveClass); // filtro por tipo clase ejecutiva
				} else if (opcion == 3) {
					nuevaLista = ll_filter(pArrayListPassenger,filtrarEconomyClass); // filtro por tipo clase economica
				}
				seguir = 0;
				break;
			case 2:
				system("cls");
				opcion = menuIngresarEstadoVuelo(auxCad);
				if (opcion == 1) {
					nuevaLista = ll_filter(pArrayListPassenger,filtrarAterrizado); // filtro por estadod en vuelo Aterrizado
				} else if (opcion == 2) {
					nuevaLista = ll_filter(pArrayListPassenger,filtrarEnHorario); // filtro por estadod en vuelo En horario
				} else if (opcion == 3) {
					nuevaLista = ll_filter(pArrayListPassenger,	filtrarEnVuelo); // filtro por estadod en vuelo En vuelo
				} else if (opcion == 4) {
					nuevaLista = ll_filter(pArrayListPassenger,	filtrarDemorado); // filtro por estadod e vuelo Demorado
				}
				seguir = 0;
				break;
			case 3:
				seguir = 0;
				break;
			default:
				seguir = confirmar(
						"\nOpcion invalida. Desea reingresar? (s o n): ");
				break;
			}
		} while (seguir == 1);
		printf("\n******** NUEVA LISTA ************\n");
		controller_ListPassenger(nuevaLista);
	}
	return nuevaLista;
}

LinkedList* controller_sublist(LinkedList *pArrayListPassenger) {

	LinkedList* nuevaLista=NULL;
	if (pArrayListPassenger != NULL) {
		int seguir = 1;
		int rangMin;
		int rangMax;

		do {
			ingresarInt(&rangMin, "\nIngrese el indice inicial: ");
			ingresarInt(&rangMax, "\nIngrese el indice final: ");
			if (rangMin > 0 && rangMin < rangMax&& rangMax < ll_len(pArrayListPassenger)) {
				nuevaLista = ll_subList(pArrayListPassenger, rangMin,rangMax);
				seguir = 0;
			} else {
				seguir = confirmar(	"\nError, desea volver a ingresar los datos?(s o n): ");
			}
		} while (seguir == 1);
	}
	return nuevaLista;
}

LinkedList* controller_clonAll(LinkedList *pArrayListPassenger) {
	LinkedList* nuevaLista=NULL;
	if (pArrayListPassenger != NULL) {

		nuevaLista = ll_clone(pArrayListPassenger);
	}
	return nuevaLista;
}
