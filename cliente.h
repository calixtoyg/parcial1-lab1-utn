#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED


typedef struct {
    int idCliente;
    char lastName[51];
    char name[51];
    char domicilio[51];
    char telefono[51];
    int isEmpty;

}eCliente;

int initClientes(eCliente *clientes, int len);
int addCliente(eCliente *clientes, int len, char name[],char lastname[],char domicilio[], char telefono[]);
int modifyCliente(eCliente *clientes, int len, int id, char name[],char lastName[],char domicilio[], char telefono[]);
int removeCliente(eCliente *clientes, int len, int id);
void printClientes(eCliente clientes[], int len);
int getFreeSpaceClientes(eCliente clientes[], int len);
int findClienteById(eCliente clientes[], int len, int id);
void sortByLNameAndName(eCliente clientes[], int len);
void toUpperLastNameAndNameClients(eCliente cliente[], int len);


#endif
