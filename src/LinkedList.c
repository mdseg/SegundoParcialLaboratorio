#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

#define UP 1
#define DOWN 0

static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = NULL;
    this= (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }


    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	int i;
	Node* nodoParaDevolver = NULL;
	if(this != NULL && nodeIndex >=0 && (nodeIndex < ll_len(this)))
	{
		nodoParaDevolver = this->pFirstNode;
		for(i = 0; i<nodeIndex;i++)
		{
			nodoParaDevolver = nodoParaDevolver->pNextNode;
		}
	}

    return nodoParaDevolver;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{

    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNuevoNodo;
    Node* pPrevNodo;

    if (this != NULL && nodeIndex >= 0 && nodeIndex <= ll_len(this))
    {
        pNuevoNodo = (Node*)malloc(sizeof(Node));
        if(pNuevoNodo != NULL)
        {
        	pNuevoNodo->pElement = pElement;
			if(nodeIndex == 0)
			{
				pNuevoNodo->pNextNode = this->pFirstNode;
				this->pFirstNode = pNuevoNodo;

			}
			else
			{
				pPrevNodo = getNode(this, nodeIndex -1);
				pNuevoNodo->pNextNode = NULL;
				pPrevNodo->pNextNode = pNuevoNodo;
			}

			this->size++;
			returnAux = 0;
        }

    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
	int returnAux = -1;
	Node* pNuevoNodo;
	Node* pPrevNodo;
	int nodeIndex = ll_len(this);
	if ( this != NULL && nodeIndex >= 0)
	{
		pNuevoNodo = (Node*)malloc(sizeof(Node));
		if(pNuevoNodo != NULL)
		{
			pNuevoNodo->pElement = pElement;
			if(nodeIndex == 0)
			{
				pNuevoNodo->pNextNode = this->pFirstNode;
				this->pFirstNode = pNuevoNodo;

			}
			else
			{
				pPrevNodo = getNode(this, nodeIndex -1);
				if(pPrevNodo != NULL)
				{
					pPrevNodo->pNextNode = pNuevoNodo;
					pNuevoNodo->pNextNode = NULL;
				}
			}

			this->size++;
			returnAux = 0;
		}

	}


    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* nodo;
    if( this != NULL && index >= 0)
    {
    	nodo = getNode(this, index);
    	if (nodo != NULL)
    	{
    		returnAux = nodo->pElement;
    	}
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* nodo = NULL;
    int len = ll_len(this);
    if(this != NULL && index >= 0 && index < len)
    {
    	nodo = getNode(this,index);
    	if(nodo != NULL)
    	{
    		returnAux = 0;
    		nodo->pElement = pElement;
    	}

    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
	int returnAux = -1;
	Node* pNodoActual;
	Node* pPrevNodo;
	Node* bufferDirecc;

	if ( this != NULL && index >=0 && index < ll_len(this))
	{
		pNodoActual = getNode(this, index);
		if(pNodoActual != NULL)
		{

			if(index == 0)
			{
				if(pNodoActual->pNextNode != NULL)
				{
					bufferDirecc = pNodoActual->pNextNode;
					this->pFirstNode = bufferDirecc;
					free(pNodoActual);
				}
				else
				{
					this->pFirstNode = NULL;
					free(pNodoActual);
				}
				returnAux = 0;
				this->size--;
			}
			else
			{
				pPrevNodo = getNode(this, index-1);
				if(pPrevNodo != NULL)
				{
					bufferDirecc = pNodoActual->pNextNode;
					free(pNodoActual);
					pPrevNodo->pNextNode = bufferDirecc;
					this->size--;
					returnAux = 0;
				}
			}
			returnAux = 0;
		}
	}
	return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{

	    int returnAux = -1;
	    Node* nodoActual = NULL;
		int len = ll_len(this);
	    if(this != NULL && len > 0)
	    {
	    	for(int i=0; i < len; i++)
	    	{
				nodoActual = getNode(this, i);
				if(nodoActual != NULL)
				{
					free(nodoActual);
					this->size--;
				}
	    	}
	    	this->pFirstNode = NULL;
	    	returnAux = 0;
	    }
	    return returnAux;

}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {

        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    void* elementoActual;
    int len = ll_len(this);
    if (this != NULL && len > 0)
    {
    	for(int i=0; i < len; i++)
		{
    		elementoActual = ll_get(this, i);
    		if(elementoActual == pElement)
			{
				returnAux = i;
				break;
			}
		}
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len = ll_len(this);
    if(this != NULL)
    {
    	if (len > 0)
		{
			returnAux = 0;
		}
    	else
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL && index >= 0)
    {
    	if(addNode(this, index, pElement) == 0)
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len = ll_len(this);
    if (this != NULL && index >= 0 && index < len)
    {
    	returnAux = ll_get(this, index);
    	if (ll_remove(this, index) != 0)
    	{
    		returnAux = NULL;
    	}
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int indexElement = -1;
    if(this != NULL)
    {
    	indexElement = ll_indexOf(this, pElement);
    	if(indexElement >=0)
    	{
    		returnAux = 1;
    	}
    	else
    	{
    		returnAux = 0;
    	}
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len = ll_len(this2);
    if(this!= NULL && this2 != NULL)
    {
    	returnAux = 1;
    	for(int i = 0; i < len;i++)
    	{
    		if(!ll_contains(this, ll_get(this2, i)))
    		{
    			returnAux = 0;
    		}
    	}
    }


    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{

    LinkedList* cloneArray = NULL;
    int i;

    if(this != NULL && from >= 0 && (from < to) && (from<=ll_len(this)) && (to<=ll_len(this)))
    {
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL)
        {
        	for(i = from; i < to;i++)
			{
				ll_add(cloneArray, ll_get(this, i));
			}
        }

    }

    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int from;
    int to;
    if(this != NULL)
    {
    	from = 0;
    	to = ll_len(this);
    	cloneArray = ll_subList(this, from, to);
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
	int flagSwap;
	int i;
	int len = ll_len(this);
	int nuevoLimite;
	void* bufferElement;
	if(this != NULL && pFunc != NULL && len > 0 && (order == 1 || order == 0))
	{
		nuevoLimite = len - 1;
		do
		{
			flagSwap=0;
			for(i=0; i<nuevoLimite;i++)
			{
				if(order == UP && (pFunc(ll_get(this, i),ll_get(this, i+1)) > 0))
				{
					flagSwap=1;
					bufferElement = ll_get(this, i);
					ll_set(this, i, ll_get(this, i+1));
					ll_set(this, i+1, bufferElement);
				}
				else if(order == DOWN &&(pFunc(ll_get(this, i),ll_get(this, i+1)) < 0) )
				{
					flagSwap=1;
					bufferElement = ll_get(this, i);
					ll_set(this, i, ll_get(this, i+1));
					ll_set(this, i+1, bufferElement);
				}
			}
			nuevoLimite--;

		}
		while(flagSwap);
		returnAux = 0;
	}
    return returnAux;

}

/** \brief Recorre todos los elementos de la LinkedList para utilizar una función criterio en cada elemento de cada nodo
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_map(LinkedList* this, int (*pFunc)(void*))
{
	int output = -1;
	int len = ll_len(this);
	void* pElement;
	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			pElement = ll_get(this, i);
			pFunc(pElement);
		}
		output = 0;
	}
	return output;
}
/** \brief Recorre todos los elementos de la LinkedList para utilizar una función criterio en cada elemento de cada nodo
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
/*
int ll_mapPointerReturn(LinkedList* this, int (*pFunc)(void*,void*))
{
	int output = -1;
	int len = ll_len(this);
	void* pElement;
	int pPuntero = 0;
	if(this != NULL && pFunc != NULL)
	{
		for(int i = 0; i < len; i++)
		{
			pElement = ll_get(this, i);
			pFunc(pElement, output);
		}
		output = 0;
	}
	return output;
}
*/
int ll_map2(LinkedList* this, int(*pFunc)(void*, char*), void* value)
{
	int output = -1;
	int len = ll_len(this);
	void *pElement = NULL;
	if(this != NULL)
	{
		output = 0;
		for(int i = 0; i < len;i++)
		{
			pElement = ll_get(this, i);
			if(pFunc(pElement, value) == 1)
			{
				output = 1;
				break;
			}
		}

	}
	return output;
}
int ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	int output = -1;
	int len = ll_len(this);
	int nuevoLimite;
	int flagSwap;
	int i;
	if(this != NULL && pFunc != NULL && len > 0)
	{
		nuevoLimite = len - 1;
		do
		{
			flagSwap=0;
			for(i=0; i<nuevoLimite;i++)
			{
				if((pFunc(ll_get(this, i)) == 0))
				{
					ll_remove(this, i);
					flagSwap = 1;
					break;
				}
			}
			nuevoLimite--;
		}
		while(flagSwap);
		output = 0;

	}
	return output;
}
// Reduce una lista a un numero
// obtener salarios de empleados
int ll_reduceFloat(LinkedList* this, int (*pFunc)(void*, float* flotante), float* pResultado)
{
	int output = -1;
//	float numFloat = 0;
	float acumulador = 0;
	float result;
	int i;
	int len = ll_len(this);
	void* pElement;
	if (this != NULL && pFunc != NULL)
	{
		for (i = 0; i < len; i++)
		{
			pElement= ll_get(this, i);
			pFunc(pElement,&result);
			acumulador+= result;
			printf("Parcial %d: %.2f\n",i,acumulador);
		}
		*pResultado = acumulador;
		output = 0;
	}

	return output;
}
// obtener edades de empleados
/*
int ll_reduceInt(LinkedList* this, int (*pFunc)(void*), int* pResultado)
{
	int output = -1;
	int len = ll_len(this);
	int acc=0;
	void* pElement=NULL;
	if(this!=NULL && pFunc!=NULL && len>-1)
	{
		output = ll_mapPointerReturn(this, pFunc);
	}
	return output;
}
*/
// No es necesario hacerla para el jueves
int ll_findInt(LinkedList* this, int (*pFunc)(void*))
{
	int output = -1;
	return output;
}

