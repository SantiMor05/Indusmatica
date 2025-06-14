/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: santi
 * 
 * Created on 1 de junio de 2025, 13:20
 */

#include "Cliente.h"
#include <cstring>
#include <iomanip>

Cliente::Cliente() {
    inicializa();
}

Cliente::Cliente(const Cliente& orig) {
    inicializa();
    *this = orig;
}

Cliente::~Cliente() {
    if(nombre != nullptr)
        delete nombre;
    if(distrito != nullptr)
        delete distrito;
}

void Cliente::SetTotalPagado(double totalPagado) {
    this->totalPagado = totalPagado;
}

double Cliente::GetTotalPagado() const {
    return totalPagado;
}

void Cliente::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Cliente::GetDescuento() const {
    return descuento;
}

void Cliente::SetDistrito(char* dist) {
    if(distrito != nullptr) delete distrito;
    distrito = new char [strlen(dist) + 1];
    strcpy(distrito, dist);
}

void Cliente::GetDistrito(char *buffer) const {
    if(distrito == nullptr) buffer[0] = 0;
    else{
        strcpy(buffer, distrito);
    }
}

void Cliente::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char [strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Cliente::GetNombre(char *buffer) const {
    if(nombre == nullptr) buffer[0] = 0;
    else{
        strcpy(buffer, nombre);
    }
}

void Cliente::SetDni(int dni) {
    this->dni = dni;
}

int Cliente::GetDni() const {
    return dni;
}

void Cliente::inicializa(){
    
    nombre = nullptr;
    distrito = nullptr;
    descuento = 0;
    totalPagado = 0;
    
}

void Cliente::operator =(const Cliente &cli){
    char buffer[500];
    dni = cli.dni;
    
    cli.GetDistrito(buffer);
    SetDistrito(buffer);
    
    cli.GetNombre(buffer);
    SetNombre(buffer);
    
    descuento = cli.GetDescuento();
    totalPagado = cli.GetTotalPagado();
    
}


void operator >> (ifstream &arch, Cliente &cli){
    
    int dni;
    char descuento, car, buffer[400];
    double porcentaje;
    arch >> dni;
    if(arch.eof())return;
    cli.SetDni(dni);
    
    arch.get();
    arch.getline(buffer, 400,',');
    cli.SetNombre(buffer);
    arch.getline(buffer,400,',');
    cli.SetDistrito(buffer);
    arch >> descuento;
    if(descuento == 'S'){
        arch >> car >> porcentaje >> car;
        cli.SetDescuento(porcentaje);
    }
}

void operator << (ofstream &arch, Cliente &cli){
    
    char buffer[500];
    arch << setprecision(2) << fixed;
    
    arch << cli.GetDni() << setw(3) << " ";
    cli.GetNombre(buffer);
    arch << left << setw(40) << buffer;
    cli.GetDistrito(buffer);
    arch << setw(30) << buffer << right << setw(5) << cli.GetDescuento() << "%" 
            <<  setw(8) << cli.GetTotalPagado() << endl;
    
}