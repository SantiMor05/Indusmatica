/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehiculo.cpp
 * Author: santi
 * 
 * Created on 19 de junio de 2025, 14:22
 */

#include "Vehiculo.h"
#include <iomanip>
#include <cstring>

Vehiculo::Vehiculo() {
    inicializa();
}

//Vehiculo::Vehiculo(const Vehiculo& orig) {
//}

Vehiculo::~Vehiculo() {
}

void Vehiculo::SetActcarga(double actcarga) {
    this->actcarga = actcarga;
}

double Vehiculo::GetActcarga() const {
    return actcarga;
}

void Vehiculo::SetMaxcarga(double maxcarga) {
    this->maxcarga = maxcarga;
}

double Vehiculo::GetMaxcarga() const {
    return maxcarga;
}

void Vehiculo::SetPlaca(char* pl) {
    if(placa == nullptr) delete placa;
    placa =new char[strlen(pl) + 1];
    strcpy(placa, pl);
}

void Vehiculo::GetPlaca(char *buffer) const {
    if(placa == nullptr) buffer[0] = 0;
    else strcpy(buffer, placa);
}

void Vehiculo::SetCliente(int cliente) {
    this->cliente = cliente;
}

int Vehiculo::GetCliente() const {
    return cliente;
}

void Vehiculo::inicializa(){
    ped = nullptr;
    placa = nullptr;
    actcarga = 0;
}

void Vehiculo::lee(ifstream &arch){
    char car, pl[8];
    arch >> cliente;
    if(arch.eof())return;
    arch.get();
    arch.getline(pl, 8, ',');
    arch >> maxcarga;
    SetPlaca(pl);
}

void Vehiculo::imprime(ofstream &arch){
    
    arch << "Codigo Cliente:    " << cliente << endl;
    arch << "Placa: " << setw(20) << placa << endl;
    arch << "Carga Maxima: " << setw(13) << maxcarga << endl;
    arch << "Carga Actual: " << setw(13) << actcarga << endl;
    
}

void Vehiculo::imprimePedidos(ofstream &arch){
    NPedido *ptr;
    arch << "Pedidos: " << endl;
    
    if(pilaVacia()) 
        arch << setw(4) << " " <<  "No hay pedido para el cliente" << endl;
    else{
        ptr = ped;
        while(ptr != nullptr){
            ptr->imprimir(arch);
            ptr = ptr->sig;
        }
        
    }
}

bool Vehiculo::pilaVacia(){
    return ped == nullptr;
}

void Vehiculo::leePedido(ifstream &arch){
    NPedido pedido; 
    pedido.leerPedido(arch);
    push(pedido);        
 
}

void Vehiculo::push(NPedido &pedido){
    
    NPedido *nuevoNodo;
    if(actcarga + pedido.peso <= maxcarga){
        actcarga += pedido.peso;
        nuevoNodo = new NPedido;
        *nuevoNodo = pedido;
        
        nuevoNodo->sig = ped; 
        ped = nuevoNodo;//Como es pila, lo ingresamos en la cabeza
        
    }
    
}