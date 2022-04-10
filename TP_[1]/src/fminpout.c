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
int ingresarCifra(float* pCifra)
{
    int retorno=-1;
    if(pCifra!=NULL)
    {
        float numero;
        int esNum;
        esNum=scanf("%f",&numero);
        fflush(stdin);
        if(numero<0 || !esNum)
        {
            system("cls");
            printf("               *** ERROR ***\n");
            printf("NO SE ADMITEN CARACTERES O NUMEROS NEGATIVOS\n\n");
            system("pause");
            *pCifra=esNum;
        }
        else{
            *pCifra=numero;
            retorno=1;
        }
    }
    return retorno;
}

int mostrarMenuPrincipal(float Kilometraje, float aerolineas, float latam)
{
    float opcion;
    system("cls");
    printf("\n");
    printf("   **************************************\n");
    printf("   ********* AGENCIA DE VIAJES **********\n");
    printf("   **************************************\n\n");
    printf("  1. INGRESAR KILOMETROS (Km = %.2f)\n",Kilometraje);
    printf("  2. INGRESAR PRECIO DE VUELOS   ||  Aerolineas = $ %.2f || Latam = $ %.2f  ||\n", aerolineas, latam);
    printf("  3. CALCULAR TODOS LOS COSTOS\n");
    printf("  4. INFORMAR RESULTADOS\n");
    printf("  5. CARGA FORZADA DE DATOS\n");
    printf("  6. SALIR\n");
    ingresarCifra(&opcion);
    return opcion;
}

int mostrarSubmenuPrecios()
{
    int opcion=0;
    system("cls");
    printf("\n");
    printf("   ******* INGRESAR PRECIO DE VUELOS *******\n");
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

int hardcodearBanderas(int* des1, int* des2, int* inter1, int* inter2, int* btc1, int* btc2, int* uni1, int* uni2, int argumento)
{
    int retorno=0;
    if(des1!=NULL && des2!=NULL && inter1!=NULL && inter2!=NULL && btc1!=NULL && inter2!=NULL && uni1!=NULL && uni2!=NULL)
    {
        if(argumento==1)
        {
            *des1=1;
            *des2=1;
            *inter1=1;
            *inter2=1;
            *btc1=1;
            *btc2=1;
            *uni1=1;
            *uni2=1;
        }
        else if(argumento==0)
            {
            *des1=0;
            *des2=0;
            *inter1=0;
            *inter2=0;
            *btc1=0;
            *btc2=0;
            *uni1=0;
            *uni2=0;
        }
        retorno=1;
    }
    return retorno;
}

int informarResultados(float km, float precio, int desc, int inter,
                   int btc, int uni,float rDesc, float rInt, float rBtc, float rUni, char mensaje[])
{
    int retorno=0;
    if(precio)
    {
        printf("Precio %s es: $%.2f\n",mensaje, precio);
        if(desc)
        {
            printf("a) Precio con tarjeta de debito: $%.2f\n", rDesc);
        }
        if(inter)
        {
            printf("b) Precio con tarjeta de credito: $%.2f\n", rInt);
        }
        if(btc)
        {
            printf("c) Precio pagando con Bitcoin: %.4f\n", rBtc);
        }
        if(uni)
        {
            printf("d) Mostrar precio unitario: $%.2f\n", rUni);
        }
        retorno =1;
    }
    return retorno;
}

