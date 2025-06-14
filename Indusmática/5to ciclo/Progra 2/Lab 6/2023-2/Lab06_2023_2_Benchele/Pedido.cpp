/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Pedido.cpp
 * Author: Lenovo
 * 
 * Created on 3 de junio de 2025, 08:11 PM
 */

#include <cstring>
#include "Pedido.h"
using namespace std;

Pedido::Pedido() {
    codigo = nullptr;
}

Pedido::Pedido(const Pedido &orig){
    codigo = nullptr;
    *this = orig;
}

Pedido::~Pedido() {
    if(codigo != nullptr)delete codigo;
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

void Pedido::SetCodigo(const char* cod) {
    if(codigo != nullptr)delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Pedido::GetCodigo(char *cod) const {
    if(codigo == nullptr)cod[0] = 0;
    else strcpy(cod, codigo);
}
void Pedido::operator =(const class Pedido &orig){
    char aux[40];
    orig.GetCodigo(aux);
    SetCodigo(aux);
    dni_cliente = orig.dni_cliente;
    precio_producto = orig.precio_producto;
    
}

/*
 JXD-139,50375303
 CRU-009,50375303
 CODPROPED DNICLIPED
 */
bool operator >>(ifstream &arch, class Pedido &pedido){
    char aux[10];
    int dni;
    arch.getline(aux, 10, ',');
    if(arch.eof())return false;
    pedido.SetCodigo(aux);
    arch>>dni;
    arch.get();
    pedido.SetDni_cliente(dni);
    return true;
}

