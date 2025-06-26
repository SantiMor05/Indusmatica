/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Falta.cpp
 * Author: 00123
 * 
 * Created on 26 de junio de 2025, 03:24 PM
 */
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
#include "Falta.h"

//Falta::Falta() {
//}
//
//Falta::Falta(const Falta& orig) {
//}
//
//Falta::~Falta() {
//}

void Falta::SetDronPolicia(string dronPolicia) {
    this->dronPolicia = dronPolicia;
}

string Falta::GetDronPolicia() const {
    return dronPolicia;
}

void Falta::SetFecha(int fecha) {
    this->fecha = fecha;
}

int Falta::GetFecha() const {
    return fecha;
}

void Falta::leer(ifstream&arch) {

    int dd,mm,aa;
    char c;
    
    getline(arch,dronPolicia,',');
    arch>>dd>>c>>mm>>c>>aa;
    arch.get();
    fecha=aa*10000+mm*100+dd;
}

void Falta::imprimir(ofstream& arch) {

    int dd,mm,aa,fec;
    fec=fecha;
    aa=fec%100;
    fec/=100;
    mm=fec%100;
    dd=fec/100;
    
    arch<<"      "<<"Dron: "<<dronPolicia<<"  Fecha: "<<
            right<<setfill('0')<<setw(2)<<dd<<"/"<<setw(2)<<mm<<
            "/"<<aa<<endl<<setfill(' ');
}
