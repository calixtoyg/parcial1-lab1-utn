#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define JUEGOSIZE 20
#define CLIENTESIZE 20
#define IDJUEGO 2

#include "functionsForProjects.h"
#include "juego.h"
#include "cliente.h"

#define CHARSIZE 51

int main()
{
    /*
    typedef struct {
    int idJuego;
    char descripcion[51];
    float importe;
    int isEmpty;

    }eJuego;
    */
    int menu, menuJuegos, menuClientes = 5, menuAlquileres = 5, menuInformes,flagJuegos = 0,
                          flagClientes = 0, flagAlquileres = 0, idToFind, index,flagFORTESTING=0;
    int dia, mes, ano;
    int idJ = 0, idC = 0, idA = 0, quantityOfJ = 5, quantityOfC = 6;
    int idJuegoParaAlquiler, idClienteParaAlquiler;
    char desciprcion[CHARSIZE], name[CHARSIZE] = {}, lastname[CHARSIZE], domicilio[CHARSIZE], telefono[CHARSIZE];
    int juegosAlquilados[JUEGOSIZE][IDJUEGO];
    int isJuegoSuccesfull, isClienteSuccesfull, isAlquilerSuccesfull;
    float importe, promedioJuegosConAlquileres=0;
    eJuego juegos[JUEGOSIZE]={{1,"Ben diez",200,0},
                       {2,"Magic Booster's pack",1500.49,0},
                       {3,"Hasbro Monopoly",1249.99,0},
                       {4,"Hasbro Guess Who?",499.99,0},
                       {5,"Hasbro Trivial Pursuit",14.99,0}};
    eCliente clientes[CLIENTESIZE]={{1,"Perez","Juan","Av. Santa fe 2544","1167232112",0},
                           {2,"Gomez","Alberto","Flores 444","1157221123",0},
                           {3,"Gonzalez","Calixto","Uruguay 3544","1167232112",0},
                           {4,"Galeano","Mateo","Gorostiaga 2355","1167232112",0},
                           {5,"Oyuela","Juan","Juncal 1433","115647922",0},
                           {6,"Cistari","Renzo","Nueva Cordoba 102","2976329121",0},
    };
    eAlquiler alquileres[JUEGOSIZE*CLIENTESIZE] = {{1,1,2,0,
                                        {10,11,2003}},
                                {2,1,3,0,
                                        {15,1,2000}},
                                {3,1,4,0,
                                        {12,10,2000}},
                                {4,2,1,0,
                                        {9,9,1999}},
                                {4,2,3,0,
                                        {11,8,2004}}
    };
    do
    {
        if (flagFORTESTING == 0){
            //TODO CAMBIAR
            flagFORTESTING=1;
            initJuegos(juegos, JUEGOSIZE);
            initClientes(clientes, CLIENTESIZE);
            initAlquileres(alquileres, JUEGOSIZE*CLIENTESIZE);
            flagAlquileres=1;
            flagClientes=1;
            flagJuegos=1;
        }
        printf("--------------------------- Menus --------------------------\n");
        printf("| 1 - JUEGOS                                               |\n");
        printf("|                                                          |\n");
        printf("| 2 - CLIENTES                                             |\n");
        printf("|                                                          |\n");
        printf("| 3 - ALQUILERES                                           |\n");
        printf("|                                                          |\n");
        printf("| 4 - INFORMES                                             |\n");
        printf("|                                                          |\n");
        printf("| 5 - SALIR                                                |\n");
        printf("------------------------------------------------------------\n");
        fflush(stdin);
        scanf("%d", &menu);
        if (!isValidMenu(menu, 1, 5))
        {
            printf("El numero ingresado no es valido.\n");
            menu = 0;
        }
        switch (menu)
        {
        case 1:
            do
            {


                printf("------------------------ MENU JUEGOS ----------------------\n");
                printf("| 1 - ALTA                                                 |\n");
                printf("|                                                          |\n");
                printf("| 2 - MODIFICAR                                            |\n");
                printf("|                                                          |\n");
                printf("| 3 - BAJA                                                 |\n");
                printf("|                                                          |\n");
                printf("| 4 - LISTA                                                |\n");
                printf("|                                                          |\n");
                printf("| 5 - RETORNAR A MENU PRINCIPAL                            |\n");
                printf("------------------------------------------------------------\n");
                fflush(stdin);
                scanf("%d", &menuJuegos);
                if (!isValidMenu(menuJuegos, 1, 5))
                {
                    printf("El numero ingresado no es valido.\n");
                    menuJuegos = 0;
                }
                switch (menuJuegos)
                {
                case 1:
                    if (flagJuegos == 0)
                    {
                        //TODO cambios
                        flagJuegos = 1;
                        initJuegos(juegos, JUEGOSIZE);

                    }
                    if (getFreeSpace(juegos, JUEGOSIZE) != -1 && quantityOfJ > 0)
                    {

                        printf("------------------------------------------------------------\n");
                        getStringOverbuffCheck(desciprcion, "Ingrese la descripcion:\n", CHARSIZE);
                        printf("------------------------------------------------------------\n");
                        getFloat(&importe, "Ingrese el importe:\n", "ERROR: Solo numeros.\n",
                                 0, pow(2, 1024), 3);
                        isJuegoSuccesfull = addJuego(juegos, JUEGOSIZE, desciprcion, importe);
                    }
                    if (isJuegoSuccesfull == 0)
                    {
                        quantityOfJ++;
                    }
                    break;
                case 2:
                    if (flagJuegos == 1 && quantityOfJ > 0)
                    {
                        getEntero(&idToFind, "Ingrese el ID del juego que desea modificar\n",
                                  "ERROR: Solo numeros dentro de la cantidad maxima del array estan perimitidos\n",
                                  0, JUEGOSIZE, 3);
                        index = findJuegoById(juegos, JUEGOSIZE, idToFind);

                        if (index != -1 && idToFind != -1)
                        {
                            printf("------------------------------------------------------------\n");
                            getStringOverbuffCheck(desciprcion, "Ingrese la descripcion:\n", CHARSIZE);
                            printf("------------------------------------------------------------\n");
                            getFloat(&importe, "Ingrese el importe:\n", "ERROR: Solo numeros.\n",
                                     0, pow(2, 1024), 3);
                            modifyJuego(juegos, JUEGOSIZE, idToFind, desciprcion, importe);
                        }
                    }
                    break;
                case 3:
                    if (flagJuegos == 1 && quantityOfJ > 0)
                    {
                        getEntero(&idToFind, "Ingrese el ID del juego que desea eliminar\n",
                                  "ERROR: Solo numeros dentro de la cantidad maxima del array estan perimitidos\n",
                                  0, JUEGOSIZE, 3);
                        isJuegoSuccesfull = removeJuego(juegos, JUEGOSIZE, idToFind);
                        if (isJuegoSuccesfull == 0)
                        {
                            quantityOfJ--;
                            idJ--;
                        }
                    }

                    break;
                case 4:
                    if (flagJuegos == 1 /*&& quantityOfJ > 0*/)
                    {
                        sortByImport(juegos, JUEGOSIZE);
                        printJuegos(juegos, JUEGOSIZE);
                    }
                    break;
                }
            }
            while (menuJuegos != 5);
            break;
        case 2:
            do
            {

                printf("---------------------- MENU CLIENTES ----------------------\n");
                printf("| 1 - ALTA                                                 |\n");
                printf("|                                                          |\n");
                printf("| 2 - MODIFICAR                                            |\n");
                printf("|                                                          |\n");
                printf("| 3 - BAJA                                                 |\n");
                printf("|                                                          |\n");
                printf("| 4 - LISTA                                                |\n");
                printf("|                                                          |\n");
                printf("| 5 - RETORNAR A MENU PRINCIPAL                            |\n");
                printf("------------------------------------------------------------\n");
                fflush(stdin);
                scanf("%d", &menuClientes);
                if (!isValidMenu(menuClientes, 1, 5))
                {
                    printf("El numero ingresado no es valido.\n");
                    menuClientes = 0;
                }
                switch (menuClientes)
                {
                case 1:
                    if (flagClientes == 0)
                    {
                        flagClientes = 1;
                        initClientes(clientes, CLIENTESIZE);

                    }
                    if (getFreeSpaceClientes(clientes, CLIENTESIZE) != -1)
                    {
                        printf("------------------------------------------------------------\n");
                        getStringLettersOnly(name, "Ingrese el nombre:\n", CHARSIZE, 3);
                        printf("------------------------------------------------------------\n");
                        getStringLettersOnly(lastname, "Ingrese el apellido:\n", CHARSIZE, 3);

                        printf("------------------------------------------------------------\n");
                        getStringOverbuffCheck(&domicilio, "Ingrese el domicilio:\n", CHARSIZE);
                        printf("------------------------------------------------------------\n");
                        getStringOverbuffCheck(&telefono, "Ingrese el telefono:\n", CHARSIZE);
                        isClienteSuccesfull = addCliente(clientes, CLIENTESIZE, name, lastname, domicilio,
                                                         telefono);
                    }
                    if (isClienteSuccesfull == 0)
                    {
                        quantityOfC++;
                    }
                    break;
                case 2:
                    if (flagClientes == 1)
                    {
                        getEntero(&idToFind, "Ingrese el ID del juego que desea modificar\n",
                                  "ERROR: Solo numeros dentro de la cantidad maxima del array estan perimitidos\n",
                                  0, CLIENTESIZE, 3);
                        index = findJuegoById(clientes, CLIENTESIZE, idToFind);

                        if (index != -1 && idToFind != -1)
                        {
                            printf("------------------------------------------------------------\n");
                            getStringLettersOnly(name, "Ingrese el nombre:\n", CHARSIZE, 3);
                            printf("------------------------------------------------------------\n");
                            getStringLettersOnly(lastname, "Ingrese el apellido:\n", CHARSIZE, 3);

                            printf("menuInformes------------------------------------------------------------\n");
                            getStringOverbuffCheck(&domicilio, "Ingrese el domicilio:\n", CHARSIZE);
                            printf("------------------------------------------------------------\n");
                            getStringOverbuffCheck(&telefono, "Ingrese el telefono:\n", CHARSIZE);
                            modifyCliente(clientes, CLIENTESIZE, idToFind, name, lastname, domicilio, telefono);
                        }
                    }
                    break;
                case 3:
                    if (flagClientes == 1)
                    {
                        getEntero(&idToFind, "Ingrese el ID del cliente que desea eliminar\n",
                                  "ERROR: Solo numeros dentro de la cantidad maxima del array estan perimitidos\n",
                                  0, CLIENTESIZE, 3);
                        isClienteSuccesfull = removeCliente(clientes, CLIENTESIZE, idToFind);
                        if (isClienteSuccesfull == 0)
                        {
                            quantityOfC--;
                        }
                    }

                    break;
                case 4:
                    if (flagClientes == 1)
                    {
                        toUpperLastNameAndNameClients(clientes, CLIENTESIZE);
                        sortByLNameAndName(clientes, CLIENTESIZE);
                        printClientes(clientes, CLIENTESIZE);
                    }
                    break;
                }

            }
            while (menuClientes != 5);
            break;
        case 3:
            do
            {
                printf("---------------------- ALQUILER ---------------------------\n");
                printf("| 1 - ALTA                                                 |\n");
                printf("|                                                          |\n");
                printf("| 2 - MOSTRAR ALQUILERES                                   |\n");
                printf("|                                                          |\n");
                printf("| 3 - RETORNAR A MENU PRINCIPAL                            |\n");
                printf("------------------------------------------------------------\n");
                fflush(stdin);
                scanf("%d", &menuAlquileres);
                if (!isValidMenu(menuAlquileres, 1, 3))
                {
                    printf("El numero ingresado no es valido.\n");
                    menuAlquileres = 0;
                }
                switch (menuAlquileres)
                {
                case 1:
                    if (flagAlquileres == 0)
                    {
                        flagAlquileres = 1;
                        initAlquileres(alquileres, CLIENTESIZE*JUEGOSIZE);

                    }
                    printf("------------------------------------------------------------\n");
                    getEntero(&idJuegoParaAlquiler, "Ingrese el id del juego:\n",
                              "ERROR: numero entre 1 y 1000", 1, 1000, 3);


                    printf("------------------------------------------------------------\n");
                    getEntero(&idClienteParaAlquiler, "Ingrese el id del cliente:\n",
                              "ERROR: numero entre 1 y 1000", 1, 1000, 3);
                    printf("------------------------------------------------------------\n");
                    getEntero(&dia, "Ingrese el dia:\n", "ERROR: dia invalido", 0, 30, 3);
                    printf("------------------------------------------------------------\n");
                    getEntero(&mes, "Ingrese el mes:\n", "ERROR: mes invalido", 0, 12, 3);
                    printf("------------------------------------------------------------\n");
                    getEntero(&ano, "Ingrese el año:\n", "ERROR: ano invalido", 1, 9999, 3);
                    if (findJuegoById(juegos, JUEGOSIZE, idJuegoParaAlquiler) != -1 &&
                            findClienteById(clientes, CLIENTESIZE, idClienteParaAlquiler) != -1)
                    {
                        isAlquilerSuccesfull = addAlquiler(alquileres, CLIENTESIZE, idJuegoParaAlquiler,
                                                           idClienteParaAlquiler, dia, mes, ano);
                    }else{
                        printf("El Id especificado no se encuentra. \n");

                    }
                    if (isAlquilerSuccesfull == 0)
                    {
                        //TODO cambiar aca
//                        quantityOfC++;
                    }

                    break;
                case 2:
                    if (flagAlquileres == 1)
                        printAlquileres(alquileres, JUEGOSIZE,CLIENTESIZE,juegos, clientes);
                    break;

                }


            }
            while (menuAlquileres != 3);
            break;
        case 4:
            do
            {
                if (flagAlquileres == 0)
                {
                    printf("No se a ingresado nigun alquiler\n");
                    break;
                }
                printf("---------------------- MENU INFORMES     ----------------------\n");
                printf("| 1 - PROMEDIO y TOTAL DE LOS IMPORTES DE JUEGOS ALQUILADOS    |\n");
                printf("| 2 - TOTAL DE IMPORTES QUE NO SUPERAN EL PROMEDIO             |\n");
                printf("| 3 - LISTAR CLIENTES DE DETERMINADO JUEGO (id del juego)      |\n");
                printf("| 4 - LISTAR JUEGOS DE DETERMINADO CLIENTE (id del cliente)    |\n");
                printf("| 7 - LISTAR JUEGOS QUE ALQUILARON EN UNA FECHA                |\n");
                printf("| 9 - LISTAR JUEGOS POR IMPORTE(DESCENDENTE)                   |\n");
                printf("| 10 - LISTAR CLIENTES POR APELLIDO(ASCENDENTE)                |\n");
                printf("| 11 - SALIR                                                   |\n");;
                printf("---------------------------------------------------------------\n");
                fflush(stdin);
                scanf("%d", &menuInformes);
                if (!isValidMenu(menuInformes, 1, 11))
                {
                    printf("El numero ingresado no es valido.\n");
                    menuInformes = 0;
                }
                switch(menuInformes)
                {
                case 1:
                     printf("---------------------------------------------------------------\n");
                     printf("| Total = %f", totalJuegosAlquilados(alquileres,juegos,clientes,JUEGOSIZE,CLIENTESIZE));
                     printf("| Promedio de Alquileres = %f", promedioJuegosAlquilados(alquileres,juegos,clientes,JUEGOSIZE,CLIENTESIZE));
                     printf("---------------------------------------------------------------\n");
                    break;
                case 2:
                     printf("---------------------------------------------------------------\n");
                     printf("| Total de importes que no superan el promedio = %d", importesQueNoSuperanPromedio(alquileres,juegos,clientes,JUEGOSIZE,CLIENTESIZE));
                     printf("---------------------------------------------------------------\n");

                    break;
                case 3:
                    getEntero(&idToFind, "Ingrese el ID del juego del cual desea listar sus clientes\n",
                              "ERROR: Solo numeros dentro de la cantidad maxima del array estan perimitidos\n",
                              0, JUEGOSIZE, 3);
                    alquilerDeUnJuegoDeterminado(idToFind,alquileres,juegos,clientes,JUEGOSIZE,CLIENTESIZE);

                    break;

                case 4:
                    getEntero(&idToFind, "Ingrese el ID del juego del cual desea listar sus clientes\n",
                              "ERROR:totalJuegosAlquilados Solo numeros dentro de la cantidad maxima del array estan perimitidos\n",
                              0, CLIENTESIZE, 3);
                    alquilerDeUnClienteDeterminado(idToFind,alquileres,juegos,clientes,JUEGOSIZE,CLIENTESIZE);
                    break;
                case 5: {

                    createArrayOfJuegosAlquilados(juegosAlquilados, juegos, JUEGOSIZE);
                    

                }
                    break;
                case 6:
                    break;
                case 7:
                    getEntero(&dia, "Ingrese el dia:\n", "ERROR: dia invalido", 0, 30, 3);
                    printf("------------------------------------------------------------\n");
                    getEntero(&mes, "Ingrese el mes:\n", "ERROR: mes invalido", 0, 12, 3);
                    printf("------------------------------------------------------------\n");
                    getEntero(&ano, "Ingrese el año:\n", "ERROR: ano invalido", 1, 9999, 3);
                    //falta validar si metio bien
                    fechaABuscar(dia,mes,ano,alquileres,juegos,clientes,JUEGOSIZE,CLIENTESIZE);
                    break;
                    break;
                case 8:

                case 9:
                    if (flagJuegos == 1 && quantityOfJ > 0)
                    {
                        sortByImport(juegos, JUEGOSIZE);
                        printJuegos(juegos, JUEGOSIZE);
                    }
                    break;
                case 10:
                    if (flagClientes == 1)
                    {
                        toUpperLastNameAndNameClients(clientes, CLIENTESIZE);
                        sortByLNameAndName(clientes, CLIENTESIZE);
                        printClientes(clientes, CLIENTESIZE);
                    }
                    break;

                }

            }
            while(menuInformes != 11);
            break;

        }

    }
    while (menu != 5);
    return 0;
}
