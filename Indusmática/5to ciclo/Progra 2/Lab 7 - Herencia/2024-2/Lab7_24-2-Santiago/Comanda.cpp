/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Comanda.cpp
 * Author: santi
 * 
 * Created on 8 de junio de 2025, 19:54
 */

#include "Comanda.h"
#include <cstring>
#include <iomanip>

Comanda::Comanda() {
    inicializa();
}

//Comanda::Comanda(const Comanda& orig) {
//}

Comanda::~Comanda() {
    if(estado != nullptr)
        delete estado;
}

void Comanda::SetEstado(char* est) {
    if(estado != nullptr)delete estado;
    estado = new char[strlen(est) + 1];
    strcpy(estado, est);
}

void Comanda::GetEstado(char *buffer) const {
    if(estado == nullptr) buffer[0] = 0;
    else
        strcpy(buffer, estado);
}

void Comanda::SetTotal(double total) {
    this->total = total;
}

double Comanda::GetTotal() const {
    return total;
}

void Comanda::SetTiempo_preparacion(int tiempo_preparacion) {
    this->tiempo_preparacion = tiempo_preparacion;
}

int Comanda::GetTiempo_preparacion() const {
    return tiempo_preparacion;
}

void Comanda::SetHora_servicio(int hora_servicio) {
    this->hora_servicio = hora_servicio;
}

int Comanda::GetHora_servicio() const {
    return hora_servicio;
}

void Comanda::SetHora_atencion(int hora_atencion) {
    this->hora_atencion = hora_atencion;
}

int Comanda::GetHora_atencion() const {
    return hora_atencion;
}

void Comanda::SetCantidad_platos_fondo(int cantidad_platos_fondo) {
    this->cantidad_platos_fondo = cantidad_platos_fondo;
}

int Comanda::GetCantidad_platos_fondo() const {
    return cantidad_platos_fondo;
}

void Comanda::SetCantidad_entradas(int cantidad_entradas) {
    this->cantidad_entradas = cantidad_entradas;
}

int Comanda::GetCantidad_entradas() const {
    return cantidad_entradas;
}

void Comanda::SetCantidad_bebidas(int cantidad_bebidas) {
    this->cantidad_bebidas = cantidad_bebidas;
}

int Comanda::GetCantidad_bebidas() const {
    return cantidad_bebidas;
}

void Comanda::SetId(int id) {
    this->id = id;
}

int Comanda::GetId() const {
    return id;
}

void Comanda::inicializa(){
    cantidad_bebidas = 0;
    cantidad_entradas = 0;
    cantidad_platos_fondo = 0;
    estado = nullptr;
    total = 0;
    
}

void Comanda::leerDatos(ifstream &arch){
    int identificador, hh, min;
    char car;
    
    arch >> identificador;
    if(arch.eof())return;
    id = identificador;
    arch >> car >> hh >> car >> min >> car;
    
    SetHora_atencion(hh * 100 + min);
    arch >> hh >> car >> min;
    SetHora_servicio(hh * 100 + min);
        
    
}

void Comanda::agregarDatos(ifstream &arch){
    
    char tipo, car;
    
    arch >> tipo >> car;
    
    if(tipo == 'B'){
        bebidas[cantidad_bebidas].leerBebida(arch);
        cantidad_bebidas++;
    }
    else if(tipo == 'P'){
        platos_fondo[cantidad_platos_fondo].leerProteina(arch);
        cantidad_platos_fondo++;
    }
    else{
        entradas[cantidad_entradas].leerEntrada(arch);
        cantidad_entradas++;
    }
    
}

void Comanda::imprimirDatos(ofstream &arch){
    arch << "ID: " << id << setw(5) << " " << "Hora de atencion: ";
    imprimirHora(arch, hora_atencion);
    arch << setw(4) << " " << "Hora de servicio: ";
    imprimirHora(arch, hora_servicio);
    arch << setw(12) << "Total: " << total;
    if(estado != nullptr){
        arch << setw(5) << " " << estado;
    }
    
    arch <<endl;
    
    
    for(int i = 0; i < cantidad_bebidas; i++){
        if(i == 0) arch << "Bebidas: " << endl;
        arch << bebidas[i];
    }
    
    
    for(int i = 0; i < cantidad_entradas; i++){
        if(i == 0)arch << endl <<"Entradas: " << endl;
        arch << entradas[i];
    }
    
    
    for(int i = 0; i < cantidad_platos_fondo; i++){
        if(i == 0) arch << endl <<"Platos de Fondo: " << endl;
        arch << platos_fondo[i];
    }
}

void Comanda::imprimirHora(ofstream &arch, int hora){
    
    arch << setfill('0') << setw(2) << hora / 100 << ":" << setw(2) << 
            hora % 100 << setfill(' ');
    
}

void Comanda::actualizarComanda(){
    for(int i = 0; i < cantidad_bebidas; i++){
        total += bebidas[i].GetPrecio();
    }
    for(int i = 0; i < cantidad_entradas; i++){
        total += entradas[i].GetPrecio();
    }
    for(int i = 0; i < cantidad_platos_fondo; i++){
        total += platos_fondo[i].GetPrecio();
    }
}