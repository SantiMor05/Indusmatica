/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Flota.cpp
 * Author: santi
 * 
 * Created on 26 de junio de 2025, 18:43
 */

#include "Flota.h"
#include "NVehiculo.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_CAR 50

Flota::Flota() {
}

Flota::Flota(const Flota& orig) {
}

Flota::~Flota() {
}

void Flota::cargaflota(){
    ifstream arch("Vehiculos.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo vehiculos" << endl;
        exit(1);
    }
    
    char tipo;
    NVehiculo vehiculo;
    while(true){
        arch >> tipo;
        if(arch.eof())break;
        arch.get();
        vehiculo.asignaTipo(tipo);
        vehiculo.lee(arch);
        vflota.push_back(vehiculo);
    }
    vehiculo.inicializa();
}

void Flota::muestracarga(){
    
    ofstream arch("Reporte.txt", ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo reporte" << endl;
        exit(1);
    }
    ordena();
    int cont = 0;
    for(auto &x : vflota){
        if(cont != 0)
            imprimirLinea(arch, '=');
        arch << cont + 1<< ")" << endl;
        x.imprime(arch);
        cont++;
    }
    
}

void Flota::imprimirLinea(ofstream &arch, char car){
    for(int i = 0; i < MAX_CAR; i++)
        arch.put(car);
    arch << endl;
}

void Flota::cargapedidos(){
    
    ifstream arch("Pedidos3.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archivo vehiculos" << endl;
        exit(1);
    }
    
    int cliente;
    NVehiculo *vehiculo;
    while(true){
        arch >> cliente;
        if(arch.eof())break;
        vehiculo = buscarCliente(cliente);
        arch.get();
        if(vehiculo != nullptr)
            vehiculo->cargadeposito(arch);
        else while(arch.get() != '\n');
    }
    
}

NVehiculo* Flota::buscarCliente(int cliente){
    
    for(auto &vehiculo : vflota){
        if(vehiculo.retornaCliente() == cliente)
            return &vehiculo;
    }
    return nullptr;
}


void Flota::ordena(){
    
    sort(vflota.begin(), vflota.end());
    
}