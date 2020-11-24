#include "Report.h"

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

int report_generatePayReport(LinkedList* pArrayClientList, LinkedList* pArraySalesList,char* path)
{
	int output = -1;
	int clientsLen = ll_len(pArrayClientList);
	int acumulator;
	Client* bufferClient;
	LinkedList* bufferSalesList = ll_newLinkedList();
	ll_filterAdd(pArraySalesList, bufferSalesList, sale_isToPay);
	if(pArrayClientList != NULL && pArraySalesList != NULL)
	{
		for (int i = 0; i< clientsLen;i++)
		{
			bufferClient = ll_get(pArrayClientList, i);
			if(bufferClient != NULL)
			{
				acumulator = ll_reduceInt(bufferSalesList, sale_clientCheckSale, client_getIdClient(bufferClient));
				client_setPostersToPay(bufferClient, acumulator);
			}

		}
		report_CreateToPayFile(pArrayClientList, path, "VentasAPagar");

	}
	return output;
}
int report_generateSalesReport(LinkedList* pArrayClientList, LinkedList* pArraySalesList,char* path)
{
	int output = -1;
	int clientsLen = ll_len(pArrayClientList);
	int acumulator;
	Client* bufferClient;
	LinkedList* bufferSalesList = ll_newLinkedList();
	ll_filterAdd(pArraySalesList, bufferSalesList, sale_isPaid);
	if(pArrayClientList != NULL && pArraySalesList != NULL)
	{
		for (int i = 0; i< clientsLen;i++)
		{
			bufferClient = ll_get(pArrayClientList, i);
			if(bufferClient != NULL)
			{
				acumulator = ll_reduceInt(bufferSalesList, sale_clientCheckSale, client_getIdClient(bufferClient));
				client_setPostersPaids(bufferClient, acumulator);
			}
		}
		report_CreatePaidFile(pArrayClientList, path, "VentasCobradas");
	}
	return output;
}
int report_CreateToPayFile(LinkedList* pArrayClientList,char* path, char* columName)
{
	int output = -1;
	int len;
	int i = 0;
	Client* bufferClient;
	FILE* pFile;
	pFile = fopen(path,"w");
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	if(path != NULL && pArrayClientList != NULL)
	{
		if(pFile != NULL)
		{

			len = ll_len(pArrayClientList);
			fprintf(pFile,REPORT_TXT_CLIENT_TOPAY_TOP);
			for (i = 0; i < len;i++)
			{
				bufferClient = ll_get(pArrayClientList, i);
				fprintf(pFile,"%d,%s,%s,%s,%d\n",client_getIdClient(bufferClient),client_getName(bufferClient),client_getLastName(bufferClient),client_getCUIT(bufferClient),client_getPostersToPay(bufferClient));
			}
			fclose(pFile);
			printf(REPORT_CREATE_FILE_SUCCESS);
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
int report_CreatePaidFile(LinkedList* pArrayClientList,char* path, char* columName)
{
	int output = -1;
	int len;
	int i = 0;
	Client* bufferClient;
	FILE* pFile;
	pFile = fopen(path,"w");
	printf(PRINT_ONE_REGISTRY_BOTTOM);
	if(path != NULL && pArrayClientList != NULL)
	{
		if(pFile != NULL)
		{

			len = ll_len(pArrayClientList);
			fprintf(pFile,REPORT_TXT_CLIENT_TOPAY_TOP);
			for (i = 0; i < len;i++)
			{
				bufferClient = ll_get(pArrayClientList, i);
				fprintf(pFile,"%d,%s,%s,%s,%d\n",client_getIdClient(bufferClient),client_getName(bufferClient),client_getLastName(bufferClient),client_getCUIT(bufferClient),client_getPostersPaids(bufferClient));
			}
			fclose(pFile);
			printf(REPORT_CREATE_FILE_SUCCESS);
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

int report_findSaleMostPosters(LinkedList* pArrayClientList,LinkedList* pArraySalesList, int order)
{
	int output = -1;
	int salesLen;
	int topValue;
	int flagFirstSale = TRUE;
	Client* bufferClient;
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

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
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





