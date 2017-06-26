#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"
#include "funciones.h"
#include  "ArrayList.h"



int menu(int limiteInf, int limiteSup)
{
    int opcion;

    system("cls");
    printf("----------ABM----------");
    opcion = recibeIntRango("\n1 - Alta\n2 - Baja\n3 - Modificacion\n4 - Listar\n5 - Salir\n\nOpcion: ","\nNo ha ingresado un valor permitido. Reingrese\n\nOpcion: ",limiteInf,limiteSup);

    return opcion;
}
Eusuario* alta_usuario()
{
    Eusuario *usuario = (Eusuario*)malloc(sizeof(Eusuario));

    usuario->id = recibeStringANumeroRango("\nIngrese el Id del usuario (1 a 50): ", "\nNo ha ingresado un valor numerico. Reingrese", 1, 50);

    while(recibeStringLetras("\nIngrese el nombre: ", usuario->nombre) == 0)
    {
        printf("\nEl nombre solo debe contener letras. Reingrese\n");
        recibeChar("\nEnter para continuar");
        continue;
    }
    usuario->sueldo = recibeStringANumeroRangoFloat("\nIngrese el sueldo del usuario: ","\nNo ha ingresado un valor permitido. Reingrese",1,100);
    recibeChar("\nEnter para continuar");
    return usuario;
}

void listar_usuarios(ArrayList *pList)
{
    int i;

    for(i=0; i<pList->size; i++)
    {
        listar(pList->pElements[i]);
    }
    recibeChar("\nEnter para continuar");
}

void listar(Eusuario *usuario)
{
    printf("\nId: %d - Nombre: %s - Sueldo: %.02f",usuario->id, usuario->nombre,usuario->sueldo);
}

int baja_usuario(ArrayList *pList)
{
    int auxId;
    int i;
    int auxReturn = 0;
    Eusuario *auxUsuario;


    auxId = recibeIntRango("\nIngrese el id buscado","\nNo ha ingresado un Id valido. Reingrese",1,50);
    for(i=0; i<pList->size; i++)
    {
        auxUsuario = al_get(pList,i);

        if(auxUsuario->id = auxId)
        {
            al_remove(pList,i);
            auxReturn = 1;
            break;
        }
    }

    recibeChar("\nEnter para continuar");
    return auxReturn;
}


void copiar(ArrayList *plist)
{
    FILE *ARCH;
    Eusuario *pUsuario ;
    int flag = 0;
    int cant;

    ARCH = fopen("archivo.dat","rb");
    if(ARCH == NULL)
    {
        ARCH = fopen("archivo.dat","wb");
        flag = 1;
    }
    if(flag == 0)
    {
        while(!feof(ARCH))
        {
            pUsuario = new_usuario();
            fflush(stdin);
            cant = fread(pUsuario,sizeof(Eusuario),1,ARCH);

            if(cant != 1)
            {
                if(feof(ARCH))
                {
                    break;
                }
                else
                {
                    printf("\nError");
                }
            }

            fflush(stdin);
            al_add(plist,pUsuario);
        }
    }
    recibeChar("\nTermino la copia");
    fclose(ARCH);
}

void guardar(ArrayList *pList)
{
    FILE *ARCH;
    Eusuario *usuario = malloc(sizeof(Eusuario));
    int i;

    ARCH = fopen("archivo.dat","wb+");
    if(ARCH == NULL)
    {
        printf("\nError al abrir el archivo");
    }
    else
    {
        for(i=0; i<pList->size; i++)
        {
            usuario = al_get(pList,i);
            printf("\nId: %d - Nombre: %s - Sueldo: %f",usuario->id,usuario->nombre,usuario->sueldo);
            fwrite(usuario,sizeof(Eusuario),1,ARCH);
        }
    }
    printf("\nTermino el guardado");
    fclose(ARCH);

}

Eusuario * new_usuario()
{
    Eusuario *usuario;
    usuario = (Eusuario*)malloc(sizeof(Eusuario));

    return usuario;
}

void modificar_usuario(ArrayList *pList)
{
    int auxId,auxIndex,opcion;
    int i;
    Eusuario *auxUsuario = new_usuario();

    printf("----------Modificacion----------");

    listar_usuarios(pList);

    auxId = recibeStringANumeroRango("\nIngrese el Id del usuario cuyos datos desea modificar: ", "\nNo ha ingresado un valor numerico. Reingrese: ", 1, 50);
    for(i=0; i<pList->size; i++)
    {
        auxUsuario = al_get(pList,i);

        if(auxUsuario->id = auxId)
        {
            while(opcion != 4)
            {
                opcion = recibeIntRango("\n1 - Id\n2 - Nombre\n3 - Sueldo\n4 - Salir\n\nOpcion: ","\nNo ha ingresado un valor permitido. Reingrese\n\nOpcion: ",1,4);

                switch(opcion)
                {
                case 1:
                    auxUsuario->id = recibeStringANumeroRango("\nIngrese el Id del usuario (1 a 50): ", "\nNo ha ingresado un valor numerico. Reingrese", 1, 50);
                    break;

                case 2:
                    break;

                case 3:
                    break;

                case 4:
                    break;
                }
            }
        }
    }
}


