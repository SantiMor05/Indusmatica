/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.cpp
 * Author: santi
 * 
 * Created on 5 de junio de 2025, 15:08
 */

#include "Almacen.h"

Almacen::Almacen() {
    inicializa();
}

//Almacen::Almacen(const Almacen& orig) {
//}

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


void Almacen::inicializa(){
    cantidad_clientes = 0;
    cantidad_productos = 0;
}
