/*
 * Client.c
 *
 *  Created on: 21 nov. 2020
 *      Author: marcos
 */
#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include <stdio.h>
#include <string.h>

#include "Client.h"

#define LONG_NAME 55


Client* client_new(void)
{
	return (Client*)malloc(sizeof(Client));
}

Client* client_newParam(char* postersPaids, char* name, char* lastName, char* CUIT)
{
	Client* this = client_new();
	if(this != NULL)
	{
		if(!(client_setIdClient(this, atoi(postersPaids)))
			&& !(client_setName(this, name))
			&& !(client_setLastName(this, lastName))
			&& !(client_setCUIT(this, CUIT))
			)
		{
			client_setPostersPaids(this, 0);
			client_setPostersToPay(this, 0);
			return this;
		}
	}
	return NULL;
}

int client_getIdClient(Client* this)
{
	return this->postersPaids;
}

int client_setIdClient(Client* this, int postersPaids)
{
	int output = -1;
	if(this != NULL  && isValidIdClient(postersPaids))
	{
		this->postersPaids = postersPaids;
		output = 0;
	}
	 return output;
}

int isValidIdClient(int postersPaids)
{
	int output = 0;
	if(postersPaids > 0)
	{
		output = 1;
	}
	return output;
}

char* client_getName(Client* this)
{
	return this->name;
}

int client_setName(Client* this, char* name)
{
	int output = -1;
	if(this != NULL && isValidName(name))
	{
		strncpy(this->name,name,(int)sizeof(this->name));
		output = 0;
	}
	return output;
}

int isValidName(char* name)
{
	int output = 0;
	if(name != NULL && utn_isValidName(name, LONG_NAME) == 1)
	{
		output = 1;
	}
	return output;
}

char* client_getLastName(Client* this)
{
	return this->lastName;
}

int client_setLastName(Client* this, char* lastName)
{
	int output = -1;
	if(this != NULL && isValidLastName(lastName))
	{
		strncpy(this->lastName,lastName,(int)sizeof(this->lastName));
		output = 0;
	}
	return output;
}

int isValidLastName(char* lastName)
{
	int output = 0;
		if(lastName != NULL && utn_isValidName(lastName, LONG_NAME) == 1)
		{
			output = 1;
		}
		return output;
}

char* client_getCUIT(Client* this)
{
	return this->CUIT;
}

int client_setCUIT(Client* this, char* CUIT)
{
	int output = -1;
	if(this != NULL && isValidCUIT(CUIT))
	{
		strncpy(this->CUIT,CUIT,(int)sizeof(this->CUIT));
		output = 0;
	}
	return output;
}

int isValidCUIT(char* CUIT)
{
	int output = 0;
	if(CUIT != NULL && utn_isValidCuit(CUIT) == 1)
	{
		output = 1;
	}
	return output;
}


/** \brief verifica que un puntero del tipo Empleado no sea nulo y posteriormente lo elimina, liberando la memoria asociada a él
 *
 * \param employee1 Employee*
 * \return void
 *
 */
void client_delete(Client* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
/** \brief imprime una tabla con los datos de un unico registro de empleado
 *
 * \param envio1 Client*
 * \return int
 *
 */
int client_printOneClient(Client* this)
{
	int output = -1;
	if (this != NULL)
	{
		printf(PRINT_ONE_REGISTRY_NO_REPORT, client_getIdClient(this), client_getName(this), client_getLastName(this), client_getCUIT(this));
		output = 0;
	}
	return output;
}
/** \brief imprime una tabla con los datos de un unico registro de empleado
 *
 * \param envio1 Client*
 * \return int
 *
 */
int client_printOneClientBanners(Client* this)
{
	int output = -1;
	if (this != NULL)
	{
		printf(PRINT_ONE_REGISTRY_TOP);
		printf(PRINT_ONE_REGISTRY_NO_REPORT, client_getIdClient(this), client_getName(this), client_getLastName(this), client_getCUIT(this));
		printf(PRINT_ONE_REGISTRY_BOTTOM);
		output = 0;
	}
	return output;
}
int client_isRepeatCuit(void* this, char* cuit)
{
	int output = 0;
	Client* bufferClient;
	bufferClient = (Client*)this;
	if(strcmp(client_getCUIT(bufferClient),cuit) == 0)
	{
		output = 1;
	}
	return output;
}
int client_getPostersPaids(Client* this)
{
	return this->postersPaids;
}

int client_setPostersPaids(Client* this, int postersPaids)
{
	int output = -1;
	if(this != NULL  && isValidPostersPaids(postersPaids))
	{
		this->postersPaids = postersPaids;
		output = 0;
	}
	 return output;
}

int isValidPostersPaids(int postersPaids)
{
	int output = 0;
	if(postersPaids >= 0)
	{
		output = 1;
	}
	return output;
}
int client_getPostersToPay(Client* this)
{
	return this->postersToPay;
}

int client_setPostersToPay(Client* this, int postersToPay)
{
	int output = -1;
	if(this != NULL  && isValidPostersToPay(postersToPay))
	{
		this->postersToPay = postersToPay;
		output = 0;
	}
	 return output;
}

int isValidPostersToPay(int postersToPay)
{
	int output = 0;
	if(postersToPay >= 0)
	{
		output = 1;
	}
	return output;
}
