#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "cliente.h"

typedef struct {
    int idJuego;
    char descripcion[51];
    float importe;
    int isEmpty;

}eJuego;
typedef struct {
    int dia,mes,ano;
}eFecha;
typedef struct {
    int idAlquiler;
    int idJuego;
    int idCliente;
    int isEmpty;
    eFecha fecha;
}eAlquiler;


int initJuegos(eJuego *juegos, int len);
int addJuego(eJuego *juegos, int len, char description[],float importe);
int modifyJuego(eJuego *juegos, int len, int id, char description[],int importe);
int removeJuego(eJuego *juegos, int len, int id);
void printJuegos(eJuego *juegos, int len);
int getFreeSpace(eJuego juegos[], int len);
int findJuegoById(eJuego juegos[], int len, int id);
void sortByImport(eJuego juegos[], int len);

int addAlquiler(eAlquiler *alquileres, int len, int idJuego, int idCliente, int dia, int mes, int ano);
int getFreeSpaceAlquiler(eAlquiler *alquileres, int len);
int initAlquileres(eAlquiler *alquileres, int len);
void printAlquileres(eAlquiler *alquileres, int lenJuegos,int lenClientes,eJuego *juegos, eCliente *clientes);
float promedioJuegosAlquilados(eAlquiler *alquileres, eJuego *juegos,eCliente *clientes,int lenJuegos,int lenClientes);
void alquilerDeUnJuegoDeterminado(int idJuego,eAlquiler *alquileres, eJuego *juegos,eCliente *clientes,int lenJuegos,int lenClientes);
void alquilerDeUnClienteDeterminado(int idAlquiler,eAlquiler *alquileres, eJuego *juegos,eCliente *clientes,int lenJuegos,int lenClientes);
float totalJuegosAlquilados(eAlquiler *alquileres, eJuego *juegos,eCliente *clientes,int lenJuegos,int lenClientes);
int importesQueNoSuperanPromedio(eAlquiler *alquileres, eJuego *juegos,eCliente *clientes,int lenJuegos,int lenClientes);
void fechaABuscar(int dia,int mes,int ano,eAlquiler *alquileres, eJuego *juegos,eCliente *clientes,int lenJuegos,int lenClientes);


void createArrayOfJuegosAlquilados(int juegosAlquilados[][2], eJuego *juegos, int sizeJuegos);
void fillJuegosAlquilados(int juegosAlquilados[][2], eJuego *juegos, eAlquiler *alquileres, int sizeJuegos,
                          int sizeClientes);
int getIndexJuegosAlquilados(int idJuego,int sizeJuegos,int juegosAlquilados[][2]);
void sortByTimesAlquilado(int juegosAlquilados[0][2], int sizeJuegos);
#endif
