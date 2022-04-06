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
int mostrarMenuPrincipal(float kilometraje)
{
    int opcion;
    system("cls");
    printf("\n");
    printf("   **************************************\n");
    printf("   ********* AGENCIA DE VIAJES **********\n");
    printf("   **************************************\n\n");
    printf("  1. INGRESAR KILOMETROS (Km = %.2f)\n",kilometraje);
    printf("  2. INGRESAR PRECIO DE VUELOS\n");
    printf("  3. CALCULAR TODOS LOS COSTOS\n");
    printf("  4. INFORMAR RESULTADOS\n");
    printf("  5. CARGA FORZADA DE DATOS\n");
    printf("  6. SALIR\n");
    scanf("%d",&opcion);
    return opcion;
}

int ingresarCifra(float* pCifra)
{
    int retorno=-1;
    if(pCifra!=NULL)
    {
        float numero;
        printf(" ingrese cifra: ");
        scanf("%f",&numero);
        if(numero<0)
        {
           retorno=0;
        }
        else{
            *pCifra=numero;
            retorno=1;
        }
    }
    return retorno;
}

int mostrarSubmenuPrecios(float aerolineas, float latam)
{
    int opcion=0;
    system("cls");
    printf("\n");
     printf("   ******* INGRESAR PRECIO DE VUELOS *******\n");
    printf("\n       (Aerolineas = %.2f, Latam = %.2f)\n\n", aerolineas, latam);
    printf("  1. PRECIO VUELO AEROLINEAS\n");
    printf("  2. PRECIO VUELO LATAM\n");
    printf("  3. MENU ANTERIOR\n");
    scanf("%d",&opcion);
    return opcion;
}

char mostrarSubmenuCostos()
{
    char opcion;
    system("cls");
    printf("\n");
    printf("   ********* CALCULAR TODOS LOS COSTOS *******\n\n");
    printf("a) Tarjeta de debito (descuento 10 porciento)\n");
    printf("b) Tarjeta de credito (interes 25 porciento)\n");
    printf("c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)\n");
    printf("d) Mostrar precio por km (precio unitario)\n");
    printf("e) Mostrar diferencia de precio ingresada (Latam - Aerolineas)\n");
    fflush(stdin);
    scanf("%c",&opcion);
    return opcion;
}

int cargaForzada(float* pKilometros, float* pPrecioAero, float* pPrecioLatam)
{
    int retorno=0;
    if(pKilometros!=NULL && pPrecioAero !=NULL && pPrecioLatam !=NULL)
    {
        *pKilometros=7090;
        *pPrecioAero=162965;
        *pPrecioLatam=159339;
        retorno=1;

    }
    return retorno;
}

int mostrarResultadosF(float kilometros, float precioAerolineas, float precioLatamLatam)
{
    system("cls");
    int retorno=0;
    if(kilometros>0 && precioLatamLatam>0 && precioAerolineas>0)
    {
        float resultadoDescuentoAero;
        float resultadoDescuentoLatam;
        float resultadoInteresAero;
        float resultadoInteresLatam;
        float resultadoBtcAero;
        float resultadoBtcLatam;
        float precioUnitarioAero;
        float precioUnitarioLatam;
        float diferenciaResultado;
        calcularDescuento(precioAerolineas,DESCUENTO,&resultadoDescuentoAero);
        calcularInteres(precioAerolineas, INTERES, &resultadoInteresAero);
        calcularBtc(precioAerolineas, ARSBTC, &resultadoBtcAero);
        calcularPrecioUnitario(precioAerolineas, kilometros, &precioUnitarioAero);
        calcularDescuento(precioLatamLatam,DESCUENTO,&resultadoDescuentoLatam);
        calcularInteres(precioLatamLatam, INTERES, &resultadoInteresLatam);
        calcularBtc(precioLatamLatam, ARSBTC, &resultadoBtcLatam);
        calcularPrecioUnitario(precioLatamLatam, kilometros, &precioUnitarioLatam);
        printf("KMs Ingresados: %.2f\n\n",kilometros);
        printf("Precio Aerolineas: $%.2f \n", precioAerolineas);
        printf("a) Precio con tarjeta de debito: $%.2f\n", resultadoDescuentoAero);
        printf("b) Precio con tarjeta de credito: $%.2f\n", resultadoInteresAero);
        printf("c) Precio pagando con Bitcoin: %.4f\n", resultadoBtcAero);
        printf("d) Mostrar precio unitario: $%.2f\n\n", precioUnitarioAero);
        printf("Precio Latam: $%.2f \n", precioLatamLatam);
        printf("a) Precio con tarjeta de debito: $%.2f\n", resultadoDescuentoLatam);
        printf("b) Precio con tarjeta de credito: $%.2f\n", resultadoInteresLatam);
        printf("c) Precio pagando con Bitcoin: %.4f\n", resultadoBtcLatam);
        printf("d) Mostrar precio unitario: $%.2f\n\n", precioUnitarioLatam);
        diferenciaPrecio(precioAerolineas,precioLatamLatam, &diferenciaResultado);
        printf("e) La diferencia de precio es: %.2f\n\n", diferenciaResultado);
        retorno=1;
    }
    return retorno;
}
