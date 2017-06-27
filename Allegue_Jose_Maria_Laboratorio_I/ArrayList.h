/*
    utest example : Unit test examples.
    Copyright (C) <2016>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __ARRAYLIST
#define __ARRAYLIST
struct ArrayList{

    void** pElements;
    int size;
    int reservedSize;

    int     (*add)();
    int     (*len)();
    int     (*contains)();
    int     (*set)();
    int     (*remove)();
    int     (*clear)();
    int     (*push)();
    int     (*indexOf)();
    int     (*isEmpty)();
    void*   (*get)();
    void*   (*pop)();
    int     (*containsAll)();
    int     (*sort)();
    struct ArrayList* (* clone)();
    struct ArrayList* (*subList)();
    int     (*deleteArrayList)();

}typedef ArrayList;
#endif


ArrayList* al_newArrayList(void);
int al_add(ArrayList* this,void* pElement);
int al_deleteArrayList(ArrayList* pList);
int al_len(ArrayList* pList);
void* al_get(ArrayList* pList , int index);
int al_contains(ArrayList* pList, void* pElement);
int al_set(ArrayList* pList, int index,void* pElement);
int al_remove(ArrayList* pList,int index);
int al_clear(ArrayList* pList);
ArrayList* al_clone(ArrayList* pList);
int al_push(ArrayList* pList, int index, void* pElement);
int al_indexOf(ArrayList* pList, void* pElement);
int al_isEmpty(ArrayList* pList);
void* al_pop(ArrayList* pList,int index);
ArrayList* al_subList(ArrayList* pList,int from,int to);
int al_containsAll(ArrayList* pList,ArrayList* this2);
int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order);
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);

//int resizeUp(ArrayList* pList);
//int expand(ArrayList* pList,int index);
//int contract(ArrayList* pList,int index);

