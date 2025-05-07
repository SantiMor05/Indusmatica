/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaconRegistros.cpp
 * Author: santi
 * 
 * Created on 5 de mayo de 2025, 23:08
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "BibliotecaGenerica.h"
#include "ListaconRegistros.h"

using namespace std;



void* leeregistros(ifstream &arch){
    
    
    char *cod, *nombre, *vehiculo;
    void **registro;
    
    cod = leerCadenaExacta(arch, ',');
    if(cod == nullptr)return nullptr;
    nombre = leerCadenaExacta(arch, ',');
    vehiculo = leerCadenaExacta(arch, '\n');
    
    registro = new void *[3];
    registro[0] = cod;
    registro[1] = nombre;
    registro[2] = vehiculo;
    return registro;
}

char *leerCadenaExacta(ifstream &arch, char deli){
    
    char buffer[200],*cad;
    arch.getline(buffer, 200, deli);
    if(arch.eof())return nullptr;
    cad = new char[strlen(buffer) + 1];
    strcpy(cad, buffer);
    return cad;
    
}

void *leeOrdenes(ifstream &arch){
    
    int documento, *dni, *cant;
    char *plato, *repartidor, car;
    
    arch >> documento;
    if(arch.eof())return nullptr;
    
    dni = new int{documento};
    cant = new int;
    arch >> car >> *cant >> car;
    plato = leerCadenaExacta(arch, ',');
    repartidor = leerCadenaExacta(arch, '\n');
    
    void **dato = new void*[3];
    
    dato[0] = dni;
    dato[1] = cant;
    dato[2] = plato;
    
    void **registro = new void *[2];
    registro[0] = repartidor;
    registro[1] = dato;
    return registro;
}

int compruebaregistros(const void *dato, const void *repartidor){
    
    void **regRepartidor = (void **)repartidor;
    //void **regDato = (void **)dato;
    char *codigoRepartidor = (char *)dato;
    char *cod = (char *)regRepartidor[0];
    
    return strcmp(codigoRepartidor, cod);
    
}

void imprimeRegistro(const void*dupla, ofstream &arch){
    
    void **regDupla = (void **)dupla;
    void **repartidor = (void **)regDupla[0];
    char *cod,*nombre, *unidad;
    cod = (char *)repartidor[0];
    nombre = (char *)repartidor[1];
    unidad = (char *)repartidor[2];
    arch << left << setw(10) << cod << setw(40) << nombre << unidad << right
            << endl;
    imprimirOrdenes(regDupla[1], arch);
    arch << endl;
}

void imprimirOrdenes(void *ordenes, ofstream &arch){
    
    void **regOrdenes = (void **)ordenes;
    void **orden;
    int *dni, *cant;
    char *plato;
    for(int i = 0; regOrdenes[i]; i++){
        orden = (void **)regOrdenes[i];
        dni = (int *)orden[0];
        cant = (int *)orden[1];
        plato = (char *)orden[2];
        
        arch << *dni << setw(6) << *cant << setw(12) << plato << endl;
    }
    
}