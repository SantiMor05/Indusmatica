/* 
 * Archivo: ConjuntoDePedidos.cpp
 * Autor: Andrés Melgar
 * Fecha: 31 de agosto de 2024, 09:59
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "ConjuntoDePedidos.hpp"
#include "Pedido.hpp"
#include "Comunes.hpp"
#include "ConjuntoDePlatos.hpp"
#include "AperturaDeArchivos.h"
#include "ConjuntoDeRepartidores.hpp"

using namespace std;

void cargar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, const char *nombre_de_archivo) {
    ifstream archivo_de_pedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_pedidos, nombre_de_archivo);
    archivo_de_pedidos >> conjuntoDePedidos;
    archivo_de_pedidos.close();
}

void operator>>(istream &archivo_de_pedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    
    ConjuntoDePedidos buffer_de_conjuntoDePedidos;
    Pedido pedido;
    inicializar_buffer_de_conjunto_de_pedidos(buffer_de_conjuntoDePedidos, 500);
    bool valido;
    while(true){
        valido = archivo_de_pedidos >> pedido;
        if(!valido)
            break;
        buffer_de_conjuntoDePedidos << pedido;
    }
    
    buffer_de_conjuntoDePedidos >> conjuntoDePedidos;
    delete buffer_de_conjuntoDePedidos.cadenas;
    delete buffer_de_conjuntoDePedidos.enteros;
}

void inicializar_buffer_de_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, int cantidad) {
    conjuntoDePedidos.enteros = new int*[cantidad];
    conjuntoDePedidos.cadenas = new char**[cantidad]; 
    conjuntoDePedidos.reales = nullptr; 
    for (int i=0; i<cantidad; i++){
        conjuntoDePedidos.enteros[i] = nullptr;
        conjuntoDePedidos.cadenas[i] = nullptr;
    }
}

void operator<<(ConjuntoDePedidos &buffer_de_conjuntoDePedidos, const Pedido &pedido) {
    
    int pos = buscar_cliente(buffer_de_conjuntoDePedidos, pedido.dni_cliente);
    int numDat = 0;
    for(; buffer_de_conjuntoDePedidos.enteros[numDat];numDat++);
    if(pos == CLIENTE_NO_ENCONTRADO){
   
        reservarEspacio(buffer_de_conjuntoDePedidos.enteros[numDat], 
                buffer_de_conjuntoDePedidos.cadenas[numDat],15 ,pedido);
        pos = numDat - 1;
    }
    else{
        modificarDatosConjunto(buffer_de_conjuntoDePedidos.enteros[pos], 
                buffer_de_conjuntoDePedidos.cadenas[pos], pedido);
    }
    
}



void operator>>(const ConjuntoDePedidos &buffer_de_conjuntoDePedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    
    int numDat = 0;
    for(;buffer_de_conjuntoDePedidos.enteros[numDat]; numDat++);
    
    conjuntoDePedidos.cadenas = new char **[numDat + 1]{};
    conjuntoDePedidos.enteros = new int*[numDat + 1]{};
    
    for(int i = 0; buffer_de_conjuntoDePedidos.enteros[i]; i++){
        copiarEnteros(buffer_de_conjuntoDePedidos.enteros[i], 
                conjuntoDePedidos.enteros[i]);
        copiarCadenas(buffer_de_conjuntoDePedidos.cadenas[i],
                conjuntoDePedidos.cadenas[i]);
    }
    conjuntoDePedidos.reales = nullptr;
}

int buscar_cliente(const ConjuntoDePedidos &conjuntoDePedidos, int dni) {
    int i=0;
    while (conjuntoDePedidos.enteros[i] != nullptr) {
        int *bloque_de_enteros = conjuntoDePedidos.enteros[i];
        int dni_del_bloque = bloque_de_enteros[0];
        if (dni_del_bloque == dni)
            return i;
        i++;
    }
    return CLIENTE_NO_ENCONTRADO;
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos) {
    
    ConjuntoDePlatos platos;
    cargar_conjunto_de_platos(platos, "platos.csv");
    
    int numDat = 0;
    for(; conjuntoDePedidos.enteros[numDat];numDat++);
    
    conjuntoDePedidos.reales = new double *[numDat + 1]{};
    for(int i = 0; conjuntoDePedidos.cadenas[i]; i++){
        numDat = contarDatosPedidos(conjuntoDePedidos.enteros[i]);
        conjuntoDePedidos.reales[i] = new double[numDat];
        buscarPrecios(conjuntoDePedidos.enteros[i], conjuntoDePedidos.reales[i],
                conjuntoDePedidos.cadenas[i], numDat, platos);
    }
    
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos, int) {
    ++conjuntoDePedidos;
}

void liberar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos) {

}

void operator!(ConjuntoDePedidos &conjuntoDePedidos) {
    
    ConjuntoDePlatos platos;
    cargar_conjunto_de_platos(platos, "platos.csv");
    
    int numDat = 0;
//    for(; conjuntoDePedidos.enteros[numDat];numDat++);
    
    for(int i = 0; conjuntoDePedidos.cadenas[i]; i++){
        numDat = contarDatosPedidos(conjuntoDePedidos.enteros[i]);
        cambiarCodANombre(conjuntoDePedidos.cadenas[i], platos, numDat);
    }
        
    
}

void operator*(const ConjuntoDePedidos &conjuntoDePedidos) {
    ofstream arch;
    int *pedido;
    char **pedidosCadena;
    char nombArch[50];
    for(int i = 0; conjuntoDePedidos.enteros[i];i++){
        pedido = conjuntoDePedidos.enteros[i];
        pedidosCadena = conjuntoDePedidos.cadenas[i];
        obtener_nombre_archivo(nombArch, pedido[0]);
        
        arch.open(nombArch, ios::out);
        arch << setprecision(2) << fixed;
        imprimir_linea(arch);
        arch << setw(3) << " " << "D.N.I. CLIENTE: " << pedido[0] << endl;
        arch << "CODIGO REPARTIDOR: " << pedidosCadena[0] << endl;
        imprimir_linea(arch);
        arch << "ITEM" << setw(8) << "PLATO" << setw(45) << "CANT" << setw(12)
                << "SUBTOTAL" << endl;
        imprimir_linea(arch, '-');
        imprimirDetalle(conjuntoDePedidos.enteros[i], 
                conjuntoDePedidos.cadenas[i],conjuntoDePedidos.reales[i], arch);
        arch.close();
    }
}

void obtener_nombre_archivo(char *nombre_archivo, int dni_numero) {
    char dni_cadena[9];
    mi_itoa(dni_numero, dni_cadena);
    strcpy(nombre_archivo, "comprobante/");
    strcat(nombre_archivo, dni_cadena);
    strcat(nombre_archivo, ".txt");
}

void imprimir_linea(ofstream &archDeReporte, char c) {
    for (int i = 0; i < MAXIMO_POR_LINEA; i++)
        archDeReporte << c;
    archDeReporte << endl;
}

int obtener_cantidad_cliente(const ConjuntoDePedidos &conjuntoDePedidos){
    int i=0;
    while (conjuntoDePedidos.enteros[i] != nullptr)
        i++;
    return i;
}


void modificarDatosConjunto(int *&enteros,  char **&cadenas, 
        const Pedido &pedido){
    
    enteros[1]++;
    int cantTipos = enteros[1];
    
    enteros[cantTipos + 1] = pedido.cantidad_platos;
    
    cadenas[cantTipos] = asignarCadena(pedido.codigo_plato);
    
}

void reservarEspacio(int *&enteros,  char **&cadenas, int espacios, 
        const Pedido &pedido){
    
    enteros = new int[espacios]{};
    enteros[0] = pedido.dni_cliente;
    enteros[1] = 1;
    enteros[2] = pedido.cantidad_platos;
    
    cadenas = new char *[espacios]{};
    cadenas[0] = asignarCadena(pedido.codigo_repartidor);
    cadenas[1] = asignarCadena(pedido.codigo_plato);
}

char  *asignarCadena(const char *codigo_repartidor){
    char *aux = new char [strlen(codigo_repartidor) + 1];
    strcpy(aux, codigo_repartidor);
    return aux;
}

void copiarEnteros(int *buffer, int *&enteros){
    
    int numDat = 0;
    for(; buffer[numDat]; numDat++);
    
    enteros = new int [numDat];
    
    for(int i = 0; i < numDat; i++)
        enteros[i] = buffer[i];
    
    delete buffer;
    
}

void copiarCadenas(char **buffer, char ** &cadenas){
    
    int numDat = 0;
    for(; buffer[numDat]; numDat++);
    
    cadenas = new char *[numDat];
    for(int i = 0; i < numDat; i++)
        cadenas[i] = buffer[i];
    delete buffer;
}

int contarDatosPedidos(int *enteros){
    
    return enteros[1] + 1;
    
}

void buscarPrecios(int *enteros, double *reales,char **cadenas, int numDat, 
        const  ConjuntoDePlatos &platos){
    double suma = 0, subtotal;
    for(int i = 1; i < numDat; i++){
        subtotal =  platos += cadenas[i];
        subtotal *= enteros[i + 1];
        suma += subtotal;
        reales[i] = subtotal;
    }
    reales[0] = suma;
}

void cambiarCodANombre(char **cadenas,const ConjuntoDePlatos &platos, int numDat){
    char *aux;
    for(int i = 1; i < numDat; i++){
        aux = platos == cadenas[i];
        delete cadenas[i];
        cadenas[i] = asignarCadena(aux);
    }
    
}

void imprimirDetalle(int *enteros,char **cadenas,double *reales, ofstream &arch){
    
    int numDat = enteros[1] + 1;
    double igv, total;
    for(int i = 1; i  < numDat; i++){
        arch << setw(2) << setfill('0') << i << setfill(' ') << ")" << setw(4) <<
                " " << left << setfill('.') << setw(45) << cadenas[i] << 
                right <<setw(4) << enteros[i + 1] << setfill(' ') <<setw(12) <<
                reales[i] << endl;
    }
    
    imprimir_linea(arch, '-');
    igv = reales[0] * 0.18;
    total = reales[0] + igv;
    arch << setw(60) << "SUBTOTAL: " << setw(8) << reales[0] << endl;
    arch << setw(60) << "I.G.V.: " << setw(8) <<  igv << endl;
    arch << setw(60) << "TOTAL: " << setw(8) << total << endl;
    imprimir_linea(arch);
    
}