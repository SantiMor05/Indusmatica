/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PrioridadMedia.cpp
 * Author: santi
 * 
 * Created on 8 de junio de 2025, 23:51
 */

#include "PrioridadMedia.h"
#include <cstring>
#include <iomanip>

PrioridadMedia::PrioridadMedia() {
    inicializa();
}

//PrioridadMedia::PrioridadMedia(const PrioridadMedia& orig) {
//}

PrioridadMedia::~PrioridadMedia() {
    if(descripcion != nullptr)
        delete descripcion;
}

void PrioridadMedia::SetNueva_fecha_entrega(int nueva_fecha_entrega) {
    this->nueva_fecha_entrega = nueva_fecha_entrega;
}

int PrioridadMedia::GetNueva_fecha_entrega() const {
    return nueva_fecha_entrega;
}

void PrioridadMedia::SetDescripcion(char* desc) {
    if(descripcion != nullptr)delete descripcion;
    descripcion = new char[strlen(desc) + 1];
    strcpy(descripcion, desc);
}

void PrioridadMedia::GetDescripcion(char *buffer) const {
    if(descripcion == nullptr) buffer[0] = 0;
    else
        strcpy(buffer, descripcion);
}

void PrioridadMedia::inicializa(){
    descripcion = nullptr;
    nueva_fecha_entrega = 0;
}

void PrioridadMedia::lee(ifstream &arch){
    
    int estado;
    char desc[12];
    
    Pedido::lee(arch);
    arch.get();
    arch >> estado;
    
    if(estado){
        strcpy(desc, "Activo");   
    }
    else strcpy(desc, "Inactivo");
    
    SetDescripcion(desc);
    
}

void PrioridadMedia::imprime(ofstream &arch){
    
    arch << "PRIORIDAD MEDIA:" << endl;
    Pedido::imprime(arch);
    
    
    arch << setw(4) << " ";
    imprimirFecha(arch, nueva_fecha_entrega);
    if(descripcion != nullptr)
        arch << setw(4) << " " << descripcion;
    arch << endl;
}

void PrioridadMedia::actualiza(){
    char estate[20];
    
    GetDescripcion(estate);
    
    Pedido::SetEstado(estate);
    
    nueva_fecha_entrega = GetFecha() + 1;
    Pedido::actualiza();
}