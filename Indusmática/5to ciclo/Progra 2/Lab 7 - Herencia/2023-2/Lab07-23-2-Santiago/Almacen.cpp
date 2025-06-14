/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Almacen.cpp
 * Author: santi
 * 
 * Created on 10 de junio de 2025, 22:38
 */

#include "Almacen.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

Almacen::Almacen() {
    inicializa();
}

Almacen::Almacen(const Almacen& orig) {
}

Almacen::~Almacen() {
}

void Almacen::inicializa(){
    cantidad_ordenes = 0;
}

void Almacen::cargar_pedidos(){
    ifstream arch("Pedidos.csv",ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo pedidos" << endl;
        exit(1);
    }
    char tipo;
    while(true){
        arch >> tipo;
        if(arch.eof())break;
        arch.get();
        
        if(tipo == 'B')
            ordenes[cantidad_ordenes].asignaPrioridadBaja();
        else if(tipo == 'M')
            ordenes[cantidad_ordenes].asignaPrioridadMedia();
        else ordenes[cantidad_ordenes].asignaPrioridadAlta();
        
        ordenes[cantidad_ordenes].lee(arch);    
        cantidad_ordenes++;
    }
    
}

void Almacen::imprimir_ordenes_venta(){
    
    ofstream arch("ReporteFinal.txt", ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo pedidos" << endl;
        exit(1);
    }
    
    arch << setprecision(2) << fixed;
    
    for(int i = 0; i < cantidad_ordenes; i++){
        ordenes[i].imprime(arch);
    }
    
}

void Almacen::actualizar_orden(){
    for(int i = 0; i < cantidad_ordenes; i++){
        ordenes[i].actualiza();
    }
}