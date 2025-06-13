/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Comanda.cpp
 * Author: YOSHI
 * 
 * Created on 12 de junio de 2025, 08:20
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
#include "Comanda.h"
#include "Restaurante.h"
#define MAX_NUM_LINEA 120

Comanda::Comanda() {
    estado = nullptr;
    cantidad_bebidas = 0;
    cantidad_entradas = 0;
    cantidad_platos_fondo = 0;
    tiempo_preparacion = 0;
}


Comanda::~Comanda() {
    if (estado!=nullptr) delete estado;
}

void Comanda::SetEstado(const char* cad) {
    if (estado!=nullptr) delete estado;
    estado = new char[strlen(cad)+1]{};
    strcpy(estado,cad);
}

void Comanda::GetEstado(char* cad) const {
    if (estado==nullptr) cad[0] = 0;
    else strcpy(cad,estado);
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

void Comanda::llenarDatos1(int id,int tempI,int tempF){
    SetId(id);
    SetHora_atencion(tempI);
    SetHora_servicio(tempF);
}

void Comanda::LeerProducto(ifstream &arch, char tipo){
    char nombre[100];
    double precio;
    arch.getline(nombre,100,',');
    arch>>precio;
    arch.get();
    switch(tipo){
        case 'P':
            int pro0, pro1, pro2, pro3;
            char c;
            arch>>pro0>>c>>pro1>>c>>pro2>>c>>pro3;
            platos_fondo[cantidad_platos_fondo].llenarDatos(nombre,precio,pro0,pro1,pro2,pro3);
            cantidad_platos_fondo++;
            break;
        case 'B':
            char tamano[12];
            arch.getline(tamano,12);
            bebudas[cantidad_bebidas].llenarDatos(nombre,precio,tamano);
            cantidad_bebidas++;
            break;
        case 'E':
            char picante[20];
            arch.getline(picante,20);
            entradas[cantidad_entradas].llenarDatos(nombre,precio,picante);
            cantidad_entradas++;
    }
}

void Comanda::imprimirComanda(ofstream &arch){
    arch<<"ID: "<<id<<setw(30)<<"Hora de atención: "<<hora_atencion/100<<":"<<
            hora_atencion%100<<setw(30)<<"Hora de servicio: "<<
            hora_servicio/100<<":"<<hora_servicio%100<<endl;
    imprimirLinea(arch,'-',MAX_NUM_LINEA);
    for (int i = 0; i < cantidad_entradas; i++){
        entradas[i].imprimir(arch);
    }
    for (int i = 0; i < cantidad_platos_fondo; i++){
        platos_fondo[i].imprimir(arch);
    }
    for (int i = 0; i < cantidad_bebidas; i++){
        bebudas[i].imprimir(arch);
    }
    imprimirLinea(arch,'-',MAX_NUM_LINEA);
    arch<<"TOTAL DE LA COMANDA: S/. "<<total<<endl;
    arch<<"TIEMPO DE PREPARACÖN: "<<tiempo_preparacion<<" minutos"<<endl;
    arch<<"ESTADO: ";
    if(estado!=nullptr)arch<<estado<<endl;
    else arch<<" "<<endl;
}

void Comanda::imprimirLinea(ofstream &arch,char c,int n){
    for (int i = 0; i < n; i++) arch.put(c);
    arch<<endl;
}

void Comanda::actualiza(){
    for (int i = 0; i < cantidad_entradas; i++) {
        total += entradas[i].GetPrecio();
        tiempo_preparacion += 15;
    }
    for (int i = 0; i < cantidad_platos_fondo; i++){
        total += platos_fondo[i].GetPrecio();
        tiempo_preparacion += 20;
    }
    for (int i = 0; i < cantidad_bebidas; i++){
        total += bebudas[i].GetPrecio();
        tiempo_preparacion += 10;
    }
    int hora = hora_atencion + tiempo_preparacion;
    if (hora%100 > 60) hora = ((hora/100)+1)*100 + hora%100 - 60;
    if (hora>hora_servicio) SetEstado("ATENDIDO CON RETRASO");
    else SetEstado("ATENDIDO");
}