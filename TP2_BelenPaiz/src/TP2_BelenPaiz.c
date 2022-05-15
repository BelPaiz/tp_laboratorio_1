/*
 ============================================================================
 Name        : TP2_BelenPaiz.c
 Author      : Belen Bernardette Paiz
 Version     :v1
 Copyright   : Your copyright notice
 Description : TP_2
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arrayPasseger.h"

#define TAM 2000
#define TAMC 4
#define TAMV 6

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);

    char salir ='n';
    int proximoId = 1000;
    ePasajero lista[TAM];
    int flagAlta = 1;
    eClaseTipo clases[TAMC] =
    {
        {1, "Economica"},
        {2, "Ejecutiva"},
        {3, "Premiun"},
        {4, "Primera"}
    };
    eVuelo vuelo[TAMV] =
    {
        {"ABC123", 1, "Activo"},
        {"FGH753", 2, "Demorado"},
        {"CVB951", 3, "Cancelado"},
        {"LAT423", 1, "Activo"},
        {"AIR963", 2, "Demorado"},
        {"DRF357", 3, "Cancelado"}
    };

    inicializarPasajeros(lista, TAM);


    do
    {
        switch(menuPasajeros())
        {
        case 1:
             if(atlaPasajero(lista, TAM, clases, TAMC, vuelo, TAMV, &proximoId, &flagAlta))
            {
                printf("Pasajero cargado con exito!!\n");
            }
            else
            {
                printf("No se pudo cargar el pasajero\n");
            }
            break;
        case 2:
             modificarPasajero(lista, TAM, clases, TAMC, vuelo, TAMV, flagAlta);
            break;
        case 3:
             bajaPasajero(lista, TAM, clases, TAMC, vuelo, TAMV, flagAlta);
            break;
        case 4:
            Informes(lista, TAM, clases, TAMC, vuelo, TAMV, flagAlta);
            break;
        case 5:
            altaForzada(lista, TAM, &proximoId, &flagAlta);
            break;
        case 6:
            confirmarSalida(&salir);
            break;
        case 10:
            informarNoEsNumero();
            break;
        default:
            printf("Opcion invalida\n");
            break;
        }

        system("pause");
    }
    while(salir != 's');


	return EXIT_SUCCESS;
}
