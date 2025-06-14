/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tesoreria.cpp
 * Author: santi
 * 
 * Created on 11 de junio de 2025, 23:30
 */

#include "Tesoreria.h"
#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

Tesoreria::Tesoreria() {
}

//Tesoreria::Tesoreria(const Tesoreria& orig) {
//}

Tesoreria::~Tesoreria() {
}

void Tesoreria::cargaescalas(){
    ifstream arch("escalas.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archvo escalas" << endl;
        exit(1);
    }
    int escala;
    while(true){
        arch >> escala;
        if(arch.eof())break;
        arch.get();
        lescala[escala - 1].leerDatos(arch);
    }
    
}

void Tesoreria::cargaalumnos(){
    ifstream arch("alumnos.csv", ios::in);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archvo alumnos" << endl;
        exit(1);
    }
    int cantPre = 0, cantSemi = 0, cantVirtual = 0;
    char tipo;
    while(true){
        arch >> tipo;
        if(arch.eof())break;
        arch.get();
        if(tipo == 'P'){
            lpresencial[cantPre].leerDatos(arch);
            cantPre++;
        }
        else if(tipo == 'S'){
            lsemipresencial[cantSemi].leerDatos(arch);
            cantSemi++;
        }
        else {
            lvirtual[cantVirtual].leerDatos(arch);
            cantVirtual++;
        }
    }
}

void Tesoreria::imprime(){
    ofstream arch("ReporteFinal.txt", ios::out);
    if(!arch){
        cout << "ERROR: No se pudo abrir el archvo reporte" << endl;
        exit(1);
    }
    arch << setprecision(2) << fixed;
    for(int i = 0; lpresencial[i].GetEscala(); i++){
        lpresencial[i].imprime(arch);
    }
    
    for(int i = 0; lsemipresencial[i].GetEscala(); i++){
        lsemipresencial[i].imprime(arch);
    }
    
    for(int i = 0; lvirtual[i].GetEscala(); i++){
        lvirtual[i].imprime(arch);
    }
}

void Tesoreria::actualiza(double creditos){
    int escala;
    double precio;
    for(int i = 0; lpresencial[i].GetEscala(); i++){
        escala = lpresencial[i].GetEscala();
        precio = lescala[escala - 1].GetPrecio();
        lpresencial[i].actualiza(creditos * precio);
    }
    
    for(int i = 0; lsemipresencial[i].GetEscala(); i++){
        escala = lsemipresencial[i].GetEscala();
        precio = lescala[escala - 1].GetPrecio();
        lsemipresencial[i].actualiza(creditos * precio);
    }
    
    for(int i = 0; lvirtual[i].GetEscala(); i++){
        escala = lvirtual[i].GetEscala();
        precio = lescala[escala - 1].GetPrecio();
        lvirtual[i].actualiza(creditos * precio);
    }
}
