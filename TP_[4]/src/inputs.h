/*
 * inputs.h
 *
 *  Created on: 18 jun. 2022
 *      Author: fedec
 */

#ifndef INPUTS_H_
#define INPUTS_H_

int menuFiltrarNuevoLinkedList();

/** \brief menu ordenamiento
 *
 * \return int retorna la opcion seleccionada
 *
 */
int menuOrdenamiento();
/** \brief muestra menu de edicion de pasajeros
 *
 * \return int retorna la opcion seleccionada
 *
 */
int menuEditPassenger();

/** \brief muestra menu
 *
 * \return retorna la opcion seleccionada
 *
 */
int menu();
/** \brief muestra menu de opciones y pide el ingreso de un numero
 *
 * \return int retorna opcion seleccionada
 *
 */
int incrementarId();

/** \brief da formato y concatena Nombre y apellido
 *
 * \param pResultado[] cadena de caracteres resultante
 * \param cadena1[] char cadena 1
 * \param [] char cadena2 cadena2
 * \return int retorna 1 si la funcion concluye correctamente
 *
 */
int formatearNombres(char pResultado[],char cadena1[], char cadena2 []);

/** \brief muestra menu de opciones
 *
 * \return int retorna la opcion elegida
 *
 */
int mostrarMenuPrincipal();

/** \brief pide un numero flotante validando previamente su tipo de dato y si es un valor positivo
 *
 * \param pFloat float* variable que guarda el flotante resultante
 * \param [] char msj mensaje de pedido de flotante
 * \param msjError[] char mensaje de error
 * \param intentos int cantidad de intentos para ingresar
 * \return int retorna (-1) si se ingreso un caracter o un numero negativo, 0 si se ingreso 0, 1 si la funcion concluyo satisfactoriamente
 *
 */
int ingresarFloat(float *pFloat, char msj []);


/** \brief pide un numero entero validando previamente su tipo de dato y si es un valor positivo
 *
 * \param pInt int* variable que guarda el entero resultante
 * \param [] char msj mensaje de pedido de entero
 * \param msjError[] char mensaje de error
 * \param intentos int cantidad de intentos paraC:\Users\fedec\OneDrive\Desktop\LABO\Munoz.Federico.P1.Lab1.1G\TP_[3]\Passenger.c ingresar
 * \return int retorna (-1) si se ingreso un caracter o un numero negativo, 0 si se ingreso 0, 1 si la funcion concluyo satisfactoriamente
 *
 */
int ingresarInt(int *pInt, char msj []);

/** \brief ingresa y valida el tamaño de una cadena de caracteres
 *
 * \param cadena[] char cadena
 * \param tamMin int tamaño minimo
 * \param tamMax int tamaño maximo
 * \param msj[] char msj
 * \param msjError[] char msj error
 * \param intentos int cantidad de intentos
 * \return int retorna 1 si se valido o 0 si no se valido
 *
 */
int ingresarValidarCadena(char cadena[],int tamMin,int tamMax, char msj[], char msjError[]);

/** \brief valida extencion de cadena y que no contenga valores numericos
 *
 * \param cadena[] char cadena
 * \param tamMin int tamaño minimo
 * \param tamMax int tamaño maximo
 * \param msj[] char msj
 * \param msjError[] char msj error
 * \param intentos int intentos
 * \return int 1 si concluye satisfactoriamente.
 *
 */
int ingresarValidarNombre(char cadena[],int tamMin,int tamMax, char msj[]);

/** \brief pide ingreso y valida tamaño minimo y maximo permitido de una cadena de caracteres
 *
 * \param msj[] char
 * \param msjError[] char
 * \param rangMin char
 * \param rangMax char
 * \return int 1 si valida correctamente, de lo contrario retorna 0
 *
 */
int ingresarValidarCaracter(char msj[], char msjError[], char rangMin, char rangMax);


/** \brief muestra menu para selccionar estado de vuelo
 *
 * \param cadena char*
 * \return int devuelve la opcion elegida
 *
 */
int menuIngresarEstadoVuelo(char* cadena);


/** \brief muestra menu para selccionar tipo pasajero
 *
 * \param cadena char*
 * \return int devuelve la opcion elegida
 *
 */
int menuIngresarTipoPasajero(char* cadena);


/** \brief valida q la cadena sea solo de carateres alfabeticos
 *
 * \param cadena[] char
 * \return int
 *
 */
int validarLetras(char cadena[]);


/** \brief pide ingrear y valida la cadena de valores numericos enteros
 *
 * \param cadena[] char cadena resultante
 * \param tamMin int tamaño minimo
 * \param tamMax int tamaño maximo
 * \param msj[] char msj
 * \return int retorna 1 si todo concluye satisfactoriamente
 *
 */
int ingresarValidarCadenaInt(char cadena[],int tamMin ,int tamMax, char msj[]);


/** \brief pide y valida una cadena de caracteres de solo valores numericos
 *
 * \param cadena[] char
 * \param tamMin int
 * \param tamMax int
 * \param msj[] char
 * \return int
 *
 */
int ingresarValidarCadenaFloat(char cadena[],int tamMin ,int tamMax, char msj[]);

/** \brief confirma un reingreso de datos
 *
 * \param msj[] char mensaje a mostrar
 * \return int retorna 0 si no confirma y 1 si confirma
 *
 */
int confirmar(char msj[]);

#endif /* INPUTS_H_ */
