/*
 * Tp4
 *      Author: Belen Paiz
 */
#include <stdio.h>
#include <stdlib.h>
#include "Linkedlist.h"
#include "empleados.h"



void listarEmpleados(LinkedList* pArrayEmpleados);

int main()
{
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* bufferLista = NULL;

    eEmpleado* bufferEmp = NULL;

    int control;

    eEmpleado* emp1 = new_empleadoParam(1000, "Juan", "Perez", 'm', 12000);
    eEmpleado* emp2 = new_empleadoParam(1001, "Iris", "Garcia", 'f', 15000);
    eEmpleado* emp3 = new_empleadoParam(1002, "Pablo", "Juarez", 'm', 20000);
    eEmpleado* emp4 = new_empleadoParam(1003, "Juliana", "Romero", 'f', 13000);
    eEmpleado* emp5 = new_empleadoParam(1004, "Yamila", "Lauria", 'f', 21000);

    ll_add(listaEmpleados, emp1);
    ll_add(listaEmpleados, emp2);
    ll_add(listaEmpleados, emp3);
    ll_add(listaEmpleados, emp4);
    ll_add(listaEmpleados, emp5);

    listarEmpleados(listaEmpleados); // esta funcion utiliza  ll_len y ll_get
    bufferEmp = new_empleadoParam(1001, "Fernanda", "Garcia", 'f', 15000);
    ll_set(listaEmpleados, 1, bufferEmp);
    printf("Modifique al empleado del indice 1.\n\n");
    listarEmpleados(listaEmpleados);
    system("pause");
    system("cls");

    bufferEmp = ll_pop(listaEmpleados, 1); // la funcion ll_pop utiliza a las funciones ll_remove y getNode

    printf("Elimine empleado del indice 1.\n\n");
    listarEmpleados(listaEmpleados);
    system("pause");
    system("cls");

    bufferEmp = new_empleadoParam(1005, "Barbara", "Ruiz", 'f', 18000);
    ll_push(listaEmpleados, 1, bufferEmp);

    printf("Inserte empleado en el indice 1.\n\n");
    listarEmpleados(listaEmpleados);
    system("pause");
    system("cls");

    bufferLista = ll_filter(listaEmpleados, empleadobuscaSexoF);
    control = ll_isEmpty(bufferLista);
    if(control)
    {
        printf("****Aca entro solo si la lista filtrada no esta vacia***\n\n");
        printf("lista nueva filtrada por sexo femenino.\n\n");
        listarEmpleados(bufferLista);
        system("pause");
        system("cls");
    }


    listarEmpleados(listaEmpleados);
    bufferLista = ll_subList(listaEmpleados, 1,4);
    printf("lista nueva desde indice 1 al indice 4'sin incluir este ultimo'.\n\n");
    listarEmpleados(bufferLista);

    control = ll_containsAll(listaEmpleados, bufferLista); // la funcion ll_containsAll utiliza a las funciones ll_contains y ll_indexOf

    if(control)
    {
        printf("****La segunda lista esta contenida en la primera****\n\n");
        system("pause");
        system("cls");
    }

    listarEmpleados(listaEmpleados);
    bufferLista = ll_clone(listaEmpleados); // ll_clone utiliza a la funcion ll_sublist
    printf("lista nueva clonada de la lista original de empleados.\n\n");
    listarEmpleados(bufferLista);
    system("pause");
    system("cls");

    listarEmpleados(listaEmpleados);
    ll_sort(listaEmpleados, empleadoCompareSueldo, 1);
    printf("lista ordenada por sueldo de manera ascendente.\n\n");
    listarEmpleados(listaEmpleados);

    empleadoDestroy(bufferEmp);
    ll_deleteLinkedList(listaEmpleados); // ll_deleteLinkedList utiliza a la funcion ll_clear
    ll_deleteLinkedList(bufferLista);
    return 0;
}


void listarEmpleados(LinkedList* pArrayEmpleados)
{
    if(pArrayEmpleados != NULL)
    {
        for(int i=0; i<ll_len(pArrayEmpleados); i++)
        {
            mostrarEmpleadoDinamico(ll_get(pArrayEmpleados, i));
        }
    }
}

