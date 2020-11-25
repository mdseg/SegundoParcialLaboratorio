#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Client.h"
#include "Sale.h"
#include "Report.h"
#include "utn.h"



#define MAIN_MENU "\n-------Sistema de Registro de Ventas ----------\nElija una de estas opciones:\n1. Agregar cliente. \n2. Vender afiches\n3. Modificar venta\n4. Cobrar Venta\n5. Generar informe de cobros.\n6. Generar informe de ventas\n7. Generar estadísticas\n8. Salir\nSu elección -->  "
#define ERROR_MENU "Por favor, elija una opción válida.\n"
#define REPORT_MENU "\n-------Menu de reportes----------\n1-"
#define LIST_OVERWRITE_CONFIRM "Usted ya ha realizado una carga de datos previamente. ¿Desea eliminar los datos previos? elija 1 para si o 2 para no.\n"
#define EXIT_PROGRAM "Saliendo de la aplicación...\n"
#define LIST_OVERWRITE_USER_CANCEL "Operación cancelada por el usuario.\n"
#define ATTEMPTS 5
#define BINARY_FILE "otro.csv"
#define TEXT_CLIENTS_FILE "clientes.txt"
#define TEXT_DEBUG_FILE "otro.csv"
#define TEXT_SALES_FILE "ventas.txt"
#define TEXT_REPORT_TOPAY "ventas_acobrar.txt"
#define TEXT_REPORT_SALES "ventas_cobradas.txt"

int main()
{
   int option;
   LinkedList* listClient = ll_newLinkedList();
   LinkedList* listSales = ll_newLinkedList();

   controller_loadClientsFromText(TEXT_CLIENTS_FILE,listClient);
   printf("len %d.\n",ll_len(listClient));
   ll_clear(listClient);
   printf("len %d.\n",ll_len(listClient));
   controller_loadClientsFromText(TEXT_CLIENTS_FILE,listClient);

   //Carga Clientes
   if(controller_loadClientsFromText(TEXT_CLIENTS_FILE,listClient) == 0 &&
		   controller_loadPostersFromText(TEXT_SALES_FILE, listSales) == 0)
   {
       do{
		   utn_getInt(&option, MAIN_MENU, ERROR_MENU, 1, 8, ATTEMPTS);
		   switch(option)
		   {
			   case 1:
				   controller_addClient(listClient, TEXT_CLIENTS_FILE);
				   break;
			   case 2:
				   controller_addSale(listSales, listClient, TEXT_SALES_FILE);
				   break;
			   case 3:
				   controller_editSale(listSales, listClient, TEXT_SALES_FILE);
				   break;
			   case 4:
				   controller_chargeSale(listSales, TEXT_SALES_FILE);
				   break;
			   case 5:
				   report_CreatePaidFile(listClient, TEXT_REPORT_SALES, "VentasCobradas");
				   break;
			   case 6:
				   report_CreateToPayFile(listClient, TEXT_REPORT_TOPAY, "VentasACobrar");
				   break;
			   case 7:
				   printf(REPORT_CLIENTS_MORE_POSTERS);
				   report_findClientPostersSold(listClient, listSales, 1);
				   printf(REPORT_CLIENTS_LESS_POSTERS);
				   report_findClientPostersSold(listClient, listSales, 2);
				   printf(REPORT_SALES_MOST_POSTERS);
				   report_findSaleMostPosters(listClient, listSales,1);
				   break;
		   }
	   }while(option != 8);
   }
   else
   {
	   printf(CONTROLLER_LOAD_LIST_NO_FILE);
   }


    return 0;
}




