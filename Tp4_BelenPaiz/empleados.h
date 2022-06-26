#ifndef EMPLEADOS_H_INCLUDED
#define EMPLEADOS_H_INCLUDED

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char sexo;
    float sueldo;
}eEmpleado;

#endif // EMPLEADOS_H_INCLUDED

//mostrar

void mostrarEmpleado(eEmpleado unEmpleado);
void mostrarEmpleadoDinamico(eEmpleado* pEmpleado);

//constructores

eEmpleado* new_empleado();
eEmpleado* new_empleadoParam(int id, char* nombre, char* apellido, char sexo, float sueldo);
eEmpleado* new_empleadoStr(char* id, char* nombre, char* apellido, char* sexo, char* sueldo);

//setters

int empleadoSetId(eEmpleado* emp, int id);
int empleadoSetNombre(eEmpleado* emp, char* nombre);
int empleadoSetApellido(eEmpleado* emp, char* apellido);
int empleadoSetSexo(eEmpleado* emp, char sexo);
int empleadoSetSueldo(eEmpleado* emp, float sueldo);

//getters

int empleadoGetId(eEmpleado* emp, int* id);
int empleadoGetNombre(eEmpleado* emp, char* nombre);
int empleadoGetNombreCompleto(eEmpleado* emp, char* nombre);
int empleadoGetApellido(eEmpleado* emp, char* apellido);
int empleadoGetSexo(eEmpleado* emp, char* sexo);
int empleadoGetSexoFull(eEmpleado* emp, char* sexo);
int empleadoGetSueldo(eEmpleado* emp, float* sueldo);

//destructor

void empleadoDestroy(eEmpleado* emp);


int empleadobuscaSexoF(void* emp);
int empleadoCompareSueldo(void* emp1, void* emp2);
