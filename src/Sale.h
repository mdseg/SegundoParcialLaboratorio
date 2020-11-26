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
#define POSTERSSOLD_MIN 1
#define POSTERSSOLD_MAX 500
#define IDSALE_MIN 1
#define IDSALE_MAX 2000
#define ZONE_MIN 1
#define ZONE_MAX 3
#define MENU_MODIFY_SALE "-------Menu de modificación de Afiches----------\nSeleccione el campo a modificar:\n1-Id del Cliente\n2-Cantidad de afiches vendidos\n3-Nombre del archivo\n4-Zona\n5-Volver al menú anterior\n"
#define MENU_SELECT_ERROR "Por favor, elija una opción valida.\n"

#define ERROR_GENERIC "Error\n"
#define ERROR_IDSALE "Por favor, ingrese un ID de cliente válido.\n"
#define ERROR_FILENAME "Por favor, ingrese un tipo de Archivo válido\n"
#define ERROR_POSTERSSOLD "Por favor, ingrese una cantidad de avisos válido.\n"
#define ERROR_ZONE "Por favor, ingrese una zona válida.\n"
#define ERROR_STATUS "Por favor, ingrese un estado válido.\n"
#define INPUT_IDSALE "Ingrese el Id de la venta:\n"
#define INPUT_POSTERSSOLD "Ingrese la cantidad de afiches vendidos:\n"
#define INPUT_FILENAME "Ingrese el nombre del archivo del afiche:\n"
#define INPUT_ZONE "Ingrese el código de la zona de la zona:\n1-CABA.\n2-Zona Sur.\n3-Zona Oeste."
#define INPUT_STATUS "Ingrese el estado del afiche.\n"


//Create
#define CREATE_SALE_SUCCESS "Aviso creado con éxito.\n"
#define CREATE_SALE_ERROR "Error al crear el aviso.\n"


//Modifiy
#define MODIFY_SALE_SUCCESS "\nVenta modificada correctamente.\n"
#define MODIFY_SALE_ERROR "\nError en la modificación de la venta.\n"
#define MODIFY_IDSALE_SUCCESS "id de Venta modificado con éxito.\n"
#define MODIFY_IDSALE_ERROR "Error al intentar modificar el id de Venta.\n"
#define MODIFY_POSTERSSOLD_SUCCESS "Cantidad de afiches modificados con éxito.\n"
#define MODIFY_POSTERSSOLD_ERROR "Error al intentar modificar la cantidad de afiches.\n"
#define MODIFY_FILENAME_SUCCESS "nombre del Archivo modificado con éxito.\n"
#define MODIFY_FILENAME_ERROR "Error al intentar modificar el nombre del archivo.\n"
#define MODIFY_ZONE_SUCCESS "Zona modificado con éxito.\n"
#define MODIFY_ZONE_ERROR "Error al intentar modificar la zona.\n"
#define MODIFY_STATUS_SUCCESS "Estado modificado con éxito.\n"
#define MODIFY_STATUS_ERROR "Error al intentar modificar el estado.\n"
#define CHARGE_SALE_SUCCESS "Venta cobrada exitosamente.\n"
#define CHARGE_SALE_ERROR "La venta o no existe, o no está como a pagar"



//Informe
#define REPORT_SALE_SUCCESS_FINISH "----Finalizado el informe----\n"
#define REPORT_SALE_ERROR "\nError al realizar el informe.\n"
#define DELETE_SALE_SUCCESS "\nVenta dada de baja correctamente.\n"
#define DELETE_SALE_ERROR "No existe una venta con ese ID.\n"
#define DELETE_SALE_CONFIRM "¿Desea eliminar a esta venta? Ingrese 1 para confirmar o 2 para cancelar.\n"
#define DELETE_SALE_CANCEL "\nSe ha cancelado la eliminación de la venta.\n"
//Acceso
#define ENTERING_CREATE_SALE "Ingresando al sector de altas...\n"
#define ENTERING_MODIFY_SALE "Ingresando al sector de modificaciones...\n"
#define ENTERING_REMOVE_SALE "Ingresando al sector de bajas...\n"
#define ENTERING_LIST_SALE "Ingresando al sector de listado de Afiches...\n"

#define ERROR_NOT_AVAILABLE "Debe ingresar al menos un registro para utilizar esta funcionalidad.\n"
#define PRINT_ONE_SALE_TOP "--ID Venta------Id Cliente--------Afiches vendidos---------Nombre del archivo----------Zona------------Estado------------------\n"
#define PRINT_ONE_SALE_BOTTOM "-------------------------------------------------------------------------------------------------------------------------------\n"
#define PRINT_ONE_SALE "|%-12d |%-12d |%-24d |%-24s| %-18s| %-24s |\n"

typedef struct
{
	int idSale;
	int idClient;
	int postersSold;
	char fileName[LONG_FILENAME];
	int zone;
	int status;

}Sale;

Sale* sale_new(void);
Sale* sale_newParam(int idSale, char* idClient, char* postersSold, char* fileName, char* zone);
Sale* sale_newParamWithStatus(int idSale, char* idClient, char* postersSold, char* fileName, char* zone,char* status);
int sale_setIdSale(Sale* this, int idSale);
int sale_setIdClient(Sale* this, int idClient);
int sale_setPostersSold(Sale* this, int postersSold);
int sale_setFileName(Sale* this, char* fileName);
int sale_setZone(Sale* this, int zone);
int sale_setStatus(Sale* this, int status);
int sale_getIdSale(Sale* this);
int sale_getIdClient(Sale* this);
int sale_getPostersSold(Sale* this);
char* sale_getFileName(Sale* this);
int sale_getZone(Sale* this);
int sale_getStatus(Sale* this);
void sale_delete(Sale* this);

int sale_printOneSaleBanners(Sale* this);
int sale_printOneSale(void* this);
int sale_clientCheckSale(void* this, int idClient);
int sale_sumPosters(void* this, int idClient);

int isValidIdSale(int idSale);
int isValidIdClient(int idClient);
int isValidPostersSold(int postersSold);
int isValidFileName(char* fileName);
int isValidZone(int zone);
int isValidStatus(int status);
int sale_isToPay(void* this);
int sale_isPaid(void* this);

int sale_compareByIdSale(void* sale1, void* sale2);
int sale_compareByIdClient(void* sale1, void* sale2);
int sale_compareByPostersSold(void* sale1, void* sale2);
int sale_compareByZone(void* sale1, void* sale2);
int sale_compareByFileName(void* sale1, void* sale2);
int sale_compareByStatus(void* sale1, void* sale2);

#endif /* SALE_H_ */
