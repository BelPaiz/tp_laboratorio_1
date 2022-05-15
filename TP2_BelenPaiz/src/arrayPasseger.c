/*
 * arrayPasseger.c
 *
 *  Created on: 14 may 2022
 *      Author: belen
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include"arrayPasseger.h"

int menuPasajeros()
{
    int opcion;
    int opcionIngresada;

    //system("cls");
    printf("   *** ABM Pasajeros ***\n\n");
    printf("1. Alta Pasajero\n");
    printf("2. Modificar Pasajero\n");
    printf("3. Baja Pasajero\n");
    printf("4. Informar\n");
    printf("5. Alta Forzada de pasajeros\n");
    printf("6. salir\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    opcionIngresada = (scanf("%d", &opcion));

    if(opcionIngresada == 0)
    {
        opcion = 10;
    }
    return opcion;
}


void informarNoEsNumero()
{
    printf("Eso no es un numero.\n");
}

void confirmarSalida(char* x)
{
    printf("Confirma que desea salir?: ");
    fflush(stdin);
    scanf("%c", x);
}

int inicializarPasajeros(ePasajero vec[], int tam)
{
    int todoOk = 0;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(ePasajero vec[], int tam, int* pIndex)
{
    int todoOk = 0;


    if(vec && pIndex && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if(vec[i].isEmpty == 1)
            {
                *pIndex = i;
                break;
            }
            todoOk = 1;
        }
    }
    return todoOk;
}

int atlaPasajero(ePasajero vec[], int tam, eClaseTipo clas[], int tamClas,
                 eVuelo vuelo[], int tamV, int* pNextId, int* pFlag)
{
    int todoOk = 0;
    int indice;
    ePasajero nuevoPasajero;
    char bufferCodigoVuelo[10];


    if(vec != NULL && pNextId != NULL && clas != NULL && tam > 0 && tamClas > 0 )
    {
        system("cls");
        printf("*** Alta Pasajero ***\n\n");
        buscarLibre(vec, tam, &indice);
        if(indice == -1)
        {
            printf("No hay lugar en el sistema.\n");
        }
        else
        {
            nuevoPasajero.id = *pNextId;

            pidoValidoLetras(nuevoPasajero.nombre, 51, "Nombre");

            pidoValidoLetras(nuevoPasajero.apellido, 51, "Apellido");

            pidoValidoFloat(&nuevoPasajero.precio, "Precio");

            printf("Ingrese Codigo de vuelo: ");
            fflush(stdin);
            gets(bufferCodigoVuelo);
            while(!validarCodigoVuelo(vuelo, tamV, bufferCodigoVuelo))
            {
                printf("Ingreso Invalido. Reingrese Codigo de vuelo: ");
                fflush(stdin);
                gets(bufferCodigoVuelo);
            }
            strcpy(nuevoPasajero.codigoVuelo, bufferCodigoVuelo);

            listarClases(clas, tamClas);

            pidoValidoNumeroRango(&nuevoPasajero.tipoPasajero, "codigo Tipo de pasajero", 1, 4);

            nuevoPasajero.isEmpty = 0;

            vec[indice] = nuevoPasajero;
            mostrarPasajero(vec[indice], clas, vuelo, tamClas, tamV);

            (*pNextId)++;
            *pFlag = 0;
            todoOk = 1;
        }
    }
    return todoOk;
}

void mostrarPasajero(ePasajero pas, eClaseTipo clas[], eVuelo vuelo[], int tamC, int tamV)
{
    char descripcion[20];
    char estadoVuelo[10];

    printf("\nId: %d\n", pas.id);
    printf("Nombre: %s\n", pas.nombre);
    printf("Apellido: %s\n", pas.apellido);
    printf("Precio: %.2f\n", pas.precio);
    printf("Codigo de Vuelo: %s\n", pas.codigoVuelo);
    cargarDescripcionClase(clas, tamC, pas.tipoPasajero, descripcion);
    printf("Tipo de Pasajero: %s\n", descripcion);
    cargarEstadoVuelo(vuelo, tamV, pas.codigoVuelo, estadoVuelo);
    printf("Estado de vuelo: %s\n", estadoVuelo);
}

void mostrarPasajeroFila(ePasajero pas, eClaseTipo clas[], eVuelo vuelo[], int tamC, int tamV)
{
    char descripcion[20];
    char estadoVuelo[10];
    cargarDescripcionClase(clas, tamC, pas.tipoPasajero, descripcion);
    cargarEstadoVuelo(vuelo, tamV, pas.codigoVuelo, estadoVuelo);

    printf("%4d     %10s       %10s      %10.2f       %10s            %10s          %10s\n",
           pas.id,
           pas.nombre,
           pas.apellido,
           pas.precio,
           pas.codigoVuelo,
           descripcion,
           estadoVuelo);
}

int listarPasajeros(ePasajero vec[], int tam, eClaseTipo clas[], int tamClas, eVuelo vuelo[], int tamV)
{
    int todoOk = 0;
    int flag = 1;

    if(vec != NULL && clas != NULL && tamClas > 0 && tam > 0)
    {
        // system("cls");
        printf("*************************************************** PASAJEROS **************************************************\n\n");
        printf(" ID           NOMBRE          APELLIDO       PRECIO           COD.VUELO           CLASE/TIPO        ESTADO VUELO\n");
        printf("----------------------------------------------------------------------------------------------------------------\n\n");

        for(int i=0; i<tam; i++)
        {
            if( !vec[i].isEmpty)
            {
                mostrarPasajeroFila(vec[i], clas, vuelo, tamClas, tamV);
                flag = 0;
            }
        }
        if(flag)
        {
            printf(" No hay pasajeros cargados en el sistema.\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int harcodearPasajeros(ePasajero vec[], int tam, int cant, int* pNextId)
{
    int todoOk = 0;

    ePasajero pasajeros[15] =
    {
        {0, "Juan", "Perez", 12365.23, "ABC123",1,0},
        {0, "Ana", "Guzman", 45621.02, "FGH753",2,0},
        {0, "Pepe", "Argento", 12657.13, "CVB951",1,0},
        {0, "Maria", "Mendez", 16983.20, "LAT423",2,0},
        {0, "Violeta", "Perez", 45789.14, "CVB951",3,0},
        {0, "Tati", "Ortiz", 39456.36, "ABC123",4,0},
        {0, "Fabian", "Juarez", 46126.47, "LAT423",2,0},
        {0, "Ivan", "Garcia", 29789.63, "DRF357",3,0},
        {0, "Ruben", "Dario", 45126.41, "AIR963",4,0},
        {0, "Alicia", "Meza", 34456.22, "FGH753",3,0},
        {0, "Jose", "Mateo", 31523.22, "ABC123",1,0},
        {0, "Emilce", "Nuñez", 15456.22, "CVB951",2,0},
        {0, "Julio", "Seca", 26425.22, "FGH753",1,0},
        {0, "Uriel", "Mos", 13489.22, "AIR963",4,0},
        {0, "Victor", "Ruiz", 16126.22, "DRF357",3,0}
    };
    if(vec != NULL && pNextId != NULL && tam >= 0 && cant >= 0)
    {
        for(int i = 0; i < cant; i++)
        {
            vec[i] = pasajeros[i];
            vec[i].id = *pNextId;
            (*pNextId)++;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarPasajero(ePasajero vec[], int tam, int id, int* pIndex)
{
    int todoOk = 0;
    if( vec != NULL && pIndex != NULL && tam > 0 )
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( !vec[i].isEmpty  && vec[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
int bajaPasajero(ePasajero vec[], int tam, eClaseTipo clas[], int tamC, eVuelo vuelo[], int tamV, int flag)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(vec != NULL && clas != NULL && vuelo != NULL && tam > 0 && tamC > 0 && tamV > 0 && flag == 0)
    {
        listarPasajeros(vec, tam, clas, tamC, vuelo, tamV);
        printf("Ingrese Id: ");
        scanf("%d",&id);

        if(buscarPasajero(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No existe un pasajero con id %d en el sistema.\n", id);
            }
            else
            {
                mostrarPasajero(vec[indice], clas, vuelo, tamC, tamV);
                printf("Presione 's' para confirmar baja: ");
                fflush(stdin);
                scanf("%c",&confirma);

                if(confirma == 's' || confirma == 'S')
                {
                    vec[indice].isEmpty = 1;
                    printf("Baja exitosa!\n");
                }
                else
                {
                    printf("Baja cancelada por el usuario!\n");
                }
            }
            todoOk = 1;
        }
    }
    else
    {
        printf("Primero debe cargar pasajeros en el sistema.\n");
    }
    return todoOk;
}

int menuModificarPasajero()
{
    int opcion;

    printf("\n   *** Seleccione campo a modificar ***\n\n");
    printf("1. Nombre.\n");
    printf("2. Apellido.\n");
    printf("3. Precio.\n");
    printf("4. Tipo de Pasajero.\n");
    printf("5. Codigo de vuelo.\n");
    printf("6. Salir\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int modificarPasajero(ePasajero vec[], int tam, eClaseTipo clas[], int tamC, eVuelo vuelo[], int tamV, int flag)
{
    int todoOk = 0;
    int indice;
    int id;
    char auxcad[100];
    float precio;
    int tipoPasajero;

    if(vec && clas && vuelo && tam > 0 && tamC > 0 && tamV > 0 && flag == 0)
    {
        listarPasajeros(vec, tam, clas, tamC, vuelo, tamV);
        printf("Ingrese Id: ");
        scanf("%d",&id);

        if(buscarPasajero(vec, tam, id, &indice))
        {
            if(indice == -1)
            {
                printf("No existe un empleado con id %d en el sistema.\n", id);
            }
            else
            {
                mostrarPasajero(vec[indice], clas, vuelo, tamC, tamV);

                switch(menuModificarPasajero())
                {
                case 1:
                    pidoValidoLetras(auxcad, 51, "nuevo nombre");
                    strcpy(vec[indice].nombre, auxcad);
                    printf("Nombre modificado!\n");
                    break;

                case 2:
                    pidoValidoLetras(auxcad, 51, "nuevo apellido");
                    strcpy(vec[indice].apellido, auxcad);
                    printf("Apellido modificado!\n");
                    break;

                case 3:
                    pidoValidoFloat(&precio, "nuevo precio");
                    vec[indice].precio = precio;
                    printf("Precio modificado!\n");
                    break;

                case 4:
                    listarClases(clas, tamC);
                    pidoValidoNumeroRango(&tipoPasajero, "nuevo codigo de Tipo de pasajero", 1, 4);
                    vec[indice].tipoPasajero = tipoPasajero;
                    printf("Tipo de pasajero modificado!\n");
                    break;

                case 5:
                    printf("Ingrese Codigo de vuelo: ");
                    fflush(stdin);
                    gets(auxcad);
                    while(!validarCodigoVuelo(vuelo, tamV, auxcad))
                    {
                        printf("Ingreso Invalido. Reingrese Codigo de vuelo: ");
                        fflush(stdin);
                        gets(auxcad);
                    }
                    strcpy(vec[indice].codigoVuelo, auxcad);
                    printf("Codigo de vuelo modificado!\n");
                    break;

                default:
                    printf("Saliendo del menu modificar!\n");
                    break;
                }
            }
            todoOk = 1;
        }
    }
    else
    {
        printf("Primero debe ingresar pasajeros al sistema.\n");
    }
    return todoOk;
}

int menuInformes()
{
    int opcion;

    printf("\n   *** INFORMES ***\n\n");
    printf("1. Listado Pasajeros Ordenados Alfabeticamente por apellido y Tipo de pasajero\n\n");
    printf("2. Total y promedio de precios de pasajes. Cantidad de pasajeros que superan el precio Promedio\n\n");
    printf("3. Listado Pasajeros por codigo de vuelo y estado 'ACTIVO'.\n\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

int ordenarPasajerosApellidoTipoAscDes(ePasajero vec[], int tam, eClaseTipo clas[], int tamC, int criterio)
{
    int todoOk = 0;
    ePasajero auxVec;

    if(vec != NULL && tam >= 0 && clas != NULL && tamC >= 0 && (criterio == 0 || criterio == 1))
    {
        for(int i=0; i < tam -1 ; i++)
        {
            for(int j=i +1; j < tam ; j++)
            {
            	if(!vec[i].isEmpty && !vec[j].isEmpty)
            	{
					if(criterio > 0)
					{
						if((stricmp(vec[i].apellido, vec[j].apellido) > 0)
								|| ((strcmp(vec[i].apellido, vec[j].apellido) == 0) && (vec[i].tipoPasajero != vec[j].tipoPasajero) && (vec[i].tipoPasajero > vec[j].tipoPasajero)))
						{
							auxVec = vec[i];
							vec[i] = vec[j];
							vec[j] = auxVec;
						}
					}
					else
					{
						if((stricmp(vec[i].apellido, vec[j].apellido) < 0)
								|| ((strcmp(vec[i].apellido, vec[j].apellido) == 0) && (vec[i].tipoPasajero != vec[j].tipoPasajero) && (vec[i].tipoPasajero < vec[j].tipoPasajero)))
						{
							auxVec = vec[i];
							vec[i] = vec[j];
							vec[j] = auxVec;
						}
					}
            	}
            }
            todoOk = 1;
        }
    }
    return todoOk;
}
int Informes(ePasajero vec[], int tam, eClaseTipo clas[], int tamC, eVuelo vuelo[], int tamV, int flag)
{
    int todoOk = 0;
    int criterio;

    if(vec != NULL && tam > 0 && clas != NULL && tamC > 0 && vuelo != NULL && tamV > 0 && flag == 0)
    {
        switch(menuInformes())
        {
        case 1:
            printf("Ingrese criterio de ordenamiento: 1 'ASCENDENTE' / 0'DESCENDENTE': ");
            scanf("%d", &criterio);
            while(criterio != 0  && criterio != 1)
            {
                printf("Ingrese criterio de ordenamiento valido: 1 'ASCENDENTE' / 0'DESCENDENTE': ");
                scanf("%d", &criterio);
            }
            ordenarPasajerosApellidoTipoAscDes(vec, tam, clas, tamC, criterio);
            listarPasajeros(vec, tam, clas, tamC, vuelo, tamV);
            break;
        case 2:
            InformesPrecio(vec, tam);
            break;
        case 3:
            ordenarPasajerosCodVueloEstdActivo(vec, tam, vuelo, tamV, clas, tamC);
            break;
        }
        todoOk = 1;
    }
    else
    {
        printf("Primero debe cargar pasajeros en el sistema.\n");
    }
    return todoOk;
}

int InformesPrecio(ePasajero vec[], int tam)
{
    int todoOk = 0;
    float acumuladorPrecios = 0;
    int contadorPasajeros = 0;
    float promedio = 0;
    int contPrecioMayorProm = 0;


    if(vec!=NULL && tam > 0 )
    {
        for(int i = 0; i < tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                acumuladorPrecios += vec[i].precio;
                contadorPasajeros ++;
            }

        }
        if(contadorPasajeros != 0)
        {
            promedio = acumuladorPrecios / contadorPasajeros;
        }
        system("cls");
        printf("        *** Informes Precios ***\n\n");
        printf("El total en precios de vuelos es: $ %2.f\n", acumuladorPrecios);
        printf("El promedio de precios de vuelos es: $ %2.f\n", promedio);
        printf("Pasajeros que superan el precio promedio: \n\n");
        printf("     Nombre        Apellido          Precio\n");
        printf("-------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if(vec[i].precio > promedio)
            {
                contPrecioMayorProm++;
                printf("%10s      %10s        %10.2f\n", vec[i].nombre, vec[i].apellido, vec[i].precio);
            }
        }
        printf("La cantidad es: %d pasajeros.\n", contPrecioMayorProm);
        todoOk = 1;
    }
    return todoOk;
}

int ordenarPasajerosCodVueloEstdActivo(ePasajero vec[], int tam, eVuelo vuelo[], int tamV, eClaseTipo clase[], int tamC)
{
    int todoOk = 0;
    char desc[10];
    ePasajero auxPass;
    int flag = 1;

    if(vec != NULL && tam > 0 && vuelo != NULL && tamV > 0 && clase != NULL && tamC > 0)
    {
        for(int i=0; i < tam - 1; i++)
        {
            for(int j=i+1; j < tam; j++)
            {
                if(stricmp(vec[i].codigoVuelo, vec[j].codigoVuelo) > 0 || stricmp(vec[i].codigoVuelo, vec[j].codigoVuelo) == 0)
                {
                    auxPass = vec[i];
                    vec[i] = vec[j];
                    vec[j] = auxPass;
                }
            }
        }
        printf("*************************************************** PASAJEROS **************************************************\n\n");
        printf(" ID           NOMBRE          APELLIDO       PRECIO           COD.VUELO           CLASE/TIPO        ESTADO VUELO\n");
        printf("----------------------------------------------------------------------------------------------------------------\n\n");

        for(int i=0; i < tam; i++)
        {
            cargarEstadoVuelo(vuelo, tamV, vec[i].codigoVuelo, desc);
            if(!vec[i].isEmpty && stricmp(desc, "ACTIVO") == 0)
            {
                mostrarPasajeroFila(vec[i], clase, vuelo, tamC, tamV);
                flag = 0;
            }
        }
        if(flag == 1)
        {
            printf("No hay vuelos activos en el sistema.\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaForzada(ePasajero vec[], int tam, int* pNextId, int*pFlag)
{
    int todoOk = 0;
    int cantidad;
    int nextId;
    nextId = *pNextId;

    if(vec != NULL && pNextId != NULL && tam > 0)
    {
        printf("Cuantos pasajeros desea dar de alta: ");
        scanf("%d", &cantidad);
        harcodearPasajeros(vec, tam, cantidad, &nextId);
        *pNextId = nextId;
        *pFlag = 0;
        todoOk = 1;
    }
    return todoOk;
}


