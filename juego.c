#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "juego.h"
#include "functionsForProjects.h"
#include "cliente.h"


/**
 * Adds an juegos to the first free space of the array
 * @param juegos *eJuego pointer to array of structs of type eJuego
 * @param len int size of array
 * @param id int id of juegos
 * @param name *name pointer to array of chars
 * @param lastName *lastName pointer to array of chars
 * @param salary int salary of juegos
 * @param sector int sector of juegos
 * @return int returns 0 if juegos was successfully added, returns -1 otherwise
 */
int addJuego(eJuego *juegos, int len, char description[], float importe)
{
    int i;
    int id;
    i = getFreeSpace(juegos, len);
    id=i+1;
    if (i != -1)
    {
        juegos[i].isEmpty = 0;
        juegos[i].idJuego = id;
        strcpy(juegos[i].descripcion, description);
        juegos[i].importe = importe;
        return 0;
    }
    return -1;
}

/**
 * Modifies juegos selected by the id
 * @param juegos *eJuego pointer to array of structs of type ejuegos
 * @param len int size of array
 * @param id int id of juegos
 * @param name *name pointer to array of chars
 * @param lastName *lastName pointer to array of chars
 * @param salary int salary of juegos
 * @param sector int sector of juegos
 * @return returns 0 if juegos was deleted -1 if operation was cancelled
 */
int modifyJuego(eJuego *juegos, int len, int id, char description[], int importe)
{
    int i;
    for (i = 0; i < len; ++i)
    {
        if (juegos[i].idJuego == id && juegos[i].isEmpty == 0)
        {
            juegos[i].isEmpty = 0;
            juegos[i].idJuego = id;
            strcpy(juegos[i].descripcion, description);
            juegos[i].importe = importe;
            printf("Operacion realizada con exito ID %d fue modificado.\n", juegos[i].idJuego);

            return 0;
        }
    }
    printf("Operacion cancelada, no se pudo modificar al empleado.\n");
    return -1;
}
/**
 * Removes juegos by id ask for char input Y or y for deletion otherwise operation is cancelled
 * @param juegos *eJuego pointer to array of structs of type eJuego
 * @param len int size of array
 * @param id int id of juegos to delete
 * @return int returns 0 if registry was deleted -1 if Error[registry not found or operation cancelled]
 */
int removeJuego(eJuego *juegos, int len, int id)
{
    char tempChar;
    int i, returnNum = -1;
    printf("Esta seguro que desea eliminar el registro (Y/N): \n");
    getC(&tempChar);
    tempChar = toupper(tempChar);

    if (tempChar == 'Y')
    {
        for (i = 0; i < len; i++)
        {
            if (id == juegos[i].idJuego)
            {
                juegos[i].isEmpty = 1;
                returnNum = 0;
                return returnNum;
            }
            returnNum = -1;
        }
        if (returnNum != 0)
        {
            printf("Registro no encontrado");
            returnNum = 0;
            return returnNum;
        }
    }
    else
    {
        system("cls");
        printf("Operacion cancelada-\n");
        return returnNum;
    }

}

/**
 * Prints Juegos
 * @param juegos *eJuegos pointer to array of structs of type eJuegos
 * @param len int size of array
 */
void printJuegos(eJuego *juegos, int len)
{
    int i;
    system("cls");
    for (i = 0; i < len; i++)
    {
        if (juegos[i].isEmpty == 0)
        {
            printf("------------------------------------------------------------\n");
            printf("| ID Juego    |    %d\n", juegos[i].idJuego);
            printf("| Descripcion |    %s\n", juegos[i].descripcion);
            printf("| Importe     |    %f\n", juegos[i].importe);
            printf("------------------------------------------------------------\n");
        }

    }


}

/**
 * Gets free space within the array
 * @param Juegos *eJuegos pointer to an array of structs of type eJuegos
 * @param len int size of array
 * @return int index of first free space in array, 0 if there is no freespace
 */
int getFreeSpace(eJuego *juegos, int len)
{

    int i;
    for (i = 0; i < len; i++)
    {
        if (juegos[i].isEmpty == 1)
        {
            return i;
        }
    }
    printf("No hay espacio en el array para agregar mas juegos.\n");
    return -1;

}

/**
 * Initializes the array of structs of Juegos, settings isEmpty variable to 1
 * @param juegos *eJuegos pointer to array of structs of type eJuegos
 * @param len int size of array
 * @return int returns -1 if array was successfully initialize
 */
int initJuegos(eJuego *juegos, int len)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (juegos[i].isEmpty != 0|| juegos[i].idJuego==0)
            juegos[i].isEmpty = 1;
    }
    return -1;
}

/**
 * Initializes the array of structs of eAlquiler, settings isEmpty variable to 1
 * @param alquileres *eAlquiler pointer to array of structs of type eAlquiler
 * @param len int size of array
 * @return int returns -1 if array was successfully initialize
 */
int initAlquileres(eAlquiler *alquileres, int len)
{

    int i;
    for (i = 0; i < len; i++)
    {
        if(alquileres[i].isEmpty!=0 || alquileres[i].idAlquiler==0)
            alquileres[i].isEmpty = 1;
    }
    return -1;
}

/**
 * Finds juegos by it's id
 * @param juegos *ejuegos pointer to array of structs of type ejuegos
 * @param len int size of array
 * @param id int id of juegos
 * @return returns index to position of the array where id is, returns -1 if there was no juegos with that id
 */
int findJuegoById(eJuego juegos[], int len, int id)
{
    int i;
    for (i = 0; i < len; i++)
    {
        if (id == juegos[i].idJuego)
        {
            return i;

        }
    }
    printf("No hay juego con el ID:%d en el array.\n", id);
    return -1;
}
/**
 * Sorts juegos by import
 * @param juegos *eJuego pointer to array of structs of type eJuego
 * @param len int size of array
 * @param order int 1 for ascending order 0 for descending order
 */
void sortByImport(eJuego *juegos, int len)
{
    int i;
    int j;
    eJuego auxjuegos;
    for (i = 0; i < len - 1; i++)
    {
        for (j = i; j < len; ++j)
        {
            if (juegos[i].importe < juegos[j].importe && juegos[j].isEmpty == 0 && juegos[i].isEmpty == 0 )
            {
                auxjuegos = juegos[i];
                juegos[i] = juegos[j];
                juegos[j] = auxjuegos;
            }

        }


    }
}

/**
 * Adds an alquileres to the first free space of the array
 * @param alquileres *eAlquiler pointer to array of structs of type eAlquiler
 * @param len int size of array
 * @param id int id of alquileres
 * @param name *name pointer to array of chars
 * @param lastName *lastName pointer to array of chars
 * @param salary int salary of alquileres
 * @param sector int sector of alquileres
 * @return int returns 0 if alquileres was successfully added, returns -1 otherwise
 */
int addAlquiler(eAlquiler *alquileres, int len, int idJuego, int idCliente, int dia, int mes, int ano)
{
    int i;
    i = getFreeSpaceAlquiler(alquileres, len);
    if (i != -1)
    {
        alquileres[i].isEmpty = 0;
        alquileres[i].idAlquiler = i + 1;
        alquileres[i].idJuego = idJuego;
        alquileres[i].idCliente = idCliente;
        alquileres[i].fecha.dia = dia;
        alquileres[i].fecha.mes = mes;
        alquileres[i].fecha.ano = ano;
        return 0;
    }
    return -1;
}

/**
 * Gets free space within the array
 * @param alquileres *eAlquiler pointer to an array of structs of type eAlquiler
 * @param len int size of array
 * @return int index of first free space in array, 0 if there is no freespace
 */
int getFreeSpaceAlquiler(eAlquiler alquileres[], int len)
{

    int i;
    for (i = 0; i < len; i++)
    {
        if (alquileres[i].isEmpty == 1)
        {
            return i;
        }
    }
    printf("No hay espacio en el array para agregar mas alquileres.\n");
    return -1;

}

/**
 * Prints Juegos
 * @param juegos *eJuegos pointer to array of structs of type eJuegos
 * @param len int size of array
 */
void printAlquileres(eAlquiler *alquileres, int lenJuegos,int lenClientes,eJuego *juegos, eCliente *clientes)
{
    int i;
    int j;
    system("cls");


//            printf("------------------------------------------------------------\n");
//            printf("| ID Alquiler       |    %d\n", alquileres[i].idAlquiler);
//            printf("| Descripcion juego |    %s\n", juegos[i].descripcion);
//            printf("| Importe           |    %f\n", juegos[i].importe);
//            printf("| Nombre cliente    |    %d\n", alquileres[i].idCliente);
//            printf("| Nombre cliente    |    %d\n", alquileres[i].idCliente);
//
//            printf("| Fecha        |    %d/%d/%d\n", alquileres[i].fecha.dia,alquileres[i].fecha.mes,alquileres[i].fecha.ano);
//            printf("------------------------------------------------------------\n");






}

float promedioJuegosAlquilados(eAlquiler *alquileres, eJuego *juegos,eCliente *clientes,int lenJuegos,int lenClientes)
{
    int i;
    int j;
    int k;
    float total=0;
    int cantidad=0;

    for (i=0; i<lenClientes*lenJuegos; i++ )
    {
        if(alquileres[i].isEmpty== 0)
        for(j=0;j<lenJuegos;j++){
            if(juegos[j].isEmpty==0&&alquileres[i].idJuego==juegos[j].idJuego){
                total+=juegos[j].importe;
                cantidad++;
            }
        }
    }
    return total/cantidad;


}

void alquilerDeUnJuegoDeterminado(int idJuego,eAlquiler *alquileres, eJuego *juegos,eCliente *clientes,int lenJuegos,int lenClientes)
{
    int i;
    int j;
    int k;
    for (i=0; i<lenClientes; i++ )
    {
        if(clientes[i].isEmpty==0)
        for(k=0; k<lenClientes*lenJuegos; k++)
        {
            if(alquileres[k].isEmpty==0 && alquileres[k].idJuego == idJuego &&clientes[i].idCliente == alquileres[k].idCliente){
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
}

void alquilerDeUnClienteDeterminado(int idCliente,eAlquiler *alquileres, eJuego *juegos,eCliente *clientes,int lenJuegos,int lenClientes)
{
    int i;
    int j;
    int k;
    for (i=0; i<lenJuegos; i++ )
    {
        if(juegos[i].isEmpty==0)
        for(k=0; k<lenClientes*lenJuegos; k++)
        {
            if(alquileres[k].isEmpty==0 && alquileres[k].idCliente == idCliente &&juegos[i].idJuego == alquileres[k].idJuego){
            printf("------------------------------------------------------------\n");
            printf("| ID           |    %d\n", juegos[i].idJuego);
            printf("| Descripcion  |    %s\n", juegos[i].descripcion);
            printf("| Importe      |    %f\n", juegos[i].importe);
            printf("------------------------------------------------------------\n");

            }

        }
    }
}
float totalJuegosAlquilados(eAlquiler *alquileres, eJuego *juegos,eCliente *clientes,int lenJuegos,int lenClientes)
{
    int i;
    int j;
    int k;
    int total=0;
    int cantidad=0;

    for (i=0; i<lenClientes*lenJuegos; i++ )
    {
        if(alquileres[i].isEmpty== 0)
        for(j=0;j<lenJuegos;j++){
            if(juegos[j].isEmpty==0&&alquileres[i].idJuego==juegos[j].idJuego){
                total+=juegos[j].importe;
                cantidad++;
            }
        }
    }
    return total/cantidad;


}

int importesQueNoSuperanPromedio(eAlquiler *alquileres, eJuego *juegos,eCliente *clientes,int lenJuegos,int lenClientes){
    int promedio=promedioJuegosAlquilados(alquileres,juegos,clientes,lenJuegos,lenClientes);
    int total=0,i;
    for (i=0;i<lenJuegos;i++){
        if(juegos[i].importe<promedio){
            total++;
        }
    }
    return total;
}

void fechaABuscar(int dia,int mes,int ano,eAlquiler *alquileres, eJuego *juegos,eCliente *clientes,int lenJuegos,int lenClientes){
    int i,j,k;
     for (i=0; i<lenJuegos; i++ )
    {
        if(juegos[i].isEmpty==0)
        for(k=0; k<lenClientes*lenJuegos; k++)
        {
            if(alquileres[k].isEmpty==0 && alquileres[k].idJuego == juegos[i].idJuego&&   alquileres[k].fecha.dia == dia&&alquileres[k].fecha.mes == mes&&alquileres[k].fecha.ano== ano){
            printf("------------------------------------------------------------\n");
            printf("| ID           |    %d\n", juegos[i].idJuego);
            printf("| Descripcion  |    %s\n", juegos[i].descripcion);
            printf("| Importe      |    %f\n", juegos[i].importe);
            printf("------------------------------------------------------------\n");

            }

        }
    }
}

void createArrayOfJuegosAlquilados(int juegosAlquilados[][2], eJuego *juegos, int sizeJuegos){
    int indexJuegosAlquilados=0,i;
    for (i = 0; i < sizeJuegos; ++i) {
        if (juegos[i].isEmpty == 0){
            juegosAlquilados[indexJuegosAlquilados][0] = juegos[i].idJuego;
            juegosAlquilados[indexJuegosAlquilados][1] = 0;
        }else{
            juegosAlquilados[indexJuegosAlquilados][0] = 0;
            juegosAlquilados[indexJuegosAlquilados][1] = 0;
        }
        indexJuegosAlquilados++;
    }


}
