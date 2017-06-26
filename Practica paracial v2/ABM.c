#include <stdio.h>
#include <stdlib.h>
#include "ABM.h"
#include "funciones.h"
#include  "ArrayList.h"

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

void listar(Eusuario *plist)
{
    printf("\nId: %d - Nombre: %s - Sueldo: %.02f",plist->id, plist->nombre,plist->sueldo);
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

    return auxReturn;
}


void copiar(ArrayList *plist)
{
    FILE *ARCH;
    //ArrayList *pList2 = al_newArrayList();
    Eusuario *pusuario ;
    //Eusuario usuario;
    int flag = 0;
    int cant;

    ARCH = fopen("archivo.dat","rb");
    if(ARCH == NULL)
    {
        printf("\nhola mundo 0");
        ARCH = fopen("archivo.dat","wb");
        flag = 1;
    }
    if(flag == 0)
    {
        while(!feof(ARCH))
        {
            pusuario = new_usuario();
            fflush(stdin);
            cant =fread(pusuario,sizeof(Eusuario),1,ARCH);
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
            //break;

            fflush(stdin);

            al_add(plist,pusuario);
        }
    }

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
            //fprintf(ARCH,"%s",usuario->nombre);
        }
    }

    fclose(ARCH);

}

Eusuario * new_usuario()
{
    Eusuario *this;
    this = (Eusuario*)malloc(sizeof(Eusuario));

    return this;
}


