/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: santi
 * 
 * Created on 5 de junio de 2025, 14:45
 */

#include "Cliente.h"
#include <cstring>

Cliente::Cliente() {
    inicializa();
}

//Cliente::Cliente(const Cliente& orig) {
//    inicializa();
//}

Cliente::~Cliente() {
    if(nombre != nullptr)delete nombre;
}

void Cliente::SetMonto_total(double monto_total) {
    this->monto_total = monto_total;
}

double Cliente::GetMonto_total() const {
    return monto_total;
}

void Cliente::SetCantidad_productos_entregados(int cantidad_productos_entregados) {
    this->cantidad_productos_entregados = cantidad_productos_entregados;
}

int Cliente::GetCantidad_productos_entregados() const {
    return cantidad_productos_entregados;
}

void Cliente::SetTelefono(int telefono) {
    this->telefono = telefono;
}

int Cliente::GetTelefono() const {
    return telefono;
}

void Cliente::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Cliente::GetNombre(char *buffer) const {
    if(nombre == nullptr) buffer[0] = 0;
    else
        strcpy(buffer, nombre);
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}


void Cliente::inicializa(){
    cantidad_productos_entregados = 0;
    monto_total = 0;
    nombre = nullptr;
}

//
//void Cliente::operator =(const Cliente &cli){
//    cantidad_productos_entregados = cli.GetCantidad_productos_entregados();
//    dni = cli.GetDni();
//    monto_total = cli.GetMonto_total();
//    telefono = cli.GetTelefono();
//    
//}

bool operator >> (ifstream &arch, Cliente &cliente){
    int dni, telefono;
    char nombre[100];
    
    arch >> dni;
    if(arch.eof())return false;
    cliente.SetDni(dni);
    arch.get();
    arch.getline(nombre, 100, ',');
    cliente.SetNombre(nombre);
    arch >> telefono;
    cliente.SetTelefono(telefono);
    return true;
}

void Cliente::operator += (const Pedido &pedido){
    
    double precio = pedido.GetPrecio_producto();
    char codigo[12];
    pedido.GetCodigo(codigo);
    
    
    productos_entregados[cantidad_productos_entregados].SetCodigo(codigo);
    productos_entregados[cantidad_productos_entregados].SetCodigo(precio);
    cantidad_productos_entregados++;
    monto_total += precio;
}