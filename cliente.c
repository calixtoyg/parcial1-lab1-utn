#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Cliente.h"
#include "functionsForProjects.h"

/**
 * Adds an clientes to the first free space of the array
 * @param clientes *eCliente pointer to array of structs of type eCliente
 * @param len int size of array
 * @param id int id of clientes
 * @param name *name pointer to array of chars
 * @param lastName *lastName pointer to array of chars
 * @param salary int salary of clientes
 * @param sector int sector of clientes
 * @return int returns 0 if clientes was successfully added, returns -1 otherwise
 */
int addCliente(eCliente *clientes, int len, char name[], char lastName[], char domicilio[], char telefono[]) {
    int i;
    i = getFreeSpaceClientes(clientes, len);
    if (i != -1) {
        clientes[i].isEmpty = 0;
        clientes[i].idCliente = i + 1;
        strcpy(clientes[i].name, name);
        strcpy(clientes[i].lastName, lastName);
        strcpy(clientes[i].domicilio, domicilio);
        strcpy(clientes[i].telefono, telefono);

        return 0;
    }
    return -1;
}

/**
 * Modifies clientes selected by the id
 * @param clientes *eCliente pointer to array of structs of type eCliente
 * @param len int size of array
 * @param id int id of clientes
 * @param name *name pointer to array of chars
 * @param lastName *lastName pointer to array of chars
 * @param salary int salary of clientes
 * @param sector int sector of clientes
 * @return returns 0 if clientes was deleted -1 if operation was cancelled
 */
int
modifyCliente(eCliente *clientes, int len, int id, char name[], char lastName[], char domicilio[], char telefono[]) {
    int i;
    for (i = 0; i < len; ++i) {
        if (clientes[i].idCliente == id && clientes[i].isEmpty == 0) {
            clientes[i].isEmpty = 0;
            clientes[i].idCliente = id;
            strcpy(clientes[i].name, name);
            strcpy(clientes[i].lastName, lastName);
            strcpy(clientes[i].domicilio, domicilio);
            strcpy(clientes[i].telefono, telefono);
            printf("Operacion realizada con exito ID %d fue modificado.\n", clientes[i].idCliente);

            return 0;
        }
    }
    printf("Operacion cancelada, no se pudo modificar al empleado.\n");
    return -1;
}

/**
 * Modifies clientes selected by the id
 * @param clientes *eCliente pointer to array of structs of type eCliente
 * @param len int size of array
 * @param id int id of clientes
 * @param name *name pointer to array of chars
 * @param lastName *lastName pointer to array of chars
 * @param salary int salary of clientes
 * @param sector int sector of clientes
 * @return returns 0 if clientes was deleted -1 if operation was cancelled
 */
int removeCliente(eCliente *clientes, int len, int id) {
    char tempChar;
    int i, returnNum = -1;
    printf("Esta seguro que desea eliminar el registro (Y/N): \n");
    getC(&tempChar);
    tempChar = toupper(tempChar);

    if (tempChar == 'Y') {
        for (i = 0; i < len; i++) {
            if (id == clientes[i].idCliente) {
                clientes[i].isEmpty = 1;
                returnNum = 0;
                return returnNum;
            }
            returnNum = -1;
        }
        if (returnNum != 0) {
            printf("Registro no encontrado");
            returnNum = 0;
            return returnNum;
        }
    } else {
        system("cls");
        printf("Operacion cancelada-\n");
        return returnNum;
    }

}

/**
 * Prints clientes
 * @param cliente *eCliente pointer to array of structs of type eCliente
 * @param len int size of array
 */
void printClientes(eCliente clientes[], int len) {
    int i;
    system("cls");
    for (i = 0; i < len; i++) {
        if (clientes[i].isEmpty == 0) {
            printf("------------------------------------------------------------\n");
            printf("| ID        |    %d\n", clientes[i].idCliente);
            printf("| Nombre    |    %s\n", clientes[i].name);
            printf("| Apellido  |    %s\n", clientes[i].lastName);
            printf("| Domicilio |    %s\n", clientes[i].domicilio);
            printf("| Telefono  |    %s\n", clientes[i].telefono);
            printf("------------------------------------------------------------\n");
        }

    }


}

/**
 * Gets free space within the array
 * @param employee *eEmployee pointer to an array of structs of type eEmployee
 * @param len int size of array
 * @return int index of first free space in array, 0 if there is no freespace
 */
int getFreeSpaceClientes(eCliente clientes[], int len) {

    int i;
    for (i = 0; i < len; i++) {
        if (clientes[i].isEmpty == 1) {
            return i;
        }
    }
    printf("No hay espacio en el array para agregar mas Clientes.\n");
    return -1;

}

/**
 * Initializes the array of structs of clientes, settings isEmpty variable to 1
 * @param cliente *eEmpleado pointer to array of structs of type eEmployee
 * @param len int size of array
 * @return int returns -1 if array was successfully initialize
 */
int initClientes(eCliente *clientes, int len) {
    int i;
    for (i = 0; i < len; i++) {
        if (clientes[i].isEmpty != 0 || clientes[i].idCliente == 0)
            clientes[i].isEmpty = 1;
    }
    return -1;

}

/**
 * Finds Clientes by it's id
 * @param clientes *eCliente pointer to array of structs of type eClientes
 * @param len int size of array
 * @param id int id of Clientes
 * @return returns index to position of the array where id is, returns -1 if there was no Clientes with that id
 */
int findClienteById(eCliente clientes[], int len, int id) {
    int i;
    for (i = 0; i < len; i++) {
        if (id == clientes[i].idCliente) {
            return i;

        }
    }
    printf("No hay Cliente con el ID:%d en el array.\n", id);
    return -1;
}

void sortByLNameAndName(eCliente *clientes, int len) {
    int i;
    int j;
    eCliente auxclientes;
    for (i = 0; i < len - 1; i++) {
        for (j = i; j < len; ++j) {
            if (clientes[j].isEmpty == 0 && clientes[i].isEmpty == 0) {
                if (strcmp(clientes[i].lastName, clientes[j].lastName) > 0) {
                    auxclientes = clientes[i];
                    clientes[i] = clientes[j];
                    clientes[j] = auxclientes;
                } else if (strcmp(clientes[i].lastName, clientes[j].lastName) == 0) {
                    if (strcmp(clientes[i].name, clientes[j].name) > 0) {
                        auxclientes = clientes[i];
                        clientes[i] = clientes[j];
                        clientes[j] = auxclientes;
                    }

                }
            }

        }

    }


}

/**
 * Turns to upper every single letter of name and last name.
 * @param cliente eCliente* Pointer to array of eCliente
 * @param len int size of array
 */
void toUpperLastNameAndNameClients(eCliente cliente[], int len) {
    int i;
    int j;
    for (i = 0; i < len; i++) {
        for (j = 0; j < strlen(cliente[i].lastName); ++j) {
            cliente[i].lastName[j] = toupper(cliente[i].lastName[j]);
        }
    }
    for (i = 0; i < len; i++) {
        for (j = 0; j < strlen(cliente[i].name); ++j) {
            cliente[i].name[j] = toupper(cliente[i].name[j]);
        }
    }
}

