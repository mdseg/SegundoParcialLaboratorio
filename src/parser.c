#include <stdio.h>
#include <stdlib.h>

#include "Client.h"
#include "Sale.h"
#include "Controller.h"
#include "LinkedList.h"


#define LONG_IDSTRING 8
#define READ_ERROR "Error al leer el archivo"
#define TRUE 1
#define FALSE 0
#define LONG_ID 55
#define LONG_NAME 55
#define LONG_CUIT 55
#define LONG_SALESSTRING 8

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int parser_ClientFromText(FILE* pFile , LinkedList* pArrayListClient)
{
	int output = -1;
	Client* bufferClient;
	char idClientString[LONG_IDSTRING];
	char name[LONG_NAME];
	char lastName[LONG_NAME];
	char cuit[LONG_CUIT];
	int idClient;
	int r;
	int flagEncabezado = FALSE;
	int flagErrores = FALSE;
	if(pFile != NULL && pArrayListClient != NULL)
	{
		do
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idClientString,name,lastName,cuit);
			if (flagEncabezado == 0)
			{
				flagEncabezado = 1;
			}
			else
			{
				if(r==4)
				{
					idClient = atoi(idClientString);
					if(isValidIdClient(idClient) && controller_isRepeatCuit(pArrayListClient, cuit) == 0)
					{
						bufferClient = client_newParams(idClient, name, lastName, cuit);
						ll_add(pArrayListClient, bufferClient);

					}
				}
				else
				{
					client_delete(bufferClient);
					flagErrores = TRUE;
					break;
				}
			}


		}while(!feof(pFile));
		if(flagErrores == FALSE)
		{
			output = 0;
		}
	}
    return output;
}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEnvio LinkedList*
 * \return int
 *
 */
int parser_SalesFromText(FILE* pFile , LinkedList* pArrayListSales)
{
	int output = -1;
	Sale* bufferSale;
	char idSaleString[LONG_IDSTRING];
	char idClientString[LONG_IDSTRING];
	char postersSaledString[LONG_SALESSTRING];
	char fileName[LONG_NAME];
	char zone[LONG_IDSTRING];
	char status[LONG_IDSTRING];
	int idSale;
	int r;
	int flagEncabezado = FALSE;
	int flagErrores = FALSE;
	if(pFile != NULL && pArrayListSales != NULL)
	{
		do
		{
			r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idSaleString,idClientString,postersSaledString,fileName,zone,status);
			if (flagEncabezado == 0)
			{
				flagEncabezado = 1;
			}
			else
			{
				if(r==6)
				{
					idSale = atoi(idSaleString);
					if(isValidIdClient(idSale))
					{
						bufferSale = sale_newParamWithStatus(idSale,idClientString,postersSaledString,fileName,zone,status);
						ll_add(pArrayListSales, bufferSale);

					}
				}
				else
				{
					sale_delete(bufferSale);
					flagErrores = TRUE;
					break;
				}
			}
		}while(!feof(pFile));
		if(flagErrores == FALSE)
		{
			output = 0;
		}
	}
    return output;
}


