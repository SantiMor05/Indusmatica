/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cadena.cpp
 * Author: 00123
 * 
 * Created on 1 de junio de 2025, 11:24 AM
 */

#include <iostream>
#include <iomanip>
#include <cstring>
#include <codecvt>
#include "Cadena.h"
using namespace std;

Cadena::Cadena(int capa) {
    
    contenedor=nullptr;
    longitud=0;
    capacidad=capa;
}
Cadena::Cadena(const char*cad){
    
    int n=strlen(cad);
    contenedor=new char[n+1];
    strcpy(contenedor,cad);
    longitud=n;
    capacidad=n+1;
}

void Cadena::operator=(const Cadena& cad) {

    if(contenedor)delete contenedor;
    int n=cad.longitud;
    contenedor=new char[n+1];
    strcpy(contenedor,cad.contenedor);
    longitud=n;
    capacidad=cad.capacidad;
}

void Cadena::assign(const char* cad) {

    int n=strlen(cad);
    if(capacidad>=n+1){
        strcpy(contenedor,cad);
    }
    else{
        if(contenedor)delete contenedor;
        capacidad=1.3*n;
        contenedor=new char[capacidad];
        strcpy(contenedor,cad);
    }
    longitud=n;
}

void Cadena::assign(const Cadena& cad){
    
    assign(cad.contenedor);
}


void Cadena::operator=(const char*cad) {

    assign(cad);
}

void Cadena::append(const char* cad) {

    char aux[60]{};
    if(contenedor){
        strcpy(aux,contenedor);
    }
    strcat(aux,cad);
    assign(aux);
}

void Cadena::append(const Cadena& cad){
    
    append(cad.contenedor);
}


void Cadena::swap(Cadena& cad) {

    Cadena aux=cad;
    cad=*this;
    *this=aux;    
}

int Cadena::length() {

    return longitud;
}

void Cadena::print() {

    if(contenedor)cout<<"Cadena: "<<contenedor<<endl;
//    cout<<"Longitud: "<<longitud<<endl;
//    cout<<"Capacidad: "<<capacidad<<endl;
}



Cadena::Cadena(const Cadena& orig) {
    this->contenedor=nullptr;
    *this=orig;
}

Cadena::~Cadena() {
    
    if(contenedor)delete contenedor;
}

//AAAAAAAAAAAAAAAAAAAAAAAAA
Cadena Cadena::operator+(const Cadena& cad) {

    Cadena aux;
    aux.contenedor=nullptr;
    aux.append(*this);
    aux.append(cad);
//    return aux;
    return aux;
}

int Cadena::compare(const char* cad) {

    return strcmp(contenedor,cad);
}

int Cadena::compare(const Cadena& cad) {

    return strcmp(contenedor,cad.contenedor);
}

bool Cadena::operator<(const Cadena& cad) {

    return strcmp(contenedor,cad.contenedor)<0;
}

bool Cadena::operator<=(const Cadena& cad) {

    return strcmp(contenedor,cad.contenedor)<=0;
}

bool Cadena::operator==(const Cadena& cad) {

    return strcmp(contenedor,cad.contenedor)==0;
}

bool Cadena::operator>(const Cadena& cad) {

    return strcmp(contenedor,cad.contenedor)>0;
}

bool Cadena::operator>=(const Cadena& cad) {

    return strcmp(contenedor,cad.contenedor)>=0;
}

