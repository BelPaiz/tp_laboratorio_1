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
/// @brief confirma si lo que se ingreso en la cadena son letras
///
/// @param letras cadena con valores ingresados por el usuario
/// @return retorna 1 si pudo validar que sea letras
int validarLetras(char letras[]);

/// @brief pide y valida cadenas de texto al usuario
///
/// @param cadena donde guardo lo que ingresa el usuario
/// @param tam tamaño de la cadena de datos donde voy a guardar lo que ingresa el usuario
/// @param mensaje nombre del dato que se desea pedir
/// @return retorna 1 si pudo validar y guardar correctamente los datos que ingreso el usuario
int pidoValidoLetras(char cadena[], int tam, char mensaje[]);

// numero flotante

/// @brief permite al usuario ingresar numeros tipo float
///
/// @param pNumero lugar donde guardara los datos ingresados por el usuario
/// @param mensaje nombre del dato que se desea pedir
/// @return retorna 1 si pudo validar y guardar correctamente los datos que ingreso el usuario
int pidoValidoFloat(float* pNumero, char mensaje[]);

/// @brief confirma si lo que se ingreso en la cadena es un numero tipo float
///
/// @param flotante cadena con los datos ingresados por el usuario
/// @param tam tamaño de la cadena de datos ingresados
/// @return retorna 1 si pudo validar que sea un numero float
int validarNumeroFloat(char flotante[], int tam);

/// @brief convierte el numero q ingreso el usuario en un numero float
///
/// @param flotante cadena con los datos ingresados
/// @param pFloat float* al lugar donde se guardara el numero validado
/// @returnretorna 1 si pudo guardar el numero correctamente
int convertirCharAFloat(char flotante[], float* pFloat);

//numeros enteros

/// @brief pide al usauario que ingrese un numero y valida que lo ingresado por el usuario sea un numero entero
///
/// @param pNumero int* al lugar dodne se guardara el numero entero
/// @param mensaje texto que indica cual es el dato solicitado
/// @return retorna 1 si pudo pedir y validar el dato correctamente
int pidoValidoNumero(int* pNumero, char mensaje[]);

/// @brief  valida si el dato ingresado por el usuario contiene solo numeros
///
/// @param numero cadena de texto que contiene lo ingresado por el usuario
/// @return retorna 1 si pudo validar
int validarNumero(char numero[]);

/// @brief convierte la cadena de texto que contiene solo numeros a entero
///
/// @param num cadena de texto ingresada por el usuario
/// @param pnumero int* lugar donde guardara el numero
/// @return retorna 1 si pudo convertir el dato a entero y guardarlo
int convertirCharAInt(char num[], int* pnumero);

/// @brief pide al usauario que ingrese un numero y valida que lo ingresado por el usuario sea un numero entero y se encuentre dentro de el rango especificado
///
/// @param pNumero int* al lugar donde se guardara la informacion ingresada por el usuario ya validada y casteada
/// @param mensaje mensaje texto que indica cual es el dato solicitado
/// @param minimo  int minimo a respetar
/// @param maximo int maximo a respetar
/// @return retorna 1 si pudo pedir y validar la informacion que ingreso el usuario
int pidoValidoNumeroRango(int* pNumero, char mensaje[], int minimo, int maximo);
