#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"

/****************************************************
 Menu:
 1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
 2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).
 3. Alta de pasajero
 4. Modificar datos de pasajero
 5. Baja de pasajero
 6. Listar pasajeros
 7. Ordenar pasajeros
 8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
 9. Guardar los datos de los pasajeros en el archivo data.bin (modo binario).
 10. Salir
 *****************************************************/

int main() {
	setbuf(stdout, NULL);
	char seguir = 's';
	int flagText = 0;
	int flagBin = 0;
	LinkedList *listaPasajeros = ll_newLinkedList();
	if (listaPasajeros == NULL) {
		printf("NO SE PUDO CONSEGUIR MEMORIA");
		exit(1);
	}

	do {
		switch (menu()) {
		case 1:
			if (controller_loadFromText("data.csv", listaPasajeros)) {
				flagText = 1;
			}
			break;
		case 2:
			if (controller_loadFromBinary("data.bin", listaPasajeros)) {
				flagBin = 1;
			}
			break;
		case 3:
            if(controller_addPassenger(listaPasajeros))
            {
                printf("\nALTA DE PASAJERO EXITOSA!!\n");
                system("pause");
            }
			break;
		case 4:
			if (ll_len(listaPasajeros) > 0) {
				controller_editPassenger(listaPasajeros);
			} else {
				printf("AUN NO SE CARGARON PASAJEROS\n");
				system("pause");
			}
			break;
		case 5:
			if (ll_len(listaPasajeros) > 0) {
				controller_removePassenger(listaPasajeros);
			} else {
				printf("AUN NO SE CARGARON PASAJEROS\n");
				system("pause");
			}
			break;
		case 6:
			if (ll_len(listaPasajeros) > 0) {
				controller_ListPassenger(listaPasajeros);
			} else {
				printf("AUN NO SE CARGARON PASAJEROS\n");
				system("pause");
			}
			break;
		case 7:
			if (ll_len(listaPasajeros) > 0) {
				controller_sortPassenger(listaPasajeros);
			} else {
				printf("AUN NO SE CARGO UN ARCHIVO\n");
				system("pause");
			}
			break;
		case 8:
			if (ll_len(listaPasajeros) > 0) {
				controller_saveAsText("data.csv", listaPasajeros);
			} else {
				printf("AUN NO SE CARGO UN ARCHIVO\n");
				system("pause");
			}
			break;
		case 9:
			if (ll_len(listaPasajeros) > 0) {
				controller_saveAsBinary("data.bin", listaPasajeros);
			} else {
				printf("AUN NO SE CARGO UN ARCHIVO\n");
				system("pause");
			}
			break;
		case 10:
			if (flagBin || flagText) {
				seguir = 'n';
			} else {
				printf("\nNO SE HA GUARDADO NINGUN ARCHIVO");
				system("pause");
			}
			break;
		default:
			printf("\nOPCION INVALIDA");
			system("pause");
			break;
		}

	} while (seguir == 's');
	ll_deleteLinkedList(listaPasajeros);
	return EXIT_SUCCESS;
}
