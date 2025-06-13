/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Comanda.cpp
 * Author: kenyi
 * 
 * Created on 12 de junio de 2025, 04:36 PM
 */

#include <cstring>
#include <iomanip>
using namespace std;

#include "Comanda.h"

Comanda::Comanda() {
    total = 0;
    cantidad_bebidas = 0;
    cantidad_entradas = 0;
    cantidad_platos_fondo = 0;
    estado = nullptr;
}

Comanda::~Comanda() {
    if (estado != nullptr)delete estado;
}

void Comanda::SetEstado(const char* est) {
    if (estado != nullptr)delete estado;
    estado = new char[strlen(est) + 1];
    strcpy(estado, est);
}

void Comanda::GetEstado(char*est) const {
    if (estado == nullptr)est[0] = 0;
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

void Comanda::llenarAten(int iden, int horaAten, int horaServ) {
    hora_atencion = horaAten;
    hora_servicio = horaServ;
    id = iden;
}

void Comanda::agregarComanda(ifstream& arch) {
    char tipo;
    arch >> tipo;
    arch.get();
    if (tipo == 'B') {
        bebidas[cantidad_bebidas].leerBeb(arch);
        cantidad_bebidas++;
    } else if (tipo == 'E') {
        entradas[cantidad_entradas].leerEnt(arch);
        cantidad_entradas++;
    } else {
        platos_fondo[cantidad_platos_fondo].leerPlat(arch);
        cantidad_platos_fondo++;
    }
}

void Comanda::imprimir(ofstream& arch) {
    imprimirLinea(arch, '=', 80);
    arch << "ID: " << id << " Hora de atencion: "
            << setw(2) << setfill('0') << hora_atencion / 100 << ":"
            << setw(2) << hora_atencion % 100 <<
            " Hora de servicio: " << setw(2) << hora_servicio / 100 << ":"
            << setw(2) << hora_servicio % 100 << setfill(' ') << endl;
    imprimirLinea(arch, '=', 80);
    arch << "Entradas: " << endl;
    if (cantidad_entradas == 0)arch << setw(6) << " " << "NO HAY" << endl;
    for (int i = 0; i < cantidad_entradas; i++) {
        arch << setw(6) << " ";
        entradas[i].imprimirEnt(arch);
    }
    arch << "Platos: " << endl;
    if (cantidad_platos_fondo == 0)arch << setw(6) << " " << "NO HAY" << endl;
    for (int i = 0; i < cantidad_platos_fondo; i++) {
        arch << setw(6) << " ";
        platos_fondo[i].imprimirPlat(arch);
    }
    arch << "Bebidas: " << endl;
    if (cantidad_bebidas == 0)arch << setw(6) << " " << "NO HAY" << endl;
    for (int i = 0; i < cantidad_bebidas; i++) {
        arch << setw(6) << " ";
        bebidas[i].imprimirBeb(arch);
    }
    imprimirLinea(arch, '-', 80);
    arch << "Total:                 " << total << endl;
    arch << "Tiempo de Preparacion: " << tiempo_preparacion << " minutos" << endl;
    arch << "Atencion:              " << estado << endl;
}

void Comanda::imprimirLinea(ofstream& arch, char c, int tam) {
    for (int i = 0; i < tam; i++)arch.put(c);
    arch << endl;
}

void Comanda::actulizar() {
    calcularTotal();
    
    if (validar())SetEstado("ATENDIDO");
    else SetEstado("ATENDIDO CON RETRASO");

}

void Comanda::calcularTotal() {
    for (int i = 0; i < cantidad_bebidas; i++) {
        total += bebidas[i].GetPrecio();
    }
    for (int i = 0; i < cantidad_entradas; i++) {
        total += entradas[i].GetPrecio();
    }
    for (int i = 0; i < cantidad_platos_fondo; i++) {
        total += platos_fondo[i].GetPrecio();
    }
}

bool Comanda::validar() {
    tiempo_preparacion = cantidad_bebidas * 10 +
            cantidad_entradas * 15 +
            cantidad_platos_fondo * 20;
    int tiempoAten = (hora_atencion / 100)*60 + hora_atencion % 100;
    int tiempoServ = (hora_servicio / 100)*60 + hora_servicio % 100;
    int tiempo_trans = tiempoServ - tiempoAten;
    if (tiempo_preparacion < tiempo_trans)return true;
    return false;
}


