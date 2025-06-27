/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NPedido.cpp
 * Author: santi
 * 
 * Created on 26 de junio de 2025, 18:33
 */

#include "NPedido.h"
#include <iomanip>

NPedido::NPedido() {
}

//NPedido::NPedido(const NPedido& orig) {
//}

NPedido::~NPedido() {
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

void NPedido::SetCodigo(string codigo) {
    this->codigo = codigo;
}

string NPedido::GetCodigo() const {
    return codigo;
}

void NPedido::lee(ifstream &arch){
    char car;
    getline(arch, codigo, ',');
    arch >> cantidad >> car >> peso;
}

void NPedido::imprime(ofstream &arch){
    
    arch << setw(3) << " "  << codigo << setw(5) << cantidad << setw(8) <<
            peso << endl;
    
}