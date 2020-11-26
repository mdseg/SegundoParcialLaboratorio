#include "LinkedList.h"

#define MENU_SELECT_ERROR "Por favor, elija una opción valida.\n"
#define ATTEMPTS 5
#define TRUE 1
#define FALSE 0
#define CONTROLLER_LOAD_LIST_TEXT "Selecciono la opción de cargar la lista de clientes desde data.csv en modo texto.\n\n"
#define CONTROLLER_LOAD_POSTERS_LIST_TEXT "Selecciono la opción de cargar la lista de afiches desde data.csv en modo texto.\n\n"
#define CONTROLLER_LOAD_LIST_NO_FILE "No existe el archivo.\n"
#define CONTROLLER_LOAD_LIST_TEXT_SUCCESS "Lista cargada en modo texto con éxito.\n"
#define CONTROLLER_LOAD_LIST_BINARY "Selecciono la opción de cargar la lista de empleados desde data.csv en modo binario.\n\n"
#define CONTROLLER_LOAD_LIST_BINARY_SUCCESS "Lista cargada en modo binario con éxito.\n"
#define CONTROLLER_CREATE_SUCCESS "Archivo creado o abierto con éxito.\n"
#define CONTROLLER_TXT_CLIENT_TOP "idCliente,nombreCliente,apellidoCliente,CUIT\n"
#define CONTROLLER_TXT_SALE_TOP "idVenta,idCliente,cantidadVendida,nombreArchivo,zona,estado\n"
#define LL_NULL_ERROR "Problema al cargar la lista de empleados.\n"
#define CONTROLLER_SAVE_BINARY_PATH_ERROR "Error al crear el archivo.\n"
#define CONTROLLER_SAVE_TEXT_ERROR "Error al crear el archivo.\n"
#define CONTROLLER_SORT_MENU "-------Menu de ordenamiento----------\nElija el tipo de ordenamiento deseado:\n1. Clientes: por Id ascendentemente.\n2. Clientes: por Id descendentemente.\n3. Clientes: por nombre ascendentemente.\n4. Clientes: por nombre descendentemente.\n5. Cliente: por apellido ascendentemente.\n6. Cliente: por apellido descendentemente.\n7. Cliente: por CUIT ascendentemente.\n8. Cliente: por CUIT descendentemente.\n9. Ventas: por id ascendentemente.\n10.Ventas: por id descendentemente.\n11. Venta: por id Cliente ascendentemente.\n12. Venta: por id Cliente descendentemente.\n13. Venta: por cantidad de posters vendidos ascendentemente.\n14. Venta: por cantidad de posters vendidos descendentemente.\n15. Venta: por zona ascendentemente.\n16. Venta: por zona desscendentemente.\n17. Venta: por estatus ascendentemente.\n18. Venta: por estatus descendentemente.\n19. Volver al menú anterior.\nSu opción --->"
#define CONTROLLER_ISREPEATCUIT_ERROR "Ya existe un Cliente con ese CUIT.\n"
#define CONTROLLER_CLIENTNOEXIST_ERROR "No existe un cliente que ese id.\n"
#define CONTROLLER_CANCEL "Operación cancelada por el usuario.\n"
#define CONTROLLER_CONFIRM "¿Confirma la operación? Elija 1 para confirmar o 2 para cancelar\n"


int controller_loadClientsFromText(char* path , LinkedList* pArrayListClients);
int controller_loadPostersFromText(char* path , LinkedList* pArrayListSales);
int controller_addClient(LinkedList* pArrayListClients, char* path);
int controller_addSale(LinkedList* pArrayListSales, LinkedList* pArrayListClients, char* path);
int controller_editClient(LinkedList* pArrayListClient, char* path);
int controller_editSale(LinkedList* pArrayListSales,LinkedList* pArrayListClients, char* path);
int controller_removeClient(LinkedList* pArrayListClients,LinkedList* pArrayListSales, char* pathClient, char* pathSales);
int controller_removeSale(LinkedList* pArrayListSales, char* path);
int controller_printClients(LinkedList* pArrayListClient);
int controller_printSales(LinkedList* pArrayListSales);
int controller_sortClient(LinkedList* pArrayListClient);
int controller_saveClienteAsText(char* path , LinkedList* pArrayListClient);
int controller_saveSalesAsText(char* path , LinkedList* pArrayListSale);
int controller_findClientById(LinkedList* pArrayListClients, int id);
int controller_findSalesById(LinkedList* pArrayListSales, int id);
int controller_getNewIdCliente(LinkedList* pArrayListClient);
int controller_getNewIdSale(LinkedList* pArrayListSale);
int controller_filterById(LinkedList* pArrayListClient);
int controller_sumAllSalaries(LinkedList* pArrayListClient);
int controller_countClients(LinkedList* pArrayListClient);
int controller_isRepeatCuit(LinkedList* pArrayListClients,char* cuit);
int controller_chargeSale(LinkedList* pArrayListSales, char* path);
int controller_sortClientsAndSales(LinkedList* pArrayListClients,LinkedList* pArrayListSales);
