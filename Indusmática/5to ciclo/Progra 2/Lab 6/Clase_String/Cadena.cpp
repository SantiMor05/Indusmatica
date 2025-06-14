/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cadena.cpp
 * Author: santi
 * 
 * Created on 31 de mayo de 2025, 20:07
 */

#include "Cadena.h"
#include <cstring>
#include <memory>
#include <iostream>
#include <regex>

using namespace std;

Cadena::Cadena() {
    inicializa();
}

Cadena::Cadena(const Cadena& orig) {
    inicializa();
    *this = orig;
}

Cadena::Cadena(const char *cad){
    inicializa();
    setCadena(cad);
}

Cadena::Cadena(int n){
    
    longitud = 0;
    capacidad = n;
    cadena = new char[n];
    
}

Cadena::~Cadena() {
    
    delete cadena;
}

void Cadena::setCapacidad(int capacidad) {
    this->capacidad = capacidad;
}

int Cadena::getCapacidad() const {
    return capacidad;
}

void Cadena::setLongitud(int longitud) {
    this->longitud = longitud;
}

int Cadena::getLongitud() const {
    return longitud;
}

void Cadena::setCadena(const char* cad) {
    if(cadena == nullptr){
        longitud = strlen(cad);
        capacidad = longitud + 1;
        cadena = new char[capacidad]{};
    }
    else{
        delete cadena;
        if(longitud < strlen(cad)){
            longitud = strlen(cad);
            capacidad = longitud + 1;
            cadena = new char[capacidad]{};
        }
        else
            longitud = strlen(cad);
    }
    strcpy(cadena,cad);
}

void Cadena::getCadena(char *buffer) const {
    
    if(cadena == nullptr)
        buffer[0] = 0;
    else
        strcpy(buffer, cadena);
    
}

void Cadena::inicializa(){
    
    cadena = nullptr;
    longitud = 0;
    capacidad = 0;    
}

void Cadena::operator =(const Cadena& orig){
    
    char buffer[500];
    
//    longitud = orig.getLongitud();
//    capacidad = orig.getCapacidad();
    if(cadena != nullptr)delete cadena;
    orig.getCadena(buffer);
    setCadena(buffer);
    
}



void Cadena::assign(const char *cad){
    
    if(cadena == nullptr){
        longitud = strlen(cad);
        capacidad = longitud * 130 / 100;
        cadena = new char[capacidad]{};
    }
    else{
        delete cadena;
        if(longitud < strlen(cad)){
            longitud = strlen(cad);
            capacidad = longitud * 130 / 100;
            cadena = new char[capacidad]{};
        }
        else
            longitud = strlen(cad);
    }
    strcpy(cadena,cad);
    
}

void Cadena::assign(const Cadena &cad){
    
    char buffer[500];
    
    cad.getCadena(buffer);
    assign(buffer);
    
}

void Cadena::operator =(const char* cad){
    assign(cad);
}

void Cadena::append(const char *cad){
    
    char *aux;
    if(cadena == nullptr)
        assign(cad);
    
    else{
        longitud += strlen(cad);
        if(capacidad < longitud * 130 / 100){
            aux = new char[longitud * 130 / 100];
            strcpy(aux, cadena);
            delete cadena;
            strcat(aux, cad);
            cadena = aux;
        }
        else{
            strcat(cadena,cad);
        }
    }
    
}

void Cadena::append(const Cadena &cad){
    
    char buffer[500];
    
    cad.getCadena(buffer);
    
    append(buffer);
    
}

void  Cadena::swap(Cadena &cad){
    Cadena aux = cad;
    
    *this = aux;
    cad = *this;
    
}
Cadena Cadena::operator +(const Cadena &cad){
    
    Cadena aux = *this;
    aux.append(cad);
    return aux;
    
}

int Cadena::compare(const char *cad){
    
    int comparacion;
    
    if(cadena == nullptr)
        comparacion = -10;
    else
        comparacion = strcmp(cadena, cad);
    
    return comparacion;
    
}

int Cadena::compare(const Cadena &cad){
    
    char buffer[500];
    cad.getCadena(buffer);
    
    return compare(buffer);
    
}


bool Cadena::operator >(const Cadena &cad){
    
    int comparacion = compare(cad);
    if(comparacion > 0) return true;
    else return false;
}

bool Cadena::operator >=(const Cadena &cad){
    
    int comparacion = compare(cad);
    if(comparacion >= 0) return true;
    else return false;
}

bool Cadena::operator ==(const Cadena &cad){
    
    int comparacion = compare(cad);
    if(comparacion == 0) return true;
    else return false;
}

bool Cadena::operator <(const Cadena &cad){
    
    int comparacion = compare(cad);
    if(comparacion < 0) return true;
    else return false;
}

bool Cadena::operator <=(const Cadena &cad){
    
    int comparacion = compare(cad);
    if(comparacion <= 0) return true;
    else return false;
}


void Cadena::print(){
    cout << cadena << endl;
}

void operator >>(ifstream &arch, Cadena &cad){
    
    char buffer[500];
    arch >> buffer;
    if(!arch.eof())
        cad.append(buffer);
    
}