#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"
#include "funciones.h"
#include  "ArrayList.h"

int main()
{
    ArrayList *pList = al_newArrayList();
    ArrayList *arrayPrioridad0;
    ArrayList *arrayPrioridad1;

    Etarea *tarea;

    int opcion = 0;

    //copiar(pList);
    while( opcion != 6)
    {
        opcion = menu(1,6);

        switch(opcion)
        {
        case 1:
            copiar(pList,tarea);
            //listar_tareas(pList);
            break;

        case 2:
            arrayPrioridad0 = particionar_prioridad_0(pList);
            arrayPrioridad1 = particionar_prioridad_1(pList);
            break;

        case 3:
            ordenar(arrayPrioridad0,arrayPrioridad1);
            break;

        case 4:
            resolver_prioridad0(arrayPrioridad0);
            resolver_prioridad1(arrayPrioridad1);
            break;

        case 5:
            guardar(arrayPrioridad0,arrayPrioridad1);
            break;

        case 6:
            break;
        }
    }
}
