/*
 * claseTipo.c
 *
 *  Created on: 14 may 2022
 *      Author: belen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "claseTipo.h"

int cargarDescripcionClase(eClaseTipo clases[], int tam, int id, char desc[])
{
    int todoOk = 0;

    if(clases != NULL && desc != NULL && tam > 0)
    {
      for(int i = 0; i < tam; i++)
      {
          if(clases[i].id == id)
          {
              strcpy(desc, clases[i].descripcion);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}

int listarClases(eClaseTipo clases[], int tam)
{
    int todoOk = 0;

    if(clases != NULL && tam > 0)
    {
        printf("    *** TIPOS DE CLASES ***    \n");
        printf("    ID     DESCRIPCION\n");
        printf("-----------------------\n");
      for(int i = 0; i < tam; i++)
      {
            printf("    %4d         %10s\n", clases[i].id, clases[i].descripcion);
      }
      todoOk = 1;
    }
    return todoOk;
}

int buscarClaseTipo(eClaseTipo vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;


    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarClaseTipo(eClaseTipo vec[], int tam, int id)
{
    int esValido = 0;
    int indice;

    if(buscarClaseTipo(vec, tam, id, &indice) == 1)
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}


