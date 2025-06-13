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

using namespace std;

void cargar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos, const char *nombre_de_archivo) {
    ifstream archivo_de_pedidos;
    AperturaDeUnArchivoDeTextosParaLeer(archivo_de_pedidos, nombre_de_archivo);
    archivo_de_pedidos >> conjuntoDePedidos;
    archivo_de_pedidos.close();
}

//12484697 AD-546 2 LAF361
void operator>>(istream &arch, ConjuntoDePedidos &pedidos) {
    
    Pedido pedido;
    ConjuntoDePedidos bufPedidos;
    inicializar_buffer_de_conjunto_de_pedidos(bufPedidos,200);
    while(true){
        if(arch>>pedido){
            bufPedidos<<pedido;
        }
        else break;
    }
    for (int i = 0; bufPedidos.enteros[i]; i++) {
        hacerExacto(bufPedidos.enteros[i],bufPedidos.cadenas[i]);
    }    
    bufPedidos>>pedidos;
}

void hacerExacto(int*&entero,char**&cadena){
    
    int ndEntero=entero[1]+2;
    int ndCadena=ndEntero-1;
    int*auxEntero=new int[ndEntero]{};
    char**auxCadena=new char*[ndCadena]{};
    
    for (int i = 0; i < ndCadena; i++) {
        auxEntero[i]=entero[i];
        auxCadena[i]=cadena[i];
    }
    auxEntero[ndCadena]=entero[ndCadena];
    delete entero;
    delete cadena;
    entero=auxEntero;
    cadena=auxCadena;

}


void inicializar_buffer_de_conjunto_de_pedidos(
    ConjuntoDePedidos &conjuntoDePedidos,int cantidad) {
    
    conjuntoDePedidos.enteros = new int*[cantidad];
    conjuntoDePedidos.cadenas = new char**[cantidad]; 
    conjuntoDePedidos.reales = nullptr; 
    for (int i=0; i<cantidad; i++){
        conjuntoDePedidos.enteros[i] = nullptr;
        conjuntoDePedidos.cadenas[i] = nullptr;
    }
}

//12484697 AD-546 2 LAF361

void operator<<(ConjuntoDePedidos &bufPedidos, const Pedido &pedido) {
    
    int pos=buscar_cliente(bufPedidos,pedido.dni_cliente);
    int nd=obtener_cantidad_cliente(bufPedidos);
    if(pos!=CLIENTE_NO_ENCONTRADO){
        actualizarPedido(bufPedidos,pos,pedido);
    }
    else{
        crearPedido(bufPedidos,nd,pedido);
    }
}

void actualizarPedido(ConjuntoDePedidos &bufPedidos,int pos,
        const Pedido &pedido){
    
    int*entero=bufPedidos.enteros[pos],i;
    char**cadena=bufPedidos.cadenas[pos];
    bool esRepetido=false;
    
    for (i = 1; cadena[i]; i++) {
        if(not strcmp(cadena[i],pedido.codigo_plato)){
            esRepetido=true;
            break;
        }
    }
    if(esRepetido) entero[i+1]+=pedido.cantidad_platos;
    else{
        cadena[i]=new char[7];
        strcpy(cadena[i],pedido.codigo_plato); 
        entero[1]++;
        entero[i+1]=pedido.cantidad_platos;
    }
}


//12484697 AD-546 2 LAF361
void crearPedido(ConjuntoDePedidos &bufPedidos,int nd,const Pedido &pedido){
//    
    bufPedidos.enteros[nd]=new int[102]{};
    bufPedidos.cadenas[nd]=new char*[102]{};
//    bufPedidos.reales[nd]=new double[102]{};
    
    int*entero=bufPedidos.enteros[nd];
    char**cadena=bufPedidos.cadenas[nd];
//    double*real=bufPedidos.reales[nd];
    
    entero[0]=pedido.dni_cliente;
    entero[1]=1;
    entero[2]=pedido.cantidad_platos;
    
    cadena[0]=new char[7];
    cadena[1]=new char[7];
    strcpy(cadena[0],pedido.codigo_repartidor);
    strcpy(cadena[1],pedido.codigo_plato);
    
}


void operator>>(const ConjuntoDePedidos &bufPedidos,
        ConjuntoDePedidos &pedidos) {
    
    int nd=obtener_cantidad_cliente(bufPedidos)+1;
    inicializar_buffer_de_conjunto_de_pedidos(pedidos,nd);
    for (int i = 0; i < nd; i++) {
        pedidos.enteros[i]=bufPedidos.enteros[i];
        pedidos.cadenas[i]=bufPedidos.cadenas[i];
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

void operator++(ConjuntoDePedidos &conjuntoDePedidos) {
    
    ConjuntoDePlatos platos;
    cargar_conjunto_de_platos(platos,"platos.csv");
    
    int nd=obtener_cantidad_cliente(conjuntoDePedidos)+1;
    conjuntoDePedidos.reales=new double*[nd]{};
    
    for (int i = 0; conjuntoDePedidos.enteros[i]; i++) {
        hallarPrecio(conjuntoDePedidos.enteros[i],conjuntoDePedidos.cadenas[i],
                conjuntoDePedidos.reales[i],platos);
    }
}

void hallarPrecio(int*entero,char**cadena,double*&real,
        const ConjuntoDePlatos &platos){
    
    int ndEntero=entero[1]+2;
    int ndCadena=entero[1]+1,cant;
    
    real=new double[ndCadena]{};
    double subTotal=0,precio,ingreso;
    for (int i = 1; i < ndCadena; i++) {
        precio=platos+=cadena[i];
        cant=entero[i+1];
        ingreso=precio*cant;
        subTotal+=ingreso;
        real[i]=ingreso;
    }
    real[0]=subTotal;
}


void operator++(ConjuntoDePedidos &conjuntoDePedidos, int) {
 
    ConjuntoDePlatos platos;
    cargar_conjunto_de_platos(platos,"platos.csv");
    
    int nd=obtener_cantidad_cliente(conjuntoDePedidos)+1;
    conjuntoDePedidos.reales=new double*[nd]{};
    
    for (int i = 0; conjuntoDePedidos.enteros[i]; i++) {
        hallarPrecio(conjuntoDePedidos.enteros[i],conjuntoDePedidos.cadenas[i],
                conjuntoDePedidos.reales[i],platos);
    }
}

void liberar_conjunto_de_pedidos(ConjuntoDePedidos &conjuntoDePedidos) {

}

void operator!(ConjuntoDePedidos &pedidos) {
    
    ConjuntoDePlatos platos;
    cargar_conjunto_de_platos(platos,"platos.csv");
    
    for (int i = 0; pedidos.cadenas[i]; i++) {
        cambiarCadena(pedidos.cadenas[i],pedidos.enteros[i],platos);
    }
}

void cambiarCadena(char**cadena,int*entero,
        const ConjuntoDePlatos &platos){
    
    int nd=entero[1]+1;
    char*nombre;
    for (int i = 1; i < nd; i++) {
        nombre=platos==cadena[i];
        if(nombre){
            cadena[i]=copiarCadena(nombre);
        }
    }
}

char*copiarCadena(const char*nombre){
    
    char *p;
    p=new char[strlen(nombre)+1];
    strcpy(p,nombre);
    return p;
}


void operator*(const ConjuntoDePedidos &pedidos) {
    
    for (int i = 0; pedidos.enteros[i]; i++) {
        hacerArchivo(pedidos.enteros[i],pedidos.cadenas[i],
                pedidos.reales[i]);
    }    
}

void hacerArchivo(int*entero,char**cadena,double*real){
    
    char nombArch[50]{};
    obtener_nombre_archivo(nombArch,entero[0]);
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"Error en "<<nombArch; exit(1);
    }
    arch.precision(2);
    arch<<fixed;
    imprimir_linea(arch);
    arch<<"   DNI CLIENTE: "<<entero[0]<<endl;
    arch<<"CODIGO REPARTIDOR: "<<cadena[0]<<endl;
    imprimir_linea(arch);
    arch<<left<<setw(62)<<"ITEM PLATO"<<"CANT SUBTOTAL"<<endl;
    imprimir_linea(arch,'-');
    int nd=entero[1]+1;
    for (int i = 1; i < nd; i++) {
        imprimePlato(arch,i,cadena[i],real[i],entero[i+1]);
    }
    imprimir_linea(arch,'-');
    arch<<right<<setw(65)<<"SUBTOTAL: "<<real[0]<<endl;
    arch<<right<<setw(65)<<"I.G.V: "<<27.52<<endl;
    arch<<right<<setw(65)<<"TOTAL: "<<real[0]-27.52<<endl;
    imprimir_linea(arch);
}

void imprimePlato(ofstream &arch,int i,char*nombre,
        double subtotal,int cant){
    
    arch<<"  "<<setfill('0')<<right<<setw(2)<<i+1<<" "<<left<<
            setfill('.')<<setw(60)<<nombre<<cant<<" "<<right<<
            setfill(' ')<<setw(5)<<subtotal<<endl;    
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