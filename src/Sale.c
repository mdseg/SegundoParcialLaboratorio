#include "Sale.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Sale* sale_new(void)
{
	return (Sale*)malloc(sizeof(Sale));
}

Sale* sale_newParam(int idSale, char* idClient, char* postersSold, char* fileName, char* zone)
{
	Sale* this = sale_new();
	if(this != NULL)
	{
		if(!(sale_setIdSale(this, idSale))
			&& !(sale_setIdClient(this, atoi(idClient)))
			&& !(sale_setPostersSold(this, atoi(postersSold)))
			&& !(sale_setFileName(this, fileName))
			&& !(sale_setZone(this, atoi(zone))))

		{
			sale_setStatus(this, 1);
			return this;
		}
	}
	return NULL;
}
Sale* sale_newParamWithStatus(int idSale, char* idClient, char* postersSold, char* fileName, char* zone,char* status)
{
	Sale* this = sale_new();
	if(this != NULL)
	{
		if(!(sale_setIdSale(this, idSale))
			&& !(sale_setIdClient(this, atoi(idClient)))
			&& !(sale_setPostersSold(this, atoi(postersSold)))
			&& !(sale_setFileName(this, fileName))
			&& !(sale_setZone(this, atoi(zone)))
			&& !(sale_setStatus(this, atoi(status))))
		{
			return this;
		}
	}
	return NULL;
}
/** \brief verifica que un puntero del tipo Empleado no sea nulo y posteriormente lo elimina, liberando la memoria asociada a él
 *
 * \param employee1 Employee*
 * \return void
 *
 */
void sale_delete(Sale* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int sale_getIdSale(Sale* this)
{
	return this->idSale;
}

int sale_setIdSale(Sale* this, int idSale)
{
	int output = -1;
	if(this != NULL  && isValidIdSale(idSale))
	{
		this->idSale = idSale;
		output = 0;
	}
	 return output;
}

int isValidIdSale(int idSale)
{
	return 1;
}

int sale_getIdClient(Sale* this)
{
	return this->idClient;
}

int sale_setIdClient(Sale* this, int idClient)
{
	int output = -1;
	if(this != NULL  && isValidIdClient(idClient))
	{
		this->idClient = idClient;
		output = 0;
	}
	 return output;
}


int sale_getPostersSold(Sale* this)
{
	return this->postersSold;
}

int sale_setPostersSold(Sale* this, int postersSold)
{
	int output = -1;
	if(this != NULL  && isValidPostersSold(postersSold))
	{
		this->postersSold = postersSold;
		output = 0;
	}
	 return output;
}

int isValidPostersSold(int postersSold)
{
	return 1;
}

char* sale_getFileName(Sale* this)
{
	return this->fileName;
}

int sale_setFileName(Sale* this, char* fileName)
{
	int output = -1;
	if(this != NULL && isValidFileName(fileName))
	{
		strncpy(this->fileName,fileName,(int)sizeof(this->fileName));
		output = 0;
	}
	return output;
}

int isValidFileName(char* fileName)
{
	return 1;
}

int sale_getZone(Sale* this)
{
	return this->zone;
}

int sale_setZone(Sale* this, int zone)
{
	int output = -1;
	if(this != NULL && isValidZone(zone))
	{
		this->zone = zone;
		output = 0;
	}
	return output;
}

int isValidZone(int zone)
{
	return 1;
}

int sale_getStatus(Sale* this)
{
	return this->status;
}

int sale_setStatus(Sale* this, int status)
{
	int output = -1;
	if(this != NULL  && isValidStatus(status))
	{
		this->status = status;
		output = 0;
	}
	 return output;
}

int isValidStatus(int status)
{
	return 1;
}

/** \brief imprime una tabla con los datos de un unico registro de empleado
 *
 * \param envio1 Sale*
 * \return int
 *
 */
int sale_printOneSale(void* this)
{
	int output = -1;
	Sale* bufferSale = (Sale*)this;
	char zoneString[LONG_ZONE];
	char statusString[55];
	int zone;
	int status;
	if (this != NULL)
	{
		zone = sale_getZone(this);
		status = sale_getStatus(this);
		switch(zone)
		{
			case 1:
				strcpy(zoneString,"CABA");
				break;
			case 2:
				strcpy(zoneString,"Zona Sur");
				break;
			case 3:
				strcpy(zoneString,"Zona Oeste");
				break;
		}
		switch(status)
		{
			case 1:
				strcpy(statusString,"A cobrar");
				break;
			case 2:
				strcpy(statusString,"Cobrada");
				break;
		}
		printf(PRINT_ONE_SALE, sale_getIdSale(bufferSale),sale_getIdClient(bufferSale), sale_getPostersSold(bufferSale), sale_getFileName(bufferSale), zoneString,statusString);
		output = 0;
	}
	return output;
}
/** \brief imprime una tabla con los datos de un unico registro de empleado
 *
 * \param envio1 Sale*
 * \return int
 *
 */
int sale_printOneSaleBanners(Sale* this)
{
	int output = -1;
	if(this != NULL)
	{
		printf(PRINT_ONE_SALE_TOP);
		sale_printOneSale(this);
		printf(PRINT_ONE_SALE_BOTTOM);
		output = 0;
	}


	return output;
}
int sale_isToPay(void* this)
{
	int output = -1;
	Sale* bufferSale = (Sale*)this;
	if (this != NULL)
	{
		output = 0;
		if(sale_getStatus(bufferSale) == 1)
		{
			output = 1;
		}
	}
	return output;
}
int sale_isPaid(void* this)
{
	int output = -1;
	Sale* bufferSale = (Sale*)this;
	if (this != NULL)
	{
		output = 0;
		if(sale_getStatus(bufferSale) == 2)
		{
			output = 1;
		}
	}
	return output;
}
int sale_sumPosters(void* this, int idClient)
{
	int output = 0;
	if(this != NULL && idClient > 0)
	{
		if(sale_getIdClient(this) == idClient)
		{
			output = sale_getPostersSold(this);
		}
	}
	return output;
}
int sale_clientCheckSale(void* this, int idClient)
{
	int output = -1;
	Sale* bufferSale = (Sale*)this;
	if (bufferSale != NULL && idClient > 0)
	{
		output = 0;
		if(sale_getIdClient(this) == idClient)
		{
			output++;
		}
	}
	return output;
}




