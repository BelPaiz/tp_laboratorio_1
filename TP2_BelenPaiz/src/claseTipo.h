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

int cargarDescripcionClase(eClaseTipo clases[], int tam, int id, char desc[]);
int listarClases(eClaseTipo clases[], int tam);
int buscarClaseTipo(eClaseTipo vec[], int tam, int id, int* pIndex);
int validarClaseTipo(eClaseTipo vec[], int tam, int id);
