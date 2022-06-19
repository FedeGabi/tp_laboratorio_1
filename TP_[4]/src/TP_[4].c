/*
 ============================================================================
 Name        : TP_[4].c
 Author      : Muñoz Federico
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "inputs.h"
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"


int main() {
	setbuf(stdout, NULL);
	char seguir = 's';
	int flagText = 0;
	int flagBin = 0;
	LinkedList *listaPasajeros = ll_newLinkedList();
	LinkedList *filterList =ll_newLinkedList();
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
				controller_saveAsText("data.csv.csv", listaPasajeros);
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
			if (ll_len(listaPasajeros) > 0) {
				filterList=controller_sublist(listaPasajeros);
			}else {
				printf("AUN NO SE CARGO ELEMENTOS EN EL ARRAY PRINCIPAL\n");
				system("pause");
			}
			break;
		case 11:
			if (ll_len(listaPasajeros) > 0) {
				filterList=controllerFilter(listaPasajeros);

			}else {
				printf("AUN NO SE CARGO EL ARCHIVO PRINCIPAL\n");
				system("pause");
			}
			break;
		case 12:
			if (ll_len(listaPasajeros) > 0) {
				filterList=controller_clonAll(listaPasajeros);
				printf("\nLA LISTA SE HA CLONADO CON EXITO!\n");
				system("PAUSE");

			}else {
				printf("AUN NO SE CARGO ELEMENTOS EN EL ARRAY PRINCIPAL\n");
				system("pause");
			}
			break;
		case 13:
			if (ll_len(filterList) > 0) {
				controller_ListPassenger(filterList);
			} else {
				printf("AUN NO SE CARGARON PASAJEROS EN LA NUEVA LISTA\n");
				system("pause");
			}
			break;
		case 14:
			controller_loadFromText("filtrados.csv", filterList);
			break;
		case 15:
			if (ll_len(filterList)>0) {
				controller_saveAsText("filtrados.csv", filterList);
			}else {
				printf("\nNO SE HA CARGADO NINGUN ARCHIVO EN LA LISTA");
				system("pause");
			}
			break;
		case 16:
			if ((flagBin || flagText)) {
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
	ll_deleteLinkedList(filterList);
	return EXIT_SUCCESS;
}

