#include "ArrayList.h"
typedef struct{
    int id;
    char nombre[51];
    float sueldo;
}Eusuario;

Eusuario* alta_usuario();
int baja_usuario(ArrayList *pList);
void listar_usuarios(ArrayList *pList);
void listar(Eusuario *usuario);
void copiar(ArrayList *plist);
void guardar(ArrayList *pList);
Eusuario * new_usuario();
int menu(int limiteInf, int limiteSup);
void modificar_usuario(ArrayList *pList);


