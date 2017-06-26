/*******************************************************************
*
*   Programa:
*   ~ ArrayList | Trabajo Práctico N° 4.
*
*   Objetivo:
*   Implementacion de la biblioteca ArrayList con archivos de texto (Lectura-Escritura).
*
*
*   Version:
*   0.1 del 16 de junio de 2017.
*
*   Autor:
*   Luca Provenzano | 1F.
*
********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>
#include "ArrayList.h"
#include "lib.h"
#include "utn.h"

int main()
{
    ArrayList* ListadoPersonas = al_newArrayList();

    Persona* personita;
    char seguir='s', opcionModificacion, guardar;
    int validacion, i, checkIndex;

    if((cargarTxt(ListadoPersonas, personita))!=-1)
        pause("Se cargo el fichero. (ENTER)");
    else
        pause("Ha ocurrido un error. (ESC PARA SALIR)");

    do
    {
        system("CLS");
        switch(menu())
        {
        case '1':
            system("CLS");
            personita = newPersona();
            validacion = unaPersona(personita);
            if(validacion!=-1)
            {
                al_add(ListadoPersonas, personita);
                system("CLS");
                pause("\nLa persona se dio de alta correctamente.");
            }
            else
            {
                system("CLS");
                pause("\nSe ha cancelado la operacion.");
            }
            break;
        case '2':
            system("CLS");
            baseListado();

            for(i=0; i<al_len(ListadoPersonas); i++)
            {
                printPersona(ListadoPersonas, al_get(ListadoPersonas,i));
            }

            printf("\nID a dar de baja: ");
            scanf("%d", &checkIndex);

            if(al_remove(ListadoPersonas, checkIndex)!=-1)
                pause("\nLa persona se dio de baja correctamente.");
            else
                pause("\nLa persona no existe.");
            break;

        case '3':
            system("CLS");
            baseListado();
            for(i=0; i<al_len(ListadoPersonas); i++)
            {
                printPersona(ListadoPersonas, al_get(ListadoPersonas,i));
            }

            printf("\nID a modificar: ");
            scanf("%d", &checkIndex);
            personita = (Persona*)al_get(ListadoPersonas, checkIndex);

            if((personita)!=NULL)
            {
                printf("\n1. Nombre.\n2. Apellido.\n3. Edad.\n");
                opcionModificacion = getch();

                switch(opcionModificacion)
                {
                case '1':
                    fflush(stdin);
                    getValidString("\nNombre: ", "Debe ser un nombre valido", personita->nombre);
                    break;
                case '2':
                    fflush(stdin);
                    getValidString("\nApellido: ", "Debe ser un apellido valido", personita->apellido);
                    break;
                case '3':
                    personita->edad = getValidInt("\nEdad: ", "Solo numerico", 0, 100);
                    break;
                }
                pause("\nSe modifico el parametro correctamente.");
            }
            else
            {
                pause("\nLa persona no existe.");
            }
            break;
        case '4':
            system("CLS");
            baseListado();

            for(i=0; i<al_len(ListadoPersonas); i++)
            {
                printPersona(ListadoPersonas, al_get(ListadoPersonas,i));
            }

            pause("\n(ENTER) para regresar.");
            break;
        case '5':
            printf("\nGuardar cambios S/N ?: ");
            guardar = tolower(getch());

            if(guardar == 's')
            {
                if((crearTxt(ListadoPersonas, personita))!=-1)
                    pause("\nSe guardo el txt con exito.");
                else
                    pause("\nNo se ha podido crear el archivo.");
            }
            seguir ='n';
            break;
        }

    }
    while(seguir=='s');
    return 0;
}
