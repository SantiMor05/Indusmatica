/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Producto.cpp
 * Author: santi
 * 
 * Created on 5 de junio de 2025, 14:52
 */

#include "Producto.h"
#include <cstring>

Producto::Producto() {
    inicializa();
}

//Producto::Producto(const Producto& orig) {
//}

Producto::~Producto() {
    if(codigo != nullptr)delete codigo;
    if(descripcion != nullptr) delete descripcion;
}

void Producto::SetCantidad_clientes_no_servidos(int cantidad_clientes_no_servidos) {
    this->cantidad_clientes_no_servidos = cantidad_clientes_no_servidos;
}

int Producto::GetCantidad_clientes_no_servidos() const {
    return cantidad_clientes_no_servidos;
}

void Producto::SetCantidad_clientes_servidos(int cantidad_clientes_servidos) {
    this->cantidad_clientes_servidos = cantidad_clientes_servidos;
}

int Producto::GetCantidad_clientes_servidos() const {
    return cantidad_clientes_servidos;
}

void Producto::SetStock(int stock) {
    this->stock = stock;
}

int Producto::GetStock() const {
    return stock;
}

void Producto::SetPrecio(double precio) {
    this->precio = precio;
}

double Producto::GetPrecio() const {
    return precio;
}

void Producto::SetDescripcion(char* des) {
    if(descripcion != nullptr) delete descripcion;
    descripcion = new char[strlen(des) + 1];
    strcpy(descripcion, des);
}

void Producto::GetDescripcion(char *buffer) const {
    if(descripcion == nullptr) buffer[0] = 0;
    else
        strcpy(buffer, descripcion);
}

void Producto::SetCodigo(char* cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Producto::GetCodigo(char *buffer) const {
    if(codigo == nullptr) buffer[0] = 0;
    else
        strcpy(buffer, codigo);
}

void Producto::inicializa(){
    cantidad_clientes_no_servidos = 0;
    cantidad_clientes_servidos = 0;
    codigo = nullptr;
    descripcion = nullptr;
}

bool operator >> (ifstream &arch, Producto &producto){
    char codigo[12], descripcion[60];
    double precio;
    int stock;
    
    arch.getline(codigo, 12, ',');
    if(arch.eof())return false;
    arch.getline(descripcion, 60, ',');
    arch >> precio;
    arch.get();
    arch >> stock;
    arch.get(); //Salto de linea
            
    producto.SetDescripcion(descripcion);
    producto.SetCodigo(codigo);
    producto.SetPrecio(precio);
    producto.SetStock(stock);
    return true;
    
}


bool Producto::operator +=(Pedido &pedido){
    
    int dni = pedido.GetDni_cliente();
    
    pedido.SetPrecio_producto(precio);
    
    if(cantidad_clientes_servidos < stock){
        clientes_servidos[cantidad_clientes_servidos] = dni;
        cantidad_clientes_servidos++;
        return true;
    }
    else{
        clientes_no_servidos[cantidad_clientes_no_servidos] = dni;
        cantidad_clientes_no_servidos++;
        return false;
    }
    
    
}