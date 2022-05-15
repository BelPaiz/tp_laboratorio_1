/*
 * validaciones.h
 *
 *  Created on: 14 may 2022
 *      Author: belen
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */

//Cadenas de letras

int validarLetras(char letras[]);
int pidoValidoLetras(char cadena[], int tam, char mensaje[]);

// numero flotante

int pidoValidoFloat(float* pNumero, char mensaje[]);
int validarNumeroFloat(char flotante[], int tam);
int convertirCharAFloat(char flotante[], float* pFloat);

//numeros enteros

int pidoValidoNumero(int* pNumero, char mensaje[]);
int validarNumero(char numero[]);
int convertirCharAInt(char num[], int* pnumero);
int pidoValidoNumeroRango(int* pNumero, char mensaje[], int minimo, int maximo);
