#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

int parser_PassengerFromText(FILE *pFile, LinkedList *pArrayListPassenger);
int parser_PassengerFromBinary(FILE *pFile, LinkedList *pArrayListPassenger);
#endif // PARSER_H_INCLUDED
