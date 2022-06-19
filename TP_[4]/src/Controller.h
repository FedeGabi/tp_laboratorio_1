/*
 * Controller.h
 *
 *  Created on: 18 jun. 2022
 *      Author: fedec
 */


#ifndef CONTROLLER_H_
#define CONTROLLER_H_
#include "LinkedLIst.h"

int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int controller_mayorId();
LinkedList*  controllerFilter(LinkedList *pArrayListPassenger);
LinkedList* controller_sublist(LinkedList *pArrayListPassenger);
LinkedList* controller_clonAll(LinkedList *pArrayListPassenger);

#endif /* CONTROLLER_H_ */
