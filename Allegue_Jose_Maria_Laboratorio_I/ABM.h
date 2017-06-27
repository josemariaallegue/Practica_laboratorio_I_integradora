#include "ArrayList.h"
typedef struct{
    char descripcion [150];
    int prioridad;
    float tiempo;
}Etarea;

Etarea *new_tarea();
void copiar(ArrayList *plist,Etarea *tarea);
void listar_tareas(ArrayList *pList);
void listar(Etarea *tarea);
ArrayList* particionar_prioridad_0(ArrayList *pList);
ArrayList* particionar_prioridad_1(ArrayList *pList);
void particionar(ArrayList *pList);
void ordenar(ArrayList *arrayPrioridad0, ArrayList *arrayPrioridad1);
int compare(Etarea* elemento1,Etarea* elemento2);
void resolver_prioridad1(ArrayList *arrayPrioridad1);
void resolver_prioridad0(ArrayList *arrayPrioridad0);
void guardar(ArrayList *arrayPrioridad0, ArrayList *arrayPrioridad1);


