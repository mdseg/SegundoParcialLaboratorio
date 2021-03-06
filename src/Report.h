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
#define REPORT_CLIENTS_MORE_POSTERS "Cliente o clientes a los que se le vendieron mas afiches.\n"
#define REPORT_CLIENTS_LESS_POSTERS "Cliente o clientes a los que se le vendieron menos afiches.\n"
#define REPORT_SALES_MOST_POSTERS "Ventas con mayor cantidad de unidades.\n"

int report_generateReport(LinkedList* pArrayClientList, LinkedList* pArraySalesList,char* path, int type);
int report_findClientPostersSold(LinkedList* pArrayClientList,LinkedList* pArraySalesList, int order);
int report_findSaleMostPosters(LinkedList* pArrayClientList,LinkedList* pArraySalesList, int order);
int report_printSalesWithClient(LinkedList* pArrayListClients,LinkedList* pArrayListSales);
#endif /* REPORT_H_ */
