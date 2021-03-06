#include "Sale.h"
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LONG_NAME 55

/** \brief reserva un espacio de memoria del tipo Sale para crear un nuevo elemento
 *
 * \param void
 * \return void
 *
 */
Sale* sale_new(void)
{
	return (Sale*)malloc(sizeof(Sale));
}
/** \brief reserva un espacio de memoria del tipo Sale para crear un nuevo elemento ingresando los parametros correspondientes
 *
 * \param iDSale int id de la venta cargada
 * \param idClient int id del cliente cargado
 * \param postersSold char* cantidad de afiches vendidos
 * \param fileName char* nombre del archivo cargado
 * \param zone char* zona del aviso publicitario
 * \return Sale* si Ok // null si error
 */
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
/** \brief reserva un espacio de memoria del tipo Sale para crear un nuevo elemento ingresando los parametros correspondientes
 *
 * \param iDSale int id de la venta cargada
 * \param idClient int id del cliente cargado
 * \param postersSold char* cantidad de afiches vendidos
 * \param fileName char* nombre del archivo cargado
 * \param zone char* zona del aviso publicitario
 * \param status char* estado de la venta
 * \return Sale* si Ok // null si error
 */
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
/** \brief verifica que un puntero del tipo Sale no sea nulo y posteriormente lo elimina, liberando la memoria asociada a él
 *
 * \param sale Sale*
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
/** \brief verifica que un puntero del tipo Sale no sea nulo y posteriormente retorna el Id de la venta del mismo.
 *
 * \param this Sale*
 * \return Sale* si ok // null si error
 *
 */
int sale_getIdSale(Sale* this)
{
	return this->idSale;
}
/** \brief verifica que un puntero del tipo Sale no sea nulo y posteriormente asigna el Id de la venta al mismo.
 *
 * \param this Sale*
 * \param idSale int
 * \return 0 si ok // -1 si error
 *
 */
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
/** \brief realiza la validacion del campo idSale.
 *
 * \param idSale int
 * \return 1 si ok // 0 si no es válido
 *
 */
int isValidIdSale(int idSale)
{
	int output = 0;
	if(idSale > 0)
	{
		output = 1;
	}
	return output;
}
/** \brief verifica que un puntero del tipo Sale no sea nulo y posteriormente retorna el Id del cliente del mismo.
 *
 * \param this Sale*
 * \return idCliente si ok // null si error
 *
 */
int sale_getIdClient(Sale* this)
{
	return this->idClient;
}
/** \brief verifica que un puntero del tipo Sale no sea nulo y posteriormente asigna el Id del cliente del mismo.
 *
 * \param this Sale*
 * \param idClient int
 * \return 0 ok // -1 si error
 *
 */
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

/** \brief verifica que un puntero del tipo Sale no sea nulo y posteriormente retorna el Id de la cantidad de posters vendidos del mismo.
 *
 * \param this Sale*
 * \return postersSold si ok // null si error
 *
 */
int sale_getPostersSold(Sale* this)
{
	return this->postersSold;
}
/** \brief verifica que un puntero del tipo Sale no sea nulo y posteriormente asigna el valor de afiches vendidos al mismo.
 *
 * \param this Sale*
 * \param postersSold int
 * \return 0 si ok // -1 si error
 *
 */
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
/** \brief realiza la validacion del campo postersSold.
 *
 * \param postersSold int
 * \return 1 si ok // 0 si no es válido
 *
 */
int isValidPostersSold(int postersSold)
{
	int output = 0;
	if(postersSold > 0)
	{
		output = 1;
	}
	return output;
}
/** \brief verifica que un puntero del tipo Sale no sea nulo y posteriormente retorna el Id de la el nombre del archivo del mismo.
 *
 * \param this Sale*
 * \return fileName si ok // null si error
 *
 */
char* sale_getFileName(Sale* this)
{
	return this->fileName;
}
/** \brief verifica que un puntero del tipo Sale no sea nulo y posteriormente asigna el valor de afiches vendidos al mismo.
 *
 * \param this Sale*
 * \param fileName char*
 * \return 0 si ok // -1 si error
 *
 */
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
/** \brief realiza la validacion del campo fileName.
 *
 * \param fileName char*
 * \return 1 si ok // 0 si no es válido
 *
 */
int isValidFileName(char* fileName)
{
	int output = 0;
	if(fileName != NULL && utn_isValidFileName(fileName))
	{
		output = 1;
	}
	return output;
}
/** \brief verifica que un puntero del tipo Sale no sea nulo y posteriormente retorna el Id de la zona del mismo.
 *
 * \param this Sale*
 * \return zone si ok // null si error
 *
 */
int sale_getZone(Sale* this)
{
	return this->zone;
}
/** \brief verifica que un puntero del tipo Sale no sea nulo y posteriormente asigna el valor de zona al mismo.
 *
 * \param this Sale*
 * \param zone int
 * \return 0 si ok // -1 si error
 *
 */
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
/** \brief realiza la validacion del campo zone.
 *
 * \param zone int
 * \return 1 si ok // 0 si no es válido
 *
 */
int isValidZone(int zone)
{
	int output = 0;
	if(zone > 0)
	{
		output = 1;
	}
	return output;
}
/** \brief verifica que un puntero del tipo Sale no sea nulo y posteriormente retorna el estado del mismo.
 *
 * \param this Sale*
 * \return postersSold si ok // null si error
 *
 */
int sale_getStatus(Sale* this)
{
	return this->status;
}
/** \brief verifica que un puntero del tipo Sale no sea nulo y posteriormente asigna el valor de estado al mismo.
 *
 * \param this Sale*
 * \param status int
 * \return 0 si ok // -1 si error
 *
 */
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
/** \brief realiza la validacion del campo status.
 *
 * \param status int
 * \return 1 si ok // 0 si no es válido
 *
 */
int isValidStatus(int status)
{
	int output = 0;
	if(status > 0)
	{
		output = 1;
	}
	return output;
}

/** \brief imprime una fila con los datos de un unico registro de venta
 *
 * \param this Sale*
 * \return 0 si ok // -1 si error
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
/** \brief imprime una tabla con los datos de un unico registro de ventas con encabezado
 *
 * \param this Sale*
 * \return 0 si ok // -1 si error
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
/** \brief function criterio que evalua si una venta esta como 'a cobrar'
 *
 * \param this Sale*
 * \return 1 si es a cobrar // 0 si no es // -1 si error
 *
 */
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
/** \brief function criterio que evalua si una venta esta como 'cobrada'
 *
 * \param this Sale*
 * \return 1 si es cobrada // 0 si no es // -1 si error
 *
 */
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
/** \brief function criterio que retorna la cantidad de posters si se corresponde con el idCliente ingresado
 *
 * \param this Sale*
 * \áram idClient int
 * \return sale_getPostersSold(this) si ok // 0 si no es // -1 si error
 *
 */
int sale_sumPosters(void* this, int idClient)
{
	int output = -1;
	if(this != NULL && idClient > 0)
	{
		output = 0;
		if(sale_getIdClient(this) == idClient)
		{
			output = sale_getPostersSold(this);
		}
	}
	return output;
}
/** \brief function criterio que evalua si la una venta corresponde a un cliente o no
 *
 * \param this Sale*
 * \param idClient int
 * \return sale_getPostersSold(this) si ok // 0 si no es // -1 si error
 *
 */
int sale_clientCheckSale(void* this, int idClient)
{
	int output = -1;
	Sale* bufferSale = (Sale*)this;
	if (bufferSale != NULL && idClient > 0)
	{
		output = 0;
		if(sale_getIdClient(this) == idClient)
		{
			output = 1;
		}
	}
	return output;
}
/** \brief function criterio que evalua si la una venta corresponde a un cliente o no
 *
 * \param this Sale*
 * \param idClient int
 * \return sale_getPostersSold(this) si ok // 0 si no es // -1 si error
 *
 */
int sale_printSaleIfMatches(void* this, int idClient)
{
	int output = -1;
	Sale* bufferSale = (Sale*)this;
	if (bufferSale != NULL && idClient > 0 && sale_getIdClient(bufferSale) == idClient)
	{
		output = 0;
		sale_printOneSale(bufferSale);
	}
	return output;
}
/** \brief función criterio para ordenar salees por el id y devuelve el resultado de la comparación por valor
 *
 * \param sale1 void*
 * \param sale1 void*
 * \return int
 *
 */
int sale_compareByIdSale(void* sale1, void* sale2)
{
	int output;
	Sale* bufferFirstSale;
	Sale* bufferSecondSale;
	bufferFirstSale = (Sale*) sale1;
	bufferSecondSale = (Sale*) sale2;
	int bufferIdFirstSale;
	int bufferIdSecondSale;
	bufferIdFirstSale = sale_getIdSale(bufferFirstSale);
	bufferIdSecondSale = sale_getIdSale(bufferSecondSale);

	if(bufferIdFirstSale > bufferIdSecondSale)
	{
		output = 1;
	}
	else
	{
		if(bufferIdFirstSale < bufferIdSecondSale)
		{
			output = -1;
		}
		else
		{
			output = 0;
		}
	}
	return output;
}
/** \brief función criterio para ordenar ventas por el idCliente y devuelve el resultado de la comparación por valor
 *
 * \param sale1 void*
 * \param sale1 void*
 * \return int
 *
 */
int sale_compareByIdClient(void* sale1, void* sale2)
{
	int output;
	Sale* bufferFirstSale;
	Sale* bufferSecondSale;
	bufferFirstSale = (Sale*) sale1;
	bufferSecondSale = (Sale*) sale2;
	int bufferIdClientFirstSale;
	int bufferIdClientSecondSale;
	bufferIdClientFirstSale = sale_getIdClient(bufferFirstSale);
	bufferIdClientSecondSale = sale_getIdClient(bufferSecondSale);

	if(bufferIdClientFirstSale > bufferIdClientSecondSale)
	{
		output = 1;
	}
	else
	{
		if(bufferIdClientFirstSale < bufferIdClientSecondSale)
		{
			output = -1;
		}
		else
		{
			output = 0;
		}
	}
	return output;
}
/** \brief función criterio para ordenar ventas por la cantidad de afiches vendidos
 *  y devuelve el resultado de la comparación por valor
 *
 * \param sale1 void*
 * \param sale1 void*
 * \return int
 *
 */
int sale_compareByPostersSold(void* sale1, void* sale2)
{
	int output;
	Sale* bufferFirstSale;
	Sale* bufferSecondSale;
	bufferFirstSale = (Sale*) sale1;
	bufferSecondSale = (Sale*) sale2;
	int bufferPostersSoldFirstSale;
	int bufferPostersSoldSecondSale;
	bufferPostersSoldFirstSale = sale_getPostersSold(bufferFirstSale);
	bufferPostersSoldSecondSale = sale_getPostersSold(bufferSecondSale);

	if(bufferPostersSoldFirstSale > bufferPostersSoldSecondSale)
	{
		output = 1;
	}
	else
	{
		if(bufferPostersSoldFirstSale < bufferPostersSoldSecondSale)
		{
			output = -1;
		}
		else
		{
			output = 0;
		}
	}
	return output;
}
/** \brief función criterio para ordenar ventas por la zona
 *  y devuelve el resultado de la comparación por valor
 *
 * \param sale1 void*
 * \param sale1 void*
 * \return int
 *
 */
int sale_compareByZone(void* sale1, void* sale2)
{
	int output;
	Sale* bufferFirstSale;
	Sale* bufferSecondSale;
	bufferFirstSale = (Sale*) sale1;
	bufferSecondSale = (Sale*) sale2;
	int bufferZoneFirstSale;
	int bufferZoneSecondSale;
	bufferZoneFirstSale = sale_getZone(bufferFirstSale);
	bufferZoneSecondSale = sale_getZone(bufferSecondSale);

	if(bufferZoneFirstSale > bufferZoneSecondSale)
	{
		output = 1;
	}
	else
	{
		if(bufferZoneFirstSale < bufferZoneSecondSale)
		{
			output = -1;
		}
		else
		{
			output = 0;
		}
	}
	return output;
}
/** \brief función criterio para ordenar ventas por el estado
 *  y devuelve el resultado de la comparación por valor
 *
 * \param sale1 void*
 * \param sale1 void*
 * \return int
 *
 */
int sale_compareByStatus(void* sale1, void* sale2)
{
	int output;
	Sale* bufferFirstSale;
	Sale* bufferSecondSale;
	bufferFirstSale = (Sale*) sale1;
	bufferSecondSale = (Sale*) sale2;
	int bufferStatusFirstSale;
	int bufferStatusSecondSale;
	bufferStatusFirstSale = sale_getStatus(bufferFirstSale);
	bufferStatusSecondSale = sale_getStatus(bufferSecondSale);

	if(bufferStatusFirstSale > bufferStatusSecondSale)
	{
		output = 1;
	}
	else
	{
		if(bufferStatusFirstSale < bufferStatusSecondSale)
		{
			output = -1;
		}
		else
		{
			output = 0;
		}
	}
	return output;
}
/** \brief función criterio para ordenar ventas por el nombre del archivo y devuelve el resultado de la comparación por valor
 *
 * \param client1 void*
 * \param client1 void*
 * \return int
 *
 */
int sale_compareByFileName(void* sale1, void* sale2)
{
	int output;
	Sale* bufferFirstSale;
	Sale* bufferSecondSale;
	bufferFirstSale = (Sale*) sale1;
	bufferSecondSale = (Sale*) sale2;
	char bufferNameFirstSale[LONG_NAME];
	char bufferNameSecondSale[LONG_NAME];
	strcpy(bufferNameFirstSale,sale_getFileName(bufferFirstSale));
	strcpy(bufferNameSecondSale,sale_getFileName(bufferSecondSale));
	if(strncmp(bufferNameFirstSale,bufferNameSecondSale,LONG_NAME)>0)
	{
		output = 1;
	}
	else
	{
		if(strncmp(bufferNameFirstSale,bufferNameSecondSale,LONG_NAME)<0)
		{
			output = -1;
		}
		else
		{
			output = 0;
		}
	}
	return output;

}




