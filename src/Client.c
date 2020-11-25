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

/** \brief reserva un espacio de memoria del tipo Client para crear un nuevo elemento
 *
 * \param void
 * \return void
 *
 */
Client* client_new(void)
{
	return (Client*)malloc(sizeof(Client));
}
/** \brief reserva un espacio de memoria del tipo Client para crear un nuevo elemento ingresando los parametros correspondientes
 *
 * \param idClient char* id del cliente cargado
 * \param name char* nombre del cliente
 * \param lastName char* apellido del cliente
 * \param CUIT char* cuit del cliente
 * \return Client* si Ok // null si error
 */
Client* client_newString(char* idClient, char* name, char* lastName, char* CUIT)
{
	Client* this = client_new();
	if(this != NULL)
	{
		if(!(client_setIdClient(this, atoi(idClient)))
			&& !(client_setName(this, name))
			&& !(client_setLastName(this, lastName))
			&& !(client_setCUIT(this, CUIT))
			)
		{
			return this;
		}
	}
	return NULL;
}
/** \brief reserva un espacio de memoria del tipo Client para crear un nuevo elemento ingresando los parametros correspondientes
 *
 * \param idClient int id del cliente cargado
 * \param name char* nombre del cliente
 * \param lastName char* apellido del cliente
 * \param CUIT char* cuit del cliente
 * \return Client* si Ok // null si error
 */
Client* client_newParams(int idClient, char* name, char* lastName, char* CUIT)
{
	Client* this = client_new();
	if(this != NULL)
	{
		if(!(client_setIdClient(this, idClient))
			&& !(client_setName(this, name))
			&& !(client_setLastName(this, lastName))
			&& !(client_setCUIT(this, CUIT))
			)
		{
			return this;
		}
	}
	return NULL;
}
/** \brief verifica que un puntero del tipo Cliente no sea nulo y posteriormente retorna el Id del cliente del mismo.
 *
 * \param this Client*
 * \return Client* si ok // null si error
 *
 */
int client_getIdClient(Client* this)
{
	return this->idClient;
}
/** \brief verifica que un puntero del tipo Client no sea nulo y posteriormente asigna el Id de del cliente al mismo.
 *
 * \param this Client*
 * \param idClient int
 * \return 0 si ok // -1 si error
 *
 */
int client_setIdClient(Client* this, int idClient)
{
	int output = -1;
	if(this != NULL  && isValidIdClient(idClient))
	{
		this->idClient = idClient;
		output = 0;
	}
	 return output;
}
/** \brief realiza la validacion del campo idClient.
 *
 * \param idClient int
 * \return 1 si ok // 0 si no es válido
 *
 */
int isValidIdClient(int idClient)
{
	int output = 0;
	if(idClient > 0)
	{
		output = 1;
	}
	return output;
}
/** \brief verifica que un puntero del tipo Cliente no sea nulo y posteriormente retorna el nombre del mismo.
 *
 * \param this Client*
 * \return name si ok // null si error
 *
 */
char* client_getName(Client* this)
{
	return this->name;
}
/** \brief verifica que un puntero del tipo Client no sea nulo y posteriormente asigna el nombre al mismo.
 *
 * \param this Client*
 * \param name char*
 * \return 0 si ok // -1 si error
 *
 */
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
/** \brief realiza la validacion del campo name.
 *
 * \param name char*
 * \return 1 si ok // 0 si no es válido
 *
 */
int isValidName(char* name)
{
	int output = 0;
	if(name != NULL && utn_isValidName(name, LONG_NAME) == 1)
	{
		output = 1;
	}
	return output;
}
/** \brief verifica que un puntero del tipo Cliente no sea nulo y posteriormente retorna el apellido del mismo.
 *
 * \param this Client*
 * \return lastName si ok // null si error
 *
 */
char* client_getLastName(Client* this)
{
	return this->lastName;
}
/** \brief verifica que un puntero del tipo Client no sea nulo y posteriormente asigna el apellido al mismo.
 *
 * \param this Client*
 * \param lastName char*
 * \return 0 si ok // -1 si error
 *
 */
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
/** \brief realiza la validacion del campo lastName.
 *
 * \param lastName char*
 * \return 1 si ok // 0 si no es válido
 *
 */
int isValidLastName(char* lastName)
{
	int output = 0;
		if(lastName != NULL && utn_isValidName(lastName, LONG_NAME) == 1)
		{
			output = 1;
		}
		return output;
}
/** \brief verifica que un puntero del tipo Cliente no sea nulo y posteriormente retorna el CUIT del mismo.
 *
 * \param this Client*
 * \return CUIT si ok // null si error
 *
 */
char* client_getCUIT(Client* this)
{
	return this->CUIT;
}
/** \brief verifica que un puntero del tipo Client no sea nulo y posteriormente asigna el CUIT al mismo.
 *
 * \param this Client*
 * \param CUIT char*
 * \return 0 si ok // -1 si error
 *
 */
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
/** \brief realiza la validacion del campo CUIT.
 *
 * \param CUIT char*
 * \return 1 si ok // 0 si no es válido
 *
 */
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
/** \brief imprime una tabla con los datos de un unico registro de Client*
 *
 * \param envio1 Client*
 * \return int
 *
 */
int client_printOneClient(void* this)
{
	int output = -1;
	Client* bufferCliente = (Client*)this;
	if (this != NULL)
	{
		printf(PRINT_ONE_REGISTRY_NO_REPORT, client_getIdClient(bufferCliente), client_getName(bufferCliente), client_getLastName(bufferCliente), client_getCUIT(bufferCliente));
		output = 0;
	}
	return output;
}
/** \brief imprime una tabla con los datos de un unico registro de Client* con encabezado
 *
 * \param envio1 Client*
 * \return 0 si ok // -1 si error
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
/** \brief verifica que un valor de Cuit de un Client* sea igual a uno ingresado por parametro.
 *
 * \param this Client*
 * \return 1 si ok // 0 si no es igual
 *
 */
int client_isRepeatCuit(void* this, char* cuit)
{
	int output = -1;
	Client* bufferClient;
	bufferClient = (Client*)this;
	if(bufferClient != NULL && cuit != NULL)
	{
		output = 0;
		if(strcmp(client_getCUIT(bufferClient),cuit) == 0)
		{
			output = 1;
		}
	}
	return output;
}

