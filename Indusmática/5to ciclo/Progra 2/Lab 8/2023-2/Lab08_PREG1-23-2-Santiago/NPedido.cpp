/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPedido.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 14:17
 */

#include "NPedido.h"
#include <cstring>
#include <iomanip>

NPedido::NPedido() {
    inicializa();
}

//NPedido::NPedido(const NPedido& orig) {
//}

NPedido::~NPedido() {
    if(codigo != nullptr) delete codigo;
}

void NPedido::SetPeso(double peso) {
    this->peso = peso;
}

double NPedido::GetPeso() const {
    return peso;
}

void NPedido::SetCantidad(int cantidad) {
    this->cantidad = cantidad;
}

int NPedido::GetCantidad() const {
    return cantidad;
}

void NPedido::SetCodigo(char* cod) {
    if(codigo == nullptr) delete codigo;
    codigo =new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void NPedido::GetCodigo(char *buffer) const {
    if(codigo == nullptr) buffer[0] = 0;
    else
        strcpy(buffer, codigo);
}

void NPedido::inicializa(){
    codigo = nullptr;
    sig = nullptr;
}


void NPedido::leerPedido(ifstream &arch){
    
    char cod[10], car;
    
    arch.getline(cod, 10, ',');
    SetCodigo(cod);
    arch >> cantidad >> car >> peso;
    
}


void NPedido::operator =(const NPedido &orig){
    
    char cod[10];
    orig.GetCodigo(cod);
    SetCodigo(cod);
    cantidad = orig.cantidad;
    peso = orig.peso;
    sig = nullptr;
    
}

void NPedido::imprimir(ofstream &arch){
    
    arch << setw(4) << " " << codigo << setw(6) << cantidad << setw(8) <<
            peso << endl;
    
}