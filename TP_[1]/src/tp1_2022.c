/*
 ============================================================================
 Name        : tp1_2022.c
 Author      : Muñoz Federico 1G, dni 32378420
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Aerolineas, Latam.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "fminpout.h"
#include "fmmath.h"

#define DESCUENTO 10
#define INTERES 25
#define ARSBTC 4606954.55

int main() {
	setbuf(stdout, NULL);
	float kilometraje = 0;
	float precioAero = 0;
	float precioLatam = 0;
	float resultadoDescuentoAero;
	float resultadoDescuentoLatam;
	float resultadoInteresAero;
	float resultadoInteresLatam;
	float resultadoBtcAero;
	float resultadoBtcLatam;
	float precioUnitarioAero;
	float precioUnitarioLatam;
	float diferenciaResultado;
	int flagCalculoAero = 0;
	int flagCalculoLatam = 0;
	int flagAtencion = 0;
	int opcion;
	do {
		opcion = mostrarMenuPrincipal(kilometraje, precioAero, precioLatam);
		switch (opcion) {
		case 1:
			printf("- Ingresar kilometros: ");
			ingresarCifra(&kilometraje);
			break;
		case 2:
			if (!kilometraje && !flagAtencion) {
				system("cls");
				printf("\n");
				printf(
						"              ***   ATENCION!, NO HA INGRESADO VALORES EN KILOMETROS   ***\n");
				printf(
						"***   SI NO INGRESA NINGUN VALOR, LOS RESULTADOS RELACIONADOS CON ESTE DATO NO SE CALCULARAN  ***\n");
				printf("***   DESEA INGRESARLO AHORA?  (S O N) ***\n");
				if (ingresarChar('s', 'n') == 's') {
					printf("- Ingresar kilometros: ");
					ingresarCifra(&kilometraje);
				}
				flagAtencion = 1;
			}
			int opcion;
			opcion = mostrarSubmenuPrecios();
			if (opcion == 1) {
				printf("- Ingresar precio Aerolineas: ");
				if (ingresarCifra(&precioAero) == 1) {
					system("cls");
					printf(
							" *** PRECIO AEROLINEAS: $ %.2f, SE HA CARGADO CON EXITO\n\n",
							precioAero);
					system("pause");
				}
			} else if (opcion == 2) {
				printf("- Ingresar precio Latam: ");
				if (ingresarCifra(&precioLatam) == 1) {
					system("cls");
					printf(
							" *** PRECIO LATAM: $ %.2f, SE HA CARGADO CON EXITO\n\n",
							precioLatam);
					system("pause");
				}
			}
			break;
		case 3:
			if (!precioAero && !precioLatam) {
				system("cls");
				printf(
						"   *** NO SE INGRESARON PRECIOS, IMPOSIBLE CALCULAR ***\n");
				system("pause");
			} else {
				if (precioAero) {
					calcularDescuento(precioAero, DESCUENTO,
							&resultadoDescuentoAero);
					calcularInteres(precioAero, INTERES, &resultadoInteresAero);
					calcularBtc(precioAero, ARSBTC, &resultadoBtcAero);
					if (kilometraje) {
						calcularPrecioUnitario(precioAero, kilometraje,
								&precioUnitarioAero);
					}
					flagCalculoAero = 1;
				}
				if (precioLatam) {
					calcularDescuento(precioLatam, DESCUENTO,
							&resultadoDescuentoLatam);
					calcularInteres(precioLatam, INTERES,
							&resultadoInteresLatam);
					calcularBtc(precioLatam, ARSBTC, &resultadoBtcLatam);
					if (kilometraje) {
						calcularPrecioUnitario(precioLatam, kilometraje,
								&precioUnitarioLatam);
					}
					flagCalculoLatam = 1;
				}
				if (precioAero || precioLatam) {
					diferenciaPrecio(precioAero, precioLatam,
							&diferenciaResultado);
				}
				system("cls");
				printf("   *** CALCULOS REALIZADOS CON EXITO ***\n\n");
				system("pause");
			}
			break;
		case 4:
			system("cls");
			if (!flagCalculoAero && !flagCalculoLatam) {
				system("cls");
				printf(
						"   *** IMPOSIBLE MOSTRAR CALCULOS, NO EXISTEN CALCULOS REGISTRADOS ***\n");
				system("pause");
				break;
			} else {
				if (kilometraje && (flagCalculoAero || flagCalculoLatam)) {
					printf("KMs Ingresados: %.2f\n\n", kilometraje);
				}
				if (flagCalculoAero) {
					informarResultados(kilometraje, precioAero,
							resultadoDescuentoAero, resultadoInteresAero,
							resultadoBtcAero, precioUnitarioAero, "Aerolineas");
					printf("\n");
				}
				if (flagCalculoLatam) {
					informarResultados(kilometraje, precioLatam,
							resultadoDescuentoLatam, resultadoInteresLatam,
							resultadoBtcLatam, precioUnitarioLatam, "Latam");
				}

				if (precioAero || precioLatam) {
					printf("\nLa diferencia de precio es: $%.2f\n\n",
							diferenciaResultado);
				}
				system("pause");
			}
			break;
		case 5:
			system("cls");
			cargaForzada(&kilometraje, &precioAero, &precioLatam, 1354, 128540,
					100002);
			hardcodearBanderas(&flagAtencion, &flagCalculoAero,
					&flagCalculoLatam, 1);
			calcularDescuento(precioAero, DESCUENTO, &resultadoDescuentoAero);
			calcularDescuento(precioLatam, DESCUENTO, &resultadoDescuentoLatam);
			calcularInteres(precioAero, INTERES, &resultadoInteresAero);
			calcularInteres(precioLatam, INTERES, &resultadoInteresLatam);
			calcularBtc(precioAero, ARSBTC, &resultadoBtcAero);
			calcularBtc(precioLatam, ARSBTC, &resultadoBtcLatam);
			calcularPrecioUnitario(precioAero, kilometraje,
					&precioUnitarioAero);
			calcularPrecioUnitario(precioLatam, kilometraje,
					&precioUnitarioLatam);
			diferenciaPrecio(precioAero, precioLatam, &diferenciaResultado);
			printf("KMs Ingresados: %.2f\n\n", kilometraje);
			informarResultados(kilometraje, precioAero, resultadoDescuentoAero,
					resultadoInteresAero, resultadoBtcAero, precioUnitarioAero,
					"Aerolineas");
			printf("\n");
			informarResultados(kilometraje, precioLatam,
					resultadoDescuentoLatam, resultadoInteresLatam,
					resultadoBtcLatam, precioUnitarioLatam, "Latam");
			printf("\ne) La diferencia de precio es: %.2f\n\n",
					diferenciaResultado);
			system("pause");
			hardcodearBanderas(&flagAtencion, &flagCalculoAero,
			&flagCalculoLatam, 0);
			cargaForzada(&kilometraje, &precioAero, &precioLatam,0,0,0);
			system("cls");
			printf("   *** SE REINICIARON LOS VALORES ***\n");
			system("pause");
			break;
		case 6:
			break;
		default:
			break;
		}
	} while (opcion >= 0 && opcion < 6);
	return EXIT_SUCCESS;
}
