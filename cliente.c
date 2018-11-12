#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "cliente.h"
#include "functionsForProjects.h"
#include "juego.h"

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
/**
 * Ordena clientes por primero apellido y despues nombre
 * @param clientes
 * @param len
 */
void sortByLNameAndName(eCliente *clientes, int len) {

//    int i, j;
//    char *key;
//    eCliente auxclientes;
//    for (i = 1; i < len; i++) {
//        key = clientes[j].lastName;
//        j = i - 1;
//        while (j >= 0 && strcmp(key, clientes[j].lastName) > 0) {
//            if (clientes[j].isEmpty == 0) {
//                clientes[j + 1] = clientes[j];
//                j = j - 1;
//            }
//
//        }
//        strcpy(clientes[j+1].lastName,key);
//
//    }
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
/**
 * Llena juegosAlquilados con el id del cliente por cada struct y la cantidad de veces que este fue rentado.
 * @param juegosAlquilados Pointer to juegosAlquilados struct (estructura "auxiliar")
 * @param juegos Pointer to juegos struct
 * @param alquileres Pointer to alquileres
 * @param sizeJuegos int size juegos
 * @param sizeClientes int size clientes
 */
void fillClientesQueAlquilaron(Alquileres *juegosAlquilados, eCliente *cliente, eAlquiler *alquileres, int sizeJuegos,
                               int sizeClientes) {
    int l, h, k;
    int i;
    for (l = 0; l < sizeJuegos; ++l) {
        juegosAlquilados[l].isEmpty = 0;
        juegosAlquilados[l].idCliente = cliente[l].idCliente;
    }
    for (i = 0; i < sizeJuegos; ++i) {
        if (cliente[i].isEmpty == 0)
            for (k = 0; k < sizeJuegos; ++k) {
                if (juegosAlquilados[k].isEmpty == 0)
                    for (h = 0; h < sizeClientes * sizeJuegos; h++) {
                        if (alquileres[h].isEmpty == 0 && juegosAlquilados[k].idCliente == cliente[i].idCliente &&
                            alquileres[h].idCliente == juegosAlquilados[k].idCliente) {
                            juegosAlquilados[k].cantidadDeAlquileres += 1;
                        }

                    }


            }


    }
    for (k = 0; k < sizeClientes; ++k) {
        printf(" EL ID %d ALQUILO %d\n", juegosAlquilados[k].idCliente, juegosAlquilados[k].cantidadDeAlquileres);

    }
}
/**
 * Ordena la cantidad de veces que se alquilo por un cliente un juego en orden ASCENDENTE
 * @param alquileres Pointer to alquileres struct (estructura "auxiliar")
 * @param sizeJuegos int size juegos
 */
void sortByClientesQueAlquilaron(Alquileres *alquileres, int sizeJuegos) {
    int j, i, key;
    Alquileres auxStruct;
    int auxCantJuego;
    for (i = 0; i < sizeJuegos; ++i) {
        for (j = 0; j < sizeJuegos - 1 - i; ++j) {
            if (alquileres[j].isEmpty == 0 && alquileres[j + 1].isEmpty == 0 &&
                alquileres[j].cantidadDeAlquileres < alquileres[j + 1].cantidadDeAlquileres) {
                auxStruct = alquileres[j];
                alquileres[j] = alquileres[j + 1];
                alquileres[j + 1] = auxStruct;
            }

        }

    }
}

/**
 * Imprime por consola El/Los cliente/s con mas alquileres.
 * @param alquileres Pointer to alquileres struct (estructura "auxiliar")
 * @param clientes Pointer to clientes struct
 * @param sizeClientes int size clientes
 */
void printClienteRealizoMasAlquileres(Alquileres *alquileres, eCliente *clientes, int sizeClientes) {
    int i = 0, flag = 0, j = 0;
    printf("El/Los cliente/s con mas alquileres es/son: \n");
    while (alquileres[j].cantidadDeAlquileres == 0) {
        j++;

    }
    printf("El cliente %s %s alquilo %d. \n",
           clientes[findClienteById(clientes, sizeClientes, alquileres[j].idCliente)].name,
           clientes[findClienteById(clientes, sizeClientes, alquileres[j].idCliente)].lastName,
           alquileres[j].cantidadDeAlquileres);
    for (i = j; alquileres[i].cantidadDeAlquileres == alquileres[i + 1].cantidadDeAlquileres; ++i) {
        printf("El cliente %s %s alquilo %d. \n",
               clientes[findClienteById(clientes, sizeClientes, alquileres[i + 1].idCliente)].name,
               clientes[findClienteById(clientes, sizeClientes, alquileres[i + 1].idCliente)].lastName,
               alquileres[i + 1].cantidadDeAlquileres);
    }
}

