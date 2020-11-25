#include "Report.h"

/** \brief crea un reporte con una lista de clientes con el maximo o el minimo de afiches vendidos
 *
 * \param pArrayClientList LinkedList*
 * \param pArraySalesList LinkedList*
 * \param int order 1 - busca máximo // 2 busca mínimo
 * \return 0 si ok // -1 si error
 *
 */
int report_findClientPostersSold(LinkedList* pArrayClientList,LinkedList* pArraySalesList, int order)
{
	int output = -1;
	int clientsLen = ll_len(pArrayClientList);
	int acumulator;
	int topValue;
	int flagFirstClient = TRUE;
	Client* bufferClient;
	LinkedList* bufferSalesList = ll_newLinkedList();
	LinkedList* searchList = ll_newLinkedList();
	ll_filterAdd(pArraySalesList, bufferSalesList, sale_isPaid);
	if(pArrayClientList != NULL && pArraySalesList != NULL)
	{
		for (int i = 0; i< clientsLen;i++)
		{
			bufferClient = ll_get(pArrayClientList, i);
			if(bufferClient != NULL)
			{
				acumulator = ll_reduceInt(bufferSalesList, sale_sumPosters, client_getIdClient(bufferClient));
				if(flagFirstClient == TRUE)
				{
					ll_add(searchList, bufferClient);
					topValue = acumulator;
					flagFirstClient = FALSE;
				}
				else
				{
					if((order == 1 && acumulator > topValue) || (order == 2 && acumulator < topValue))
					{
						ll_clear(searchList);
						ll_add(searchList, bufferClient);
						topValue = acumulator;
					}
					else if(acumulator == topValue)
					{
						ll_add(searchList, bufferClient);
					}
				}
			}
		}
		controller_printClients(searchList);
		output = 0;
	}
	return output;

}
/** \brief Genera un informe de ventas o de cobros y lo almacena en un archivo tipo .txt
 *
 * \param pArrayClientList LinkedList*
 * \param pArraySalesList LinkedList*
 * \param path char*
 * \param type int   1 para reportes de Cobros // 2 para reportes de Ventas por cobrar
 * \return 0 si ok // -1 si error
 *
 */
int report_generateReport(LinkedList* pArrayClientList, LinkedList* pArraySalesList,char* path, int type)
{
	int output = -1;
	int clientsLen = ll_len(pArrayClientList);
	int acumulator;
	Client* bufferClient;
	LinkedList* bufferSalesList = ll_newLinkedList();
	FILE* pFile;
	pFile = fopen(path,"w");
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	if(pArrayClientList != NULL && pArraySalesList != NULL && pFile != NULL)
	{
		switch(type)
		{
		case 1:
			ll_filterAdd(pArraySalesList, bufferSalesList, sale_isPaid);
			fprintf(pFile,REPORT_TXT_CLIENT_PAID_TOP);
			break;
		case 2:
			ll_filterAdd(pArraySalesList, bufferSalesList, sale_isToPay);
			fprintf(pFile,REPORT_TXT_CLIENT_TOPAY_TOP);
			break;
		}
		for (int i = 0; i< clientsLen;i++)
		{
			bufferClient = ll_get(pArrayClientList, i);
			if(bufferClient != NULL)
			{
				acumulator = ll_reduceInt(bufferSalesList, sale_clientCheckSale, client_getIdClient(bufferClient));
				fprintf(pFile,"%d,%s,%s,%s,%d\n",client_getIdClient(bufferClient),client_getName(bufferClient),client_getLastName(bufferClient),client_getCUIT(bufferClient),acumulator);
			}
		}
		fclose(pFile);
		printf(REPORT_CREATE_FILE_SUCCESS);
		printf(PRINT_ONE_REGISTRY_BOTTOM);
	}
	return output;
}

/** \brief crea una lista de ventas que compartan la mayor/menor cantidad de afiches vendidos
 *
 * \param pArrayClientList LinkedList*
 * \param pArraySalesList LinkedList*
 * \param order int 1 - busca el mayor // 2 - busca el menor
 * \return 0 si ok // -1 si error
 *
 */
int report_findSaleMostPosters(LinkedList* pArrayClientList,LinkedList* pArraySalesList, int order)
{
	int output = -1;
	int salesLen;
	int topValue;
	int flagFirstSale = TRUE;
	Sale* bufferSale;
	LinkedList* bufferSalesList = ll_newLinkedList();
	LinkedList* searchList = ll_newLinkedList();
	ll_filterAdd(pArraySalesList, bufferSalesList, sale_isPaid);
	salesLen = ll_len(bufferSalesList);
	if(pArrayClientList != NULL && pArraySalesList != NULL)
	{
		for (int i = 0; i< salesLen;i++)
		{
			bufferSale = ll_get(bufferSalesList, i);
			if(bufferSale != NULL)
			{

				if(flagFirstSale == TRUE)
				{
					topValue = sale_getPostersSold(bufferSale);
					ll_add(searchList, bufferSale);
					flagFirstSale = FALSE;
				}
				else
				{
					if((order == 1 && sale_getPostersSold(bufferSale) > topValue) || (order == 2 && sale_getPostersSold(bufferSale) < topValue))
					{
						ll_clear(searchList);
						ll_add(searchList, bufferSale);
						topValue = sale_getPostersSold(bufferSale);
					}
					else if(sale_getPostersSold(bufferSale) == topValue)
					{
						ll_add(searchList, bufferSale);
					}
				}
			}
		}
		report_printSalesWithClient(pArrayClientList, searchList);
		output = 0;


	}
	return output;

}

/** \brief Imprime el id de una venta junto con el CUIT del cliente asociado a la misma
 *
 * \param pArrayListClients LinkedList*
 * \param pArrayListSales LinkedList*
 * \return int
 *
 */

int report_printSalesWithClient(LinkedList* pArrayListClients,LinkedList* pArrayListSales)
{
	int output = -1;
	int indexClient;
	int len = ll_len(pArrayListSales);
	Client* bufferClient;
	Sale* bufferSale;
	if(pArrayListSales != NULL && len > 0)
	{
		printf(REPORT_MOSTPORSTESSOLD_TOP);
		for(int i = 0; i < len;i++)
		{
			bufferSale = ll_get(pArrayListSales, i);
			indexClient = controller_findClientById(pArrayListClients, sale_getIdClient(bufferSale));
			bufferClient = ll_get(pArrayListClients,indexClient);
			printf(REPORT_MOSTPOSTERSSOLD_ONE_REGISTRY,sale_getIdSale(bufferSale),client_getCUIT(bufferClient));
		}
		printf(REPORT_MOSTPORSTESSOLD_BOTTOM);

		output = 0;
	}
    return output;
}





