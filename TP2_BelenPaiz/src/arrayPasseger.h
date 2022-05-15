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
/// @brief menu de opciones principal. Brinda opciones y permite cargar una opcion
///
/// @return retorna la opcion ingresada
int menuPasajeros();

/// @brief informa que lo ingresado por el usuario no es un numero
///
void informarNoEsNumero();

/// @brief permite confirmar que se desea salir del menu
///
/// @param x char* letra para confirmar salida
void confirmarSalida(char* x);

/// @brief coloca todos los campos isEmpty de la estructura en 1(vacios)
///
/// @param vec el vector de la estructura de pasajeros
/// @param tam tamaño del vector de pasajeros
/// @return retorna 1 si pudo cumplir su objetivo
int inicializarPasajeros(ePasajero vec[], int tam);

/// @brief busca si hay alguna estructura de pasajeros que este vacia
///
/// @param vec el vector de la estructura de pasajeros
/// @param tam tamaño del vector de pasajeros
/// @param pIndex int* escribe la valor del indice que tiene la estructura vacia
/// @return retorna 1 si pudo encontrar la estructura vacia
int buscarLibre(ePasajero vec[], int tam, int* pIndex);

/// @brief solicita los datos del nuevo pasajero y los guarda en una estructura vacia
///
/// @param vec vector estructura de pasajeros
/// @param tam int tamaño del vector de pasajeros
/// @param clas vector la estructura de clases
/// @param tamClas tamaño del vector de clases
/// @param vuelo vector la estructura de vuelos
/// @param tamV tamaño del vector de vuelos
/// @param pNextId int* permite leer y modificar el valor de la proxima id disponible
/// @param pFlag permite modificar el valor de la bandera q indica que ya se dio de alta un pasajero
/// @return  retorna 1 si pudo guardar los datos en una estructura
int atlaPasajero(ePasajero vec[], int tam, eClaseTipo clas[], int tamClas, eVuelo vuelo[], int tamV, int* pNextId, int* pFlag);

/// @brief muestra la informacion en una estructura de pasajero encolumnada
///
/// @param pas estructura de pasajero
/// @param clas vector de clases
/// @param vuelo vector de vuelos
/// @param tamC tamaño del vector de clases
/// @param tamV tamaño del vector de vuelo
void mostrarPasajero(ePasajero pas, eClaseTipo clas[], eVuelo vuelo[], int tamC, int tamV);

/// @brief muestra la informacion en una estructura de pasajero en una fila
///
/// @param pas estructura de pasajero
/// @param clas vector de clases
/// @param vuelo vector de vuelos
/// @param tamC tamaño del vector de clases
/// @param tamV tamaño del vector de vuelo
void mostrarPasajeroFila(ePasajero pas, eClaseTipo clas[], eVuelo vuelo[], int tamC, int tamV);

/// @brief lista todos las estructuras de pasajeros que no esten vacias en una tabla
///
/// @param vec vector de pasajeros
/// @param tam tamaño del vector de pasajeros
/// @param clas vector de clases
/// @param vuelo vector de vuelos
/// @param tamC tamaño del vector de clases
/// @param tamV tamaño del vector de vuelo
/// @return retorna 1 si pudo listar los pasajeros
int listarPasajeros(ePasajero vec[], int tam, eClaseTipo clas[], int tamClas, eVuelo vuelo[], int tamV);

/// @brief permite cargar datos de pasajeros ficticios en las estructuras de pasajeros que esten vacias
///
/// @param vec vector de pasajeros
/// @param tam tamaño del vector de pasajeros
/// @param cant int cantidad de pasajeros que queremos dar de alta
/// @param pNextId int* permite modificar el valor del proximo id disponible
/// @return retorna 1 si pudo cumplir su objetivo
int harcodearPasajeros(ePasajero vec[], int tam, int cant, int* pNextId);

/// @brief busca si el id ingresado existe y devuelve en q indice se encuentra
///
/// @param vec vector de pasajeros
/// @param tam tamaño del vector de pasajeros
/// @param id int recibe el valor de un numero de id
/// @param pIndex int escribe el valor del indice del id que busco
/// @return retorna 1 si pudo cumplir su objetivo
int buscarPasajero(ePasajero vec[], int tam, int id, int* pIndex);

/// @brief permite dar de baja un pasajero a traves de su id
///
/// @param vec vector de pasajeros
/// @param tam tamaño del vector de pasajeros
/// @param clas vector de clases
/// @param vuelo vector de vuelos
/// @param tamC tamaño del vector de clases
/// @param tamV tamaño del vector de vuelo
/// @param flag lee el valor de la bandera que indica si ya se ingresaron pasajeros
/// @return retorna 1 si la baja fue exitosa
int bajaPasajero(ePasajero vec[], int tam, eClaseTipo clas[], int tamC, eVuelo vuelo[], int tamV, int flag);

/// @brief muestra las opciones disponibles para modificar datos. permite ingresar una opcion
///
/// @return retorna el valor de la opcion ingresada
int menuModificarPasajero();

/// @brief permite modificar datos guardados de pasajeros
///
/// @param vec vector de pasajeros
/// @param tam tamaño del vector de pasajeros
/// @param clas vector de clases
/// @param vuelo vector de vuelos
/// @param tamC tamaño del vector de clases
/// @param tamV tamaño del vector de vuelo
/// @param flag lee el valor de la bandera que indica si ya se ingresaron pasajeros
/// @return retorna 1 si pudo modificar los datos
int modificarPasajero(ePasajero vec[], int tam, eClaseTipo clas[], int tamC, eVuelo vuelo[], int tamV, int flag);

/// @brief muestra las opciones disponibles en informes y permite ingresar una opcion
///
/// @return retorna el valor de la opcion ingresada
int menuInformes();

/// @brief ordena las estructuras de pasajeros por orden alfabetico  de apellido y tipo segun criterio ingresado
///
/// @param vec vector de pasajeros
/// @param tam tamaño del vector de pasajeros
/// @param clas vector de clases
/// @param tamC tamaño del vector de clases
/// @param criterio int 1 si se quiere ordenar de manera ascendente 0 si se desea descendente
/// @return retorna 1 si pudo cumplir su objetivo
int ordenarPasajerosApellidoTipoAscDes(ePasajero vec[], int tam, eClaseTipo clas[], int tamC, int criterio);

/// @brief brinda todas las opciones de informes y ejecuta las opciones elegidas
///
/// @param vec vector de pasajeros
/// @param tam tamaño del vector de pasajeros
/// @param clas vector de clases
/// @param tamC tamaño del vector de clases
/// @param vuelo vector de vuelos
/// @param tamV tamaño del vector de vuelo
/// @param flag lee el valor de la bandera que indica si ya se ingresaron pasajeros
/// @return retorna 1 si pudo informar
int Informes(ePasajero vec[], int tam, eClaseTipo clas[], int tamC, eVuelo vuelo[], int tamV, int flag);

/// @brief informes relacionados a los precios de vuelos
///
/// @param vec vector de pasajeros
/// @param tam tamaño del vector de pasajeros
/// @return retorna 1 si pudo informar
int InformesPrecio(ePasajero vec[], int tam);

/// @brief ordena las estructuras de pasajeros por ordena alfabetico por codigo de vuelo y muestra los que tengan estados de vuelo activos
///
/// @param vec vector de pasajeros
/// @param tam tamaño del vector de pasajeros
/// @param vuelo vector de vuelos
/// @param tamV tamaño del vector de vuelo
/// @param clas vector de clases
/// @param tamC tamaño del vector de clases
/// @return retorna 1 si pudo ordenar
int ordenarPasajerosCodVueloEstdActivo(ePasajero vec[], int tam, eVuelo vuelo[], int tamV, eClaseTipo clase[], int tamC);

/// @brief permite dar de alta pasajeros con datos harcodeados
///
/// @param vec vector de pasajeros
/// @param tam tamaño del vector de pasajeros
/// @param pNextId int* permite leer y modificar el valor de la proxima id disponible
/// @param pFlag permite modificar el valor de la bandera q indica que ya se dio de alta un pasajero
/// @return  retorna 1 si pudo guardar los datos en una estructura
int altaForzada(ePasajero vec[], int tam, int* pNextId, int*pFlag);
