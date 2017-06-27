#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#define T 15
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList = (ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void*) *T );
        if(pElements != NULL)
        {
            pList->size = 0;
            pList->pElements = pElements;
            pList->reservedSize = T;
            pList->add = al_add;
            pList->len = al_len;
            pList->set = al_set;
            pList->remove = al_remove;
            pList->clear = al_clear;
            pList->clone = al_clone;
            pList->get = al_get;
            pList->contains = al_contains;
            pList->push = al_push;
            pList->indexOf = al_indexOf;
            pList->isEmpty = al_isEmpty;
            pList->pop = al_pop;
            pList->subList = al_subList;
            pList->containsAll = al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList, void* pElement)
{
    int auxReturn;

    if(pList == NULL || pElement == NULL)
    {
        auxReturn = -1;
    }

    else
    {
        if(pList->size == pList->reservedSize)
        {
            resizeUp(pList);
        }

        pList->pElements[pList->size] = pElement;
        pList->size ++;
        auxReturn = 0;
    }

    return auxReturn;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList)
{
    int auxReturn;

    if(pList == NULL)
    {
        //printf("\nError en deleteArrayList");
        auxReturn = -1;
    }
    else
    {
        free(pList->pElements);
        free(pList);
        auxReturn = 0;
    }

    return auxReturn;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pList)
{
    int auxReturn;

    if(pList == NULL)
    {
        //printf("\nError en len");
        auxReturn = -1;
    }

    else
    {
        auxReturn = pList->size;
    }

    return auxReturn;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList, int index)
{
    void* auxReturn = NULL;

    if(pList == NULL || index < 0 || index > pList->size)
    {
        //printf("\nError en get");
        auxReturn = NULL;
    }
    else
    {
        auxReturn = pList->pElements[index];
    }

    return auxReturn;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement)
{
    int auxReturn;
    int i;

    if(pList == NULL || pElement == NULL)
    {
        auxReturn = -1;
    }

    else
    {
        for(i=0;i<pList->size;i++)
        {
            if(pList->pElements[i] == pElement)
            {
                auxReturn = 1;
                break;
            }
            else
            {
                auxReturn = 0;
            }
        }
    }

    return auxReturn;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement)
{
    int auxReturn;

    if(pList == NULL || pElement == NULL || index < 0 || index > pList->size)
    {
        //printf("\nError en set");
        auxReturn = -1;
    }
    else
    {
        if(index == pList->size)
        {
            al_add(pList,pElement);
            auxReturn = 0;
        }
        else if(index < pList->size)
        {
            pList->pElements[index] = pElement;
            auxReturn = 0;
        }
    }


    return auxReturn;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */

int al_remove(ArrayList* pList,int index)
{
    int auxReturn;

    if(pList == NULL || index < 0 || index > pList->size)
    {

        auxReturn = -1;
    }
    else
    {
        contract(pList,index);
        auxReturn = 0;
    }
    return auxReturn;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList)
{
    int auxReturn;
    int i;

    if(pList == NULL)
    {
        auxReturn = -1;
    }
    else
    {
        for(i=0;i<pList->size;i++)
        {
            al_remove(pList,i);
        }
        pList->size = 0;
        auxReturn = 0;
    }

    return auxReturn;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pList)
{
    ArrayList *auxReturn;

    if(pList == NULL)
    {
        //printf("\nError en clone");
        auxReturn = NULL;
    }
    else
    {

        auxReturn = al_subList(pList,0,pList->size);
    }

    return auxReturn;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement)
{
    int auxReturn;

    if(pList == NULL || pElement == NULL || index < 0 || index > pList->size)
    {
        //printf("\nError en push");
        auxReturn = -1;
    }
    else
    {
        expand(pList,index);
        al_set(pList,index,pElement);
        auxReturn = 0;
    }

    return auxReturn;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement)
{
    int auxReturn;
    int i;

    if(pList == NULL || pElement == NULL)
    {
        //printf("\nError en indexOf");
        auxReturn = -1;
    }
    else
    {
        for(i=0;i<pList->size;i++)
        {
            if(pList->pElements[i] == pElement)
            {
                auxReturn = i;
                break;
            }
            else
            {
                auxReturn = -1;
            }
        }
    }

    return auxReturn;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList)
{
   int auxReturn;

   if(pList == NULL)
   {
       //printf("\nError en isEmpty");
       auxReturn = -1;
   }
   else
   {
       if(pList->size == 0)
       {
           auxReturn = 1;
       }
       else
       {
           auxReturn = 0;
       }
   }

   return auxReturn;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index)
{
    ArrayList *auxReturn;

    if(pList == NULL || index < 0 || index > pList->size)
    {
        auxReturn = NULL;
    }
    else
    {
        auxReturn = al_get(pList,index);
        al_remove(pList,index);
    }

    return auxReturn;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pList,int from,int to)
{
    int i;
    ArrayList* auxReturn;

    if(pList == NULL || from < 0 || to > pList->size || from > to)
    {
        auxReturn = NULL;
    }
    else
    {
        auxReturn = al_newArrayList();

        for(i=from;i<to;i++)
        {
            auxReturn->add(auxReturn,pList->get(pList,i));
        }
    }

    return auxReturn;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2)
{
    int auxReturn;
    int i;

    if(pList == NULL || pList2 == NULL || pList2->size == 0)
    {
        auxReturn = -1;
    }
    else
    {
        for(i=0;i<pList->size;i++)
        {
            if(al_contains(pList,pList2->pElements[i]) == 0)
            {
                auxReturn = 0;
                break;
            }
            else
            {
                auxReturn = 1;
            }
        }

    }

    return auxReturn;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order)
{
    int auxReturn;
    void *aux;
    int i,j;

    if(pList == NULL || pFunc == NULL || order > 1 || order < 0)
    {
        auxReturn = -1;
    }
    else
    {
        for(i=0;i<pList->size-1;i++)
        {
            for(j=i+1;j<pList->size;j++)
            {
                switch(order)
                {
                    case 0:
                    if(pFunc(pList->pElements[i],pList->pElements[j]) == -1 && aux != NULL)
                       {
                           aux = pList->pElements[i];
                           pList->pElements[i] = pList->pElements[j];
                           pList->pElements[j] = aux;
                       }
                    break;

                    case 1:
                    if(pFunc(pList->pElements[i],pList->pElements[j]) == 1 && aux != NULL)
                       {
                           aux = pList->pElements[i];
                           pList->pElements[i] = pList->pElements[j];
                           pList->pElements[j] = aux;
                       }
                    break;

                }
            }
        }

        auxReturn = 0;
    }

    return auxReturn;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList)
{
    int auxReturn;
    void **auxPElements;

    if(pList != NULL)
    {
        //printf("\nError en resizeUp");
        auxReturn = -1;
    }

    else
    {
        auxPElements = (void**)realloc(pList->pElements, sizeof(void*) *(pList->reservedSize + T));

        if(auxPElements == NULL)
        {
            printf("\nError en resizeUp");
            auxReturn = -1;
        }

        else
        {
            pList->pElements = auxPElements;
            pList->reservedSize += T;
            auxReturn = 0;
        }
    }

    return auxReturn;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index)
{
    int auxReturn;
    int i;

    if(pList == NULL || index < 0 || index > pList->size)
    {
        //printf("\nError en contract");
        auxReturn = -1;
    }
    else
    {
        if(pList->size > 0)
        {
            for(i=pList->size-1;i>index;i--)
            {
                pList->set(pList,i,pList->get(pList,i - 1));
            }

            pList->size ++;
            auxReturn = 0;
        }
    }
    return auxReturn;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */

int contract(ArrayList* pList,int index)
{
    int auxReturn;
    int i;

    if(pList == NULL || index < 0 || index > pList->size)
    {
        auxReturn = -1;
    }
    else
    {
        if(pList->size > 0)
        {
            for(i=index;i<pList->size;i++)
            {
                pList->set(pList,i,pList->get(pList,i + 1));
            }
            pList->size --;
            auxReturn = 0;
        }
    }
    return auxReturn;
}
