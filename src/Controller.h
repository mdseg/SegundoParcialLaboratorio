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
#define CONTROLLER_SORT_MENU "-------Menu de ordenamiento----------\nElija el tipo de ordenamiento deseado:\n1. Por Id ascendentemente.\n2. Por Id descendentemente.\n3. Por nombre ascendentemente.\n4. Por nombre descendentemente.\n5. Por horas trabajadas ascendentemente.\n6. Por horas trabajadas descendentemente.\n7. Por salario ascendentemente.\n8. Por salario descendentemente.\n9. Volver al menú anterior.\nSu opción --->"
#define CONTROLLER_ISREPEATCUIT_ERROR "Ya existe un Cliente con ese CUIT.\n"

int controller_loadClientsFromText(char* path , LinkedList* pArrayListClient);
int controller_loadPostersFromText(char* path , LinkedList* pArrayListSales);
int controller_loadFromBinary(char* path , LinkedList* pArrayListClient);
int controller_addClient(LinkedList* pArrayListClient, char* path);
int controller_editClient(LinkedList* pArrayListClient, char* path);
int controller_removeClient(LinkedList* pArrayListClient,char* path);
int controller_printClients(LinkedList* pArrayListClient);
int controller_sortClient(LinkedList* pArrayListClient);
int controller_saveAsText(char* path , LinkedList* pArrayListClient);
int controller_saveClienteAsText(char* path , LinkedList* pArrayListClient);
int controller_saveSalesAsText(char* path , LinkedList* pArrayListSale);
int controller_saveAsBinary(char* path , LinkedList* pArrayListClient);
int controller_getFreeIndex(LinkedList* pArrayListClient);
int controller_saveBinaryPrueba(char* path);
int controller_findClientById(LinkedList* pArrayListClient, int id);
int controller_getNewIdCliente(LinkedList* pArrayListClient);
int controller_filterById(LinkedList* pArrayListClient);
int controller_sumAllSalaries(LinkedList* pArrayListClient);
int controller_countClients(LinkedList* pArrayListClient);
int controller_isRepeatCuit(LinkedList* pArrayListClients,char* cuit);


