#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include  "ArrayList.h"

int main()
{
    ArrayList *pList = al_newArrayList();
    int opcion = 0;

    copiar(pList);
    while( opcion != 5)
    {
        opcion = menu(1,5);
        system("cls");

        switch(opcion)
        {
        case 1:
            al_add(pList,alta_usuario());
            break;

        case 2:
            if(baja_usuario(pList) == 1)
            {
                printf("\nSe dio de baja correctamente");
                recibeChar("\nEnter para continuar");
            }
            else
            {
                printf("\nEl id ingresado no fue dado de alta");
                recibeChar("\nEnter para continuar");
            }
            break;

        case 3:
            modificar_usuario(pList);
            break;

        case 4:
            listar_usuarios(pList);
            break;

        case 5:
            guardar(pList);
            break;
        }
    }
}
