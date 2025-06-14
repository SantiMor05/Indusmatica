/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pedido.cpp
 * Author: santi
 * 
 * Created on 8 de junio de 2025, 23:43
 */

#include "Pedido.h"
#include <cstring>
#include <iomanip>

Pedido::Pedido() {
    inicializa();
}

//Pedido::Pedido(const Pedido& orig) {
//}

Pedido::~Pedido() {
    if(codigo != nullptr)
        delete codigo;
    if(estado != nullptr)
        delete estado;
}

void Pedido::SetTotal(double total) {
    this->total = total;
}

double Pedido::GetTotal() const {
    return total;
}

void Pedido::SetEstado(char* est) {
    if(estado != nullptr)delete estado;
    estado = new char[strlen(est) + 1];
    strcpy(estado, est);
}

void Pedido::GetEstado(char *buffer) const {
    if(estado == nullptr) buffer[0] = 0;
    else
        strcpy(buffer,estado);
}

void Pedido::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Pedido::GetFecha() const {
    return fecha;
}

void Pedido::SetSubtotal(double subtotal) {
    this->subtotal = subtotal;
}

double Pedido::GetSubtotal() const {
    return subtotal;
}

void Pedido::SetDni_cliente(int dni_cliente) {
    this->dni_cliente = dni_cliente;
}

int Pedido::GetDni_cliente() const {
    return dni_cliente;
}

void Pedido::SetCodigo(char* cod) {
    if(codigo != nullptr)delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Pedido::GetCodigo(char *buffer) const {
    if(codigo == nullptr) buffer[0] = 0;
    else
        strcpy(buffer,codigo);
}


void Pedido::inicializa(){
    codigo = nullptr;
    estado = nullptr;
    total = 0;
}

void Pedido::lee(ifstream &arch){
    int dd, mm, aa;
    char cod[10], car;
    arch.getline(cod,10,',');
    if(arch.eof())return;
    SetCodigo(cod);
    
    arch >> dni_cliente >> car >> subtotal >> car >> aa >> car >> mm >> car >>
            dd;
    
    fecha = aa * 10000 + mm * 100 + dd;
    
}

void Pedido::imprime(ofstream &arch){
    
    arch << codigo << setw(12) << dni_cliente << setw(8) << subtotal << setw(4)
            << " ";
    imprimirFecha(arch, fecha);
    arch << setw(4) << " ";
    if(estado != nullptr)
        arch << left << setw(12) << estado << right;
                
    arch << setw(8) << total;
}


void Pedido::imprimirFecha(ofstream &arch, int fecha){
    int aa, mm, dd;
    
    dd = fecha % 100;
    fecha /= 100;
    mm = fecha % 100;
    aa = fecha / 100;
    
    arch << setfill('0') << setw(4) << aa << "-" << setw(2) << mm << "-" <<
            setw(2) << dd << setfill(' ');
}


void Pedido::actualiza(){
    total += subtotal;
}