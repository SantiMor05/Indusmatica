/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Almacen.cpp
 * Author: Lenovo
 * 
 * Created on 3 de junio de 2025, 08:11 PM
 */

#include <iostream>
#include <iomanip>
#include <cstring> 
#include "Almacen.h"
#define NO_ENCONTRADO -1
#define MAX_LINEA 120
using namespace std;

Almacen::Almacen() {
    cantidad_clientes = 0;
    cantidad_productos = 0;
}


Almacen::~Almacen() {
}

void Almacen::SetCantidad_productos(int cantidad_productos) {
    this->cantidad_productos = cantidad_productos;
}

int Almacen::GetCantidad_productos() const {
    return cantidad_productos;
}

void Almacen::SetCantidad_clientes(int cantidad_clientes) {
    this->cantidad_clientes = cantidad_clientes;
}

int Almacen::GetCantidad_clientes() const {
    return cantidad_clientes;
}

void Almacen::cargar_clientes(const char*nombArch){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Cliente cli;
    while (true) {
        if(!(arch>>cli))break;
        arreglo_clientes[cantidad_clientes] = cli;
        cantidad_clientes++;
    }

    
}
void Almacen::cargar_productos(const char*nombArch){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Producto pro;
    
    while (true) {
        if(!(arch>>pro))break; 
        arreglo_productos[cantidad_productos] = pro; 
        cantidad_productos++;
    }
    
}
void Almacen::cargar_pedidos(const char*nombArch){
    ifstream arch(nombArch, ios::in);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    class Pedido pedido;
    int posCLi, posPla;
    char cod[10];
    while (true) {
        if(!(arch>>pedido))break; 
        
        posCLi = buscarCliente(pedido.GetDni_cliente());
        
        pedido.GetCodigo(cod);
        posPla = buscarPlato(cod);
        if(posCLi != NO_ENCONTRADO and posPla != NO_ENCONTRADO){
            arreglo_productos[posPla]+=pedido; //Primero actualizar esto para conseguir el precio del producto
            arreglo_clientes[posCLi]+=pedido; 
        }
    }

    
}

int Almacen::buscarCliente(int dni){
    for (int i = 0; i < cantidad_clientes; i++) {
        if(dni == arreglo_clientes[i].GetDni())return i;
    }
    return NO_ENCONTRADO;

}
int Almacen::buscarPlato(char *cod){
    char codPla[10];
    for (int i = 0; i < cantidad_productos; i++) {
        arreglo_productos[i].GetCodigo(codPla);
        if(strcmp(cod, codPla) == 0)return i;
    }
    return NO_ENCONTRADO;
}

void Almacen::mostrar_datos(const char*nombArch){
    ofstream arch(nombArch, ios::out);
    if(not arch.is_open()){
        cout<<"ERROR: No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<fixed<<setprecision(2);
    
    //Impresion cliente
    arch<<setw((MAX_LINEA + 8)/2)<<"CLIENTES"<<endl;
    imprimirLinea(arch, '=');
    arch<<left<<setw(9)<<"DNI"<<setw(43)<<"Nombre"<<right<<setw(13)<<"Telefono"<<setw(11)<<"Monto"<<endl;
    imprimirLinea(arch, '=');
    for (int i = 0; i < cantidad_clientes; i++) {
        arch<<arreglo_clientes[i];
        arch<<endl;
    }
    arch<<endl;
    imprimirLinea(arch, '-');
    arch<<endl;
    
    //Impresion productos
    arch<<right<<setw((MAX_LINEA + 9)/2)<<"PRODUCTOS"<<endl;
    imprimirLinea(arch, '=');
    arch<<left<<setw(10)<<"Codigo"<<setw(50)<<"Descripcion"<<
            right<<setw(22)<<"Precio"<<setw(12)<<"Stock"<<endl;
    imprimirLinea(arch, '=');
    for (int i = 0; i < cantidad_productos; i++) {
        arch<<arreglo_productos[i];
        arch<<endl;
        imprimirLinea(arch, '-');
    }
}


void Almacen::imprimirLinea(ofstream &arch, char linea){
    for (int i = 0; i < MAX_LINEA; i++)arch.put(linea);
    arch<<endl;
}
