/*
 * Parser.h
 *
 *  Created on: 18 jun. 2022
 *      Author: fedec
 */

#ifndef PARSER_H_
#define PARSER_H_



int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger);
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger);

#endif /* PARSER_H_ */
