/*
 * Sale.h
 *
 *  Created on: 21 nov. 2020
 *      Author: marcos
 */

#include "Client.h"

#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef SALE_H_
#define SALE_H_

#define LONG_FILENAME 55
#define LONG_ZONE 55

typedef struct
{
	int idSale;
	int idClient;
	int postersSaled;
	char fileName[LONG_FILENAME];
	char zone[LONG_ZONE];
	int status;

}Sale;

Sale* sale_new(void);
Sale* sale_newParam(int idSale, int idClient, int postersSaled, char* fileName, char* zone, int status);
int sale_setIdSale(Sale* this, int idSale);
int sale_setIdClient(Sale* this, int idClient);
int sale_setPostersSaled(Sale* this, int postersSaled);
int sale_setFileName(Sale* this, char* fileName);
int sale_setZone(Sale* this, char* zone);
int sale_setStatus(Sale* this, int status);
int sale_getIdSale(Sale* this);
int sale_getIdClient(Sale* this);
int sale_getPostersSaled(Sale* this);
char* sale_getFileName(Sale* this);
char* sale_getZone(Sale* this);
int sale_getStatus(Sale* this);

int isValidIdSale(int idSale);
int isValidIdClient(int idClient);
int isValidPostersSaled(int postersSaled);
int isValidFileName(char* fileName);
int isValidZone(char* zone);
int isValidStatus(int status);





#endif /* SALE_H_ */
