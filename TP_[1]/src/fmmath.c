/*
 * fmmath.c
 *
 *  Created on: 4 abr. 2022
 *      Author: Federico Muñoz 1G Dni 32378420
 */

#include "fmmath.h"

int calcularDescuento(float monto, float descuentoAsig, float *pResultado) {
	int retorno = 0;
	if (pResultado != NULL && monto > 0 && descuentoAsig > 0) {
		float aux;
		aux = (monto * descuentoAsig) / 100;
		*pResultado = monto - aux;
		retorno = 1;
	}
	return retorno;
}

int calcularInteres(float monto, float interesAsig, float *pResultado) {
	int retorno = 0;
	if (pResultado != NULL && monto > 0 && interesAsig > 0) {
		float auxInteres;
		auxInteres = (interesAsig * monto) / 100;
		*pResultado = monto + auxInteres;
		retorno = 1;
	}
	return retorno;
}

int calcularBtc(float monto, float valorUnBtc, float *pResultado) {
	int retorno = 0;
	if (pResultado != NULL && monto > 0 && valorUnBtc > 0) {
		*pResultado = monto / valorUnBtc;
		retorno = 1;
	}
	return retorno;
}

int diferenciaPrecio(float monto1, float monto2, float *pResultado) {
	int retorno = -1;
	if (pResultado != NULL && monto1 > 0 && monto2 > 0) {
		if (monto1 > monto2) {
			*pResultado = monto1 - monto2;
			retorno = 0;
		} else {
			if (monto1 < monto2) {
				*pResultado = monto2 - monto1;
				retorno = 1;
			}
		}
	}
	return retorno;
}

int calcularPrecioUnitario(float precio, float kilometros, float *pResultado) {
	int retorno = 0;
	if (pResultado != NULL && precio > 0 && kilometros > 0) {
		*pResultado = precio / kilometros;
		retorno = 1;
	}
	return retorno;
}

