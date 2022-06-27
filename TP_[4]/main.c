#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "Controller.h"
#include "inputs.h"

int main()
{
    int seguir=1;
    int auxInt;
    LinkedList* lista = ll_newLinkedList();   // crea un nuevo LinkedList
    LinkedList* listaAuxiliar = ll_newLinkedList();  // crea un nuevo LinkedList
    controller_loadFromText("data.csv", lista);

    Passenger* pasajero = (Passenger*)calloc(sizeof(Passenger), 1);
    Passenger* pasajeroDos = (Passenger*)calloc(sizeof(Passenger), 1);

    if(lista == NULL && listaAuxiliar != NULL && pasajero != NULL && pasajeroDos!= NULL)
    {
        printf("No se pudo conseguir espacio en memoria");
        exit(1);
    }

    char nombres[2][20]= {"pedrito","lorenita"};
    char apellidos[2][20]= {"rodriguez","gonzalez"};    // datos para hardcodear
    char codigosVuelo[2][20]= {"aaaiii4","eeeuuu6"};

    Passenger_setId(pasajero, 5555);
    Passenger_setNombre(pasajero, nombres[0]);
    Passenger_setApellido(pasajero, apellidos[0]);  // datos de UN pasajero hardcodeados para utilizar "ll_set()" y "ll_push()"
    Passenger_setPrecio(pasajero, 86900);
    Passenger_setCodigoVuelo(pasajero, codigosVuelo[0]);
    Passenger_setTipoPasajero(pasajero, "MenganoClass");
    Passenger_setEstadoVuelo(pasajero,"Aterrorizado" );

    Passenger_setId(pasajeroDos, 6666);
    Passenger_setNombre(pasajeroDos, nombres[1]);
    Passenger_setApellido(pasajeroDos, apellidos[1]);  // datos de OTRO pasajero hardcodeados para utilizar "ll_add()"
    Passenger_setPrecio(pasajeroDos, 82500);
    Passenger_setCodigoVuelo(pasajeroDos, codigosVuelo[1]);
    Passenger_setTipoPasajero(pasajeroDos, "PepitoClass");
    Passenger_setEstadoVuelo(pasajeroDos,"A destiempo" );

    do
    {
        switch(menu())
        {

        case 1:
            controller_ListPassenger(lista);   /* Controller_list utiliza "ll_len()" y "ll_get()" para recuperar
                                                   los "pElements" en la posicion i de cada NODO y los muestra. */
            break;
        case 2:
            if(ll_len(listaAuxiliar)>0)
            {
                controller_ListPassenger(listaAuxiliar);
            }
            else
            {
                printf("Todavia no hay elementos guardados en el LinkedList DOS\n");
                system("pause");
            }
            break;
        case 3:
            controller_sortPassenger(lista);  /* Controller_sort utiliza "ll_sort()", esta recibe como parametro el putero
                                                  a la funcon que ordena, tambien recibe el criterio ascendente u descendente*/
            break;
        case 4:
            ll_clear(listaAuxiliar);
            listaAuxiliar = controller_clonAll(lista); // utiliza "ll_clone()" para clonar una lista completa en otra
            break;
        case 5:
            ll_clear(listaAuxiliar);
            listaAuxiliar = controller_sublist(lista);  /* Utiliza "ll_subList()" para generar una sub-lista nueva a partir de una lista origen.
                                                        y recibe dos parametros enteros q son los indices entre los cuales se va a crear la lista*/
            break;
        case 6:
            printf("el siguiente pasajero se agregara al indice Numero 995 de la lista utilizando ll_set():\n\n");
            mostrarPassenger(pasajero);
            printf("\n\n");
            system("pause");
            ll_set(lista, 995, pasajero);   /* setea elemento de un NODO en el indice especificado
                                            y pisa o reemplaza el elemento existente si lo hubiera*/

            controller_ListPassenger(lista);
            break;
        case 7:
            printf("el siguiente pasajero se ELIMINARA de la lista en el indice Numero 998 ll_remove():\n\n");
            mostrarPassenger((Passenger*)ll_get(lista, 995));
            system("pause");
            ll_remove(lista, 995);               /* "ll_remove()" libera la memoria de un NODO existente en una lista
                                                                y en un indice especificado*/
            controller_ListPassenger(lista);
            break;
        case 8:
            auxInt=ll_indexOf(lista, pasajeroDos);
            if(auxInt==-1)
            {
                printf("Lorenita no esta en la lista\n");
            }
            else
            {
                printf("El indice de lorenita es: \n");
                printf("\nes: %d \n", auxInt);
            }                                                              // "ll_indexOf()" recibe un elemento, buscandolo dentro de la lista y retornando su indice
            system("pause");
            break;
        case 9:
            ll_add(lista, pasajeroDos); // agrega un elemento al final de la lista
            controller_ListPassenger(lista);

            break;
        case 10:
            printf("El pasajero: \n\n");
            mostrarPassenger(pasajero);
            if(!ll_contains(lista, pasajero)) // "ll_contains()" verifica si el elemento se cuentra o no contenido en la lista
            {
                printf("PEDRITO NO se encuentra contenido en la lista...\n");
            }
            else
            {
                printf("PEDRITO SI se encuentra contenido en la lista...\n");
            }
            system("pause");
            break;
        case 11:
            ll_push(lista, 997, pasajero);  // agrega un nuevo NODO cargado con el elemento en el indice especificado
            controller_ListPassenger(lista);
            break;
        case 12:
            if(!ll_isEmpty(lista))  // "ll_isEmpty()" verifica el size del linkedList, si es igual a 0 la lista esta vacia
            {
                printf("No esta vacia...\n");
            }
            else
            {
                printf("Si, esta vacia...\n");
            }
            system("pause");
            break;
        case 13:
            printf("El siguiente pasajero fue eliminado de la lista: \n\n");
            mostrarPassenger(ll_pop(lista, 998));    // "ll_pop()" devuelve un NODO de la lista y luego lo elimina
            system("pause");
            break;
        case 14:
            if(ll_containsAll(lista, listaAuxiliar) )  /* "ll_containsAll()" verifica si todos los elementos de lista auxiliar
                                                            estan contenidos dentro la lista 1*/
            {
                printf("SI, los elementos de la lista auxiliar estan contenidos dentro de la lista 1");
            }
            else
            {
                printf("NO, los elementos de la lista auxiliar NO estan contenidos dentro de la lista 1");
            }
            system("pause");
            break;
        case 15:
            listaAuxiliar=controllerFilter(lista);      /*utiliza "ll_filter()", recibe punteros a funciones para filtrar y generar
                                                            una nueva lista */
            break;
        case 16:
            ll_clear(lista);                /* limpia una lista completa utilizando "ll_remove()" para liberar la memoria
                                                de todos los nodos existentes quedando asi un Linkedlist vacio*/
            ll_clear(listaAuxiliar);
            break;
        case 17:
            ll_deleteLinkedList(lista);                // elimina un LinkedList utiliza "ll_clear()" vaciando la lista y luego se hace un FREE del linkedList.
            ll_deleteLinkedList(listaAuxiliar);
            seguir=0;
            break;
        default:
            printf("opcion invalida");
            break;
        }
    }
    while(seguir==1);


    return 0;
}
