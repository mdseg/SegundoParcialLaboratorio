#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Client.h"
#include "Sale.h"
#include "Report.h"
#include "utn.h"



#define MAIN_MENU "\n-------Sistema de Registro de Empleados ----------\nElija una de estas opciones:\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n3. Alta de empleado\n4. Modificar datos de empleado\n5. Baja de empleado\n6. Listar empleados\n7. Ordenar empleados\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n10. Salir\nSu elección -->  "
#define ERROR_MENU "Por favor, elija una opción válida.\n"
#define LIST_OVERWRITE_CONFIRM "Usted ya ha realizado una carga de datos previamente. ¿Desea eliminar los datos previos? elija 1 para si o 2 para no.\n"
#define EXIT_PROGRAM "Saliendo de la aplicación...\n"
#define LIST_OVERWRITE_USER_CANCEL "Operación cancelada por el usuario.\n"
#define ATTEMPTS 5
#define BINARY_FILE "otro.csv"
#define TEXT_FILE "data.txt"
#define TEXT_DEBUG_FILE "otro.csv"
#define TEXT_SALES_FILE "ventas.csv"
#define TEXT_REPORT_TOPAY "ventas_acobrar.txt"
#define TEXT_REPORT_SALES "ventas_cobradas.txt"

int main()
{
    int option;
    int flagCargaDatos = TRUE;
    int optionSec;
   LinkedList* listClient = ll_newLinkedList();
   LinkedList* listSales = ll_newLinkedList();
   controller_loadClientsFromText(TEXT_FILE,listClient);
   controller_loadPostersFromText(TEXT_SALES_FILE, listSales);


   //LinkedList* newList = ll_newLinkedList();
   //ll_filterAdd(listSales, newList, sale_isToPay);
   //controller_printSales(newList);
   //controller_editSale(listSales, listClient, TEXT_SALES_FILE);
   //controller_chargeSale(listSales, TEXT_SALES_FILE);
   //report_generatePayReport(listClient, listSales,TEXT_REPORT_TOPAY);
   //report_generateSalesReport(listClient, listSales, TEXT_REPORT_SALES);
   report_findClientPostersSold(listClient, listSales);
    do{
    	utn_getInt(&option, MAIN_MENU, ERROR_MENU, 1, 13, ATTEMPTS);
        switch(option)
        {
            case 1:
            	if(flagCargaDatos == TRUE)
            	{
            		if(utn_getInt(&optionSec, LIST_OVERWRITE_CONFIRM, MENU_SELECT_ERROR, 1, 2, ATTEMPTS) == 0)
					{
            			if(optionSec == 1)
            			{
            				controller_loadClientsFromText(TEXT_FILE,listClient);
            			}
            			else
            			{
            				printf(LIST_OVERWRITE_USER_CANCEL);
            			}
					}
            	}
            	else if( controller_loadClientsFromText(TEXT_FILE,listClient) == 0)
            	{
            		flagCargaDatos = TRUE;
            	}
                break;

            case 3:
            	/*if(flagCargaDatos == TRUE)
            	{*/
            		controller_addClient(listClient,TEXT_FILE);
            	/*}
            	else
            	{
            		printf(ERROR_NOT_AVAILABLE);
            	}
				*/
            	break;
            case 4:
            	if(flagCargaDatos == TRUE)
            	{
            		controller_editClient(listClient,TEXT_FILE);

            	}
            	else
            	{
            		printf(ERROR_NOT_AVAILABLE);
            	}
            	break;
            case 5:
            	if(flagCargaDatos == TRUE)
				{
                	controller_removeClient(listClient,TEXT_FILE);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;

            case 6:
            	if(flagCargaDatos == TRUE)
				{
            		controller_printClients(listClient);

				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;

            case 7:
            	if(flagCargaDatos == TRUE)
				{
            		controller_loadPostersFromText(TEXT_SALES_FILE, listSales);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;

            case 8:

            	if(flagCargaDatos == TRUE)
				{
                	controller_saveClienteAsText(TEXT_FILE, listClient);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;

            case 9:
            	if(flagCargaDatos == TRUE)
				{
    				controller_saveSalesAsText(TEXT_SALES_FILE, listSales);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
            	break;

            case 10:
            	if(flagCargaDatos == TRUE)
				{
            		controller_printClients(listClient);
            		controller_addSale(listSales, listClient, TEXT_SALES_FILE);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
				break;
				/*
            case 11:
				if(flagCargaDatos == TRUE)
				{
					controller_sumAllSalaries(listClient);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
				break;
            case 12:
				if(flagCargaDatos == TRUE)
				{
					//controller_countClient(listClient);
				}
				else
				{
					printf(ERROR_NOT_AVAILABLE);
				}
				break;
				*/

        }
    }while(option != 13);
    return 0;
}




