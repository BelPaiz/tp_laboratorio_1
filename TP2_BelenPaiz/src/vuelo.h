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


/// @brief guarda la descripcion de un estado de vuelo en un lugar de memoria ingresado por el usuario
///
/// @param vec vector de la estructura de vuelo
/// @param tam tamaño del vector de la estructura de vuelo
/// @param codigo cadena de texto con el codigo del estado que quiero buscar
/// @param desc lugar donde copia la descripcion asociada al codigo ingresado
/// @return retorna 1 si pudo cargar la descripcion
int cargarEstadoVuelo(eVuelo vec[], int tam, char codigo[], char desc[]);

/// @brief buscar si el id de codigo de vuelo ingresado es corresponde a una estructura de vuelo valida
///
/// @param vec vector de la estructura de vuelo
/// @param tam tamaño del vector de la estructura de vuelo
/// @param codigo cadena de texto del codigo q se desea buscar
/// @param pIndex int* al lugar donde se escribira el indice del codigo que se busco
/// @return retorna 1 si pudo encontrar el codigo ingresado
int buscarCodigoVuelo(eVuelo vec[], int tam, char codigo[], int* pIndex);

/// @brief valida si el codigo ingresado corresponde a una estructura de vuelo activa
///
/// @param vec vector de estructura de vuelo
/// @param tam tamaño del vector de la estructura de vuelo
/// @param codigo cadena de texto con el codigo q se desea validar
/// @return retorna 1 si el codigo existe, 0 si no.
int validarCodigoVuelo(eVuelo vec[], int tam, char codigo[]);
