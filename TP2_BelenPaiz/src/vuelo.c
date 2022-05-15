/*
 * vuelo.c
 *
 *  Created on: 14 may 2022
 *      Author: belen
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vuelo.h"

int cargarEstadoVuelo(eVuelo vec[], int tam, char codigo[], char desc[])
{
    int todoOk = 0;

    if(vec != NULL && tam > 0)
    {
      for(int i = 0; i < tam; i++)
      {
          if(stricmp(vec[i].codigoVuelo, codigo)== 0)
          {
              strcpy(desc, vec[i].descEstado);
              todoOk = 1;
              break;
          }
      }
    }
    return todoOk;
}

int buscarCodigoVuelo(eVuelo vec[], int tam, char codigo[], int* pIndex)
{
    int todoOk = 0;


    if(vec != NULL && pIndex != NULL && codigo != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if((stricmp(vec[i].codigoVuelo, codigo)) == 0)
            {
                *pIndex = i;
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}

int validarCodigoVuelo(eVuelo vec[], int tam, char codigo[])
{
    int esValido = 0;
    int indice;

    if(buscarCodigoVuelo(vec, tam, codigo, &indice) == 1)
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }
    return esValido;
}
