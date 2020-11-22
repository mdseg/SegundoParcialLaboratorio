/*
 * Client.h
 *
 *  Created on: 21 nov. 2020
 *      Author: marcos
 */

#ifndef CLIENT_H_
#define CLIENT_H_

#define SIZE_STR 55

#define IDCLIENTE_MIN 1
#define IDCLIENTE_MAX 1000
#define KMRECORRIDOS_MIN 1
#define KMRECORRIDOS_MAX 5000
#define TIPOENTREGA_MIN 1
#define TIPOENTREGA_MAX 20

#define MENU_MODIFY "-------Menu de modificación de Clientes----------\nSeleccione el campo a modificar:\n1-Nombre\n2-Apellido\n3-CUIT\n4-Volver al menú principal\n"
#define MENU_SELECT_ERROR "Por favor, elija una opción valida.\n"

#define ERROR_GENERIC "Error\n"
#define ERROR_IDCLIENTE "Por favor, ingrese un ID de cliente válido.\n"
#define ERROR_NAME "Por favor, ingrese un nombre válido.\n"
#define ERROR_LASTNAME "Por favor, ingrese un apellido válido.\n"
#define ERROR_CUIT "Por favor, ingrese un cuit válido.\n"
#define INPUT_ID "Ingrese el Id del Cliente:\n"
#define INPUT_NAME "Ingrese el nombre:\n"
#define INPUT_LASTNAME "Ingrese el apellido:\n"
#define INPUT_CUIT "Ingrese el Cuit del cliente sin guiones (ej: 20358638628):\n"

//Create
#define CREATE_CLIENT_SUCCESS "Cliente creado con éxito.\n"
#define CREATE_CLIENT_CUIT_ERROR "Ya existe un cliente con ese CUIT"

//Modifiy
#define MODIFY_CLIENT_SUCCESS "\nCliente modificado correctamente.\n"
#define MODIFY_CLIENT_ERROR "\nError en la modificación del cliente.\n"
#define MODIFY_CLIENT_NO_EXIST "\nError en la modificación del cliente, no existe el cliente.\n"
#define MODIFY_NAME_SUCCESS "Nombre modificado con éxito.\n"
#define MODIFY_NAME_ERROR "Error al intentar modificar el nombre.\n"
#define MODIFY_LASTNAME_SUCCESS "Apellido modificado con éxito.\n"
#define MODIFY_LASTNAME_ERROR "Error al intentar modificar el apellido.\n"
#define MODIFY_CUIT_SUCCESS "Cuit modificado con éxito.\n"
#define MODIFY_CUIT_ERROR "Error al intentar modificar el Cuit.\n"


//Informe
#define REPORT_CLIENT_SUCCESS_FINISH "----Finalizado el informe----\n"
#define REPORT_CLIENT_ERROR "\nError al realizar el informe.\n"
#define DELETE_CLIENT_SUCCESS "\nCliente dado de baja correctamente.\n"
#define DELETE_CLIENT_ERROR "No existe un cliente con ese ID.\n"
#define DELETE_CLIENT_CONFIRM "¿Desea eliminar a este cliente? Ingrese 1 para confirmar o 2 para cancelar.\n"
#define DELETE_CLIENT_CANCEL "\nSe ha cancelado la eliminación del cliente.\n"
//Acceso
#define ENTERING_CREATE_CLIENT "Ingresando al sector de altas...\n"
#define ENTERING_MODIFY_CLIENT "Ingresando al sector de modificaciones...\n"
#define ENTERING_REMOVE_CLIENT "Ingresando al sector de bajas...\n"
#define ENTERING_LIST_CLIENT "Ingresando al sector de listado de Clientes...\n"

#define ERROR_NOT_AVAILABLE "Debe ingresar al menos un registro para utilizar esta funcionalidad.\n"
#define PRINT_ONE_REGISTRY_NO_REPORT "|%-4d |%-24s| %-24s| %-24s |\n"
#define PRINT_ONE_REGISTRY_TOP "--ID-------Nombre---------------------Apellido---------------------CUIT--------------\n"
#define PRINT_ONE_REGISTRY_BOTTOM "-------------------------------------------------------------------------------------\n"
#define PRINT_ONE_REGISTRY "|%-4d |%-24s| %-24s| %-24s |\n"

typedef struct
{
	int idClient;
	char name[SIZE_STR];
	char lastName[SIZE_STR];
	char CUIT[SIZE_STR];
	int postersPaids;
	int postersToPay;


}Client;

Client* client_new(void);
Client* client_newString(char* idClient, char* name, char* lastName, char* CUIT);
Client* client_newParams(int idClient, char* name, char* lastName, char* CUIT);
int client_setIdClient(Client* this, int idClient);
int client_setName(Client* this, char* name);
int client_setLastName(Client* this, char* lastName);
int client_setCUIT(Client* this, char* CUIT);
int client_setPostersPaids(Client* this, int postersPaids);
int client_setPostersToPay(Client* this, int postersToPay);
int client_getIdClient(Client* this);
char* client_getName(Client* this);
char* client_getLastName(Client* this);
char* client_getCUIT(Client* this);
int client_getPostersPaids(Client* this);
int client_getPostersToPay(Client* this);


void client_delete(Client* this);
int client_printOneClient(void* this);
int client_printOneClientBanners(Client* this);
int client_isRepeatCuit(void* this, char* cuit);

int isValidIdClient(int idClient);
int isValidName(char* name);
int isValidLastName(char* lastName);
int isValidCUIT(char* CUIT);
int isValidPostersPaids(int postersPaids);
int isValidPostersToPay(int postersToPay);



#endif /* CLIENT_H_ */
