#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayList.h"
#include "lib.h"
#include "utn.h"

/** \brief Menu Principal del ABM.
 *
 * \param -
 * \param -
 * \return Caracter ingresado por teclado.
 *
 */
char menu()
{
    char c;
    printf("1. Nueva persona\n");
    printf("2. Dar de baja una persona\n");
    printf("3. Modificar persona\n");
    printf("4. Listar personas\n");
    printf("\n5. Salir\n\n");
    c=getch();
    return c;
}

/** \brief Espacio en memoria para una Persona.
 *
 * \param -
 * \param -
 * \return Puntero a Persona.
 *
 */
Persona* newPersona()
{
    Persona* this;
    this = (Persona*)malloc(sizeof(Persona));
    return this;
}


/** \brief Agrega una nueva persona a la estructura.
 *
 * \param Puntero a Persona.
 * \return [0]=> Si se agregó satisfactoriamente. // [-1]Si se pulsa "salir" (cancelar operacion)
 *
 */
int unaPersona(Persona* p)
{
    int retorno = 0;

    fflush(stdin);
    getValidString("Nombre: ", "Debe ser un nombre valido", p->nombre);
    if(strncmp(p->nombre,"salir",5)==0)
    {
        retorno = -1;
    }

    fflush(stdin);
    getValidString("Apellido: ", "Debe ser un nombre valido", p->apellido);

    p->edad = getValidInt("Edad: ", "Solo numerico", 0, 100);

    return retorno;
}

/** \brief Forma del listado orientativo.
 *
 * \param -
 * \param -
 * \return void.
 *
 */
void baseListado()
{
    printf("*************************************************\n");
    printf("************** L I S T A D O ********************\n");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("* ID ----- NOMBRE -------- APELLIDO ------ EDAD *\n\n");
}

/** \brief Muestra en pantalla el contenido de la estructura dentro de la lista.
 *
 * \param Lista donde se encuentra la estructura.
 * \param Estructura con datos a mostrar.
 * \return void.
 *
 */
void printPersona(ArrayList* this, Persona* p)
{
    printf("   %-8d%-15s%-18s%-d\n", al_indexOf(this, p),p->nombre,p->apellido, p->edad);

}

//ARCHIVOS

/** \brief Escribe en un archivo de texto los datos de la estructura Persona.
 *
 * \param Lista donde se encuentra la estructura.
 * \param Estructura con datos a mostrar.
 * \return [-1]=> Error / NULL. || [0]=> Si se escribio en el txt satisfactoriamente.
 *
 */

int crearTxt(ArrayList* this, Persona* p)
{
    int i, retorno=-1;
    FILE *f;
    f=fopen("Personas.txt", "w+");

    if(f == NULL)
    {
        printf("No se pudo abrir el archivo\n");
    }
    else
    {
        for(i=0; i<al_len(this); i++)
        {
            p = (Persona*)al_get(this,i);
            fflush(stdin);
            fprintf(f,"%s,%s,%d\n",p->nombre,p->apellido, p->edad);
        }
        retorno = 0;
    }

    fclose(f);
    return retorno;
}

/** \brief Lee el txt con el listado de personas y carga dicha estructura.
 *
 * \param Lista donde se encuentra la estructura.
 * \param Estructura con datos a mostrar.
 * \return [-1]=> Error / NULL. || [0]=> Si se leyó en el txt satisfactoriamente.
 *
 */
int cargarTxt(ArrayList* this, Persona* p)
{
    int retorno = 0;
    FILE* f;
    char nombreA[51];
    char apellidoA[51];
    char edadA[20];

    if((f = fopen("Personas.txt", "r"))==NULL)
        retorno =-1;

    while(!(feof(f)))
    {
        p=newPersona();
        if(p!=NULL)
        {
            fscanf(f,"%[^,],%[^,],%[^\n]\n", nombreA, apellidoA, edadA);
            strcpy(p->nombre, nombreA);
            strcpy(p->apellido, apellidoA);
            p->edad = atoi(edadA);
            al_add(this, p);
        }
    }

    return retorno;
}



