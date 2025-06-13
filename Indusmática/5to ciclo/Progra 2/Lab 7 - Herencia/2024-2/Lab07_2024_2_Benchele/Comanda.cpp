/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.cc to edit this template
 */

/* 
 * File:   Comanda.cpp
 * Author: Lenovo
 * 
 * Created on 12 de junio de 2025, 05:22 PM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Comanda.h"
#define MAX_LINEA 120
using namespace std;

Comanda::Comanda() {
    inicializar();
}

Comanda::~Comanda() {
    if(estado != nullptr)delete estado;
}

void Comanda::SetEstado(const char* est) {
    if(estado != nullptr)delete estado;
    estado = new char[strlen(est) + 1];
    strcpy(estado, est);
}

void Comanda::GetEstado(char* est) const {
    if(estado == nullptr)est[0] = 0;
    else strcpy(est, estado);
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

void Comanda::inicializar(){
    estado = nullptr;
    cantidad_bebidas = 0;
    cantidad_entradas = 0;
    cantidad_platos_fondo = 0;
    tiempo_preparacion = 0;
    total = 0.0;
}


void Comanda::asignarDatos(int d, int horaAten, int horaServ){
    id = d;
    hora_atencion = horaAten;
    hora_servicio = horaServ;
}

void Comanda::actualizar(ifstream &arch){
    char tipo;
    arch>>tipo;
    arch.get();
    switch(tipo){
        case 'B':
            bebidas[cantidad_bebidas].leerDatos(arch);
            cantidad_bebidas++;
            break;
        case 'E':
            entreadas[cantidad_entradas].leerDatos(arch);
            cantidad_entradas++;
            break;
        case 'P':
            platos_fondo[cantidad_platos_fondo].leerDatos(arch);
            cantidad_platos_fondo++;
            break;
    }
}

void Comanda::actualizarDatos(){
    //Actualizar precios y el tiempo de preparacion
    for (int i = 0; i < cantidad_bebidas; i++) {
        total += bebidas[i].GetPrecio();
        tiempo_preparacion += 10; //Tiempo bebidas
    }
    for (int i = 0; i < cantidad_entradas; i++) {
        total += entreadas[i].GetPrecio();
        tiempo_preparacion += 15; //Tiempo Entradas
    }
    for (int i = 0; i < cantidad_platos_fondo; i++) {
        total += platos_fondo[i].GetPrecio();
        tiempo_preparacion += 20; //Tiempo Plato de fono
    }
    
    //Verificar si está atendido o no
    int tiempoPasado = hora_servicio - hora_atencion;
    
    if(tiempo_preparacion < tiempoPasado){
        SetEstado("ATENDIDO");
    }
    else{
        SetEstado("ATENDIDO CON RETRASO");
    }

}

void Comanda::mostrarResultados(ofstream &arch){
    
    imprimirLinea(arch, '=');
    
    arch<<"ID: "<<id<<setw(4)<<" "<<"Hora de atencion: ";
    imprimirHora(arch, 1);
    arch<<setw(4)<<" "<<"Hora de servicio: ";
    imprimirHora(arch, 2);
    arch<<endl;
    
    imprimirLinea(arch, '=');
    
    arch<<left<<setw(73)<<"Producto"<<setw(9)<<"Precio"<<"Descripcion"<<endl;
    imprimirLinea(arch, '-');
    
    arch<<"Bebidas: "<<endl;
    if (cantidad_bebidas != 0){
        for (int i = 0; i < cantidad_bebidas; i++) {
            arch<<setw(6)<<" ";
            bebidas[i].imprimir(arch);
        }
    }
    else{
        arch<<setw(12)<<" "<<"NO HAY BEBIDAS ATENDIDAS"<<endl;
    }
    
    arch<<"Entradas:"<<endl;
    if(cantidad_entradas != 0){
        for (int i = 0; i < cantidad_entradas; i++) {
            arch<<setw(6)<<" ";
            entreadas[i].imprimir(arch);
        }
    }
    else{
        arch<<setw(12)<<" "<<"NO HAY ENTRADAS ATENDIDAS"<<endl;
    }
    
    arch<<"Platos: "<<endl;
    if(cantidad_platos_fondo != 0){
        for (int i = 0; i < cantidad_platos_fondo; i++) {
            arch<<setw(6)<<" ";
            platos_fondo[i].imprimir(arch);
        }
    }
    else{
        arch<<setw(12)<<" "<<"NO HAY PLATOS DE FONO ATENDIDAS"<<endl;
    }
    
    imprimirLinea(arch, '-');
    arch<<left<<setw(36)<<"TOTAL COMANDA:"<<"S/."<<total<<endl;
    arch<<left<<setw(36)<<"TIEMPO DE PREPARACION:"<<tiempo_preparacion<<" minutos"<< endl;
    arch<<left<<setw(36)<<"ATENCION:"<<estado<<endl;
    
}
void Comanda::imprimirHora(ofstream &arch, int tipo){
    int hh, mm;
    if(tipo == 1){
        hh = hora_atencion/60;
        mm = hora_atencion - hh*60;
    }
    else{
        if(tipo == 2){
            hh = hora_servicio/60;
            mm = hora_servicio - hh*60;
        }
    }
    arch<<right<<setfill('0')<<setw(2)<<hh<<":"<<setw(2)<<mm<<setfill(' ');
}

void Comanda::imprimirLinea(ofstream &arch, char linea){
    for (int i = 0; i < MAX_LINEA; i++) arch.put(linea);
    arch<<endl;
}