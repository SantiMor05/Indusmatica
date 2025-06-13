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
    Pedido pedido;
    ConjuntoDePedidos buffConj;
    inicializar_buffer_de_conjunto_de_pedidos(buffConj,100);
    while(archivo_de_pedidos>>pedido)
        buffConj<<pedido;
    buffConj>>conjuntoDePedidos;
}

void inicializar_buffer_de_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, int cantidad) {
    conjuntoDePedidos.enteros = new int*[cantidad]{};
    conjuntoDePedidos.cadenas = new char**[cantidad]{}; 
    conjuntoDePedidos.reales = nullptr; 
    for (int i=0; i<cantidad; i++){
        conjuntoDePedidos.enteros[i] = nullptr;
        conjuntoDePedidos.cadenas[i] = nullptr;
    }
}

void llenar_cadenas(char **&cadenas, const Pedido &pedido){
    int nd = 0;
    while(cadenas[nd]) nd++;
    if (nd==0){
        cadenas[0] = new char[7]{};
        strcpy(cadenas[0],pedido.codigo_repartidor);
        cadenas[1] = new char[7]{};
        strcpy(cadenas[1],pedido.codigo_plato);
    }else{
        cadenas[nd] = new char[7]{};
        strcpy(cadenas[nd],pedido.codigo_plato);
    }
}

void llenar_enteros(int *&enteros, const Pedido &pedido){
    int nd = 0;
    while(enteros[nd]) nd++;
    if (nd==0){
        enteros[0] = pedido.dni_cliente;
        enteros[1] = 1;
        enteros[2] = pedido.cantidad_platos;
    }else{
        enteros[1]++;
        enteros[nd] = pedido.cantidad_platos;
    }
}

void operator<<(ConjuntoDePedidos &buffer_de_conjuntoDePedidos, const Pedido &pedido) {
    int pos = buscar_cliente(buffer_de_conjuntoDePedidos,pedido.dni_cliente);
    if (pos!=CLIENTE_NO_ENCONTRADO){
        llenar_enteros(buffer_de_conjuntoDePedidos.enteros[pos],pedido);
        llenar_cadenas(buffer_de_conjuntoDePedidos.cadenas[pos],pedido);
    }else{
        int nd=0;
        while(buffer_de_conjuntoDePedidos.enteros[nd]) nd++;
        buffer_de_conjuntoDePedidos.enteros[nd] = new int[12]{};
        buffer_de_conjuntoDePedidos.cadenas[nd] = new char*[12]{};
        llenar_enteros(buffer_de_conjuntoDePedidos.enteros[nd],pedido);
        llenar_cadenas(buffer_de_conjuntoDePedidos.cadenas[nd],pedido);
    }
}

void copiar_enteros(int *&enteros, int *buffEnteros){
    int nd = 0;
    while(buffEnteros[nd]) nd++;
    enteros = new int[nd+1]{};
    for (int i = 0; i < nd; i++)
        enteros[i] = buffEnteros[i];
}

void copiar_cadenas(char**&cadenas ,char**buffCadenas){
    int nd = 0;
    while(buffCadenas[nd]) nd++;
    cadenas = new char*[nd+1]{};
    for (int i = 0; i < nd; i++) {
        cadenas[i] = buffCadenas[i];
    }
}

void operator>>(const ConjuntoDePedidos &buffer_de_conjuntoDePedidos, ConjuntoDePedidos &conjuntoDePedidos) {
    int numDat=0;
    while(buffer_de_conjuntoDePedidos.enteros[numDat]) numDat++;
    conjuntoDePedidos.enteros = new int*[numDat+1]{};
    conjuntoDePedidos.cadenas = new char**[numDat+1]{};
    conjuntoDePedidos.reales = new double*[numDat+1]{};
    for (int i = 0; i<numDat; i++) {
        copiar_enteros(conjuntoDePedidos.enteros[i],buffer_de_conjuntoDePedidos.enteros[i]);
        copiar_cadenas(conjuntoDePedidos.cadenas[i],buffer_de_conjuntoDePedidos.cadenas[i]);
        conjuntoDePedidos.reales[i] = nullptr;
    }

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

void llenar_reales(double *&reales,int *&enteros, char **&cadenas, const ConjuntoDePlatos &platos){
    int nd = 0;
    while(enteros[nd]) nd++;
    reales = new double[nd]{};
    for (int i = 2; i < nd; i++) {
        reales[i-1] = (platos += cadenas[i-1])*enteros[i];
        reales[0] += (platos += cadenas[i-1])*enteros[i];
    }
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos) {
    ConjuntoDePlatos platos;
    cargar_conjunto_de_platos(platos,"platos.csv");
    for (int i = 0; conjuntoDePedidos.enteros[i]; i++) {
        llenar_reales(conjuntoDePedidos.reales[i],conjuntoDePedidos.enteros[i],
                conjuntoDePedidos.cadenas[i],platos);
    }
}

void operator++(ConjuntoDePedidos &conjuntoDePedidos, int) {
    ConjuntoDePlatos platos;
    cargar_conjunto_de_platos(platos,"platos.csv");
    for (int i = 0; conjuntoDePedidos.enteros[i]; i++) {
        llenar_reales(conjuntoDePedidos.reales[i],conjuntoDePedidos.enteros[i],
                conjuntoDePedidos.cadenas[i],platos);
    }
}

void liberar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos) {

}

void cambiar_nombre_cod(char **&cadenas, ConjuntoDePlatos &platos){
    for (int i = 1; cadenas[i]; i++) {
        char* nombrePla = platos == cadenas[i];
        delete cadenas[i];
        cadenas[i] = nombrePla;
    }
}

void operator!(ConjuntoDePedidos &conjuntoDePedidos) {
    ConjuntoDePlatos platos;
    cargar_conjunto_de_platos(platos,"platos.csv");
    for (int i = 0; conjuntoDePedidos.cadenas[i]; i++) {
        cambiar_nombre_cod(conjuntoDePedidos.cadenas[i],platos);
    }

}

void fabricar_archivo(const char *nombre_archivo,int *enteros,
                char **cadenas, double *reales){
    ofstream arch(nombre_archivo,ios::out);
    if (not arch.is_open()){
        cout<<"ERROR: No s epudo abrir el archivo "<<nombre_archivo<<endl;
        exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    imprimir_linea(arch,'=');
    arch<<"DNI CLIENTE: "<<enteros[0]<<endl;
    arch<<"CODIGO REPARTIDOR: "<<cadenas[0]<<endl;
    imprimir_linea(arch,'=');
    arch<<"ITEM PLATO"<<setw(45)<<"CANT"<<setw(10)<<"SUBTOTAL"<<endl;
    imprimir_linea(arch,'-');
    for (int i = 2; enteros[i]; i++) {
        arch<<setfill('0')<<setw(2)<<i-1<<setfill('.')<<"  "<<left<<setw(50)<<
                cadenas[i-1]<<setfill(' ')<<setw(2)<<enteros[i]<<right<<setw(8)<<
                reales[i-1]<<endl;
    }
    imprimir_linea(arch,'-');
    arch<<"SUBTOTAL: "<<setw(8)<<reales[0]<<endl;
    arch<<"IGV:      "<<setw(8)<<reales[0]*0.18<<endl;
    arch<<"TOTAL:    "<<setw(8)<<reales[0]*1.18<<endl;
    imprimir_linea(arch,'=');
}

void operator*(const ConjuntoDePedidos &conjuntoDePedidos) {
    char*nombre_archivo;
    int *enteros;
    for (int i = 0; conjuntoDePedidos.enteros[i]; i++) {
        enteros = conjuntoDePedidos.enteros[i];
        obtener_nombre_archivo(nombre_archivo,enteros[0]);
        fabricar_archivo(nombre_archivo,conjuntoDePedidos.enteros[i],
                conjuntoDePedidos.cadenas[i],conjuntoDePedidos.reales[i]);
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