#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include "Client.h"
#include "Sale.h"

#ifndef REPORT_H_
#define REPORT_H_

#define REPORT_TXT_CLIENT_TOPAY_TOP "idCliente,nombreCliente,apellidoCliente,CUIT,VentasAPagar\n"
#define REPORT_TXT_CLIENT_PAID_TOP "idCliente,nombreCliente,apellidoCliente,CUIT,VentasCobradas\n"
#define REPORT_CREATE_FILE_SUCCESS "Reporte creado con éxito.\n"
#define REPORT_MOSTPORSTESSOLD_TOP "----Id Venta----------CUIT del cliente-------\n"
#define REPORT_MOSTPOSTERSSOLD_ONE_REGISTRY "|%-12d |%-28s |\n"
#define REPORT_MOSTPORSTESSOLD_BOTTOM "---------------------------------------------\n"
int report_generatePayReport(LinkedList* pArrayClientList, LinkedList* pArraySalesList,char* path);
int report_generateSalesReport(LinkedList* pArrayClientList, LinkedList* pArraySalesList,char* path);
int report_CreatePaidFile(LinkedList* pArrayClientList,char* path, char* columName);
int report_CreateToPayFile(LinkedList* pArrayClientList,char* path, char* columName);
int report_findClientPostersSold(LinkedList* pArrayClientList,LinkedList* pArraySalesList, int order);
int report_findSaleMostPosters(LinkedList* pArrayClientList,LinkedList* pArraySalesList, int order);
int report_printSalesWithClient(LinkedList* pArrayListClients,LinkedList* pArrayListSales);
#endif /* REPORT_H_ */
