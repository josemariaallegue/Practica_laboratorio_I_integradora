#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/**
 * \brief pide un numero entero
 * \param mensaje es lo que se pide
 * \return devuelve el numero ingresado
 */

int recibeInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("\n%d",&auxiliar);
    return auxiliar;
}

/**
 * \brief pide un numero entero y valida que este entre 2 rangos
 * \param mensaje es lo que se pide
 * \param mensajeError es el mensaje que aparece si lo que se ingresa no esta entre los rangos
 * \return devuelve el numero ingresado
 *
 */

int recibeIntRango(char mensaje[], char mensajeError [], int limiteInf, int limiteSup)
{
    int auxiliar;
    printf("%s", mensaje);
    scanf("%d", &auxiliar);
    if(auxiliar < limiteInf || auxiliar > limiteSup)
    {
        printf("%s", mensajeError);
        scanf("%d", &auxiliar);
    }
    return auxiliar;
}


/**
 * \brief pide un flotante
 * \param mensaje es lo que se pide
 * \return devuelve el numero ingresado
 */

float recibeFloat(char mensaje[])
{
    float auxiliar;
    printf("%s", mensaje);
    scanf("%f", &auxiliar);
    return auxiliar;
}


/**
 * \brief pide un caracter
 * \param mensaje es lo que se pide
 * \return devuelve el caracter ingresado
 */

char recibeChar(char mensaje[])
{
    char auxiliar;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}

/**
 * \brief verifica que el valor ingresado sea numero
 * \param str es la cadena a ser analizada
 * \return 1 si es númerico y 0 si no
 */

int esNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
       i++;
   }
   return 1;
}


/**
 * \brief verifica que el valor ingresado sea un numero con decimales
 * \param str es la cadena a ser analizada
 * \return 1 si es númerico y 0 si no
 */

int esNumericoFlotante(char str[])
{
   int i = 0;
   int cantidadPuntos = 0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 */

int esSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 */

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief verifica si el valor recibido contiene solo números, " " y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion
 */

int esTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}


/**
 * \brief solicita un texto al usuario y lo devuelve
 * \param mensaje ss el mensaje a ser mostrado
 * \param input es el string donde se guarda lo ingresado
 * \return void
 */

void recibeString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf("%s", input);
}


/**
 * \brief solicita un texto al usuario y verifica que sean caracteres
 * \param mensaje ss el mensaje a ser mostrado
 * \param input es el string donde se guarda lo ingresado
 * \return 1 si el texto contiene solo letras 0 si no
 */

int recibeStringLetras(char mensaje[],char input[])
{
    char aux[256];
    recibeString(mensaje,aux);
    if(esSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief solicita un texto al usuario y verifica que sean caracteres y mientras no lo sea devuelve un mensaje de error y vuelve a pedir que reingrese
 * \param mensaje ss el mensaje a ser mostrado
 * \param mensajeError es el mensaje que se muestra si la cadena no contiene solo caracteres
 * \param input es el string donde se guarda lo ingresado
 * \return nada
 */

 void recibeStringLetrasValido(char mensaje[], char mensajeError[], char input [])
 {
     while(1)
    {
        if (!recibeStringLetras(mensaje,input))
        {
            printf ("%s\n",mensajeError);
            continue;
        }
        break;
    }
 }


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje es el mensaje a ser mostrado
 * \param input es el string donde se guarda lo ingresado
 * \return 1 si el texto contiene solo números y 0 si no
 */

int recibeStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    recibeString(mensaje,aux);
    if(esNumerico(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico (flotante) al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param Solicita un texto numérico al usuario y lo devuelve
 * \return 1 si el texto contiene solo números (flotantes) y 0 si no
 */
int recibeStringNumerosFlotantes(char mensaje[],char input[])
{

    char aux[256];
    recibeString(mensaje,aux);
    if(esNumericoFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario, convierte a entero y comprueba que este entre dos rangos
 * \param mensaje es el mensaje a ser mostrado
 * \param mensajeError es el mensaje mostrado si el texto no es solo numerico
 * \param limiteInf es lo minimo que puede valer lo ingresado
 * \param limiteSup es lo maximo que puede valer lo ingresado
 * \return retorna el valor ingresado
 */

int recibeStringANumeroRango(char mensaje[], char mensajeError[], int limiteInf, int limiteSup)
{

    char aux[256];
    int auxiliarInt;
    while(1)
    {   fflush(stdin);
        if(!recibeStringNumerosFlotantes(mensaje, aux))
        {
            printf("%s\n", mensajeError);
            continue;
        }
        auxiliarInt = atoi(aux);
        if(auxiliarInt < limiteInf || auxiliarInt > limiteSup)
        {
            printf("\nEl numero ingresado debe ser mayor o igual a %d o menor o igual a %d. Reingrese\n", limiteInf, limiteSup);
            continue;
        }
        break;
    }
    return auxiliarInt;
}


/**
 * \brief Solicita un texto numérico al usuario, convierte a flotante y comprueba que este entre dos rangos
 * \param mensaje es el mensaje a ser mostrado
 * \param mensajeError es el mensaje mostrado si el texto no es solo numerico
 * \param limiteInf es lo minimo que puede valer lo ingresado
 * \param limiteSup es lo maximo que puede valer lo ingresado
 * \return retorna el valor ingresado
 */

float recibeStringANumeroRangoFloat(char mensaje[], char mensajeError[], float limiteInf, float limiteSup)
{

    char aux[256];
    float auxiliarFloat;
    while(1)
    {   fflush(stdin);
        if(!recibeStringNumerosFlotantes(mensaje, aux))
        {
            printf("%s\n", mensajeError);
            continue;
        }
        auxiliarFloat = atof(aux);
        if(auxiliarFloat < limiteInf || auxiliarFloat > limiteSup)
        {
            printf("\nEl numero ingresado debe ser mayor o igual a %.02f o menor o igual a %.02f. Reingrese\n", limiteInf, limiteSup);
            continue;
        }
        break;
    }
    return auxiliarFloat;
}

