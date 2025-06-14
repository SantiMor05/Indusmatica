/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Plato.cpp
 * Author: santi
 * 
 * Created on 1 de junio de 2025, 13:21
 */

#include "Plato.h"
#include <cstring>
#include <iomanip>

Plato::Plato() {
    inicializa();
}

Plato::Plato(const Plato& orig) {
    inicializa(); //Colocar los punteroa a nullptr
    *this = orig;
}

Plato::~Plato() {
    if(nombre != nullptr)
        delete nombre;
    if(categoria != nullptr)
        delete categoria;
    if(codigo != nullptr)
        delete codigo;
}

void Plato::SetTotalNeto(double totalNeto) {
    this->totalNeto = totalNeto;
}

double Plato::GetTotalNeto() const {
    return totalNeto;
}

void Plato::SetTotalBruto(double totalBruto) {
    this->totalBruto = totalBruto;
}

double Plato::GetTotalBruto() const {
    return totalBruto;
}

void Plato::SetTotalEsparado(double totalEsparado) {
    this->totalEsparado = totalEsparado;
}

double Plato::GetTotalEsparado() const {
    return totalEsparado;
}

void Plato::SetNoAtendidos(int noAtendidos) {
    this->noAtendidos = noAtendidos;
}

int Plato::GetNoAtendidos() const {
    return noAtendidos;
}

void Plato::SetAtendidos(int atendidos) {
    this->atendidos = atendidos;
}

int Plato::GetAtendidos() const {
    return atendidos;
}

void Plato::SetDescuento(double descuento) {
    this->descuento = descuento;
}

double Plato::GetDescuento() const {
    return descuento;
}

void Plato::SetPreparados(int preparados) {
    this->preparados = preparados;
}

int Plato::GetPreparados() const {
    return preparados;
}

void Plato::SetCategoria(char* cat) {
    if(categoria != nullptr) delete categoria;
    categoria = new char[strlen(cat) + 1];
    strcpy(categoria, cat);
}

void Plato::GetCategoria(char *buffer) const {
    if(categoria == nullptr) buffer[0] = 0;
    else
        strcpy(buffer,categoria);
}

void Plato::SetPrecio(double precio) {
    this->precio = precio;
}

double Plato::GetPrecio() const {
    return precio;
}

void Plato::SetNombre(char* nomb) {
    if(nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1];
    strcpy(nombre, nomb);
}

void Plato::GetNombre(char *buffer) const {
    if(nombre == nullptr) buffer[0] = 0;
    else
        strcpy(buffer,nombre);
}

void Plato::SetCodigo(char* cod) {
    if(codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod) + 1];
    strcpy(codigo, cod);
}

void Plato::GetCodigo(char *buffer) const {
    if(codigo == nullptr) buffer[0] = 0;
    else
        strcpy(buffer,codigo);
}

void Plato::inicializa(){
    
    codigo = nullptr;
    nombre = nullptr;
    categoria = nullptr;
    preparados = 0;
    descuento = 0;
    atendidos = 0;
    noAtendidos = 0;
    totalEsparado = 0;
    totalBruto = 0;
    totalNeto = 0;
    
}


void Plato::operator = (const Plato &plato){
    
    char buffer[500];
    plato.GetCodigo(buffer);
    SetCodigo(buffer);
    
    plato.GetCategoria(buffer);
    SetCategoria(buffer);
    
    plato.GetNombre(buffer);
    SetNombre(buffer);
    
    precio = plato.GetPrecio();
    preparados = plato.GetPreparados();
    descuento = plato.GetDescuento();
    atendidos = plato.GetAtendidos();
    noAtendidos = plato.GetNoAtendidos();
    totalEsparado = plato.GetTotalEsparado(); 
    totalBruto = plato.GetTotalBruto();
    totalNeto = plato.GetTotalNeto();
    
}


void operator >> (ifstream &arch, Plato &plato){
    
    char buffer[500], car;
    double precio, descuento;
    int cant_platos;
    
    arch.getline(buffer, 500, ',');
    if(arch.eof())return;
    plato.SetCodigo(buffer);
    
    arch.getline(buffer, 500, ',');
    plato.SetNombre(buffer);
    
    arch >> precio >> car;
    plato.SetPrecio(precio);
    arch.getline(buffer, 500, ',');
    plato.SetCategoria(buffer);
    
    arch >> cant_platos;
    plato.SetPreparados(cant_platos);
    if(arch.get() == ','){
        arch >> descuento >> car;
        plato.SetDescuento(descuento);
    }
    arch.get();
}


void operator << (ofstream &arch, Plato &plato){
    
    char buffer[500];
    
    plato.GetCodigo(buffer);
    arch << left << setw(12) << buffer;
    plato.GetNombre(buffer);
    arch << setw(50) << buffer << right << setw(6) << plato.GetPrecio() << 
            setw(3) << " " << left << setw(12);
    plato.GetCategoria(buffer);
    arch << buffer << right << setw(6) << plato.GetPreparados() << setw(8) <<
            plato.GetDescuento() << "%" << setw(8) << plato.GetAtendidos() <<
            plato.GetNoAtendidos() << setw(12) << plato.GetTotalEsparado() <<
            setw(10) << plato.GetTotalBruto() << setw(10) << 
            plato.GetTotalNeto() << endl;
}