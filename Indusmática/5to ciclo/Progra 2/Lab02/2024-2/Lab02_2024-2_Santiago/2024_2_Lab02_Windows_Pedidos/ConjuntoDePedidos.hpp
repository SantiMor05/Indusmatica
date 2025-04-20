/* 
 * Archivo: ConjuntoDePedidos.hpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 09:59
 */

#ifndef CONJUNTODEPEDIDOS_HPP
#define CONJUNTODEPEDIDOS_HPP

#include <iostream>
#include <fstream>
#include "Pedido.hpp"
#include "ConjuntoDePlatos.hpp"
#define CLIENTE_NO_ENCONTRADO -1
#define MAXIMO_POR_LINEA 70

using namespace std;

struct ConjuntoDePedidos{
    int **enteros;
    char ***cadenas;
    double **reales;    
};

void cargar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, const char *nombre_de_archivo);

void operator>>(istream &archivo_de_pedidos, ConjuntoDePedidos &conjuntoDePedidos);

void inicializar_buffer_de_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, int cantidad);

void operator<<(ConjuntoDePedidos &buffer_de_conjuntoDePedidos, const Pedido &pedido);

void operator>>(const ConjuntoDePedidos &buffer_de_conjuntoDePedidos, ConjuntoDePedidos &conjuntoDePedidos);

int buscar_cliente(const ConjuntoDePedidos &conjuntoDePedidos, int dni);

void operator++(ConjuntoDePedidos &conjuntoDePedidos);

void operator++(ConjuntoDePedidos &conjuntoDePedidos, int);

void liberar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos);

void operator!(ConjuntoDePedidos &conjuntoDePedidos);

void operator*(const ConjuntoDePedidos &conjuntoDePedidos);

void obtener_nombre_archivo(char *nombre_archivo, int dni_numero);

void imprimir_linea(ofstream &archDeReporte, char c = '=');

int obtener_cantidad_cliente(const ConjuntoDePedidos &conjuntoDePedidos);

void modificarDatosConjunto(int *&enteros,  char **&cadenas, 
        const Pedido &pedido);
void reservarEspacio(int *&enteros,  char **&cadenas, int espacios, 
        const Pedido &pedido);
char  *asignarCadena(const char *codigo_repartidor);
void copiarEnteros(int *buffer, int *&enteros);
void copiarCadenas(char **buffer, char ** &cadenas);
void modificarDatosConjunto(int *&enteros,  char **&cadenas, 
        const Pedido &pedido);

int contarDatosPedidos(int *enteros);
void buscarPrecios(int *enteros, double *reales,char **cadenas, int numDat, 
        const  ConjuntoDePlatos &platos);
void cambiarCodANombre(char **cadenas,const ConjuntoDePlatos &platos, int numDat);
void imprimirDetalle(int *enteros,char **cadenas,double *reales, ofstream &arch);
#endif /* CONJUNTODEPEDIDOS_HPP */

