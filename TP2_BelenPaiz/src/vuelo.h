/*
 * vuelo.h
 *
 *  Created on: 14 may 2022
 *      Author: belen
 */

#ifndef VUELO_H_
#define VUELO_H_

typedef struct
{
    char codigoVuelo[10];
    int estadoVuelo;
    char descEstado[10];
}eVuelo;


#endif /* VUELO_H_ */

int cargarEstadoVuelo(eVuelo vec[], int tam, char codigo[], char desc[]);
int buscarCodigoVuelo(eVuelo vec[], int tam, char codigo[], int* pIndex);
int validarCodigoVuelo(eVuelo vec[], int tam, char codigo[]);
