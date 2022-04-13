/*
 * fminpout.c
 *
 *  Created on: 4 abr. 2022
 *      Author: Federico Muñoz 1G Dni 32378420
 */

#define DESCUENTO 10
#define INTERES 25
#define ARSBTC 4606954.55
#include "fminpout.h"

int ingresarCifra(float *pCifra) {
	int retorno = -1;
	if (pCifra != NULL) {
		float numero;
		int esNum;
		esNum = scanf("%f", &numero);
		fflush(stdin);
		if (numero < 0 || !esNum) {
			system("cls");
			printf("               *** ERROR ***\n");
			printf("NO SE ADMITEN CARACTERES O NUMEROS NEGATIVOS\n\n");
			system("pause");
			*pCifra = 0;
			retorno = -1;
		} else if (!numero) {
			*pCifra = 0;
			retorno = 0;
		} else {
			*pCifra = numero;
			retorno = 1;
		}
	}
	return retorno;
}

int mostrarMenuPrincipal(float Kilometraje, float aerolineas, float latam) {
	float opcion;
	system("cls");
	printf("\n");
	printf("   **************************************\n");
	printf("   ********* AGENCIA DE VIAJES **********\n");
	printf("   **************************************\n\n");
	printf("  1. INGRESAR KILOMETROS (Km = %.2f)\n", Kilometraje);
	printf(
			"  2. INGRESAR PRECIO DE VUELOS   ||  Aerolineas = $ %.2f || Latam = $ %.2f  ||\n",
			aerolineas, latam);
	printf("  3. CALCULAR TODOS LOS COSTOS\n");
	printf("  4. INFORMAR RESULTADOS\n");
	printf("  5. CARGA FORZADA DE DATOS\n");
	printf("  6. SALIR\n");
	ingresarCifra(&opcion);
	return opcion;
}

float mostrarSubmenuPrecios() {
	float opcion;
	system("cls");
	printf("\n");
	printf("   ******* INGRESAR PRECIO DE VUELOS *******\n");
	printf("  1. PRECIO VUELO AEROLINEAS\n");
	printf("  2. PRECIO VUELO LATAM\n");
	printf("  3. MENU ANTERIOR\n");
	ingresarCifra(&opcion);
	return opcion;
}

int cargaForzada(float *pKilometros, float *pPrecioAero, float *pPrecioLatam,
		float km, float precio1, float precio2) {
	int retorno = 0;
	if (pKilometros != NULL && pPrecioAero != NULL && pPrecioLatam != NULL) {
		*pKilometros = km;
		*pPrecioAero = precio1;
		*pPrecioLatam = precio2;

		retorno = 1;

	}
	return retorno;
}

int hardcodearBanderas(int *flag1, int *flag2, int *flag3, int argumento) {
	int retorno = 0;
	if (flag1 != NULL) {
		if (argumento == 1) {
			*flag1 = 1;
			*flag2 = 1;
			*flag3 = 1;
		} else if (argumento == 0) {
			*flag1 = 0;
			*flag2 = 0;
			*flag3 = 0;
		}
		retorno = 1;
	}
	return retorno;
}

int informarResultados(int flagKm, float precio, float rDesc, float rInt,
		float rBtc, float rUni, char mensaje[]) {
	int retorno = 0;
	if (precio) {
		printf("Precio %s es: $%.2f\n", mensaje, precio);
		printf("a) Precio con tarjeta de debito: $%.2f\n", rDesc);
		printf("b) Precio con tarjeta de credito: $%.2f\n", rInt);
		printf("c) Precio pagando con Bitcoin: %.5f\n", rBtc);
		if (flagKm) {
			printf("d) Mostrar precio unitario: $%.2f\n", rUni);
		} else {
			printf(
					"d) KILOMETROS NO INGRESADOS (no se pudo calcular el precio unitario)\n");
		}
		retorno = 1;
	}
	return retorno;
}

char ingresarChar(char char1, char char2) {
	char retorno = 'n';
	char aux;
	fflush(stdin);
	scanf("%c", &aux);
	if (tolower(char1) == tolower(aux)) {
		retorno = char1;
	} else {
		if (tolower(char2) == tolower(aux)) {
			retorno = char2;
		}
	}
	return retorno;
}

