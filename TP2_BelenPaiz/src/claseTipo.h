/*
 * claseTipo.h
 *
 *  Created on: 14 may 2022
 *      Author: belen
 */

#ifndef CLASETIPO_H_
#define CLASETIPO_H_

typedef struct
{
   int id;
   char descripcion[20];
}eClaseTipo;


#endif /* CLASETIPO_H_ */
/// @brief realiza la carga de la descripcion del tipo de clase
///
/// @param clases vector de clases
/// @param tam tamaño del vector de clases
/// @param id int numero de id que debe buscar
/// @param desc cadena donde copiara la descripcion
/// @return retorna 1 si pudo cargar la descripcion
int cargarDescripcionClase(eClaseTipo clases[], int tam, int id, char desc[]);

/// @brief  lista las clases que estan cargadas en el sistema
///
/// @param clases vector de clases
/// @param tam tamaño del vector de clases
/// @return retorna 1 si pudo listar las clases
int listarClases(eClaseTipo clases[], int tam);

/// @brief  busca un tipo de clase con un numero de id
///
/// @param vec vector de clases
/// @param tam tamaño del vector de clases
/// @param id int numero de id a buscar
/// @param pIndex int numero de indice donde se encontro el id
/// @return retorna 1 si pudo encontrar el tipo
int buscarClaseTipo(eClaseTipo vec[], int tam, int id, int* pIndex);

/// @brief  valida si un numero de id corresponde a una clase disponible
///
///
/// @param vec vector de clases
/// @param tam tamaño del vector de clases
/// @param id int numero de id a validar
/// @return retorna 1 si pudo validar el tipo
int validarClaseTipo(eClaseTipo vec[], int tam, int id);
