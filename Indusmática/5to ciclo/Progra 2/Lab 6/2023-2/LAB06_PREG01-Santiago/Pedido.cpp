/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: santi
 * 
 * Created on 5 de junio de 2025, 15:00
 */

#include "Pedido.h"
#include <cstring>

Pedido::Pedido() {
    inicializa();
}

Pedido::Pedido(const Pedido& orig) {
    inicializa();
    *this = orig;
}

Pedido::~Pedido() {
}

void Pedido::SetPrecio_producto(double precio_producto) {
    this->precio_producto = precio_producto;
}

double Pedido::GetPrecio_producto() const {
    return precio_producto;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(char* cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Pedido::GetCodigo(char *buffer) const {
    if(codigo == nullptr) buffer[0] = 0;
    else
        strcpy(buffer, codigo);
}

void Pedido::inicializa(){
    codigo = nullptr;
}

void Pedido::operator =(const Pedido &pedido){
    
    char buffer[500];
    
    dni_cliente = pedido.GetDni_cliente();
    precio_producto = pedido.GetPrecio_producto();
    pedido.GetCodigo(buffer);
    SetCodigo(buffer);
}


bool operator >> (ifstream &arch, Pedido &pedido){
    
    char codigo[12];
    int dni;
    
    arch.getline(codigo, 12, ',');
    if(arch.eof())return false;
    arch >> dni;
    arch.get(); //Salto de linea
    
    
    pedido.SetCodigo(codigo);
    pedido.SetDni_cliente(dni);
    return true;
}