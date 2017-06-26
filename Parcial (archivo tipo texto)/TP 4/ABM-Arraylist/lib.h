#include "ArrayList.h"

typedef struct{
    char nombre[21];
    char apellido[51];
    int edad;
}Persona;

char menu();
Persona* newPersona();
int unaPersona(Persona* p);
void printPersona(ArrayList* this, Persona* p);
void baseListado();

//Archivos
int cargarTxt(ArrayList* this, Persona* p);
int crearTxt(ArrayList* this, Persona* p);
