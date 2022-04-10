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



int main()
{
    setbuf(stdout, NULL);
    float kilometraje=0;
    float precioAero=0;
    float precioLatam=0;
    float resultadoDescuentoAero;
    float resultadoDescuentoLatam;
    float resultadoInteresAero;
    float resultadoInteresLatam;
    float resultadoBtcAero;
    float resultadoBtcLatam;
    float precioUnitarioAero;
    float precioUnitarioLatam;
    float diferenciaResultado;
    int flagDescontoAero=0;
    int flagInteresAero=0;
    int flagCalculoBtcAero=0;
    int flagUnitarioAero=0;
    int flagDescontoLatam=0;
    int flagInteresLatam=0;
    int flagCalculoBtcLatam=0;
    int flagUnitarioLatam=0;
    int flagDiferenciaRes=0;
    int opcion;
    do{
        opcion=mostrarMenuPrincipal(kilometraje);
        switch(opcion)
        {
            case 1:
                printf("- Ingresar kilometros: ");
                ingresarCifra(&kilometraje);
                break;
            case 2:
                switch(mostrarSubmenuPrecios(precioAero, precioLatam))
                {
                    case 1:
                        printf("- Ingresar precio Aerolineas: ");
                        ingresarCifra(&precioAero);
                        break;
                    case 2:
                        printf("- Ingresar precio Latam: ");
                        ingresarCifra(&precioLatam);
                        break;
                }
                break;
            case 3:
                if(!precioAero && !precioLatam)
                {
                    system("cls");
                    printf("NO SE INGRESARON PRECIOS\n");
                    system("pause");
                    break;
                }
                    switch(tolower(mostrarSubmenuCostos()))
                    {
                        case 'a':
                            if(precioAero && precioLatam)
                            {
                                calcularDescuento(precioAero,DESCUENTO,&resultadoDescuentoAero);
                                calcularDescuento(precioLatam,DESCUENTO,&resultadoDescuentoLatam);
                                flagDescontoAero=1;
                                flagDescontoLatam=1;
                                break;
                            }
                            else if(precioAero)
                            {
                                calcularDescuento(precioAero,DESCUENTO,&resultadoDescuentoAero);
                                flagDescontoAero=1;
                                break;
                            }
                            else{
                                calcularDescuento(precioLatam,DESCUENTO,&resultadoDescuentoLatam);
                                flagDescontoLatam=1;
                            }
                            break;
                        case 'b':
                            if(precioAero && precioLatam)
                            {
                                calcularInteres(precioAero,INTERES,&resultadoInteresAero);
                                calcularInteres(precioLatam,INTERES,&resultadoInteresLatam);
                                flagInteresAero=1;
                                flagInteresLatam=1;
                                break;
                            }
                            else if(precioAero)
                            {
                                calcularInteres(precioAero,INTERES,&resultadoInteresAero);
                                flagInteresAero=1;
                                break;
                            }
                            else{
                                calcularInteres(precioLatam,INTERES,&resultadoInteresLatam);
                                flagInteresLatam=1;
                            }
                            break;
                        case 'c':
                            if(precioAero && precioLatam)
                            {
                                calcularBtc(precioAero,ARSBTC,&resultadoBtcAero);
                                calcularBtc(precioLatam,ARSBTC,&resultadoBtcLatam);
                                flagCalculoBtcAero=1;
                                flagCalculoBtcLatam=1;
                                break;
                            }
                            else if(precioAero)
                            {
                                calcularBtc(precioAero,ARSBTC,&resultadoBtcAero);
                                flagCalculoBtcAero=1;
                                break;
                            }
                            else{
                                calcularBtc(precioLatam,ARSBTC,&resultadoBtcLatam);
                                flagCalculoBtcLatam=1;
                            }
                            break;
                        case 'd':
                            if(!kilometraje)
                            {
                                system("cls");
                                printf("                          *** ERROR ***\n");
                                printf("   *** PARA CALCULAR EL PRECIO UNITARIO SE DEBE INGRESAR KILOMETROS***\n");
                                printf("   *** DESEA INGRESARLO AHORA? (S o N)***\n");
                                char aux;
                                fflush(stdin);
                                scanf("%c", &aux);
                                aux=tolower(aux);
                                if(aux =='s')
                                {
                                    printf("- Ingresar kilometros,");
                                    ingresarCifra(&kilometraje);
                                }
                                break;
                            }
                            else{
                                if(precioAero)
                                {
                                    calcularPrecioUnitario(precioAero,kilometraje, &precioUnitarioAero);
                                    flagUnitarioAero=1;
                                }
                                if(precioLatam)
                                {
                                    calcularPrecioUnitario(precioLatam,kilometraje, &precioUnitarioLatam);
                                    flagUnitarioLatam=1;
                                }
                            }
                            break;
                        case 'e':
                            if(precioAero || precioLatam)
                            {
                                diferenciaPrecio(precioAero,precioLatam, &diferenciaResultado);
                                flagDiferenciaRes=1;
                            }
                            else{
                                printf("NO SE INGRESARON PRECIOS A CALCULAR\n");
                                system("pause");
                            }
                    }
                    break;
            case 4:
                system("cls");
                if(!precioAero && !precioLatam)
                {
                    system("cls");
                    printf("NO SE INGRESARON PRECIOS\n");
                    system("pause");
                    break;
                }
                else{
                    if(kilometraje && (precioAero || precioLatam))
                    {
                        printf("KMs Ingresados: %.2f\n\n", kilometraje);
                    }
                    mostrarPrecios(kilometraje,precioAero,flagDescontoAero, flagInteresAero, flagCalculoBtcAero, flagUnitarioAero,
                                   resultadoDescuentoAero, resultadoInteresAero, resultadoBtcAero, precioUnitarioAero, "Aerolineas");
                    printf("\n");
                    mostrarPrecios(kilometraje,precioLatam,flagDescontoLatam, flagInteresLatam, flagCalculoBtcLatam, flagUnitarioLatam,
                                   resultadoDescuentoLatam, resultadoInteresLatam, resultadoBtcLatam, precioUnitarioLatam,"Latam");
                    if(flagDiferenciaRes)
                    {
                        printf("\nLa diferencia de precio es: $%.2f\n\n", diferenciaResultado);
                    }
                    system("pause");
                }
                break;
            case 5:
                system("cls");
                cargaForzada(&kilometraje,&precioAero,&precioLatam);
                hardcodearBanderas(&flagDescontoAero, &flagDescontoLatam, &flagInteresAero, &flagInteresLatam,
                                    &flagCalculoBtcAero, &flagCalculoBtcLatam, &flagUnitarioAero, &flagUnitarioLatam, 1);
                calcularDescuento(precioAero,DESCUENTO,&resultadoDescuentoAero);
                calcularDescuento(precioLatam,DESCUENTO,&resultadoDescuentoLatam);
                calcularInteres(precioAero,INTERES,&resultadoInteresAero);
                calcularInteres(precioLatam,INTERES,&resultadoInteresLatam);
                calcularBtc(precioAero,ARSBTC,&resultadoBtcAero);
                calcularBtc(precioLatam,ARSBTC,&resultadoBtcLatam);
                calcularPrecioUnitario(precioAero,kilometraje, &precioUnitarioAero);
                calcularPrecioUnitario(precioLatam,kilometraje, &precioUnitarioLatam);
                diferenciaPrecio(precioAero,precioLatam, &diferenciaResultado);
                printf("KMs Ingresados: %.2f\n\n", kilometraje);
                mostrarPrecios(kilometraje,precioAero,flagDescontoAero, flagInteresAero, flagCalculoBtcAero, flagUnitarioAero,
                               resultadoDescuentoAero, resultadoInteresAero, resultadoBtcAero, precioUnitarioAero, "Aerolineas");
                printf("\n");
                mostrarPrecios(kilometraje,precioLatam,flagDescontoLatam, flagInteresLatam, flagCalculoBtcLatam, flagUnitarioLatam,
                               resultadoDescuentoLatam, resultadoInteresLatam, resultadoBtcLatam, precioUnitarioLatam,"Latam");
                printf("\ne) La diferencia de precio es: %.2f\n\n", diferenciaResultado);
                hardcodearBanderas(&flagDescontoAero, &flagDescontoLatam, &flagInteresAero, &flagInteresLatam,
                                    &flagCalculoBtcAero, &flagCalculoBtcLatam, &flagUnitarioAero, &flagUnitarioLatam, 0);
                system("pause");
                break;
            case 6:
                break;
            default:
                break;
        }
    }while(opcion>=0 && opcion<6);
    return EXIT_SUCCESS;
}
