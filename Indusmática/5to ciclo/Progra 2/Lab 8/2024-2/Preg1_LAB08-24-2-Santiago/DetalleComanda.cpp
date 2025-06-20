/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DetalleComanda.cpp
 * Author: santi
 * 
 * Created on 18 de junio de 2025, 10:58
 */

#include "DetalleComanda.h"
#include "Bebida.h"
#include "PlatoFondo.h"
#include "Entrada.h"

DetalleComanda::DetalleComanda() {
    inicializa();
}

DetalleComanda::DetalleComanda(const DetalleComanda& orig) {
    inicializa();
    *this = orig;
}

DetalleComanda::~DetalleComanda() {
    if(pedido != nullptr)delete pedido;
}

void DetalleComanda::SetId(int id) {
    this->id = id;
}

int DetalleComanda::GetId() const {
    return id;
}

void DetalleComanda::inicializa(){
    pedido = nullptr;
}


void DetalleComanda::operator =(const DetalleComanda& orig){
    id = orig.id;
//    if(pedido!= nullptr) 
//        delete pedido;
//    
//    pedido = new Producto(); //En duda
//        
//    *pedido = *(orig.pedido);
    
    pedido = orig.pedido; //No colocamos  destructor para que no destruya 
}

void DetalleComanda::leerComanda(ifstream &arch){
    
    int identi;
    char tipo, car;
    
    arch >> identi;
    if(arch.eof())return;
    arch >> car >> tipo >> car;
    
    id = identi;
    if(tipo == 'B')
        pedido = new Bebida;
    else if(tipo == 'E')
        pedido = new Entrada;
    else
        pedido = new PlatoFondo;
    
    pedido->leerDatos(arch);
}

void DetalleComanda::imprimirDatos(ofstream &arch){
    arch << "Codigo de comanda: " << id << endl;
    pedido->imprimirDatos(arch);
}