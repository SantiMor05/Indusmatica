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



void actualizarPedido(ConjuntoDePedidos &bufPedidos,int pos,
        const Pedido &pedido);
void crearPedido(ConjuntoDePedidos &bufPedidos,int nd,const Pedido &pedido);
void hacerExacto(int*&entero,char**&cadena);

void hallarPrecio(int*entero,char**cadena,double*&real,const ConjuntoDePlatos &platos);
void cambiarCadena(char**cadena,int*entero,const ConjuntoDePlatos &platos);
char*copiarCadena(const char*nombre);

void hacerArchivo(int*entero,char**cadena,double*real);
void imprimePlato(ofstream &arch,int i,char*nombre,double subtotal,int cant);

#endif /* CONJUNTODEPEDIDOS_HPP */