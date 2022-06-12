/*
 * inputs.h
 *
 *  Created on: 6 jun. 2022
 *      Author: fedec
 */

#ifndef INPUTS_H_
#define INPUTS_H_


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
int ingresarFloat(float *pFloat, char msj [], char msjError[], int intentos);


/** \brief pide un numero entero validando previamente su tipo de dato y si es un valor positivo
 *
 * \param pInt int* variable que guarda el entero resultante
 * \param [] char msj mensaje de pedido de entero
 * \param msjError[] char mensaje de error
 * \param intentos int cantidad de intentos para ingresar
 * \return int retorna (-1) si se ingreso un caracter o un numero negativo, 0 si se ingreso 0, 1 si la funcion concluyo satisfactoriamente
 *
 */
int ingresarInt(int *pInt, char msj [], char msjError[], int intentos);

/** \brief pide cadena de caracteres validando previamente su tama�o
 *
 * \param cadena[] char variable q guarda la cadena resultante
 * \param tamMin int tama�o minimo de la cadena
 * \param tamMax int tama�o maximo de cadena
 * \param msj[] char msj de pedido de cadena
 * \param msjError[] char mensaje de error
 * \param intentos int cantdad de intentos para ingresar
 * \return int 1 si la funcion concluye satisfactoriamente, de lo contrario retorna 0
 *
 */
/** \brief ingresa y valida el tama�o de una cadena de caracteres
 *
 * \param cadena[] char cadena
 * \param tamMin int tama�o minimo
 * \param tamMax int tama�o maximo
 * \param msj[] char msj
 * \param msjError[] char msj error
 * \param intentos int cantidad de intentos
 * \return int retorna 1 si se valido o 0 si no se valido
 *
 */
int ingresarValidarCadena(char cadena[],int tamMin,int tamMax, char msj[], char msjError[], int intentos);

/** \brief valida extencion de cadena y que no contenga valores numericos
 *
 * \param cadena[] char cadena
 * \param tamMin int tama�o minimo
 * \param tamMax int tama�o maximo
 * \param msj[] char msj
 * \param msjError[] char msj error
 * \param intentos int intentos
 * \return int 1 si concluye satisfactoriamente.
 *
 */
int ingresarValidarNombre(char cadena[],int tamMin,int tamMax, char msj[], char msjError[]);

/** \brief pide ingreso y valida tama�o minimo y maximo permitido de una cadena de caracteres
 *
 * \param msj[] char
 * \param msjError[] char
 * \param rangMin char
 * \param rangMax char
 * \return int 1 si valida correctamente, de lo contrario retorna 0
 *
 */
int ingresarValidarCaracter(char msj[], char msjError[], char rangMin, char rangMax);

/** \brief valida si la cadena de caracteres contiene solo caracteres alfabeticos
 *
 * \param cadena[] char
 * \return int 1 si solo tiene letras, 0 si encuentra caracteres numericos
 *
 */
int validarLetras(char cadena[]);

/** \brief confirma un reingreso de datos
 *
 * \param msj[] char mensaje a mostrar
 * \return int retorna 0 si no confirma y 1 si confirma
 *
 */
int confirmar(char msj[]);


#endif /* INPUTS_H_ */
