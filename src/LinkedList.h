/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

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

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;
    struct Node* pNextNode;
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void); //Crea la linkedlist
int ll_len(LinkedList* this); // Devuelve la cantidad de elementos de la Linkedlist
Node* test_getNode(LinkedList* this, int nodeIndex);
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);
int ll_add(LinkedList* this, void* pElement); // Incorpora un nuevo elemento a la lista pElement en este caso es un puntero a Empleado
void* ll_get(LinkedList* this, int index);
int ll_set(LinkedList* this, int index,void* pElement); // Agrega un elemento en una posicion de la lista siempre y cuando esa posicion exista
int ll_remove(LinkedList* this,int index); // Elimina un elemento
int ll_clear(LinkedList* this); // Borra todos los elementos de la lista
int ll_deleteLinkedList(LinkedList* this); // Borra de memoria la lista
int ll_indexOf(LinkedList* this, void* pElement); // Le paso un elemento que creo que está en alguna posición de la lista y me devuelve en que posición se encuentra
int ll_isEmpty(LinkedList* this); // Me avisa si la lista está vacia
int ll_push(LinkedList* this, int index, void* pElement); // Permite elegir un lugar para elegir un elemento, por ejemplo si quiero poner entre el 1 y el 2 un elmento. Al 2 lo corre a la posición 3 y pone el nuevo elmeento en la posicion 2
void* ll_pop(LinkedList* this,int index); // Permite sacar un elemento de la lista, pero en el mismo momento en que lo saco me devuelve el puntero
int ll_contains(LinkedList* this, void* pElement); // Devuelve TRUE si el elemento por el que pregunto está contenido en la lista
int ll_containsAll(LinkedList* this,LinkedList* this2); // Lo mismo pero con una lista de elementos
LinkedList* ll_subList(LinkedList* this,int from,int to); // Crea una sublista de una lista original por ej entre el elemento 5 y el 80
LinkedList* ll_clone(LinkedList* this); // Duplica la lista en memoria generando una lista nueva
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order); // permite ordenar la lista
int ll_reduceFloat(LinkedList* this, int (*pFunc)(void*, float* flotante), float* pResultado);
int ll_reduceInt(LinkedList* this, int (*pFunc)(void*), int* pResultado);
int ll_filter(LinkedList* this, int (*pFunc)(void*));
int ll_filterAdd(LinkedList* originalList,LinkedList* newList, int (*pFunc)(void*));
int ll_map(LinkedList* this, int (*pFunc)(void*));
int ll_mapPointerReturn(LinkedList* this, int (*pFunc)(void*,void* pPunteroInt));
int ll_map2(LinkedList* this, int(*pFunc)(void*, char*), void* value);
