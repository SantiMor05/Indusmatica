/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Restaurante.cpp
 * Author: santi
 * 
 * Created on 8 de junio de 2025, 20:14
 */

#include "Restaurante.h"
#include <iomanip>
#include <iostream>
#include <fstream>
using namespace std;

#define NO_ENCONTRADO -1
#define MAX_CAR 120

Restaurante::Restaurante() {
    inicializa();
}

//Restaurante::Restaurante(const Restaurante& orig) {
//}

Restaurante::~Restaurante() {
}

void Restaurante::SetCantidad_comandas(int cantidad_comandas) {
    this->cantidad_comandas = cantidad_comandas;
}

int Restaurante::GetCantidad_comandas() const {
    return cantidad_comandas;
}

void Restaurante::inicializa(){
    cantidad_comandas = 0;
}

void Restaurante::cargar_comandas(){
    int id, pos;
    char tipo, car;
    ifstream arch("atenciones.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo atenciones" << endl;
        exit(1);
    }
    
    while(true){
        comandas[cantidad_comandas].leerDatos(arch);
        if(arch.eof())break;
        cantidad_comandas++;
    }
    
    arch.close();
    arch.open("comandas.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo comandas" << endl;
        exit(1);
    }
    
    while(true){
        arch >> id;
        if(arch.eof())break;
        arch.get();
        pos = buscarComanda(id);
        if(pos != NO_ENCONTRADO)
            comandas[pos].agregarDatos(arch);
            
    }
    
}

int Restaurante::buscarComanda(int ident){
    for(int i = 0; i < cantidad_comandas; i++){
        if(comandas[i].GetId() == ident)
            return i;
    }
    return NO_ENCONTRADO;
}

void Restaurante::imprimir_comandas(){
    
    ofstream arch("ReporteFinal.txt", ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo Reporte" << endl;
        exit(1);
    }
    
    arch << setprecision(2) << fixed;
    
    for(int i = 0; i < cantidad_comandas; i++){
        arch << i + 1 << ") ";
        comandas[i].imprimirDatos(arch);
        imprimirLinea(arch, '=');
    }
}

void Restaurante::imprimirLinea(ofstream &arch, char car){
    for(int i = 0; i < MAX_CAR; i++)
        arch.put(car);
    arch << endl;
}


void Restaurante::actualizar_comandas(){
    
    for(int i = 0; i < cantidad_comandas; i++)
        comandas[i].actualizarComanda();
    
}