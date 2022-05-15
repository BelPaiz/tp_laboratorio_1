/*
 * arrayPasseger.h
 *
 *  Created on: 14 may 2022
 *      Author: belen
 */

#include "claseTipo.h"
#include "vuelo.h"
#include "validaciones.h"

#ifndef ARRAYPASSEGER_H_
#define ARRAYPASSEGER_H_

typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    float precio;
    char codigoVuelo[10];
    int tipoPasajero;
    int estadoVuelo;
    int isEmpty;
}ePasajero;

#endif /* ARRAYPASSEGER_H_ */

int menuPasajeros();
void informarNoEsNumero();
void confirmarSalida(char* x);
int inicializarPasajeros(ePasajero vec[], int tam);
int buscarLibre(ePasajero vec[], int tam, int* pIndex);
int atlaPasajero(ePasajero vec[], int tam, eClaseTipo clas[], int tamClas, eVuelo vuelo[], int tamV, int* pNextId, int* pFlag);
void mostrarPasajero(ePasajero pas, eClaseTipo clas[], eVuelo vuelo[], int tamC, int tamV);
void mostrarPasajeroFila(ePasajero pas, eClaseTipo clas[], eVuelo vuelo[], int tamC, int tamV);
int listarPasajeros(ePasajero vec[], int tam, eClaseTipo clas[], int tamClas, eVuelo vuelo[], int tamV);
int harcodearPasajeros(ePasajero vec[], int tam, int cant, int* pNextId);
int buscarPasajero(ePasajero vec[], int tam, int id, int* pIndex);
int bajaPasajero(ePasajero vec[], int tam, eClaseTipo clas[], int tamC, eVuelo vuelo[], int tamV, int flag);
int menuModificarPasajero();
int modificarPasajero(ePasajero vec[], int tam, eClaseTipo clas[], int tamC, eVuelo vuelo[], int tamV, int flag);
int menuInformes();
int ordenarPasajerosApellidoTipoAscDes(ePasajero vec[], int tam, eClaseTipo clas[], int tamC, int criterio);
int Informes(ePasajero vec[], int tam, eClaseTipo clas[], int tamC, eVuelo vuelo[], int tamV, int flag);
int InformesPrecio(ePasajero vec[], int tam);
int ordenarPasajerosCodVueloEstdActivo(ePasajero vec[], int tam, eVuelo vuelo[], int tamV, eClaseTipo clase[], int tamC);
int altaForzada(ePasajero vec[], int tam, int* pNextId, int*pFlag);
