#include "Sale.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Sale* sale_new(void)
{
	return (Sale*)malloc(sizeof(Sale));
}

Sale* sale_newParam(int idSale, char* idClient, char* postersSaled, char* fileName, char* zone, char* status)
{
	Sale* this = sale_new();
	if(this != NULL)
	{
		if(!(sale_setIdSale(this, idSale))
			&& !(sale_setIdClient(this, atoi(idClient)))
			&& !(sale_setPostersSaled(this, atoi(postersSaled)))
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


int sale_getPostersSaled(Sale* this)
{
	return this->postersSaled;
}

int sale_setPostersSaled(Sale* this, int postersSaled)
{
	int output = -1;
	if(this != NULL  && isValidPostersSaled(postersSaled))
	{
		this->postersSaled = postersSaled;
		output = 0;
	}
	 return output;
}

int isValidPostersSaled(int postersSaled)
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


