#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include "Client.h"
#include "Sale.h"

#define LONG_ID 55
#define LONG_NAME 55
#define LONG_CUIT 55
#define READ_ERROR "Error al leer el archivo"
#define TRUE 1
#define FALSE 0
#define ATTEMPTS 5



/** \brief Carga los datos de los clientes desde el archivo clientes.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListClients LinkedList*
 * \return int
 *
 */
int controller_loadClientsFromText(char* path , LinkedList* pArrayListClients)
{
	int output = -1;
	FILE* pFile;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(CONTROLLER_LOAD_LIST_TEXT);
	ll_clear(pArrayListClients);
	if(pArrayListClients != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile == NULL)
		{
			printf(CONTROLLER_LOAD_LIST_NO_FILE);
		}
		else if(parser_ClientFromText(pFile, pArrayListClients) == 0)
		{
			printf(CONTROLLER_LOAD_LIST_TEXT_SUCCESS);
			output = 0;
		}
		fclose(pFile);
	}
	else
	{
		printf(LL_NULL_ERROR);
	}
	printf(PRINT_ONE_REGISTRY_BOTTOM);
    return output;
}

/** \brief Carga los datos de las ventas desde el archivo ventas.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListSales LinkedList*
 * \return int
 *
 */
int controller_loadPostersFromText(char* path , LinkedList* pArrayListSales)
{
	int output = -1;
	FILE* pFile;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(CONTROLLER_LOAD_POSTERS_LIST_TEXT);
	ll_clear(pArrayListSales);
	if(pArrayListSales != NULL)
	{
		pFile = fopen(path,"r");
		if(pFile == NULL)
		{
			printf(CONTROLLER_LOAD_LIST_NO_FILE);
		}
		else if(parser_SalesFromText(pFile, pArrayListSales) == 0)
		{
			printf(CONTROLLER_LOAD_LIST_TEXT_SUCCESS);
			output = 0;
		}
		fclose(pFile);
	}
	else
	{
		printf(LL_NULL_ERROR);
	}
	printf(PRINT_ONE_REGISTRY_BOTTOM);
    return output;
}


/** \brief Alta de clientes
 *
 * \param pArrayListClients LinkedList*
 * \param path char*
 * \return int
 *
 */

int controller_addClient(LinkedList* pArrayListClients, char* path)
{
	int output = -1;
	int idClient;
	char idClientString[LONG_ID];
	char name[LONG_NAME];
	char lastName[LONG_NAME];
	char cuit[LONG_CUIT];
	Client* bufferClient;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(ENTERING_CREATE_CLIENT);

	if(utn_getString(INPUT_NAME, ERROR_IDCLIENTE, name, ATTEMPTS, LONG_NAME) == 0 &&
		utn_getString(INPUT_LASTNAME, ERROR_LASTNAME, lastName, ATTEMPTS, LONG_NAME) == 0 &&
		utn_getCuit(INPUT_CUIT, ERROR_CUIT, cuit,ATTEMPTS, LONG_CUIT) == 0)
	{
		idClient = controller_getNewIdCliente(pArrayListClients);
		if(isValidIdClient(idClient) == 1 )
		{
			if(controller_isRepeatCuit(pArrayListClients, cuit) == 0)
			{
				sprintf(idClientString,"%d",idClient);
				bufferClient = client_newString(idClientString,name,lastName,cuit);
				ll_add(pArrayListClients, bufferClient);
				printf(CREATE_CLIENT_SUCCESS);
				client_printOneClientBanners(bufferClient);
				controller_saveClienteAsText(path, pArrayListClients);
				output = 0;
			}
			else
			{
				printf(CONTROLLER_ISREPEATCUIT_ERROR);
			}
		}
	}
    return output;
}
/** \brief Alta de Ventas
 *
 * \param pArrayListSales LinkedList*
 * \param pArrayListClients LinkedList*
 * \param path char* archivo que será modificada
 * \return 0 si ok // -1 si error
 *
 */
int controller_addSale(LinkedList* pArrayListSales,LinkedList* pArrayListClients, char* path)
{
	int output = -1;
	int idSale;
	int idClient;
	char idClientString[LONG_ID];
	int idPostersSold;
	char idPostersSoldString[LONG_ID];
	char fileName[LONG_NAME];
	int zone;
	char zoneString[LONG_ID];
	Sale* bufferSale;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(ENTERING_CREATE_CLIENT);
	controller_printClients(pArrayListClients);
	if(pArrayListSales != NULL && pArrayListClients != NULL)
	{
		if(utn_getInt(&idClient, INPUT_ID, ERROR_IDCLIENTE, IDCLIENTE_MIN, IDCLIENTE_MAX, ATTEMPTS) == 0  &&
				utn_getInt(&idPostersSold, INPUT_POSTERSSOLD, ERROR_POSTERSSOLD, POSTERSSOLD_MIN, POSTERSSOLD_MAX, ATTEMPTS) == 0 &&
				utn_getInt(&zone, INPUT_ZONE, ERROR_ZONE, ZONE_MIN, ZONE_MAX, ATTEMPTS) == 0 &&
				utn_getFileName(INPUT_FILENAME, ERROR_FILENAME, fileName, ATTEMPTS, LONG_NAME) == 0
				)
		{
			idSale = controller_getNewIdSale(pArrayListSales);
			if(isValidIdSale(idSale) == 1 && controller_findClientById(pArrayListClients, idClient) > 0)
			{
					sprintf(idClientString,"%d",idClient);
					sprintf(idPostersSoldString,"%d", idPostersSold);
					sprintf(zoneString,"%d", zone);
					bufferSale = sale_newParam(idSale, idClientString, idPostersSoldString, fileName, zoneString);
					if(bufferSale != NULL)
					{
						ll_add(pArrayListSales, bufferSale);
						printf(CREATE_SALE_SUCCESS);
						controller_saveSalesAsText(path, pArrayListSales);
					}
					output = 0;
			}
			else
			{
				printf(CONTROLLER_CLIENTNOEXIST_ERROR);
			}

		}
	}
    return output;
}

/** \brief muestra un menu para modificar Cliente nombre, apellido or CUIT
* \param pArrayListClient LinkedList*
* \param path char*
* \return int Return (-1) if Error - (0) if Ok
*/
int controller_editClient(LinkedList* pArrayListClient, char* path)
{
	int output = -1;
	char name[LONG_NAME];
	char lastName[LONG_NAME];
	char cuit[LONG_CUIT];
	int id;
	int index;
	int op;
	int flagCarga = FALSE;
	Client* bufferClient;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(ENTERING_MODIFY_CLIENT);
	if(pArrayListClient != NULL)
	{
		if(utn_getInt(&id, INPUT_ID, ERROR_IDCLIENTE, IDCLIENTE_MIN, IDCLIENTE_MAX, ATTEMPTS) == 0)
		{
			index = controller_findClientById(pArrayListClient, id);

			if(index != -1)
			{
				bufferClient = ll_get(pArrayListClient, index);
				client_printOneClientBanners(bufferClient);
				do
				{
					utn_getInt(&op, MENU_MODIFY, MENU_SELECT_ERROR, 1, 4, ATTEMPTS);
					switch (op)
					{
						case 1:
							if(utn_getName(INPUT_NAME,ERROR_NAME,name, ATTEMPTS, LONG_NAME) == 0)
							{
								client_setName(bufferClient, name);
								flagCarga = TRUE;
								printf(MODIFY_NAME_SUCCESS);
							}
							else
							{
								printf(MODIFY_NAME_ERROR);
							}
							break;
						case 2:
							if(utn_getName(INPUT_LASTNAME,ERROR_LASTNAME,lastName, ATTEMPTS, LONG_NAME) == 0)
							{
								client_setLastName(bufferClient, lastName);
								flagCarga = TRUE;
								printf(MODIFY_LASTNAME_SUCCESS);
							}
							else
							{
								printf(MODIFY_LASTNAME_ERROR);
							}
							break;
						case 3:
							if(utn_getCuit(INPUT_CUIT, ERROR_CUIT, cuit,ATTEMPTS, LONG_CUIT) == 0)
							{
								client_setCUIT(bufferClient, cuit);
								flagCarga = TRUE;
								printf(MODIFY_CUIT_SUCCESS);
							}
							else
							{
								printf(MODIFY_CUIT_ERROR);
							}
							break;
					}
					client_printOneClientBanners(bufferClient);
				}
				while(op != 4);
				if(flagCarga == TRUE)
				{
					ll_set(pArrayListClient, index, bufferClient);
					controller_saveClienteAsText(path, pArrayListClient);
					printf(MODIFY_CLIENT_SUCCESS);
					output = 0;
				}
			}
		}
	}
	else
	{
		printf(LL_NULL_ERROR);
	}
	printf(PRINT_ONE_REGISTRY_BOTTOM);
    return output;
}

/** \brief muestra un menu para modificar los campos de la venta siempre y cuando esté como a cobrar
* \param pArrayListSales LinkedList*
* \param pArrayListClients LinkedList*
* \param path char*
* \return int Return (-1) if Error - (0) if Ok
*/
int controller_editSale(LinkedList* pArrayListSales,LinkedList* pArrayListClients, char* path)
{
	int output = -1;
	int idSale;
	int idClient;
	int postersSold;
	char fileName[LONG_NAME];
	int zone;
	int index;
	int indexClient;
	int op;
	int flagCarga = FALSE;
	LinkedList* newList = ll_newLinkedList();
	Sale* bufferSale;
	Client* bufferClient;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(ENTERING_MODIFY_SALE);
	if(pArrayListClients != NULL && pArrayListSales != NULL && newList != NULL)
	{
		ll_filterAdd(pArrayListSales, newList, sale_isToPay);
		controller_printSales(newList);
		if(utn_getInt(&idSale, INPUT_IDSALE, ERROR_IDSALE, IDSALE_MIN, IDSALE_MAX, ATTEMPTS) == 0)
		{
			index = controller_findSalesById(pArrayListSales, idSale);

			if(index != -1)
			{
				bufferSale = ll_get(pArrayListSales, index);
				idClient = sale_getIdClient(bufferSale);
				indexClient = controller_findClientById(pArrayListClients, idClient);
				bufferClient = ll_get(pArrayListClients,indexClient);
				printf("Cliente al que pertenece el aviso:\n");
				client_printOneClientBanners(bufferClient);
				printf("Detalles del aviso:\n");
				sale_printOneSaleBanners(bufferSale);
				do
				{
					utn_getInt(&op, MENU_MODIFY_SALE, MENU_SELECT_ERROR, 1, 5, ATTEMPTS);
					switch (op)
					{
						case 1:
							if(utn_getInt(&idClient, INPUT_ID, ERROR_IDCLIENTE, IDCLIENTE_MIN, IDCLIENTE_MAX, ATTEMPTS) == 0 &&
									controller_findClientById(pArrayListClients, idClient) > -1	)
							{
								sale_setIdClient(bufferSale, idClient);
								flagCarga = TRUE;
								printf(MODIFY_NAME_SUCCESS);
							}
							else
							{
								printf(MODIFY_CLIENT_NO_EXIST);
							}
							break;
						case 2:
							if(utn_getInt(&postersSold, INPUT_POSTERSSOLD, ERROR_POSTERSSOLD, POSTERSSOLD_MIN, POSTERSSOLD_MAX, ATTEMPTS) == 0)
							{
								sale_setPostersSold(bufferSale, postersSold);
								flagCarga = TRUE;
								printf(MODIFY_POSTERSSOLD_SUCCESS);
							}
							else
							{
								printf(MODIFY_POSTERSSOLD_ERROR);
							}
							break;
						case 3:
							if(utn_getFileName(INPUT_FILENAME, ERROR_FILENAME, fileName, ATTEMPTS, LONG_NAME) == 0)
							{
								sale_setFileName(bufferSale, fileName);
								flagCarga = TRUE;
								printf(MODIFY_FILENAME_SUCCESS);
							}
							else
							{
								printf(MODIFY_FILENAME_ERROR);
							}
							break;
						case 4:
							if(utn_getInt(&zone, INPUT_ZONE, ERROR_ZONE, ZONE_MIN, ZONE_MAX, ATTEMPTS) == 0)
							{
								sale_setZone(bufferSale, zone);
								flagCarga = TRUE;
								printf(MODIFY_ZONE_SUCCESS);
							}
							else
							{
								printf(MODIFY_ZONE_ERROR);
							}
							break;
					}
					sale_printOneSaleBanners(bufferSale);
				}
				while(op != 5);
				if(flagCarga == TRUE)
				{
					ll_set(pArrayListSales, index, bufferSale);
					controller_saveSalesAsText(path, pArrayListSales);
					printf(MODIFY_SALE_SUCCESS);
					output = 0;
				}
			}
		}
	}
	else
	{
		printf(LL_NULL_ERROR);
	}
	printf(PRINT_ONE_REGISTRY_BOTTOM);
    return output;
}


/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_removeClient(LinkedList* pArrayListClients, char* path)
{
	int output = -1;
	int id;
	int index;
	int op;
	Client* bufferClient;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf(ENTERING_REMOVE_CLIENT);
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	if(ll_len(pArrayListClients) > 0 && utn_getInt(&id, INPUT_ID, ERROR_IDCLIENTE, IDCLIENTE_MIN, IDCLIENTE_MAX, ATTEMPTS) == 0)
	{
		index = controller_findClientById(pArrayListClients, id);
		bufferClient = ll_get(pArrayListClients, index);
		if (index != -1 && bufferClient != NULL)
		{
			if(client_printOneClientBanners(bufferClient) == 0 &&
				utn_getInt(&op, DELETE_CLIENT_CONFIRM, MENU_SELECT_ERROR, 1, 2, ATTEMPTS) == 0)
			{
				if(op == 1)
				{
					ll_remove(pArrayListClients, index);
					client_delete(bufferClient);
					controller_saveClienteAsText(path, pArrayListClients);
					printf(DELETE_CLIENT_SUCCESS);
				}
				else
				{
					printf(DELETE_CLIENT_CANCEL);
				}
				output = 0;
			}
		}
		else
		{
			printf(DELETE_CLIENT_ERROR);
		}
	}
	else
	{
		printf(ERROR_GENERIC);
	}
	return output;
}
/** \brief toma una lista de empleados y evalua que no haya CUIT repetidos
 *
 * \param pArrayListClients LinkedList*
 * \param cuit char*
 * \return ll_map2(pArrayListClients, client_isRepeatCuit, cuit) si ok // -1 si error
 *
 */
int controller_isRepeatCuit(LinkedList* pArrayListClients,char* cuit)
{
	int output = -1;
	output = ll_map2(pArrayListClients, client_isRepeatCuit, cuit);
	return output;
}
/** \brief imprime todos los clientes con un encabezado añadido
 *
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */
int controller_printClients(LinkedList* pArrayListClients)
{
	int output = -1;
	int len = ll_len(pArrayListClients);
	if(pArrayListClients != NULL && len > 0)
	{
		printf(PRINT_ONE_REGISTRY_TOP);
		ll_map(pArrayListClients, client_printOneClient);
		printf(PRINT_ONE_REGISTRY_BOTTOM);

		output = 0;
	}
    return output;
}
/** \brief imprime todas las ventas con un encabezado añadido
 *
 * \param pArrayListSales LinkedList*
 * \return int
 *
 */
int controller_printSales(LinkedList* pArrayListSales)
{
	int output = -1;
	int len = ll_len(pArrayListSales);
	printf(ENTERING_LIST_SALE);
	if(pArrayListSales != NULL && len > 0)
	{
		printf(PRINT_ONE_SALE_TOP);
		ll_map(pArrayListSales, sale_printOneSale);
		printf(PRINT_ONE_SALE_BOTTOM);

		output = 0;
	}
    return output;
}

/** \brief muestra un menu para que el usuario seleccione por que campo y en que orden desea ordenar la lista de empleados
 *
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */

int controller_sortClientsAndSales(LinkedList* pArrayListClients,LinkedList* pArrayListSales)
{
	int output = -1;
	int op;
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	printf("Entrando en el menu de reportes.\n");
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	if(pArrayListClients != NULL)
	{
		do
		{
			utn_getInt(&op, CONTROLLER_SORT_MENU, MENU_SELECT_ERROR, 1, 9, ATTEMPTS);
			switch(op)
			{
				case 1:
					ll_sort(pArrayListClients,client_compareById,UP);
					output = 0;
					break;

				case 2:
					ll_sort(pArrayListClients,client_compareById,DOWN);
					output = 0;
					break;
				case 3:
					ll_sort(pArrayListClients,client_compareByName,UP);
					output = 0;
					break;
				case 4:
					ll_sort(pArrayListClients,client_compareByName,DOWN);
					output = 0;
					break;
				case 5:
					ll_sort(pArrayListClients,client_compareByLastName,UP);
					output = 0;
					break;
				case 6:
					ll_sort(pArrayListClients,client_compareByLastName,DOWN);
					output = 0;
					break;
				case 7:
					ll_sort(pArrayListClients,client_compareByCUIT,UP);
					output = 0;
					break;
				case 8:
					ll_sort(pArrayListClients,client_compareByCUIT,DOWN);
					output = 0;
					break;

			}
		}
		while(op != 9);
	}
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	return output;

}

/**
 * \brief Guarda los datos de los clientes en el archivo clientes.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListClient LinkedList*
 * \return int
 *
 */

int controller_saveClienteAsText(char* path , LinkedList* pArrayListClients)
{
	int output = -1;
	int len;
	int i = 0;
	Client* bufferClient;
	FILE* pFile;
	pFile = fopen(path,"w");
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	if(path != NULL && pArrayListClients != NULL)
	{
		if(pFile != NULL)
		{

			len = ll_len(pArrayListClients);
			fprintf(pFile,CONTROLLER_TXT_CLIENT_TOP);
			for (i = 0; i < len;i++)
			{
				bufferClient = ll_get(pArrayListClients, i);
				fprintf(pFile,"%d,%s,%s,%s\n",client_getIdClient(bufferClient),client_getName(bufferClient),client_getLastName(bufferClient),client_getCUIT(bufferClient));
			}
			fclose(pFile);
			printf(CONTROLLER_CREATE_SUCCESS);
			output = 0;
		}
		else
		{
			printf(CONTROLLER_SAVE_BINARY_PATH_ERROR);
		}
	}
	printf(PRINT_ONE_REGISTRY_BOTTOM);
    return output;
}
/** \brief Guarda los datos de las ventas en el archivo ventas.txt (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int controller_saveSalesAsText(char* path , LinkedList* pArrayListSale)
{
	int output = -1;
	int len;
	int i = 0;
	Sale* bufferSale;
	FILE* pFile;
	pFile = fopen(path,"w");
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	if(path != NULL && pArrayListSale != NULL)
	{
		if(pFile != NULL)
		{

			len = ll_len(pArrayListSale);
			fprintf(pFile,CONTROLLER_TXT_SALE_TOP);
			for (i = 0; i < len;i++)
			{
				bufferSale = ll_get(pArrayListSale, i);
				fprintf(pFile,"%d,%d,%d,%s,%d,%d\n",sale_getIdSale(bufferSale),sale_getIdClient(bufferSale),sale_getPostersSold(bufferSale),sale_getFileName(bufferSale),sale_getZone(bufferSale),sale_getStatus(bufferSale));
			}
			fclose(pFile);
			printf(CONTROLLER_CREATE_SUCCESS);
			output = 0;
		}
		else
		{
			printf(CONTROLLER_SAVE_BINARY_PATH_ERROR);
		}
	}
	printf(PRINT_ONE_REGISTRY_BOTTOM);
    return output;
}


/** \brief Busca un nuevo Id disponible en una lista enlazada de clientes y lo devuelve por valor.
 *
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int controller_getNewIdCliente(LinkedList* pArrayListClient)
{
	int output = -1;
	int len;
	Client* bufferClient;
	if(pArrayListClient != NULL)
	{
		len = ll_len(pArrayListClient);
		bufferClient = ll_get(pArrayListClient, (len-1));
		output = client_getIdClient(bufferClient) + 1;
	}

	return output;
}
/** \brief Busca un nuevo Id disponible en una lista enlazada de ventas y lo devuelve por valor.
 *
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */

int controller_getNewIdSale(LinkedList* pArrayListSale)
{
	int output = -1;
	int len;
	Sale* bufferSale;
	if(pArrayListSale != NULL)
	{
		len = ll_len(pArrayListSale);
		bufferSale = ll_get(pArrayListSale, (len-1));
		output = sale_getIdSale(bufferSale) + 1;
	}

	return output;
}
/** \brief Busca un nuevo dato del tipo Client* en una lista enlazada tomando como parametro el id retornando el valor por referencias.
 *
 * \param pArrayListClients LinkedList*
 * \param int id
 * \return int
 *
 */
int controller_findClientById(LinkedList* pArrayListClients, int id)
{
	int output = -1;
	int len;
	int i;
	Client* bufferClient;
	if (pArrayListClients != NULL && isValidIdClient(id) == 1)
	{
		output = 0;
		len = ll_len(pArrayListClients);

		for(i = 0; i < len; i++)
		{
			bufferClient = ll_get(pArrayListClients, i);
			if(client_getIdClient(bufferClient) == id)
			{
				output = i;
				break;
			}
		}

	}
	return output;
}
/** \brief Busca un nuevo dato del tipo Sale* en una lista enlazada tomando como parametro el id retornando el valor por referencias.
 *
 * \param pArrayListSales LinkedList*
 * \param int id
 * \return int
 *
 */
int controller_findSalesById(LinkedList* pArrayListSales, int id)
{
	int output = -1;
	int len;
	int i;
	Sale* bufferSale;
	if (pArrayListSales != NULL && isValidIdSale(id) == 1)
	{
		output = 0;
		len = ll_len(pArrayListSales);
		for(i = 0; i < len; i++)
		{
			bufferSale = ll_get(pArrayListSales, i);
			if(sale_getIdSale(bufferSale) == id)
			{
				output = i;
				break;
			}
		}
	}
	return output;
}
/** \brief modifica el valor de una venta a 'cobrada'
 *
 * \param pArrayListSales LinkedList*
 * \param int id
 * \return int
 *
 */
int controller_chargeSale(LinkedList* pArrayListSales, char* path)
{
	int output = -1;
	int idSale;
	int op;
	int index;
	LinkedList* newList = ll_newLinkedList();
	Sale* bufferSale;
	if(pArrayListSales != NULL && newList != NULL)
	{
		ll_filterAdd(pArrayListSales, newList, sale_isToPay);
		controller_printSales(newList);
		if(utn_getInt(&idSale, INPUT_IDSALE, ERROR_IDSALE, IDSALE_MIN, IDSALE_MAX, ATTEMPTS) == 0)
		{
			index = controller_findSalesById(pArrayListSales, idSale);
			bufferSale = ll_get(pArrayListSales, index);
			if(ll_contains(newList, bufferSale) == 1)
			{
				if(utn_getInt(&op, CONTROLLER_CONFIRM, MENU_SELECT_ERROR, 1, 2, ATTEMPTS) == 0)
				{
					switch(op)
					{
						case 1:
							sale_setStatus(bufferSale, 2);
							controller_saveSalesAsText(path, pArrayListSales);
							printf(CHARGE_SALE_SUCCESS);
							break;
						case 2:
							printf(CONTROLLER_CANCEL);
							break;
					}
					output = 0;
				}
			}
			else
			{
				printf(CHARGE_SALE_ERROR);
			}
		}
	}
	return output;
}





