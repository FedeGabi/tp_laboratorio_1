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
                printf("- Kilometros,");
                if(!ingresarCifra(&kilometraje))
                {
                    system("cls");
                    printf("ERROR. NO SE ADMITEN VALORES NEGATIVOS\n");
                    system("pause");
                    break;
                }
                break;
            case 2:
                switch(mostrarSubmenuPrecios(precioAero, precioLatam))
                {
                    case 1:
                        printf("- Precio Aerolineas,");
                        if(!ingresarCifra(&precioAero))
                        {
                            system("cls");
                            printf("ERROR. NO SE ADMITEN VALORES NEGATIVOS\n");
                            system("pause");
                        }
                        break;
                    case 2:
                        printf("- Precio Latam,");
                        if(!ingresarCifra(&precioLatam))
                        {
                            system("cls");
                            printf("ERROR. NO SE ADMITEN VALORES NEGATIVOS\n");
                            system("pause");
                        }
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
                                printf("   *** NO SE PUEDE CALCULAR EL PRECIO UNITARIO, NO SE HA INGRESADO KILOMETROS***\n");
                                printf("   *** DESEA INGRESARLO AHORA? (S o N)***\n");
                                char aux;
                                fflush(stdin);
                                scanf("%c", &aux);
                                aux=tolower(aux);
                                if(aux =='s')
                                {
                                    printf("- Kilometros,");
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
                if(!precioAero && !precioLatam)
                {
                    system("cls");
                    printf("NO SE INGRESARON PRECIOS\n");
                    system("pause");
                    break;
                }
                system("cls");
                if(kilometraje && (precioAero || precioLatam))
                {
                    printf("KMs Ingresados: %.2f\n\n", kilometraje);
                }
                if(precioAero)
                {
                    printf("Precio Aerolineas: $%.2f\n", precioAero);
                    if(flagDescontoAero)
                    {
                        printf("a) Precio con tarjeta de debito: $%.2f\n", resultadoDescuentoAero);
                    }
                    if(flagInteresAero)
                    {
                        printf("b) Precio con tarjeta de credito: $%.2f\n", resultadoInteresAero);
                    }
                    if(flagCalculoBtcAero)
                    {
                        printf("c) Precio pagando con Bitcoin: %.4f\n", resultadoBtcAero);
                    }
                    if(flagUnitarioAero)
                    {
                        printf("d) Mostrar precio unitario: $%.2f\n", precioUnitarioAero);
                    }
                }
                printf("\n");
               if(precioLatam)
                {
                    printf("Precio Latam: $%.2f\n", precioLatam);
                    if(flagDescontoLatam)
                    {
                        printf("a) Precio con tarjeta de debito: $%.2f\n", resultadoDescuentoLatam);
                    }
                    if(flagInteresLatam)
                    {
                        printf("b) Precio con tarjeta de credito: $%.2f\n", resultadoInteresLatam);
                    }
                    if(flagCalculoBtcLatam)
                    {
                        printf("c) Precio pagando con Bitcoin: %.4f\n", resultadoBtcLatam);
                    }
                    if(flagUnitarioLatam)
                    {
                        printf("d) Mostrar precio unitario: $%.2f\n", precioUnitarioLatam);
                    }
                }
                printf("\n");
                if(flagDiferenciaRes)
                {
                    printf("La diferencia de precio es: $%.2f\n\n", diferenciaResultado);
                }
                system("pause");
                break;
            case 5:
                cargaForzada(&kilometraje,&precioAero,&precioLatam);
                mostrarResultadosF(kilometraje,precioAero,precioLatam);
                system("pause");
                break;
            case 6:
                break;
        }
    }while(opcion>0 && opcion<6);
    return EXIT_SUCCESS ;
}
