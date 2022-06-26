#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "empleados.h"


void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%d      %s      %s      %c      %.2f\n\n",
           unEmpleado.id,
           unEmpleado.nombre,
           unEmpleado.apellido,
           unEmpleado.sexo,
           unEmpleado.sueldo);
}

void mostrarEmpleadoDinamico(eEmpleado* pEmpleado)
{
    printf("%4d      %10s      %10s      %c      %6.2f\n\n",
           pEmpleado->id,
           pEmpleado->nombre,
           pEmpleado->apellido,
           pEmpleado->sexo,
           pEmpleado->sueldo);
}


eEmpleado* new_empleado()
{
    eEmpleado* nuevoEmpleado = NULL;
    nuevoEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));
    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->id = 0;
        strcpy(nuevoEmpleado->nombre, "");
        strcpy(nuevoEmpleado->apellido, "");
        nuevoEmpleado->sexo = ' ';
        nuevoEmpleado->sueldo = 0;
    }
    return nuevoEmpleado;
}

eEmpleado* new_empleadoParam(int id, char* nombre, char* apellido, char sexo, float sueldo)
{
    eEmpleado* nuevoEmpleado = new_empleado();
        if(!(empleadoSetId(nuevoEmpleado, id) &&
           empleadoSetNombre(nuevoEmpleado, nombre) &&
           empleadoSetApellido(nuevoEmpleado, apellido) &&
           empleadoSetSexo(nuevoEmpleado, sexo) &&
           empleadoSetSueldo(nuevoEmpleado, sueldo)))
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    return nuevoEmpleado;
}

int empleadoSetId(eEmpleado* emp, int id)
{
    int todoOk = 0;

    if(emp != NULL && id >= 1000)
    {
        emp->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int empleadoSetNombre(eEmpleado* emp, char* nombre)
{
    int todoOk = 0;

    if(emp != NULL && nombre != NULL && strlen(nombre) < 20 && strlen(nombre) > 2)
    {
        strcpy(emp->nombre, nombre);
        strlwr(emp->nombre);
        emp->nombre[0] = toupper(emp->nombre[0]);
        todoOk = 1;
    }
    return todoOk;
}

int empleadoSetApellido(eEmpleado* emp, char* apellido)
{
    int todoOk = 0;

    if(emp != NULL && apellido != NULL && strlen(apellido) < 20 && strlen(apellido) > 2)
    {
        strcpy(emp->apellido, apellido);
        strlwr(emp->apellido);
        emp->apellido[0] = toupper(emp->apellido[0]);
        todoOk = 1;
    }
    return todoOk;
}

int empleadoSetSexo(eEmpleado* emp, char sexo)
{
    int todoOk = 0;

    if(emp != NULL && (sexo == 'f' || sexo == 'm' || sexo == 'F' || sexo == 'M'))
    {
        sexo = tolower(sexo);
        emp->sexo = sexo;
        todoOk = 1;
    }
    return todoOk;
}

int empleadoSetSueldo(eEmpleado* emp, float sueldo)
{
    int todoOk = 0;

    if(emp != NULL && sueldo >= 0)
    {
        emp->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

void empleadoDestroy(eEmpleado* emp)
{
    free(emp);
}

int empleadoGetId(eEmpleado* emp, int* id)
{
  int todoOk = 0;

    if(emp != NULL && id != NULL)
    {
        *id = emp->id;
        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetNombre(eEmpleado* emp, char* nombre)
{
    int todoOk = 0;

    if(emp != NULL && nombre != NULL)
    {
        strcpy(nombre, emp->nombre);
        todoOk = 1;
    }
    return todoOk;
}
int empleadoGetNombreCompleto(eEmpleado* emp, char* nombre)
{
    int todoOk = 0;

    if(emp != NULL && nombre != NULL)
    {
        strcpy(nombre, emp->nombre);
        strcat(nombre, " ");
        strcat(nombre, emp->apellido);
        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetApellido(eEmpleado* emp, char* apellido)
{
    int todoOk = 0;

    if(emp != NULL && apellido!= NULL)
    {
        strcpy(apellido, emp->apellido);
        todoOk = 1;
    }
    return todoOk;
}
int empleadoGetSexo(eEmpleado* emp, char* sexo)
{
    int todoOk = 0;

    if(emp != NULL && sexo != NULL)
    {
        *sexo = emp->sexo;
        todoOk = 1;
    }
    return todoOk;
}

int empleadoGetSexoFull(eEmpleado* emp, char* sexo)
{
    int todoOk = 0;
    if(emp != NULL && sexo != NULL)
    {
        if(emp->sexo == 'm')
        {
            strcpy(sexo, "Masculino");
        }
        else
        {
            strcpy(sexo, "Femenino");
        }
        todoOk = 1;
    }
    return todoOk;
}
int empleadoGetSueldo(eEmpleado* emp, float* sueldo)
{
    int todoOk = 0;

    if(emp != NULL && sueldo != NULL)
    {
        *sueldo = emp->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

eEmpleado* new_empleadoStr(char* id, char* nombre, char* apellido, char* sexo, char* sueldo)
{
    eEmpleado* nuevoEmpleado = new_empleado();
        if(!(empleadoSetId(nuevoEmpleado, atoi(id)) &&
           empleadoSetNombre(nuevoEmpleado, nombre) &&
           empleadoSetApellido(nuevoEmpleado, apellido) &&
           empleadoSetSexo(nuevoEmpleado, sexo[0]) &&
           empleadoSetSueldo(nuevoEmpleado, atof(sueldo))))
        {
            free(nuevoEmpleado);
            nuevoEmpleado = NULL;
        }
    return nuevoEmpleado;
}

int empleadobuscaSexoF(void* emp)
{
    int todoOk = 0;
    char sexo;

    if(emp != NULL)
    {
        empleadoGetSexo(emp, &sexo);
        if(sexo == 'f')
        {
            todoOk = 1;
        }
    }
    return todoOk;
}
int empleadoCompareSueldo(void* emp1, void* emp2)
{
    int todoOk = 0;
    int sueldo1;
    int sueldo2;

    if(emp1 != NULL && emp2 != NULL)
    {
        empleadoGetSueldo(emp1, &sueldo1);
        empleadoGetSueldo(emp2, &sueldo2);
        if(sueldo1 > sueldo2)
        {
            todoOk = 1;
        }
        else
        {
            if(sueldo1 < sueldo2)
            {
                todoOk = -1;
            }
        }

    }
    return todoOk;
}
